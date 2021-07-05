//@Time : 2021-07-05 11:55
//@Author: zxf_要努力
//@File : speechManager.h
//
#pragma once
#ifndef C___SPEECHMANAGER_H
#define C___SPEECHMANAGER_H

#include "iostream"
#include "speaker.h"
#include "algorithm"
#include "fstream"
#include "ctime"
#include <vector>
#include <map>
#include <deque>

using namespace std;

class SpeechManager {
public:
    //构造函数
    SpeechManager();
    //显示系统
    void show_Menu();
    //初始话属性
    void initSpeech();
    //退出系统
    void exitSystem();
    //创建选手
    void createSpeaker();
    //开始比赛
    void startSpeech();
    //抽签
    void speechDraw();
    //比赛
    void speechContest();
    //显示结果
    void showScore();
    //保存结果
    void saveRecord();
    //读取结果
    void loadRecord();
    //显示往届得分
    void showRecord();
    //清空记录
    void clearRecord();
    //析构函数
    ~SpeechManager();
public:
    //比赛选手 容器  12人
    vector<int> v1;
    //第一轮晋级容器  6人
    vector<int> v2;
    //胜利前三名容器  3人
    vector<int> vVictory;
    //存放编号 以及对应的 具体选手 容器
    map<int,Speaker> m_Speaker;
    //比赛轮数
    int m_Index;
    //文件为空标志
    bool fileIsEmpty;

    //往届记录
    map<int,vector<string>> m_Record;

};


#endif //C___SPEECHMANAGER_H
