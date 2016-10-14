#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

/**
  * Floyd Warshall Algorithm
  *
  * Finds the shortest path between all pairs of verticies.
  *
  * It works by iteratively going over the graph to look
  * for better routes, until there is no change.
  *
  * Time Complexity
  * ---------------
  * Ω(n^3)   Best case
  * Θ(n^3)   Average
  * O(n^3)   Worst case
  *
  * Space Complexity
  * ----------------
  * O(n^2)   Worst case
  */

#ifndef INF
#define INF INT_MAX
#endif

#ifndef N
#define N 5
#endif

int** floydWarshall(int** graph) {
  int*** distances;
  size_t i, j, k;

  for (k = 1; k < N; k++) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        distances[k][i][j] = min(distances[k-1][i][j], distances[k-1][i][k] + distances[k-1][k][j]);
      }
    }
  }

  return distances[N];
}

int main(int argc, char const *argv[]) {
  int** graph = {
    {0  , 3  , 8  , INF, -4 },
    {INF, 0  , INF, 1  , 7  },
    {INF, 4  , 0  , INF, INF},
    {2  , INF, -5 , 0  , INF},
    {INF, INF, INF, 6  , 0  }
  };
  int** distances = floydWarshall(graph);

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      if (distances[i][j] == INF) {
        cout << "INF ";
      } else {
        cout << distances[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
