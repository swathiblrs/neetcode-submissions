class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 0) // if input is empty
        {
            return {}; // return empty result
        }
        unordered_map<string, vector<string>> mp; // key -> list of anagrams
        for(string s : strs) // go through each word
        {
            vector<int> count(26,0); // count letters a-z
            for(char c : s) // check each character
            {
                count[c - 'a']++; // increase its frequency
            }
            string key = ""; // build unique frequency key
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(count[i]); // add counts to key
            }
            mp[key].push_back(s); // group word by key
        }
        vector<vector<string>> result; // store final groups
        for (auto& it : mp) {
            result.push_back(it.second); // add each group to result
        }
         return result; // return grouped anagrams
    }
};