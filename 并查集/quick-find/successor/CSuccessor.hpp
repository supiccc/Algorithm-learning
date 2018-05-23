//
//  CSuccessor.hpp
//  quick-find
//
//  Created by 陈树沛 on 08/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#ifndef CSuccessor_hpp
#define CSuccessor_hpp

#include <stdio.h>
class CSuccessor {
public:
    CSuccessor(int);
    void Union(int, int);
    int Root(int);
    void Remove(int);
    int GetSuccessor(int);
    virtual ~CSuccessor();
private:
    int * id;
    bool * isRemove;
    int num;
};
#endif /* CSuccessor_hpp */
