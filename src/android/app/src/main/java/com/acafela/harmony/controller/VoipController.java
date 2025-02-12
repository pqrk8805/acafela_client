package com.acafela.harmony.controller;

import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;
import android.widget.ToggleButton;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Semaphore;

import com.acafela.harmony.Config;
import com.acafela.harmony.R;
import com.acafela.harmony.crypto.CryptoKeyRpc;
import com.acafela.harmony.crypto.ICrypto;
import com.acafela.harmony.communicator.*;
import com.acafela.harmony.sip.SipMessage;
import com.acafela.harmony.sip.SipMessage.SIPMessage;
import com.acafela.harmony.crypto.Crypto;
import com.acafela.harmony.crypto.CryptoBroker;
import com.acafela.harmony.ui.AudioCallActivity;
import com.acafela.harmony.ui.VideoCallActivity;
import com.acafela.harmony.userprofile.UserInfo;
import com.acafela.harmony.util.AudioPathSelector;
import com.acafela.harmony.util.ConfigSetup;
import com.acafela.harmony.util.ControlMessageTestor;


import static android.content.Intent.FLAG_ACTIVITY_NEW_TASK;
import static com.acafela.harmony.sip.SipMessage.Command.*;
import static com.acafela.harmony.ui.AudioCallActivity.BROADCAST_BYE;
import static com.acafela.harmony.ui.AudioCallActivity.BROADCAST_CONNECTING;
import static com.acafela.harmony.ui.AudioCallActivity.INTENT_ISCALLEE;
import static com.acafela.harmony.ui.AudioCallActivity.INTENT_PHONENUMBER;

public class VoipController {
    public static final int CONTROL_SEND_PORT = 5000;
    public static final int CONTROL_RECIEVE_PORT = 5001;
    private static final String LOG_TAG = "[AcafelaController]";
    private static final int BUFFER_SIZE = 128;
    public static final int CONTROL_TIMEOUT = 500;
    public static final int RETRY_COUNT = 10; // RETRY_COUNT = 0 means No Retry.
    public static final int CONTROLMSG_DUPLICATE_COUNT = 1; // CONTROLMSG_DUPLICATE_COUNT = 1 means not duplicated.
    private boolean UdpListenerThreadRun = false;
    private DatagramSocket socket;
    private  InetAddress mIpAddress;

    private Context mContext;
    private int sesssionNo=0;
    private String sesssionID;
    private int msgSeq =0;
    private boolean isCaller =false;
    private boolean isRun =false;
    RingController mRingControl;
    private CryptoKeyRpc mCryptoRpc;
    private List<DataCommunicator> mSessionList;
    private String mCalleeNumber;
    private String mCallerNumber;

    private byte[]mSenderMsg;
    private int mRetryCnt;
    private Timer mTimer;
    private Object mSyncTimer = new Object();
    private boolean mIsVideoCall;
    static Semaphore mSemaphore;


    public  enum STATE {
        IDLE_STATE,
        INVITE_STATE,
        RINGING_STATE,
        CONNECTING_STATE,
    }
    private STATE mState;

    public VoipController(Context context)
    {
        mState = STATE.IDLE_STATE;
        mSessionList = new ArrayList<DataCommunicator>();
        mSemaphore= new Semaphore(1);
        mContext = context;
        mRingControl= new RingController(mContext);
        mCryptoRpc = new CryptoKeyRpc(
                ConfigSetup.getInstance().getServerIP(mContext),
                Config.RPC_PORT_CRYPTO_KEY,
                context.getResources().openRawResource(R.raw.ca),
                context.getResources().openRawResource(R.raw.server));
        try {
            this.mIpAddress = InetAddress.getByName(ConfigSetup.getInstance().getServerIP(mContext));
        } catch (Exception e) {
            Log.e(LOG_TAG, "Exception Answer Message: " + e);
            return ;
        }
    }


