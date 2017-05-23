#ifndef VERTEXPAINTER_H
#define VERTEXPAINTER_H

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include <vector>
#include <iostream>
#include "geometry.h"


/* Classe que faz o desenho do conjunto de pontos
 */
class VertexPainter
{
public:
    VertexPainter();
    void initialize();
    void setPoints(std::vector<std::shared_ptr<Geometry::Vertex2D>> points);
    void setEdges(std::vector<std::shared_ptr<Geometry::Edge2D>> edges);
    void draw();

private:
    std::vector<std::shared_ptr<Geometry::Vertex2D>> points;
    std::vector<std::shared_ptr<Geometry::Edge2D>> edges;

    QOpenGLBuffer vertexBuffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    QOpenGLBuffer elementBuffer = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    QOpenGLVertexArrayObject vao;
    QOpenGLFunctions glFuncs;
};

#endif // VERTEXPAINTER_H
