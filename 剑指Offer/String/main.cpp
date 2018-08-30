#include <iostream>
#include "Solution.h"

int main() {
    Solution a;
    char re[100] = "My name is";
    a.replaceSpace(re, 100);
    for (int i = 0; re[i] != '\0'; ++i) {
        std::cout << re[i];
    }
    return 0;
}