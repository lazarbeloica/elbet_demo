
#include <string.h>
#include <GL/glui.h>

#include <GL/glut.h>

/** These are the live variables passed into GLUI ***/
int   wireframe = 0;
int segments = 8;
int   main_window;
GLUI_EditText   *edittext;
std::string text = "Hello World!";
std::string msg = "";
GLUI *glui;

void control_cb( int control )
{
  printf( "callback: %d\n", control );
  printf( "text: %s\n", edittext->get_text().c_str() );

}

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
  glutInitWindowPosition( 50, 50 );
  glutInitWindowSize( 600, 300 );

  GLfloat light0_ambient[] =  {0.1f, 0.1f, 0.3f, 1.0f};
  GLfloat light0_diffuse[] =  {.6f, .6f, 1.0f, 1.0f};
  GLfloat light0_position[] = {1.0f, 1.0f, 1.0f, 0.0f};

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

  glEnable(GL_DEPTH_TEST);

  GLUI *glui = GLUI_Master.create_glui( "GLUI" );
  edittext = new GLUI_EditText( glui, "Text:",GLUI_EDITTEXT_INT, &text, 3, control_cb );
  int a, b;
  glui->add_button( "Next", a, control_cb );
  glui->add_button( "Sort", b, control_cb );
  GLUI_EditText *result = new GLUI_EditText( glui, "Text:",GLUI_EDITTEXT_INT, &text, 3, control_cb );
  result->disable();

  glutMainLoop();

  return EXIT_SUCCESS;
}



