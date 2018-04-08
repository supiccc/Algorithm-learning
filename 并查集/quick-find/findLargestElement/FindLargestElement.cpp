//
//  FindLargestElement.cpp
//  quick-find
//
//  Created by 陈树沛 on 08/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#include "FindLargestElement.hpp"

FindLargestElement::FindLargestElement(int N) : WeightedQuickUnion(N) {
    max = new int[N];
    for (int i = 0; i < N; i++) {
        max[i] = i;
    }
}

void FindLargestElement::unionUF(int p, int q) {
    int proot = root(p);
    int qroot = root(q);
    if (proot == qroot) {
        return;
    }
    m_count -= 1;
    if (size[qroot] < size[proot]) {
        id[qroot] = proot; //小树合并到大树上
        size[proot] += size[qroot];
        if (qroot > proot) {
            max[proot] = max[qroot];
        } else {
            max[proot] = max[proot];
        }
    } else {
        id[proot] = qroot;
        size[qroot] += size[proot];
        if (max[qroot] > max[proot]) {
            max[qroot] = max[qroot];
        } else {
            max[qroot] = max[proot];
        }
    }
}

int FindLargestElement::find(int i) {
    int iroot = root(i);
    return max[iroot];
}






