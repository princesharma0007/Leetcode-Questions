class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int result = 0;

        int len = nums.size();

        for(int i = 0; i < len; i++) {
            result = result ^ nums[i];
        }

        return result;}
  
};