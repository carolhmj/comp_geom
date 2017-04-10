#include "vector.h"

Vector::Vector(double _values[])
{
    unsigned int nElems = sizeof(_values) / sizeof(double);
    for (int i = 0; i < nElems; i++) {
        valores.push_back(_values[i]);
    }
}

Vector::Vector(std::vector<double> _values) :
    valores(_values)
{

}

unsigned int Vector::dimensao()
{
    return valores.size();
}

double Vector::operator[](int i)
{
    return valores.at(i);
}

double Vector::valorEm(int i)
{
    return valores.at(i);
}

Vector Vector::somavetorial(Vector v)
{
    if (this->dimensao() != v.dimensao()) { throw 0; }
    std::vector<double> sum;

    for (unsigned int i = 0; i < this->dimensao(); i++) {
        sum.push_back(this->valorEm(i) + v.valorEm(i));
    }

    return Vector(sum);
}

Vector Vector::multescalar(double v)
{
    std::vector<double> mult;

    for (unsigned int i = 0; i < this->dimensao(); i++) {
        mult.push_back(this->valorEm(i) * v);
    }

    return Vector(mult);
}

double Vector::prodescalar(Vector v)
{
    if (this->dimensao() != v.dimensao()) { throw 0; }
    double prod;

    for (unsigned int i = 0; i < this->dimensao(); i++) {
        prod += (this->valorEm(i) * v.valorEm(i));
    }

    return prod;
}

double Vector::norma()
{
    return std::sqrt(this->prodescalar(*this));
}

double Vector::distancia(Vector v)
{
    return this->somavetorial(v.multescalar(-1)).norma();
}

double Vector::angulo(Vector v)
{
    return std::acos(this->prodescalar(v) / (this->norma() * v.norma()) );
}

double Vector::angulo()
{
    if (this->dimensao() != 2) { throw 0; }

    std::vector<double> x({1,0});
    Vector eixoX(x);

    if (this->valorEm(0) >= 0) {
        return this->angulo(x);
    } else {
        return -this->angulo(x);
    }
}

Vector Vector::prodvetorial(Vector v)
{
    if (this->dimensao() != 3) { throw 0; }
    std::vector<double> pv;

    pv.push_back(this->valorEm(1)*v.valorEm(2) - this->valorEm(2)*v.valorEm(1));
    pv.push_back(this->valorEm(2)*v.valorEm(0) - this->valorEm(0)*v.valorEm(2));
    pv.push_back(this->valorEm(0)*v.valorEm(1) - this->valorEm(1)*v.valorEm(0));
}

