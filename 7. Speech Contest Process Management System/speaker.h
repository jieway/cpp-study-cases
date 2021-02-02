#pragma once
#include <iostream>
using namespace std;

class Speaker{
public:
    Speaker();
    
    string m_Name;
    // 分别存放两轮得分！
    double m_Score[2];

    ~Speaker();

};