#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QOpenGLWidget>
#include <vector>

#include "geometry.h"
#include "algorithm"

typedef std::pair<std::vector<std::shared_ptr<Geometry::Vertex2D>>, std::vector<std::shared_ptr<Geometry::Edge2D>>> pointsHullPair;
//TODO PERSPECTIVA!!!!!!!!!!!
class GLWidget : public QOpenGLWidget
{
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();
private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    std::vector<pointsHullPair> pointsHullSet;
};

#endif // GLWIDGET_H
