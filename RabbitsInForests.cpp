#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> colorNumMap;
        int color = 0;
        unsigned int rabbitNum = 0;
        for(auto a : answers){
            if(colorNumMap.size() == 0){
                colorNumMap.insert(make_pair(color,a+1));
                ++color;
                rabbitNum += (a + 1);
            }
            else{
                bool flag = 0;
                for(auto b = colorNumMap.begin();b != colorNumMap.end(); ++b){
                    if((a == (b->second - 1)) && (a != 0) ){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    colorNumMap.insert(make_pair(color,a+1));
                    ++color;
                    rabbitNum += (a + 1);
                }   
            }
        }

        return rabbitNum;
    }
};

#if 0
int main()
{
    Solution sol;

    vector<int> answers = {0,0,1,1,1};
    // vector<int> answers = {10,10,10};
    // vector<int> answers = {1,1,2};
    unsigned int rabbitNum = sol.numRabbits(answers);

    cout<<rabbitNum<<endl;
}
#endif