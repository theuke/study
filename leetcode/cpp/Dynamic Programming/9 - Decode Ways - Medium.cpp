// Iterative DP solution constant space.
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        
        int one_back = 1;
        int two_back = 1;
        int s_len = s.size();

        for (int i = 1; i < s_len; ++i)
        {
            int current = 0;

            if (s[i] != '0')
                current = one_back;
            
            if (s[i] != '\0' && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')))
                current += two_back;
            
            two_back = one_back;
            one_back = current;
        }

        return one_back;
    }
};



// Memoized DP recursive solution with better efficiency
class Solution {
private:
    int dp[101];
    const char *str;
    int str_size;

    int numDec(const char *s)
    {
        if (dp[s - str] != -1)
            return dp[s - str];
        if (s[0] == '0')
            return 0;
        else if (s[0] == '\0')
            return 1;
        
        // The first digit is now gauranteed to consititute a decoding.
        // Hence, dig deeper
        int one_digit = numDec(&s[1]);
        dp[&s[1] - str] = one_digit;

        int two_digit = 0;

        // The two digit pairing only constitutes a decoding if it forms
        // the stringified representation of 1-26. Note that no need for
        // null termination checking since its implicitly done below.
        if (s[1] != '\0' && (s[0] == '1' || (s[0] == '2' && s[1] < '7')))
        {
            two_digit = numDec(&s[2]);
            dp[&s[2] - str] = two_digit;
        }
        
        return one_digit + two_digit;
    }

public:
    int numDecodings(string s) {
        str = s.c_str();
        str_size = strlen(str) + 1;

        // We do not tolerate any number of leading 0's.
        if (s[0] == '0')
            return 0;
        
        // Initialize the string counts to be all -1, meaning that we do not
        // initially know what the count is for any of the subproblems.
        for (int i = 0; i < str_size; ++i)
            dp[i] = -1;
        
        // For memoization, we use an array mapping where each element
        // of the array corresponds to a substring within the string.

        return numDec(str);
    }
};



// Memoized DP recursive solution.
class Solution {
private:
    map<const char *, int> memo;

    int numDec(const char *s)
    {
        if (memo.count(s))
            return memo[s];
        if (s[0] == '0')
            return 0;
        else if (s[0] == '\0')
            return 1;
        
        // The first digit is now gauranteed to consititute a decoding.
        // Hence, dig deeper
        int one_digit = numDec(&s[1]);
        memo[&s[1]] = one_digit;

        int two_digit = 0;

        // The two digit pairing only constitutes a decoding if it forms
        // the stringified representation of 1-26. Note that no need for
        // null termination checking since its implicitly done below.
        if (s[1] != '\0' && (s[0] == '1' || (s[0] == '2' && s[1] < '7')))
        {
            two_digit = numDec(&s[2]);
            memo[&s[2]] = two_digit;
        }
        
        return one_digit + two_digit;
    }

public:
    int numDecodings(string s) {
        // We do not tolerate any number of leading 0's.
        if (s[0] == '0')
            return 0;
        
        // For memoization, make a hashmap where the key is the substring and
        // the the value is its count. If the key is not present in the hashmap
        // then that means that the subproblem in question has not been solved.
        // Else, this means that the sub-problem has been solved so no need
        // to continue the recursion.

        return numDec(s.c_str());
    }
};



// Non-memoized brute force recursive solution.
class Solution {
private:
    map<string, int> memo;

    int numDec(const char *s)
    {
        if (s[0] == '0')
            return 0;
        else if (s[0] == '\0')
            return 1;
        
        // The first digit is now gauranteed to consititute a decoding.
        // Hence, dig deeper
        int one_digit = numDec(&s[1]);

        int two_digit = 0;

        // The two digit pairing only constitutes a decoding if it forms
        // the stringified representation of 1-26. Note that no need for
        // null termination checking since its implicitly done below.
        if (s[1] != '\0' && (s[0] == '1' || (s[0] == '2' && s[1] < '7')))
            two_digit = numDec(&s[2]);
        
        return one_digit + two_digit;
    }

public:
    int numDecodings(string s) {
        // We do not tolerate any number of leading 0's.
        if (s[0] == '0')
            return 0;
        
        // For memoization, make a hashmap where the key is the substring and
        // the the value is its count. If the key is not present in the hashmap
        // then that means that the subproblem in question has not been solved.
        // Else, this means that the sub-problem has been solved so no need
        // to continue the recursion.

        return numDec(s.c_str());
    }
};