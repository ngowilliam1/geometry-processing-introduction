#include "euler_characteristic.h"
#include "edges.h"
int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  int nVertices = F.maxCoeff() + 1; // +1 because coeifficients start at 0
  int nFaces = F.rows();
  int nEdges = edges(F).rows();
  Chi = nVertices - nEdges + nFaces;
  return Chi;
}
