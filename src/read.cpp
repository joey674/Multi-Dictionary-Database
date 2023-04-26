#include "read.h"


void read(){
    std::cout << "reading file start."  << std::endl;
    std::ifstream infile("../mockfile" , std::ios::binary);
    MetaImage metaImage;
    TMP* tmp = TMP::getInstance();
    if (!infile.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
    }
    //header
    infile.read(
        reinterpret_cast<char*>( &metaImage.header ), 
        sizeof( ImgHeader_T )
    );
    auto header = std::make_shared<Header_T>(Header_T{
        .signature = metaImage.header.signature,
        .major_ver = metaImage.header.major_ver,
        .minor_ver = metaImage.header.minor_ver,
        .patch_ver = metaImage.header.patch_ver,
        .chronicle_info_size = metaImage.header.chronicle_info_size,
        .file_info_size = metaImage.header.file_info_size,
        .stat_info_size = metaImage.header.stat_info_size
    });
    tmp->header = header;
    std::cout   << "header "                                        <<" "
                <<  tmp->header->signature                          <<" "
                <<  static_cast<int>(tmp->header->major_ver)        <<"."
                <<  static_cast<int>(tmp->header->minor_ver)        <<"."
                <<  static_cast<int>(tmp->header->patch_ver)        <<" "
                <<  tmp->header->chronicle_info_size                <<" "
                <<  tmp->header->file_info_size                     <<" "
                <<  tmp->header->stat_info_size                 
    <<std::endl;                  

    //chro
    int num_chro = metaImage.header.chronicle_info_size/sizeof(ImgChronicleInfo_T);
    int num_file = metaImage.header.file_info_size/sizeof(ImgFileInfo_T);
    int num_stat = metaImage.header.stat_info_size/sizeof(ImgStatInfo_T);
    ImgChronicleInfo_T  list_chro[num_chro];
    ImgFileInfo_T       list_file[num_file];
    ImgStatInfo_T       list_stat[num_stat];
    for (int i = 0; i < num_chro; i++) {
        infile.read(  
            reinterpret_cast<char*>(&list_chro[i]), 
            sizeof(ImgChronicleInfo_T)
        );
        auto chronicle = std::make_shared<ChronicleInfo_T>(ChronicleInfo_T {
            .chronicle_id = std::string(list_chro[i].chronicle_id, list_chro[i].chronicle_id+36),
            .port_type = list_chro[i].port_type,
            .port_id   = list_chro[i].port_id,
            .logger    = list_chro[i].logger
        });
        auto ptr1 = chronicle; auto ptr2 = chronicle;
        tmp->chroId_Map.insert({ptr1->chronicle_id, ptr1});
        tmp->port_Map.insert({{ptr2->port_type,ptr2->port_id}, ptr2}) ;
        std::cout   <<"chronicle "
                    <<ptr1->chronicle_id << " "
                    <<static_cast<int>(ptr1->port_type)
                    <<static_cast<int>(ptr1->port_id)
                    <<static_cast<int>(ptr1->logger)
        <<std::endl;
    }

    //file
    for (int i = 0; i < num_file; i++) {
        infile.read(  
            reinterpret_cast<char*>(&list_file[i]), 
            sizeof(ImgFileInfo_T)
        );
        auto file = std::make_shared<FileInfo_T>(FileInfo_T{
            .file_id       = std::string(list_file[i].file_id, list_file[i].file_id+36),
            .datalogger_id = std::string(list_file[i].datalogger_id, list_file[i].datalogger_id+36),
            .chronicle_id  = std::string(list_file[i].chronicle_id, list_file[i].chronicle_id+36),
            .file_type     = list_file[i].file_type,
            .status        = list_file[i].status,
            .reserved_1    = list_file[i].reserved_1,
            .size          = list_file[i].size,
            .btime         = list_file[i].btime,
            .mtime         = list_file[i].mtime,
            .reserved_2    = list_file[i].reserved_2,
            .file_path     = list_file[i].file_path
        });        
        auto ptr1 = file; auto ptr2 = file;auto ptr3 = file;
        tmp->fileId_fileMap.insert({ptr1->file_id , ptr1});
        tmp->chronicleId_fileMap.insert({ptr2->chronicle_id , ptr2}) ;
        tmp->dataloggerId_fileMap.insert({ptr3->datalogger_id , ptr3}) ;
        std::cout   <<"file      "
                    <<ptr1->file_id         << " "
                    <<ptr1->datalogger_id   << " "
                    <<ptr1->chronicle_id    << " "
                    <<static_cast<int>(ptr1->file_type)
                    <<static_cast<int>(ptr1->status)
                    <<static_cast<int>(ptr1->reserved_1)
                    <<static_cast<int>(ptr1->size)
                    <<static_cast<int>(ptr1->btime)
                    <<static_cast<int>(ptr1->mtime)
                    <<static_cast<int>(ptr1->reserved_2)
                    <<ptr1->file_path                    
        <<std::endl;
    }
     for (int i = 0; i < num_stat; i++) {
        infile.read(  
            reinterpret_cast<char*>(&list_stat[i]), 
            sizeof(ImgStatInfo_T)
        );
        auto stat = std::make_shared<StatInfo_T> (StatInfo_T{
            .port_type         = list_stat[i].port_type,
            .port_id           = list_stat[i].port_id,
            .reserved          = list_stat[i].reserved,
            .timestamp_minute  = list_stat[i].timestamp_minute,
            .append_size =
            {
                list_stat[i].append_size[0],
                list_stat[i].append_size[1],
                list_stat[i].append_size[2],
                list_stat[i].append_size[3],
                list_stat[i].append_size[4],
                list_stat[i].append_size[5]   
            }
               
        });
        auto  ptr1 = stat; 
        tmp->stat_Map.insert( { {ptr1->port_type,ptr1->port_id }, ptr1} );
        std::cout   <<"stat "
                    <<static_cast<int>(ptr1->port_type)
                    <<static_cast<int>(ptr1->port_id)
                    <<static_cast<int>(ptr1->reserved)
                    <<static_cast<int>(ptr1->timestamp_minute)
        <<std::endl;
    }
    std::cout << "reading file finished." <<std::endl  << std::endl;
}

