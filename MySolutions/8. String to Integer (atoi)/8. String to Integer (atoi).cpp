//============================================================================
// Name        : Leetcode.8. String to Integer (atoi)
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://medium.com/@qwe73320/3a2797d89409
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool sign = true;
        int num = 0;

        int i = 0;

        while(str[i] == ' ')
            ++i;

        if(str[i] == '-')
        {
            sign = false;
            ++i;
        }
        else if(str[i] == '+')
        {
            ++i;
        }

        int upper = INT_MAX / 10;
        int lower = INT_MIN / 10;
        for(; str[i] >= '0' and str[i] <= '9'; i++)
        {
            if(sign)
            {
                if(num > upper || (num == upper && (str[i] - '0' > INT_MAX % 10)))
                {
                    return INT_MAX;
                }
                else
                {
                    num = num * 10 + (str[i] - '0');
                }
            }
            else
            {
                if(num < lower || (num == lower && (('0' - str[i]) < INT_MIN % 10)))
                {
                    return INT_MIN;
                }
                else
                {
                    num = num * 10 + ('0' - str[i]);
                }
            }
        }


        return num;
    }
};

int main() {

    Solution sol;
    cout << sol.myAtoi("-91283472332") << endl;

	return 0;
}
