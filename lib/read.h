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
std::shared_ptr<ChronicleInfo_T> ChroInfo( std::string chronicle_id );
std::vector<std::shared_ptr<FileInfo_T>> FileInfo( uint8_t port_type  ,uint8_t port_id );
std::shared_ptr<FileInfo_T> FileInfo_fileId( std::string file_id );
std::vector<std::shared_ptr<FileInfo_T>> FileInfo_dataloggerId( std::string datalogger_id );
std::vector<std::shared_ptr<FileInfo_T>> FileInfo_chronicleId( std::string chronicle_id );

uint32_t StatInfo(uint8_t port_type  ,uint8_t port_id ,uint32_t start, uint32_t end);

#endif