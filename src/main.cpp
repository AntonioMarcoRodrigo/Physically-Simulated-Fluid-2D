
#include <iostream>
#include <GL/glut.h>

#include "scene.h"

// Scene class containing all stuff
Scene gScene;

// Idle function
void idlefunc( void )
{
    gScene.update();

    glutPostRedisplay();
}

// Keyboard function
void keyboardfunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 27: // ESC
        exit( 0 ); break;
    case 's':
        gScene.pause(); break;
    case 'p':
        // draw pressure
    default:
      break;
    }
}

// Display function
void displayfunc( void )
{
    glClear( GL_COLOR_BUFFER_BIT );

    gScene.display();

    glutSwapBuffers();
}

void init( void )
{
    // Setup the projection matrix.
    glMatrixMode( GL_PROJECTION );
    gluPerspective( 45.0, 1.0, 1.0, 10.0);

    // Setup the view and world matrix.
    glMatrixMode( GL_MODELVIEW );
    gluLookAt( 0.0, 0.0, 5.0,
             0.0, 0.0, 0.0,
             0.0, 1.0, 0.0 );
}

// Main program
int main( int argc, char* argv[] )
{
    glutInit( &argc, argv );
    glutInitWindowSize( 600, 600 );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutCreateWindow( "Basic fluid simulator" );

    glutIdleFunc( idlefunc );
    glutKeyboardFunc( keyboardfunc );
    glutDisplayFunc( displayfunc );

    init();
    gScene.init( argc, argv );

    glutMainLoop();

    return 0;
}
