/* 
* 
* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
* A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
* 
*           2       3  
*         "abc"   "def"   
*   4       5       6
* "ghi"   "jkl"   "mno"
*   7       8       9
* "pqrs"  "tuv"   "wxyz"
* 
* 
* Example 1:
* 
* Input: digits = "23"
* Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
* Example 2:
* 
* Input: digits = ""
* Output: []
* Example 3:
* 
* Input: digits = "2"
* Output: ["a","b","c"]
* 
*/


/* My solution, perf 100% mem 99-87%
* use a switch case to determine simple cases where there's no input or there's just 1 input.
* keep an array of the count of letters that correlate each input digit, multiplied by the letter count of earlier digit inputs. example, input = "2,3,7" - "Counts" array would read "3,3x3,3x3x4" = "3,9,36" 
* loop over the total number of elements which we get by multiplying the number of present letters together.
* use division and modulus to loop over the letters and throw them into our output for every relevant case.
*   
*   bad example cause GHIJ isn't a proper option but this is just to demo the way these letters show up based on their count.
*   notice the number of each set of elements gets multiplied by the letter count of the next digit's letters.
*   (in my code, i just use the recorded count value of the n+1th digit, and just use "1" for the last one)
*
*   3x4x1 cases of A, B, C    per loop (just 1 loop over the whole output set)
*   4x1   cases of D, E, F    per loop
*   1     case  of G, H, I, J per loop
* 
*   ADG  AEG  AFG
*   ADH  AEH  AFH
*   ADI  AEI  AFI
*   ADJ  AEJ  AFJ
* 
*   BDG  BEG  BFG
*   BDH  BEH  BFH
*   BDI  BEI  BFI
*   BDJ  BEJ  BFJ
* 
*   CDG  CEG  CFG
*   CDH  CEH  CFH
*   CDI  CEI  CFI
*   CDJ  CEJ  CFJ
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        std::string alphabet[]{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        std::vector <std::string> output;
        int len = digits.length();

        switch (len)
        {
        case 0: return output;
        case 1:

            for (char c : alphabet[digits[0] - 50])
                output.push_back(string(1, c));

            return output;

        default:

            int* counts = new int[len];
            int totals = 1;

            for (int i = len - 1; i > -1; i--)
            {
                totals *= alphabet[digits[i] - 50].length();
                counts[i] = totals;
            }

            output.resize(totals);

            for (int l = 0; l < len; l++)
            {
                string s = alphabet[digits[l] - 50];
                if (l == len - 1)
                {
                    for (int i = 0; i < totals; i++)
                        output[i] += s[i % s.length()];
                }
                else
                {
                    for (int i = 0; i < totals; i++)
                        output[i] += s[(i / counts[l + 1]) % s.length()];
                }
            }

            delete[] counts;
            return output;
        }
    }
};