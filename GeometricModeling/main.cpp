#include "mainwindow.h"
#include <QApplication>

#include "algorithms.h"
#include <iostream>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    //Testando quickhull!
    std::vector<Vector2f> points;
    points.push_back(Vector2f(0,8));
    points.push_back(Vector2f(-4,6));
    points.push_back(Vector2f(-5,0));
    points.push_back(Vector2f(-1,1));
    points.push_back(Vector2f(-3,-3));
    points.push_back(Vector2f(0,-4));
    points.push_back(Vector2f(5,-2));
    points.push_back(Vector2f(9,0));
    points.push_back(Vector2f(4,5));
    points.push_back(Vector2f(8,3));

    std::vector<std::shared_ptr<Geometry::Vertex2D>> pointsVertex;
    for (unsigned int i = 0; i < points.size(); i++) {
        pointsVertex.push_back(std::make_shared<Geometry::Vertex2D>(i, points[i]));
    }

    std::vector<Vector2f> conv_hull = Algorithm::quickhull(points);

    std::cout << "CONVEX HULL ==================================================\n";
    for (Vector2f& v : conv_hull) {
        std::cout << v.transpose() << std::endl;
    }

    std::vector<std::shared_ptr<Geometry::Edge2D>> conv_hull2 = Algorithm::quickhull(pointsVertex);
    std::cout << "CONVEX HULL VERSION 2 ==================================================\n";
    for (std::shared_ptr<Geometry::Edge2D>& v : conv_hull2) {
        std::cout << v->a->pos.transpose() << " --- " << v->b->pos.transpose() << std::endl;
    }
}
