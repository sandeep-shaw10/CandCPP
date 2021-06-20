#include <bits/stdc++.h>
using namespace std;
#define V 9
#define max INT_MAX


bool isValidEdge(int u, int v, vector<bool> inMST)
{
   if (u == v)
       return false;
   if (inMST[u] == false && inMST[v] == false)
        return false;
   else if (inMST[u] == true && inMST[v] == true)
        return false;
   return true;
}
 

void primMST(int cost[][V])
{ 
    vector<bool> inMST(V, false);
 
    inMST[0] = true;

    int edge_count = 0, mincost = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {              
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("Edge %d:(%d, %d) cost: %d \n", edge_count++, a, b, min);
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    printf("\n Minimum cost= %d \n", mincost);
}



int main() {
    int cost[][V] = {
        {max,1,6,5,max,max,max,max,max},
        {1,max,6,max,max,max,max,max,max},
        {6,6,max,max,7,3,max,max,max},
        {5,max,max,max,max,2,10,max,max},
        {max,max,7,max,max,max,max,12,max},
        {max,max,3,2,max,max,max,8,max},
        {max,max,max,10,max,max,max,7,3},
        {max,max,max,max,12,8,7,max,8},
        {max,max,max,max,max,max,3,8,max},
    };

    primMST(cost);
    
    return 0;
}
