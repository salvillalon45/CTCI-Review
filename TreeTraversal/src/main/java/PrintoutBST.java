import java.util.Stack;

public class PrintoutBST {
    static Stack<Integer> stack = new Stack<>();

    public static void inOrderStack(TreeNode node) {
        if (node == null) {
            return;
        }

        inOrderStack(node.left);
        stack.push(node.data);
        inOrderStack(node.right);
    }

    public static void printBST(TreeNode node) {
        inOrderStack(node);

        while (stack.size() > 0) {
            int popped = stack.pop();
            System.out.print(popped + " ");
        }
    }
}

/*
Interesting Thing That Occurred Here
Originally on the printBST method. I had a for loop that used a variable that was incrementing up to the size of the
stack. In the body of the for loop I was doing pop on the stack. For example:

for (int i = 0; i < stack.size(); i++) {
    int popped = stack.pop();
    System.out.print(popped + " ");
}


This did not work. It did not work because as I was incrementing I was also decrementing. At one point the i and the stack.size()
will reach a point where the two would be the same number even before visiting all the values in the stack
it would be:

i = 0   size = 8
---------------------
i = 1   size = 7
i = 2   size = 6
i = 3   size = 5
i = 4   size = 4 Here the loop will stop.

This was an interesting bug that I found.

The moral of the story is to use a While loop when iterating a Stack!
 */
