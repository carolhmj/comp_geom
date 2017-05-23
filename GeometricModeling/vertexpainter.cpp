#include "vertexpainter.h"
#include <QDebug>

VertexPainter::VertexPainter()
{

}

void VertexPainter::initialize()
{
    if (!QOpenGLContext::currentContext()) {
        std::cout << "No current OpenGL context" << std::endl;
        return;
    }
    glFuncs = QOpenGLFunctions(QOpenGLContext::currentContext());

    vao.create();
    vao.bind();

    vertexBuffer.create();
    if (!vertexBuffer.bind()) {
        qDebug() << "Could not bind vertex buffer to context\n";
        return;
    }

    elementBuffer.create();
    if (!elementBuffer.bind()) {
        qDebug() << "Could not bind element buffer to context\n";
        return;
    }

    vertexBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
//    vertexBuffer.allocate(vertices.data(), sizeof(Vertex) * vertices.size());

    elementBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
//    elementBuffer.allocate(indices.data(), sizeof(GLuint) * indices.size());

    glFuncs.glEnableVertexAttribArray(0);
//    glFuncs.glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, sizeof(Vertex),
//                                (GLvoid*)0);
    glFuncs.glEnableVertexAttribArray(1);
//    glFuncs.glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
//                                (GLvoid*)offsetof(Vertex, color));

    vao.release();
}

