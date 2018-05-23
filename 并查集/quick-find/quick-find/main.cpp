//
//  main.cpp
//  quick-find
//
//  Created by 陈树沛 on 02/04/2018.
//  Copyright © 2018 supiccc. All rights reserved.
//

#include <iostream>
#include "CSocialNetwork.hpp"
#include "QuickFindUF.hpp"
#include "QuickUnion.hpp"
#include "FindLargestElement.hpp"
#include "CSuccessor.hpp"

int main(int argc, const char * argv[]) {
    
    /*    QuickFind     */
//    QuickFindUF U(2);
//    int a = 1;
//    int b = 0;
//    if (!U.connected(a, b)) {
//            std::cout << "Hello, World!\n";
//    }
//    return 0;

    
      /*  QuickUnion */
//    QuickUnion U(10);
//    int a = 2;
//    int b = 3;
//    int c = 4;
//    int d;
//    U.unionUF(a, b);
//    d = b;
//    if (U.connected(a, d)) {
//        std::cout << a << " connect to " << d << std::endl;
//    } else {
//        std::cout << a << " not connect to " << d << std::endl;
//    }
//    return 0;

    /* socialnetwork */
//    std::string filename = "socialnetworkinfo.txt";
//    CSocialNetwork socialNetwork(11, filename);
//    std::cout << "整个社交网络连在一起的时间是：" << socialNetwork.GetEarliestConnectTime() << std::endl;
    
    /* Find Largest Element */
//    FindLargestElement U(11);
//    U.unionUF(1, 2);
//    U.unionUF(0, 1);
//    U.unionUF(1, 10);
//    std::cout << U.find(3) << std::endl;
    
    
    /* Get Successor */
    CSuccessor successor(10);
    successor.Remove(9);
    std::cout << successor.GetSuccessor(9) << std::endl;
}















