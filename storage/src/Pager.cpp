//
// Created by o_oya on 2021/10/24.
//

#include "Pager.h"

Pager::Pager(const std::string& dir) {
    fileData.open(dir, std::ios::in | std::ios::out | std::ios::binary);
    if(!fileData) {
        std::cout<< "file does not exisit, create a new one." << std::endl;
        std::fstream newFile(dir);
        newFile.close();
        fileData.open(dir, std::ios::in | std::ios::out | std::ios::binary);
    }
//    getFileSize();
}

void Pager::getFileSize() {
    fileData.seekg(0, std::ios::end);
    fileLen = fileData.tellg();
}

int Pager::write(int addr, char* data, int len) {
    fileData.seekg(addr, std::ios::beg);
    int ad = fileData.tellg();
    fileData.write(data, len);
    getFileSize();
    return ad;
}

int Pager::read(int addr, char *data, int len) {
    if(addr > fileLen) {
        throw "out of file range";
    }
    fileData.seekg(addr, std::ios::beg);
    fileData.read(data, len);
    return 0;
}

SQLData Pager::loadData(int addr) {
    if(addr <= fileLen) {
        fileData.seekg(addr, std::ios::beg);
        int len;
        fileData.read((char *) len, sizeof(len));
        char * data;
        fileData.read(data, len);
        return {data, len};
    }
    std::cout << "out of file" << std::endl;
    return {nullptr, 0};
}

int Pager::writeData(SQLData data, int pos) {
    fileData.seekg(0,std::ios::end);
    int ad = fileData.tellg();
    int len;
    fileData.write((char *) &data.size, sizeof(data.size));
    fileData.write((char *) &data.data, data.size);
    return ad;
}


