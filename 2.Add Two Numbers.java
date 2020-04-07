/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int i = 0;
        int j = 0;
        ListNode head = l1;
        while(l1.next != null && l2.next != null) {
            i = (l1.val + l2.val + j) % 10;
            j = (l1.val + l2.val + j) / 10;
            l1.val = i;
            
            l1 = l1.next;
            l2 = l2.next;
        }
        j = j + l2.val;
        if(l2.next != null) {
            l1.next = l2.next;
        }
        ListNode temp = l1;
        while(l1 != null) {
            i = (l1.val + j) % 10;
            j = (l1.val + j) / 10;
            l1.val = i;
            temp = l1;
            l1 = l1.next;
        }
        l1 = temp;
        if (j != 0 ) {
            ListNode last = new ListNode(j);
            l1.next = last;
        }

        return head;
    }
}