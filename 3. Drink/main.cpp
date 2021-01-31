#include <iostream>
using namespace std;

class AbstractDrinking {
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;

    void makeDrink() {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};


class Coffee: public AbstractDrinking {

public:
    void Boil() {
        cout << "��ˮ" << endl;
    }
    void Brew(){
        cout << "���ݿ���" << endl;
    }
    void PourInCup(){
        cout << "���뱭��" << endl;
    }
    void PutSomething(){
        cout << "�����Ǻ�ţ��" << endl;
    }

    void makeDrink() {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }

};

class Tea: public AbstractDrinking {

public:
    void Boil() {
        cout << "��ˮ" << endl;
    }
    void Brew(){
        cout << "���ݲ�" << endl;
    }
    void PourInCup(){
        cout << "���뱭��" << endl;
    }
    void PutSomething(){
        cout << "�������" << endl;
    }

    void makeDrink() {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }

};

void Test(AbstractDrinking * ab){

    ab->makeDrink();
    delete ab;
}

int main(){
    cout << "--------����---------" << endl;
    AbstractDrinking * ab = new Coffee();
    Test(ab);
    cout << "---------��--------" << endl;
    AbstractDrinking *cd = new Tea();
    Test(cd);

    return 0;
}