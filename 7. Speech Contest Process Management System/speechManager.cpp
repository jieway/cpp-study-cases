#include <iostream>
#include "speechManager.h"

SpeechManager::SpeechManager(){

    this->initSpeech();

}

void SpeechManager::Show_Menu(){
    cout << "**********************" << endl;
    cout << "*** ��ӭ�μ��ݽ����� ***" << endl;
    cout << "*** 1. ��ʼ�ݽ�������***" << endl;
    cout << "*** 2. �鿴�����¼��***" << endl;
    cout << "*** 3. ��ձ�����¼��***" << endl;
    cout << "*** 0. �˳���������***" << endl;
    cout << "**********************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem(){
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech(){
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    // ��ʼ�������ִ�
    this->m_Index = 1;
}

void SpeechManager::createSpeaker(){

    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed; i++){
        string name = "ѡ��";
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