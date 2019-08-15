import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BFSAdjacencyMatrix {
    static class Node {
        int data;
        boolean visited;

        Node(int data) {
            this.data = data;
        }
    }

    private Queue<Node> queue;
    static ArrayList<Node> nodes = new ArrayList<>();

    public BFSAdjacencyMatrix() {
        queue = new LinkedList<>();
    }

    public ArrayList<Node> findNeighbors(int adjacenyMatrix[][], Node x) {
        int nodeIndex = -1;

        // This for loop will iterate through the array of nodes until it finds the one
        // we are looking for
        System.out.println("NODES::: " + nodes);
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.get(i).equals(x)) {
                nodeIndex = i;
                break;
            }
        }

        // If nodeIndex is still -1, this means that this node was not found and there
        // was no neighbors to find for it
        ArrayList<Node> neighbors = new ArrayList<>();

        if (nodeIndex != -1) {
            System.out.println(adjacenyMatrix[nodeIndex].length);
            for (int j = 0; j < adjacenyMatrix[nodeIndex].length; j++) {
                System.out.println("What is value:: " + adjacenyMatrix[nodeIndex].getClass());
                // If it finds a one that means that there is an edge between two nodes. You want to includes this
                // in the list of neighbors
                if (adjacenyMatrix[nodeIndex][j] == 1) {
                    neighbors.add(nodes.get(j));
                }
            }
        }

        return neighbors;
    }

    public void BFS(int adjacenyMatrix[][], Node node) {

        node.visited = true;
        queue.add(node);

        while (!queue.isEmpty()) {
            Node popped = queue.remove();
            System.out.print(popped.data + " ");
            ArrayList<Node> neighbors = findNeighbors(adjacenyMatrix, popped);

            for (int i = 0; i < neighbors.size(); i++) {
                Node curNode = neighbors.get(i);

                if (curNode != null && curNode.visited == false) {
                    curNode.visited = true;
                    queue.add(curNode);
                }
            }
        }
    }


}
