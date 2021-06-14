// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 0;
        for (auto it = head; it != NULL; it = it->next)
            len++;
        // cout << len << endl;
        //[1,2,3,4,5] 2
        int moveSteps = len - n - 1;
        if (moveSteps == -1)
        { //说明要删除的是头结点
            return head->next;
        }
        ListNode *p = head;
        for (int i = 0; i < moveSteps; i++)
        {
            p = p->next;
        }
        //if (moveSteps == len - 2) {//说明删除的是尾节点
        //  p->next = NULL;
        //} else {
        p->next = p->next->next;
        //}
        return head;
    }
};