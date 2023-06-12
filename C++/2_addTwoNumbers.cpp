/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single
 * digit. Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example 1: 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * Example 2: 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
*/

/**
 * Definition for singly-linked list.
 */

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


// My initial solution, saves memory by modifying the larger listnode but is slower
// perf 64% mem 96%
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{

    ListNode* L1Root = l1;
    ListNode* L2Root = l2;

    int result = 0;
    int carry = 0;

    int l1Length = 0;
    int l2Length = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        result = carry;

        if (l1)
        {
            result += l1->val;
            l1Length++;
        }

        if (l2)
        {
            result += l2->val;
            l2Length++;
        }

        carry = result * 0.1f;
        result %= 10;

        if (l1)
        {
            l1->val = result;
            l1 = l1->next;
            l1Length++;
        }

        if (l2)
        {
            l2->val = result;
            l2 = l2->next;
            l2Length++;
        }
    }


    return (l1Length > l2Length ? L1Root : L2Root);
}

// My alternative solution, populates a new listnode, sacrificing memory for better performance
// perf 87% mem 31%

/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* Root = new ListNode();
        ListNode* node = Root;

        int result = 0;
        int carry = 0;

        int l1Length = 0;
        int l2Length = 0;

        while(l1 != nullptr || l2 != nullptr)
        {
            result = carry;

            if (l1)
            {
                result += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                result += l2->val;
                l2 = l2->next;
            }

            carry = result * 0.1f;
            result %= 10;

            node->val = result;

            if(l1 == nullptr && l2 == nullptr)
            {
                if(carry)
                {
                    node->next = new ListNode(1);
                    break;
                }
            }
            else
            {
                node->next = new ListNode();
                node = node->next;
            }
        }


        return Root;
    }
*/