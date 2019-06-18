package com.acafela.harmony.codec;

import android.media.MediaFormat;
import android.media.MediaCodecInfo;

public class VideoMediaFormat {

    private static final String TAG = VideoMediaFormat.class.getName();

    public static final String VIDEO_MIME_TYPE = MediaFormat.MIMETYPE_VIDEO_AVC;
    private static final int VIDEO_FRAME_RATE = 30;               // 30fps
    private static final int VIDEO_IFRAME_INTERVAL = 0;  // TRADE-OFF
    private static final int VIDEO_BIT_RATE = 300000;

    public static final int VIDEO_QUEUE_BOUND = 100;

    private MediaFormat mFormat = new MediaFormat();

    public VideoMediaFormat() {
        mFormat.setString(MediaFormat.KEY_MIME, VIDEO_MIME_TYPE);
        mFormat.setInteger(MediaFormat.KEY_COLOR_FORMAT, MediaCodecInfo.CodecCapabilities.COLOR_FormatSurface);
        mFormat.setInteger(MediaFormat.KEY_FRAME_RATE, VIDEO_FRAME_RATE);
        mFormat.setInteger(MediaFormat.KEY_I_FRAME_INTERVAL, VIDEO_IFRAME_INTERVAL);
        mFormat.setInteger(MediaFormat.KEY_BIT_RATE, VIDEO_BIT_RATE);
    }

    public MediaFormat getVideoMediaFormat() {
        return mFormat;
    }


}