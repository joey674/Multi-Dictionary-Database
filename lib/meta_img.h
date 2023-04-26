#ifndef __D3FS_META_META_IMG_H__
#define __D3FS_META_META_IMG_H__

#include <stdint.h>

typedef struct {
    char        signature[5];
    uint8_t     major_ver;
    uint8_t     minor_ver;
    uint8_t     patch_ver;
    uint64_t    reserved;
    uint64_t    chronicle_info_size;
    uint64_t    file_info_size;
    uint64_t    stat_info_size;
} ImgHeader_T;

typedef struct {
    char        chronicle_id[36];
    uint8_t     port_type;
    uint8_t     port_id;
    uint16_t    logger;
} ImgChronicleInfo_T;

typedef struct {
    char        file_id[36];
    char        datalogger_id[36];
    char        chronicle_id[36];
    uint8_t     file_type;
    uint8_t     status;
    uint16_t    reserved_1;
    uint32_t    size;
    uint32_t    btime;
    uint32_t    mtime;
    uint32_t    reserved_2;
    char        file_path[256];
} ImgFileInfo_T;

//统计每个port传输file的量和时间记录
typedef struct {
    uint8_t     port_type;
    uint8_t     port_id;
    uint16_t    reserved;
    uint32_t    timestamp_minute;
    uint32_t    append_size[6];
} ImgStatInfo_T;

typedef struct {
    ImgHeader_T             header;
    ImgChronicleInfo_T*     p_chronicle_info;
    ImgFileInfo_T*          p_files_info;
    ImgStatInfo_T*          p_stats_info;
} MetaImage;

#endif