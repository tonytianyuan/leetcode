#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(5);
        string::iterator it;
        for(it = text.begin();it < text.end(); ++it){
            switch(*it){
                case 'b':
                    ++cnt[0];
                    break;
                case 'a':
                    ++cnt[1];
                    break;
                case 'l':
                    ++cnt[2];
                    break;
                case 'o':
                    ++cnt[3];
                    break;
                case 'n':
                    ++cnt[4];
                    break;
            }
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        return *min_element(cnt.begin(),cnt.end());
    }
};
#if 0
int main()
{
    Solution sol;
    string inputNames = "leetcode";

    int str;
    str = sol.maxNumberOfBalloons(inputNames);
    cout<<str<<endl;

    
}
#endif