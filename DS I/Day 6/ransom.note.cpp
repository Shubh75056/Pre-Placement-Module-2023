class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> counts;
        int rLen = ransomNote.length();
        int mLen = magazine.length();
        for (int i = 0; i < mLen; i++) {
            char ch = magazine[i];
            if (counts.find(ch) != counts.end()) {
                counts[ch] += 1;
            } else {
                counts.insert(pair<char, int>(ch, 1));
            }
        }
        for (int i = 0; i < rLen; i++) {
            char ch = ransomNote[i];
            if (counts.find(ch) == counts.end()) {
                return false;
            }
            counts[ch] -= 1;
            if (counts[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};