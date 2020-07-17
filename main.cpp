#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Cahyo Nugroho - 672018039");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}


void gedung_baris_depan() {
    //gedung tengah
    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 20.0, 0.0);
    glVertex3f(-10.0, 20.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(10.0, 20.0, 10.0);
    glVertex3f(-10.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 20.0, 0.0);
    glVertex3f(10.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-10.0, 20.0, 0.0);
    glVertex3f(-10.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 20.0, 10.0);
    glVertex3f(-10.0, 20.0, 0.0);
    glVertex3f(10.0, 20.0, 0.0);
    glVertex3f(10.0, 20.0, 10.0);
    glEnd();
    //gedung tengah end

    //gedung kiri
    glColor3f(1.0, 0.65, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-35.0, 0.0, 0.0);
    glVertex3f(-35.0, 20.0, 0.0);
    glVertex3f(-10.0, 20.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(-35.0, 0.0, 10.0);
    glVertex3f(-35.0, 20.0, 10.0);
    glVertex3f(-10.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-35.0, 0.0, 0.0);
    glVertex3f(-35.0, 0.0, 10.0);
    glVertex3f(-10.0, 0.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 20.0, 0.0);
    glVertex3f(-35.0, 20.0, 0.0);
    glVertex3f(-35.0, 20.0, 10.0);
    glVertex3f(-10.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-35.0, 0.0, 10.0);
    glVertex3f(-35.0, 0.0, 0.0);
    glVertex3f(-35.0, 20.0, 0.0);
    glVertex3f(-35.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-10.0, 20.0, 0.0);
    glVertex3f(-10.0, 20.0, 10.0);
    glEnd();
    //gedung kiri end

    //gedung kanan
    glColor3f(1.0, 0.1, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(35.0, 0.0, 0.0);
    glVertex3f(35.0, 20.0, 0.0);
    glVertex3f(10.0, 20.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.1, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(35.0, 0.0, 10.0);
    glVertex3f(35.0, 20.0, 10.0);
    glVertex3f(10.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.1, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(35.0, 0.0, 0.0);
    glVertex3f(35.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.1, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 20.0, 0.0);
    glVertex3f(35.0, 20.0, 0.0);
    glVertex3f(35.0, 20.0, 10.0);
    glVertex3f(10.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.1, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(35.0, 0.0, 10.0);
    glVertex3f(35.0, 0.0, 0.0);
    glVertex3f(35.0, 20.0, 0.0);
    glVertex3f(35.0, 20.0, 10.0);
    glEnd();

    glColor3f(1.0, 0.1, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 20.0, 0.0);
    glVertex3f(10.0, 20.0, 10.0);
    glEnd();

}

void gedung_baris_2()
{
    //gedung kiri
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50.0, 23.0, 0.0);
    glVertex3f(-30.0, 23.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, -13.0);
    glVertex3f(-50.0, 0.0, -13.0);
    glVertex3f(-50.0, 23.0, -13.0);
    glVertex3f(-30.0, 23.0, -13.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, 0.0);
    glVertex3f(-30.0, 0.0, -13.0);
    glVertex3f(-30.0, 23.0, -13.0);
    glVertex3f(-30.0, 23.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, -13.0);
    glVertex3f(-50.0, 23.0, -13.0);
    glVertex3f(-50.0, 23.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, -13.0);
    glVertex3f(-30.0, 0.0, -13.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-30.0, 23.0, 0.0);
    glVertex3f(-50.0, 23.0, 0.0);
    glVertex3f(-50.0, 23.0, -13.0);
    glVertex3f(-30.0, 23.0, -13.0);
    glEnd();
    //gedung kiri end

    //gedung kanan
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 23.0, 0.0);
    glVertex3f(30.0, 23.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, -13.0);
    glVertex3f(50.0, 0.0, -13.0);
    glVertex3f(50.0, 23.0, -13.0);
    glVertex3f(30.0, 23.0, -13.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(30.0, 0.0, -13.0);
    glVertex3f(30.0, 23.0, -13.0);
    glVertex3f(30.0, 23.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, -13.0);
    glVertex3f(50.0, 23.0, -13.0);
    glVertex3f(50.0, 23.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, -13.0);
    glVertex3f(30.0, 0.0, -13.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 23.0, 0.0);
    glVertex3f(50.0, 23.0, 0.0);
    glVertex3f(50.0, 23.0, -13.0);
    glVertex3f(30.0, 23.0, -13.0);
    glEnd();
    //gedung kanan end
}

void tampil(void)
{
    glPushMatrix();

    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    gedung_baris_depan();
    gedung_baris_2();

    glPopMatrix();
    glutSwapBuffers();
}


void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case 'i':
    case 'I':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth) {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) {
        tinggi = 1;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
