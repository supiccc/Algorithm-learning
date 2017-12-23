//
//  main.cpp
//  melon
//
//  Created by 陈树沛 on 31/10/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <iostream>
int num = 0;
void melon(int i) {
    int m = 0;
    int n = m;
    while (m <= i) {
        n = m;
        if (n % 5 != 0) {
            n -= 1;
            if (n % 5 == 0 && n > 5) {
                n -= n/5;
                n -= 1;
                if (n % 5 == 0 && n > 5) {
                    n -= n/5;
                    n -= 1;
                    if (n % 5 == 0 && n > 5) {
                        n -= n/5;
                        n -= 1;
                        if (n % 5 == 0 && n > 5) {
                            n -= n/5;
                            n -= 1;
                            if (n % 5 ==0 && n > 5) {
                                std::cout << m << " ";
                                num++;
                            }
                        }
                    }
                }
            }
        }
        m++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    std::cin >> n;
    melon(n);
    if (num == 0) {
        std::cout << "impossible" << std::endl;
    }
    return 0;
}
