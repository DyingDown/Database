//
// Created by o_oya on 2021/10/23.
//

#ifndef DATABASE_BPLUSTREE_H
#define DATABASE_BPLUSTREE_H

#include "BPlusTreeNode.h"
#include "Pager.h"
#include "SQLData.h"
#include <iostream>

class DBFile;

class BPlusTree {
private:
    void insertToArr(std::vector<int> &vec, int pos, int num);
public:
    BPlusTree(int rootAddr, Pager &pager, BPlusTreeNode currentNode, DBFile &storage);
    int rootAddr;
    void presearch(int num);
    SQLData search(int num);
    void insert(int num, SQLData data);
    BPlusTreeNode currentNode;
    Pager &pager;
    int splitLeaf(int pos, int& num, int leftChildPos);
    void splitNoneLeaf(int pos, int& num);
    void changeRoot(int addr);
    DBFile &storage;
};


#endif //DATABASE_BPLUSTREE_H
