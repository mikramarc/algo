 #include <iostream>

 using namespace std;
 
 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reverse_list(ListNode* head)
{
    if (head == nullptr) return head;

    ListNode* curr;
    auto curr_next = head->next;
    head->next = nullptr;

    while(curr_next != nullptr)
    {
        curr = head;
        head = curr_next;
        curr_next = curr_next->next;
        head->next = curr;
    }

    return head;
}

int main()
{
    ListNode *x = new ListNode(0);

    ListNode *y = x;

    for (int i = 1; i < 6; ++i)
    {
        y->next = new ListNode(i);
        y = y->next;
    }

    ListNode *z = reverse_list(x);

    while (z != nullptr)
    {
        cout << z->val << endl;
        z = z->next;
    }

    return 0;
}

/* 
NOTES
- two aditional vars needed (apart from head) - current and current_next
- init - curr = head, next = head->next
- in while - curr is now head, head is next, next is next->next, head->next is curr
- change next before changing head since head will be temporarily the next!
 */
    
