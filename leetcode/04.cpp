//@Time : 2021-07-08 19:33
//@Author: zxf_要努力
//@File : 04.h
//
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if( n == 1){
            return matrix;
        }
        for (int i = 0; i < n / 2 ; ++i) {
            vector<int> tmp = matrix[i];
              matrix[i] = matrix[n-i-1];
             matrix[n-i-1] = tmp;
        }
        for (int i = 0; i < n ; ++i) {
            for (int j = i+1; j < n; ++j) {
                int one_temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = one_temp;
            }
        }
        return matrix;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = vector<vector<int>>({{1,2,3},{4,5,6},{7,8,9}});
    for( auto num : v){
        for(int n :num){
            cout << n <<" ";
        }
    }
    cout << endl;
    v = s.rotate(v);
     for(vector<int> num : v) {
         for (int n : num) {
             cout << n << " ";
         }
     }
     cout << endl;
}