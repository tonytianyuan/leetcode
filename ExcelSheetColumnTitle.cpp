#include<string>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        #if 1
        string columnTitle;
        while(columnNumber){
            columnTitle += (char)(--columnNumber%26 + 'A');
            columnNumber/=26;
        }
        reverse(columnTitle.begin(),columnTitle.end());
        return columnTitle;
        #else
        return columnNumber ? convertToTitle((columnNumber-1)/26) + (char)((columnNumber-1)%26 + 'A'): "";
        #endif
    }
};
#if 0
int main()
{
    Solution sol;
    int n = 701;

    string str;
    str = sol.convertToTitle(n);
    cout<<str<<endl;

    
}
#endif