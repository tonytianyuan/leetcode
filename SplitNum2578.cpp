#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        int numSplit[2] = {0};
        string numS = to_string(num);
        sort(numS.begin(),numS.end());
        for(auto it = numS.begin();it < numS.end();++it){
            if(*it == '0'){
                numS.erase(it);
            }
        }
        int splitLen = numS.size() / 2;
        for(int i= 0;i < splitLen + numS.size()%2;++i){
            numSplit[0] += (int)(numS[2*i]- '0') * pow(10,splitLen - i - 1 + numS.size()%2);
        }
        for(int i= 0;i < splitLen;++i){
            numSplit[1] += (int)(numS[2*i + 1]- '0') * pow(10,splitLen - i - 1);
        } 
        return numSplit[0] + numSplit[1];
    }
};
#if 0
int main(){
    Solution sol;

    int res;
    int a = 100;
    res = sol.splitNum(a);
    cout<<res<<endl;

    return 0;
}
#endif