//
// Created by o_oya on 2021/10/23.
//

#include <DBFile.h>
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
        std::cout << "already exist" << std::endl;
    } else {
        int newDataPos = pager.writeData(data,pos);
        // insert first
        BPlusTree::insertToArr(currentNode.keys, pos, num);
        BPlusTree::insertToArr(currentNode.children, pos, newDataPos);
        currentNode.num ++;
        // split
        while(currentNode.num > BPlusTreeNode::degree) {
            splitLeaf();
        }
        int newNodePos = splitLeaf(pos, num, newDataPos);

    }
}

BPlusTree::BPlusTree(int rootAddrs, Pager &pagers, BPlusTreeNode currentNd, DBFile &storage1) :rootAddr(rootAddrs), pager(pagers),
                                                                               currentNode(currentNd), storage(storage1){

}

int BPlusTree::splitLeaf(int pos, int& num, int leftChildPos) {
    int degree = BPlusTreeNode::degree;
    // if it's root, create a new parent
    if(currentNode.parentNode == 0) {
        int parentAddr = pager.applySpace();
        BPlusTreeNode newParent = BPlusTreeNode(pager, 0, false, 0, parentAddr);
        newParent.children[0] = currentNode.currentAddr;
        pager.write(parentAddr, (char *) &newParent, sizeof(newParent));
        currentNode.parentNode = parentAddr;
        changeRoot(parentAddr);
    }
    // find free block to store new node
    int address = storage.getBlockAddr();
    if(address == 0) {
        address = pager.applySpace();
    }
    BPlusTreeNode newNode = BPlusTreeNode(pager, currentNode.parentNode, currentNode.isLeaf, degree - degree / 2, address);
    currentNode.num = degree / 2;
    // split children and keys
    std::copy(currentNode.keys.begin() + degree / 2, currentNode.keys.end(), newNode.keys.begin());
    std::copy(currentNode.children.begin() + degree / 2, currentNode.children.end(), newNode.children.begin());
    for(int i = degree / 2; i < degree; i ++) {
        currentNode.keys[i] = 0;
        currentNode.children[i] = 0;
    }
    num = newNode.keys[0];
    // links neighbors
    currentNode.nextNodeAddr = newNode.currentAddr;
    newNode.prevNodeAddr = currentNode.currentAddr;
    // load parent node
    BPlusTreeNode current = currentNode;
    currentNode.loadNode(currentNode.parentNode); // get parentNode
    // save change
    pager.write(current.currentAddr, (char *)&current, sizeof(current));
    pager.write(address, (char *)&newNode, sizeof(newNode));
    return newNode.currentAddr;
}

void BPlusTree::splitNoneLeaf(int pos, int &num) {
    int degree = BPlusTreeNode::degree;
    if(currentNode.num >= degree) {
        // if it's root, create a new parent
        if(currentNode.parentNode == 0) {
            int addr = pager.applySpace();
            BPlusTreeNode newParent = BPlusTreeNode(pager, 0, false, 0, addr);
            newParent.insert(newParent.children, 0, currentNode.currentAddr);
            pager.write(addr, (char *) &newParent, sizeof(newParent));
            currentNode.parentNode = addr;
            changeRoot(addr);
        }
        // find free block to store new node
        int address = storage.getBlockAddr();
        if(address == 0) {
            address = pager.applySpace();
        }
        BPlusTreeNode newNode = BPlusTreeNode(pager, currentNode.parentNode, currentNode.isLeaf, degree - degree / 2, address);
        currentNode.num = degree / 2;

    } else {

    }
}

void BPlusTree::changeRoot(int addr) {
    rootAddr = addr;
}

void BPlusTree::insertToArr(std::vector<int> &vec, int pos, int number) {
//    for(int i = (int)vec.size() - 1; i > pos; i --) {
//        vec[i] = vec[i - 1];
//    }
//    vec[pos] = number;
    vec.insert(vec.begin() + pos, number);
}


