class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() == 0 || nums.size()< 3)
        {return {}; 
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i< nums.size()-2;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int front = i +1;
            int back = nums.size()-1;
            while(front<back){
                int sum = nums[i] + nums[front] + nums[back];
                if(sum>0){ back--; }
                else if(sum<0) { front++;}
                else if(sum == 0) {
                    result.push_back({nums[i],nums[front],nums[back]});
                    front ++;
                    back--;
                    while (front < back && nums[front] == nums[front - 1]) front++;
                    while (front < back && nums[back] == nums[back + 1]) back--;
                }
            }
        }
        return result;
    }
};
