string longestPalinSubstring(string str) {
    // Write your code here.
    int n = str.length();
    if (n == 1) {
        return str;
    }

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string longest_palindrome = "";

    // Single characters are palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        longest_palindrome = str[i];
    }

    // Check substrings of length 2 and greater
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (str[i] == str[j] && (length == 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (length > longest_palindrome.length()) {
                    longest_palindrome = str.substr(i, length);
                }
            }
        }
    }

    return longest_palindrome;
}