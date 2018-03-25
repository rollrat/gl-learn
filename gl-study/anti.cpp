#include <glut.h>
#include <math.h>
#include <iostream>

char title[] = "3D Shapes";

void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glutSetCursor(GLUT_CURSOR_NONE);
}

float mouse_x_pin = 0.0, mouse_y_pin = 0.0;

float angle = 0;
float x_eye=0.0, y_eye=0.0, z_eye=0.0;
float x_l=0.0, y_l=0.0, z_l=1.0;
float yaw = 90.0, pitch = 90.0;

void mouse_move(int x, int y)
{
  float x_offset = x - (int)mouse_x_pin;
  float y_offset = y - (int)mouse_y_pin;

  float sensitivity = 0.13f;
  x_offset *= sensitivity;
  y_offset *= sensitivity;

  yaw += x_offset;
  pitch += y_offset;

  if (pitch > 179.9)
    pitch = 179.9;
  if (pitch < 0.1)
    pitch = 0.1;

  float yaw_r = yaw * 3.14159265 / 180.0;
  float pitch_r = pitch * 3.14159265 / 180.0;

  x_l = cos(yaw_r) * sin(pitch_r);
  y_l = cos(pitch_r);
  z_l = sin(yaw_r) * sin(pitch_r);

  glutWarpPointer(mouse_x_pin, mouse_y_pin);
}

bool key_w, key_a, key_s, key_d;
bool key_shift, key_control, key_alt;

void keyboard_down(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 'w': key_w = true; break;
  case 'a': key_a = true; break;
  case 's': key_s = true; break;
  case 'd': key_d = true; break;
  }
}

void keyboard_up(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 'w': key_w = false; break;
  case 'a': key_a = false; break;
  case 's': key_s = false; break;
  case 'd': key_d = false; break;
  }
}

void sca_set()
{
  int mod = glutGetModifiers();
  if (mod & GLUT_ACTIVE_SHIFT)
    key_shift = true;
  else
    key_shift = false;
  if (mod & GLUT_ACTIVE_CTRL)
    key_control = true;
  else
    key_control = false;
}

void timer(int extra)
{
  angle -= 0.01;

  float sensitivity = 0.05;

  if (key_w == true)
  {
    x_eye += x_l * sensitivity;
    z_eye += z_l * sensitivity;
  }
  if (key_s == true)
  {
    x_eye -= x_l * sensitivity;
    z_eye -= z_l * sensitivity;
  }
  if (key_a == true)
  {
    x_eye += z_l * sensitivity;
    z_eye -= x_l * sensitivity;
  }
  if (key_d == true)
  {
    x_eye -= z_l * sensitivity;
    z_eye += x_l * sensitivity;
  }

  if (key_shift == true)
  {
    std::cout << "asdf";
    y_eye += 1.0;
  }
  if (key_control == true)
  {
    std::cout << "asdf";
    y_eye -= 1.0;
  }

  glutPostRedisplay();
  glutTimerFunc(1, timer, 0);
}

void set_camera()
{
  gluLookAt(x_eye, y_eye, z_eye,
      x_l+x_eye, y_l+y_eye, z_l+z_eye,
      0.0, 1.0, 0.0);
}
void setOrthographicProjection()
{
  // 행렬을 투영모드로 변경합니다.
  glMatrixMode(GL_PROJECTION);
  // 원근투영에 대한 환경변수를 
  // 가지고 있는 이전 행렬을 저장합니다.
  glPushMatrix();
  // 행렬을 초기화합니다.
  glLoadIdentity();
  // 2D 직교투영을 설정합니다.
  gluOrtho2D(0, mouse_x_pin*2, 0, mouse_y_pin*2);
  // y 축을 뒤집습니다.
  glScalef(1, -1, 1);
  // 좌측아래의 원점을 
  // 좌측위로 옮깁니다.
  glTranslatef(0, -mouse_y_pin * 2, 0);
  glMatrixMode(GL_MODELVIEW);
}
void resetPerspectiveProjection()
{
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}
void draw_axis()
{

}

void draw_rgbbox()
{
  glBegin(GL_QUADS);

  glColor3f(0.0f, 1.0f, 0.0f);     // Green
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);

  // Bottom face (y = -1.0f)
  glColor3f(1.0f, 0.5f, 0.0f);     // Orange
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);

  // Front face  (z = 1.0f)
  glColor3f(1.0f, 0.0f, 0.0f);     // Red
  glVertex3f(1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);

  // Back face (z = -1.0f)
  glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
  glVertex3f(1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);

  // Left face (x = -1.0f)
  glColor3f(0.0f, 0.0f, 1.0f);     // Blue
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);

  // Right face (x = 1.0f)
  glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glEnd();
}

void draw_floor()
{
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  //glColor3f(0.5, 0.5, 1);
  glLineWidth(1);

  int x_p = 100, z_p = 100;
  for (int i = -100; i < 100; i++)
  {
    glBegin(GL_LINES);
    glVertex3f(i, -1, z_p);
    glVertex3f(i, -1, -z_p);
    glEnd();
  }
  for (int i = -100; i < 100; i++)
  {
    glBegin(GL_LINES);
    glVertex3f(x_p, -1, i);
    glVertex3f(-x_p, -1, i);
    glEnd();
  }
}

void draw_bitmapcharacter(float x, float y, float z, const char *string)
{
  const char *c;
  glRasterPos3f(x, y, z);
  for (c = string; *c != '\0'; c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
  }
}

double aspect;

void display() {

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  set_camera();
  glTranslatef(0.0f, 0.0f, 5.0f);
  glRotatef(angle*10, 1, 1, 1);
  draw_rgbbox();

  glLoadIdentity();
  set_camera();
  glTranslatef(0.0f, 0.0f, 0.0f);
  draw_floor();

  draw_axis();

  setOrthographicProjection();
  glPushMatrix();
  glLoadIdentity();
  draw_bitmapcharacter(10.0, 10.0, 10.0, "rollrat");
  glPopMatrix();
  resetPerspectiveProjection();

  glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
  if (height == 0) height = 1;
  aspect = (GLfloat)width / (GLfloat)height;

  glViewport(0, 0, width, height);

  mouse_x_pin = (float)width / 2;
  mouse_y_pin = (float)height / 2;
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow(title);
  glutDisplayFunc(display);
  glutPassiveMotionFunc(mouse_move);
  glutKeyboardFunc(keyboard_down);
  glutKeyboardUpFunc(keyboard_up);
  glutTimerFunc(0, timer, 0);
  glutReshapeFunc(reshape);
  initGL();
  glutMainLoop();
  return 0;
}