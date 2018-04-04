//
//  QuickUnion.cpp
//  quick-find
//
//  Created by 陈树沛 on 03/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#include "QuickUnion.hpp"
QuickUnion::QuickUnion(int N) {
    id = new int[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }
}

int QuickUnion::root(int i) {
    while (i != id[i]) {
        i = id[i];
    }
    return i;
}

bool QuickUnion::connected(int p, int q) {
    return (root(p) == root(q));
}

void QuickUnion::unionUF(int p, int q) {
    int proot = root(p);
    int qroot = root(q);
    id[proot] = qroot;
}
