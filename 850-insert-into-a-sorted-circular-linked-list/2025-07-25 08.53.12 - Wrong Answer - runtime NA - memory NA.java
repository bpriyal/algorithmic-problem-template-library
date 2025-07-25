/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
    public Node insert(Node head, int insertVal) {
        Node newNode = new Node (insertVal);
        Node root = head;
        if (head == null) {
            newNode.next = newNode;
            return newNode;
        }
        if (root.next == root) {
            root.next = newNode;
            newNode.next = root;
            return root;
        }
        // if (insertVal < root.val)
        Node prev = root;
        
        do {
            prev = root;
            root = root.next;
            if (prev.val > root.val) {
                if (insertVal > prev.val) root = insert (prev, root, newNode);
            }
            else if (insertVal >= prev.val && insertVal < root.val) {
                root = insert(prev,root,newNode);
                break;
            }
        } while (root != head); 
        return root;
    }
    Node insert (Node prev, Node curr, Node between) {
        prev.next = between;
        between.next = curr;
        return curr;
    }
}