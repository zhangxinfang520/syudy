//@Time : 2021-07-05 11:55
//@Author: zxf_要努力
//@File : speechManager.h
//

#include "speechManager.h"


SpeechManager::SpeechManager() {
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
}

void SpeechManager::show_Menu() {
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem(){
    cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
};

void SpeechManager::initSpeech(){
    this->v1.clear();
    this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//初始化比赛轮数
	this->m_Index = 1;
}

void SpeechManager::createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "选手";
        name += nameSeed[i];
        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; ++j) {
            sp.m_Score[j] = 0;
        }

        this->v1.push_back(i+10001);
        //选手编号以及对应的选手存放到map容器中
        this->m_Speaker.insert(make_pair(i+10001,sp));
    }
};

void SpeechManager:: startSpeech(){
    //第一轮比赛
    this->initSpeech();
    this->createSpeaker();
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示晋级结果
    this->showScore();
	//第二轮比赛
	this->m_Index ++;
	//1、抽签
    this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示最终结果
	this->showScore();
	//4、保存分数
	this->saveRecord();

	this->loadRecord();
	cout<<"speech finish"<<endl;
	system("pause");
	system("cls");
};

void SpeechManager::speechDraw(){
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签"<<endl;
    cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->m_Index ==1){
        random_shuffle(this->v1.begin(), this->v1.end());
        for(vector<int>::iterator it=this->v1.begin();it!=this->v1.end();it++){
            cout << *it << " ";
        }
        cout << endl;
	}else{
	    random_shuffle(this->v2.begin(), this->v2.end());
        for(vector<int>::iterator it=this->v2.begin();it!=this->v2.end();it++){
            cout << *it << " ";
        }
        cout << endl;
	}
	cout << "---------------------" << endl;
	cout << endl;
};

void SpeechManager::speechContest(){
    cout << "------------- 第"<< this->m_Index << "轮正式比赛开始：------------- " << endl;
    multimap<double, int,greater<int>> groupScore; //临时容器，保存key分数 value 选手编号

    int num = 0 ; //记录人员数，6个为1组
    vector<int> v_Src;
    if(this->m_Index==1){
        v_Src = this -> v1;
    }else{
        v_Src = this -> v2;
    }
    //遍历所有参赛选手
    for(int id:v_Src){
        num ++;
        //评委打分
        deque<double> d;
        for (int i = 0; i < 10; ++i) {
               double score = (rand() % 401 + 600) / 10.f;
               d.push_back(score);
        }
        sort(d.begin(), d.end(),greater<int>());
        d.pop_front();//去掉最高分
        d.pop_back();//去掉最低分
        double sum = accumulate(d.begin(), d.end(),0.0f);

        double avg = sum / (double)d.size();//获取平均值
        // 每一个人的分数
        this->m_Speaker[id].m_Score[this->m_Index - 1] = avg;
        //6个人一组，用临时容器保存
        groupScore.insert(make_pair(avg,id));

        if(num % 6 == 0){
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << " 姓名： " << this->m_Speaker[it->second].m_Name << " 成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
            int count = 0;
            //取前三名
            for(multimap<double,int,greater<int>>::iterator it = groupScore.begin(); it!=groupScore.end()&&count<3;count++,it++){
                if (this->m_Index == 1){
                    this->v2.push_back((*it).second);
                } else{
                    this->vVictory.push_back(it->second);
                }
            }
            groupScore.clear();
            cout << endl;
        }
        

    }
    cout << "------------- 第" << this->m_Index << "轮比赛完毕  ------------- " << endl;
};

void SpeechManager::showScore(){
    cout << "---------第" << this->m_Index << "轮晋级选手信息如下：-----------" << endl;
    vector<int> v;
    if (this->m_Index == 1){
        v =this->v2;
    }else{
        v = this->vVictory;
    }
    for (int id:v){
        cout << "选手编号： "<< id <<"姓名："<< this->m_Speaker[id].m_Name
        <<"分数： "<<this->m_Speaker[id].m_Score[this->m_Index-1]<<endl;
    }
    cout <<endl;
    system("pause");
	system("cls");
	this->show_Menu();
};

void SpeechManager::saveRecord(){
    ofstream ofs;
    ofs.open("speech.csv",ios::out|ios::app);// 用输出的方式打开文件  -- 写文件
    for (int id:this->vVictory){
        ofs << id << ","<<this->m_Speaker[id].m_Score[1]<<",";
    }
    ofs<<endl;
    ofs.close();
    cout << "记录已经保存" << endl;
}

void SpeechManager::loadRecord(){
    ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件
    if(!ifs.is_open()){
        this->fileIsEmpty = true;
        cout << "文件不存在！" << endl;
		ifs.close();
		return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "文件为空!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
    }
    //文件不为空
    this->fileIsEmpty = false;
    ifs.putback(ch); //读取的单个字符放回去
    string data;
    int index = 0;
    while(ifs >> data){
        vector<string>v;

		int pos = -1;
		int start = 0;
		while(true){
		    pos = data.find(",", start); //从0开始查找 ','
			if (pos == -1)
			{
				break; //找不到break返回
			}
			string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
    }
    ifs.clear();
}

//显示往届得分
void SpeechManager::showRecord(){
    for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届 " <<
			"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
			"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
			"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
	}
    system("pause");
	system("cls");
};

void SpeechManager::clearRecord(){
    cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;

	if (select == 1){
	    //打开模式 ios::trunc 如果存在删除文件并重新创建
	    ofstream  ofs("speech.csv",ios::trunc);
	    ofs.close();
	    //初始化属性
	    this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        this->m_Record.clear();
        cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
};

SpeechManager::~SpeechManager() {

}