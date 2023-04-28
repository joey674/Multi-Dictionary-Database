#include <iostream>
#include <meta_img.h>
#include <create.h>
#include <read.h>
#include <meta.h>
#include <tmp.h>
#include <vector>
#include <memory>



int main(){

    create();    
    
    read();
    
    uint8_t port = 1, id =2; uint32_t start = 0, end = 3;
    // std::string chronicle_id = "0e433c5b-a97d-4216-ae28-03a7b9d9d959";
    // std::shared_ptr<ChronicleInfo_T> chronicle = ChroInfo(chronicle_id);
    // std::cout   << "( chronicle_id )==>chronicle "
    //             << chronicle->chronicle_id                      << " "
    //             << static_cast<int>(chronicle->port_type)       << " "
    //             << static_cast<int>(chronicle->port_id)         << " "
    //             << static_cast<int>(chronicle->logger)          << " "
    // << std::endl;

    // auto files = FileInfo(port , id);
    // for(auto it = files->begin(); it != files->end(); ++it )
    // std::cout   << "( port_type,port_id )==>files "                    
    //             << (*it)->file_id             << " "
    //             << (*it)->datalogger_id       << " "
    //             << (*it)->chronicle_id 
    // << std::endl;

    // std::string file_id = "5c927dec-1678-4208-86ac-0e9514535221";
    // std::shared_ptr<FileInfo_T> files1 = FileInfo_fileId(file_id);
    // std::cout   << "( file_id )==>file "
    //             << files1->file_id       << " "
    //             << files1->datalogger_id << " "
    //             << files1->chronicle_id  << " "                
    // << std::endl;

    // // // 
    // std::string datalogger_id = "4a977397-948f-4017-b87a-426349200857";
    // std::vector<std::shared_ptr<FileInfo_T>>* files2 = FileInfo_dataloggerId(datalogger_id);
    // for(auto it = files2->begin(); it != files2->end(); ++it )
    // std::cout   << "( datalogger_id )==>files " << " "
    //             << (*it)->file_id               << " "
    //             << (*it)->datalogger_id         << " "
    //             << (*it)->chronicle_id  
    // << std::endl;

    // std::string chronicle_id1 = "0e433c5b-a97d-4216-ae28-03a7b9d9d959";
    // std::vector<std::shared_ptr<FileInfo_T>>* files3 = FileInfo_chronicleId(chronicle_id1);
    // for(auto it = files3->begin(); it != files3->end(); ++it )
    // std::cout   << "( chronicle_id )==>files "
    //             << (*it)->file_id       <<" "
    //             << (*it)->datalogger_id <<" "
    //             << (*it)->chronicle_id  
    // << std::endl;

    // uint32_t trace =StatInfo(port, id, start, end);
    // std::cout   << "( port_type,port_id,start,end )==>trace number "
    //             << static_cast<int>(trace)      
    // <<std::endl;

    return 0;
}
