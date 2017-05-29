#ifndef PRIMITIVES
#define PRIMITIVES

#include <Eigen/Dense>
#include <cmath>
#include <vector>

using namespace Eigen;

namespace Primitives {
    //Distância entre pontos
    float distance(VectorXf a, VectorXf b);

    //Ângulo entre vetores
    float angle(VectorXf a, VectorXf b);

    //Ângulo orientado de um vetor
    float angle(VectorXf a);

    //Área orientada (S) do polígono, com pontos 2D e o = (0,0)
    float area(std::vector<Vector2f> p);

    //Produto vetorial em 2D
    float cross2d(Vector2f a, Vector2f b);

    //Retorna se o vetor b está à esquerda do vetor a
    bool isLeftTo(Vector2f b, Vector2f a);
}

#endif // PRIMITIVES

