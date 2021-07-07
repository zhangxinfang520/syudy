//@Time : 2021-07-06 22:25
//@Author: zxf_要努力
//@File : 03.h
//
#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if(nums[j] == 0){
                i ++;
            }else if( i!= 0){
                nums[j-i] = nums[j];
                nums[j] = 0;
            }
        }
    }
};

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    Solution s;
    s.moveZeroes(v);
    for(int num:v){
        cout << num <<endl;
    }

}

