public class Main {

    static class TreeNode {
        TreeNode left;
        TreeNode right;
        int data;

        TreeNode(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    public static void main(String args[]) {

        TreeNode root = new TreeNode(30);

        root.left = new TreeNode(10);
        root.right = new TreeNode(55);
        root.left.right = new TreeNode(20);
        root.left.right.left = new TreeNode(15);
        root.left.right.right = new TreeNode(25);
        root.right.left = new TreeNode(45);
        root.right.right = new TreeNode(70);

        System.out.println("PreOrder Tree Traversal");
        PreOrderTreeTraversal.preOrder(root);

        System.out.println(" ");
        System.out.println(" ");
        System.out.println("PostOrder Tree Traversal");
        PostOrderTreeTraversal.postOrder(root);

        System.out.println(" ");
        System.out.println(" ");
        System.out.println("InOrder Tree Traversal");
        InOrderTreeTraversal.inOrder(root);

        System.out.println(" ");
        System.out.println(" ");
        System.out.println("LevelOrder Tree Traversal");
        LevelOrderTreeTraversal.levelOrder(root);


    }
}