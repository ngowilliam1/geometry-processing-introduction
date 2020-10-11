#include "edges.h"
#include <set>
#include <utility>
#include <tuple>
Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  //index of vertices
  int v1, v2;

  // first create a set to store the ordered undirected edges (set used to ensure uniqueness of edge)
  std::set<std::tuple<int,int>> uniqueEdgesSet;
  
  // loop over all faces
  for (int row=0; row<F.rows(); row++){
    for (int i=0; i<3; i++){
      v1 = F(row, i);
      v2 = F(row, (i+1)%3);
      // ensure v1 < v2, this makes smaller index first
      if (v1>v2){
        std::swap(v1,v2);
      }
      uniqueEdgesSet.insert({v1,v2});
    }
  }
  E.resize(uniqueEdgesSet.size(),2);
  int row = 0;
  // convert set of tuple to Eigen Matrix
  for (std::tuple<int,int> edge: uniqueEdgesSet){
    E(row, 0) = std::get<0>(edge);
    E(row, 1) = std::get<1>(edge);
    row++;
  }


  return E;
}
