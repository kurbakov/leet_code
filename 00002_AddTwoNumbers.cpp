#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* teil = nullptr;
        
        int reminder = 0;
        
        while(l1 != nullptr && l2 != nullptr){
            if(head == nullptr){
                head = new ListNode((l1->val + l2->val + reminder) % 10);
                reminder = (l1->val + l2->val + reminder) / 10;
                
                teil = head;
            }
            else{
                ListNode* tmp = new ListNode((l1->val + l2->val + reminder) % 10);
                reminder = (l1->val + l2->val + reminder) / 10;
                
                teil->next = tmp;
                teil = tmp;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != nullptr){
            ListNode* tmp = new ListNode((l1->val + reminder) % 10);
            reminder = (l1->val + reminder) / 10;
                
            teil->next = tmp;
            teil = tmp;
            
            l1 = l1->next;
        }
        while(l2 != nullptr){
            ListNode* tmp = new ListNode((l2->val + reminder) % 10);
            reminder = (l2->val + reminder) / 10;
                
            teil->next = tmp;
            teil = tmp;
            
            l2 = l2->next;
        }
        while(reminder){
            ListNode* tmp = new ListNode(reminder % 10);
            reminder = reminder / 10;
                
            teil->next = tmp;
            teil = tmp;
        }
        
        
        return head;
    }
};


void printLL(ListNode* head){
    while(head != nullptr){
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    printLL(l1);
    printLL(l2);;

    Solution s;
    auto* result = s.addTwoNumbers(l1, l2);
    printLL(result);

    return 0;
}