#include<iostream>
#include<vector>
using namespace std;

#if 0
class Solution {
public:
    bool isValid(string s) {
        int i=0,cnt[6] = {0};       //'(',')','[',']','{','}'
        if(s.length() == 1)
            return false;
        for(i=0;i<s.length();++i){
            if((s[i] == '(' && s[i+1] == ']') ||
                (s[i] == '(' && s[i+1] == '}') ||
                (s[i] == '[' && s[i+1] == ')') ||
                (s[i] == '[' && s[i+1] == '}') ||
                (s[i] == '{' && s[i+1] == ']') ||
                (s[i] == '{' && s[i+1] == ')') || 
                (s[i] == '(' && s[i+1] == '\0') || 
                (s[i] == '{' && s[i+1] == '\0') || 
                (s[i] == '[' && s[i+1] == '\0') )
                return false;
            switch(s[i]){
                case '(':
                    cnt[0]++;
                    break;
                case ')':
                    cnt[1]++;
                    break;
                case '[':
                    cnt[2]++;
                    break;
                case ']':
                    cnt[3]++;
                    break;
                case '{':
                    cnt[4]++;
                    break;
                case '}':
                    cnt[5]++;
                    break;
                default:
                return false;
            }
        }
        if((cnt[0] == cnt[1]) && (cnt[2] == cnt[3]) && (cnt[4] ==cnt[5]))
            return true;
        else
            return false;
    }
};
#endif
class Solution {
public:
    bool isValid(string s) {
        int i=0,cnt[6] = {0};       //'(',')','[',']','{','}'
        string tmp;
        if(s.length() == 1)
            return false;
        for(i=0;i<s.length();++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                tmp += s[i];
            }
            else if((tmp.back() == '(' && s[i] == ')') || 
                (tmp.back() == '[' && s[i] == ']') || 
                (tmp.back() == '{' && s[i] == '}')){
                tmp.pop_back();
            }
            else
                return false;
        }
        if(tmp.length() == 0)
            return true;
        else
            return false;   
    }
};
#if 0
int main()
{
    Solution sol;
    string str = ")(){}";
    bool a = true;

    a = sol.isValid(str);

    cout<<a<<endl;
}
#endif