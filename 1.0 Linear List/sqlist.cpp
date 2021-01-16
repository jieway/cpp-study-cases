//
// Created by weijiew on 1/16/2021.
// 静态分配的顺序表

#include <iostream>
#define MaxSize 10
using namespace std;

typedef struct {
    ElemType data[MaxSize]; // 静态分配，采用数组实现！
    int length;             // 顺序表当前长度
}SqList;

void InitList(&L);          // 初始化表，构造空的线性表
void DestroyList(&L);       // 销毁操作，销毁线性表
void ListInsert(&L,i,e);    // 在表 L 中的第 i 个位置上插入指定元素 e
void ListDelete(&L,i,&e);   // 删除表第 i 个位置的元素，并用 e 返回删除的元素值。


int main() {
    cout << "aaa" << endl;
    return 0;
}

void InitList(&L) {          // 初始化表，构造空的线性表

}