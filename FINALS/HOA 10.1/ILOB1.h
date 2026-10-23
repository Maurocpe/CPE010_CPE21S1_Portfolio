#ifndef ILOB1_H
#define ILOB1_H

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <stack>

template <typename T>
class Graph;

// Structure for an edge in the graph
template <typename T>
struct Edge
{
    size_t src;
    size_t dest;
    T weight;

    // Compare edges based on their weights
    inline bool operator<(const Edge<T>& e) const
    {
        return this->weight < e.weight;
    }

    inline bool operator>(const Edge<T>& e) const
    {
        return this->weight > e.weight;
    }
};

// Graph class
template <typename T>
class Graph
{
public:

    // Initialize the graph with N vertices
    Graph(size_t N) : V(N)
    {
    }

    // Return number of vertices
    auto vertices() const
    {
        return V;
    }

    // Return all edges
    auto& edges() const
    {
        return edge_list;
    }

    // Add an edge to the graph
    void add_edge(Edge<T>&& e)
    {
        // Check if vertices are within range
        if (e.src >= 1 && e.src <= V &&
            e.dest >= 1 && e.dest <= V)
        {
            edge_list.emplace_back(e);
        }
        else
        {
            std::cerr << "Vertex out of bounds" << std::endl;
        }
    }

    // Return all outgoing edges from vertex v
    auto outgoing_edges(size_t v) const
    {
        std::vector<Edge<T>> edges_from_v;

        for (auto& e : edge_list)
        {
            if (e.src == v)
            {
                edges_from_v.emplace_back(e);
            }
        }

        return edges_from_v;
    }

    // Allow graph to be printed using cout
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Graph<U>& G);

private:

    size_t V;
    std::vector<Edge<T>> edge_list;
};

// Display the graph
template <typename T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& G)
{
    // Use <= so vertex 9 is also displayed
    for (auto i = 1; i <= G.vertices(); i++)
    {
        os << i << ":\t";

        auto edges = G.outgoing_edges(i);

        for (auto& e : edges)
        {
            os << "{" << e.dest << ": " << e.weight << "}, ";
        }

        os << std::endl;
    }

    return os;
}

// Depth-First Search
template <typename T>
auto depth_first_search(const Graph<T>& G, size_t dest)
{
    std::stack<size_t> stack;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    // DFS starts from vertex 1
    stack.push(1);

    while (!stack.empty())
    {
        auto current_vertex = stack.top();
        stack.pop();

        // Check if vertex has not been visited
        if (visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            // Add unvisited adjacent vertices to stack
            for (auto e : G.outgoing_edges(current_vertex))
            {
                if (visited.find(e.dest) == visited.end())
                {
                    stack.push(e.dest);
                }
            }
        }
    }

    return visit_order;
}

// Create the reference graph
template <typename T>
auto create_reference_graph()
{
    Graph<T> G(9);

    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2, 0}, {5, 0}};
    edges[2] = {{1, 0}, {5, 0}, {4, 0}};
    edges[3] = {{4, 0}, {7, 0}};
    edges[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
    edges[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
    edges[6] = {{4, 0}, {7, 0}, {8, 0}};
    edges[7] = {{3, 0}, {6, 0}};
    edges[8] = {{4, 0}, {5, 0}, {6, 0}};
    edges[9] = {};

    for (auto& i : edges)
    {
        for (auto& j : i.second)
        {
            G.add_edge(Edge<T>{i.first, j.first, j.second});
        }
    }

    return G;
}

// Test DFS
template <typename T>
void test_DFS()
{
    // Create and print the graph
    auto G = create_reference_graph<unsigned>();

    std::cout << G << std::endl;

    // Run DFS starting from vertex 1
    std::cout << "DFS Order of vertices: " << std::endl;

    auto dfs_visit_order = depth_first_search(G, 1);

    for (auto v : dfs_visit_order)
    {
        std::cout << v << std::endl;
    }
}

#endif
