#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

ListNode* reverseList(ListNode* head) {
    vector<int> v;
    ListNode* temp = head;

    while (temp) {
        v.push_back(temp->val);
        temp = temp->next;
    }

    temp = head;
    for (int i = v.size() - 1; i >= 0 && temp; i--) {
        temp->val = v[i];
        temp = temp->next;
    }

    return head;
}

void display(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = reverseList(head);
    display(head);

    return 0;
}
