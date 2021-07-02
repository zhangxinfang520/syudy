//@Time : 2021-07-02 9:32
//@Author: zxf_要努力
//@File : 03.h
// 对Vector的容量的操作
#include "iostream"
#include <vector>
#include "algorithm"

using namespace std;

/*
 * `empty(); `                            //判断容器是否为空

* `capacity();`                      //容器的容量

* `size();`                              //返回容器中元素的个数

* `resize(int num);`             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

  				      //如果容器变短，则末尾超出容器长度的元素被删除。

* `resize(int num, elem);`  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

 			              //如果容器变短，则末尾超出容器长度的元素被删除


 * */

void printVector(vector<int> &v){
    for(int m: v){
        cout<< m <<endl;
    }
}

void test(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    printVector(v);
     //查看vector是否为空
     if(v.empty()){
         cout << "v is empty" << endl;
     }else{
         cout <<"v is not empty"<< endl;
         cout<<"v size "<< v.size()<<endl;
         cout<<"v capacity " << v.capacity()<<endl;

         v.resize(14,100);
         printVector(v);
         v.resize(5);
         printVector(v);

     }
}

int main(){
    test();


}

