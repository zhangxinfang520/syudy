//@Time : 2021-07-05 11:55
//@Author: zxf_ҪŬ��
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
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem(){
    cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
};

void SpeechManager::initSpeech(){
    this->v1.clear();
    this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_Index = 1;
}

void SpeechManager::createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "ѡ��";
        name += nameSeed[i];
        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; ++j) {
            sp.m_Score[j] = 0;
        }

        this->v1.push_back(i+10001);
        //ѡ�ֱ���Լ���Ӧ��ѡ�ִ�ŵ�map������
        this->m_Speaker.insert(make_pair(i+10001,sp));
    }
};

void SpeechManager:: startSpeech(){
    //��һ�ֱ���
    this->initSpeech();
    this->createSpeaker();
	//1����ǩ
	this->speechDraw();
	//2������
	this->speechContest();
	//3����ʾ�������
    this->showScore();
	//�ڶ��ֱ���
	this->m_Index ++;
	//1����ǩ
    this->speechDraw();
	//2������
	this->speechContest();
	//3����ʾ���ս��
	this->showScore();
	//4���������
	this->saveRecord();

	this->loadRecord();
	cout<<"speech finish"<<endl;
	system("pause");
	system("cls");
};

void SpeechManager::speechDraw(){
    cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ"<<endl;
    cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
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
    cout << "------------- ��"<< this->m_Index << "����ʽ������ʼ��------------- " << endl;
    multimap<double, int,greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ��

    int num = 0 ; //��¼��Ա����6��Ϊ1��
    vector<int> v_Src;
    if(this->m_Index==1){
        v_Src = this -> v1;
    }else{
        v_Src = this -> v2;
    }
    //�������в���ѡ��
    for(int id:v_Src){
        num ++;
        //��ί���
        deque<double> d;
        for (int i = 0; i < 10; ++i) {
               double score = (rand() % 401 + 600) / 10.f;
               d.push_back(score);
        }
        sort(d.begin(), d.end(),greater<int>());
        d.pop_front();//ȥ����߷�
        d.pop_back();//ȥ����ͷ�
        double sum = accumulate(d.begin(), d.end(),0.0f);

        double avg = sum / (double)d.size();//��ȡƽ��ֵ
        // ÿһ���˵ķ���
        this->m_Speaker[id].m_Score[this->m_Index - 1] = avg;
        //6����һ�飬����ʱ��������
        groupScore.insert(make_pair(avg,id));

        if(num % 6 == 0){
            cout << "��" << num / 6 << "С��������Σ�" << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " << this->m_Speaker[it->second].m_Name << " �ɼ��� " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
            int count = 0;
            //ȡǰ����
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
    cout << "------------- ��" << this->m_Index << "�ֱ������  ------------- " << endl;
};

void SpeechManager::showScore(){
    cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
    vector<int> v;
    if (this->m_Index == 1){
        v =this->v2;
    }else{
        v = this->vVictory;
    }
    for (int id:v){
        cout << "ѡ�ֱ�ţ� "<< id <<"������"<< this->m_Speaker[id].m_Name
        <<"������ "<<this->m_Speaker[id].m_Score[this->m_Index-1]<<endl;
    }
    cout <<endl;
    system("pause");
	system("cls");
	this->show_Menu();
};

void SpeechManager::saveRecord(){
    ofstream ofs;
    ofs.open("speech.csv",ios::out|ios::app);// ������ķ�ʽ���ļ�  -- д�ļ�
    for (int id:this->vVictory){
        ofs << id << ","<<this->m_Speaker[id].m_Score[1]<<",";
    }
    ofs<<endl;
    ofs.close();
    cout << "��¼�Ѿ�����" << endl;
}

void SpeechManager::loadRecord(){
    ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�
    if(!ifs.is_open()){
        this->fileIsEmpty = true;
        cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "�ļ�Ϊ��!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
    }
    //�ļ���Ϊ��
    this->fileIsEmpty = false;
    ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ
    string data;
    int index = 0;
    while(ifs >> data){
        vector<string>v;

		int pos = -1;
		int start = 0;
		while(true){
		    pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
    }
    ifs.clear();
}

//��ʾ����÷�
void SpeechManager::showRecord(){
    for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "�� " <<
			"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
			"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
			"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
	}
    system("pause");
	system("cls");
};

void SpeechManager::clearRecord(){
    cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;

	if (select == 1){
	    //��ģʽ ios::trunc �������ɾ���ļ������´���
	    ofstream  ofs("speech.csv",ios::trunc);
	    ofs.close();
	    //��ʼ������
	    this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        this->m_Record.clear();
        cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
};

SpeechManager::~SpeechManager() {

}