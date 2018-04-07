//
//  CSocialNetwork.cpp
//  quick-find
//
//  Created by 陈树沛 on 07/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#include "CSocialNetwork.hpp"
#include <iostream>

CSocialNetwork::CSocialNetwork(int num, std::string &str) {
    m_uf = new WeightedQuickUnion(num);
    m_fin.open(str.c_str());
}

std::string CSocialNetwork::GetEarliestConnectTime() {
    std::string earliestConnectTime = "";
    std::string timestamp = "";
    std::string firstname = "";
    std::string secondname = "";
    char connect[25];
    while (m_fin.getline(connect, 25)) {
        std::vector<std::string> connectSplit = split(connect, " ");
        timestamp = connectSplit[0];
        firstname = connectSplit[1];
        secondname = connectSplit[2];
        if (m_uf->connected(std::atoi(firstname.c_str()), std::atoi(secondname.c_str()))){
            
        } else {
            m_uf->unionUF(std::atoi(firstname.c_str()), std::atoi(secondname.c_str()));
        }
        if (m_uf->Getcount() == 1) {
            earliestConnectTime = timestamp;
            break;
        }
    }
    return earliestConnectTime;
}

std::vector<std::string> CSocialNetwork::split(const std::string &str,const std::string &pattern)
{
    //const char * convert to char*
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str());
    std::vector<std::string> resultVec;
    char * tmpStr = strtok(strc, pattern.c_str());
    while (tmpStr != NULL)
    {
        resultVec.push_back(std::string(tmpStr));
        tmpStr = strtok(NULL, pattern.c_str());
    }
    
    delete[] strc;
    return resultVec;
}
