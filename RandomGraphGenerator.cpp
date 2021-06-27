#include <bits/stdc++.h>
using namespace std;


//Class Bellmanford
class BellmanFord{

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
        cout << edge << " " << endl;
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
            for (int j = 0; j < graphList[i].size(); j++)
                cout << graphList[i][j] << " ";
            cout << endl;
        }
    }

};


// Main Function
int main() {
    
    //Creating object of class
    BellmanFord init;
    long edges[1] = {30};

    for( long edge: edges){
        init.generateGraph(edge);
    }

    return 0;
}
