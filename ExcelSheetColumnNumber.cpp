#include<string>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//int a=0,b=0;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        unsigned int n=0;
        for(int i=0;i<columnTitle.length();++i)
        {
            n += (columnTitle[columnTitle.length()-i-1] - 'A'+1)*pow(26,i); 
        }
        return n;
    }
};
#if 1
int main()
{
    Solution sol;
    int n;

    string str = "ZY";
    n = sol.titleToNumber(str);
    cout<<n<<endl;

    
}
#endif