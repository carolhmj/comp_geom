#ifndef ALGORITHMS
#define ALGORITHMS

#include "geometry.h"
#include "primitives.h"
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

namespace Algorithm {
    //Recebe uma lista de pontos, retorna as arestas do fecho convexo
    std::vector<Vector2f> quickhull(std::vector<Vector2f> C);
    //Recebe uma lista de vértices, retorna um conjunto de arestas
    std::vector<std::shared_ptr<Geometry::Edge2D>> quickhull(std::vector<std::shared_ptr<Geometry::Vertex2D> > C);

    //Recebe dois pontos e, d, e um conjunto C de pontos situados à sua esquerda. Retorna a lista ordenada das arestas de conv(C U {e,d})
    std::vector<Vector2f> rec_quickhull(std::vector<Vector2f> C, Vector2f e, Vector2f d);
    std::vector<std::shared_ptr<Geometry::Edge2D>> rec_quickhull(std::vector<std::shared_ptr<Geometry::Vertex2D>> C, std::shared_ptr<Geometry::Vertex2D> e, std::shared_ptr<Geometry::Vertex2D> d);
}

#endif // ALGORITHMS

