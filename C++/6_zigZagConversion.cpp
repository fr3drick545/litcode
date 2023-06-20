/**
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* 
* Write the code that will take a string and make this conversion given a number of rows:
* string convert(string s, int numRows);
* 
* Example 1:
* Input: s = "PAYPALISHIRING", numRows = 3
* Output: "PAHNAPLSIIGYIR"
* 
* Example 2:
* Input: s = "PAYPALISHIRING", numRows = 4
* Output: "PINALSIGYAHRPI"
* Explanation:
* P     I    N
* A   L S  I G
* Y A   H R
* P     I
* Example 3:
* 
* Input: s = "A", numRows = 1
* Output: "A"
*/


// My solution, have an array of strings representing each row.
// Go through the rows in a ping pong fashion and and throw characters from the incoming string into them.
// Finally, append all strings together.
// perf fluctuates 100-80% mem 82%

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows < 2)
        {
            return s;
        }

        string rows[numRows];
        int row = 0, goingdown = 1;

        for (int i = 0; i < s.length(); i++)
        {
            rows[row] += s[i];

            if (goingdown > 0)
            {
                row++;
            }
            else
            {
                row--;
            }

            if (row == numRows - 1 || row == 0)
            {
                goingdown *= -1;
            }
        }

        string out;

        for (string& s : rows)
        {
            out += s;
        }

        return out;
    }
};
