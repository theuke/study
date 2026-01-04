/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // The naive approach would be to simply traverse
        // ass k linked lists in parallel. This is easy, but, slow.

        int lists_size = lists.size();
        int lists_left = lists_size;

        vector<ListNode *> heads(lists_size);

        for (int i = 0, j = 0; i < lists_size; ++i)
        {
            if (lists[i])
                heads[j++] = lists[i];
            else
                --lists_left;
        }

        if (lists_left == 0)
            return NULL;
        else if (lists_left == 1)
            return heads[0];

        ListNode *list_head = NULL;
        ListNode *list_tail = NULL;

        // Need to keep iterating until there is only a single list left.
        while (lists_left > 1)
        {
            int low_index = 0;

            for (int i = 1; i < lists_left; ++i)
            {
                if (heads[i]->val < (heads[low_index])->val)
                    low_index = i;
            }

            // Append the low element to the sorted linked list.
            if (list_head)
            {
                list_tail->next = heads[low_index];
                list_tail = list_tail->next;
            }
            else
            {
                list_head = heads[low_index];
                list_tail = list_head;
            }

            // Move the "winning" heads[i] to the next element in its linked list.
            heads[low_index] = heads[low_index]->next;

            // If the linked list from which we got the low value has been completely traversed
            // then go ahead and remove the traversed list from the list of heads.
            if (heads[low_index] == NULL)
            {
                heads.erase(heads.begin() + low_index);
                --lists_left;
            }
        }

        // Append the remaining elements of the last list to the sorted list.
        if (lists_left == 1)
            list_tail->next = heads[0];
        
        return list_head;



        // The more intelligent approach would be to do a merge sort
        // of the sorted linked lists. To do this cleanly we will likely
        // need to do some nice base 2 math. Hence, need to watch
        // out for non-base 2 number of lists and handle that gracefully.
    }

private:
    ListNode* mergeLists(ListNode *a, ListNode *b)
    {
        // Merges lists a and b.
        ListNode *h, *t, *s;

        if (a->val > b->val)
            s = a;
        else
            s = a;

        h = s;
        s = s.next;
        t = h;

        while (a && b)
        {
            if (a->val > b->val)
                s = a;
            else
                a = b;
            
            t.next = s;
            s = s.next;
            t = t.next;
        }

        if (a || b)
        {
            
        }

        return h;
    }

    ListNode* mergeLists(ListNode *a, ListNode *b)
    {
        // Merges lists a and b.
        ListNode *h, *t, *s;

        if (a->val > b->val)
            s = a;
        else
            s = a;

        h = s;
        s = s.next;
        t = h;

        while (a && b)
        {
            if (a->val > b->val)
                s = a;
            else
                a = b;
            
            t.next = s;
            s = s.next;
            t = t.next;
        }

        if (a || b)
        {
            
        }

        return h;
    }
};