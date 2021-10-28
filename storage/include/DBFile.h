//
// Created by o_oya on 2021/10/24.
//

#ifndef DATABASE_DBFILE_H
#define DATABASE_DBFILE_H

#include "BPlusTree.h"
#include "Pager.h"

class DBFile {
public:
    char symbol[9] = "Database";
    int currentPos;
    BPlusTree generateTree();
    Pager pager;
    DBFile(const std::string& fileName);
    int tableNum;
    static const int pageSize;
    std::vector<BPlusTree> trees;
};


#endif //DATABASE_DBFILE_H
