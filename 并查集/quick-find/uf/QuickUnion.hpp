//
//  QuickUnion.hpp
//  quick-find
//
//  Created by 陈树沛 on 03/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#ifndef QuickUnion_hpp
#define QuickUnion_hpp

#include <stdio.h>
class QuickUnion {
public:
    QuickUnion(int);
    bool connected(int, int);
    void unionUF(int, int);
    ~QuickUnion(){ delete [] id; }
private:
    int * id;
    int root(int);
};
#endif /* QuickUnion_hpp */
