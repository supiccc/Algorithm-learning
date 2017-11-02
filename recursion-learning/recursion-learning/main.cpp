//
//  main.cpp
//  recursion-learning
//
//  Created by 陈树沛 on 26/10/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <iostream>
using namespace std;
int recursion (int n) {
    if (n != 1) {
        return n * recursion(n - 1);
    } else {
        return 1;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    cout << recursion(n) << endl;
    return 0;
}
