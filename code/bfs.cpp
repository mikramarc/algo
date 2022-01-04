#include <iostream>
#include <map>
#include <list>
#include <vector>

typedef std::map<int, std::list<int> > adj_list;

void BFS(const adj_list &graph, int start)
{
    std::vector<int> levels(graph.size(), -1);
    std::vector<bool> visited(graph.size(), false);
    int current_node;
    std::list<int> queue;

    visited[start] = true;
    levels[start] = 0;
    queue.push_back(start);

    while (!queue.empty())
    {
        current_node = queue.front();
        queue.pop_front();
        for (const auto& el : graph.at(current_node))
        {
            if (!visited[el])
            {
                int curr_level = levels[current_node] + 1;
                std::cout << "node: " << el << " (level: " << curr_level << ")" << std::endl;
                queue.push_back(el);
                visited[el] = true;
                levels[el] = curr_level;
            }
        }
    }
}

int main()
{
    adj_list graph;

    graph.insert(std::pair<int,std::list<int> >(0, {1, 2, 4}));
    graph.insert(std::pair<int,std::list<int> >(1, {5}));
    graph.insert(std::pair<int,std::list<int> >(2, {6}));
    graph.insert(std::pair<int,std::list<int> >(3, {}));
    graph.insert(std::pair<int,std::list<int> >(4, {3}));
    graph.insert(std::pair<int,std::list<int> >(5, {6}));
    graph.insert(std::pair<int,std::list<int> >(6, {7, 8}));
    graph.insert(std::pair<int,std::list<int> >(7, {}));
    graph.insert(std::pair<int,std::list<int> >(8, {9}));
    graph.insert(std::pair<int,std::list<int> >(9, {}));

    BFS(graph, 0);

    return 0;
}

/* 
NOTES
- typically implemente on a queue
- use list for queue for O(1) pop_front()
- can use std::queue instead of the std::list
 */