//
// Created by o_oya on 2021/10/23.
//

#ifndef DATABASE_BPLUSTREENODE_H
#define DATABASE_BPLUSTREENODE_H

#include <vector>
#include "Pager.h"

class BPlusTreeNode {
private:
    static const int degree = 255;   // maxmiun number of keys in the node
public:
    std::vector<int> keys;            // key value array
    std::vector<int> children;        // child nodes or data nodes
    int parentNode;                   // parent node
    bool isLeaf;                      // is leaf node
    int num;                          // number of keys in this node
    BPlusTreeNode(Pager &pager);
    Pager &pager;
    int currentAddr;
    int findCertainKey(int key);
    int findAddrToInsert(int key);
    void loadNode(int addr);
};

#endif //DATABASE_BPLUSTREENODE_H
