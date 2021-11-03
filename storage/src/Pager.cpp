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
    if(addr == 0) fileData.seekg(0, std::ios::end);
    else fileData.seekg(addr, std::ios::beg);
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
    fileData.seekp(0,std::ios::end);
    int ad = fileData.tellg();
    int len;
    fileData.write((char *) &data.size, sizeof(data.size));
    fileData.write((char *) &data.data, data.size);
    return ad;
}

int Pager::applySpace() {
    fileData.seekp(0, std::ios::end);
    int addr = fileData.tellp();
    fileData.write(nullptr, 4096);
    return addr;
}


