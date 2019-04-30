/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.size() == 0){
            vector<string> empty;
            return empty;
        }
        return Descartes(digits, dict);
    }
    vector<string> Descartes(string digits, vector<string> dict){
        int len = digits.size();
        if(len == 1){
            vector<string> temp;
            int idx = digits[0] - '0';
            for(int i = 0; i < dict[idx-2].size(); i++){
                string s(1, dict[idx-2][i]);
                temp.push_back(s);
            }
            return temp;
        }
        string left = digits.substr(0, len/2);
        string right = digits.substr(len/2);
        vector<string> leftDes = Descartes(left, dict);
        vector<string> rightDes = Descartes(right, dict);
        vector<string> result;
        for (int i = 0; i < leftDes.size(); i++){
            for(int j = 0; j < rightDes.size(); j++){
                result.push_back(leftDes[i] + rightDes[j]);
            }
        }
        return result;
    }

};

