#include <iostream>
#include <cmath>
#include "../sort/Merge.h"
#include "../sort/Quick.h"
#include "../dataStructure/SequentialSearchST.h"
//#include <exception>
#include "../message/MessageProtocol.h"
#include "Zhaoshan.h"

void solve1();
void solve2();
void solve3();
void solve4();

int main() {
//    int a[] = {1, 3, 2, 2, 5, 2, 2, 5, 5};
//    supi::testQuickSort(a);
//
//    char b[] = {'a', 'c', 'b'};
//    supi::testMergeSort(b);
//
//    supi::testSequentialSearchST();

//    supi::testEncodeVarint32(130);
//
//    supi::testEncodezigzag(2);
    Zhaoshan().solve7();
}

void solve1() {
    /*
     * 每位同学的步长不同，一位同学可以将物品传给下一位同学，下一位同学再传给下一位
     * 求第一位同学将手中的物品传到最后一位同学手里的步数的总步数。
     * 动态规划问题
     * */
    int n;
    std::cin >> n; // 长度
    std::vector<int> queue; // 存储队列
    std::vector<int> min;
    int tmp; // 输入字符中转
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        queue.push_back(tmp);
    }
    for (int k = 0; k < n; ++k) {
        min.push_back(n);
    }
    for (int j = n-1; j >= 0; --j) {
        if((j+queue[j]) < (n-1)) {
            for (int i = 1; i <= queue[j]; ++i) {
                min[j] = std::min(min[j], min[j+i] + 1);
            }
        } else {
            min[j] = 1;
        }
    }
    std::cout << min[0];
}

void solve2(){
    /*假设有几个系统，每个系统的运行时间已知，系统之间有不同的依赖关系，求系统之间的依赖数及
     * 每个依赖所需的运行时间；
     * 输入系统个数，依赖个数，系统运行时间，系统间依赖关系，输出系统间依赖关系数及最大运行时间
     * */
    int n, k; // n为系统个数，k为依赖关系树目
    int tmp; // 输入中转
    std::cin >> n;
    std::cin>> k;
    int sum = 0; // 记录链路数量
    std::vector<std::vector<int>> q; // 关系集
    struct node {
        int val; // 第几个系统
        int time; // 运行时间
        int flag = 0; // 是否是叶结点
        struct node* next;
    } ;
    struct node *no[20]; // 无法解决动态分配问题，只能先分配好！
//    std::vector<struct node*> no; // 无法解决动态分配问题
//    struct node *no[n]; // 无法解决动态分配问题
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        struct node* ptr = new(struct node);
        ptr->time = tmp;
        ptr->val = i + 1;
        ptr->next = nullptr;
        no[i] = ptr;
    }
    for (int j = 0; j < k; ++j) {
        std::vector<int> qq;
        for (int i = 0; i < 2; ++i) {
            std::cin >> tmp;
            qq.push_back(tmp);
        }
        q.push_back(qq);
        no[q[j][1]-1]->next = no[q[j][0]-1];
        no[q[j][0]-1]->flag = 1;
    }
    int max = 0;
    for (int l = 0; l < n; ++l) {
        if(!no[l]->flag) {
            int total = 0;
            struct node* p = no[l];
            sum++;
            total += p->time;
            while (p->next) {
                p = (p->next);
                total += p->time;
            }
            max = std::max(max, total);
        }
    }
    std::cout << sum << " " << max;
}

void solve3(){
    int n, g;
    int sum = 0, flag = 1;
    std::cin >> n;
    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
        std::cin >> g;
        a.push_back(g);
    }
    while (flag) {
        int j = 0;
        for (j = 0; j < n; ++j) {
            if(a[j] % 2 == 0) {
                a[j] /= 2;
                break;
            } else {
                a[j] *= 3;
            }
            if (j == n-1) flag = 0;
        }
        if (flag) {
            sum += 1;
            for (int i = j+1; i < n; ++i) {
                a[i] *= 3;
            }
        }
    }
    std::cout << sum;
}

void solve4() {
    unsigned long n, x, f, sum = 0;
    std::vector<unsigned long> s;
    std::cin >> n >> x;
    for (unsigned long i = 0; i < n; ++i) {
        std::cin >> f;
        s.push_back(f);
    }
    auto min = s[0];
    auto mindex = 0;
    for (unsigned long l = 1; l < s.size(); ++l) {
        if(s[l] <= min) {
            if (s[l] == min) {
                if (l < x) {
                    min = s[l];
                    mindex = l;
                } else if(mindex > x-1) {
                    min = s[l];
                    mindex = l;
                }
            } else {
                min = s[l];
                mindex = l;
            }

        }
    }
    if (mindex >= x) {
        for (int i = 0; i < x; ++i) {
            s[i] -= (min + 1);
            sum += min + 1;
        }
        for (int j = x; j <= mindex; ++j) {
            s[j] -= min;
            sum += min;
        }
        for (unsigned long k = mindex + 1; k < s.size(); ++k) {
            s[k] -= (min + 1);
            sum += min + 1;
        }
    } else {
        for (int i = 0; i <= mindex; ++i) {
            s[i] -= min;
            sum += min;
        }
        for (int j = mindex + 1; j < x; ++j) {
            s[j] -= (min + 1);
            sum += min + 1;
        }
        for (unsigned long k = x; k < s.size(); ++k) {
            s[k] -= min;
            sum += min;
        }
    }
    s[mindex] = sum;
    for (int m = 0; m < s.size(); ++m) {
        std::cout  << s[m] << " ";
    }
}