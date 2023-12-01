#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {

  // Write your code here
  unordered_map<char, int> charCount;

    // Count the frequency of each character
    for(int i = 0; i < str.length(); i++) {
      charCount[str[i]]++;
    }

    // Find the first non-repeating character
    for(int i = 0; i < str.length(); i++) {
        if (charCount[str[i]] == 1) {
            return str[i];
        }
    }
    return str[0];
}