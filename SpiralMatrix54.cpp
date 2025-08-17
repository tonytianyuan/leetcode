#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        const int lineMax = matrix.size(),colMax = matrix[0].size();

        int line=0,col=0,cnt=0;
        int colTmp = colMax;
        int rowTmp = lineMax;
        int colMin = 0;
        int rowMin = 0;

        while(cnt < colMax*lineMax){
            while(col < colTmp && cnt < colMax*lineMax){
                result.emplace_back(matrix[line][col]);
                ++col;
                ++cnt;
            }
            ++line;
            --col;

            while(line < rowTmp && cnt < colMax*lineMax){
                result.emplace_back(matrix[line][col]);
                ++line;
                ++cnt;
            }
            --line;
            --col;

            while(col >= colMin && cnt < colMax*lineMax){
                result.emplace_back(matrix[line][col]);
                --col;
                ++cnt;
            }
            ++col;
            --line;

            ++rowMin;

            while(line >= rowMin && cnt < colMax*lineMax){
                result.emplace_back(matrix[line][col]);
                --line;
                ++cnt;
            }
            ++line;
            ++col;
            

            --rowTmp;
            --colTmp;
            ++colMin;

        }

        return result;
    }
};

#if 0
int main(){
    vector<vector<int>> matrix {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    Solution sol;
    vector<int> result;
    result = sol.spiralOrder(matrix);
    for(auto ele : result){
        cout<<ele<<",";
    }
    cout<<endl;

}
#endif