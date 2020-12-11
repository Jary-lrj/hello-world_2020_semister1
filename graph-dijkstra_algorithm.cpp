//--by Ruijie Li,2020-12-11,Dijkstra algorithm.Allrights reserved.
#include <iostream>
#include <string>
using namespace std;
int INT_max = 0x3f3f3f3f;
int graph_matrix[10][10];
bool graph_vis[10];
int graph_dis[10];
int node_num, edge_num;
int start_v, end_v, edge_weight;
int main()
{
    cin >> node_num >> edge_num;
    for (int i = 1; i <= node_num; i++)
    {
        for (int j = 1; j <= node_num; j++)
        {
            if (i == j)
                graph_matrix[i][j] = 0;
            else
            {
                graph_matrix[i][j] = INT_max;
            }
        }
    }
    for (int i = 1; i <= edge_num; i++)
    {
        cin >> start_v >> end_v >> edge_weight;
        graph_matrix[start_v][end_v] = edge_weight;
    }
    //we regard node1 as our start node;
    //so the first line is the set of its direct paths to other nodes.
    for (int i = 1; i <= node_num; i++)
    {
        graph_dis[i] = graph_matrix[1][i];
    }
    //from now,node1 is visited and its shortest path's length is 0(to itself).
    for (int i = 1; i <= node_num; i++)
        graph_vis[i] = 0;
    graph_vis[1] = 1;
    for (int i = 1; i <= node_num - 1; i++)
    {
        int min_dist = INT_max;
        //the current shortest node to the start node.
        int min_dist_index = 0;
        //the index of the current shortest node to the start node.
        for (int k = 1; k <= node_num; k++)
        {
            //search for node_num times, find the current shortest node.
            if (min_dist > graph_dis[k] && graph_vis[k] == 0)
            {
                min_dist = graph_dis[k];
                min_dist_index = k;
            }
        }
        //the current shortest node has been visited.
        graph_vis[min_dist_index] = 1;
        for (int j = 1; j <= node_num; j++)
        {
            //for every node,whether the direct path to the final node is shorter or passing
            //min_dist_index node is shorter,then set shortest path as the shorter weight sum.
            if (graph_matrix[min_dist_index][j] < INT_max)
            {
                if (graph_dis[j] > graph_matrix[min_dist_index][j] + graph_dis[min_dist_index])
                    graph_dis[j] = graph_matrix[min_dist_index][j] + graph_dis[min_dist_index];
            }
        }
    }
    for (int i = 1; i <= node_num; i++)
    {
        cout << graph_dis[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
