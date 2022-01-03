#include <iostream>
#include <map>
#include <list>
#include <vector>

typedef std::map<int, std::list<int> > adj_list;

// TODO: Write recursive version too

void DFS(const adj_list &graph, int start)
{
    int curr_node;
    std::vector<int> stack;
    std::vector<bool> visited(graph.size(), false);
    std::vector<int> depths(graph.size(), -1);

    depths[start] = 0;
    stack.push_back(start);

    while(!stack.empty())
    {
        curr_node = stack.back();
        stack.pop_back();

        if (visited[curr_node])
        {
            continue;
        }

        std::cout << "node: " << curr_node << " (level: " << depths[curr_node] << ")" << std::endl;
        visited[curr_node] = true;

        for (const auto& el : graph.at(curr_node))
        {
            if (!visited[el])
            {
                stack.push_back(el);
                depths[el] = depths[curr_node] + 1;
            }
        }
    }
}

// Colouring vertices when adding to the stack
void DFS_2(const adj_list &graph, int start)
{
    int curr_node;
    std::vector<int> stack;
    std::vector<bool> visited(graph.size(), false);
    std::vector<int> depths(graph.size(), -1);

    visited[start] = true;
    depths[start] = 0;
    stack.push_back(start);

    while(!stack.empty())
    {
        curr_node = stack.back();
        std::cout << "node: " << curr_node << " (level: " << depths[curr_node] << ")" << std::endl;
        stack.pop_back();

        for (const auto& el : graph.at(curr_node))
        {
            if (!visited[el])
            {
                stack.push_back(el);
                visited[el] = true;
                depths[el] = depths[curr_node] + 1;
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

    DFS(graph, 0);

    return 0;
}
