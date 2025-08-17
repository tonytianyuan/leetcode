#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        __int16_t aLen = a.length() - 1;
        __int16_t bLen = b.length() - 1;

        string ret;
        int sum;
        int flow = 0;
        
        while((aLen >= 0) || (bLen>=0) || flow){
            sum = flow;
            if(aLen >= 0){
                sum += a[aLen--] - '0';
            }
            if(bLen >= 0){
                sum += b[bLen--] - '0';
            }
            ret += (sum % 2) + '0';
            flow = sum / 2;
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
};
#if 1
int main()
{
    Solution sol;
    //vector<int> numArray = {-2,1,-3,4,-1,2,1,-5,4};
    string a("10"),b("10");
    string ret;
    ret = sol.addBinary(a,b);
    cout<<ret<<endl;
}
#endif