#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<int, list<int> > adj_list;

// TODO: Write recursive version too

bool detect_cycle(const adj_list &graph, int start)
{
    int curr_node;
    vector<int> stack;
    vector<bool> visited(graph.size(), false);
    vector<int> depths(graph.size(), 100000);
    vector<int> path_stack;
    map<int, bool> in_path;

    depths[start] = 0;
    stack.push_back(start);
    path_stack.push_back(start);

    while(!stack.empty())
    {
        curr_node = stack.back();
        stack.pop_back();

        if (visited[curr_node])
        {
            continue;
        }

        cout << "node: " << curr_node << " (level: " << depths[curr_node] << ")" << endl;
        visited[curr_node] = true;

        auto dist = (depths[path_stack.back()] - depths[curr_node]);
        for (int i = 0; i <= dist; i++)
        {
            int path_back = path_stack.back();
            path_stack.pop_back();
            in_path[path_back] = false;

        }

        path_stack.push_back(curr_node);
        in_path[curr_node] = true;

        for (const auto& el : graph.at(curr_node))
        {
            if(in_path[el])
            {
                return true;
            }

            if (!visited[el])
            {
                stack.push_back(el);
                depths[el] = depths[curr_node] + 1;
            }
        }
    }
    return false;
}


int main()
{

    adj_list graph;

    graph.insert(pair<int,list<int> >(0, {1, 2, 3}));
    graph.insert(pair<int,list<int> >(1, {}));
    graph.insert(pair<int,list<int> >(2, {3}));
    graph.insert(pair<int,list<int> >(3, {4}));
    graph.insert(pair<int,list<int> >(4, {2, 5}));
    graph.insert(pair<int,list<int> >(5, {}));

    cout << "Case one - cycle present" << endl;
    if (detect_cycle(graph, 0)) cout << "cycle detected!" << endl;

    adj_list graph2;

    graph2.insert(pair<int,list<int> >(0, {1, 2, 3}));
    graph2.insert(pair<int,list<int> >(1, {}));
    graph2.insert(pair<int,list<int> >(2, {3}));
    graph2.insert(pair<int,list<int> >(3, {4}));
    graph2.insert(pair<int,list<int> >(4, {1, 5}));
    graph2.insert(pair<int,list<int> >(5, {}));

    cout << "Case one - no cycle" << endl;
    if (detect_cycle(graph2, 0)) cout << "cycle detected!" << endl;

    adj_list graph3;

    graph3.insert(pair<int,list<int> >(0, {1}));
    graph3.insert(pair<int,list<int> >(1, {2}));
    graph3.insert(pair<int,list<int> >(2, {3}));
    graph3.insert(pair<int,list<int> >(3, {0}));

    cout << "Case one - cycle present" << endl;
    if (detect_cycle(graph3, 0)) cout << "cycle detected!" << endl;

    return 0;
}

/* 
NOTES
- typically implemente on stack
- you don't add nodes to stack one by one like it would seem from the concept, you add to stack by layers (sets of neighbours)
- color only when removing from stack from easier understanding
 */