class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowstart = 0; // left side of sliding window
        char lc; // character removed from left when window shrinks
        unordered_map<char, int> mp1, mp2; // mp1 = freq of s1, mp2 = freq of current window in s2

        for (auto c : s1) { // build frequency map for s1
            mp1[c]++;
        }

        for (int windowend = 0; windowend < s2.size(); windowend++) { // expand window by moving right pointer
            char rc = s2[windowend]; // current right character entering window
            mp2[rc]++; // add right character count to current window map

            if (windowend - windowstart + 1 > s1.size()) { // if window becomes larger than s1, shrink it
                lc = s2[windowstart]; // get left character leaving window
                mp2[lc]--; // decrease its count
                if (mp2[lc] == 0) { // if count becomes zero, remove it from map
                    mp2.erase(lc);
                }
                windowstart++; // move left pointer right
            }

            if (windowend - windowstart + 1 == s1.size() && mp1 == mp2) { // if window size matches s1 and frequencies match
                return true; // found a permutation of s1 in s2
            }
        }

        return false; // no permutation found
    }
};