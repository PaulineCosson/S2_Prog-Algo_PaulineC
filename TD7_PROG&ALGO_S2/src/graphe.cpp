#include "graphe.hpp"

void Graph::WeightedGraph::add_vertex(int const id){
    if(adjacency_list.find(id) == adjacency_list.end()){
        adjacency_list.insert ({id,{}}); 
    }
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight){
    if(adjacency_list.find(to) == adjacency_list.end()){
        add_vertex(to);
    }
    adjacency_list[from].push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    add_directed_edge(from,to,weight);
    add_directed_edge(to,from,weight);
}

WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
    for(int i {0}; i < adjacency_matrix.size; i++){
        for(int j {0}; j < adjacency_matrix.size; j++){
            
        }
    }
}