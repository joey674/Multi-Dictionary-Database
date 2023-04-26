#include <iostream>
#include <meta_img.h>
#include <create.h>
#include <read.h>
#include <meta.h>
#include <tmp.h>
#include <vector>
#include <memory>



int main(){
    TMP* tmp = TMP::getInstance();

    // create mockfile
    MetaImage metaImage;   
    create(&metaImage);    

    read();
    
    // // ( chronicle_id )==>chronicle
    // std::string chronicle_id = "e551e60e-897f-48d8-bea1-9bfd1b621016";
    // std::shared_ptr<ChronicleInfo_T> chronicle = ChroInfo(chronicle_id);
    // std::cout << chronicle->chronicle_id << std::endl;

    // // ( port_type , port_id )==>files
    // std::vector<std::shared_ptr<FileInfo_T>> files = FileInfo(1, 2);
    // for(auto it = files.begin(); it != files.end(); ++it )
    // std::cout   << (*it)->file_id       <<" "
    //             << (*it)->datalogger_id <<" "
    //             << (*it)->chronicle_id  
    // << std::endl;

    // // ( file_id )==>file
    // std::string file_id = "cfa5bba2-788c-4516-83d1-89cabb8350d3";
    // std::shared_ptr<FileInfo_T> files1 = FileInfo_fileId(file_id);
    // std::cout << files1->chronicle_id << std::endl;

    // // ( datalogger_id )==>files
    // std::string datalogger_id = "7a65959d-1092-4c15-b2df-b7a35f3e9558";
    // std::vector<std::shared_ptr<FileInfo_T>> files2 = FileInfo_dataloggerId(datalogger_id);
    // for(auto it = files2.begin(); it != files2.end(); ++it )
    // std::cout   << (*it)->file_id       <<" "
    //             << (*it)->datalogger_id <<" "
    //             << (*it)->chronicle_id  
    // << std::endl;

    // // ( chronicle_id )==>files
    // std::string chronicle_id1 = "b93578f8-2fbc-4ecf-8d46-45ca63424e23";
    // std::vector<std::shared_ptr<FileInfo_T>> files3 = FileInfo_chronicleId(chronicle_id1);
    // for(auto it = files3.begin(); it != files3.end(); ++it )
    // std::cout   << (*it)->file_id       <<" "
    //             << (*it)->datalogger_id <<" "
    //             << (*it)->chronicle_id  
    // << std::endl;

    // //( port_type , port_id , start , end )==>trace number
    // uint32_t trace =StatInfo(1,2,3,5);
    // std::cout << static_cast<int>(trace) <<std::endl;




    return 0;
}
