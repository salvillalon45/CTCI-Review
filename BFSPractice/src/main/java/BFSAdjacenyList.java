import java.util.Queue;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;


public class BFSAdjacenyList {

    static class Node {
        int data;
        boolean visited;
        List<Node> neighbors;

        Node(int data) {
            this.data = data;
            this.neighbors = new ArrayList<>();
        }

        public void addNeighbors(Node node) {
            this.neighbors.add(node);
        }

        public List<Node> getNeighbors() {
            return this.neighbors;
        }

        public void setNeighbors(List<Node> neighbors) {
            this.neighbors = neighbors;
        }
    }

    public Queue<Node> queue;
    // static ArrayList<Node> nodes;

    public BFSAdjacenyList() {
        queue = new LinkedList<Node>();
    }

    public void BFS(Node node) {

        node.visited = true;
        queue.add(node);

        while (!queue.isEmpty()) {
            Node popped = queue.remove();
            System.out.print(popped.data + " ");
            List<Node> nodes = popped.getNeighbors();

            for (int i = 0; i < nodes.size(); i++) {
                Node curNode = nodes.get(i);

                if (curNode != null && curNode.visited == false) {
                    curNode.visited = true;
                    queue.add(curNode);
                }
            }
        }
    }
}
