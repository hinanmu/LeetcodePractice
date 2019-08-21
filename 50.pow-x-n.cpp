/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
        {
            return 0;
        }
        if(n > 0)
        {
            return pow(x, n);
        }
        else
        {
            if(n != -2147483648)
            {
                return 1 / pow(x, -n);
            }
            else
            {
                n = n + 1;
                return 1 / (pow(x, -n) * x);
            }
        }
        
    }

    double pow(double x, int n)
    {
        double temp;
        if(n == 0 || x == 1)
        {
            return 1;
        }
        else
        {
            temp = pow(x, n / 2);
        }

        if(n % 2 == 0)
        {
            return temp * temp;
        }
        else
        {
            return temp * temp * x;
        }
        
    }
};

