import java.util.Stack;

public class PostOrderTreeTraversal {


    /**
     *
     * Description:
     * This is the PostOrder Tree Traversal using Recursion
     *
     */
    public static void postOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.data + " ");
    }


    /**
     *
     * Description:
     * This is the PostOrder Tree Traversal using Iteration
     * stack1 helps traverse the tree
     * stack2 keeps the order that I need to help print them out
     *
     */
    public static void iterativePostOrder(TreeNode node) {
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();

        if (node != null) {
            stack1.push(node);
        }

        while(!stack1.isEmpty()) {
            TreeNode popped1 = stack1.pop();
            stack2.push(popped1);

            if (popped1.left != null) {
                stack1.push(popped1.left);
            }
            if (popped1.right != null) {
                stack1.push(popped1.right);
            }
        }

        while(!stack2.isEmpty()) {
            TreeNode popped = stack2.pop();
            System.out.print(popped.data + " ");
        }
    }

}
