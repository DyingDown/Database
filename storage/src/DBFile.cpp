//
// Created by o_oya on 2021/10/24.
//

#include "DBFile.h"



BPlusTree DBFile::generateTree() {

}

DBFile::DBFile(std::string fileName) {
    pager = Pager(fileName);
    if(pager.fileLen == 0) {
        currentPos = 0;
        // mark db file symbol
        pager.write(currentPos, symbol, sizeof(symbol));
        currentPos += sizeof(symbol);
        // mark number of tables
        tableNum = 0;
        pager.write(currentPos, (char *)&tableNum, sizeof(tableNum));
        currentPos += sizeof(tableNum);

        generateTree();
    } else if(pager.fileLen >= pageSize){
        currentPos = 0;
        char head[8];
        // check symbol of db file
        pager.read(currentPos, head, sizeof(head));
        currentPos += sizeof(head);
        if(std::strcmp(head, symbol) == 0) {
            throw "not a database file.";
        }
        // get table number
        pager.read(currentPos, (char *)&tableNum, sizeof(tableNum));
        currentPos += sizeof(tableNum);

    } else {
        throw "not a complete db file";
    }
}
