#include <iostream>

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int x)
    {
        val = x;
    }
    ListNode(int x, ListNode *after)
    {
        next = after;
    }
};

int main()
{
    int nums[6] = {1, 2, 3, 4, 5, 6};
    const int len = sizeof(nums) / sizeof(int);
    ListNode *head = nullptr;
    ListNode *ptr = head;
    for (int i = 0; i < len; ++i)
    {
        if (!ptr)
        {
            head = new ListNode(nums[i]);
            ptr = head;
        }
        else
        {
            ptr->next = new ListNode(nums[i]);
            ptr = ptr->next;
        }
    }
    while (head)
    {
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}