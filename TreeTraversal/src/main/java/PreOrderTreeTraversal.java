import java.util.Stack;

public class PreOrderTreeTraversal {

    /**
     *
     * Description:
     * This is the PreOrder Tree Traversal using Recursion
     *
     */
    public static void preOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }


    /**
     *
     * Description:
     * This is the PreOrder Tree Traversal using Iteration
     *
     */
    public static void iterativePreOrder(TreeNode node) {
        Stack<TreeNode> stack = new Stack<>();

        if (node != null) {
            stack.push(node);
        }

        while(!stack.isEmpty()) {
            TreeNode popped = stack.pop();
            System.out.print(popped.data + " ");

            if (popped.right != null) {
                stack.push(popped.right);
            }

            if (popped.left != null) {
                stack.push(popped.left);
            }
        }

    }
}

/*
The Complexities:
Time Complexity: Theta(n)
- It is theta(n) because we are visiting each node in the tree

Space Complexity: O(h)
- It is O(h) because it depends on the height of the tree. It will be


How did the iterative solution work?
- We use a stack to help us keep track of when to visit the nodes

- If you notice we first push the nodes on the right by doing this it causes them to go on the bottom of the stack. Right
  after we push the node on the right we push the left node. Doing this helps so that the left nodes are visited/popped first
  before the right ones
 */