//
//  WeightedQuickUnion.hpp
//  quick-find
//
//  Created by 陈树沛 on 03/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#ifndef WeightedQuickUnion_hpp
#define WeightedQuickUnion_hpp

#include <stdio.h>
class WeightedQuickUnion {
public:
//    WeightedQuickUnion();
    WeightedQuickUnion(int);
    bool connected(int, int);
    void unionUF(int, int);
    int Getcount();
    ~WeightedQuickUnion(){ delete [] id; delete [] size; }
private:
    int * id; //存储该结点的父结点
    int * size; //存储该结点的权值
    int m_num;
    int m_count; //保存根结点的数量
    int root(int);
};
#endif /* WeightedQuickUnion_hpp */
