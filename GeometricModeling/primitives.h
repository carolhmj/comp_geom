#ifndef PRIMITIVES
#define PRIMITIVES

#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;

namespace Primitives {
    VectorXf distance(VectorXf a, VectorXf b) {
        return (a-b).norm();
    }
    VectorXf angle(VectorXf a, VectorXf b) {
        return std::acos(a.dot(b) / (a.norm() * b.norm()));
    }
    //Angulo orientado
    VectorXf angle(VectorXf a) {
        if (a.cols() !=  2) { throw 0; }
        return angle(a, Vector2f(1,0));
    }
}

#endif // PRIMITIVES

