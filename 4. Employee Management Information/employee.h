#pragma once
#include <iostream>
using namespace std;
#include "worker.h"


// Ա����
class Employee:public Worker {
public:
    Employee(int id, string name, int dId);

    virtual void showInfo();

    virtual string getDeptName();

    ~Employee();
};