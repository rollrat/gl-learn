#include <glut.h>
#include <math.h>
#include <iostream>

/* Global variables */
char title[] = "3D Shapes";

/* Initialize OpenGL Graphics */
void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
  glClearDepth(1.0f);                   // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
  glShadeModel(GL_SMOOTH);   // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

float angle = 0;
float x_l=0.0, y_l=0.0, z_l=1.0;
float yaw = 0.0, pitch = 0.0;

int x_last = 0, y_last = 0;
//void camera(int x, int y)
//{
//  float x_offset = x - x_last;
//  float y_offset = y - y_last;
//  x_last = x;
//  y_last = y;
//
//  float sensitivity = 0.5f;
//  x_offset *= sensitivity;
//  y_offset *= sensitivity;
//
//  yaw += x_offset;
//  pitch += y_offset;
//
//  if (pitch > 89.0)
//    pitch = 89.0;
//  if (pitch < -89.0)
//    pitch = -89.0;
//
//  std::cout << yaw << "," << pitch << std::endl;
//
//  float yaw_r = yaw * 3.14159265 / 180.0;
//  float pitch_r = pitch * 3.14159265 / 180.0;
//
//  x_l = cos(yaw_r) * sin(pitch_r);
//  y_l = sin(pitch_r);
//  z_l = sin(yaw_r) * sin(pitch_r);
//
//  std::cout << x_l << "," << y_l <<"," << z_l<< std::endl;
//}

void timer(int extra)
{
  // spin
  angle -= 0.05;

  x_l = cos(angle);
  z_l = sin(angle);

  glutPostRedisplay();
  glutTimerFunc(16, timer, 0);
}

void set_camera()
{
  /*gluLookAt(0.0, 0.0, 0.0,
    x_l, y_l, z_l,
    0.0, 1.0, 0.0);*/
  gluLookAt(0.0, 0.0, 0.0,
      x_l, 0.0, z_l,
      0.0, 1.0, 0.0);
}

double aspect;

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

  glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
                                  // Render a color-cube consisting of 6 quads with different colors
  glLoadIdentity();                 // Reset the model-view matrix
  set_camera();
  glTranslatef(0.0f, 0.0f, 5.0f);  // Move right and into the screen
  //glRotatef(angle, 1, 1, 1);

  glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
                                    // Top face (y = 1.0f)
                                    // Define vertices in counter-clockwise (CCW) order with normal pointing out
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
  glEnd();  // End of drawing color-cube

            // Render a pyramid consists of 4 triangles
  //glLoadIdentity();                  // Reset the model-view matrix
  //set_camera();
  //glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen
  //glRotatef(-angle, 1, 1, 1);

  //glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
  //                                 // Front
  //glColor3f(1.0f, 0.0f, 0.0f);     // Red
  //glVertex3f(0.0f, 1.0f, 0.0f);
  //glColor3f(0.0f, 1.0f, 0.0f);     // Green
  //glVertex3f(-1.0f, -1.0f, 1.0f);
  //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
  //glVertex3f(1.0f, -1.0f, 1.0f);

  //// Right
  //glColor3f(1.0f, 0.0f, 0.0f);     // Red
  //glVertex3f(0.0f, 1.0f, 0.0f);
  //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
  //glVertex3f(1.0f, -1.0f, 1.0f);
  //glColor3f(0.0f, 1.0f, 0.0f);     // Green
  //glVertex3f(1.0f, -1.0f, -1.0f);

  //// Back
  //glColor3f(1.0f, 0.0f, 0.0f);     // Red
  //glVertex3f(0.0f, 1.0f, 0.0f);
  //glColor3f(0.0f, 1.0f, 0.0f);     // Green
  //glVertex3f(1.0f, -1.0f, -1.0f);
  //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
  //glVertex3f(-1.0f, -1.0f, -1.0f);

  //// Left
  //glColor3f(1.0f, 0.0f, 0.0f);       // Red
  //glVertex3f(0.0f, 1.0f, 0.0f);
  //glColor3f(0.0f, 0.0f, 1.0f);       // Blue
  //glVertex3f(-1.0f, -1.0f, -1.0f);
  //glColor3f(0.0f, 1.0f, 0.0f);       // Green
  //glVertex3f(-1.0f, -1.0f, 1.0f);
  //glEnd();   // Done drawing the pyramid

  glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
                                               // Compute aspect ratio of the new window
  if (height == 0) height = 1;                // To prevent divide by 0
  aspect = (GLfloat)width / (GLfloat)height;

  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);

  // Set the aspect ratio of the clipping volume to match the viewport
  //glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
  //glLoadIdentity();             // Reset
  //                              // Enable perspective projection with fovy, aspect, zNear and zFar
  //gluPerspective(45.0f, aspect, 0.1f, 100.0f);
  //
  ////glMatrixMode(GL_MODELVIEW);
  ////glLoadIdentity();
  ////gluLookAt(10.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  //gluLookAt(0.0, 0.0, 0.0,
  //  0.0, 0.0, 1.0,
  //  0.0, 1.0, 0.0);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
  glutInit(&argc, argv);            // Initialize GLUT
  glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
  glutInitWindowSize(640, 480);   // Set the window's initial width & height
  glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
  glutCreateWindow(title);          // Create window with the given title
  glutDisplayFunc(display);       // Register callback handler for window re-paint event
  //glutPassiveMotionFunc(camera);
  glutTimerFunc(0, timer, 0);
  glutReshapeFunc(reshape);       // Register callback handler for window re-size event
  initGL();                       // Our own OpenGL initialization
  glutMainLoop();                 // Enter the infinite event-processing loop
  return 0;
}