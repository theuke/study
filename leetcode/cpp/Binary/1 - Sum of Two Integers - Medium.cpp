class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;

        for (int i = 0; i < 32; ++i)
        {
            int mask = 1 << i;
            bool a_set = mask & a;
            bool b_set = mask & b;
            bool sum_set = mask & sum;

            if (a_set && b_set && sum_set)
            {
                if (i != 31)
                    sum |= 2 << i;
            }
            else if (a_set && b_set || a_set && sum_set || b_set && sum_set)
            {
                if (i != 31)
                    sum |= 2 << i;

                sum &= ~(1 << i);
            }
            else if (a_set || b_set)
            {
                sum |= 1 << i;
            }
        }

        return sum;
    }
};