#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"

using namespace std;

class SpeechManager{
public:
    SpeechManager();

    // ��ʾ�˵�
    void Show_Menu();

    // �˳�ϵͳ
    void exitSystem();

    // ��ʼ������
    void initSpeech();

    // ����ѡ��
    void createSpeaker();

    ~SpeechManager();

    // ����ѡ������ �� 12 ��
    vector<int> v1;

    // ��һ�ֽ������� 6 ��
    vector<int> v2;

    // ʤ��ǰ�������� 3 ��
    vector<int> vVictory;

    // ��ű�ţ��Լ���Ӧ�ľ���ѡ������
    map<int, Speaker> m_Speaker;

    // ��¼��������
    int m_Index;

};