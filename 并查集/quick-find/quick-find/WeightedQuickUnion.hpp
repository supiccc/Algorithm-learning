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
    WeightedQuickUnion(int);
    bool connected(int, int);
    void unionUF(int, int);
    ~WeightedQuickUnion(){ delete [] id; delete [] size; }
private:
    int * id;
    int * size;
    int root(int);
};
#endif /* WeightedQuickUnion_hpp */
