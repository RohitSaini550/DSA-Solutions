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
// class Solution {
// public:
//     ListNode* reverse(ListNode* head ,int initial, int k ){
//             ListNode* temp = head;
//             int cnt = initial;
//             stack<int> stk;

//             while(cnt <= k){
//                 stk.push(temp -> val);
//                 temp = temp -> next;
//                 cnt++;
//             }
//             temp =  head;
//             cnt = initial;
//             while(cnt <= k){
//                 temp -> val = stk.top();
//                 stk.pop();
//                 temp = temp -> next;
//                 cnt++;
//             }
//             if(temp == NULL) return head;
//             else return temp;
//     }

//     int length(ListNode* head){
//         int cnt = 0;
//         while(head != NULL){
//             head = head -> next;
//             cnt++;
//         }
//         return cnt;
//     }
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == NULL || head -> next == NULL) return head;
//         // if(k == 0) return head;
//         ListNode* temp = head;
//         int n = length(temp);
//         k = k % n;
//         ListNode* newNode1 = reverse(temp ,0,  n -k -1);
//         ListNode* newNode2 = reverse(newNode1 ,n- k , n-1);
//         ListNode* newNode3 = reverse(temp , 0 , n- 1);
//         return head;
//     }
// };



class Solution {
public:
    int length(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            head = head -> next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        int n = length(head);
        
        k = k % n;
        ListNode* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = head;

        int cnt = 1;
        temp = head;
        while(cnt < n -k){
            temp = temp -> next;
            cnt++;
        }
        head = temp -> next;
        temp -> next = NULL;

        return head;
    }
};