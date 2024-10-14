#pragma once
#include "MyClass.h"

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
ostream& operator<<(ostream& cout, Box& box) {
    cout << "(" << box.x << ", " << box.y << ")" << " ";
    return cout;
}
void printVector(vector<Box>& v) {
    for (vector<Box>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

bool isPositionInVector(const Pos& temp, const std::vector<Pos>& positions) {
    for (const auto& pos : positions) {
        if (pos.x == temp.x && pos.y == temp.y) {
            return true;
        }
    }
    return false;
}

void PrintMap(int* arr, int rows, int cols) {
    cout<<"迷宫数组如下：" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // 使用指针算术来访问元素
            if (*(arr + i * cols + j)==1) {
                cout << "*" << " ";
            }
            else if (*(arr + i * cols + j) == -1) {
                cout << "#" << " ";
            }
            else {
                cout << " " << " ";
            }
        }
        cout << endl;
    }
}

void PrintWay(Stack<Box>& stack) {
    cout << "迷宫路径如下：" << endl;
    Stack<Box> copy(stack);
    vector<Box> v;
    while (!copy.Empty()) {
        v.push_back(copy.Pop());
    }
    reverse(v.begin(), v.end());
    printVector(v);
}

void PrintMap(int* arr, int rows, int cols,Stack<Box>&stack) {
    cout << "迷宫图解如下：" << endl;
    vector<Pos> positions;
    while (!stack.Empty()) {
        Box temp = stack.Pop();
        Pos pos(temp.x,temp.y);
        positions.push_back(pos);
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Pos temp(i, j);
            if (isPositionInVector( temp, positions)) {
                cout << "6" << " ";
            }else if (*(arr + i * cols + j) == 1) {
                cout << "*" << " ";
            }
            else {
                cout << " " << " ";
            }
        }
        cout << endl;
    }
}

