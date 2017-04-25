#ifndef GEOMETRY
#define GEOMETRY

#include <Eigen/Core>

using namespace Eigen;

namespace Geometry {

//Representa a aresta que vai de a a b
struct Edge {
    Vector3f a;
    Vector3f b;

    Edge(Vector3f _a, Vector3f _b) : a(_a), b(_b) { }
};

}

#endif // GEOMETRY

