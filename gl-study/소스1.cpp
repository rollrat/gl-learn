//#include <glut.h>
//#include <math.h>
//#include <stdlib.h>
//
//static float angle = 0.0, ratio;
//static float x = 0.0f, y = 1.75f, z = 5.0f;
//static float lx = 0.0f, ly = 0.0f, lz = -1.0f;
//static GLint snowman_display_list;
//
//void changeSize(int w, int h)
//{
//  // â�� �ʹ� �۾������� 0 ���� ������ ���� �����մϴ�.
//  if (h == 0)
//    h = 1;
//
//  ratio = 1.0f * w / h;
//  // ��ǥ�踦 �����ϱ� ���� �ʱ�ȭ�մϴ�.
//  glMatrixMode(GL_PROJECTION);
//  glLoadIdentity();
//
//  // ����Ʈ�� â ��üũ��� �����մϴ�. 
//  glViewport(0, 0, w, h);
//
//  // ���� ������ �����մϴ�.
//  gluPerspective(45, ratio, 1, 1000);
//  glMatrixMode(GL_MODELVIEW);
//  glLoadIdentity();
//  gluLookAt(x, y, z,
//    x + lx, y + ly, z + lz,
//    0.0f, 1.0f, 0.0f);
//}
//
//void drawSnowMan()
//{
//  glColor3f(1.0f, 1.0f, 1.0f);
//
//  // ���� �׸��ϴ�.
//  glTranslatef(0.0f, 0.75f, 0.0f);
//  glutSolidSphere(0.75f, 20, 20);
//
//  // �Ӹ��� �׸��ϴ�.
//  glTranslatef(0.0f, 1.0f, 0.0f);
//  glutSolidSphere(0.25f, 20, 20);
//
//  // �� ���� �׸��ϴ�.
//  glPushMatrix();
//  glColor3f(0.0f, 0.0f, 0.0f);
//  glTranslatef(0.05f, 0.10f, 0.18f);
//  glutSolidSphere(0.05f, 10, 10);
//  glTranslatef(-0.1f, 0.0f, 0.0f);
//  glutSolidSphere(0.05f, 10, 10);
//  glPopMatrix();
//
//  // �ڸ� �׸��ϴ�.
//  glColor3f(1.0f, 0.5f, 0.5f);
//  glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
//  glutSolidCone(0.08f, 0.5f, 10, 2);
//}
//
//GLuint createDL()
//{
//  GLuint snowManDL;
//
//  // ���÷��̸���Ʈ�� �����ϰ� id �� ��ȯ�մϴ�.
//  snowManDL = glGenLists(1);
//
//  // ���÷��̸���Ʈ�� �����մϴ�.
//  glNewList(snowManDL, GL_COMPILE);
//
//  // �������� �����ϴ� �Լ��� ȣ���մϴ�.
//  drawSnowMan();
//
//  // ���÷��̸���Ʈ�� ����Ĩ�ϴ�.
//  glEndList();
//
//  return(snowManDL);
//}
//
//void initScene()
//{
//  glEnable(GL_DEPTH_TEST);
//  snowman_display_list = createDL();
//}
//
//void renderScene(void)
//{
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//  // ������ �׸��ϴ�.
//  glColor3f(0.9f, 0.9f, 0.9f);
//  glBegin(GL_QUADS);
//  glVertex3f(-100.0f, 0.0f, -100.0f);
//  glVertex3f(-100.0f, 0.0f, 100.0f);
//  glVertex3f(100.0f, 0.0f, 100.0f);
//  glVertex3f(100.0f, 0.0f, -100.0f);
//  glEnd();
//
//  // 36���� ������� �׸��ϴ�.
//  for (int i = -3; i < 3; i++)
//    for (int j = -3; j < 3; j++)
//    {
//      glPushMatrix();
//      glTranslatef(i*10.0, 0, j * 10.0);
//      glCallList(snowman_display_list);;
//      glPopMatrix();
//    }
//   glDisable(GL_LINE_SMOOTH);
//  glutSwapBuffers();
//}
//
//void moveMeFlat(int direction)
//{
//  x = x + direction * (lx)*0.1;
//  z = z + direction * (lz)*0.1;
//  glLoadIdentity();
//  gluLookAt(x, y, z,
//    x + lx, y + ly, z + lz,
//    0.0f, 1.0f, 0.0f);
//}
//
//void orientMe(float ang)
//{
//  lx = sin(ang);
//  lz = -cos(ang);
//  glLoadIdentity();
//  gluLookAt(x, y, z,
//    x + lx, y + ly, z + lz,
//    0.0f, 1.0f, 0.0f);
//}
//
//void inputKey(int key, int x, int y)
//{
//  switch (key)
//  {
//  case GLUT_KEY_LEFT:
//    angle -= 0.05f;
//    orientMe(angle);
//    break;
//  case GLUT_KEY_RIGHT:
//    angle += 0.05f;
//    orientMe(angle);
//    break;
//  case GLUT_KEY_UP:
//    moveMeFlat(1);
//    break;
//  case GLUT_KEY_DOWN:
//    moveMeFlat(-1);
//    break;
//  }
//}
//
//int main(int argc, char **argv)
//{
//  glutInit(&argc, argv);
//  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//  glutInitWindowPosition(100, 100);
//  glutInitWindowSize(640, 360);
//  glutCreateWindow("SnowMen from 3D-Tech");
//
//  initScene();
//
//  glutSpecialFunc(inputKey);
//  glutDisplayFunc(renderScene);
//  glutIdleFunc(renderScene);
//  glutReshapeFunc(changeSize);
//
//  glutMainLoop();
//
//  return(0);
//}