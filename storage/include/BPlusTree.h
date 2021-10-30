//
// Created by o_oya on 2021/10/23.
//

#ifndef DATABASE_BPLUSTREE_H
#define DATABASE_BPLUSTREE_H



#include "BPlusTreeNode.h"
#include "Pager.h"
#include "SQLData.h"
#include <iostream>

class BPlusTree {
public:
    BPlusTree(int rootAddr, Pager &pager, BPlusTreeNode currentNode);
    int rootAddr;
    void presearch(int num);
    SQLData search(int num);
    void insert(int num, SQLData data);
    BPlusTreeNode currentNode;
    Pager &pager;

};


#endif //DATABASE_BPLUSTREE_H
