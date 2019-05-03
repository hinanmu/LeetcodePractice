/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = 1;
        if(divisor == 0) {
            return pow(2, 31)-1;
        }

        int result = 0;
        int minval = -pow(2, 31);
        if(dividend == minval && divisor == -1) {
                return pow(2, 31)-1;
        }
        if(dividend == minval && divisor == 1) {
                return minval;
        }
        if(dividend != minval && divisor == minval){
            return 0;
        }
        if(dividend == minval && divisor == minval){
            return 1;
        }
        if(dividend == minval){
            dividend = dividend + abs(divisor);
            result += 1;
        }


        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            flag = 0;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);

        int base = 1;
        int temp = divisor;
        while(dividend >= temp){
            if(dividend >= divisor){
                dividend -= divisor;
                result += base;
                divisor <<= 1;
                base <<= 1;
            }else
            {
                divisor >>= 1;
                base >>= 1;
            }
        }
        
        if (flag == 0) {
            result = -result;
        }
        
        return result;
    }
};

