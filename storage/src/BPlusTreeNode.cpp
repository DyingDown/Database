//
// Created by o_oya on 2021/10/23.
//

#include "BPlusTreeNode.h"

BPlusTreeNode::BPlusTreeNode(Pager& pager_) : pager(pager_){
    this->num = 0;
    this->keys = std::vector<int>(degree);
    this->children = std::vector<int>(degree + 1);
    this->parentNode = 0;
    this->isLeaf = true;
    this->currentAddr = 0;
}

BPlusTreeNode::BPlusTreeNode(Pager &pager1, int parent, bool isLeaf, int num, int addr) : pager(pager1){
    this->num = num;
    this->keys = std::vector<int>(degree);
    this->children = std::vector<int>(degree + 1);
    this->parentNode = parent;
    this->isLeaf = isLeaf;
    this->currentAddr = addr;
}

void BPlusTreeNode::loadNode(int addr) {
    currentAddr = addr;
    // get keys
    pager.read(currentAddr, (char *)keys.data(), sizeof(keys[0]) * degree);
    currentAddr += sizeof(keys[0] * degree);

    // get children node
    pager.read(currentAddr, (char *)children.data(), sizeof(children[0]) * degree);
    currentAddr += sizeof(keys[0] * degree);

    // get parent Node
    pager.read(currentAddr, (char *)&parentNode, sizeof(parentNode));
    currentAddr += sizeof(parentNode);

    // is leaf
    pager.read(currentAddr, (char *)& isLeaf, sizeof(isLeaf));
    currentAddr += sizeof(isLeaf);

    // get number
    pager.read(currentAddr, (char *)& num, sizeof(num));
    currentAddr += sizeof(num);
}

int BPlusTreeNode::findCertainKey(int key) {
    int pos = std::lower_bound(keys.begin(), keys.begin() + num, key) - keys.begin();
//    if(keys[pos] == key) { // if data found
//        return children[pos];
//    }
    //    return children[pos];
    return pos;
}

int BPlusTreeNode::findAddrToInsert(int key) {

    return 0;
}




