#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cmath>

//Classe que representa um vetor no R^n
class Vector
{
public:
    Vector(double _values[]);
    Vector(std::vector<double> _values);
    unsigned int dimensao();
    double operator[](int i);
    double valorEm(int i);
    Vector somavetorial(Vector v);
    Vector multescalar(double v);
    double prodescalar(Vector v);
    double norma();
    double distancia(Vector v);
    double angulo(Vector v);
    double angulo(); //Ângulo orientado
    Vector prodvetorial(Vector v); //Só definido se a dimensão dos dois vetores é 3

private:
    std::vector<double> valores;
};

#endif // VECTOR_H
