#include <glut.h>
#include <iostream>

using namespace std;

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

void keyboard(unsigned char key, int x, int y)
{
  cout << "���� Ű�� ���������ϴ�. \"" << key << "\" ASCII: " << (int)key << endl;

  //ESC Ű�� �������ٸ� ���α׷� ����
  if (key == 27)
  {
    exit(0);
  }
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  /*glBegin(GL_POLYGON);

  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(-0.5, 0.5, 0.0);

  glEnd();*/
  glColor3f(1.0f, 0.0f, 0.0f); //������ ����
  glBegin(GL_TRIANGLES);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();
  glFlush();
}

void changeSize(int w, int h)
{
  //â�� ���� ���� ��, 0 ���� ������ ���� �����մϴ�.
  if (h == 0)
    h = 1;
  float ratio = 1.0* w / h;

  //��ǥ�踦 �����ϱ� ���� �ʱ�ȭ�մϴ�.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //����Ʈ�� â�� ��ü ũ��� �����մϴ�.
  glViewport(0, 0, w, h);

  //���ð��� �����մϴ�.
  gluPerspective(45, ratio, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitWindowSize(500, 500);   //�������� width�� height
  glutInitWindowPosition(100, 100); //�������� ��ġ (x,y)
  glutCreateWindow("Test");

  glutDisplayFunc(display);
  glutReshapeFunc(changeSize);
  glutKeyboardFunc(keyboard);

  glutMainLoop();
  return 0;
}