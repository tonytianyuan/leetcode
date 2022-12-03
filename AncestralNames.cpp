#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class Solution {
    #if 0
private:
    int romanToInt(string s) {
        map<char,int> romanDic = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int here,after;
        int result = 0;
        for(int i=0;i<s.length();i++){
            here = romanDic[s[i]];
            after = romanDic[s[i+1]];
            if(here >= after){
                result += here;
            }     
            else
                result -= here;
        }
        return result;
    }
    #endif
public:
    int romanToInt(string s) {
        map<char,int> romanDic = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int here,after;
        int result = 0;
        for(int i=0;i<s.length();i++){
            here = romanDic[s[i]];
            after = romanDic[s[i+1]];
            if(here >= after){
                result += here;
            }     
            else
                result -= here;
        }
        return result;
    }
    vector<string> AncestralNames(vector<string> inputNames){
        const string pattern= " ";
        int i;
        int pos;
        #if 0
        multimap<string,int> namesShaped;
        vector<string> outputNames;

        for(i = 0;i < inputNames.size();++i){
            pos = inputNames[i].find(pattern,0);
            namesShaped.insert(pair<string,int>(inputNames[i].substr(0,pos),romanToInt(inputNames[i].substr(pos))));
        }
        #endif
        sort(inputNames.begin(), inputNames.end(), [this](string &a, string &b) {
            
            auto pos_a = a.find(' '), pos_b = b.find(' ');
            string name_a = a.substr(0, pos_a), name_b = b.substr(0, pos_b);
            string num_a = a.substr(pos_a), num_b = b.substr(pos_b);
            
            if(name_a == name_b)
                return (romanToInt(num_b) >= romanToInt(num_a));
            return name_b > name_a;
	    });
        return inputNames; 
    }
};

void (*myfun[2])(int value);

#if 0
int main()
{
    Solution sol;
    vector<string> inputNames = {
		"Steven XL", "Steven XVI", "David IX", "Mary XV", "Mary XIII", "Mary XX"
	};
    vector<string> outputNames;

    outputNames = sol.AncestralNames(inputNames);

    for(int i=0;i < outputNames.size();++i){
        cout<<outputNames.at(i)<<endl;
    }
}
#endif