#include<string>
#include<iostream>
using namespace std;

//int a=0,b=0;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        #if 0
        if((text1.size()== 0) || (text2.size() == 0))
            return 0;
        if(text1.at(text1.length()-1) == text2.at(text2.length()-1)){
            return 1+longestCommonSubsequence(text1.erase(text1.length()-1),text2.erase(text2.length()-1));
        }
        else{
            int a,b;
            string tmp = text1;
            a = longestCommonSubsequence(tmp.erase(tmp.length()-1),text2);
            b = longestCommonSubsequence(text1,text2.erase(text2.length()-1));
            return a > b ? a : b;
        }
        #else
        int matrix[100][100] = {0};
        for(int i = 0; i < text2.length(); ++i){
            for(int j = 0; j < text1.length(); ++j){
                if(text2.at(i) == text1.at(j)){
                    matrix[i+1][j+1] = matrix[i][j] + 1;
                }
                else{
                    if(j == 0)
                        matrix[i+1][j+1] = matrix[i][j+1];
                    else
                        matrix[i+1][j+1] = matrix[i][j+1] > matrix[i+1][j] ? matrix[i][j+1] : matrix[i+1][j];
                }
            }
        }
        return matrix[text2.length()][text1.length()];
        #endif
    }
};

int main()
{
    Solution sol;
    //string text1("abcde"),text2=("ace");
    string text1("yrkzavgdmdgtqpg"),text2=("ylqpejqbalahwr");
    //string text1("abc"),text2=("def");
    //string text1("ezupkr"),text2("ubmrapg");

    int comLen;
    comLen = sol.longestCommonSubsequence(text1,text2);

    cout<<comLen<<endl;
    
}