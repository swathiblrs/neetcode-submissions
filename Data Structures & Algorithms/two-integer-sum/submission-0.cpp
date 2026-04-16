class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i =0;i<= nums.size();i++)
        {
            int component = target - nums[i];
            if(mp.find(component) != mp.end())
            {
                return{mp[component],i};
            }
            mp[nums[i]] = i;
        }
        return{};
    }
};
