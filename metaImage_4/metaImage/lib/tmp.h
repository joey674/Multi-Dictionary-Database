#ifndef TMP_H
#define TMP_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <map>
#include "meta.h"

struct pair_hash{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class TMP {
private:
    TMP()  {}
    static TMP* instance;
    ~TMP() {
        delete instance;
    }
public:
    std::shared_ptr<Header_T> header;

    std::unordered_map<std::string, std::shared_ptr<ChronicleInfo_T>> chroId_Map;
    std::unordered_multimap<std::pair<uint8_t, uint8_t>, std::vector<std::shared_ptr<FileInfo_T>>,pair_hash>port_Map;
    std::vector<std::shared_ptr<FileInfo_T>> port_file_vector;

    std::unordered_map<std::string, std::shared_ptr<FileInfo_T>> fileId_fileMap;
   
    std::unordered_multimap<std::string, std::vector<std::shared_ptr<FileInfo_T>>
    > chronicleId_fileMap;
    std::unordered_multimap<std::string, std::vector<std::shared_ptr<FileInfo_T>> > dataloggerId_fileMap;
    
    std::unordered_multimap< std::pair<uint8_t, uint8_t>, std::map<uint32_t,std::shared_ptr<StatInfo_T>> ,pair_hash>stat_Map;

    static TMP* getInstance(){
        if (instance == nullptr) instance = new TMP();
        return instance;
    }

};

#endif