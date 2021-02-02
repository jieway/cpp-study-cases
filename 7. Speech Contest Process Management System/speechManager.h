#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"

using namespace std;

class SpeechManager{
public:
    SpeechManager();

    // 显示菜单
    void Show_Menu();

    // 退出系统
    void exitSystem();

    // 初始化容器
    void initSpeech();

    // 创建选手
    void createSpeaker();

    ~SpeechManager();

    // 比赛选手容器 ， 12 人
    vector<int> v1;

    // 第一轮晋级容器 6 人
    vector<int> v2;

    // 胜利前三名容器 3 人
    vector<int> vVictory;

    // 存放编号，以及对应的具体选手容器
    map<int, Speaker> m_Speaker;

    // 记录比赛轮数
    int m_Index;

};