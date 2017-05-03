#ifndef ALGORITHMS
#define ALGORITHMS

#include "geometry.h"
#include "primitives.h"
#include <vector>

namespace Algorithm {
    //Recebe uma lista de pontos, retorna as arestas do fecho convexo
    std::vector<Vector2f> quickhull(std::vector<Vector2f> C);

    //Recebe dois pontos e, d, e um conjunto C de pontos situados à sua esquerda. Retorna a lista ordenada das arestas de conv(C U {e,d})
    std::vector<Vector2f> rec_quickhull(std::vector<Vector2f> C, Vector2f e, Vector2f d);
}

#endif // ALGORITHMS

