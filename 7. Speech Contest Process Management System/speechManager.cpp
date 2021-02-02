#include <iostream>
#include "speechManager.h"

SpeechManager::SpeechManager(){

    this->initSpeech();

}

void SpeechManager::Show_Menu(){
    cout << "**********************" << endl;
    cout << "*** 欢迎参加演讲比赛 ***" << endl;
    cout << "*** 1. 开始演讲比赛。***" << endl;
    cout << "*** 2. 查看往届记录。***" << endl;
    cout << "*** 3. 清空比赛记录。***" << endl;
    cout << "*** 0. 退出比赛程序。***" << endl;
    cout << "**********************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem(){
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech(){
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    // 初始化比赛轮次
    this->m_Index = 1;
}

void SpeechManager::createSpeaker(){

    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed; i++){
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;

        sp.m_Name = name;
        for (int i = 0; i < 2; i++){
            sp.m_Score[i] = 0;
        }
    }
}

SpeechManager::~SpeechManager(){

}