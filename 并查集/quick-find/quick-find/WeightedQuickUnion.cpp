//
//  WeightedQuickUnion.cpp
//  quick-find
//
//  Created by 陈树沛 on 03/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#include "WeightedQuickUnion.hpp"
WeightedQuickUnion::WeightedQuickUnion(int N) {
    id = new int[N];
    size = new int[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
        size[i] = 1; //存储权数
    }
}

int WeightedQuickUnion::root(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]]; //路径压缩: 将每个被查询的结点合并到他的根结点，下次查询该结点速度会变快
        i = id[i]; //花费时间最多环节
    }
    return i;
}

bool WeightedQuickUnion::connected(int p, int q) {
    return (root(p) == root(q));
}

void WeightedQuickUnion::unionUF(int p, int q) {
    int proot = root(p);
    int qroot = root(q);
    if (proot == qroot) {
        return;
    }
    if (size[qroot] < size[proot]) {
        id[qroot] = proot; //小树合并到大树上
        size[proot] += size[qroot];
    } else {
        id[proot] = qroot;
        size[qroot] += size[proot];
    }
}
