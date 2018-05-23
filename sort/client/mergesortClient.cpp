#include <iostream>
#include "../func/Merge.h"

int main() {
    int a[] = {1, 3, 2, 2, 5};
    Merge<int>::sort(a, 5);
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    char b[] = {'a', 'c', 'b'};
    Merge<char>::sort(b, 3);
    for (int j = 0; j < 3; j++) {
        std::cout << b[j] << " ";
    }
}
