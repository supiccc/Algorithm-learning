//
//  main.c
//  tree
//
//  Created by 陈树沛 on 17/09/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TElemType;
typedef int Status;

#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef struct TNode{
    TElemType key;
    struct TNode *leftChild;
    struct TNode *rightChild;
    struct TNode *parent;
}TNode, *TNodePtr, Tree;

Status InitTree (Tree *T) {
    T = (TNodePtr)malloc(sizeof(TNode));
    if (!T) {
        exit(OVERFLOW);
    }
    T->key = 0;
    T->leftChild = T->parent = T->rightChild = NULL;
    return OK;
}

Status InsertTree (Tree *T, int x) {
    if (!T) {
        InitTree(T);
        T->key = x;
        return OK;
    }
    TNode *N = T;
    TNode *I = (TNodePtr)malloc(sizeof(TNode));
    I->key = x;
    I->leftChild = I->parent = I->rightChild = NULL;
    if (I->key < N->key) {
        N = N->leftChild;
        if (N) {
            InsertTree(N, x);
        }
    } else {
        N = N->rightChild;
        if (N) {
            InsertTree(N, x);
        }
    }
    
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
