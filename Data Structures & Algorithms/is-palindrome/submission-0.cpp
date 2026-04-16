class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;
        while(front<back)
        {
            if(!isalnum(s[front])) front ++;
            else if(!isalnum(s[back])) back --;
            else if(tolower(s[front]) != tolower(s[back])) return false;
            else {
                front ++;
                back --;
            }
        }
        return true;
    }
};
