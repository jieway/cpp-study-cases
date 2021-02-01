#include <iostream>
#include "MyArray.hpp"
using namespace std;

int main(){

    MyArray<int> arr1(5);

    // 拷贝构造
    // MyArray<int> arr2(arr1);

    // MyArray<int> arr3(100);

    // arr3 = arr1;

    for (int i = 0; i < 5; i++){
        arr1.Push_back(i);
    }

    for (int i = 0; i < arr1.getCapacity(); i++){
        cout << arr1[i] << " ";
    }

    cout << endl;
    cout << "数组 size （尾删前）：" << arr1.getSize() << endl;
    arr1.Pop_Back();
    cout << "数组 size （尾删后）：" << arr1.getSize() << endl;
    
    return 0;
}