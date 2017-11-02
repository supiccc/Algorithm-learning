//
//  main.cpp
//  full-permutation
//
//  Created by 陈树沛 on 20/10/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>

namespace permutation {
    using std::cout;
    using std::endl;
    using std::cin;
    int count = 0;
    
    void swap (char *a, char *b) {
        char tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
    int testRepeat (char *A, int k, int j) {
        if (j > k) {
            for (int i = k; i < j; i++) {
                if (A[j] == A[i]) {
                    return 0;
                }
            }

        }
        return 1;
    }
    
    void permutation (char *A, int k, int n) {
        if (k == n) {
            count += 1;
            cout << "第" << std::setw(2) << count << "种排列：";
            for (int i = 0; i <= n; i++) {
                cout << A[i] << ' ';
            }
            cout << endl;
        } else {
            for (int j = k; j <= n; j ++) {
                if (testRepeat(A, k, j)) {
                    swap(&A[k], &A[j]);
                    permutation(A, k + 1, n);
                    swap(&A[k], &A[j]);
                }

            }
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here..
    using namespace permutation;
    char A[] = "ABCDA";
    permutation::permutation(A, 0, (int)strlen(A) - 1);
    return 0;
}
