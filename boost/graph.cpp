/*
 * @Description: dijkstra算法
 * @version: v1.0
 * @Author: HTY
 * @Date: 2022-10-15 18:51:50
 */


#include <iostream>
#include <vector>
#include <utility>                   // for std::pair
#include <algorithm>                 // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;
using namespace std;


int main(int, char*[])
{
    // create a typedef for the Graph type
    typedef property<edge_weight_t, int> EdgeWeightProperty; //边的权重
    typedef adjacency_list<vecS, vecS, directedS,no_property,EdgeWeightProperty> Graph;
    typedef graph_traits < Graph >::vertex_descriptor vertex_descriptor;
    typedef std::pair<int, int> Edge;
    enum {A,B,C,D,E,F,G,N};

    Graph graph;
    add_edge(A, B, 6, graph);
    add_edge(B, C, 3, graph);
    add_edge(B, D, 3, graph);
    add_edge(D, E, 4, graph);
    add_edge(D, F, 2, graph);
    add_edge(E, F, 4, graph);
    add_edge(C, F, 9, graph);

    int ipot_st, ipot_end;
    ipot_st  = A; //起始点
    ipot_end = F; //结束

    std::vector<vertex_descriptor> p(num_vertices(graph));
    std::vector<Graph::edge_descriptor> q(num_vertices(graph));
    std::vector<int> d(num_vertices(graph));
    vertex_descriptor s = vertex(ipot_st, graph);
    std::cout << " start point Vertext A to F" << std::endl;
    dijkstra_shortest_paths(graph, s,
        predecessor_map(boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, graph))).
        distance_map(boost::make_iterator_property_map(d.begin(), get(boost::vertex_index, graph))));

    std::cout << "distances and parents:" << std::endl;
    graph_traits < Graph >::vertex_iterator vi, vend;


    //输出从A点 到其余点的最短距离和父节点
    for (boost::tie(vi, vend) = vertices(graph); vi != vend; ++vi) {
        std::cout << "distance(" << *vi << ") = " << d[*vi] << ", ";
        std::cout << "parent(" << *vi << ") = " << p[*vi] << std::
            endl;
    }

    //从终止点到起始点的路径
    int t = ipot_end;
    vector<int> path;
    for (; t != ipot_st; t = p[t])
        path.push_back(t);
    path.push_back(ipot_st);
    //反转路线 从起始点到出发点
    reverse(path.begin(), path.end());

    //输出路径
    for (int i = 0; i < path.size(); i++)
    {
        std::cout << path[i] << "-> ";
    }
    std::cout << std::endl;

    return 0;
}
