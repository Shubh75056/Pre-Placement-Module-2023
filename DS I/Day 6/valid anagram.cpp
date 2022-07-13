class Solution {
public:
    bool isAnagram(string s, string t) {
        int i=0,j=0,flag=0,n1=s.size(),n2=t.size();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(n1!=n2)
        {
            return false;
        }
        else
        {
            for(i=0;i<n1;i++)
            {
                if(s[i]==t[i])
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                return false;
            }
        }
        return true;
    }
};