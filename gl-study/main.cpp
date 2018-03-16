#include <glut.h>
#include <iostream>

using namespace std;

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

void keyboard(unsigned char key, int x, int y)
{
  cout << "다음 키가 눌러졌습니다. \"" << key << "\" ASCII: " << (int)key << endl;

  //ESC 키가 눌러졌다면 프로그램 종료
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
  glColor3f(1.0f, 0.0f, 0.0f); //빨간색 지정
  glBegin(GL_TRIANGLES);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();
  glFlush();
}

void changeSize(int w, int h)
{
  //창이 아주 작을 때, 0 으로 나누는 것을 예방합니다.
  if (h == 0)
    h = 1;
  float ratio = 1.0* w / h;

  //좌표계를 수정하기 전에 초기화합니다.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //뷰포트를 창의 전체 크기로 설정합니다.
  glViewport(0, 0, w, h);

  //투시값을 설정합니다.
  gluPerspective(45, ratio, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitWindowSize(500, 500);   //윈도우의 width와 height
  glutInitWindowPosition(100, 100); //윈도우의 위치 (x,y)
  glutCreateWindow("Test");

  glutDisplayFunc(display);
  glutReshapeFunc(changeSize);
  glutKeyboardFunc(keyboard);

  glutMainLoop();
  return 0;
}