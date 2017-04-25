#include "algorithms.h"

std::vector<Vector2f> Algorithm::quickhull(std::vector<Vector2f> C) {
    //TODO encontrar a primeira aresta
    //TODO chamar o quickhull recursivo
}

std::vector<Vector2f> Algorithm::rec_quickhull(std::vector<Vector2f> C, Vector2f e, Vector2f d) {
    //TODO se C = {e, d} retorne o segmento orientado ed
    Vector2f h;
    bool foundh = false;
    float maxSedh = 0.0;
    //TODO encontrar o ponto h tal que Sedh seja máxima
    for (Vector2f& v : C) {
        float Sedh = Primitives::area({e,d,h});
        if (Sedh > maxSedh) {
            maxSedh = Sedh;
            h = v;
            foundh = true;
        }
    }
    if (!foundh) {
        //TODO problema?
    }

    //TODO encontrar C1 o conjunto de pontos de C à esquerda de eh
    //TODO encontrar C2 o conjunto de pontos de C à esquerda de hd
    //TODO retornar rec_quickhull(C1, e, h) + rec_quickhull(C2, h, d)
}
