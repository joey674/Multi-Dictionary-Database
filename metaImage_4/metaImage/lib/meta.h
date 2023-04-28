#ifndef META_H__
#define META_H__

#include <stdint.h>
#include <cstring>

typedef struct {
    std::string         signature;
    uint8_t             major_ver;
    uint8_t             minor_ver;
    uint8_t             patch_ver;
    uint64_t            reserved;
    uint64_t            chronicle_info_size;
    uint64_t            file_info_size;
    uint64_t            stat_info_size;
} Header_T;

typedef struct {
    std::string         chronicle_id;
    uint8_t             port_type;
    uint8_t             port_id;
    uint16_t            logger;

} ChronicleInfo_T;

typedef struct{
    std::string         file_id;//uuidv4 36
    std::string         datalogger_id;//uuidv4
    std::string         chronicle_id;//uuidv4
    uint8_t             file_type;
    uint8_t             status;
    uint16_t            reserved_1;
    uint32_t            size;
    uint32_t            btime;
    uint32_t            mtime;
    uint32_t            reserved_2;
    std::string         file_path;//256
} FileInfo_T;

typedef struct {
    uint8_t             port_type;
    uint8_t             port_id;
    uint16_t            reserved;
    uint32_t            timestamp_minute;
    uint32_t            append_size[6];
} StatInfo_T;




#endif