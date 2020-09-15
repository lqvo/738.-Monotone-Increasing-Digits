#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10)return true;
        vector<int>nums;
        while (n > 9) {
            nums.push_back(n % 10);
            n /= 10;
        }
        nums.push_back(n);
        reverse(nums.begin(), nums.end());
        while (!check(nums)) {
            int i = 1;
            for (; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    nums[i - 1]--;
                    int j = i;
                    for (; j < nums.size(); j++)
                        nums[j] = 9;
                    i = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += nums[i] * pow(10, nums.size() - i - 1);
        return ans;
    }
    bool check(vector<int>nums) {
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1])return false;
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.monotoneIncreasingDigits(10332545);
    return 0;
}