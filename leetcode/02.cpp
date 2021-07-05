//@Time : 2021-07-05 19:16
//@Author: zxf_要努力
//@File : 02.h
//
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //这一种方法 容易溢出
    vector<int> plusOne(vector<int>& digits) {
        long long int i = 1;
        long long int sum = 0;
        reverse(digits.begin(),digits.end());
        long long int re = 0;
        for(int num : digits){
            re = i * num;
            sum += re;
            i *= 10;
        }
        vector<int> result;
        sum = sum + 1;
        int temp = 0;
        while (sum > 0){
           temp = sum % 10;
           result.push_back(temp);
           sum /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> othermethod(vector<int> &digits){
        for (int i = digits.size()-1; i >0 ; i--) {
            if(digits[i]!= 9){
                digits[i]++;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        vector<int> re(digits.size()+1,0);
        re[0] = 1;
        return re;
    }
};

int main(){
    Solution s;
    vector<int> v;
    vector<int> v1;
    v.push_back(9);
    v.push_back(8);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    for(int num:v){
        cout<< num << " ";
    }
    cout<< endl;
    v1 = s.plusOne(v);
    for(int num : v1){
        cout <<num<<" ";
    }
}