std::shared_ptr<ChronicleInfo_T> ChroInfo(std::string chronicle_id ){
    TMP* tmp = TMP::getInstance();
    if( tmp->chroId_Map.find(chronicle_id) == tmp->chroId_Map.end() ){
        std::cerr << "Error: Could not find matching chronicle id." << std::endl;
        exit(EXIT_FAILURE);
    }else{
        return tmp->chroId_Map.find(chronicle_id)->second ;
    }
}

std::vector<std::shared_ptr<FileInfo_T>> FileInfo(uint8_t port_type, uint8_t port_id){
    TMP* tmp = TMP::getInstance();
    std::vector<std::shared_ptr<FileInfo_T>> files;
    // std::cout<<static_cast<int>(port_type)<<static_cast<int>(port_id)<<std::endl; 
    auto range = tmp->port_Map.equal_range({port_type,port_id});
    if (range.first == tmp->port_Map.end() && range.second == tmp->port_Map.end()) {
        std::cerr << "Error: Could not find matching port_type or port_id";
        exit(EXIT_FAILURE);
    } else{
        for (auto it = range.first; it != range.second; ++it) {
            // std::cout << "chronicle_id " << it->second->chronicle_id << std::endl;
            auto range1 = tmp->chronicleId_fileMap.equal_range(it->second->chronicle_id);
            for (auto it1 = range1.first; it1 != range1.second; ++it1) {      
                // std::cout<< "file_id " << it1->second->file_id <<std::endl;
                files.push_back(it1->second);
            }
        }    
        return files;
    }
}

std::shared_ptr<FileInfo_T> FileInfo_fileId( std::string file_id ){
    TMP* tmp = TMP::getInstance();
    if( tmp->fileId_fileMap.find(file_id) == tmp->fileId_fileMap.end() ){
        std::cerr << "Error: Could not find matching file id." << std::endl;
        exit(EXIT_FAILURE);
    }else{
        return tmp->fileId_fileMap.find(file_id)->second ;
    }  
}

std::vector<std::shared_ptr<FileInfo_T>> FileInfo_dataloggerId( std::string datalogger_id ){
    TMP* tmp = TMP::getInstance();
    std::vector <std::shared_ptr<FileInfo_T>> files;
    auto range = tmp->dataloggerId_fileMap.equal_range({datalogger_id});
    if (range.first == tmp->dataloggerId_fileMap.end() && range.second == tmp->dataloggerId_fileMap.end()){
        std::cerr << "Error: Could not find matching datalogger_id.";
        exit(EXIT_FAILURE);
    }else{
        for (auto it = range.first; it != range.second; ++it) {
                files.push_back(it->second);
        }    
        return files;
    }
}

std::vector<std::shared_ptr<FileInfo_T>> FileInfo_chronicleId( std::string chronicle_id ){
    TMP* tmp = TMP::getInstance();
    std::vector <std::shared_ptr<FileInfo_T>> files;
    auto range = tmp->chronicleId_fileMap.equal_range({chronicle_id});
    if (range.first == tmp->chronicleId_fileMap.end() && range.second == tmp->chronicleId_fileMap.end()){
        std::cerr << "Error: Could not find matching chronicle_id.";
        exit(EXIT_FAILURE);
    }else{
        for (auto it = range.first; it != range.second; ++it) {
                files.push_back(it->second);
        }    
        return files;
    }
}

uint32_t StatInfo(uint8_t port_type  ,uint8_t port_id ,uint32_t start, uint32_t end){
    TMP* tmp = TMP::getInstance();
    // std::vector<std::shared_ptr<StatInfo_T>> stats;
    uint32_t trace_num=0;
    auto range = tmp->stat_Map.equal_range({port_type,port_id});
    if (range.first == tmp->stat_Map.end() && range.second == tmp->stat_Map.end()) {
        std::cerr << "Error: Could not find matching port_type or port_id";
        exit(EXIT_FAILURE);
    } else{
        for (auto it = range.first; it != range.second; ++it) {
            if( (it->second->timestamp_minute >= start) && (it->second->timestamp_minute <= end) ){
                for(int j=0; j<6; j++) {
                    // std::cout << static_cast<int>(it->second->append_size[j]) << " ";
                    trace_num += it->second->append_size[j];
                }
            }
        }    
    return trace_num;
    }
}