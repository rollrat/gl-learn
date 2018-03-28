
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "common\shader.hpp"

using namespace glm;

int main() {
  // GLFW �ʱ�ȭ
  if (!glfwInit())
  {
    fprintf(stderr, "GLFW �ʱ�ȭ ����\n");
    return -1;
  }
  glfwWindowHint(GLFW_SAMPLES, 4); // 4x ��Ƽ���ϸ����
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3 �� �� �̴ϴ�
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS �� ��� ������; �� �ʿ��� �κ��� �ƴ�
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //���� OpenGL�� ������ �ʾƿ�

                                                                 // ��â�� ����, OpenGL ���ؽ�Ʈ�� ����
  GLFWwindow* window; // (�ļ��Ǵ� �ڵ带 ����, �� ������ ����(Global)�Դϴ�.)
  window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
  if (window == NULL) {
    fprintf(stderr, "GLFW �����츦 ���µ� �����߽��ϴ�. Intel GPU �� ����Ѵٸ�, 3.3 ������ ���� �ʽ��ϴ�. 2.1 ������ Ʃ�丮���� �õ��ϼ���.\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window); // GLEW �ʱ�ȭ
  glewExperimental = true; // �ھ� ���������� ���� �ʿ���
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  // �ؿ��� Escape Ű�� �������� ���� ������ �� �ֵ��� �� ��
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  do {
    // �ƹ��͵� �׸��� �ʽ��ϴ�. �ι�° Ʃ�丮�󿡼� �������� ����!

    // ���۵��� ��ü
    glfwSwapBuffers(window);
    glfwPollEvents();

  } // ���� ESC Ű�� ���������� Ȥ�� â�� �������� üũ üũ
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0);
}

