#include <bits/stdc++.h>
using namespace std;


//Class Bellmanford
class BellmanFord{
    
    //Structure
    struct Edges{
        int to;
        int weight;
    };
    // <vector<vector<Edges>> adjacentList;

    //Access Specifier
    public:
        int vertices = 11;
        int graph[11][11] {0};
        bool setEdges[121] {false};
        vector<vector<int>> graphList;

    //Constructor
    BellmanFord(){
        cout << "Object Created" << endl;
    }
    
    //Random Edge Generation
    void randomify(int edge){

        long limit = vertices*vertices;

        for(long i = 0; i < edge;  ){
            long place = rand() % limit + 1;
            if(place == i+1){ i--; }
            else{
                setEdges[place] = true;
                i++;
            }
        }
    }

    //Generate Adjacency Matrix
    void generateGraph(int edge){
        cout << "EDGES = " << edge << "\n\n";
        cout << "ADJACENCY MATRIX" << endl;
        
        randomify(edge);

        int count = 0;
        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                if(setEdges[count] == 1){ 
                    graph[i][j] = 1;
                }
                count++;
            }
        }

        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        
        generateList();
    }
    
    //Fetch Adjacency List from the Matrix
    void generateList(){
        
        cout << "\n\nADJACENCY LIST" << endl;
        
        for(int i=0; i<vertices; i++){
            vector<int> subGraph;
            for(int j=0; j<vertices; j++){
                if(graph[i][j] == 1){
                    subGraph.push_back(j+1);
                }
            }
            graphList.push_back(subGraph);
        }
        
        for (int i = 0; i < graphList.size(); i++) {
            cout << (i+1) << " --> ";
            for (int j = 0; j < graphList[i].size(); j++)
                cout << graphList[i][j] << " ";
            cout << endl;
        }
    }
    
    //Using Adjacency Matrix
    void deployMatrix(){
        
        //STEP 1: Init all vertices to infinity
        int dis[vertices];
        for(int i=0; i<vertices; i++){
            dis[i] = INT_MAX;
        }
        
        //STEP 2: Init the starting point to 0 
        dis[0] = 0;
        
        //STEP 3: Vertex Relaxation ( V - 1 ) times
        for (int i = 0; i < vertices-1; i++){
            for (int j = 0; j < vertices; j++){
                if(graph[i][j] == 1){
                    if (dis[i] != INT_MAX && dis[i] + graph[i][j] < dis[j])
                        dis[j] = dis[i] + graph[i][j]; 
                }
            }
        }
        
        //STEP 4: Check for Negative Edge Cycle
        
        //STEP 5: Display
        cout << "\n Vertex Distance from Source" << endl;
        for (int i = 0; i < vertices; i++)
            cout << (i+1) << "\t\t" << dis[i] << endl;
        
    }
    
    //Using Adjacency List
    void deployList(){ 
        
        vector<int> dis;
    
        //STEP 1: Init all vertices to infinity
        dis.resize(vertices);
        for(int i=0; i<vertices; i++){
            dis[i] = INT_MAX;
        }
        
        //STEP 2: Init the starting point to 0 
        dis[0] = 0;
        
        //STEP 3: Vertex Relaxation ( V - 1 ) times
        for (int i = 0; i < graphList.size(); i++) {
            for (int j = 0; j < graphList[i].size(); j++){
                if (dis[i] != INT_MAX && dis[i] + 1 < dis[graphList[i][j]-1])
                    dis[graphList[i][j]-1] = dis[i] + 1; 
            }
        }
        
        //STEP 4: Check for Negative Edge Cycle
        
        
        //STEP 5: Display
        cout << "\nVertex Distance from Source" << endl;
        for (int i = 0; i < vertices; i++)
            cout << (i+1) << "\t\t" << dis[i] << endl;
        
    }

};


// Main Function
int main() {
    
    //Creating object of class
    BellmanFord init;
    long edges[1] = {30};

    for( long edge: edges){
        init.generateGraph(edge);
        init.deployMatrix();
        init.deployList();
    }

    return 0;
}
