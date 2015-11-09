#ifndef TTRANSFORM_H
#define TTRANSFORM_H
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat spin = 0.0;

#define X .525731112119133606
#define Z .850650808352039932
#define RotateDegree 180.0

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    //glPushMatrix();
    glMatrixMode (GL_MODELVIEW);
    glColor3f(0.5, 1.0, 0.0);
//    glLineStipple(1, 0x0007);
//    glEnable(GL_LINE_STIPPLE);
//    glPolygonMode(GL_FRONT,GL_LINE);

//    glBegin(GL_POLYGON);
//    glVertex3f (-25.0, -25.0, 0.0);
//    glVertex3f (25.0, -25.0, 0.0);
//    glVertex3f (25.0, 25.0, 0.0);
//    glVertex3f (-25.0, 25.0, 0.0);
//    glEnd();
    gluLookAt (10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    glRotatef(90.0 - spin, 0.0, 0.0, 0.0);
    glutWireCube (8.0);
    glRotatef(-80.0 + spin, 0.0, 0.0, 0.0);
    glRotatef(spin, 1.0, 0.0, 0.0);
    //glLoadIdentity ();
    glRotatef(spin, 0.0, 0.0, 0.0);
    glColor3f(0.5, 1.0, 1.0);
    //glScalef (1.0, 1.0, 1.0);      /* modeling transformation */
    glutWireCube (8.0);
    //glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay(void)
{
    spin += 0.01;
    if (spin >= RotateDegree)
    {
        spin = 0;
        //glClear(GL_COLOR_BUFFER_BIT);
    }
    glutPostRedisplay();
}

void init(void)
{
    glClearColor (-0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}

void test_Rotate(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
}


#endif // TROTATE_H
