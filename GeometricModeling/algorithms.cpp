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

    for (Vector2f& v : C) {
        if (v != vminy && v != vmaxy) {
            if (Primitives::isLeftTo(v-vminy, div)) {
                CL.push_back(v);
            } else if (Primitives::isLeftTo(v-vmaxy, -div)) {
                CR.push_back(v);
            }
        }
    }

    std::vector<Vector2f> rCL = rec_quickhull(CL, vminy, vmaxy);
    std::vector<Vector2f> rCR = rec_quickhull(CR, vmaxy, vminy);
    //retorna a concatenação dos dois vetores
    rCL.insert(rCL.begin(), rCR.begin(), rCR.end());
    return rCL;
}

std::vector<Vector2f> Algorithm::rec_quickhull(std::vector<Vector2f> C, Vector2f e, Vector2f d) {
    //Printar a aresta
    std::cout << "[e: " << e.transpose() << " d: " << d.transpose() << "]" << std::endl;

    //Printar o conjunto
    std::cout << "C: [" << std::endl;
    for (Vector2f& v : C) {
        std::cout << "\t" << v.transpose() << std::endl;
    }
    std::cout << "] " << std::endl;

    //se C = { } retorne o segmento orientado ed
    if (C.size() == 0) {
        return {e, d};
    }
    Vector2f h, maxh;
    bool foundh = false;
    float maxSedh = std::numeric_limits<float>::min();
    //encontrar o ponto h tal que Sedh seja máxima
    for (Vector2f& v : C) {
        h = v;
        float Sedh = Primitives::area({e,d,h});
        std::cout << "v: " << v.transpose() << " Sedh: " << Sedh << "\n";
        if (Sedh > maxSedh) {
            maxSedh = Sedh;
            maxh = h;
            foundh = true;
        }
    }
    if (!foundh) {
        //TODO problema?
        throw 1;
    }

    h = maxh;

    Vector2f eh = h-e;
    Vector2f hd = d-h;
    std::vector<Vector2f> CL;
    std::vector<Vector2f> CR;
    //encontrar CL o conjunto de pontos de C à esquerda de eh
    //encontrar CR o conjunto de pontos de C à esquerda de hd
    for (Vector2f& v : C) {
        if (v != h) {
            std::cout << "orientation of " << v.transpose() << "\n";
            if (Primitives::isLeftTo(v-e, eh)) {
                std::cout << "is left to " << eh.transpose() << "\n";
                CL.push_back(v);
            } else if (Primitives::isLeftTo(v-h, hd)) {
                std::cout << "is left to " << hd.transpose() << "\n";
                CR.push_back(v);
            }
        }
    }

    //retornar rec_quickhull(C1, e, h) + rec_quickhull(C2, h, d)
    std::vector<Vector2f> rCL = rec_quickhull(CL, e, h);
    std::vector<Vector2f> rCR = rec_quickhull(CR, h, d);
    //retorna a concatenação dos dois vetores
    rCL.insert(rCL.begin(), rCR.begin(), rCR.end());
    return rCL;
}


