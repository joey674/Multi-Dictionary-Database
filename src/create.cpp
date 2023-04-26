#include "create.h"

void create(MetaImage* metaImage){
    std::cout << "creating file start." << std::endl;
    //random file number  &&  random uuid 
    std::minstd_rand0 num_rand(std::random_device{}());
    boost::random::uniform_int_distribution<> dist(5 , 10);
    int arr_num[2];
    for (int i = 0; i < 3; i++) {
        arr_num[i] = dist(num_rand);
        // std::cout << arr_num[i] << " ";
    }
    // const int num_chro=arr_num[0] , num_file=arr_num[1] , num_stat=arr_num[2];
    const int num_chro=2 , num_file=3 , num_stat=4;
    boost::uuids::random_generator gen;

    //setup
    ImgChronicleInfo_T  list_chro[num_chro];
    ImgFileInfo_T       list_file[num_file];
    ImgStatInfo_T       list_stat[num_stat];

    //ImgHeader
    strcpy(metaImage->header.signature, "META");
    // std::cout << sizeof(metaImage->header.signature) << std::endl;
    metaImage->header.major_ver = 2 ; metaImage->header.minor_ver = 1 ; 
    metaImage->header.patch_ver = 3 ; metaImage->header.reserved  = 5 ;
    metaImage->header.chronicle_info_size = sizeof(list_chro);
    metaImage->header.file_info_size      = sizeof(list_file);
    metaImage->header.stat_info_size      = sizeof(list_stat);

    //ImgChronicleInfo
    for(int i = 0 ; i < num_chro ; i++){
        boost::uuids::uuid uuid = gen();
        std::string uuid_str = boost::uuids::to_string(uuid);
        // std::copy(uuid_str.begin(),uuid_str.end(),list_chro[i].chronicle_id);
        for(int j=0;j<36;j++ ) {
            list_chro[i].chronicle_id[j]=uuid_str[j];
        }
        list_chro[i].port_type= 1 ;
        list_chro[i].port_id= 2 ;
        list_chro[i].logger= 3 ;
    }

    //ImgFileInfo
    std::minstd_rand0 chro_rand(std::random_device{}());
    boost::random::uniform_int_distribution<> dis(0 , num_chro-1);
    for(int i = 0 ; i < num_file ; i++){   
        boost::uuids::uuid uuid1 = gen();
        std::string uuid1_str = boost::uuids::to_string(uuid1);
        // std::copy(uuid1_str.begin(),uuid1_str.end(),list_file[i].file_id);
        for(int j=0;j<36;j++ ) {
            list_file[i].file_id[j]=uuid1_str[j];
        }

        boost::uuids::uuid uuid2 = gen();
        std::string uuid2_str = boost::uuids::to_string(uuid2);
        // std::copy(uuid2_str.begin(),uuid2_str.end(),list_file[i].datalogger_id);
        for(int j=0;j<36;j++ ) {
            list_file[i].datalogger_id[j]=uuid2_str[j];
        }
    
        int dis_chro_rand = dis(chro_rand);
        std::string uuidstr = list_chro[dis_chro_rand].chronicle_id;
        // std::copy(uuidstr.begin(),uuidstr.end(), list_file[i].chronicle_id);
        for(int j=0;j<36;j++ ) {
            list_file[i].chronicle_id[j]=uuidstr[j];
        }
        list_file[i].file_type  = 1;
        list_file[i].status     = 2;
        list_file[i].reserved_1 = 3 ;
        list_file[i].size       = 4 ;
        list_file[i].btime      = 921;
        list_file[i].mtime      = 1033;
        list_file[i].reserved_2 =5 ;
        strcpy(list_file[i].file_path, "/media/ssd/");
    }

    //ImgStatInfo
    for(int i = 0 ; i < num_stat ; i++){
        list_stat[i].port_type          = 1 ;
        list_stat[i].port_id            = 2 ;
        list_stat[i].reserved           = 3 ;
        list_stat[i].timestamp_minute   = 4 ;
        for(int j = 0; j < 6; j++){
        list_stat[i].append_size[j] = 8 ;
        // std::cout << static_cast<int>(list_stat[i].append_size[j]);
        }
        // std::cout << " ";
    }

    std::cout   <<  static_cast<int>(metaImage->header.major_ver)      <<"."
                <<  static_cast<int>(metaImage->header.minor_ver)      <<"."
                <<  static_cast<int>(metaImage->header.patch_ver)      <<" "
                <<  metaImage->header.signature                        <<" "
                <<  metaImage->header.chronicle_info_size              <<" "
                <<  metaImage->header.file_info_size                   <<" "
                <<  metaImage->header.stat_info_size                   <<" "
                // <<  list_file[0].file_path                             <<" "
    << std::endl;   
    
    std::string filePath = "../mockfile";
    std::ofstream outfile(filePath,  std::ios::out | std::ios::binary | std::ios::trunc);
    outfile.close();
    outfile.open(filePath, std::ios::binary | std::ios::out | std::ios::app);
    outfile.write(
        (char*)&metaImage->header, 
        sizeof(metaImage->header)
    );

    ImgChronicleInfo_T* ptr_chro = list_chro;
    for (int i = 0; i < num_chro; i++) {
        outfile.write(  
            reinterpret_cast<char*>(&ptr_chro[i]), 
            sizeof(ImgChronicleInfo_T)
        );
    }
    ImgFileInfo_T* ptr_file = list_file;
    for (int i = 0; i < num_file; i++) {
        outfile.write(  
            reinterpret_cast<char*>(&ptr_file[i]), 
            sizeof(ImgFileInfo_T)
        );
    }
    ImgStatInfo_T* ptr_stat = list_stat;
    for (int i = 0; i < num_stat; i++) {
        outfile.write(  
            reinterpret_cast<char*>(&ptr_stat[i]), 
            sizeof(ImgStatInfo_T)
        );
    }

    outfile.close();
    std::cout << "creating file finished." << std::endl << std::endl;
}