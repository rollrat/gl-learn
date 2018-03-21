//#include <glut.h>
//#include <stdio.h>
//
//using namespace std;
//
//GLint winWidth = 400, winHeight = 400;
//
//GLfloat x0 = 15.0, y0 = 80.0, z0 = 100.0;
//GLfloat xref = 0.0, yref = 0.0, zref = 0.0;
//GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;
//
//GLfloat xwMin = -100.0, ywMin = -100.0, xwMax = 100.0, ywMax = 100.0;
//GLfloat dnear = 20.0, dfar = 300.0;
//
//void init()
//{
//  glClearColor(1.0, 1.0, 1.0, 0.0);
//
//  glMatrixMode(GL_MODELVIEW);
//  gluLookAt(x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
//  
//  glMatrixMode(GL_PROJECTION);
//  glOrtho(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
//}
//
//float angle = 0.f;
//
//void display()
//{
//  glClear(GL_COLOR_BUFFER_BIT);
//
//  glEnable(GL_BLEND);
//  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//  glEnable(GL_LINE_SMOOTH);
//  glColor3f(0.5, 0.5, 1);
//
//  glMatrixMode(GL_PROJECTION);
//  glLoadIdentity();
//  glOrtho(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
//
//  glRotatef(angle, 0, 1, 0);
//
//  glLineWidth(5);
//  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//  glBegin(GL_QUADS);
//    glVertex3f(-50.0, -50.0, -50.0);
//    glVertex3f(-50.0, 50.0, -50.0);
//    glVertex3f(50.0, 50.0, -50.0);
//    glVertex3f(50.0, -50.0, -50.0);
//
//    glVertex3f(-50.0, -50.0, 50.0);
//    glVertex3f(50.0, -50.0, 50.0);
//    glVertex3f(50.0, 50.0, 50.0);
//    glVertex3f(-50.0, 50.0, 50.0);
//
//    glVertex3f(-50.0, -50.0, -50.0);
//    glVertex3f(-50.0, -50.0, 50.0);
//    glVertex3f(-50.0, 50.0, 50.0);
//    glVertex3f(-50.0, 50.0, -50.0);
//
//    glVertex3f(50.0, -50.0, -50.0);
//    glVertex3f(50.0, 50.0, -50.0);
//    glVertex3f(50.0, 50.0, 50.0);
//    glVertex3f(50.0, -50.0, 50.0);
//    //////
//    //glVertex3f(-50.0, -50.0, -50.0);
//    //glVertex3f(50.0, -50.0, -50.0);
//    //glVertex3f(50.0, -50.0, 50.0);
//    //glVertex3f(-50.0, -50.0, 50.0);
//    //
//    //glVertex3f(-50.0, 50.0, -50.0);
//    //glVertex3f(-50.0, 50.0, 50.0);
//    //glVertex3f(50.0, 50.0, 50.0);
//    //glVertex3f(50.0, 50.0, -50.0);
//
//  glEnd();
//
//  glDisable(GL_LINE_SMOOTH);
//  glFlush();
//}
//
//bool token = true;
//void timer(int extra)
//{
//  angle += 0.5;
//  /*if (token)
//    dnear -= 1.0;
//  else
//    dnear += 1.0;
//
//  if (dnear < 50.0 && token )
//  { token = false; }
//  else if (dnear > 200.0 && !token)
//  { token = true; }
//  printf("%lf\n", dnear);*/
//
//  glutPostRedisplay();
//  glutTimerFunc(20, timer, 0);
//}
//
//int main(int argc, char** argv) {
//  glutInit(&argc, argv);
//  glutInitWindowPosition(400, 200);
//  glutInitWindowSize(winWidth, winHeight);
//  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//  glutTimerFunc(0, timer, 0);
//  glutCreateWindow("OpenGL");
//
//  init();
//  glutDisplayFunc(display);
//  glutMainLoop();
//  return 0;
//}