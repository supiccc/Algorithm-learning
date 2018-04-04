//
//  QuickFindUF.hpp
//  quick-find
//
//  Created by 陈树沛 on 02/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#ifndef QuickFindUF_hpp
#define QuickFindUF_hpp

#include <stdio.h>

class QuickFindUF {
private:
    int * id;
public:
    QuickFindUF(int);
    
    bool connected(int, int);
    
    void unionUF(int, int, int);
    
    ~QuickFindUF() {
        delete [] id;
    }
};
#endif /* QuickFindUF_hpp */
