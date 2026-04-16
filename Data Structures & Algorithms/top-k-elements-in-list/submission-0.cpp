class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> bucket(nums.size()+1); // declearing bucket array
        for(int i : nums)
        {
            mp[i]++; // freq count 
        }
        for(auto& it: mp) // filling the bucket array
        {
            int num = it.first;
            int freq = it.second;
            bucket[freq].push_back(num);
        }
        vector<int> result;
        int counter = 0;
        for(int i = bucket.size()-1;i>=0 && counter < k;i--)
        {
            for(int j :bucket[i])
            {
                result.push_back(j);
                counter++;
            if(counter ==k){
            break;}
            }
        }
        return result;
    }
};
