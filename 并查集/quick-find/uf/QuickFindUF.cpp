//
//  QuickFindUF.cpp
//  quick-find
//
//  Created by 陈树沛 on 02/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#include "QuickFindUF.hpp"


QuickFindUF::QuickFindUF(int N) {
    id = new int[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }
}

bool QuickFindUF::connected(int p, int q) {
    return (id[p] == id[q]);
}

void QuickFindUF::unionUF(int p, int q, int N) {
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < N; i++) {
        if (id[i] == pid) {
            id[i] = qid;
        }
    }
}
