#include<string>
#include<iostream>
#include<vector>
using namespace std;

//int a=0,b=0;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> a,b,c;
        string stringBasic = "(";
        string tmp1,tmp2;
        if(n == 0){
            b.push_back("");
            return b;
        }
        for(int i=0;i<n;i++){
            a = generateParenthesis(i);
            b = generateParenthesis(n-i-1);
            for(int j=0;j< a.size();++j)
                for(int k=0;k < b.size();++k){
                    c.push_back("("+a[j]+")"+ b[k]);
                }
        }
        return c;
    }
};

int main()
{
    Solution sol;
    int n=4;

    vector<string> vStr;
    vStr = sol.generateParenthesis(n);

    for(int i=0;i<vStr.size();i++)
        cout<<vStr[i]<<",";
    cout<<endl;
    
}