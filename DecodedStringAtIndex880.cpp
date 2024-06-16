#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string final,tmp,output;
        for(int i=0;i < s.size();++i){
            if(s[i] >= '2' && s[i] <= '9'){
                
            }
        }
        output.push_back(final.at(k-1));
        return output;
    }
};


#if 0
int main()
{
    Solution sol;
    /*string input = "a2345678999999999999999";
    int k = 1000000000;*/
    string input = "leet2code3";
    int k = 10;

    string output;
    output = sol.decodeAtIndex(input,k);

    cout<<output;

}
#endif