#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

typedef struct abc{
    int num1:16;
    int num2:16;
}abc;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = nums.size() + 1;
        for(int i=0;i<nums.size() && res > abs(start-i);++i){
            if(target == nums[i]){
                res = abs(i-start);
            }
        }
        return res;
    }
};

#if 0
int main()
{
    Solution sol;
    int minimum,target=1,start=0;
    int a[] = {1,1,1,1,1,1,1,1,1,1};
    vector<int> nums(a,a+sizeof(a)/sizeof(a[0]));

    minimum = sol.getMinDistance(nums,target,start);

    cout<<minimum<<endl;

}
#endif