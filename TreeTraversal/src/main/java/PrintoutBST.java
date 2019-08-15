import java.util.Stack;

public class PrintoutBST {
    static Stack<Integer> stack = new Stack<>();

    public static void inOrderStack(Main.TreeNode node) {
        if (node == null) {
            return;
        }

        inOrderStack(node.left);
        stack.push(node.data);
        inOrderStack(node.right);
    }

    public static void printBST(Main.TreeNode node) {
        inOrderStack(node);

        while (stack.size() > 0) {
            int popped = stack.pop();
            System.out.print(popped + " ");
        }
    }
}
