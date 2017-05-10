#include "algorithms.h"
#include <algorithm>
#include <limits>
#include <iostream>

std::vector<Vector2f> Algorithm::quickhull(std::vector<Vector2f> C) {
    //encontrar como as arestas máximas e mínimas em y
    float maxy = std::numeric_limits<float>::min(), miny = std::numeric_limits<float>::max();
    Vector2f vmaxy, vminy;
    bool foundmin = false, foundmax = false;
    for (Vector2f& v : C) {
        if (v[1] < miny) {
            miny = v[1];
            vminy = v;
            foundmin = true;
        } if (v[1] > maxy) {
            maxy = v[1];
            vmaxy = v;
            foundmax = true;
        }
    }
    if (!foundmin && !foundmax) {
        throw 1;
    }

    //TODO: Dividir C nos pontos à direita e à esquerda da reta
    Vector2f div = vmaxy - vminy;
    std::vector<Vector2f> CL, CR;

    return rec_quickhull(C, vminy, vmaxy);
}

std::vector<Vector2f> Algorithm::rec_quickhull(std::vector<Vector2f> C, Vector2f e, Vector2f d) {
    //Printar a aresta
    std::cout << "[e: " << e.transpose() << " d: " << d.transpose() << "]" << std::endl;

    //Printar o conjunto
    std::cout << "C: [" << std::endl;
    for (Vector2f v : C) {
        std::cout << "\t" << v.transpose() << std::endl;
    }
    std::cout << "] " << std::endl;

    //se C = {e, d} retorne o segmento orientado ed
    if (C.size() == 2/* && C[0] == e &&  C[1] == d*/) {
        return C;
    }
    Vector2f h;
    bool foundh = false;
    float maxSedh = std::numeric_limits<float>::min();
    //encontrar o ponto h tal que Sedh seja máxima
    for (Vector2f v : C) {
        float Sedh = Primitives::area({e,d,h});
        if (Sedh > maxSedh) {
            maxSedh = Sedh;
            h = v;
            foundh = true;
        }
    }
    if (!foundh) {
        //TODO problema?
        throw 1;
    }

    Vector2f eh = h-e;
    Vector2f hd = d-h;
    std::vector<Vector2f> CL = {e, h};
    std::vector<Vector2f> CR = {h, d};
    //encontrar CL o conjunto de pontos de C à esquerda de eh
    //encontrar CR o conjunto de pontos de C à esquerda de hd
    for (Vector2f v : C) {
        if (Primitives::isLeftTo(v, eh)) {
            CL.push_back(v);
        } else if (Primitives::isLeftTo(v, hd)) {
            CR.push_back(v);
        }
    }

    //retornar rec_quickhull(C1, e, h) + rec_quickhull(C2, h, d)
    std::vector<Vector2f> rCL = rec_quickhull(CL, e, h);
    std::vector<Vector2f> rCR = rec_quickhull(CR, h, d);
    //retorna a concatenação dos dois vetores
    rCL.insert(rCL.begin(), rCR.begin(), rCR.end());
    return rCL;
}
