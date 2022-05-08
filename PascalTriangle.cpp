#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.resize(numRows);
        for(int i=0;i<numRows;++i){
            int j;
            ret[i].resize(i+1);
            ret[i][0] = 1;
            if(i == 0)
                continue;
            for(j=1;j<i;++j){
                // if(j < (i+1)/2){
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
                // }
                // else if((i+1)%2){
                //     ret[i].push_back(ret[i-1][j-1] + ret[i-1][j]);
                // }
                // else{
                //     ret[i].push_back(ret[i][j-(i+1)/2]);
                // }
            }
            ret[i][i] = 1;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    //vector<int> numArray = {-2,1,-3,4,-1,2,1,-5,4};
    int numRows = 5;
    vector<vector<int>> a;

    a = sol.generate(numRows);

    //cout<<a<<endl;
}