//
// Created by 陈树沛 on 11/06/2018.
// 单向链表实现搜索树

#ifndef TOY_SEQUENTIALSEARCHST_H
#define TOY_SEQUENTIALSEARCHST_H

#include <iostream>
namespace supi {
    template <class K, class V>
    class SequentialSearchST {
    private:
        typedef struct node {
            V value;
            K key;
            struct node *next;
        } Node;
        Node * first;
    public:
        SequentialSearchST(){ first = nullptr; }
        void put(K key, V value);
        V get(K key);
        ~SequentialSearchST();
        bool isEmpty(){ return first == nullptr; }
    };

    template <class K, class V>
    void SequentialSearchST<K, V>::put(K key, V value) {
        if (first == nullptr) {
            first = new Node();
            first->key = key;
            first->value = value;
            first->next = nullptr;
        } else {
            for (Node *i = first; i != nullptr ; i = i->next) {
                if (i->key == key) {
                    i->value = value;
                    return;
                }
            }
            Node *n = new Node();
            n->value = value;
            n->key = key;
            n->next = first;
            first = n;
        }
    }

    template <class K, class V>
    V SequentialSearchST<K, V>::get(K key) {
        Node *p = first;
        while (p) {
            if (p->key == key) {
                return p->value;
            }
            p = p->next;
        }
        throw "ST have no this key!";
    }

    template <class K, class V>
    SequentialSearchST<K, V>::~SequentialSearchST() {
        Node *p = first;
        while (first) {
            p = first;
            first = first->next;
            delete p;
        }
    }

    void testSequentialSearchST() {
        try {
            SequentialSearchST<char, int> s;
            std::cout << "\nloading SequentialSearchST...\n";
            std::cout << "Inserted ('a', 2), ('a', 4) , ('c', 6)\n";
            s.put('a', 2);
            s.put('a', 4);
            s.put('b', 6);
            std::cout << "Now get('a'): ";
            std::cout << s.get('a') << "\n";
            std::cout << "Now get('c'): " << s.get('c') << '\n';
        } catch (const char* message){
            std::cerr << message << std::endl;
        }
    }
}


#endif //TOY_SEQUENTIALSEARCHST_H
