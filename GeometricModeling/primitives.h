#ifndef PRIMITIVES
#define PRIMITIVES

#include <Eigen/Dense>
#include <cmath>
#include <vector>
#include "geometry.h"

using namespace Eigen;

namespace Primitives {
    //Distância entre pontos
    float distance(VectorXf a, VectorXf b) {
        return (a-b).norm();
    }
    //Ângulo entre vetores
    float angle(VectorXf a, VectorXf b) {
        return std::acos(a.dot(b) / (a.norm() * b.norm()));
    }
    //Ângulo orientado de um vetor
    float angle(VectorXf a) {
        if (a.cols() !=  2) { throw 0; }
        return angle(a, Vector2f(1,0));
    }
    //Vetor normal ao plano dos pontos (em R3)
    //Área orientada do polígono formado pelos pontos (em R2)
    float S(std::vector<VectorXf> p, VectorXf o) {
        //TODO checar se tds de p são 2/3d e se o é 2/3d
        //TODO formula: S = 1/2 * (op1 x op2 + op2 x op3 + ... + opn x op1)
    }

    //Área orientada do polígono, com pontos 2D e o = (0,0)
    float area(std::vector<Vector2f> p) {
        float area = 0.0;
        unsigned int i = 0;
        for (; i < p.size() - 1; i++)
        //invariante 0 <= i <= p.size - 1
        {
            //S = x1y2 - x2y1 + x2y3 - x3y2 + ... + xny1 - x1yn
            area += p[i][0]*p[i+1][1] - p[i+1][0]*p[i][1];
        }
        //i == p.size - 1
        area += p[i][0]*p[1][1] - p[1][0]*p[i][1];
        return area;
    }

    //Produto vetorial em 2D
    float cross2d(Vector2f a, Vector2f b) {
        return a[0]*b[1] - b[0]*a[1];
    }

    //Retorna se o vetor b está à esquerda do vetor a
    bool isLeftTo(Vector2f b, Vector2f a) {
        return cross2d(a, b) > 0;
    }

}

#endif // PRIMITIVES

