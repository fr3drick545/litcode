/** 
 * You are given an array of strings names, and an array heights 
 * that consists of distinct positive integers. Both arrays are of length n.
 * For each index i, names[i] and heights[i] denote the name and height of the ith person.
 * Return names sorted in descending order by the people's heights.
 *
 * Example 1:
 * Input: names = ["Mary","John","Emma"], heights = [180,165,170]
 * Output: ["Mary","Emma","John"]
 * Explanation: Mary is the tallest, followed by Emma and John.
*/

// My initial Solution, Perf 16% mem 86%
// Selection sort with custom swap logic
/*
class Solution {
public:

    void Swap(const int& a, const int& b, vector<string>& names, vector<int>& heights)
    {
        string s = names[a];
        names[a] = names[b];
        names[b] = s;

        int i = heights[a];
        heights[a] = heights[b];
        heights[b] = i;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n = names.size();
        int tallestHeight;

        for (int i = 0; i < n-1; i++)
        {
            tallestHeight = i;

            for (int j = i+1; j < n; j++)
            {
                if (heights[j] > heights[tallestHeight])
                tallestHeight = j;
            }

            if(tallestHeight != i)
            Swap(i, tallestHeight, names, heights);
        }

        return names;
    }

};
*/


// My best Solution, Perf 84% mem 75%
// Hold data in vector of pairs, sort and return.

class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int, string>> data;
        int n = heights.size();

        for (int i = 0; i < n; i++)
        {
            data.push_back({ heights[i], names[i] });
        }

        sort(data.rbegin(), data.rend());

        for (int i = 0; i < n; i++)
        {
            names[i] = data[i].second;
        }

        return names;
    }

};


/*
 * 
 
 //Cheeky solution 60% perf and 50% mem
 //have a vector initialized with 10000 empty strings. do:
 //vec[heights[i]] = names[1]; // using the heights themselves as the index, therefore "ordering" the array.
 //remove all elements that are empty strings and return the result.



*/