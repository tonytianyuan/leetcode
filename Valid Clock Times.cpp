#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;



class Solution {
public:
    int a[5] = {3,10,1,6,10};
    int countTime(string time) {
        unsigned int c = 1;
        auto it = time.begin();
        if((*it == '?') && (*(it+1) == '?')){
            c *= 24;
            it += 2;
        }
        else if((*it == '?') && (*(it+1) != '?')){
            if(*(it+1) >= '4')
                c *= 2;
            else
                c *= 3;
            ++it;
        }
        else if((*it != '?') && (*(it+1) == '?')){
            if(*it == '2')
                c *= 4;
            else
                c *= 10;
            it += 2;
        }
        else{
            ++it;
        }
        for(; it < time.end();++it){
            if(*it == '?'){
                c *= a[it-time.begin()];
            }
        }
        return c;
    }
};
#if 0
int main()
{
    Solution sol;
    string inputNames = "??:??";

    int str;
    str = sol.countTime(inputNames);
    cout<<str<<endl;

    
}
#endif