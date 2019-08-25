public class InsertIntoBinaryTree {

    /**
     *
     * Description:
     * This insert into a binary search tree. The way it works is that once it hits null, then it tries to insert
     * by changing the current node with value of null, to the given int val
     * Then it will try to place this new node either on the left or right side of the root it came from
     *
     * Time Complexity: O(log n) since we are not visiting all nodes to do this operation
     * Space Complexity: O(h) since it depends on how tall the tree is and how far we have to go down
     */
    public static TreeNode insertToBST(TreeNode root, int val) {
        if (root == null) {
            TreeNode newNode = new TreeNode(val);
            root = newNode;
        }
        else if (root.data < val) {
            TreeNode newNodeRight = insertToBST(root.right, val);
            root.right = newNodeRight;
        }
        else if (root.data > val) {
            TreeNode newNodeLeft = insertToBST(root.left, val);
            root.left = newNodeLeft;
        }

        return root;
    }
}
