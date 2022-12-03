#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romanDic = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int here,after;
        int result = 0;
        for(int i=0;i<s.length();i++){
            here = romanDic[s[i]];
            after = romanDic[s[i+1]];
            if(here >= after){
                result += here;
            }     
            else
                result -= here;
        }
        return result;
    }
};

#if 0
int main()
{
    Solution sol;
    string str = "MCMXCIV";
    int a;

    a = sol.romanToInt(str);

    cout<<a<<endl;
}
#endif