class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they cannot be anagrams
        if(s.size() != t.size())
        {
            return false;
        }

        // Create a frequency array of size 26 for all lowercase letters a to z
        // Initially all counts are 0
        vector<int> count(26, 0);

        // Traverse string s
        // For each character, increase its corresponding count
        // Example: if c = 'b', then count[1]++
        for(char c : s) 
            count[c - 'a']++;

        // Traverse string t
        // For each character, decrease its corresponding count
        // This cancels out the counts added from string s
        for(char c : t) 
            count[c - 'a']--;

        // Check the frequency array
        // If any position is not 0, it means the character counts do not match
        for(char x : count) 
        {
            if(x != 0)
            {
                return false;
            }
        }

        // If all counts are 0, both strings have exactly the same characters
        return true;
    }
};
