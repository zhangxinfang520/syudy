#include <iostream>

using namespace std;
// ������Ҫ ѧϰ�βκ�ʵ�ε�����
// ����Ϊ �β�
//��������
void swatch(int temp1,int temp2);

void swatch(int temp1,int temp2){
    cout<< "����ǰtemp1Ϊ:"<<temp1<<" ";
    cout<< "����ǰtemp2Ϊ:"<<temp2<<" ";
    //ֵ ���н���
    int temp = temp1;
    temp1 = temp2;
    temp2 = temp;
    cout<< "������temp1Ϊ:"<<temp1<<" ";
    cout<< "������temp2Ϊ:"<<temp2<<" ";
}

int main1() {

	int a = 5;
	int b = 6;
	cout<< a<<" ";
	cout<< b<<" ";
	swatch(a,b);
	cout<< a<<" ";
	cout<< b<<" ";
    return 0;
}

void test_dll(int a,int b){
    cout << a <<endl;
    cout << b <<endl;

}

int main(){
    main1();
}


