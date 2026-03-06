// Leetcode 1784
// Problem: Check if Binary String Has at Most One Segment of Ones
// Topic: string
// Diff: easy

class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '1' && s[i-1] == '0') {
                return false;
            }

        }
        return true;
    }
};
