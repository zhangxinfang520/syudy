//@Time : 2021-07-05 11:54
//@Author: zxf_要努力
//@File : main.h
//演讲比赛
#include "speechManager.h"

int main(){
    //srand((unsigned int) time(NULL));
    SpeechManager sm;
    int choice;
    while(true){
        sm.show_Menu();
        cout << "请输入您的选择： " << endl;
        cin >> choice;
        switch(choice){
            case 1://开始比赛
//                for(map<int,Speaker>::iterator it=sm.m_Speaker.begin(); it!=sm.m_Speaker.end();it++){
//                    cout<< " id " <<(*it).first<<endl;
//                    cout<< " id " <<(*it).second.m_Name<<endl;
//                    cout<< " id " <<(*it).second.m_Score[0]<<endl;
//                }
                sm.startSpeech();
                break;
            case 2://查看记录
                sm.showRecord();
                break;
            case 3://清空记录
                sm.clearRecord();
                break;
            case 0://退出系统
                sm.exitSystem();
                break;
            default:
                system("cls");
                break;
        }
    }

}

