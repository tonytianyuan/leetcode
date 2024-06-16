#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        vector<string>::iterator it = words.begin();
        int vecSize = words.size();
        int output = vecSize + 1;;
        while(it < words.end()){
            if(*it == target){
                int tmp = min(abs(it-words.begin()-startIndex),abs(startIndex+vecSize-(it-words.begin())));
                tmp = min(tmp,(int)(it-words.begin()+vecSize-startIndex));
                if(tmp < output)
                    output = tmp;
            }
            ++it;
        }
        if(output > vecSize)
            output = -1;
        return output;
    }
};
#if 0
int main()
{
    Solution sol;
    string inputNames[] = {"a","b","am","c","hello"};
    vector<string> words(inputNames,inputNames+5);

    int startIndex = 4;
    string target = "a";
    int output;
    output = sol.closetTarget(words,target,startIndex);
    cout<<output<<endl;

    
}
#endif