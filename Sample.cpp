//#include <windows.h>
#include <GL/glut.h>
using namespace std;
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glFlush();
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(600, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Hello OpenGL");
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}