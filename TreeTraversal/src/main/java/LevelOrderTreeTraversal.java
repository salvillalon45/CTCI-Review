import java.util.LinkedList;
import java.util.Queue;

public class LevelOrderTreeTraversal {

    /**
     *
     * Description:
     * To perform Lever Order traversal we use a Queue. This queue helps us keep the order of the
     * nodes from left to right order
     *
     * Time Complexity: Theta(n) since we are visiting each node in the tree
     * Space Complexity: O(w) since it depends on how wide the tree will be
     */
    public static void levelOrder(TreeNode node) {
        Queue<TreeNode> queue = new LinkedList<>();

        if (node != null) {
            queue.add(node);
        }

        while (!queue.isEmpty()) {
            TreeNode popped = queue.remove();
            System.out.print(popped.data + " ");
            if (popped.left != null) {
                queue.add(popped.left);
            }
            if (popped.right != null) {
                queue.add(popped.right);
            }
        }
    }



}
