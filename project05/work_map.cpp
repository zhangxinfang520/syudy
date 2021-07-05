//@Time : 2021-07-04 13:06
//@Author: zxf_ҪŬ��
//@File : work_map.h
//
//* ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//* Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
//* �����10��Ա�����䲿�ź͹���
//* ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
//* �ֲ�����ʾԱ����Ϣ
#include "iostream"
#include <vector>
#include "algorithm"
#include <map>
#include "string"
#include "ctime"

using namespace std;
//���ֶ���
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker{
public:
    string name;
    int  m_Salary;
};

void printVector(vector<Worker> &v){
    for (vector<Worker>::iterator i = v.begin(); i != v.end() ; ++i) {
        cout << "work name: " << (*i).name << " work salary: " << (*i).m_Salary<<endl;
    }
}
void  crate_worker_team(vector<Worker> &v){
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i <10 ; ++i) {
        Worker w;
        w.name = "emplyoee";
        w.name +=nameSeed[i];
        w.m_Salary = rand() %10000 + 10000;
        v.push_back(w);
    }
}

//Ա������
void setGroup(vector<Worker> &v,multimap<int,Worker> &m){

    for (vector<Worker>::iterator i = v.begin(); i !=v.end() ; ++i) {
        //�����������
        int deptid = rand() % 3;
        m.insert(make_pair(deptid,*i));
    }
}

void show_all_info(multimap<int,Worker> &w){
    cout << "�߻����ţ�" << endl;
    multimap<int,Worker>::iterator pos = w.find(CEHUA);
    int count = w.count(CEHUA);
    int index = 0;
    for (; index < count && pos!=w.end() ; index++,pos++) {
        cout << "name: " <<(*pos).second.name<<" salary: "
        <<(*pos).second.m_Salary<<endl;
    }
    cout << "--------" <<endl;
    cout << "�������ţ�" << endl;
    pos = w.find(MEISHU);
    count = w.count(MEISHU);
    index = 0;
    for (; index < count && pos!=w.end() ; index++,pos++) {
        cout << "name :" <<(*pos).second.name<<" salary: "
        <<(*pos).second.m_Salary<<endl;
    }
    cout << "--------" <<endl;
    cout << "�з����ţ�" << endl;
    pos = w.find(YANFA);
    count = w.count(YANFA);
    index = 0;
    for (; index < count && pos!=w.end() ; index++,pos++) {
        cout << "name : " <<(*pos).second.name<<" salary: "
        <<(*pos).second.m_Salary<<endl;
    }
    cout << "--------" <<endl;
}

void test(){
    srand((unsigned int) time(NULL));
    vector<Worker> v;
    crate_worker_team(v);
    printVector(v);
    multimap<int,Worker> w;
    setGroup(v,w);
    show_all_info(w);
}


int main(){
    test();
}


