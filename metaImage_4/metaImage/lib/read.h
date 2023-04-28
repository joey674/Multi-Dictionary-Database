#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <memory>
#include "meta.h"
#include "tmp.h"
#include "meta_img.h"


void read();
std::shared_ptr<ChronicleInfo_T> ChroInfo(const std::string &chronicle_id );
std::vector<std::shared_ptr<FileInfo_T>>* FileInfo(const uint8_t &port_type  ,const uint8_t &port_id );
std::shared_ptr<FileInfo_T> FileInfo_fileId(const std::string &file_id );
std::vector<std::shared_ptr<FileInfo_T>>* FileInfo_dataloggerId(const std::string &datalogger_id );
std::vector<std::shared_ptr<FileInfo_T>>* FileInfo_chronicleId(const std::string &chronicle_id );

uint32_t StatInfo(const uint8_t &port_type  ,const uint8_t &port_id ,const uint32_t &start,const uint32_t &end);

#endif