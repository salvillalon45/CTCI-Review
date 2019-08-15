

public class Main {

    public static void main(String[] args) {

        // Adjacency List Test
        // ---------------------------------------------------------------
//        BFSAdjacenyList.Node node40 = new BFSAdjacenyList.Node(40);
//        BFSAdjacenyList.Node node10 = new BFSAdjacenyList.Node(10);
//        BFSAdjacenyList.Node node20 = new BFSAdjacenyList.Node(20);
//        BFSAdjacenyList.Node node30 = new BFSAdjacenyList.Node(30);
//        BFSAdjacenyList.Node node60 = new BFSAdjacenyList.Node(60);
//        BFSAdjacenyList.Node node50 = new BFSAdjacenyList.Node(50);
//        BFSAdjacenyList.Node node70 = new BFSAdjacenyList.Node(70);
//
//        node40.addNeighbors(node10);
//        node40.addNeighbors(node20);
//        node10.addNeighbors(node30);
//        node20.addNeighbors(node10);
//        node20.addNeighbors(node30);
//        node20.addNeighbors(node60);
//        node20.addNeighbors(node50);
//        node30.addNeighbors(node60);
//        node60.addNeighbors(node70);
//        node50.addNeighbors(node70);
//
//        System.out.println("The BFS traversal of the graph is ");
//        BFSAdjacenyList bfsExample = new BFSAdjacenyList();
//
//        bfsExample.BFS(node40);



        // Adjacency Matrix Test
        // ---------------------------------------------------------------
        BFSAdjacencyMatrix.Node node40 =new BFSAdjacencyMatrix.Node(40);
        BFSAdjacencyMatrix.Node node10 =new BFSAdjacencyMatrix.Node(10);
        BFSAdjacencyMatrix.Node node20 =new BFSAdjacencyMatrix.Node(20);
        BFSAdjacencyMatrix.Node node30 =new BFSAdjacencyMatrix.Node(30);
        BFSAdjacencyMatrix.Node node60 =new BFSAdjacencyMatrix.Node(60);
        BFSAdjacencyMatrix.Node node50 =new BFSAdjacencyMatrix.Node(50);
        BFSAdjacencyMatrix.Node node70 =new BFSAdjacencyMatrix.Node(70);

        BFSAdjacencyMatrix.nodes.add(node40);
        BFSAdjacencyMatrix.nodes.add(node10);
        BFSAdjacencyMatrix.nodes.add(node20);
        BFSAdjacencyMatrix.nodes.add(node30);
        BFSAdjacencyMatrix.nodes.add(node60);
        BFSAdjacencyMatrix.nodes.add(node50);
        BFSAdjacencyMatrix.nodes.add(node70);

        int adjacency_matrix[][] = {
                {0,1,1,0,0,0,0}, // Node 1: 40
                {0,0,0,1,0,0,0}, // Node 2 :10
                {0,1,0,1,1,1,0}, // Node 3: 20
                {0,0,0,0,1,0,0}, // Node 4: 30
                {0,0,0,0,0,0,1}, // Node 5: 60
                {0,0,0,0,0,0,1}, // Node 6: 50
                {0,0,0,0,0,0,0}, // Node 7: 70
        };

        System.out.println("The BFS traversal of the graph is ");
        BFSAdjacencyMatrix bfsExample = new BFSAdjacencyMatrix();
        bfsExample.BFS(adjacency_matrix, node40);

    }
}
