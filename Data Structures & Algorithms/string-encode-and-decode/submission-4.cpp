class Solution {
public:
    string encode(vector<string>& strs) {
        string s; // final encoded string
        for (auto word : strs) { // go through each word
            s += to_string(word.size()) + "#" + word; // store length + # + word
        }
        return s; // return encoded result
    }

    vector<string> decode(string s) {
        vector<string> ans; // store decoded words
        int i = 0; // pointer to current position
        while (i < s.size()) { // process whole string
            int j = i; // find separator #
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i)); // get word length
            i = j + 1; // move to word start
            j = i + len; // find word end
            ans.push_back(s.substr(i, len)); // extract word
            i = j; // move to next encoded word
        }
        return ans; // return decoded list
    }
};