class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // store size of array

        vector<int> left(n);   // left[i] = product of all elements before i
        vector<int> right(n);  // right[i] = product of all elements after i
        vector<int> result(n); // final answer

        left[0] = 1; // no element on left of first index
        for(int i = 1; i < n; i++)
        {
            left[i] = left[i-1] * nums[i-1]; // build left product
        }

        right[n-1] = 1; // no element on right of last index
        for(int i = n-2; i >= 0; i--)
        {
            right[i] = right[i+1] * nums[i+1]; // build right product
        }

        for(int i = 0; i < n; i++)
        {
            result[i] = left[i] * right[i]; // multiply left and right products
        }

        return result; // return final array
    }
};