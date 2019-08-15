public class PostOrderTreeTraversal {
    public static void postOrder(Main.TreeNode node) {
        if (node == null) {
            return;
        }

        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.data + " ");
    }
}
