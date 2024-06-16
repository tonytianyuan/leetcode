#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>> mapIdx;

        for(int i=0;i<s.length();++i){
            mapIdx[s[i]].push_back(i);
        }
        int res = s.length() + 1;
        for(auto ele : mapIdx){
            if(ele.second.size() == 1 && ele.second.at(0) < res){
                res = ele.second.at(0);
            }
        }
        if(res == (s.length() + 1))
            res = -1;
        return res;
    }
};
#if 0
int main(){
    Solution sol;

    int res;
    string a = "aabb";
    res = sol.firstUniqChar(a);
    cout<<res<<endl;

    return 0;
}
#endif