#include <iostream>
using namespace std;

// 没有使用多态的实现方式
class Calculator {
public:
    int getResult(string oper){
        if (oper == "+") {
            return num1 + num2;
        }else if (oper == "-") {
            return num1 - num2;
        }else if (oper == "*") {
            return num1 * num2;
        }else if (oper == "/") {
            return num1 / num2;
        }
    }
    int num1;
    int num2;
};

class AbstractCalculator{
public:
    virtual int getResult() {
        return 0;
    }
    int num1;
    int num2;
};

class AddCalculator : public AbstractCalculator{
public:
    int getResult() {
        return num1 + num2;
    }
};

class SubCalculator : public AbstractCalculator{
public:
    int getResult() {
        return num1 - num2;
    }
};

int main(){

    // 普通的加法的实现，不符合开闭原则。
    Calculator a;
    a.num1 = 1;
    a.num2 = 2;
    cout << a.getResult("+") << endl;
    
    // 加法
    AbstractCalculator * c = new AddCalculator();
    c->num1 = 1;
    c->num2 = 2;
    cout << c->getResult() << endl;
    delete c;
    
    // 减法
    AbstractCalculator * b = new SubCalculator();
    b->num1 = 1;
    b->num2 = 2;
    cout << b->getResult() << endl;
    delete b;

    return 0;
}