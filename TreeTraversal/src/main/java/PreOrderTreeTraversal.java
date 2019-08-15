public class PreOrderTreeTraversal {
    public static void preOrder(Main.TreeNode node) {
        if (node == null) {
            return;
        }

        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
}
