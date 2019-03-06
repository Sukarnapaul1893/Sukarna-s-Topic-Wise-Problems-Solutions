#include<bits/stdc++.h>

using namespace std;

int bellmanFord(
                    vector< list< pair<int, int> > > adjacencyList,
                    int vertices,
                    int startVertex,
                    vector< pair<int, int> > & shortestDistances
               )
{
    list< pair<int, int> >::iterator traverse;
    int i, j, k;

    for (i = 0; i <= vertices; ++i) {
        shortestDistances[i].first = INT_MAX;
        shortestDistances[i].second = -1;
    }

    shortestDistances[startVertex].first = 0;
    shortestDistances[startVertex].second = 0;

    for (i = 0; i < vertices - 1; ++i) {
        for (j = 0; j < vertices; ++j) {

            traverse = adjacencyList[j].begin();

            while (traverse != adjacencyList[j].end()) {
                if (shortestDistances[j].first == INT_MAX) {
                    ++traverse;
                    continue;
                }

                if ((*traverse).second + shortestDistances[j].first < shortestDistances[(*traverse).first].first) {

                    shortestDistances[(*traverse).first].first = (*traverse).second + shortestDistances[j].first;
                    shortestDistances[(*traverse).first].second = j;
                }
                ++traverse;
            }
        }
    }
    for (j = 0; j < vertices; ++j) {
        traverse = adjacencyList[j].begin();

        while (traverse != adjacencyList[j].end()) {
            if ((*traverse).second + shortestDistances[j].first < shortestDistances[(*traverse).first].first) {
                return j;
            }

            ++traverse;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int vertices, edges, v1, v2, weight;

        scanf("%d", &vertices);
        scanf("%d", &edges);
        vector< list< pair<int, int> > > adjacencyList(vertices + 1);

        for (int i = 1; i <= edges; ++i) {
            scanf("%d%d%d", &v1, &v2, &weight);
            adjacencyList[v1].push_back(make_pair(v2, weight));
            //adjacencyList[v2].push_back(make_pair(v1, -weight)); //For undirected graph
        }

        vector< pair<int, int> > shortestDistances(vertices + 1);
        int startVertex=0;

        int returnValue = bellmanFord(adjacencyList, vertices, startVertex, shortestDistances);

        if (returnValue == -1) {
            printf("not possible\n");
        }
        else {
            printf("possible\n");
        }
    }
}
