//
//  CSuccessor.cpp
//  quick-find
//
//  Created by 陈树沛 on 08/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#include "CSuccessor.hpp"
#include <exception>
#include <iostream>

CSuccessor::CSuccessor(int N) {
    num = N;
    id = new int[N];
    isRemove = new bool[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
        isRemove[i] = false;
    }
}

CSuccessor::~CSuccessor() {
    delete [] id;
    delete [] isRemove;
}

int CSuccessor::Root(int p) {
    while (p != id[p]) {
        p = id[p];
    }
    return p;
}

void CSuccessor::Union(int p, int q) {
    int proot = Root(p);
    int qroot = Root(q);
    if (qroot == proot) {
        return;
    } else if (proot > qroot) {
        id[qroot] = proot;
    } else {
        id[proot] = qroot;
    }
}

void CSuccessor::Remove(int p) {
    isRemove[p] = true;
    if (p > 0 && isRemove[p-1]) {
        Union(p, p-1); //将相邻的移除树联合起来
    }
}

int CSuccessor::GetSuccessor(int p) {
    if (p < 0 || p > num - 1) {
        std::cout << "访问过界" << std::endl;
        return -1;
    } else {
        if (isRemove[p]) {
            if (Root(p) >= num - 1) {
                return -1;
            } else {
                return Root(p) + 1;
            }
        } else {
            return p;
        }
    }
}












