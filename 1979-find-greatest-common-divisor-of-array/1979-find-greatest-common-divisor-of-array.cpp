class Solution {
public:
int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
}
    int findGCD(vector<int>& nums) {
       int Min = nums[0];
        int Max = nums[0];

        for (int num : nums) {
            Min = min(Min, num);
            Max = max(Max, num);
        }

        return gcd(Min, Max);
      } 
    
};