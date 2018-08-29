//
// Created by 陈树沛 on 2018/8/26.
//

#ifndef ARRAY_SOLUTION_H
#define ARRAY_SOLUTION_H

#include <iostream>
#include <vector>

class Solution{
public:
    /*
     * 题目描述：
     * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入
     * 这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     * */
    bool Find(int target, std::vector<std::vector<int>> array) {
        if (array.empty()) return false;
//        if (target < array[0][0]) return false;
        int i = (int)array.size() - 1, j = 0;
        while (i >= 0 && j < array[i].size()) {
//            if (array[i].empty()) return false;
            if (target == array[i][j]) {
                return true;
            } else if (target < array[i][j]) {
                i--;
            } else if (target > array[i][j]) {
                j++;
            }
        }
        return false;
    }

};
#endif //ARRAY_SOLUTION_H
