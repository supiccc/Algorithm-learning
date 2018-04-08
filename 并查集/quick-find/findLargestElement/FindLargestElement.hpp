//
//  FindLargestElement.hpp
//  quick-find
//
//  Created by 陈树沛 on 08/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#ifndef FindLargestElement_hpp
#define FindLargestElement_hpp

#include <stdio.h>
#include "WeightedQuickUnion.hpp"
class FindLargestElement : public WeightedQuickUnion {
public:
    FindLargestElement(int);
    void unionUF(int, int);
    int find(int);
    ~FindLargestElement() {delete [] max;}
private:
    int * max;
};
#endif /* FindLargestElement_hpp */
