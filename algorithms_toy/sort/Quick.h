//
// Created by 陈树沛 on 28/05/2018.
//

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

#include <iostream>
#include <algorithm>

namespace supi {
    template <class T>
    class Quick {
    public:
        static void sort(T * comparable, int length);
        static void sort_dup(T * comparable, int length);

    private:
        static void sort(T * comparable, int left, int right);
        static int partition(T * comparable, int left, int right);
        static void sort_dup(T * comparable, int left, int right);
    };

    template <class T>
    void Quick<T>::sort(T *comparable, int length) {
        sort(comparable, 0, length - 1);
    }

    template <class T>
    void Quick<T>::sort_dup(T *comparable, int length) {
        sort_dup(comparable, 0, length - 1);
    }

    template <class T>
    void Quick<T>::sort(T *comparable, int left, int right) {
        if (left >= right) return;
        int j = partition(comparable, left, right);
        sort(comparable, left, j-1);
        sort(comparable, j+1, right);
    }

    template <class T>
    int Quick<T>::partition(T *comparable, int left, int right) {
        int i = left, j = right + 1;
        while (true) {
            while (comparable[++i] < comparable[left]) {
                if (i == right)
                    break;
            }
            while (comparable[--j] > comparable[left]) {
                if (j == left)
                    break;
            }

            if (i >= j) break;
            std::swap(comparable[i], comparable[j]);
        }
        std::swap(comparable[left], comparable[j]);
        return j;
    }

    template <class T>
    void Quick<T>::sort_dup(T *comparable, int left, int right) {
        if (left >= right) return;
        int lt = left, gt = right;
        T v = comparable[lt];
        int i = left;
        while (i <= gt) {
            if (comparable[i] < v) std::swap(comparable[i++], comparable[lt++]);
            else if (comparable[i] > v) std::swap(comparable[i], comparable[gt--]);
            else i++;
        }
        sort_dup(comparable, left, lt-1);
        sort_dup(comparable, gt+1, right);
    }

    template <class T>
    void testQuickSort(T *a) {
        Quick<int>::sort_dup(a, 9);
        for (int i = 0; i < 9; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}

#endif //SORT_QUICK_H
