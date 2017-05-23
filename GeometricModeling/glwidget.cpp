#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent) {
}

GLWidget::~GLWidget() {
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

        std::vector<std::shared_ptr<Geometry::Edge2D>> conv_hull2 = Algorithm::quickhull(pointsVertex);
        std::cout << "CONVEX HULL VERSION 2 ==================================================\n";
        for (std::shared_ptr<Geometry::Edge2D>& v : conv_hull2) {
            std::cout << v->a->pos.transpose() << " --- " << v->b->pos.transpose() << std::endl;
        }

        pointsHullPair p = std::make_pair<pointsHullPair.first_type, pointsHullPair.second_type>(pointsVertex, conv_hull2);

        pointsHullSet.push_back(p);
}

void GLWidget::initializeGL() {
    glClearColor(0.f,0.f,0.f,1.f);
}

void GLWidget::resizeGL(int w, int h) {

}

void GLWidget::paintGL() {
    for (pointsHullPair& ph : pointsHullSet) {
        glBegin(GL_POINTS);
            glColor3f(1,0,0);
            //Desenha os pontos
            for (std::shared_ptr<Geometry::Vertex2D> vertex : ph.first) {
                glVertex2f(vertex->pos[0], vertex->pos[1]);
            }
        glEnd();
        glBegin(GL_LINES);
            glColor3f(0,0,1);
            //Desenha as linhas
            for (std::shared_ptr<Geometry::Edge2D> edge : ph.second) {
                glVertex2f(edge->a->pos[0], edge->a->pos[1]);
                glVertex2f(edge->b->pos[0], edge->b->pos[1]);
            }
        glEnd();
    }

}
