// Leetcode 3474
// Problem: lexicographically smallest generated string
// Topic: Greedy + Strings + Implementation
// Diff: hard


class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string word(len, '?');
        vector<bool> locked(len, false);

        // Step 1: Apply 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        locked[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        // Fill remaining with 'a'
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

        // Step 2: Handle 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool fixed = false;

                    // Try to break using NON-locked positions only
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (!locked[pos]) {
                            for (char c = 'a'; c <= 'z'; c++) {
                                if (c != str2[j]) {
                                    word[pos] = c;
                                    fixed = true;
                                    break;
                                }
                            }
                        }

                        if (fixed) break;
                    }

                    if (!fixed) return "";
                }
            }
        }

        return word;
    }
};
