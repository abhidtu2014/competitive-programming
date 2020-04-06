class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),x;
        queue <int> q;
        for (int i=0;i<n;i++) {
            if (nums[i] == 0) q.push(i);
            else {
                if(!q.empty()) {
                    x = q.front();
                    q.pop();
                    swap(nums[x], nums[i]);
                    q.push(i);
                }
            }
        }
        while(!q.empty()) {
            q.pop();
        }
    }
};