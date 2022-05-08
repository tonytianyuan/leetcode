#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int sum = nums[0],maxValue = nums[0];
        for(int i=1;i<nums.size();++i){
            if(sum < 0){
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            maxValue = maxValue > sum? maxValue : sum;
        }
        return maxValue;
    }
};
#if 0
int main()
{
    Solution sol;
    //vector<int> numArray = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> numArray = {5,4,-1,7,8};

    int a = sol.maxSubArray(numArray);

    cout<<a<<endl;
}
#endif