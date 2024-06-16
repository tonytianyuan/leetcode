#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string dict[] = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
            ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
            ".--","-..-","-.--","--.."
        };
        set<string> morseset;
        int i,j;
        for(i=0; i< words.size();++i){
            string tmp;
            for(j = 0; j< words[i].length(); ++j){
                tmp += dict[words[i].at(j) - 'a'];
            }
            morseset.insert(tmp);
        }
        return morseset.size();
    }
};
#if 0
int main()
{
    Solution sol;
    string inputNames[] = {"gin","zen","gig","msg"};
    vector<string> words(inputNames,inputNames+4);

    int str;
    str = sol.uniqueMorseRepresentations(words);
    cout<<str<<endl;

    
}
#endif