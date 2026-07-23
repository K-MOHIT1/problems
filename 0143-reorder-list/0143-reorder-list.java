/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverses(ListNode temp){
        if(temp==null) return null;
        ListNode prev=null;
        ListNode temp2=temp;
        while(temp2!=null){
            ListNode nex=temp2.next;
            temp2.next=prev;
            prev=temp2;
            temp2=nex;
        }
        return prev;
    }

    public void reorderList(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        ListNode hd2=head;
        while(fast.next!=null && fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        ListNode temp=slow.next;
        slow.next=null;
        ListNode xd=reverses(temp);
        ListNode x=new ListNode(-1);
        slow=x;
        while(xd!=null && hd2!=null){
            x.next=hd2;
            hd2=hd2.next;
            x=x.next;
            System.out.println(x.val);
           
            x.next=xd;
            xd=xd.next;
            x=x.next;
            System.out.println(x.val);
        } 
        x.next=hd2;
        head=slow.next;

    }
}