package app;

public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode node = new ListNode();
        ListNode dummy = node;
        
        while(l1 != null && l2 != null) {
            int sum = l1.val + l2.val + carry;
            l1 = l1.next;
            l2 = l2.next;
            
            if(sum > 9) {
                carry = 1;
                sum = sum%10;
            } else {
                carry = 0;
            }
            node.next = new ListNode(sum);
            node = node.next;
        }
        ListNode l = (l1 != null) ? l1 : l2;
        while(l != null) {
            int sum = l.val +  carry;
            l = l.next;
            
            if(sum > 9) {
                carry = 1;
                sum = sum%10;
            } else {
                carry = 0;
            }
            node.next = new ListNode(sum);
            node = node.next;
            
        }
        
        if(carry > 0) {
            node.next = new ListNode(carry);
            node = node.next;
        }
        return dummy.next;
    }
    public static void main(String[] args) {
        // ListNode l1=new ListNode(2,ListNode(3,ListNode(4)));
        System.out.println("1");
    }
}
