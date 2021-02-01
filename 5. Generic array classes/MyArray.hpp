#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
        cout << "�вι��캯������" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // ���
    MyArray(const MyArray& arr){
        cout << "�������캯������" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[this->m_Capacity];

        for(int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= ��ֹǳ��������
    MyArray& operator=(const MyArray& arr){
        cout << "op = ���캯������" << endl;
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

    // β�巨
    void Push_back(const T & val){
        if (this->m_Size == this->m_Capacity) {
            return;
        }
        this->pAddress[this->m_Size++] = val;
    }

    // βɾ��
    void Pop_Back(){
        if (this->m_Size == 0) {
            return;
        }
        this->m_Size--;
    }

    // [] ����
    T& operator[](const T & index){
        return this->pAddress[index];
    }

    // ������������
    int getCapacity(){
        return this->m_Capacity;
    }

    // �������� size
    int getSize(){
        return this->m_Size;
    }
    ~MyArray(){
        if(this->pAddress != NULL){
            cout << "�����������ã���" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T * pAddress;
    int m_Capacity; // ��������
    int m_Size;     // �����С
};