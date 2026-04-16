class Solution {
public:
    int maxArea(vector<int>& heights) {
        int front = 0;
        int back = heights.size()-1;
        int result = 0;
        while(front<back)
        {
            int area = (min(heights[front],heights[back]) * (back-front));
            result = max(area,result);
            if(heights[front] < heights[back])
            {
                front ++;
            }
            else{
                back --;
            }
        }
        return result;
    }
};
