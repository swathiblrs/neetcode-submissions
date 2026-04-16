class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a hash map to store:
        // key   -> number from array
        // value -> its index
        unordered_map<int,int> mp;

        // Traverse through the array
        for(int i = 0; i < nums.size(); i++)
        {
            // Find the number needed along with nums[i]
            // so that their sum becomes target
            int component = target - nums[i];

            // Check if that needed number already exists in the map
            if(mp.find(component) != mp.end())
            {
                // If found, return the index of that number
                // and the current index
                return {mp[component], i};
            }

            // Otherwise, store the current number and its index in the map
            mp[nums[i]] = i;
        }

        // If no pair is found, return an empty vector
        return {};
    }
};
