//
// Created by o_oya on 2021/10/24.
//

#ifndef DATABASE_PAGER_H
#define DATABASE_PAGER_H

#include <fstream>
#include <iostream>
#include <cstring>
//#include "BPlusTree.h"
#include "SQLData.h"

class Pager {
public:
    std::fstream fileData;
    Pager(const std::string& dir);
    long long fileLen;
    void getFileSize();                  /* length of file */
    int write(int addr, char* data, int len);
    int read(int addr, char* data, int len);
    SQLData loadData(int addr);          /* load row data*/
    int writeData(SQLData data, int pos);
};


#endif //DATABASE_PAGER_H
