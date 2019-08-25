import java.util.Stack;

public class InOrderTreeTraversal {

    /**
     *
     * Description:
     * This is the InOrder Tree Traversal using Recursion
     *
     * Time Complexity: Theta(n) since we are visiting all nodes to do this operation
     * Space Complexity: O(h) since it depends on how tall the tree is and how far we have to go down
     *
     */
    public static void inOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        inOrder(node.left);
        System.out.print(node.data + " ");
        inOrder(node.right);
    }


    /**
     *
     * Description:
     * This is the InOrder Tree Traversal using Iteration
     * The second while loop is what helps us go to the left most node and get the smallest one
     * Once we know that the cur is at null, then we are ready to pop the element and print the value
     * The element that we are going to pop is in the correct order thanks to how they are stored in the stack
     * The stack will always have the node that is next in the sequence at the very top
     *
     * Time Complexity: Theta(n) since we are visiting all nodes to do this operation
     * Space Complexity: O(h) since it depends on how tall the tree is and how far we have to go down
     *
     */
    public static void iterativeInOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = node;

        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }

            if (cur == null && !stack.isEmpty()) {
                TreeNode popped = stack.pop();
                System.out.print(popped.data + " ");
                cur = popped.right;
            }
        }
    }
}
