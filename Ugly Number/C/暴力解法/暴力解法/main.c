//
//  main.c
//  暴力解法
//
//  Created by 陈树沛 on 08/09/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <stdio.h>
#define bool int
#define true 1
#define flase 0
int valid();
int get();

int main(int argc, const char * argv[]) {
    // insert code here...
    get(1500);
    //30s
    return 0;
}

bool valid(int x) {
    while (x % 2  == 0) {
        x /= 2;
    }
    while (x % 3 == 0) {
        x /= 3;
    }
    while (x % 5 == 0) {
        x /= 5;
    }
    if (x == 1) {
        return true;
    } else {
        return flase;
    }
}

int get(int n) {
    int x = 1;
    int i = 0;
    do {
        if (valid(x)) {
            i += 1;
            if (i == n) {
                printf("%d\n", x);
            }
        }
        x += 1;
    } while (i != n);
    return 0;
}

