/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.02%)
 * Total Accepted:    282.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p[0] == '*'){
            return true;
        }
     struct Node
    {
        char selfChar = ' ';
        char nextChar = ' ';
        bool flag = 0;
        Node* next = NULL;
        /* data */
    };
    vector<Node*> state;
    Node* startNode = new Node();
    Node* pNode = startNode;

    state.push_back(pNode);
    for(int i = 0; i < p.size(); i++)
    {
        if(i < p.size() - 1 && p[i+1] == '*')
        {
            pNode->selfChar = p[i];
            pNode->nextChar = ' ';
            Node* temp = new Node();
            pNode->next = temp;
            pNode = pNode->next;
            state.push_back(pNode);
            i += 1;
        }
        else
        {
            Node* temp = new Node();
            pNode->next = temp;
            pNode->nextChar = p[i];
            pNode = pNode->next;
            state.push_back(pNode);
        }
    }
    vector<vector<int>> first;
    for(int i = state.size()-1; i >= 0 ; i--)
    {
        vector<int> temp;
        if (state[i]->nextChar != ' ' || state[i]->next == NULL){
            temp.push_back(i);
            first.push_back(temp);
        }else{
            temp = first[first.size()-1];
            temp.push_back(i);
            first.push_back(temp);
        }
    }
    int len = first.size();
    reverse(first.begin(), first.end());
    set<int> match;
    for(int i = 0; i < first[0].size(); i++){
        match.insert(first[0][i]);
    }
    for(int i = 0; i < s.size(); i++)
    {
        vector<int> temp;
        set<int>::iterator iter;
        for(iter = match.begin(); iter != match.end(); iter++){
            if(state[*iter]->nextChar == s[i] || state[*iter]->nextChar == '.'){
                temp.insert(temp.end(), first[*iter+1].begin(), first[*iter+1].end());
            }else if(state[*iter]->selfChar == s[i] || state[*iter]->selfChar == '.'){
                temp.insert(temp.end(), first[*iter].begin(), first[*iter].end());
            }
        }
        match.clear();
        for(int j = 0; j < temp.size(); j++){
            match.insert(temp[j]);
        }
    }

    if (match.empty()) {
        return false;
    }else
    {
        if(match.find(len-1) != match.end()){
            return true;
        }else{
            return false;
        }

    }
    return 0;
    }
};


