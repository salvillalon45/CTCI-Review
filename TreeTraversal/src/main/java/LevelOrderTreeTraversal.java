import java.util.LinkedList;
import java.util.Queue;

public class LevelOrderTreeTraversal {

    public static void levelOrder(Main.TreeNode node) {
        Queue<Main.TreeNode> queue = new LinkedList<>();

        if (node != null) {
            queue.add(node);
        }

        while (!queue.isEmpty()) {
            Main.TreeNode popped = queue.remove();
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
