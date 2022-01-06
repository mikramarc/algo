#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

typedef std::map<int, vector<int> > adj_list;

adj_list map_to_graph(const vector<vector<int> >& map)
{
    adj_list result;

    int map_h = map.size();
    int map_w = map[0].size();

    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};

    for (int i = 0; i < map_h; ++i)
    {
        for (int j = 0; j < map_w; ++j)
        {
            if (map[i][j] == 0) continue;

            vector<int> neighbours;

            for (int k = 0; k < 4; ++k)
            {
                if (i + x[k] >= 0 && i + x[k] < map_h && j + y[k] >= 0 && j + y[k] < map_w &&
                    map[i + x[k]][j + y[k]] == 1)
                {
                    neighbours.push_back((i + x[k])*map_w + (j + y[k]));
                }
            }
            result[i*map_w + j] = neighbours;
        }
    }

    return result;
}

void bfs(const adj_list& graph, int start, int finish)
{
    list<int> q;
    q.push_back(start);
    map<int, bool> visited;
    map<int, int> depth;
    visited[start] = true;
    depth[start] = 0;

    while (!q.empty())
    {
        int current_node = q.front();
        cout << "current node: " << current_node << ", depth: " << depth[current_node] << endl;
        q.pop_front();

        for (const auto& x : graph.at(current_node))
        {
            if (x == finish)
            {
                cout << "Found exit and distance " << depth[current_node] + 1 << endl;
                return;
            }
            if (!visited[x])
            {
                q.push_back(x);
                visited[x] = true;
                depth[x] = depth[current_node] + 1;
            }
        }
    }

}

int main()
{
    vector<vector <int> > dungeon_map = {{1, 1, 1, 1, 1, 1},
                                         {1, 0, 0, 0, 0, 1},
                                         {1, 1, 1, 1, 1, 1}};


    auto graph = map_to_graph(dungeon_map);

    for (const auto& x : graph)
    {
        cout << x.first << ":" << endl;
        for (const auto& y : x.second)
        {
            cout << "\t" << y << endl;
        }
    }

    cout << endl << endl;

    bfs(graph, 0, 12);

    return 0;
}

/* 
NOTES
- instead of translating to graph form just make method that gives adj nodes
- if not all nodes in adj list, use map instead of vector for coloring
 */