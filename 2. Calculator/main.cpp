#include <iostream>
using namespace std;

// û��ʹ�ö�̬��ʵ�ַ�ʽ
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

    // ��ͨ�ļӷ���ʵ�֣������Ͽ���ԭ��
    Calculator a;
    a.num1 = 1;
    a.num2 = 2;
    cout << a.getResult("+") << endl;
    
    // �ӷ�
    AbstractCalculator * c = new AddCalculator();
    c->num1 = 1;
    c->num2 = 2;
    cout << c->getResult() << endl;
    delete c;
    
    // ����
    AbstractCalculator * b = new SubCalculator();
    b->num1 = 1;
    b->num2 = 2;
    cout << b->getResult() << endl;
    delete b;

    return 0;
}