//
// Created by 陈树沛 on 2018/8/9.
//

#ifndef TOY_ZHAOSHAN_H
#define TOY_ZHAOSHAN_H

#include <iostream>
#include <cmath>
#include <cstring>

class Zhaoshan {
public:
    static void solve1() {
       int n, sum = 0;
       std::cin >> n;
       if (n <= 1) {
           std::cout << 0;
           exit(0);
       }
       if (n == 2) {
           std::cout << 1;
           exit(0);
       }
       if (n == 3) {
           std::cout << 2;
           exit(0);
       }
       while (n > 3) {
            n -= 2;
            sum += 1;
       }
       n = n * std::pow(2, sum);
       std::cout << n;

    }
    
    static void solve2() {
        int n;
        std::cin >> n;
        int *a = new int[n];
        int *b = new int[n];
        for (int l = 0; l < n; ++l) {
            b[l] = 0;
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int j = 0; j < n; ++j) {
            b[a[j]] = -1;
        }
        for (int k = 0; k < n; ++k) {
            if (b[k] == 0) {
                std::cout << k;
                exit(0);
            }
        }
    }

    static void solve3() {
        int n, sum = 0, m = 1;
        std::cin >> n;
        if (n == 0) {
            std::cout << 0;
            exit(0);
        }
        if (n < 0) {
            n = -n; // 将负数问题转换成正数问题
        }
        while (n > 1) {
            if(n % 2 == 1) {
                sum += 1;
                if (n == 3) {
                    n = n - 1; // 解决 3 的时侯出现错误
                } else if (((n+1)/2) % 2 == 0) {
                    n = n + 1; // 尽量使n除以2以后还是偶数
                } else {
                    n = n -1;
                }
            }
            n /= 2;
            sum += 1;
        }
        sum += 1;
        std::cout << sum;
    }

    static void solve5() {
        std::vector<char> s;
        char f;
        int l, r;
        std::cin >> f;
        s.push_back(f);
        while (f != '\n') {
            f = std::cin.get();
            s.push_back(f);
        }
        int len = s.size();
        int a, b=1, win=0;
        while (len > 1) {
            b += 1;
            if(len % b != 0) {
                a = len / b;
                for (int i = 1; i <= b; ++i) {
                    for (int j = 0; j < a; ++j) {
                        if (s[j] != s[j+a*i]) {
                            break;
                        }
                    }
                }

            }
        }
    }

    static void solve4() {
//        给出一个非空的字符串，判断这个字符串是否是由它的一个子串进行多次首尾拼接构成的。
        std::string s; // 输入字符串
        std::cin >> s;
        std::string reqs = ""; // 结果字符
        if (s.size() == 0) {
            std::cout << "false";
            exit(0);
        }
        int len = s.size();
        for (int i = 0; i < len - 1; ++i) {
            if(s[i] == s.back()) {
                std::string tmps = s.substr(0, i + 1);
                int tmplen = tmps.size();
                if(len % tmplen != 0) {
                    continue;
                }
                int cou = len / tmplen;
                int j;
                for (j = 0; j < cou; ++j) {
                    if (s.substr(tmplen*j, tmplen) != tmps) break;
                }
                if (j == cou) {
                    reqs = tmps;
                }
            }
        }
        if (reqs == "") {
            std::cout << "false";
            exit(0);
        }
        std::cout << reqs;
    }

    static void process(std::string & s, std::vector<std::string> &req, int l, int r, int n) {
        if (l >= n && r >= n) {
            // 符合条件的插入vector
            req.push_back(s);
            return;
        }

        if (l < n) {
            // 先插入'（'
            s.push_back('(');
            process(s, req, l+1, r, n);
            s.pop_back();
        }

        if (l > r) {
            s.push_back(')');
            process(s, req, l, r+1, n);
            s.pop_back();
        }
    }

    static void solve7() {
        //给出一个正整数n，请给出所有的包含n个'('和n个')'的字符串，使得'('和')'可以完全匹配。
        int n;
        std::string s;
        std::vector<std::string> req;
        std::cin >> n;
        process(s, req, 0, 0, n);
        std::cout << req.front();
        for (int i = 1; i < req.size(); ++i) {
            std::cout << ',' << req[i];
        }
    }

//    static void solve8(){
//        int n;
//        std::vector<int[2]> res;
//        std::cin >> n;
//        int a[2];
//        char b;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < 2; ++j) {
//                std::cin >> a[j];
//                std::cin >> b;
//            }
//        }
//    }

    static void solve9(){
        int n, tmp;
        std::vector<int> scorePersonal;
        std::vector<int> scoreTeam;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            scorePersonal.push_back(tmp);
            std::cin >> tmp;
            scoreTeam.push_back(tmp);
        }

    }
};


#endif //TOY_ZHAOSHAN_H
