#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
        cout << "有参构造函数！！" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 深拷贝
    MyArray(const MyArray& arr){
        cout << "拷贝构造函数！！" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[this->m_Capacity];

        for(int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝问题
    MyArray& operator=(const MyArray& arr){
        cout << "op = 构造函数！！" << endl;
        if(this->pAddress != NULL){
            delete[] this->pAddress;
            this->m_Size = 0;
            this->m_Capacity = 0;
            this->pAddress = NULL;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];

        for (int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    // 尾插法
    void Push_back(const T & val){
        if (this->m_Size == this->m_Capacity) {
            return;
        }
        this->pAddress[this->m_Size++] = val;
    }

    // 尾删法
    void Pop_Back(){
        if (this->m_Size == 0) {
            return;
        }
        this->m_Size--;
    }

    // [] 重载
    T& operator[](const T & index){
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity(){
        return this->m_Capacity;
    }

    // 返回数组 size
    int getSize(){
        return this->m_Size;
    }
    ~MyArray(){
        if(this->pAddress != NULL){
            cout << "析构函数调用！！" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T * pAddress;
    int m_Capacity; // 数组容量
    int m_Size;     // 数组大小
};