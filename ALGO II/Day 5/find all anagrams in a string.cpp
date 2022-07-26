class Solution {
public:
bool isAllZero(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
        if (nums[i]) return false;
    return true;
}
vector<int> findAnagrams(string s, string p) {
    vector<int> charCount(26, 0);
    vector<int> res;
    int m = (int)p.length(), n = (int)s.length();
    int left = 0;
    if (n < m) return res;
    for (int i = 0; i < m; i++)
        charCount[p[i] - 'a']++;
    for (int i = 0; i < n; i++)
    {
        charCount[s[i] - 'a']--;
        if (i - left + 1 > m)
        {
            charCount[s[left] - 'a']++;
            left++;
        }
        if (i - left + 1 == m && isAllZero(charCount)) res.push_back(left);
    }
    return res;
}
};