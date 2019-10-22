/*
Leetcode 151

Given an input string, reverse the string word by word.

Runtime: 4 ms, faster than 98.44% of C++ online submissions for Reverse Words in a String.
Memory Usage: 11.4 MB, less than 32.43% of C++ online submissions for Reverse Words in a String.

October 21, 2019
*/

class Solution {
public:
    string reverseWords(const string &str) {
        
        // handle the empty string
        if (str == "") return str;
        
        // tokenize the string and store
        // the words in a vector
        vector<string> tokens;
        istringstream iss (str);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens));
        
        // reverse the vecor 
        reverse(begin(tokens), end(tokens));
        
        // concatenate the worlds back into a string
        string reversed_str;
        for(const auto &t: tokens) reversed_str += (t + " "); 
        
        // remove the last white space
        reversed_str.erase(reversed_str.find_last_not_of(" ") + 1);
        
        return reversed_str;
    }
};
