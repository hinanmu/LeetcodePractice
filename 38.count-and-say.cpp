/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 2; i <= n; i++)
        {
            string temp = "";
            int value = result[0] - '0';
            int num = 0;
            for (int j = 0; j < result.size(); j++)
            {
               if(result[j] - '0' == value)
               {
                   num++;
               }
               else
               {
                   char c = '0' + num;
                   temp = temp + c;
                   c = '0' + value;
                   temp = temp + c;
                   value = result[j] - '0';
                   num = 1;
               }
            }
               char c = '0' + num;
               temp = temp + c;
               c = '0' + value;
               temp = temp + c;
                result = temp;
        }
        return result;
        
    }
};

