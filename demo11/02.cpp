//@Time : 2021-06-28 11:53
//@Author: zxf_要努力
//@File : 02.h
//函数模板练习
#include "iostream"
using namespace std;

template <class T>
void swapDate(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

//数组排序
template <class T>
void sort_Array(T arr[],int len){
    for (int i = 0; i < len; i++){
        int max = i;
        for (int j= i+1; j< len; j++){
            if(arr[max] < arr[j]){
                max = j;
            }
        }
        if (max!=i){
            //进行交换
            swapDate(arr[max],arr[i]);
        }
    }
}

template<class T>
void printArry(T arr[],int len){
    for (int i =0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void test(){
    char arrchar[] = "abcdswedf";
    int len = sizeof(arrchar) / sizeof(char);
    sort_Array(arrchar,len);
    printArry(arrchar,len);
    cout<<"----------"<<endl;
    int arrInt[] = {1,2,3,4,5,6};
    int int_len = sizeof(arrInt) / sizeof(int);
    sort_Array(arrInt,int_len);
    printArry(arrInt,int_len);

}
int main(){
    test();
}
