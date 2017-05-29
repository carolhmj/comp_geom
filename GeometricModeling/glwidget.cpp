#include "glwidget.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent) {
}

GLWidget::~GLWidget() {
}

void GLWidget::initializeGL() {
    glClearColor(0.f,0.f,0.f,1.f);
    glPointSize(3);
    adjustPerspective();
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0,0,w,h);
}

void GLWidget::paintGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    adjustPerspective();
    for (VertexGroup& ph : pointsHullSet) {
        glBegin(GL_POINTS);
            glColor3f(1.0f,0.0f,0.0f);
            //Desenha os pontos
            for (std::shared_ptr<Geometry::Vertex2D> vertex : ph.vertices) {
                glVertex2f(vertex->pos[0], vertex->pos[1]);
            }
        glEnd();
        glBegin(GL_LINES);
            glColor3f(0.0f,0.0f,1.0f);
            //Desenha as linhas
            for (std::shared_ptr<Geometry::Edge2D> edge : ph.hull) {
                glVertex2f(edge->a->pos[0], edge->a->pos[1]);
                glVertex2f(edge->b->pos[0], edge->b->pos[1]);
            }
        glEnd();
    }
}

void GLWidget::adjustPerspective()
{
    //Itera nas coordenadas de todos os pontos
    float maxX = std::numeric_limits<float>::min(),
          maxY = std::numeric_limits<float>::min(),
          minX = std::numeric_limits<float>::max(),
          minY = std::numeric_limits<float>::max();

    for (VertexGroup& ph : pointsHullSet) {
        for (std::shared_ptr<Geometry::Vertex2D> vertex : ph.vertices) {
            Vector2f pos = vertex->pos;
            if (pos[0] >= maxX) {
                maxX = pos[0];
            } else if (pos[0] <= minX) {
                minX = pos[0];
            }
            if (pos[1] >= maxY) {
                maxY = pos[1];
            } else if (pos[1] <= minY) {
                minY = pos[1];
            }
        }
    }
    float xDiff = maxX - minX;
    float yDiff = maxY - minY;
//    std::cout << "minX " << minX << " maxX " << maxX << " minY " << minY << " maxY " << maxY << "\n";
    //Ajusta a perspectiva de acordo com os pontos máximos encontrados
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(minX - xDiff/10.0f, maxX + xDiff/10.0f, minY - yDiff/10.0f, maxY + yDiff/10.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::openArchive()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Model File"), "/home", tr(""));

    std::cout << "opening file: " << fileName.toStdString() << "\n";

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    pointsHullSet.clear();

    QTextStream in(&file);

    int numGroups = in.readLine().toInt();

    try {

        //Lê cada grupo
        for (int i = 0; i < numGroups; i++) {
            int numPoints = in.readLine().toInt();
            std::vector<std::shared_ptr<Geometry::Vertex2D>> pointsVertex;
            for (int j = 0; j < numPoints; j++) {
                float id, x, y, z;
                QString point = in.readLine();
                QStringList info = point.split(" ");
                id = info[0].toInt();
                x = info[1].toFloat();
                y = info[2].toFloat();
                z = info[3].toFloat();
    //            std::cout << "Read vertex " << id << ": " << x << " " << y << " " << z << "\n";
                std::flush(std::cout);
                pointsVertex.push_back(std::make_shared<Geometry::Vertex2D>(id, Vector2f(x,y)));
            }
            pointsHullSet.push_back(pointsVertex);
        }

    } catch (exception& e) {
        std::cout << "Erro na leitura de arquivo!\n";
    }

    file.close();
    update();
}

void GLWidget::generateHulls()
{
    for (VertexGroup& vg : pointsHullSet) {
        vg.generateHull();
    }

    update();
}

void GLWidget::saveArchive()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Model File"), "/home", tr(""));

//    std::cout << "saving file: " << fileName.toStdString() << "\n";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);

    out << pointsHullSet.size() << endl;

    for (VertexGroup& vg : pointsHullSet) {
        auto hull = vg.hull;
        out << hull.size() << endl;

        for (std::shared_ptr<Geometry::Edge2D>& edge : hull) {
            out << edge->a->id << " " << edge->b->id << endl;
        }
    }

    file.close();
}