    public void startListenerController() {

        Crypto.init();
        UdpListenerThreadRun = true;
        Thread UDPListenThread = new Thread(new Runnable() {
            public void run() {
                try {
                    // Setup the socket to receive incoming messages
                    byte[] buffer = new byte[1024];
                    socket = new DatagramSocket(null);
                    socket.setReuseAddress(true);
                    socket.bind(new InetSocketAddress(CONTROL_RECIEVE_PORT));
                    DatagramPacket packet = new DatagramPacket(buffer, BUFFER_SIZE);
                    Log.i(LOG_TAG, "Incoming call listener started");

                    while (UdpListenerThreadRun) {
                        socket.receive(packet);
                        String senderIP = packet.getAddress().getHostAddress();
                        byte[] data = new byte[packet.getLength()];
                        System.arraycopy(packet.getData(), packet.getOffset(),data, 0, packet.getLength());
                        SIPMessage sipMessage = SIPMessage.parseFrom(data);

                        if(sipMessage.getIsACK()) {
                            Log.e(LOG_TAG, "message get ACK [" + sipMessage.getCmd().toString() + "]");
                            cancelTimer();
                            if (sipMessage.getCmd().toString().compareTo("INVITE") == 0) {
                                ControlMessageTestor.getInstance().getAck();
                            }
                            continue;
                        } else {
                            Log.e(LOG_TAG, "Send  ACK answer by message[" + sipMessage.getCmd().toString() + "]");
                            if(sipMessage.getCmd()==INVITE)
                            {
                                sesssionID = sipMessage.getSessionid();
                                mCallerNumber = sipMessage.getFrom();
                                mCalleeNumber = sipMessage.getTo();
                                mIsVideoCall = sipMessage.getIsVideoCall();
                            }
                            replyMessage(sipMessage);
                        }

                        Log.e(LOG_TAG, "Got UDP message from " + senderIP + ", message: " + sipMessage.toString());
                        mSemaphore.acquire();
                        handle(sipMessage);
                        mSemaphore.release();
                    }
                    Log.e(LOG_TAG, "Call Listener ending");
                    socket.disconnect();
                    socket.close();

                } catch (Exception e) {
                    UdpListenerThreadRun = false;
                    e.printStackTrace();
                }
            }
        });
        UDPListenThread.start();
        isRun = true;
    }

