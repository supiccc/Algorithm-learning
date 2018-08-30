//
// Created by 陈树沛 on 2018/8/29.
//

#ifndef STRING_SOLUTION_H
#define STRING_SOLUTION_H

#include <iostream>
#include <cstring>
class Solution{
public:
    /*
     * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
     * 则经过替换之后的字符串为We%20Are%20Happy。
     */
    void replaceSpace(char * str,int length) {
        if (str == nullptr || length < 0) return;
        int oldlen_ = 0, newlen_ = 0; // 保存旧字符串和新字符串的长度
        int spacenum_ = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            oldlen_++;
            if (str[i] == ' ') {
                spacenum_++;
            }
        }
        newlen_ = oldlen_ + 2 * spacenum_;
        if (newlen_ > length) return;
        // 不减1是因为要包含'\0'
        for (int j = oldlen_; j >= 0; --j) {
            if (str[j] != ' ') {
                str[newlen_--] = str[j];
            } else {
                str[newlen_--] = '0';
                str[newlen_--] = '2';
                str[newlen_--] = '%';
            }
        }
    }
};
#endif //STRING_SOLUTION_H
