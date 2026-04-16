class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1, mp2;
        int ws = 0;
        char lc; 
        int minlen = INT_MAX;
        int startin = 0; 
        if(s.size()<t.size())
        {
            return "";
        }
        for(auto c : t)
        {
            mp1[c]++;//building frequency map for t
        }
        for(int we = 0; we< s.size(); we++)
        {
            char rc = s[we];
            mp2[rc]++;// mp2 map will work with freq for window
            while(contains(mp1,mp2))
            {
               if (we - ws + 1 < minlen) {
    minlen = we - ws + 1;
    startin = ws;
}
            
                lc = s[ws];
                mp2[lc]--;
                if (mp2[lc] == 0) 
                {
                    mp2.erase(lc);
                }
                ws++;
            }
        }
            if (minlen == INT_MAX) {
            return "";
        }
            return s.substr(startin, minlen);
    }
    bool contains(unordered_map<char,int>& mp1, unordered_map<char,int>& mp2)
    {
        for(int i = 0;i<256; i++)
        if(mp1[i]>mp2[i])
        {
            return false;// here i will be checking if count frequency in t -mp1 is 
                        //still greater than count frequency in s -mp2
        }
        return true;
    }
};
