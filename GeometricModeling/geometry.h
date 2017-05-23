#ifndef GEOMETRY
#define GEOMETRY

#include <memory>
#include <Eigen/Core>

using namespace Eigen;

namespace Geometry {

//Representa um vértice 2D. Guarda o id e a posição dele
struct Vertex2D {
    unsigned int id;
    Vector2f pos;
    bool is_hull = false;
    Vertex2D() {}
    Vertex2D(unsigned int _id, Vector2f _pos) : id(_id), pos(_pos) { }
};

//Representa a aresta 2D cujos vértices são a e b
struct Edge2D {
    std::shared_ptr<Vertex2D> a;
    std::shared_ptr<Vertex2D> b;

    Vector2f val() {
        return b->pos - a->pos;
    }

    Edge2D() { }
    Edge2D(std::shared_ptr<Vertex2D> _a, std::shared_ptr<Vertex2D> _b) : a(_a), b(_b) { }
};

}

#endif // GEOMETRY

