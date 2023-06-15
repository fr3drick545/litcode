/**
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while preserving
 * the order of characters. No two characters may map to the same character, but a character 
 * may map to itself. 
 * 
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3: 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 */

// Great solution (not mine originally)
// Map characters from each string onto the other. map[s1[i]] = s2[i];
// if a given character is already mapped to another character, and if the character it's mapped to is different from the orignal string, it's not isometric.
// perf 70% mem 91%

class Solution {
public:

    bool isIsomorphic(string s, string t) {
        int length = s.length();

        unordered_map <char, char> mapA;
        unordered_map <char, char> mapB;

        for (int i = 0; i < length; i++)
        {

            if (mapA[s[i]] && mapA[s[i]] != t[i]) return false;
            if (mapB[t[i]] && mapB[t[i]] != s[i]) return false;

            mapA[s[i]] = t[i];
            mapB[t[i]] = s[i];
        }
        return true;
    }
};