std::vector<std::shared_ptr<Geometry::Edge2D> > Algorithm::quickhull(std::vector<std::shared_ptr<Geometry::Vertex2D>> C)
{
    //encontrar como as arestas máximas e mínimas em y
    float maxy = std::numeric_limits<float>::min(), miny = std::numeric_limits<float>::max();
    std::shared_ptr<Geometry::Vertex2D> vmaxy, vminy;
    bool foundmin = false, foundmax = false;
    for (std::shared_ptr<Geometry::Vertex2D>& v : C) {
        if (v->pos[1] < miny) {
            miny = v->pos[1];
            vminy = v;
            foundmin = true;
        } if (v->pos[1] > maxy) {
            maxy = v->pos[1];
            vmaxy = v;
            foundmax = true;
        }
    }
    if (!foundmin && !foundmax) {
        throw 1;
    }

    //TODO: Dividir C nos pontos à direita e à esquerda da reta
    Vector2f div = vmaxy->pos - vminy->pos;
    std::vector<std::shared_ptr<Geometry::Vertex2D>> CL, CR;

    for (std::shared_ptr<Geometry::Vertex2D>& v : C) {
        if (v->pos != vminy->pos && v->pos != vmaxy->pos) {
            if (Primitives::isLeftTo(v->pos-vminy->pos, div)) {
                CL.push_back(v);
            } else if (Primitives::isLeftTo(v->pos-vmaxy->pos, -div)) {
                CR.push_back(v);
            }
        }
    }

    std::vector<std::shared_ptr<Geometry::Edge2D>> rCL = rec_quickhull(CL, vminy, vmaxy);
    std::vector<std::shared_ptr<Geometry::Edge2D>> rCR = rec_quickhull(CR, vmaxy, vminy);
    //retorna a concatenação dos dois vetores
    rCL.insert(rCL.begin(), rCR.begin(), rCR.end());
    return rCL;
}


std::vector<std::shared_ptr<Geometry::Edge2D>> Algorithm::rec_quickhull(std::vector<std::shared_ptr<Geometry::Vertex2D>> C, std::shared_ptr<Geometry::Vertex2D> e, std::shared_ptr<Geometry::Vertex2D> d)
{
    //Printar a aresta
    std::cout << "[e: " << e->pos.transpose() << " d: " << d->pos.transpose() << "]" << std::endl;

    //Printar o conjunto
    std::cout << "C: [" << std::endl;
    for (std::shared_ptr<Geometry::Vertex2D>& v : C) {
        std::cout << "\t" << v->pos.transpose() << std::endl;
    }
    std::cout << "] " << std::endl;

    //se C = { } retorne o segmento orientado ed
    if (C.size() == 0) {
        return {std::make_shared<Geometry::Edge2D>(e, d)};
    }
    std::shared_ptr<Geometry::Vertex2D> h, maxh;
    bool foundh = false;
    float maxSedh = std::numeric_limits<float>::min();
    //encontrar o ponto h tal que Sedh seja máxima
    for (std::shared_ptr<Geometry::Vertex2D>& v : C) {
        h = v;
        float Sedh = Primitives::area({e->pos,d->pos,h->pos});
        std::cout << "v: " << v->pos.transpose() << " Sedh: " << Sedh << "\n";
        if (Sedh > maxSedh) {
            maxSedh = Sedh;
            maxh = h;
            foundh = true;
        }
    }
    if (!foundh) {
        //TODO problema?
        throw 1;
    }

    h = maxh;

    Vector2f eh = h->pos-e->pos;
    Vector2f hd = d->pos-h->pos;
    std::vector<std::shared_ptr<Geometry::Vertex2D>> CL;
    std::vector<std::shared_ptr<Geometry::Vertex2D>> CR;
    //encontrar CL o conjunto de pontos de C à esquerda de eh
    //encontrar CR o conjunto de pontos de C à esquerda de hd
    for (std::shared_ptr<Geometry::Vertex2D>& v : C) {
        if (v->pos != h->pos) {
            std::cout << "orientation of " << v->pos.transpose() << "\n";
            if (Primitives::isLeftTo(v->pos-e->pos, eh)) {
                std::cout << "is left to " << eh.transpose() << "\n";
                CL.push_back(v);
            } else if (Primitives::isLeftTo(v->pos-h->pos, hd)) {
                std::cout << "is left to " << hd.transpose() << "\n";
                CR.push_back(v);
            }
        }
    }

    //retornar rec_quickhull(C1, e, h) + rec_quickhull(C2, h, d)
    std::vector<std::shared_ptr<Geometry::Edge2D>> rCL = rec_quickhull(CL, e, h);
    std::vector<std::shared_ptr<Geometry::Edge2D>> rCR = rec_quickhull(CR, h, d);
    //retorna a concatenação dos dois vetores
    rCL.insert(rCL.begin(), rCR.begin(), rCR.end());
    return rCL;
}
