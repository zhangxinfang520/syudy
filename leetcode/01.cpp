//@Time : 2021-07-04 22:44
//@Author: zxf_要努力
//@File : 01_重复数据.h
// 删除重复数据
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.size()==0 || nums1.size()==0){
            return result;
        }
        while (nums1.size()>0 && (nums2.size()>0)){
            int len = nums1.size();
            int temp = nums1[len-1];
            nums1.pop_back();
            vector<int>::iterator pos = find(nums2.begin(),nums2.end(),temp);
            if(pos == nums2.end()){
                continue;
            }else{
                result.push_back(temp);
                nums2.erase(pos);
            }

        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(1);
    nums1.push_back(2);
    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(2);

    vector<int> re = s.intersect(nums1,nums2);

    for(int num: re){
        cout << num <<endl;
    }
}