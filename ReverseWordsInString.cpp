#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

string reverseString(string &str){
	// Write your code here.
	istringstream iss(str);
    string word;
    vector<std::string> words;

    while (iss >> ws >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Join the words with a single space
    std::ostringstream oss;
    for (const auto& w : words) {
        oss << w << ' ';
    }

    // Get the final reversed string without leading and trailing spaces
    std::string result = oss.str();
    result.erase(result.find_last_not_of(" \n\r\t") + 1);

    return result;	
}