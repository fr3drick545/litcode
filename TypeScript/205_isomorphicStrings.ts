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
 * Best Solution, Also the simplest
 * @param s 
 * @param t 
 * @returns 
 */
const isIsomorphic = function (s, t) {
	// isomorphic strings always have the same length
	if (s.length != t.length) {
		return false;
	}
	for (let i = 1; i < s.length; i++) {
		// verify that the first occurrence of the current character occurs at the same position in both s and t
		if (t.indexOf(t[i]) !== s.indexOf(s[i])) {
			return false;
		}
	}
	return true;
};
