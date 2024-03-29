// C Program for Floyd Warshall Algorithm
#include <stdio.h>

// Number of vertices in the graph
#define V 5

/* Define Infinite as a large enough
value. This value will be used
for vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
// void printSolution(int dist[][V]);

// // Solves the all-pairs shortest path
// // problem using Floyd Warshall algorithm
// void floydWarshall(int dist[][V])
// {

//   /* Add all vertices one by one to
//   the set of intermediate vertices.
//   ---> Before start of an iteration, we
//   have shortest distances between all
//   pairs of vertices such that the shortest
//   distances consider only the
//   vertices in set {0, 1, 2, .. k-1} as
//   intermediate vertices.
//   ----> After the end of an iteration,
//   vertex no. k is added to the set of
//   intermediate vertices and the set
//   becomes {0, 1, 2, .. k} */
//   for (int k = 0; k < V; k++)
//   {
//     // Pick all vertices as source one by one
//     for (int i = 0; i < V; i++)
//     {
//       // Pick all vertices as destination for the
//       // above picked source
//       for (int j = 0; j < V; j++)
//       {
//         // If vertex k is on the shortest path from
//         // i to j, then update the value of
//         // dist[i][j]
//         if (dist[i][k] + dist[k][j] < dist[i][j])
//           dist[i][j] = dist[i][k] + dist[k][j];
//       }
//     }
//   }

//   // Print the shortest distance matrix
//   printSolution(dist);
// }

// /* A utility function to print solution */
// void printSolution(int dist[][V])
// {
//   printf(
//       "The following matrix shows the shortest distances"
//       " between every pair of vertices \n");
//   for (int i = 0; i < V; i++)
//   {
//     for (int j = 0; j < V; j++)
//     {
//       if (dist[i][j] == INF)
//         printf("%7s", "INF");
//       else
//         printf("%7d", dist[i][j]);
//     }
//     printf("\n");
//   }
// }

// // driver's code
// int main()
// {
//   /* Let us create the following weighted graph
//       10
//   (0)------->(3)
//     |		 /|\
//   5 |		 |
//     |		 | 1
//   \|/		 |
//   (1)------->(2)
//       3		 */
//   int graph[V][V] = {{0, 8, 5},
//                      {2, 0, INF},
//                      {INF, 1, 0}};

//   // Function call
//   floydWarshall(graph);
//   return 0;
// }
void floydWarshall(int graph[][V])
{
  for (int k = 0; k < V; k++)
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (graph[i][k] + graph[k][j] < graph[i][j])
        {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }

  for (int i = 0; i < V; i++)
  {
    printf("\n");
    for (int j = 0; j < V; j++)
    {
      if (graph[i][j] == INF)
      {
        printf("%7s", "INF");
      }
      else
      {
        printf("%7d", graph[i][j]);
      }
    }
  }
}
void main()
{
  int graph[V][V] = {{0, 3, 8, INF, -4},
                     {INF, 0, INF, 1, 7},
                     {INF, 4, 0, INF, INF},
                     {2, INF, -5, 0, INF},
                     {INF, INF, INF, 6, 0}};

  floydWarshall(graph);
}