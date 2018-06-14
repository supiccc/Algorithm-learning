//
// Created by 陈树沛 on 23/05/2018.
//

#ifndef MERGE_H
#define MERGE_H
#include <iostream>

namespace supi {
    template <class T>
    class Merge {

    public:
        static bool sort(T* comparable, int len);

    private:
        static void sort(T* comparable,T* aux, int low, int high);
        static void merge(T* comparable, T* aux, int low, int mid, int high);
    };

    template <class T>
    bool Merge<T>::sort(T* comparable, int len) {
        T* aux = new T[len];
        sort(comparable, aux, 0,len-1);
        delete[] aux;
        return true;
    }

    template <class T>
    void Merge<T>::sort(T* comparable,T* aux, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            sort(comparable, aux, low, mid);
            sort(comparable, aux,mid+1, high);
            merge(comparable, aux, low, mid, high);
        }
    }

    template <class T>
    void Merge<T>::merge(T* comparable, T* aux, int low, int mid, int high) {
        int front = low, rear = mid+1;

        for (int i = low; i <= high; ++i) {
            aux[i] = comparable[i];
        }


        for (int j = low; j <= high; ++j) {
            if (front > mid) comparable[j] = aux[rear++];
            else if (rear > high) comparable[j] = aux[front++];
            else if (aux[front] <= aux[rear]) comparable[j] = aux[front++];
            else if (aux[front] > aux[rear]) comparable[j] = aux[rear++];
            else continue;
        }
    }

    template <class T>
    void testMergeSort(T* b) {
        Merge<char>::sort(b, 3);
        for (int j = 0; j < 3; j++) {
            std::cout << b[j] << " ";
        }
    }
}


#endif //MERGE_H
