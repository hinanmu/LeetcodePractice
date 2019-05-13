/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
        {
           return 0; 
        }
        vector<int> next = getNext(needle);

        int i = 0;
        int j = 0;
        int hlen = haystack.size();
        int nlen = needle.size();
        while (i < hlen && j < nlen)
        {
            if (j == -1)
            {
                ++i;
                ++j;
            }
            else if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
            
        }

        if (j == needle.size())
        {
            return i - j;
        }
        else
        {
           return -1;
        }
    }

    vector<int> getNext(string needle)
    {
        vector<int> next(needle.size());
        next[0] = -1;
        int i = 0;
        int j = -1;

        while (i < needle.size() - 1)
        {
            if (j == -1)
            {
                ++i;
                ++j;
                next[i] = j;
            }
            else if (needle[i] == needle[j])
            {
                ++i;
                ++j;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
        return next;
    }
};

