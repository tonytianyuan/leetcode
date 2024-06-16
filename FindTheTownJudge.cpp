#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

#if 1
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(auto ele : trust){
            peopleA.insert(ele[0]);
            ++countTrust[ele[1]-1];
        }
        for(int i=0;i < n;++i){
            if(countTrust[i] == (n-1)){
                if(peopleA.count(i+1) == 0){
                    return i+1;
                }
            }
            else{
                continue;
            }
        }
        return -1;
    }
private:
    vector<int> countTrust = vector<int> (1000,0);
    set<int> peopleA;
};
#else
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(auto ele : trust){

        }
    }
private:
    vector<int> countTrust = vector<int> (1000,1);
};
#endif
#if 1
int main()
{
    Solution sol;

    int n = 4;
    // vector<vector<int>> trust = {{1,3},{2,3}};
    // vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
    // vector<vector<int>> trust = {{1,2}};
    vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};

    cout << sol.findJudge(n,trust)<<endl;

    
}
#endif