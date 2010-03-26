#ifndef _I965_MEDIA_H264_H_
#define _I965_MEDIA_H264_H_

#include "i965_avc_bsd.h"
#include "i965_avc_hw_scoreboard.h"

#define MB_CMD_IN_BYTES         64
#define MB_CMD_IN_DWS           16
#define MB_CMD_IN_OWS           4

enum {
    H264_AVC_COMBINED = 0,
    H264_AVC_NULL
};

struct i965_h264_context
{
    struct {
        dri_bo *bo;
        unsigned int mbs;
    } avc_it_command_mb_info;

    struct {
        dri_bo *bo;
        long write_offset;
    } avc_it_data;

    struct {
        unsigned int width_in_mbs;
        unsigned int height_in_mbs;
        int mbaff_frame_flag;
    } picture;

    int use_avc_hw_scoreboard;

    int use_hw_w128;
    unsigned int weight128_luma_l0;
    unsigned int weight128_luma_l1;
    unsigned int weight128_chroma_l0;
    unsigned int weight128_chroma_l1;
    char weight128_offset0_flag;
    short weight128_offset0;

    struct i965_avc_bsd_context i965_avc_bsd_context;
    struct i965_avc_hw_scoreboard_context avc_hw_scoreboard_context;
};

Bool i965_media_h264_init(VADriverContextP ctx);
Bool i965_media_h264_ternimate(VADriverContextP ctx);
void i965_media_h264_decode_init(VADriverContextP ctx);

#endif /* _I965_MEDIA_H264_H_ */