//
// Created by o_oya on 2021/10/23.
//

#include "BPlusTree.h"

void BPlusTree::presearch(int num) {
    currentNode.loadNode(rootAddr);
    while(!currentNode.isLeaf) {
        int p = std::lower_bound(currentNode.keys.begin(), currentNode.keys.end(), num) - currentNode.keys.begin();
        int childAddr = currentNode.children[p];
        currentNode.loadNode(childAddr);
    }
}

SQLData BPlusTree::search(int num) {
    presearch(num);
    int pos = currentNode.findCertainKey(num);
    if(currentNode.keys[pos] == num) {
        int addr = currentNode.children[pos];
        return pager.loadData(addr);
    } else {
        std::cout << "not found" << std::endl;
        return {nullptr, false};
    }
}

void BPlusTree::insert(int num, SQLData data) {
    presearch(num);
    int pos = currentNode.findCertainKey(num);
    if(currentNode.keys[pos] == num){
        std::cout << "already exisits" << std::endl;
    } else {
        pager.writeData(data,pos);
    }
}

BPlusTree::BPlusTree(int rootAddrs, Pager &pagers, BPlusTreeNode currentNd) :rootAddr(rootAddrs), pager(pagers),
                                                                               currentNode(currentNd){

}



