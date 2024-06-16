#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long> creatorViewCnt;
        unordered_map<string,pair<string,long> > creatorIdsCnt;
        vector<vector<string> > result;

        for(int i=0;i<creators.size();++i){
            if(creatorViewCnt.count(creators[i])){
                creatorViewCnt[creators[i]] += views[i];
                if(creatorIdsCnt[creators[i]].second < views[i] || (creatorIdsCnt[creators[i]].second == views[i]
                        && creatorIdsCnt[creators[i]].first > ids[i])){
                    creatorIdsCnt[creators[i]].first = ids[i];
                    creatorIdsCnt[creators[i]].second = views[i];
                }
            }
            else{
                creatorViewCnt[creators[i]] = views[i];
                creatorIdsCnt[creators[i]].first = ids[i];
                creatorIdsCnt[creators[i]].second = views[i];
            }
        }

        auto it1 = creatorViewCnt.begin();
        auto it2 = creatorIdsCnt.begin();
        vector<string> tmp;
        tmp.push_back(it1->first);
        tmp.push_back(it2->second.first);
        result.push_back(tmp);
        ++it1;
        ++it2;
        while(it1 != creatorViewCnt.end()){
            if(it1->second > creatorViewCnt[result[0][0]]){
                result.clear();
                tmp.clear();
                tmp.push_back(it1->first);
                tmp.push_back(it2->second.first);
                result.push_back(tmp);
            }
            else if(it1->second == creatorViewCnt[result[0][0]]){
                tmp.clear();
                tmp.push_back(it1->first);
                tmp.push_back(it2->second.first);
                result.push_back(tmp);
            }
            ++it1;
            ++it2;
        }

        return result;

        
    }
};

#if 0
int main(){
    #if 0
    int n = 3;
    string a[] = {"alice","alice","alice"};
    vector<string> creators(a,a+n);
    string b[] = {"a","b","c"};
    vector<string> ids(b,b+n);
    int c[] = {1,2,2};
    vector<int> views(c,c+n);
    #endif
    #if 1
    int n = 4;
    string a[] = {"alice","bob","alice","chris"};
    vector<string> creators(a,a+n);
    string b[] = {"one","two","three","four"};
    vector<string> ids(b,b+n);
    int c[] = {5,10,5,4};
    vector<int> views(c,c+n);
    #endif

    Solution solu;

    vector<vector<string> > result;
    result = solu.mostPopularCreator(creators,ids,views);

    for(auto it=result.begin();it < result.end();++it){
        cout<<(*it)[0]<<","<<(*it)[1]<<endl;
    }
}
#endif