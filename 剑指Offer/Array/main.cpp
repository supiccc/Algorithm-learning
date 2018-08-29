#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include "Solution.h"

using namespace std;
char str[100];
int N;
int main() {
    std::vector<std::vector<int>> a;
    std::vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    a.push_back(b);
    b.clear();
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    a.push_back(b);
    b.clear();
    b.push_back(3);
    b.push_back(4);
    b.push_back(5);
    a.push_back(b);
    Solution c;
    if (c.Find(0, a)) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }

}