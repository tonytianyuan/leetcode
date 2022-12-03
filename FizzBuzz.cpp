#include<string>
#include<iostream>
#include<vector>
using namespace std;

//int a=0,b=0;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1;i <= n; ++i){
            if(i%3 == 0 && i%5 == 0)
                res.push_back("FizzBuzz");
            else if(i%3 == 0)
                res.push_back("Fizz");
            else if(i%5 == 0)
                res.push_back("Buzz");
            else{
                res.emplace_back(to_string(i));
            }
        }
        return res;
    }
};
#if 0
int main()
{
    Solution sol;
    int n=15;

    vector<string> vStr;
    vStr = sol.fizzBuzz(n);

    for(int i=0;i<vStr.size();i++)
        cout<<vStr[i]<<",";
    cout<<endl;
    
}
#endif