    private void handle( final SIPMessage message) {
        if(isCaller) {
            switch (message.getCmd()) {
                case RINGING:
                    if(mState!=STATE.RINGING_STATE)
                        mRingControl.ringbackTone_start();
                    mState = STATE.RINGING_STATE;
                    break;
                case ACCEPTCALL:
                    if(mState==STATE.RINGING_STATE) {
                        mRingControl.ringbackTone_stop();
                        sendMessage(SipMessage.Command.MAKECALL);
                    }
                    break;
                case OPENSESSION:
                    byte[] keyByte = mCryptoRpc.getKey(sesssionID);
                    if(keyByte.length == 0)
                    {
                        Log.e(LOG_TAG, "key is empty");
                        terminateCall();
                        break;
                    }

                    for(int i=0;i<message.getSessioninfo().getSessionsCount();i++) {
                        SipMessage.Session session = message.getSessioninfo().getSessions(i);
                        opensession(session.getSessiontype(), session.getIp(), session.getPort(),keyByte);
                    }
                    informConnectingState();
                    mState = STATE.CONNECTING_STATE;
                    break;
                case CLOSESESSION:
                    for(int i=0;i<message.getSessioninfo().getSessionsCount();i++) {
                        int idx;
                        SipMessage.Session session = message.getSessioninfo().getSessions(i);
                        for (idx=0; idx < mSessionList.size();idx++){
                            DataCommunicator data = (DataCommunicator) mSessionList.get(idx);
                            if(data.getPortNum()==session.getPort())
                            {
                                data.endCommunicator();
                                mSessionList.remove(data);
                            }
                        }
                    }
                    break;
                case BYE:
                    endCommunication();
                    mState = STATE.IDLE_STATE;
                    break;
                case STARTVIDEO:
                case STOPVIDEO:
                case TERMINATE:
                case MAKECALL:
                case INVITE:
                case UNRECOGNIZED:
                    break;
            }
        }
        else {
            switch (message.getCmd()) {
                case INVITE:
                    if(mState==STATE.IDLE_STATE) {

                        AudioPathSelector.getInstance().setAudioManager(mContext);
                        if (AudioPathSelector.getInstance().isBluetoothConnected()) {
                            AudioPathSelector.getInstance().setBluetoothAudio();
                        }
                        else {
                            AudioPathSelector.getInstance().setEarPieceAudio();
                        }
                        mRingControl.ring_start();
                        sendMessage(SipMessage.Command.RINGING);
                        if (message.getIsVideoCall()) {
                            Intent intent = new Intent(mContext, VideoCallActivity.class);
                            intent.putExtra(INTENT_PHONENUMBER, mCallerNumber);
                            intent.putExtra(INTENT_ISCALLEE, true);
                            intent.setFlags(FLAG_ACTIVITY_NEW_TASK);
                            mContext.startActivity(intent);
                        }
                        else {
                            Intent intent = new Intent(mContext, AudioCallActivity.class);
                            intent.putExtra(INTENT_PHONENUMBER, mCallerNumber);
                            intent.putExtra(INTENT_ISCALLEE, true);
                            intent.setFlags(FLAG_ACTIVITY_NEW_TASK);
                            mContext.startActivity(intent);
                        }
                    }
                    mState = STATE.RINGING_STATE;
                    break;
                case OPENSESSION:
                    //if(mState==STATE.CONNECTING_STATE) break;
                    byte[] keyByte = mCryptoRpc.getKey(sesssionID);
                    //Log.e(LOG_TAG, "Send Message: " +"keyByte" + keyByte.length);
                    for(int i=0;i<message.getSessioninfo().getSessionsCount();i++) {
                        SipMessage.Session session = message.getSessioninfo().getSessions(i);
                        opensession(session.getSessiontype(), session.getIp(), session.getPort(),keyByte);
                    }
                    informConnectingState();
                    mState = STATE.CONNECTING_STATE;
                    break;
                case CLOSESESSION:
                    for(int i=0;i<message.getSessioninfo().getSessionsCount();i++) {
                        int idx;
                        SipMessage.Session session = message.getSessioninfo().getSessions(i);
                        for (idx=0; idx < mSessionList.size();idx++){
                            DataCommunicator data = (DataCommunicator) mSessionList.get(idx);
                            if(data.getPortNum()==session.getPort())
                            {
                                data.endCommunicator();
                                mSessionList.remove(data);
                            }
                        }
                    }
                    break;
                case BYE:
                    endCommunication();
                    mState = STATE.IDLE_STATE;
                    break;
                case STARTVIDEO:
                case STOPVIDEO:
                case TERMINATE:
                case MAKECALL:
                case ACCEPTCALL:
                case UNRECOGNIZED:
                    break;
            }
        }
    }

    private void endCommunication() {
        mRingControl.allStop();
        destroyAllsession();
        finishCallActivity();
        isCaller = false;
        mState = STATE.IDLE_STATE;
        msgSeq = 0;
        mIsVideoCall =false;
    }

    private void informConnectingState() {
        Log.i(LOG_TAG, "informConnectingState");
        Intent intent = new Intent(BROADCAST_CONNECTING);
        mContext.sendBroadcast(intent);
    }

    private void finishCallActivity() {
        Log.i(LOG_TAG, "finishCallActivity");
        Intent intent = new Intent(BROADCAST_BYE);
        mContext.sendBroadcast(intent);
    }

    void opensession(SipMessage.SessionType type, String ip, int port , byte[] keyByte)
    {
        Log.e(LOG_TAG, "open session: "+ type +", ip: " +ip +", port: "+ port + " keybByte" + Arrays.toString(keyByte));
        DataCommunicator communicator = null;
        ICrypto crypto;
        switch(type)
        {
            case SENDAUDIO:
                crypto  = CryptoBroker.getInstance().create("AES");
                crypto.init(keyByte);
                communicator = new SenderAudio(crypto);
                break;
            case SENDVIDEO:
                communicator = new SendVideoSession(mContext);
                break;
            case RECIEVEAUDIO:
                crypto  = CryptoBroker.getInstance().create("AES");
                crypto.init(keyByte);
                communicator = new ReceiverAudio(mContext, crypto);
                break;
            case RECIEVEVIDEO:
                communicator = new ReceiveVideoSession(mContext);
                break;
            case UNRECOGNIZED:
                return;
        }
        communicator.setSession(ip, port);
        communicator.startCommunicator();
        mSessionList.add(communicator);
    }
    void destroyAllsession()
    {
        for(DataCommunicator session:mSessionList)
            session.endCommunicator();
        mSessionList.clear();
    }
    //////////////////////////////////////////////
    private void UdpSend( final byte[] buffer) {
        Thread replyThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    DatagramSocket socket = new DatagramSocket();
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length, mIpAddress, CONTROL_SEND_PORT);

