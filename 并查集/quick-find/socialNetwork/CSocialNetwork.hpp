//
//  CSocialNetwork.hpp
//  quick-find
//
//  Created by 陈树沛 on 07/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#ifndef CSocialNetwork_hpp
#define CSocialNetwork_hpp

#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include "WeightedQuickUnion.hpp"

class CSocialNetwork {
public:
    CSocialNetwork(int, std::string &);
    std::string GetEarliestConnectTime();
    ~CSocialNetwork() {delete m_uf;}
private:
    WeightedQuickUnion * m_uf;
    std::ifstream m_fin;
    std::vector<std::string> split(const std::string &str,const std::string &pattern);
};
#endif /* CSocialNetwork_hpp */
