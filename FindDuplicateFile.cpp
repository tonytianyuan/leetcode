#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    void SplitStr2File(string input,unordered_map<string,vector<string> > &matchcase){
        auto firstPosSpace = input.find(" ");
        string path = input.substr(0,firstPosSpace);
        string filename,filedata;
        auto left = input.find("(",firstPosSpace+1);
        auto right = input.find(")",firstPosSpace+1);
        while(string::npos != left){
            filename = path + '/' + input.substr(firstPosSpace+1,left-1-firstPosSpace);
            filedata = input.substr(left+1,right-1-left);
            matchcase[filedata].push_back(filename); 
            left = input.find("(",right+1);
            right = input.find(")",right+1);
            firstPosSpace = input.find(" ",right+1);
        }
    }
    vector<vector<string> > GetResult(unordered_map<string,vector<string> > matchcase){
        vector<vector<string> > output;
        vector<string> tmp;
        for(auto it=matchcase.begin();it != matchcase.end();++it){
            if(it->second.size() != 1)
                output.push_back(it->second);
        }
        return output;
    }
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string> > matchcase;
        pair<string,string> tmpPair;
        for(auto it = paths.begin();it < paths.end(); ++ it){
            SplitStr2File(*it,matchcase);
        }
        return GetResult(matchcase);
    }
};
#if 0
int main(){
    Solution sol;

    string a[] = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    vector<string> path(a,a+4);
    vector<vector<string> > output;

    output = sol.findDuplicate(path);
    for(auto it=output.begin();it < output.end();++it){
        for(auto it1=it->begin();it1 < it->end();++it1){
            cout<<*it1<<",";
        }
        cout<<endl;
    }
        


    return 0;
}
#endif