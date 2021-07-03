//@Time : 2021-07-03 11:55
//@Author: zxf_要努力
//@File : main.h
//案例打分
//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
#include "iostream"
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;


class Person{
public:
    Person(string name,int age){
        this-> name = name;
        this-> age = age;
    }
    string name;
    int age;
};
void add_person(vector<Person> &v){
    string name = "ABCDE";
    for (int i = 0; i < 5 ; ++i) {
        string person_name = "student";
        person_name += name[i];
        int score = 0;
        Person p(person_name,score);
        v.push_back(p);
    }
}
void setSocre(vector<Person> &p){
    for (vector<Person>::iterator v = p.begin(); v!= p.end(); v++) {
        deque<int> scores;
        for(int i=0;i<10;i++){
            int score = rand() % 41 + 60;
            scores.push_back(score);
        }
        sort(scores.begin(),scores.end());
        scores.pop_front(); //删除第一个
        scores.pop_back(); //删除最后一个
        int sum = 0;
        for (deque<int>::const_iterator a =scores.begin() ; a!=scores.end() ; a++) {
             sum += *a;
        }
        int avg = sum / scores.size();
        v->age = avg;
    }
}

void test(){
    srand((unsigned int) time(NULL));
    vector<Person> v_person;
    add_person(v_person);

    for (vector<Person>::iterator i = v_person.begin(); i != v_person.end() ; ++i) {
        cout <<"person name "<< (*i).name <<" person age "<<(*i).age<<endl;
    }

    setSocre(v_person);
    for (vector<Person>::iterator i = v_person.begin(); i != v_person.end() ; ++i) {
        cout <<"person name "<< (*i).name <<" person age "<<(*i).age<<endl;
    }
}
int main(){

    test();
}

