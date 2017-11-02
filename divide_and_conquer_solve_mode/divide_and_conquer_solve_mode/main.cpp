//
//  main.cpp
//  divide_and_conquer_solve_mode
//
//  Created by 陈树沛 on 02/11/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <iostream>
#include <algorithm>

void Split(int array[], int &left, int &right, int n) {
    int mid = n / 2;
    for (left = 0; left < mid; left++) {
        if (array[left] == array[mid]) {
            break;
        }
    }
    for (right = left + 1; right < n; right++) {
        if (array[right] != array[mid]) {
            break;
        }
    }
}

void GetMaxCountVar(int array[], int &max_count_var, int &max_count, int n) {
    int left = 0, right = 0;
    Split(array, left, right, n);
    int count = right - left;
    int mid = n / 2;
    if (count > max_count) {
        max_count = count;
        max_count_var = array[mid];
    }
    if (left + 1 > max_count) {
        GetMaxCountVar(array, max_count_var, max_count, left + 1);
    }
    if (n - right > max_count) {
        GetMaxCountVar(array + right, max_count_var, max_count, n - right);
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::sort(array, array + n);
    int max_count_var = array[0];
    int max_count = 0;
    GetMaxCountVar(array, max_count_var, max_count, n);
    std::cout << max_count_var << " " << max_count << std::endl;
    return 0;
}
