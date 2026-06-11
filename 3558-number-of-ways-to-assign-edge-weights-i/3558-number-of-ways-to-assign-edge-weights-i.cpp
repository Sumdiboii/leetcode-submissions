#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int assignEdgeWeights( vector<vector<int>>& edges) {
        // Optimize standard I/O operations for performance
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int total_edges = edges.size();
        int n = total_edges + 1;
        
        // --- GRAPH REPRESENTATION (Forward Star / Flat Adjacency List) ---
        // Instead of nested vectors, we use flat arrays for speed.
        // first_edge_pointer[node] stores the ID of the first edge connected to that node.
        vector<int> first_edge_pointer(n + 1, -1);
        
        // Stores the target/destination node that a specific edge ID points to.
        vector<int> edge_destination(2 * total_edges);
        
        // Linked list structure: stores the ID of the next edge connected to the same source node.
        vector<int> next_edge_pointer(2 * total_edges);
        
        int current_edge_id = 0;
        auto add_directional_edge = [&](int source, int destination) {
            edge_destination[current_edge_id] = destination;
            next_edge_pointer[current_edge_id] = first_edge_pointer[source];
            first_edge_pointer[source] = current_edge_id;
            current_edge_id++;
        };

        // Populate our flat graph structure (undirected means adding both ways)
        for (const auto& edge : edges) {
            int node_a = edge[0];
            int node_b = edge[1];
            add_directional_edge(node_a, node_b);
            add_directional_edge(node_b, node_a);
        }

        // --- BFS TRACKING ---
        // distance_from_root[node] tracks how many edges away a node is from node 1.
        vector<int> distance_from_root(n + 1, -1);
        
        // A flat vector acting as a high-performance queue (no push/pop memory overhead)
        vector<int> bfs_queue;
        bfs_queue.reserve(n);

        // Initialize BFS from the root (Node 1)
        int root_node = 1;
        distance_from_root[root_node] = 0;
        bfs_queue.push_back(root_node);

        int max_depth_found = 0;
        size_t queue_index = 0;

        // Traverse the tree level by level to find the deepest node
        while (queue_index < bfs_queue.size()) {
            int current_node = bfs_queue[queue_index++];
            int current_distance = distance_from_root[current_node];
            
            if (current_distance > max_depth_found) {
                max_depth_found = current_distance;
            }

            // Loop through all edges connected to the current node
            for (int edge_id = first_edge_pointer[current_node]; edge_id != -1; edge_id = next_edge_pointer[edge_id]) {
                int neighbor_node = edge_destination[edge_id];
                
                // If the neighbor hasn't been visited yet
                if (distance_from_root[neighbor_node] == -1) {
                    distance_from_root[neighbor_node] = current_distance + 1;
                    bfs_queue.push_back(neighbor_node);
                }
            }
        }

        // --- MATH CALCULATION ---
        // Formula: 2^(max_depth - 1) % (10^9 + 7)
        long long total_valid_combinations = 1;
        long long multiplier_base = 2;
        int exponent = max_depth_found - 1;
        long long modulo_prime = 1000000007;

        // Fast Binary Exponentiation
        while (exponent > 0) {
            if (exponent & 1) { // If the exponent is odd
                total_valid_combinations = (total_valid_combinations * multiplier_base) % modulo_prime;
            }
            multiplier_base = (multiplier_base * multiplier_base) % modulo_prime;
            exponent >>= 1; // Divide exponent by 2
        }

        return total_valid_combinations;
    }
};