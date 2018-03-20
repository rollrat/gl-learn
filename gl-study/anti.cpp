#include <glut.h>

void init()
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0f, 0.0f, 0.0f);
  gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  glColor3f(0.5, 0.5, 1);

  glLineWidth(10);
  glPolygonMode(GL_FRONT, GL_LINE);
  glBegin(GL_POLYGON);
    glVertex2i(100, 200);
    glVertex2i(50, 50);
    glVertex2i(350, 50);
    glVertex2i(250, 250);
  glEnd();

  glDisable(GL_LINE_SMOOTH);

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(400, 200);
  glutInitWindowSize(400, 300);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("OpenGL");

  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}