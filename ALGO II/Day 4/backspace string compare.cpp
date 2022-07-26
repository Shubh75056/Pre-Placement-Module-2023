class Solution 
{
public:
    void backSpacestring(string& s)
    {
        // Get an iterator to the first instance of `#`
        auto firstHashtagIter(std::find(s.cbegin(), s.cend(), '#'));

        // Loop until all instances of `#` have been removed
        while (firstHashtagIter != s.cend())
        {
            // Bounds check. Only erase the previous element if we aren't at the beginning
            if (firstHashtagIter != s.cbegin())
            {
                s.erase(firstHashtagIter - 1);
            }

            // Remove the first instance of `#` now that it's been used
            s.erase(std::find(s.cbegin(), s.cend(), '#'));

            // Get the next instance of `#`
            firstHashtagIter = std::find(s.cbegin(), s.cend(), '#');
        }
    }

    bool backspaceCompare(string s, string t) 
    {
        backSpacestring(s);
        backSpacestring(t);

        return (s == t);
    }
};
