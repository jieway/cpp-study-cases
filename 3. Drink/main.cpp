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
        cout << "ÖóË®" << endl;
    }
    void Brew(){
        cout << "³åÅÝ¿§·È" << endl;
    }
    void PourInCup(){
        cout << "µ¹Èë±­ÖÐ" << endl;
    }
    void PutSomething(){
        cout << "¼ÓÈëÌÇºÍÅ£ÄÌ" << endl;
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
        cout << "ÖóË®" << endl;
    }
    void Brew(){
        cout << "³åÅÝ²è" << endl;
    }
    void PourInCup(){
        cout << "µ¹Èë±­ÖÐ" << endl;
    }
    void PutSomething(){
        cout << "¼ÓÈëèÛè½" << endl;
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
    cout << "--------¿§·È---------" << endl;
    AbstractDrinking * ab = new Coffee();
    Test(ab);
    cout << "---------²è--------" << endl;
    AbstractDrinking *cd = new Tea();
    Test(cd);

    return 0;
}