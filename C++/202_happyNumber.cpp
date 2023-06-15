/**
 * Write an algorithm to determine if a number n is happy.
 *
 * A happy number is a number defined by the following process:
 *
 * Starting with any positive integer, replace the number by the sum
 * of the squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 * Return true if n is a happy number, and false if not.
 *
 * Example 1:
 * Input: n = 19
 * Output: true
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 * Example 2:
 * Input: n = 2
 * Output: false
 *
 */

 // sum squares of digits and hold the results in a set.
 // if you see a result was repeated, we're in a loop and will never hit 1.
 // perf 100% mem 55%, unreliable results?

class Solution
{
public:

    bool isHappy(int in)
    {
        int sum = 0;
        std::unordered_set<int> results;

        while (1)
        {
            while (in != 0)
            {
                int digit = in % 10;
                sum += digit * digit;

                in /= 10;
            }

            if (sum == 1)
                return true;

            if (results.count(sum))
                return false;

            results.insert(sum);

            in = sum;
            sum = 0;
        }
    }
};

/*
// Best solution, Floyd's Cycle-Finding Algorithm.
// Floyd's cycle-finding algorithm, also known as the tortoise and hare algorithm, is used to detect cycles in a linked list or any sequence of values.
// It uses two pointers, one moving at a slower pace (tortoise) and the other at a faster pace (hare), and if there is a cycle, the two pointers will eventually meet at the same node.
// If the hare reaches the end of the list, there's no cycle.
// if the hare and the tortoise occupy the same node, there's a cycle.
// perf 100% mem 75%

class Solution {
private:
    int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
public:
    bool isHappy(int n) {
        int slowPointer = n;
        int fastPointer = nextNumber(n);
        while(fastPointer != 1 && fastPointer != slowPointer){
            slowPointer = nextNumber(slowPointer);
            fastPointer = nextNumber(nextNumber(fastPointer));
        }
        return fastPointer==1;
    }
};
*/