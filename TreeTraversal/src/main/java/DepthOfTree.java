public class DepthOfTree {

    /**
     *
     * Description:
     * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
     *
     * Time Complexity: Theta(n) since we are visiting each node in the tree
     * Space Complexity: O(1) since we are not using extra space
     */
    public static int findDepth(TreeNode root) {
       if (root == null) {
           return 0;
       }

       return 1 + Math.max(findDepth(root.left), findDepth(root.right));
    }
}
