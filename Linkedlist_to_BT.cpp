//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 10, Project 9
//  3/13/2016
//  Linked list to Binary Tree

#include "bt_class.h"
#include "list.h"
#include <iostream>
using namespace std;

//turn binary search tree to priority queue
template <typename T>
binary_tree<T> *turnToBTree(List<T> &list){
    list.start();
    if (list.size() == 0){
        return NULL;
    }
    return loop(list, 0, list.size()-1);;
}

//inorder traverse and push into queue to make priority queue
template <typename T>
binary_tree<T>* loop(List<T> &list, int start, int end){
    if (start > end){
        return NULL;
    }
    int mid = start + (end - start) / 2;
    binary_tree<T> *left = loop(list, start, mid-1);
    binary_tree<T> *root = new binary_tree<T>(list.current());
    list.advance();
    binary_tree<T> *right = loop(list, mid+1, end);
    root->add_left_tree(left);
    root->add_right_tree(right);
    return root;
}

int main(){
    List<int> list;
    for(int i = 1; i < 32; i++){
        list.end();
        list.attach(i);
    }
    list.start();

    binary_tree<int>* bt = turnToBTree(list);
    print(bt->root, 3);
    return 0;
}
