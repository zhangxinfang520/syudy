//@Time : 2021-07-04 10:31
//@Author: zxf_要努力
//@File : demo17.h
//map 和 multimap 使用
#include "iostream"
#include <map>
#include "algorithm"

using namespace std;

//基本概念
// map中所有元素都是pair
// pair中第一个元素为key（键值），起到索引作用（不能重复），第二个元素为value（实值）
// 所有元素都会根据元素的键值自动排序
void printMap(map<int,int> &m){
    for (map<int,int>::iterator it = m.begin();  it!=m.end() ; it++) {
        cout << "map first key " << it->first << " map second value "<< it->second << endl;
    }
    cout << endl;
}

map<int,int> creat_map(){
    map<int,int> m;
    m.insert(pair<int,int>(1,2));
    m.insert(pair<int,int>(2,3));
    m.insert(pair<int,int>(4,5));
    m.insert(pair<int,int>(3,5));
    return m;
}
void test01(){
    //map 的构造
    map<int,int> m = creat_map();
    printMap(m);
    //拷贝构造
    map<int,int> m2(m);
    printMap(m2);
    //复制构造 其实函数返回值就是赋值构造
    map<int,int> m3;
    m3 = m;
    printMap(m3);
}

void test02(){
    //map的大小和交换
    //- `size();`          //返回容器中元素的数目
    //- `empty();`        //判断容器是否为空
    //- `swap(st);`      //交换两个集合容器
    map<int,int> m = creat_map();
    if (m.empty()){
        cout << " map is empty"<<endl;
    }else{
        cout << "map size " << m.size()<<endl;
    }
    map<int,int> m2;
    m2.insert(pair<int,int>(2,2));
    printMap(m);
    printMap(m2);
    m.swap(m2);
    printMap(m);
    printMap(m2);
}

void test03(){
    //插入和删除
    //- `insert(elem);`           //在容器中插入元素。
    //- `clear();`                    //清除所有元素
    //- `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
    //- `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    //- `erase(key);`            //删除容器中值为key的元素
    map<int,int> m = creat_map();
    printMap(m);
    m.insert(map<int,int>::value_type(3,30));
    m[50] = 50;
    printMap(m);
    //删除
    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);

    //清空
    m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);
}

void test04(){
    //查找与统计
    //- `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    //- `count(key);`                //统计key的元素个数
    map<int,int> m =creat_map();
    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end()){
        cout << " find key= "<<(*pos).first<< "value: "<<(*pos).second<<endl;
    }else{
        cout << " key not found"<<endl;
    }
    //统计
    int num = m.count(3);
    cout << "key 3 num: "<<num<<endl;
}

class MyCompare{
public:
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};

void test05(){
    //map 排序
    //- map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
    map<int,int,MyCompare> m;
    m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}

}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
}

