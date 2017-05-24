#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QOpenGLWidget>
#include <vector>

#include "geometry.h"
#include "algorithms.h"
#include <iostream>

struct VertexGroup {
    std::vector<std::shared_ptr<Geometry::Vertex2D>> vertices;
    std::vector<std::shared_ptr<Geometry::Edge2D>> hull;

    VertexGroup(std::vector<std::shared_ptr<Geometry::Vertex2D>> _vertices) : vertices(_vertices) { }
    VertexGroup(std::vector<std::shared_ptr<Geometry::Vertex2D>> _vertices, std::vector<std::shared_ptr<Geometry::Edge2D>> _hull) : vertices(_vertices), hull(_hull) { }

    void generateHull() {
        //Hull não foi criado ainda
        if (hull.empty()) {
//            std::cout << "called quickhull\n";
            hull = Algorithm::quickhull(vertices);
        }
    }
};

class GLWidget : public QOpenGLWidget
{
public:
    explicit GLWidget(QWidget *parent = 0);
    void openArchive();
    void generateHulls();
    void saveArchive();
    ~GLWidget();
private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    //Encontra as coordenadas extremas e ajusta a perspectiva baseada nisso
    void adjustPerspective();

    std::vector<VertexGroup> pointsHullSet;
};

#endif // GLWIDGET_H