                    socket.send(packet);
                    //Log.e(LOG_TAG, "Send Message: "+ mIpAddress);
                    socket.disconnect();
                    socket.close();
                } catch (SocketException e) {
                    Log.e(LOG_TAG, "Failure. SocketException in UdpSend: " + e);
                } catch (IOException e) {
                    Log.e(LOG_TAG, "Failure. IOException in UdpSend: " + e);
                }
            }
        });
        replyThread.start();
    }
    public void  replyMessage(SIPMessage msg)
    {
        final byte[] SenderMsg = msg.toBuilder().setIsACK(true).build().toByteArray();
        UdpSend(SenderMsg);
    }
    public void  sendMessage(SipMessage.Command cmd)
    {
        SIPMessage.Builder builder = SIPMessage.newBuilder();
        final byte[] mSenderMsg = builder.
                setCmd(cmd).
                setIsVideoCall(mIsVideoCall).
                setFrom(mCallerNumber).
                setTo(mCalleeNumber).
                setSessionid(sesssionID).
                setSeq(msgSeq).
                build().
                toByteArray();
        Log.e(LOG_TAG, "Send Message : "  +  cmd.toString());

        mRetryCnt = RETRY_COUNT;
        cancelTimer();

        synchronized (mSyncTimer) {
            mTimer = new Timer();
            mTimer.schedule(new TimerTask() {
                @Override
                public void run() {
                    if (mRetryCnt == -1) {
                        mTimer.cancel();
                        Log.e(LOG_TAG, "Timeout Control Message");
                        terminateCall();
                    } else {
                        Log.e(LOG_TAG, "mRetryCnt : " + mRetryCnt);
                        for (int i = 0; i<CONTROLMSG_DUPLICATE_COUNT; i++) {
                            UdpSend(mSenderMsg);
                        }
                    }
                    mRetryCnt--;
                }
            }, 0, CONTROL_TIMEOUT);
        }
        msgSeq++;
    }

    private void cancelTimer() {
        synchronized (mSyncTimer) {
            if(mTimer!=null)  {
                mTimer.cancel();
                mTimer=null;
            }
        }
    }

    public void inviteCall(String calleeNumber, boolean isVideoCall)
    {
        if(mState != STATE.IDLE_STATE) return;
        mState = STATE.INVITE_STATE;
        mCalleeNumber = calleeNumber;
        mCallerNumber = UserInfo.getInstance().getPhoneNumber();
        isCaller = true;
        mIsVideoCall = isVideoCall;

        if(calleeNumber.indexOf("#")==0)
            sesssionID = calleeNumber;
        else
            sesssionID = UserInfo.getInstance().getPhoneNumber() + sesssionNo++;

        sendMessage(INVITE);
    }

    public void terminateCall()
    {
        if(mState == STATE.IDLE_STATE) return;
        try {
            mSemaphore.acquire();
            endCommunication();
            mSemaphore.release();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        sendMessage(SipMessage.Command.TERMINATE);

    }
    public void acceptCall()
    {
        if(mState != STATE.RINGING_STATE) return;
        if(isCaller) return;
        mRingControl.ring_stop();
        sendMessage(SipMessage.Command.ACCEPTCALL);
    }

    private void showToastInService(final String string) {
        Handler handler = new Handler(Looper.getMainLooper());
        handler.post(new Runnable() {

            @Override
            public void run() {
                Toast.makeText(mContext, string, Toast.LENGTH_SHORT).show();
            }
        });
    }
}
