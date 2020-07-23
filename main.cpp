#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14

float d=40, b=40, px1, py1, mab, mcd, cab, ccd;
int st=1;

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/30,timer,0);
    switch(st)
    {
    case 1:
        if(d<45){
            d+=0.15;
            b-=0.15;
        }
        else
            st=-1;
        break;
    case -1:
        if(d>35){
            d-=0.15;
            b+=0.15;
        }
        else
            st=1;
        break;
    }
}
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

void init(void){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    //transparansi
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //end
	glPointSize(7);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, 800, 600);
    glPointSize(9.0);
    glLineWidth(6.0);

}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("TR GRAFKOM - 672018039 672018054");
    init();
    glutDisplayFunc(tampil);
    glutTimerFunc(0,timer,0);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void gedung_baris_depan(){
    //gedung tengah
    glColor3f(0.98, 0.922, 0.843);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, -5.0);
    glVertex3f(10.0, 0.0, -5.0);
    glVertex3f(10.0, 30.0, -5.0);
    glVertex3f(-10.0, 30.0, -5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 5.0);
    glVertex3f(10.0, 0.0, 5.0);
    glVertex3f(10.0, 30.0, 5.0);
    glVertex3f(-10.0, 30.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 5.0);
    glVertex3f(10.0, 0.0, -5.0);
    glVertex3f(10.0, 30.0, -5.0);
    glVertex3f(10.0, 30.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 5.0);
    glVertex3f(-10.0, 0.0, -5.0);
    glVertex3f(-10.0, 30.0, -5.0);
    glVertex3f(-10.0, 30.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 5.0);
    glVertex3f(-10.0, 0.0, -5.0);
    glVertex3f(10.0, 0.0, -5.0);
    glVertex3f(10.0, 0.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 30.0, 5.0);
    glVertex3f(-10.0, 30.0, -5.0);
    glVertex3f(10.0, 30.0, -5.0);
    glVertex3f(10.0, 30.0, 5.0);
    glEnd();
    //gedung tengah end

    //gedung kiri
    glColor3f(0.98, 0.922, 0.843);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-35.0, 0.0, 0.0);
    glVertex3f(-35.0, 30.0, 0.0);
    glVertex3f(-10.0, 30.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(-35.0, 0.0, 10.0);
    glVertex3f(-35.0, 30.0, 10.0);
    glVertex3f(-10.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-35.0, 0.0, 0.0);
    glVertex3f(-35.0, 0.0, 10.0);
    glVertex3f(-10.0, 0.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 30.0, 0.0);
    glVertex3f(-35.0, 30.0, 0.0);
    glVertex3f(-35.0, 30.0, 10.0);
    glVertex3f(-10.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-35.0, 0.0, 10.0);
    glVertex3f(-35.0, 0.0, 0.0);
    glVertex3f(-35.0, 30.0, 0.0);
    glVertex3f(-35.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-10.0, 30.0, 0.0);
    glVertex3f(-10.0, 30.0, 10.0);
    glEnd();
    //gedung kiri end

    //gedung kanan
    glColor3f(0.98, 0.922, 0.843);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(35.0, 0.0, 0.0);
    glVertex3f(35.0, 30.0, 0.0);
    glVertex3f(10.0, 30.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(35.0, 0.0, 10.0);
    glVertex3f(35.0, 30.0, 10.0);
    glVertex3f(10.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(35.0, 0.0, 0.0);
    glVertex3f(35.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 30.0, 0.0);
    glVertex3f(35.0, 30.0, 0.0);
    glVertex3f(35.0, 30.0, 10.0);
    glVertex3f(10.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(35.0, 0.0, 10.0);
    glVertex3f(35.0, 0.0, 0.0);
    glVertex3f(35.0, 30.0, 0.0);
    glVertex3f(35.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 30.0, 0.0);
    glVertex3f(10.0, 30.0, 10.0);
    glEnd();

}

void gedung_baris_2(){
    //gedung kiri
    glColor3f(0.98, 0.922, 0.843);
    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50.0, 33.0, 0.0);
    glVertex3f(-30.0, 33.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, -13.0);
    glVertex3f(-50.0, 0.0, -13.0);
    glVertex3f(-50.0, 33.0, -13.0);
    glVertex3f(-30.0, 33.0, -13.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, 0.0);
    glVertex3f(-30.0, 0.0, -13.0);
    glVertex3f(-30.0, 33.0, -13.0);
    glVertex3f(-30.0, 33.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, -13.0);
    glVertex3f(-50.0, 33.0, -13.0);
    glVertex3f(-50.0, 33.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50.0, 0.0, -13.0);
    glVertex3f(-30.0, 0.0, -13.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 33.0, 0.0);
    glVertex3f(-50.0, 33.0, 0.0);
    glVertex3f(-50.0, 33.0, -13.0);
    glVertex3f(-30.0, 33.0, -13.0);
    glEnd();
    //gedung kiri end

    //gedung kanan
    glColor3f(0.98, 0.922, 0.843);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 33.0, 0.0);
    glVertex3f(30.0, 33.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, -13.0);
    glVertex3f(50.0, 0.0, -13.0);
    glVertex3f(50.0, 33.0, -13.0);
    glVertex3f(30.0, 33.0, -13.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(30.0, 0.0, -13.0);
    glVertex3f(30.0, 33.0, -13.0);
    glVertex3f(30.0, 33.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, -13.0);
    glVertex3f(50.0, 33.0, -13.0);
    glVertex3f(50.0, 33.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, -13.0);
    glVertex3f(30.0, 0.0, -13.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0, 33.0, 0.0);
    glVertex3f(50.0, 33.0, 0.0);
    glVertex3f(50.0, 33.0, -13.0);
    glVertex3f(30.0, 33.0, -13.0);
    glEnd();
    //gedung kanan end
}

void gedung_setelah_depan(){

    //gedung tengah
    glColor3f(1.0, 0.98, 0.94);
    glBegin(GL_QUADS);
    glVertex3f(-6.0, 0.0, -25.0);
    glVertex3f(6.0, 0.0, -25.0);
    glVertex3f(6.0, 60.0, -25.0);
    glVertex3f(-6.0, 60.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-6.0, 0.0, -15.0);
    glVertex3f(6.0, 0.0, -15.0);
    glVertex3f(6.0, 60.0, -15.0);
    glVertex3f(-6.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(6.0, 0.0, -15.0);
    glVertex3f(6.0, 0.0, -25.0);
    glVertex3f(6.0, 60.0, -25.0);
    glVertex3f(6.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-6.0, 0.0, -15.0);
    glVertex3f(-6.0, 0.0, -25.0);
    glVertex3f(-6.0, 60.0, -25.0);
    glVertex3f(-6.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-6.0, 0.0, -15.0);
    glVertex3f(-6.0, 0.0, -25.0);
    glVertex3f(6.0, 0.0, -25.0);
    glVertex3f(6.0, 0.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-6.0, 60.0, -15.0);
    glVertex3f(-6.0, 60.0, -25.0);
    glVertex3f(6.0, 60.0, -25.0);
    glVertex3f(6.0, 60.0, -15.0);
    glEnd();
    //gedung tengah end

    //kiri
    glColor3f(1.0, 0.98, 0.94);
    glBegin(GL_QUADS);
    glVertex3f(-26.0, 0.0, -25.0);
    glVertex3f(-6.0, 0.0, -25.0);
    glVertex3f(-6.0, 50.0, -25.0);
    glVertex3f(-26.0, 50.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-26.0, 0.0, -15.0);
    glVertex3f(-6.0, 0.0, -15.0);
    glVertex3f(-6.0, 50.0, -15.0);
    glVertex3f(-26.0, 50.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-6.0, 0.0, -15.0);
    glVertex3f(-6.0, 0.0, -25.0);
    glVertex3f(-6.0, 50.0, -25.0);
    glVertex3f(-6.0, 50.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-26.0, 0.0, -15.0);
    glVertex3f(-26.0, 0.0, -25.0);
    glVertex3f(-26.0, 50.0, -25.0);
    glVertex3f(-26.0, 50.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-26.0, 0.0, -15.0);
    glVertex3f(-26.0, 0.0, -25.0);
    glVertex3f(-6.0, 0.0, -25.0);
    glVertex3f(-6.0, 0.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-26.0, 50.0, -15.0);
    glVertex3f(-26.0, 50.0, -25.0);
    glVertex3f(-6.0, 50.0, -25.0);
    glVertex3f(-6.0, 50.0, -15.0);
    glEnd();
    //kiri end

    //kanan
    glColor3f(1.0, 0.98, 0.94);
    glBegin(GL_QUADS);
    glVertex3f(26.0, 0.0, -25.0);
    glVertex3f(6.0, 0.0, -25.0);
    glVertex3f(6.0, 50.0, -25.0);
    glVertex3f(26.0, 50.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(26.0, 0.0, -15.0);
    glVertex3f(6.0, 0.0, -15.0);
    glVertex3f(6.0, 50.0, -15.0);
    glVertex3f(26.0, 50.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(6.0, 0.0, -15.0);
    glVertex3f(6.0, 0.0, -25.0);
    glVertex3f(6.0, 50.0, -25.0);
    glVertex3f(6.0, 50.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(26.0, 0.0, -15.0);
    glVertex3f(26.0, 0.0, -25.0);
    glVertex3f(26.0, 50.0, -25.0);
    glVertex3f(26.0, 50.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(26.0, 0.0, -15.0);
    glVertex3f(26.0, 0.0, -25.0);
    glVertex3f(6.0, 0.0, -25.0);
    glVertex3f(6.0, 0.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(26.0, 50.0, -15.0);
    glVertex3f(26.0, 50.0, -25.0);
    glVertex3f(6.0, 50.0, -25.0);
    glVertex3f(6.0, 50.0, -15.0);
    glEnd();
    //kanan end

    //menara kanan
    glColor3f(1.0, 0.98, 0.94);
    glBegin(GL_QUADS);
    glVertex3f(32.0, 0.0, -25.0);
    glVertex3f(27.0, 0.0, -25.0);
    glVertex3f(27.0, 60.0, -25.0);
    glVertex3f(32.0, 60.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(32.0, 0.0, -15.0);
    glVertex3f(27.0, 0.0, -15.0);
    glVertex3f(27.0, 60.0, -15.0);
    glVertex3f(32.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(27.0, 0.0, -15.0);
    glVertex3f(27.0, 0.0, -25.0);
    glVertex3f(27.0, 60.0, -25.0);
    glVertex3f(27.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(32.0, 0.0, -15.0);
    glVertex3f(32.0, 0.0, -25.0);
    glVertex3f(32.0, 60.0, -25.0);
    glVertex3f(32.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(32.0, 0.0, -15.0);
    glVertex3f(32.0, 0.0, -25.0);
    glVertex3f(27.0, 0.0, -25.0);
    glVertex3f(27.0, 0.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(32.0, 60.0, -15.0);
    glVertex3f(32.0, 60.0, -25.0);
    glVertex3f(27.0, 60.0, -25.0);
    glVertex3f(27.0, 60.0, -15.0);
    glEnd();
    //menara kanan end

    //menara kanan
    glColor3f(1.0, 0.98, 0.94);
    glBegin(GL_QUADS);
    glVertex3f(-32.0, 0.0, -25.0);
    glVertex3f(-27.0, 0.0, -25.0);
    glVertex3f(-27.0, 60.0, -25.0);
    glVertex3f(-32.0, 60.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-32.0, 0.0, -15.0);
    glVertex3f(-27.0, 0.0, -15.0);
    glVertex3f(-27.0, 60.0, -15.0);
    glVertex3f(-32.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-27.0, 0.0, -15.0);
    glVertex3f(-27.0, 0.0, -25.0);
    glVertex3f(-27.0, 60.0, -25.0);
    glVertex3f(-27.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-32.0, 0.0, -15.0);
    glVertex3f(-32.0, 0.0, -25.0);
    glVertex3f(-32.0, 60.0, -25.0);
    glVertex3f(-32.0, 60.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-32.0, 0.0, -15.0);
    glVertex3f(-32.0, 0.0, -25.0);
    glVertex3f(-27.0, 0.0, -25.0);
    glVertex3f(-27.0, 0.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-32.0, 60.0, -15.0);
    glVertex3f(-32.0, 60.0, -25.0);
    glVertex3f(-27.0, 60.0, -25.0);
    glVertex3f(-27.0, 60.0, -15.0);
    glEnd();
    //menara kanan end
}

void gedung_belakang_perkiraan(){

    //gedung belakang bagian tengah
    glColor3f(1.0, 0.98, 0.97);
    glBegin(GL_QUADS);
    glVertex3f(-21.0, 0.0, -50.0);
    glVertex3f(21.0, 0.0, -50.0);
    glVertex3f(21.0, 34.0, -50.0);
    glVertex3f(-21.0, 34.0, -50.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0, 0.0, -25.0);
    glVertex3f(21.0, 0.0, -25.0);
    glVertex3f(21.0, 34.0, -25.0);
    glVertex3f(-21.0, 34.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.0, 0.0, -25.0);
    glVertex3f(21.0, 0.0, -50.0);
    glVertex3f(21.0, 34.0, -50.0);
    glVertex3f(21.0, 34.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0, 0.0, -25.0);
    glVertex3f(-21.0, 0.0, -50.0);
    glVertex3f(-21.0, 34.0, -50.0);
    glVertex3f(-21.0, 34.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0, 0.0, -25.0);
    glVertex3f(-21.0, 0.0, -20.0);
    glVertex3f(21.0, 0.0, -20.0);
    glVertex3f(21.0, 0.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0, 34.0, -25.0);
    glVertex3f(-21.0, 34.0, -50.0);
    glVertex3f(21.0, 34.0, -50.0);
    glVertex3f(21.0, 34.0, -25.0);
    glEnd();
    //gedung belakang tengah end
}

void jendelaKiriDepan (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 29.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 29.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 26.0 -yy, 10.2);
    glVertex3f(-30.0+xx, 26.0 -yy, 10.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 29.0 -yy, 10.2);
    glVertex3f(-30.0+xx, 26.0 -yy, 10.2);
    glVertex3f(-30.0+xx, 26.0 -yy, 10.5);
    glVertex3f(-30.0+xx, 29.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-27.0+xx, 29.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 26.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 26.0 -yy, 10.5);
    glVertex3f(-27.0+xx, 29.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 29.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 29.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 29.0 -yy, 10.5);
    glVertex3f(-30.0+xx, 29.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 26.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 26.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 26.0 -yy, 10.5);
    glVertex3f(-30.0+xx, 26.0 -yy, 10.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 29.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 29.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 26.0 -yy, 10.3);
    glVertex3f(-28.6+xx, 26.0 -yy, 10.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 29.0 -yy, 10.3);
    glVertex3f(-28.6+xx, 26.0 -yy, 10.3);
    glVertex3f(-28.6+xx, 26.0 -yy, 10.4);
    glVertex3f(-28.6+xx, 29.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.4+xx, 29.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 26.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 26.0 -yy, 10.4);
    glVertex3f(-28.4+xx, 29.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 29.0-yy, 10.3);
    glVertex3f(-28.4+xx, 29.0-yy, 10.3);
    glVertex3f(-28.4+xx, 29.0-yy, 10.4);
    glVertex3f(-28.6+xx, 29.0-yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 26.0-yy, 10.3);
    glVertex3f(-28.4+xx, 26.0-yy, 10.3);
    glVertex3f(-28.4+xx, 26.0-yy, 10.4);
    glVertex3f(-28.6+xx, 26.0-yy, 10.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 29.0-yy, 10.5);
    glVertex3f(-27.0+xx, 29.0-yy, 10.5);
    glVertex3f(-27.0+xx, 26.0-yy, 10.5);
    glVertex3f(-30.0+xx, 26.0-yy, 10.5);
    glEnd();
    //end
}

void jendelaKananDepan (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 29.0 -yy, 10.2);
    glVertex3f(27.0-xx, 29.0 -yy, 10.2);
    glVertex3f(27.0-xx, 26.0 -yy, 10.2);
    glVertex3f(30.0-xx, 26.0 -yy, 10.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 29.0 -yy, 10.2);
    glVertex3f(30.0-xx, 26.0 -yy, 10.2);
    glVertex3f(30.0-xx, 26.0 -yy, 10.5);
    glVertex3f(30.0-xx, 29.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(27.0-xx, 29.0 -yy, 10.2);
    glVertex3f(27.0-xx, 26.0 -yy, 10.2);
    glVertex3f(27.0-xx, 26.0 -yy, 10.5);
    glVertex3f(27.0-xx, 29.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 29.0 -yy, 10.2);
    glVertex3f(27.0-xx, 29.0 -yy, 10.2);
    glVertex3f(27.0-xx, 29.0 -yy, 10.5);
    glVertex3f(30.0-xx, 29.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 26.0 -yy, 10.2);
    glVertex3f(27.0-xx, 26.0 -yy, 10.2);
    glVertex3f(27.0-xx, 26.0 -yy, 10.5);
    glVertex3f(30.0-xx, 26.0 -yy, 10.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 29.0 -yy, 10.3);
    glVertex3f(28.4-xx, 29.0 -yy, 10.3);
    glVertex3f(28.4-xx, 26.0 -yy, 10.3);
    glVertex3f(28.6-xx, 26.0 -yy, 10.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 29.0 -yy, 10.3);
    glVertex3f(28.6-xx, 26.0 -yy, 10.3);
    glVertex3f(28.6-xx, 26.0 -yy, 10.4);
    glVertex3f(28.6-xx, 29.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.4-xx, 29.0 -yy, 10.3);
    glVertex3f(28.4-xx, 26.0 -yy, 10.3);
    glVertex3f(28.4-xx, 26.0 -yy, 10.4);
    glVertex3f(28.4-xx, 29.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 29.0-yy, 10.3);
    glVertex3f(28.4-xx, 29.0-yy, 10.3);
    glVertex3f(28.4-xx, 29.0-yy, 10.4);
    glVertex3f(28.6-xx, 29.0-yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 26.0-yy, 10.3);
    glVertex3f(28.4-xx, 26.0-yy, 10.3);
    glVertex3f(28.4-xx, 26.0-yy, 10.4);
    glVertex3f(28.6-xx, 26.0-yy, 10.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 29.0-yy, 10.5);
    glVertex3f(27.0-xx, 29.0-yy, 10.5);
    glVertex3f(27.0-xx, 26.0-yy, 10.5);
    glVertex3f(30.0-xx, 26.0-yy, 10.5);
    glEnd();
    //end
}

void jendelaKananMentokDepan (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 30.0 -yy, 0.2);
    glVertex3f(42.0-xx, 30.0 -yy, 0.2);
    glVertex3f(42.0-xx, 27.0 -yy, 0.2);
    glVertex3f(45.0-xx, 27.0 -yy, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 30.0 -yy, 0.2);
    glVertex3f(45.0-xx, 27.0 -yy, 0.2);
    glVertex3f(45.0-xx, 27.0 -yy, 0.5);
    glVertex3f(45.0-xx, 30.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(42.0-xx, 30.0 -yy, 0.2);
    glVertex3f(42.0-xx, 27.0 -yy, 0.2);
    glVertex3f(42.0-xx, 27.0 -yy, 0.5);
    glVertex3f(42.0-xx, 30.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 30.0 -yy, 0.2);
    glVertex3f(42.0-xx, 30.0 -yy, 0.2);
    glVertex3f(42.0-xx, 30.0 -yy, 0.5);
    glVertex3f(45.0-xx, 30.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 27.0 -yy, 0.2);
    glVertex3f(42.0-xx, 27.0 -yy, 0.2);
    glVertex3f(42.0-xx, 27.0 -yy, 0.5);
    glVertex3f(45.0-xx, 27.0 -yy, 0.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 30.0 -yy, 0.3);
    glVertex3f(43.4-xx, 30.0 -yy, 0.3);
    glVertex3f(43.4-xx, 27.0 -yy, 0.3);
    glVertex3f(43.6-xx, 27.0 -yy, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 30.0 -yy, 0.3);
    glVertex3f(43.6-xx, 27.0 -yy, 0.3);
    glVertex3f(43.6-xx, 27.0 -yy, 0.4);
    glVertex3f(43.6-xx, 30.0 -yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.4-xx, 30.0 -yy, 0.3);
    glVertex3f(43.4-xx, 27.0 -yy, 0.3);
    glVertex3f(43.4-xx, 27.0 -yy, 0.4);
    glVertex3f(43.4-xx, 30.0 -yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 30.0-yy, 0.3);
    glVertex3f(43.4-xx, 30.0-yy, 0.3);
    glVertex3f(43.4-xx, 30.0-yy, 0.4);
    glVertex3f(43.6-xx, 30.0-yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 27.0-yy, 0.3);
    glVertex3f(43.4-xx, 27.0-yy, 0.3);
    glVertex3f(43.4-xx, 27.0-yy, 0.4);
    glVertex3f(43.6-xx, 27.0-yy, 0.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 30.0-yy, 0.5);
    glVertex3f(42.0-xx, 30.0-yy, 0.5);
    glVertex3f(42.0-xx, 27.0-yy, 0.5);
    glVertex3f(45.0-xx, 27.0-yy, 0.5);
    glEnd();
    //end
}

void jendelaKiriMentokDepan (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-45.0+xx, 30.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 30.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 27.0 -yy, 0.2);
    glVertex3f(-45.0+xx, 27.0 -yy, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-45.0+xx, 30.0 -yy, 0.2);
    glVertex3f(-45.0+xx, 27.0 -yy, 0.2);
    glVertex3f(-45.0+xx, 27.0 -yy, 0.5);
    glVertex3f(-45.0+xx, 30.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-42.0+xx, 30.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 27.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 27.0 -yy, 0.5);
    glVertex3f(-42.0+xx, 30.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-45.0+xx, 30.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 30.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 30.0 -yy, 0.5);
    glVertex3f(-45.0+xx, 30.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-45.0+xx, 27.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 27.0 -yy, 0.2);
    glVertex3f(-42.0+xx, 27.0 -yy, 0.5);
    glVertex3f(-45.0+xx, 27.0 -yy, 0.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-43.6+xx, 30.0 -yy, 0.3);
    glVertex3f(-43.4+xx, 30.0 -yy, 0.3);
    glVertex3f(-43.4+xx, 27.0 -yy, 0.3);
    glVertex3f(-43.6+xx, 27.0 -yy, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-43.6+xx, 30.0 -yy, 0.3);
    glVertex3f(-43.6+xx, 27.0 -yy, 0.3);
    glVertex3f(-43.6+xx, 27.0 -yy, 0.4);
    glVertex3f(-43.6+xx, 30.0 -yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-43.4+xx, 30.0 -yy, 0.3);
    glVertex3f(-43.4+xx, 27.0 -yy, 0.3);
    glVertex3f(-43.4+xx, 27.0 -yy, 0.4);
    glVertex3f(-43.4+xx, 30.0 -yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-43.6+xx, 30.0-yy, 0.3);
    glVertex3f(-43.4+xx, 30.0-yy, 0.3);
    glVertex3f(-43.4+xx, 30.0-yy, 0.4);
    glVertex3f(-43.6+xx, 30.0-yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-43.6+xx, 27.0-yy, 0.3);
    glVertex3f(-43.4+xx, 27.0-yy, 0.3);
    glVertex3f(-43.4+xx, 27.0-yy, 0.4);
    glVertex3f(-43.6+xx, 27.0-yy, 0.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-45.0+xx, 30.0-yy, 0.5);
    glVertex3f(-42.0+xx, 30.0-yy, 0.5);
    glVertex3f(-42.0+xx, 27.0-yy, 0.5);
    glVertex3f(-45.0+xx, 27.0-yy, 0.5);
    glEnd();
    //end
}

void jendelaKananBelakang (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0 -yy, -14.5);
    glVertex3f(21.0-xx, 45.0 -yy, -14.5);
    glVertex3f(21.0-xx, 42.0 -yy, -14.5);
    glVertex3f(24.0-xx, 42.0 -yy, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0 -yy, -14.5);
    glVertex3f(24.0-xx, 42.0 -yy, -14.5);
    glVertex3f(24.0-xx, 42.0 -yy, -14.2);
    glVertex3f(24.0-xx, 45.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.0-xx, 45.0 -yy, -14.5);
    glVertex3f(21.0-xx, 42.0 -yy, -14.5);
    glVertex3f(21.0-xx, 42.0 -yy, -14.2);
    glVertex3f(21.0-xx, 45.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0 -yy, -14.5);
    glVertex3f(21.0-xx, 45.0 -yy, -14.5);
    glVertex3f(21.0-xx, 45.0 -yy, -14.2);
    glVertex3f(24.0-xx, 45.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 42.0 -yy, -14.5);
    glVertex3f(21.0-xx, 42.0 -yy, -14.5);
    glVertex3f(21.0-xx, 42.0 -yy, -14.2);
    glVertex3f(24.0-xx, 42.0 -yy, -14.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 45.0 -yy, -14.4);
    glVertex3f(22.4-xx, 45.0 -yy, -14.4);
    glVertex3f(22.4-xx, 42.0 -yy, -14.4);
    glVertex3f(22.6-xx, 42.0 -yy, -14.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 45.0 -yy, -14.4);
    glVertex3f(22.6-xx, 42.0 -yy, -14.4);
    glVertex3f(22.6-xx, 42.0 -yy, -14.3);
    glVertex3f(22.6-xx, 45.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.4-xx, 45.0 -yy, -14.4);
    glVertex3f(22.4-xx, 42.0 -yy, -14.4);
    glVertex3f(22.4-xx, 42.0 -yy, -14.3);
    glVertex3f(22.4-xx, 45.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 45.0-yy, -14.4);
    glVertex3f(22.4-xx, 45.0-yy, -14.4);
    glVertex3f(22.4-xx, 45.0-yy, -14.3);
    glVertex3f(22.6-xx, 45.0-yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 42.0-yy, -14.4);
    glVertex3f(22.4-xx, 42.0-yy, -15.4);
    glVertex3f(22.4-xx, 42.0-yy, -14.3);
    glVertex3f(22.6-xx, 42.0-yy, -14.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0-yy, -14.2);
    glVertex3f(21.0-xx, 45.0-yy, -14.2);
    glVertex3f(21.0-xx, 42.0-yy, -14.2);
    glVertex3f(24.0-xx, 42.0-yy, -14.2);
    glEnd();
    //end
}

void jendelaKiriBelakang (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 45.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -14.5);
    glVertex3f(-24.0+xx, 42.0 -yy, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0 -yy, -14.5);
    glVertex3f(-24.0+xx, 42.0 -yy, -14.5);
    glVertex3f(-24.0+xx, 42.0 -yy, -14.2);
    glVertex3f(-24.0+xx, 45.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+xx, 45.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -14.2);
    glVertex3f(-21.0+xx, 45.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 45.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 45.0 -yy, -14.2);
    glVertex3f(-24.0+xx, 45.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 42.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -14.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -14.2);
    glVertex3f(-24.0+xx, 42.0 -yy, -14.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 45.0 -yy, -14.4);
    glVertex3f(-22.4+xx, 45.0 -yy, -14.4);
    glVertex3f(-22.4+xx, 42.0 -yy, -14.4);
    glVertex3f(-22.6+xx, 42.0 -yy, -14.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 45.0 -yy, -14.4);
    glVertex3f(-22.6+xx, 42.0 -yy, -14.4);
    glVertex3f(-22.6+xx, 42.0 -yy, -14.3);
    glVertex3f(-22.6+xx, 45.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.4+xx, 45.0 -yy, -14.4);
    glVertex3f(-22.4+xx, 42.0 -yy, -14.4);
    glVertex3f(-22.4+xx, 42.0 -yy, -14.3);
    glVertex3f(-22.4+xx, 45.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 45.0-yy, -14.4);
    glVertex3f(-22.4+xx, 45.0-yy, -14.4);
    glVertex3f(-22.4+xx, 45.0-yy, -14.3);
    glVertex3f(-22.6+xx, 45.0-yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 42.0-yy, -14.4);
    glVertex3f(-22.4+xx, 42.0-yy, -15.4);
    glVertex3f(-22.4+xx, 42.0-yy, -14.3);
    glVertex3f(-22.6+xx, 42.0-yy, -14.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0-yy, -14.2);
    glVertex3f(-21.0+xx, 45.0-yy, -14.2);
    glVertex3f(-21.0+xx, 42.0-yy, -14.2);
    glVertex3f(-24.0+xx, 42.0-yy, -14.2);
    glEnd();
    //end
}

void jendelaKiriBelakangMentok (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-31.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-31.0+xx, 52.0 -yy, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-31.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-31.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-31.0+xx, 52.0 -yy, -14.2);
    glVertex3f(-31.0+xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 52.0 -yy, -14.2);
    glVertex3f(-28.0+xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-31.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 55.0 -yy, -14.2);
    glVertex3f(-31.0+xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-31.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-28.0+xx, 52.0 -yy, -14.2);
    glVertex3f(-31.0+xx, 52.0 -yy, -14.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-29.6+xx, 55.0 -yy, -14.4);
    glVertex3f(-29.4+xx, 55.0 -yy, -14.4);
    glVertex3f(-29.4+xx, 52.0 -yy, -14.4);
    glVertex3f(-29.6+xx, 52.0 -yy, -14.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.6+xx, 55.0 -yy, -14.4);
    glVertex3f(-29.6+xx, 52.0 -yy, -14.4);
    glVertex3f(-29.6+xx, 52.0 -yy, -14.3);
    glVertex3f(-29.6+xx, 55.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.4+xx, 55.0 -yy, -14.4);
    glVertex3f(-29.4+xx, 52.0 -yy, -14.4);
    glVertex3f(-29.4+xx, 52.0 -yy, -14.3);
    glVertex3f(-29.4+xx, 55.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.6+xx, 55.0-yy, -14.4);
    glVertex3f(-29.4+xx, 55.0-yy, -14.4);
    glVertex3f(-29.4+xx, 55.0-yy, -14.3);
    glVertex3f(-29.6+xx, 55.0-yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.6+xx, 52.0-yy, -14.4);
    glVertex3f(-29.4+xx, 52.0-yy, -15.4);
    glVertex3f(-29.4+xx, 52.0-yy, -14.3);
    glVertex3f(-29.6+xx, 52.0-yy, -14.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-31.0+xx, 55.0-yy, -14.2);
    glVertex3f(-28.0+xx, 55.0-yy, -14.2);
    glVertex3f(-28.0+xx, 52.0-yy, -14.2);
    glVertex3f(-31.0+xx, 52.0-yy, -14.2);
    glEnd();
    //end
}

void jendelaKananBelakangMentok (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0 -yy, -14.5);
    glVertex3f(28.0-xx, 55.0 -yy, -14.5);
    glVertex3f(28.0-xx, 52.0 -yy, -14.5);
    glVertex3f(31.0-xx, 52.0 -yy, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0 -yy, -14.5);
    glVertex3f(31.0-xx, 52.0 -yy, -14.5);
    glVertex3f(31.0-xx, 52.0 -yy, -14.2);
    glVertex3f(31.0-xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.0-xx, 55.0 -yy, -14.5);
    glVertex3f(28.0-xx, 52.0 -yy, -14.5);
    glVertex3f(28.0-xx, 52.0 -yy, -14.2);
    glVertex3f(28.0-xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0 -yy, -14.5);
    glVertex3f(28.0-xx, 55.0 -yy, -14.5);
    glVertex3f(28.0-xx, 55.0 -yy, -14.2);
    glVertex3f(31.0-xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 52.0 -yy, -14.5);
    glVertex3f(28.0-xx, 52.0 -yy, -14.5);
    glVertex3f(28.0-xx, 52.0 -yy, -14.2);
    glVertex3f(31.0-xx, 52.0 -yy, -14.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 55.0 -yy, -14.4);
    glVertex3f(29.4-xx, 55.0 -yy, -14.4);
    glVertex3f(29.4-xx, 52.0 -yy, -14.4);
    glVertex3f(29.6-xx, 52.0 -yy, -14.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 55.0 -yy, -14.4);
    glVertex3f(29.6-xx, 52.0 -yy, -14.4);
    glVertex3f(29.6-xx, 52.0 -yy, -14.3);
    glVertex3f(29.6-xx, 55.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.4-xx, 55.0 -yy, -14.4);
    glVertex3f(29.4-xx, 52.0 -yy, -14.4);
    glVertex3f(29.4-xx, 52.0 -yy, -14.3);
    glVertex3f(29.4-xx, 55.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 55.0-yy, -14.4);
    glVertex3f(29.4-xx, 55.0-yy, -14.4);
    glVertex3f(29.4-xx, 55.0-yy, -14.3);
    glVertex3f(29.6-xx, 55.0-yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 52.0-yy, -14.4);
    glVertex3f(29.4-xx, 52.0-yy, -15.4);
    glVertex3f(29.4-xx, 52.0-yy, -14.3);
    glVertex3f(29.6-xx, 52.0-yy, -14.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0-yy, -14.2);
    glVertex3f(28.0-xx, 55.0-yy, -14.2);
    glVertex3f(28.0-xx, 52.0-yy, -14.2);
    glVertex3f(31.0-xx, 52.0-yy, -14.2);
    glEnd();
    //end
}

void jendelaKananBelakangMentokBalik (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0 -yy, -25.5);
    glVertex3f(28.0-xx, 55.0 -yy, -25.5);
    glVertex3f(28.0-xx, 52.0 -yy, -25.5);
    glVertex3f(31.0-xx, 52.0 -yy, -25.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0 -yy, -25.5);
    glVertex3f(31.0-xx, 52.0 -yy, -25.5);
    glVertex3f(31.0-xx, 52.0 -yy, -25.2);
    glVertex3f(31.0-xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.0-xx, 55.0 -yy, -25.5);
    glVertex3f(28.0-xx, 52.0 -yy, -25.5);
    glVertex3f(28.0-xx, 52.0 -yy, -25.2);
    glVertex3f(28.0-xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0 -yy, -25.5);
    glVertex3f(28.0-xx, 55.0 -yy, -25.5);
    glVertex3f(28.0-xx, 55.0 -yy, -25.2);
    glVertex3f(31.0-xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 52.0 -yy, -25.5);
    glVertex3f(28.0-xx, 52.0 -yy, -25.5);
    glVertex3f(28.0-xx, 52.0 -yy, -25.2);
    glVertex3f(31.0-xx, 52.0 -yy, -25.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 55.0 -yy, -25.4);
    glVertex3f(29.4-xx, 55.0 -yy, -25.4);
    glVertex3f(29.4-xx, 52.0 -yy, -25.4);
    glVertex3f(29.6-xx, 52.0 -yy, -25.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 55.0 -yy, -25.4);
    glVertex3f(29.6-xx, 52.0 -yy, -25.4);
    glVertex3f(29.6-xx, 52.0 -yy, -25.3);
    glVertex3f(29.6-xx, 55.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.4-xx, 55.0 -yy, -25.4);
    glVertex3f(29.4-xx, 52.0 -yy, -25.4);
    glVertex3f(29.4-xx, 52.0 -yy, -25.3);
    glVertex3f(29.4-xx, 55.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 55.0-yy, -25.4);
    glVertex3f(29.4-xx, 55.0-yy, -25.4);
    glVertex3f(29.4-xx, 55.0-yy, -25.3);
    glVertex3f(29.6-xx, 55.0-yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(29.6-xx, 52.0-yy, -25.4);
    glVertex3f(29.4-xx, 52.0-yy, -25.4);
    glVertex3f(29.4-xx, 52.0-yy, -25.3);
    glVertex3f(29.6-xx, 52.0-yy, -25.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(31.0-xx, 55.0-yy, -25.6);
    glVertex3f(28.0-xx, 55.0-yy, -25.6);
    glVertex3f(28.0-xx, 52.0-yy, -25.6);
    glVertex3f(31.0-xx, 52.0-yy, -25.6);
    glEnd();
    //end
}

void jendelaKiriBelakangMentokBalik (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-31.0-xx, 55.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 55.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 52.0 -yy, -25.5);
    glVertex3f(-31.0-xx, 52.0 -yy, -25.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-31.0-xx, 55.0 -yy, -25.5);
    glVertex3f(-31.0-xx, 52.0 -yy, -25.5);
    glVertex3f(-31.0-xx, 52.0 -yy, -25.2);
    glVertex3f(-31.0-xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.0-xx, 55.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 52.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 52.0 -yy, -25.2);
    glVertex3f(-28.0-xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-31.0-xx, 55.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 55.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 55.0 -yy, -25.2);
    glVertex3f(-31.0-xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-31.0-xx, 52.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 52.0 -yy, -25.5);
    glVertex3f(-28.0-xx, 52.0 -yy, -25.2);
    glVertex3f(-31.0-xx, 52.0 -yy, -25.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-29.6-xx, 55.0 -yy, -25.4);
    glVertex3f(-29.4-xx, 55.0 -yy, -25.4);
    glVertex3f(-29.4-xx, 52.0 -yy, -25.4);
    glVertex3f(-29.6-xx, 52.0 -yy, -25.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.6-xx, 55.0 -yy, -25.4);
    glVertex3f(-29.6-xx, 52.0 -yy, -25.4);
    glVertex3f(-29.6-xx, 52.0 -yy, -25.3);
    glVertex3f(-29.6-xx, 55.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.4-xx, 55.0 -yy, -25.4);
    glVertex3f(-29.4-xx, 52.0 -yy, -25.4);
    glVertex3f(-29.4-xx, 52.0 -yy, -25.3);
    glVertex3f(-29.4-xx, 55.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.6-xx, 55.0-yy, -25.4);
    glVertex3f(-29.4-xx, 55.0-yy, -25.4);
    glVertex3f(-29.4-xx, 55.0-yy, -25.3);
    glVertex3f(-29.6-xx, 55.0-yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-29.6-xx, 52.0-yy, -25.4);
    glVertex3f(-29.4-xx, 52.0-yy, -25.4);
    glVertex3f(-29.4-xx, 52.0-yy, -25.3);
    glVertex3f(-29.6-xx, 52.0-yy, -25.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-31.0-xx, 55.0-yy, -25.6);
    glVertex3f(-28.0-xx, 55.0-yy, -25.6);
    glVertex3f(-28.0-xx, 52.0-yy, -25.6);
    glVertex3f(-31.0-xx, 52.0-yy, -25.6);
    glEnd();
    //end
}

void jendelaKiriBelakangBalik (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 45.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -25.5);
    glVertex3f(-24.0+xx, 42.0 -yy, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0 -yy, -25.5);
    glVertex3f(-24.0+xx, 42.0 -yy, -25.5);
    glVertex3f(-24.0+xx, 42.0 -yy, -25.2);
    glVertex3f(-24.0+xx, 45.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+xx, 45.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -25.2);
    glVertex3f(-21.0+xx, 45.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 45.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 45.0 -yy, -25.2);
    glVertex3f(-24.0+xx, 45.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 42.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -25.5);
    glVertex3f(-21.0+xx, 42.0 -yy, -25.2);
    glVertex3f(-24.0+xx, 42.0 -yy, -25.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 45.0 -yy, -25.4);
    glVertex3f(-22.4+xx, 45.0 -yy, -25.4);
    glVertex3f(-22.4+xx, 42.0 -yy, -25.4);
    glVertex3f(-22.6+xx, 42.0 -yy, -25.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 45.0 -yy, -25.4);
    glVertex3f(-22.6+xx, 42.0 -yy, -25.4);
    glVertex3f(-22.6+xx, 42.0 -yy, -25.3);
    glVertex3f(-22.6+xx, 45.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.4+xx, 45.0 -yy, -25.4);
    glVertex3f(-22.4+xx, 42.0 -yy, -25.4);
    glVertex3f(-22.4+xx, 42.0 -yy, -25.3);
    glVertex3f(-22.4+xx, 45.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 45.0-yy, -25.4);
    glVertex3f(-22.4+xx, 45.0-yy, -25.4);
    glVertex3f(-22.4+xx, 45.0-yy, -25.3);
    glVertex3f(-22.6+xx, 45.0-yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-22.6+xx, 42.0-yy, -25.4);
    glVertex3f(-22.4+xx, 42.0-yy, -25.4);
    glVertex3f(-22.4+xx, 42.0-yy, -25.3);
    glVertex3f(-22.6+xx, 42.0-yy, -25.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-24.0+xx, 45.0-yy, -25.6);
    glVertex3f(-21.0+xx, 45.0-yy, -25.6);
    glVertex3f(-21.0+xx, 42.0-yy, -25.6);
    glVertex3f(-24.0+xx, 42.0-yy, -25.6);
    glEnd();
    //end
}

void jendelaKananBelakangBalik (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0 -yy, -25.5);
    glVertex3f(21.0-xx, 45.0 -yy, -25.5);
    glVertex3f(21.0-xx, 42.0 -yy, -25.5);
    glVertex3f(24.0-xx, 42.0 -yy, -24.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0 -yy, -25.5);
    glVertex3f(24.0-xx, 42.0 -yy, -25.5);
    glVertex3f(24.0-xx, 42.0 -yy, -25.2);
    glVertex3f(24.0-xx, 45.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.0-xx, 45.0 -yy, -25.5);
    glVertex3f(21.0-xx, 42.0 -yy, -25.5);
    glVertex3f(21.0-xx, 42.0 -yy, -25.2);
    glVertex3f(21.0-xx, 45.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0 -yy, -25.5);
    glVertex3f(21.0-xx, 45.0 -yy, -25.5);
    glVertex3f(21.0-xx, 45.0 -yy, -25.2);
    glVertex3f(24.0-xx, 45.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 42.0 -yy, -25.5);
    glVertex3f(21.0-xx, 42.0 -yy, -25.5);
    glVertex3f(21.0-xx, 42.0 -yy, -25.2);
    glVertex3f(24.0-xx, 42.0 -yy, -25.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 45.0 -yy, -25.4);
    glVertex3f(22.4-xx, 45.0 -yy, -25.4);
    glVertex3f(22.4-xx, 42.0 -yy, -25.4);
    glVertex3f(22.6-xx, 42.0 -yy, -25.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 45.0 -yy, -25.4);
    glVertex3f(22.6-xx, 42.0 -yy, -25.4);
    glVertex3f(22.6-xx, 42.0 -yy, -25.3);
    glVertex3f(22.6-xx, 45.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.4-xx, 45.0 -yy, -25.4);
    glVertex3f(22.4-xx, 42.0 -yy, -25.4);
    glVertex3f(22.4-xx, 42.0 -yy, -25.3);
    glVertex3f(22.4-xx, 45.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 45.0-yy, -25.4);
    glVertex3f(22.4-xx, 45.0-yy, -25.4);
    glVertex3f(22.4-xx, 45.0-yy, -25.3);
    glVertex3f(22.6-xx, 45.0-yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.6-xx, 42.0-yy, -25.4);
    glVertex3f(22.4-xx, 42.0-yy, -25.4);
    glVertex3f(22.4-xx, 42.0-yy, -25.3);
    glVertex3f(22.6-xx, 42.0-yy, -25.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(24.0-xx, 45.0-yy, -25.6);
    glVertex3f(21.0-xx, 45.0-yy, -25.6);
    glVertex3f(21.0-xx, 42.0-yy, -25.6);
    glVertex3f(24.0-xx, 42.0-yy, -25.6);
    glEnd();
    //end
}

void jendelaTengahBelakang (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-1.0+xx, 52.0 -yy, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-1.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-1.0+xx, 52.0 -yy, -14.2);
    glVertex3f(-1.0+xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-4.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -14.2);
    glVertex3f(-4.0+xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 55.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 55.0 -yy, -14.2);
    glVertex3f(-1.0+xx, 55.0 -yy, -14.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -14.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -14.2);
    glVertex3f(-1.0+xx, 52.0 -yy, -14.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 55.0 -yy, -14.4);
    glVertex3f(-2.4+xx, 55.0 -yy, -14.4);
    glVertex3f(-2.4+xx, 52.0 -yy, -14.4);
    glVertex3f(-2.6+xx, 52.0 -yy, -14.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 55.0 -yy, -14.4);
    glVertex3f(-2.6+xx, 52.0 -yy, -14.4);
    glVertex3f(-2.6+xx, 52.0 -yy, -14.3);
    glVertex3f(-2.6+xx, 55.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.4+xx, 55.0 -yy, -14.4);
    glVertex3f(-2.4+xx, 52.0 -yy, -14.4);
    glVertex3f(-2.4+xx, 52.0 -yy, -14.3);
    glVertex3f(-2.4+xx, 55.0 -yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 55.0-yy, -14.4);
    glVertex3f(-2.4+xx, 55.0-yy, -14.4);
    glVertex3f(-2.4+xx, 55.0-yy, -14.3);
    glVertex3f(-2.6+xx, 55.0-yy, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 52.0-yy, -14.4);
    glVertex3f(-2.4+xx, 52.0-yy, -15.4);
    glVertex3f(-2.4+xx, 52.0-yy, -14.3);
    glVertex3f(-2.6+xx, 52.0-yy, -14.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0-yy, -14.2);
    glVertex3f(-4.0+xx, 55.0-yy, -14.2);
    glVertex3f(-4.0+xx, 52.0-yy, -14.2);
    glVertex3f(-1.0+xx, 52.0-yy, -14.2);
    glEnd();
    //end
}

void jendelaTengahBelakangBalik (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 55.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -25.5);
    glVertex3f(-1.0+xx, 52.0 -yy, -25.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0 -yy, -25.5);
    glVertex3f(-1.0+xx, 52.0 -yy, -25.5);
    glVertex3f(-1.0+xx, 52.0 -yy, -25.2);
    glVertex3f(-1.0+xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-4.0+xx, 55.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -25.2);
    glVertex3f(-4.0+xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 55.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 55.0 -yy, -25.2);
    glVertex3f(-1.0+xx, 55.0 -yy, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 52.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -25.5);
    glVertex3f(-4.0+xx, 52.0 -yy, -25.2);
    glVertex3f(-1.0+xx, 52.0 -yy, -25.2);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 55.0 -yy, -25.4);
    glVertex3f(-2.4+xx, 55.0 -yy, -25.4);
    glVertex3f(-2.4+xx, 52.0 -yy, -25.4);
    glVertex3f(-2.6+xx, 52.0 -yy, -25.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 55.0 -yy, -25.4);
    glVertex3f(-2.6+xx, 52.0 -yy, -25.4);
    glVertex3f(-2.6+xx, 52.0 -yy, -25.3);
    glVertex3f(-2.6+xx, 55.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.4+xx, 55.0 -yy, -25.4);
    glVertex3f(-2.4+xx, 52.0 -yy, -25.4);
    glVertex3f(-2.4+xx, 52.0 -yy, -25.3);
    glVertex3f(-2.4+xx, 55.0 -yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 55.0-yy, -25.4);
    glVertex3f(-2.4+xx, 55.0-yy, -25.4);
    glVertex3f(-2.4+xx, 55.0-yy, -25.3);
    glVertex3f(-2.6+xx, 55.0-yy, -25.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.6+xx, 52.0-yy, -25.4);
    glVertex3f(-2.4+xx, 52.0-yy, -25.4);
    glVertex3f(-2.4+xx, 52.0-yy, -25.3);
    glVertex3f(-2.6+xx, 52.0-yy, -25.3);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-1.0+xx, 55.0-yy, -25.6);
    glVertex3f(-4.0+xx, 55.0-yy, -25.6);
    glVertex3f(-4.0+xx, 52.0-yy, -25.6);
    glVertex3f(-1.0+xx, 52.0-yy, -25.6);
    glEnd();
    //end
}

void loopJendela(){
    //loop jendela depan kiri
    int yj,xj;
    for(xj = 0; xj <= 25; xj += 5){
        for(yj = 0; yj < 15; yj += 5){
            jendelaKiriDepan(xj, yj);
        }
    }
    //end loop

    //loop jendela depan kanan
    for(xj = 0; xj <= 25; xj += 5){
        for(yj = 0; yj < 15; yj += 5){
            jendelaKananDepan(xj, yj);
        }
    }
    //end loop

    //loop jendela kanan mentok depan
    for(xj = 0; xj <= 25; xj += 5){
        for(yj = 0; yj < 10; yj += 5){
            jendelaKananMentokDepan(xj, yj);
        }
    }
    //end loop

    //loop jendela kiri mentok depan
    for(xj = 0; xj <= 25; xj += 5){
        for(yj = 0; yj < 10; yj += 5){
            jendelaKiriMentokDepan(xj, yj);
        }
    }
    //end loop

    //loop jendela kanan belakang
    for(xj = 0; xj <= 32; xj += 4){
        for(yj = 0; yj < 16; yj += 4){
            jendelaKananBelakang(xj, yj);
        }
    }
    //end loop

    //loop jendela kanan belakang
    for(xj = 0; xj <= 32; xj += 4){
        for(yj = 0; yj < 16; yj += 4){
            jendelaKananBelakangBalik(xj, yj);
        }
    }
    //end loop

    //loop jendela kiri belakang
    for(xj = 0; xj <= 32; xj += 4){
        for(yj = 0; yj < 16; yj += 4){
            jendelaKiriBelakang(xj, yj);
        }
    }
    //end loop

    //loop jendela kiri belakang
    for(xj = 0; xj <= 32; xj += 4){
        for(yj = 0; yj < 16; yj += 4){
            jendelaKiriBelakangBalik(xj, yj);
        }
    }
    //end loop

    //loop jendela kanan mentok belakang
    for(xj = 0; xj <= 32; xj += 4){
        for(yj = 0; yj < 16; yj += 4){
            jendelaKiriBelakang(xj, yj);
        }
    }
    //end loop

    //loop jendela kiri mentok belakang
    for(xj = 0; xj <= 48; xj += 4){
        for(yj = 0; yj < 5; yj += 5){
            jendelaKiriBelakangMentok(xj, yj);
        }
    }
    //end loop

    //loop jendela kanan mentok belakang
    for(xj = 0; xj <= 48; xj += 4){
        for(yj = 0; yj < 5; yj += 5){
            jendelaKananBelakangMentok(xj, yj);
        }
    }
    //end loop

    //loop jendela tengah belakang
    for(xj = 0; xj <= 48; xj += 4){
        for(yj = 0; yj < 10; yj += 5){
            jendelaTengahBelakang(xj, yj);
        }
    }
    //end loop

    //loop jendela tengah belakang
    for(xj = 0; xj <= 16; xj += 4){
        for(yj = 0; yj < 10; yj += 5){
            jendelaTengahBelakangBalik(xj, yj);
        }
    }
    //end loop

     //loop jendela kanan mentok belakang balik
    for(xj = 0; xj <= 48; xj += 4){
        for(yj = 0; yj < 5; yj += 5){
            jendelaKananBelakangMentokBalik(xj, yj);
        }
    }
    //end loop

    //loop jendela kiri mentok belakang balik
    for(xj = 0; xj <= 48; xj += 4){
        for(yj = 0; yj < 5; yj += 5){
            jendelaKiriBelakangMentokBalik(xj, yj);
        }
    }
    //end loop


}

void platform(){
    //garis loop
    int zz;
    for(zz = 0; zz <= 210; zz += 21){
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-190.0, 0.0, 60.0-zz);
        glVertex3f(-140.0, 0.0, 60.0-zz);
        glVertex3f(-140.0, 0.0, 57.0-zz);
        glVertex3f(-190.0, 0.0, 57.0-zz);
        glEnd();
    }
    //end

    //garis parkir
    glBegin(GL_QUADS);
    glVertex3f(-190.0, 0.0, 60.0);
    glVertex3f(-185.0, 0.0, 60.0);
    glVertex3f(-185.0, 0.0, -150.0);
    glVertex3f(-190.0, 0.0, -150.0);
    glEnd();
    //end

    //parkiran
    glColor3f(0.41, 0.41, 0.41);
    glBegin(GL_QUADS);
    glVertex3f(-190.0, 0.0, 60.0);
    glVertex3f(-140.0, 0.0, 60.0);
    glVertex3f(-140.0, 0.0, -150.0);
    glVertex3f(-190.0, 0.0, -150.0);
    glEnd();
    //end

    for(zz = 0; zz <= 210; zz += 21){
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(190.0, 0.0, 60.0-zz);
        glVertex3f(140.0, 0.0, 60.0-zz);
        glVertex3f(140.0, 0.0, 57.0-zz);
        glVertex3f(190.0, 0.0, 57.0-zz);
        glEnd();
    }
    //end

    //garis parkir
    glBegin(GL_QUADS);
    glVertex3f(190.0, 0.0, 60.0);
    glVertex3f(185.0, 0.0, 60.0);
    glVertex3f(185.0, 0.0, -150.0);
    glVertex3f(190.0, 0.0, -150.0);
    glEnd();
    //end

    //parkiran
    glColor3f(0.41, 0.41, 0.41);
    glBegin(GL_QUADS);
    glVertex3f(190.0, 0.0, 60.0);
    glVertex3f(140.0, 0.0, 60.0);
    glVertex3f(140.0, 0.0, -150.0);
    glVertex3f(190.0, 0.0, -150.0);
    glEnd();
    //end

    //jalan
    glColor3f(0.41, 0.41, 0.41);
    glBegin(GL_QUADS);
        glVertex3f(-60.0, 0.0, 60);
        glVertex3f(60.0, 0.0, 60);
        glVertex3f(60.0, 0.0, 50);
        glVertex3f(-60.0, 0.0, 50);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-60.0, 0.0, -70);
        glVertex3f(60.0, 0.0, -70);
        glVertex3f(60.0, 0.0, -60);
        glVertex3f(-60.0, 0.0, -60);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-60.0, 0.0, -150);
        glVertex3f(60.0, 0.0, -150);
        glVertex3f(60.0, 0.0, -140);
        glVertex3f(-60.0, 0.0, -140);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-65.0, 0.0, 60);
        glVertex3f(-55.0, 0.0, 60);
        glVertex3f(-55.0, 0.0, -150);
        glVertex3f(-65.0, 0.0, -150);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(65.0, 0.0, 60);
        glVertex3f(55.0, 0.0, 60);
        glVertex3f(55.0, 0.0, -150);
        glVertex3f(65.0, 0.0, -150);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0, 0.0, 60);
        glVertex3f(5.0, 0.0, 60);
        glVertex3f(5.0, 0.0, 5);
        glVertex3f(-5.0, 0.0, 5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0, 0.0, -150);
        glVertex3f(5.0, 0.0, -150);
        glVertex3f(5.0, 0.0, -100);
        glVertex3f(-5.0, 0.0, -100);
    glEnd();
    //end


    glColor3f(1.0, 0.41, 0.71);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 0.0, 100);
        glVertex3f(-100.0, 0.0, -50);
        glVertex3f(0.0, 0.0, -200.0);
        glVertex3f(100.0, 0.0, -50);
    glEnd();

    glColor3f(0.56, 0.74, 0.56);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 0.0, 100);
        glVertex3f(-150.0, 0.0, -50);
        glVertex3f(0.0, 0.0, -200.0);
        glVertex3f(150.0, 0.0, -50);
    glEnd();

    glColor3f(0.96, 0.64, 0.38);
    glBegin(GL_QUADS);
        glVertex3f(-200.0, 0.0, 100);
        glVertex3f(200.0, 0.0, 100);
        glVertex3f(200.0, 0.0, -200);
        glVertex3f(-200.0, 0.0, -200);
    glEnd();
}

void gedung_tambahan(){
    //gedung
    glColor3f(1.0, 0.98, 0.94);
    glBegin(GL_QUADS);
    glVertex3f(-25.0, 35.0, -80.0);
    glVertex3f(25.0, 35.0, -80.0);
    glVertex3f(25.0, 35.0, -105.0);
    glVertex3f(-25.0, 35.0, -105.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 0.0, -80.0);
    glVertex3f(25.0, 0.0, -80.0);
    glVertex3f(25.0, 0.0, -105.0);
    glVertex3f(-25.0, 0.0, -105.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 35.0, -80.0);
    glVertex3f(25.0, 35.0, -80.0);
    glVertex3f(25.0, 0.0, -80.0);
    glVertex3f(-25.0, 0.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 35.0, -80.0);
    glVertex3f(-25.0, 35.0, -105.0);
    glVertex3f(-25.0, 0.0, -105.0);
    glVertex3f(-25.0, 0.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(25.0, 35.0, -80.0);
    glVertex3f(25.0, 35.0, -105.0);
    glVertex3f(25.0, 0.0, -105.0);
    glVertex3f(25.0, 0.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 35.0, -105.0);
    glVertex3f(25.0, 35.0, -105.0);
    glVertex3f(25.0, 0.0, -105.0);
    glVertex3f(-25.0, 0.0, -105.0);
    glEnd();
    //end
    //estetik kiri
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_QUADS);
    glVertex3f(-25.0, 35.2, -88.5);
    glVertex3f(-20.0, 35.2, -88.5);
    glVertex3f(-20.0, 35.2, -96.5);
    glVertex3f(-25.0, 35.2, -96.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 37.2, -88.5);
    glVertex3f(-20.0, 37.2, -88.5);
    glVertex3f(-20.0, 37.2, -96.5);
    glVertex3f(-25.0, 37.2, -96.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 37.2, -88.5);
    glVertex3f(-20.0, 37.2, -88.5);
    glVertex3f(-20.0, 35.2, -88.5);
    glVertex3f(-25.0, 35.2, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 37.2, -96.5);
    glVertex3f(-20.0, 37.2, -96.5);
    glVertex3f(-20.0, 35.2, -96.5);
    glVertex3f(-25.0, 35.2, -96.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 37.2, -88.5);
    glVertex3f(-20.0, 37.2, -96.5);
    glVertex3f(-20.0, 35.2, -96.5);
    glVertex3f(-20.0, 35.2, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 37.2, -88.5);
    glVertex3f(-25.0, 37.2, -96.5);
    glVertex3f(-25.0, 0.0, -96.5);
    glVertex3f(-25.0, 0.00, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 37.2, -88.5);
    glVertex3f(-25.0, 37.2, -96.5);
    glVertex3f(-29.0, 0.0, -96.5);
    glVertex3f(-29.0, 0.0, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-25.0, 0.0, -88.5);
    glVertex3f(-25.0, 0.0, -96.5);
    glVertex3f(-29.0, 0.0, -96.5);
    glVertex3f(-29.0, 0.0, -88.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-25.0, 37.2, -88.5);
    glVertex3f(-25.0, 0.0, -88.5);
    glVertex3f(-29.0, 0.0, -88.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-25.0, 37.2, -96.5);
    glVertex3f(-25.0, 0.0, -96.5);
    glVertex3f(-29.0, 0.0, -96.5);
    glEnd();
    //end
    //estetik kanan
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_QUADS);
    glVertex3f(25.0, 35.2, -88.5);
    glVertex3f(20.0, 35.2, -88.5);
    glVertex3f(20.0, 35.2, -96.5);
    glVertex3f(25.0, 35.2, -96.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(25.0, 37.2, -88.5);
    glVertex3f(20.0, 37.2, -88.5);
    glVertex3f(20.0, 37.2, -96.5);
    glVertex3f(25.0, 37.2, -96.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(25.0, 37.2, -88.5);
    glVertex3f(20.0, 37.2, -88.5);
    glVertex3f(20.0, 35.2, -88.5);
    glVertex3f(25.0, 35.2, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(25.0, 37.2, -96.5);
    glVertex3f(20.0, 37.2, -96.5);
    glVertex3f(20.0, 35.2, -96.5);
    glVertex3f(25.0, 35.2, -96.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(20.0, 37.2, -88.5);
    glVertex3f(20.0, 37.2, -96.5);
    glVertex3f(20.0, 35.2, -96.5);
    glVertex3f(20.0, 35.2, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(25.0, 37.2, -88.5);
    glVertex3f(25.0, 37.2, -96.5);
    glVertex3f(25.0, 0.0, -96.5);
    glVertex3f(25.0, 0.00, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(25.0, 37.2, -88.5);
    glVertex3f(25.0, 37.2, -96.5);
    glVertex3f(29.0, 0.0, -96.5);
    glVertex3f(29.0, 0.0, -88.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(25.0, 0.0, -88.5);
    glVertex3f(25.0, 0.0, -96.5);
    glVertex3f(29.0, 0.0, -96.5);
    glVertex3f(29.0, 0.0, -88.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(25.0, 37.2, -88.5);
    glVertex3f(25.0, 0.0, -88.5);
    glVertex3f(29.0, 0.0, -88.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(25.0, 37.2, -96.5);
    glVertex3f(25.0, 0.0, -96.5);
    glVertex3f(29.0, 0.0, -96.5);
    glEnd();
    //end
}

void hiasan1(){
    //meja(?)
    glColor3f(1.0, 0.3, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-3.0, 0.0, -62.0);
    glVertex3f(3.0, 0.0, -62.0);
    glVertex3f(3.0, 0.0, -68.0);
    glVertex3f(-3.0, 0.0, -68.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 3.0, -62.0);
    glVertex3f(3.0, 3.0, -62.0);
    glVertex3f(3.0, 3.0, -68.0);
    glVertex3f(-3.0, 3.0, -68.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(3.0, 0.0, -62.0);
    glVertex3f(3.0, 3.0, -62.0);
    glVertex3f(3.0, 3.0, -68.0);
    glVertex3f(3.0, 0.0, -68.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 0.0, -62.0);
    glVertex3f(-3.0, 3.0, -62.0);
    glVertex3f(-3.0, 3.0, -68.0);
    glVertex3f(-3.0, 0.0, -68.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 3.0, -62.0);
    glVertex3f(3.0, 3.0, -62.0);
    glVertex3f(3.0, 0.0, -62.0);
    glVertex3f(-3.0, 0.0, -62.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 3.0, -68.0);
    glVertex3f(3.0, 3.0, -68.0);
    glVertex3f(3.0, 0.0, -68.0);
    glVertex3f(-3.0, 0.0, -68.0);
    glEnd();
    //end
    //gagang
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.5, 3.1, -64.5);
    glVertex3f(0.5, 3.1, -64.5);
    glVertex3f(0.5, 3.1, -65.5);
    glVertex3f(-0.5, 3.1, -65.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5, 10.1, -64.5);
    glVertex3f(0.5, 10.1, -64.5);
    glVertex3f(0.5, 10.1, -65.5);
    glVertex3f(-0.5, 10.1, -65.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.5, 3.1, -64.5);
    glVertex3f(0.5, 10.1, -64.5);
    glVertex3f(0.5, 10.1, -65.5);
    glVertex3f(0.5, 3.1, -65.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5, 3.1, -64.5);
    glVertex3f(-0.5, 10.1, -64.5);
    glVertex3f(-0.5, 10.1, -65.5);
    glVertex3f(-0.5, 3.1, -65.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5, 3.1, -64.5);
    glVertex3f(0.5, 3.1, -64.5);
    glVertex3f(0.5, 10.1, -64.5);
    glVertex3f(-0.5, 10.1, -64.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5, 3.1, -65.5);
    glVertex3f(0.5, 3.1, -65.5);
    glVertex3f(0.5, 10.1, -65.5);
    glVertex3f(-0.5, 10.1, -65.5);
    glEnd();
    //end
    //payung
    glColor3f(0.6, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-6.0, 10.2, -59.0);
    glVertex3f(6.0, 10.2, -59.0);
    glVertex3f(6.0, 10.2, -71.0);
    glVertex3f(-6.0, 10.2, -71.0);
    glEnd();

    glColor3f(0.8, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-6.0, 10.2, -59.0);
    glVertex3f(6.0, 10.2, -59.0);
    glVertex3f(0.0, 15.2, -65.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(6.0, 10.2, -59.0);
    glVertex3f(6.0, 10.2, -71.0);
    glVertex3f(0.0, 15.2, -65.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-6.0, 10.2, -59.0);
    glVertex3f(-6.0, 10.2, -71.0);
    glVertex3f(0.0, 15.2, -65.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-6.0, 10.2, -71.0);
    glVertex3f(6.0, 10.2, -71.0);
    glVertex3f(0.0, 15.2, -65.0);
    glEnd();
}

void skyway(){
    //base
    glColor3f(0.633, 0.633, 0.633);
    glBegin(GL_QUADS);
    glVertex3f(-17.0, 20.0, -50.1);
    glVertex3f(17.0, 20.0, -50.1);
    glVertex3f(17.0, 20.0, -79.9);
    glVertex3f(-17.0, 20.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.0, 19.5, -50.1);
    glVertex3f(17.0, 19.5, -50.1);
    glVertex3f(17.0, 19.5, -79.9);
    glVertex3f(-17.0, 19.5, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17.0, 19.5, -50.1);
    glVertex3f(17.0, 20.0, -50.1);
    glVertex3f(17.0, 20.0, -79.9);
    glVertex3f(17.0, 19.5, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.0, 19.5, -50.1);
    glVertex3f(-17.0, 20.0, -50.1);
    glVertex3f(-17.0, 20.0, -79.9);
    glVertex3f(-17.0, 19.5, -79.9);
    glEnd();
    //end
    //frame atas
    glBegin(GL_QUADS);
    glVertex3f(-17.1, 30.1, -50.1);
    glVertex3f(-14.0, 30.1, -50.1);
    glVertex3f(-14.0, 30.1, -79.9);
    glVertex3f(-17.1, 30.1, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17.1, 30.1, -50.1);
    glVertex3f(14.0, 30.1, -50.1);
    glVertex3f(14.0, 30.1, -79.9);
    glVertex3f(17.1, 30.1, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17.1, 30.1, -50.1);
    glVertex3f(14.0, 30.1, -50.1);
    glVertex3f(-17.1, 30.1, -79.9);
    glVertex3f(-14.0, 30.1, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.1, 30.1, -50.1);
    glVertex3f(-14.0, 30.1, -50.1);
    glVertex3f(17.1, 30.1, -79.9);
    glVertex3f(14.0, 30.1, -79.9);
    glEnd();

    mab=(-79.9+50.1)/(17.1+17.1);
    mcd=(-79.9+50.1)/(-17.1-17.1);
    cab=-50.1-(-17.1*mab);
    ccd=-50.1-(17.1*mcd);
    px1=(ccd-cab)/(mab-mcd);
    py1=(mab*px1)+cab;

    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    glVertex3f(px1, 30.2, py1);
    glEnd();
    //end
    //frame kiri
    glColor3f(0.633, 0.633, 0.633);
    glBegin(GL_QUADS);
    glVertex3f(-17.1, 30.0, -50.1);
    glVertex3f(-17.1, 27.0, -50.1);
    glVertex3f(-17.1, 27.0, -79.9);
    glVertex3f(-17.1, 30.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.1, 22.0, -50.1);
    glVertex3f(-17.1, 19.0, -50.1);
    glVertex3f(-17.1, 19.0, -79.9);
    glVertex3f(-17.1, 22.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.1, 30.0, -50.1);
    glVertex3f(-17.1, 29.0, -50.1);
    glVertex3f(-17.1, 19.0, -79.9);
    glVertex3f(-17.1, 20.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.1, 19.0, -50.1);
    glVertex3f(-17.1, 20.0, -50.1);
    glVertex3f(-17.1, 29.0, -79.9);
    glVertex3f(-17.1, 30.0, -79.9);
    glEnd();
    //end
    //frame kanan
    glBegin(GL_QUADS);
    glVertex3f(17.1, 30.0, -50.1);
    glVertex3f(17.1, 27.0, -50.1);
    glVertex3f(17.1, 27.0, -79.9);
    glVertex3f(17.1, 30.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17.1, 22.0, -50.1);
    glVertex3f(17.1, 19.0, -50.1);
    glVertex3f(17.1, 19.0, -79.9);
    glVertex3f(17.1, 22.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17.1, 30.0, -50.1);
    glVertex3f(17.1, 29.0, -50.1);
    glVertex3f(17.1, 19.0, -79.9);
    glVertex3f(17.1, 20.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17.1, 19.0, -50.1);
    glVertex3f(17.1, 20.0, -50.1);
    glVertex3f(17.1, 29.0, -79.9);
    glVertex3f(17.1, 30.0, -79.9);
    glEnd();
    //end
    //kaca
    glColor4f(0.0, 1.0, 1.0, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(-17.0, 30.0, -50.1);
    glVertex3f(17.0, 30.0, -50.1);
    glVertex3f(17.0, 30.0, -79.9);
    glVertex3f(-17.0, 30.0, -79.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.0, 30.0, -50.1);
    glVertex3f(-17.0, 30.0, -79.9);
    glVertex3f(-17.0, 20.0, -79.9);
    glVertex3f(-17.0, 20.0, -50.1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17.0, 30.0, -50.1);
    glVertex3f(17.0, 30.0, -79.9);
    glVertex3f(17.0, 20.0, -79.9);
    glVertex3f(17.0, 20.0, -50.1);
    glEnd();
    //end
}

void setengah(int n_angle, float cx, float cy, float radius, float rotAngle, float zz){
    double angle , angleInc;
	int k;
	if(n_angle > 3)
    {
        angle = rotAngle * M_PI / 180;
        angleInc = 2 * M_PI /n_angle;
        glVertex3f(radius * cos(angle) + cx, radius * sin(angle)+cy, zz);
        for(k = 0; k < n_angle; k++)
        {
            angle += angleInc;
            glVertex3f(radius * cos(angle) + cx, radius * sin(angle) + cy, zz);
        }
	}
	else return;
}

void atap_setengah(){
    double angleInc = 2 * M_PI / 33, i;
	glBegin(GL_POLYGON);
    for(i = 0; i < 10 ; i += angleInc)
    {
        glColor4f(0.0, 1.0, 1.0, 0.3);
        setengah(8,0,60,6,90,-24.5);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(i = 0; i < 10 ; i += angleInc)
    {
        glColor4f(0.0, 1.0, 1.0, 0.3);
        setengah(8,0,60,6,90,-15.5);
    }
	glEnd();
	glFlush();
}

void cover_atap(){
    glColor3f(0.633, 0.633, 0.633);
    glBegin(GL_QUADS);
    glVertex3f(-6.0, 60.0, -15.5);
    glVertex3f(-4.3, 64.2, -15.5);
    glVertex3f(-4.3, 64.2, -24.5);
    glVertex3f(-6.0, 60.0, -24.5);
    glEnd();

    glColor3f(0.633, 0.633, 0.633);
    glBegin(GL_QUADS);
    glVertex3f(-4.3, 64.2, -15.5);
    glVertex3f(0, 66.0, -15.5);
    glVertex3f(0, 66.0, -24.5);
    glVertex3f(-4.3, 64.2, -24.5);
    glEnd();

    glColor3f(0.633, 0.633, 0.633);
    glBegin(GL_QUADS);
    glVertex3f(6.0, 60.0, -15.5);
    glVertex3f(4.3, 64.2, -15.5);
    glVertex3f(4.3, 64.2, -24.5);
    glVertex3f(6.0, 60.0, -24.5);
    glEnd();

    glColor3f(0.633, 0.633, 0.633);
    glBegin(GL_QUADS);
    glVertex3f(4.3, 64.2, -15.5);
    glVertex3f(0, 66.0, -15.5);
    glVertex3f(0, 66.0, -24.5);
    glVertex3f(4.3, 64.2, -24.5);
    glEnd();
}

void pohon1(int pz){
    //batang
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex3f(-70.0, 0.0, 40.0-pz);
    glVertex3f(-68.0, 0.0, 40.0-pz);
    glVertex3f(-68.0, 5.0, 40.0-pz);
    glVertex3f(-70.0, 5.0, 40.0-pz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-70.0, 0.0, 38.0-pz);
    glVertex3f(-68.0, 0.0, 38.0-pz);
    glVertex3f(-68.0, 5.0, 38.0-pz);
    glVertex3f(-70.0, 5.0, 38.0-pz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-68.0, 0.0, 40.0-pz);
    glVertex3f(-68.0, 0.0, 38.0-pz);
    glVertex3f(-68.0, 5.0, 38.0-pz);
    glVertex3f(-68.0, 5.0, 40.0-pz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-70.0, 0.0, 40.0-pz);
    glVertex3f(-70.0, 0.0, 38.0-pz);
    glVertex3f(-70.0, 5.0, 38.0-pz);
    glVertex3f(-70.0, 5.0, 40.0-pz);
    glEnd();
    //end

    //daun
    glColor3f(0.68, 1.0, 0.18);
    glBegin(GL_QUADS);
    glVertex3f(-72.0, 5.0, 42.0-pz);
    glVertex3f(-66.0, 5.0, 42.0-pz);
    glVertex3f(-66.0, 5.0, 36.0-pz);
    glVertex3f(-72.0, 5.0, 36.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-72.0, 5.0, 42.0-pz);
    glVertex3f(-66.0, 5.0, 42.0-pz);
    glVertex3f(-69.0, 12.0, 39.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-72.0, 5.0, 36.0-pz);
    glVertex3f(-66.0, 5.0, 36.0-pz);
    glVertex3f(-69.0, 12.0, 39.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-72.0, 5.0, 42.0-pz);
    glVertex3f(-72.0, 5.0, 36.0-pz);
    glVertex3f(-69.0, 12.0, 39.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-66.0, 5.0, 42.0-pz);
    glVertex3f(-66.0, 5.0, 36.0-pz);
    glVertex3f(-69.0, 12.0, 39.0-pz);
    glEnd();
    //end
}

void pohon2(int pz){
    //batang
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex3f(70.0, 0.0, 40.0-pz);
    glVertex3f(68.0, 0.0, 40.0-pz);
    glVertex3f(68.0, 5.0, 40.0-pz);
    glVertex3f(70.0, 5.0, 40.0-pz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(70.0, 0.0, 38.0-pz);
    glVertex3f(68.0, 0.0, 38.0-pz);
    glVertex3f(68.0, 5.0, 38.0-pz);
    glVertex3f(70.0, 5.0, 38.0-pz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(68.0, 0.0, 40.0-pz);
    glVertex3f(68.0, 0.0, 38.0-pz);
    glVertex3f(68.0, 5.0, 38.0-pz);
    glVertex3f(68.0, 5.0, 40.0-pz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(70.0, 0.0, 40.0-pz);
    glVertex3f(70.0, 0.0, 38.0-pz);
    glVertex3f(70.0, 5.0, 38.0-pz);
    glVertex3f(70.0, 5.0, 40.0-pz);
    glEnd();
    //end

    //daun
    glColor3f(0.68, 1.0, 0.18);
    glBegin(GL_QUADS);
    glVertex3f(72.0, 5.0, 42.0-pz);
    glVertex3f(66.0, 5.0, 42.0-pz);
    glVertex3f(66.0, 5.0, 36.0-pz);
    glVertex3f(72.0, 5.0, 36.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(72.0, 5.0, 42.0-pz);
    glVertex3f(66.0, 5.0, 42.0-pz);
    glVertex3f(69.0, 12.0, 39.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(72.0, 5.0, 36.0-pz);
    glVertex3f(66.0, 5.0, 36.0-pz);
    glVertex3f(69.0, 12.0, 39.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(72.0, 5.0, 42.0-pz);
    glVertex3f(72.0, 5.0, 36.0-pz);
    glVertex3f(69.0, 12.0, 39.0-pz);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(66.0, 5.0, 42.0-pz);
    glVertex3f(66.0, 5.0, 36.0-pz);
    glVertex3f(69.0, 12.0, 39.0-pz);
    glEnd();
    //end
}

void loopPohon(){
    int pz;
    for(pz = 0; pz < 200; pz += 10){
        pohon1(pz);
    }

    for(pz = 0; pz < 200; pz += 10){
        pohon2(pz);
    }
}

void pintuUtama(){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, 5.2);
    glVertex3f(7.0, 24.0, 5.2);
    glVertex3f(7.0, 0.0, 5.2);
    glVertex3f(-7.0, 0.0, 5.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, 5.2);
    glVertex3f(-7.0, 0.0, 5.2);
    glVertex3f(-7.0, 0.0, 5.5);
    glVertex3f(-7.0, 24.0, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(7.0, 24.0, 5.2);
    glVertex3f(7.0, 0.0, 5.2);
    glVertex3f(7.0, 0.0, 5.5);
    glVertex3f(7.0, 24.0, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, 5.2);
    glVertex3f(7.0, 24.0, 5.2);
    glVertex3f(7.0, 24.0, 5.5);
    glVertex3f(-7.0, 24.0, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 0.0, 5.2);
    glVertex3f(7.0, 0.0, 5.2);
    glVertex3f(7.0, 0.0, 5.5);
    glVertex3f(-7.0, 0.0, 5.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.6, 24.0, 5.3);
    glVertex3f(0.4, 24.0, 5.3);
    glVertex3f(0.4, 0.0, 5.3);
    glVertex3f(0.6, 0.0, 5.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 24.0, 5.3);
    glVertex3f(0.6, 0.0, 5.3);
    glVertex3f(0.6, 0.0, 5.4);
    glVertex3f(0.6, 24.0, 5.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.4, 24.0, 5.3);
    glVertex3f(0.4, 0.0, 5.3);
    glVertex3f(0.4, 0.0, 5.4);
    glVertex3f(0.4, 24.0, 5.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 24.0, 5.3);
    glVertex3f(0.4, 24.0, 5.3);
    glVertex3f(0.4, 24.0, 5.4);
    glVertex3f(0.6, 24.0, 5.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 0.0, 5.3);
    glVertex3f(0.4, 0.0, 5.3);
    glVertex3f(0.4, 0.0, 5.4);
    glVertex3f(0.6, 0.0, 5.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, 5.5);
    glVertex3f(7.0, 24.0, 5.5);
    glVertex3f(7.0, 0.0, 5.5);
    glVertex3f(-7.0, 0.0, 5.5);
    glEnd();
    //end

    //atap pintu
    glColor3f(0.83, 0.83, 0.83);
    glBegin(GL_QUADS);
    glVertex3f(-8.0, 24.0, 30.0);
    glVertex3f(8.0, 24.0, 30.0);
    glVertex3f(8.0, 24.0, 5.0);
    glVertex3f(-8.0, 24.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 25.0, 30.0);
    glVertex3f(8.0, 25.0, 30.0);
    glVertex3f(8.0, 25.0, 5.0);
    glVertex3f(-8.0, 25.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 25.0, 30.0);
    glVertex3f(8.0, 25.0, 30.0);
    glVertex3f(8.0, 24.0, 30.0);
    glVertex3f(-8.0, 24.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 25.0, 30.0);
    glVertex3f(-8.0, 25.0, 5.0);
    glVertex3f(-8.0, 24.0, 5.0);
    glVertex3f(-8.0, 24.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(8.0, 25.0, 30.0);
    glVertex3f(8.0, 25.0, 5.0);
    glVertex3f(8.0, 24.0, 5.0);
    glVertex3f(8.0, 24.0, 30.0);
    glEnd();
    //end

    //pilar
    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 24.0, 27.0);
    glVertex3f(7.0, 24.0, 25.0);
    glVertex3f(7.0, 0.0, 25.0);
    glVertex3f(7.0, 0.0, 27.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(6.0, 24.0, 27.0);
    glVertex3f(6.0, 24.0, 25.0);
    glVertex3f(6.0, 0.0, 25.0);
    glVertex3f(6.0, 0.0, 27.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(6.0, 24.0, 27.0);
    glVertex3f(7.0, 24.0, 27.0);
    glVertex3f(7.0, 0.0, 27.0);
    glVertex3f(6.0, 0.0, 27.0);
    glEnd();


    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, 27.0);
    glVertex3f(-7.0, 24.0, 25.0);
    glVertex3f(-7.0, 0.0, 25.0);
    glVertex3f(-7.0, 0.0, 27.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(-6.0, 24.0, 27.0);
    glVertex3f(-6.0, 24.0, 25.0);
    glVertex3f(-6.0, 0.0, 25.0);
    glVertex3f(-6.0, 0.0, 27.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(-6.0, 24.0, 27.0);
    glVertex3f(-7.0, 24.0, 27.0);
    glVertex3f(-7.0, 0.0, 27.0);
    glVertex3f(-6.0, 0.0, 27.0);
    glEnd();

    //end
}

void pintuBelakang(){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, -105.2);
    glVertex3f(7.0, 24.0, -105.2);
    glVertex3f(7.0, 0.0, -105.2);
    glVertex3f(-7.0, 0.0, -105.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, -105.2);
    glVertex3f(-7.0, 0.0, -105.2);
    glVertex3f(-7.0, 0.0, -105.5);
    glVertex3f(-7.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(7.0, 24.0, -105.2);
    glVertex3f(7.0, 0.0, -105.2);
    glVertex3f(7.0, 0.0, -105.5);
    glVertex3f(7.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, -105.2);
    glVertex3f(7.0, 24.0, -105.2);
    glVertex3f(7.0, 24.0, -105.5);
    glVertex3f(-7.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 0.0, -105.2);
    glVertex3f(7.0, 0.0, -105.2);
    glVertex3f(7.0, 0.0, -105.5);
    glVertex3f(-7.0, 0.0, -105.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.6, 24.0, -105.3);
    glVertex3f(0.4, 24.0, -105.3);
    glVertex3f(0.4, 0.0, -105.3);
    glVertex3f(0.6, 0.0, -105.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 24.0, -105.3);
    glVertex3f(0.6, 0.0, -105.3);
    glVertex3f(0.6, 0.0, -105.4);
    glVertex3f(0.6, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.4, 24.0, -105.3);
    glVertex3f(0.4, 0.0, -105.3);
    glVertex3f(0.4, 0.0, -105.4);
    glVertex3f(0.4, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 24.0, -105.3);
    glVertex3f(0.4, 24.0, -105.3);
    glVertex3f(0.4, 24.0, -105.4);
    glVertex3f(0.6, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 0.0, -105.3);
    glVertex3f(0.4, 0.0, -105.3);
    glVertex3f(0.4, 0.0, -105.4);
    glVertex3f(0.6, 0.0, -105.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, -105.5);
    glVertex3f(7.0, 24.0, -105.5);
    glVertex3f(7.0, 0.0, -105.5);
    glVertex3f(-7.0, 0.0, -105.5);
    glEnd();
    //end

    //atap pintu
    glColor3f(0.83, 0.83, 0.83);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 24.0, -130.0);
    glVertex3f(10.0, 24.0, -130.0);
    glVertex3f(10.0, 24.0, -105.0);
    glVertex3f(-10.0, 24.0, -105.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 25.0, -130.0);
    glVertex3f(10.0, 25.0, -130.0);
    glVertex3f(10.0, 25.0, -105.0);
    glVertex3f(-10.0, 25.0, -105.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 25.0, -130.0);
    glVertex3f(10.0, 25.0, -130.0);
    glVertex3f(10.0, 24.0, -130.0);
    glVertex3f(-10.0, 24.0, -130.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 25.0, -130.0);
    glVertex3f(-10.0, 25.0, -105.0);
    glVertex3f(-10.0, 24.0, -105.0);
    glVertex3f(-10.0, 24.0, -130.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 25.0, -130.0);
    glVertex3f(10.0, 25.0, -105.0);
    glVertex3f(10.0, 24.0, -105.0);
    glVertex3f(10.0, 24.0, -130.0);
    glEnd();
    //end

    //pilar
    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 24.0, -127.0);
    glVertex3f(7.0, 24.0, -125.0);
    glVertex3f(7.0, 0.0, -125.0);
    glVertex3f(7.0, 0.0, -127.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(6.0, 24.0, -127.0);
    glVertex3f(6.0, 24.0, -125.0);
    glVertex3f(6.0, 0.0, -125.0);
    glVertex3f(6.0, 0.0, -127.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(6.0, 24.0, -127.0);
    glVertex3f(7.0, 24.0, -127.0);
    glVertex3f(7.0, 0.0, -127.0);
    glVertex3f(6.0, 0.0, -127.0);
    glEnd();


    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 24.0, -127.0);
    glVertex3f(-7.0, 24.0, -125.0);
    glVertex3f(-7.0, 0.0, -125.0);
    glVertex3f(-7.0, 0.0, -127.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(-6.0, 24.0, -127.0);
    glVertex3f(-6.0, 24.0, -125.0);
    glVertex3f(-6.0, 0.0, -125.0);
    glVertex3f(-6.0, 0.0, -127.0);
    glEnd();

    glColor3f(0.44, 0.50, 0.56);
    glBegin(GL_QUADS);
    glVertex3f(-6.0, 24.0, -127.0);
    glVertex3f(-7.0, 24.0, -127.0);
    glVertex3f(-7.0, 0.0, -127.0);
    glVertex3f(-6.0, 0.0, -127.0);
    glEnd();
    //end
}

void jendelaBelakang(){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-20.0, 24.0, -105.2);
    glVertex3f(-14.0, 24.0, -105.2);
    glVertex3f(-14.0, 10.0, -105.2);
    glVertex3f(-20.0, 10.0, -105.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 24.0, -105.2);
    glVertex3f(-20.0, 10.0, -105.2);
    glVertex3f(-20.0, 10.0, -105.5);
    glVertex3f(-20.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-14.0, 24.0, -105.2);
    glVertex3f(-14.0, 10.0, -105.2);
    glVertex3f(-14.0, 10.0, -105.5);
    glVertex3f(-14.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 24.0, -105.2);
    glVertex3f(-14.0, 24.0, -105.2);
    glVertex3f(-14.0, 24.0, -105.5);
    glVertex3f(-20.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 10.0, -105.2);
    glVertex3f(-14.0, 10.0, -105.2);
    glVertex3f(-14.0, 10.0, -105.5);
    glVertex3f(-20.0, 10.0, -105.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-16.6, 24.0, -105.3);
    glVertex3f(-16.4, 24.0, -105.3);
    glVertex3f(-16.4, 10.0, -105.3);
    glVertex3f(-16.6, 10.0, -105.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.6, 24.0, -105.3);
    glVertex3f(-16.6, 10.0, -105.3);
    glVertex3f(-16.6, 10.0, -105.4);
    glVertex3f(-16.6, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.4, 24.0, -105.3);
    glVertex3f(-16.4, 10.0, -105.3);
    glVertex3f(-16.4, 10.0, -105.4);
    glVertex3f(-16.4, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.6, 24.0, -105.3);
    glVertex3f(-16.4, 24.0, -105.3);
    glVertex3f(-16.4, 24.0, -105.4);
    glVertex3f(-16.6, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.6, 10.0, -105.3);
    glVertex3f(-16.4, 10.0, -105.3);
    glVertex3f(-16.4, 10.0, -105.4);
    glVertex3f(-16.6, 10.0, -105.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-20.0, 24.0, -105.5);
    glVertex3f(-14.0, 24.0, -105.5);
    glVertex3f(-14.0, 10.0, -105.5);
    glVertex3f(-20.0, 10.0, -105.5);
    glEnd();
    //end
}

void jendelaBelakang2(){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(20.0, 24.0, -105.2);
    glVertex3f(14.0, 24.0, -105.2);
    glVertex3f(14.0, 10.0, -105.2);
    glVertex3f(20.0, 10.0, -105.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(20.0, 24.0, -105.2);
    glVertex3f(20.0, 10.0, -105.2);
    glVertex3f(20.0, 10.0, -105.5);
    glVertex3f(20.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(14.0, 24.0, -105.2);
    glVertex3f(14.0, 10.0, -105.2);
    glVertex3f(14.0, 10.0, -105.5);
    glVertex3f(14.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(20.0, 24.0, -105.2);
    glVertex3f(14.0, 24.0, -105.2);
    glVertex3f(14.0, 24.0, -105.5);
    glVertex3f(20.0, 24.0, -105.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(20.0, 10.0, -105.2);
    glVertex3f(14.0, 10.0, -105.2);
    glVertex3f(14.0, 10.0, -105.5);
    glVertex3f(20.0, 10.0, -105.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(16.6, 24.0, -105.3);
    glVertex3f(16.4, 24.0, -105.3);
    glVertex3f(16.4, 10.0, -105.3);
    glVertex3f(16.6, 10.0, -105.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(16.6, 24.0, -105.3);
    glVertex3f(16.6, 10.0, -105.3);
    glVertex3f(16.6, 10.0, -105.4);
    glVertex3f(16.6, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(16.4, 24.0, -105.3);
    glVertex3f(16.4, 10.0, -105.3);
    glVertex3f(16.4, 10.0, -105.4);
    glVertex3f(16.4, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(16.6, 24.0, -105.3);
    glVertex3f(16.4, 24.0, -105.3);
    glVertex3f(16.4, 24.0, -105.4);
    glVertex3f(16.6, 24.0, -105.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(16.6, 10.0, -105.3);
    glVertex3f(16.4, 10.0, -105.3);
    glVertex3f(16.4, 10.0, -105.4);
    glVertex3f(16.6, 10.0, -105.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(20.0, 24.0, -105.5);
    glVertex3f(14.0, 24.0, -105.5);
    glVertex3f(14.0, 10.0, -105.5);
    glVertex3f(20.0, 10.0, -105.5);
    glEnd();
    //end
}

void bendera(){
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-10, 25, d+20);
        glVertex3f(-5, 25, 60);
        glVertex3f(-5, 18, 60);
        glVertex3f(-10, 18, d+20);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0, 25, b+20);
        glVertex3f(5, 25, 60);
        glVertex3f(5, 18, 60);
        glVertex3f(0, 18, b+20);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0, 25, b+20);
        glVertex3f(5, 25, 60);
        glVertex3f(5, 18, 60);
        glVertex3f(0, 18, b+20);
    glEnd();

    //tiang kiri
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-5.1, 0, 60);
    glVertex3f(-4.8, 0, 60);
    glVertex3f(-4.8, 0, 59);
    glVertex3f(-5.1, 0, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.1, 25, 60);
    glVertex3f(-4.8, 25, 60);
    glVertex3f(-4.8, 25, 59);
    glVertex3f(-5.1, 25, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.1, 25, 60);
    glVertex3f(-4.8, 25, 60);
    glVertex3f(-4.8, 25, 59);
    glVertex3f(-5.1, 25, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-4.8, 0, 60);
    glVertex3f(-4.8, 25, 60);
    glVertex3f(-4.8, 25, 59);
    glVertex3f(-4.8, 0, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.1, 0, 60);
    glVertex3f(-5.1, 25, 60);
    glVertex3f(-5.1, 25, 59);
    glVertex3f(-5.1, 0, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.1, 0, 60);
    glVertex3f(-4.8, 0, 60);
    glVertex3f(-4.8, 25, 60);
    glVertex3f(-5.1, 25, 60);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.1, 0, 59);
    glVertex3f(-4.8, 0, 59);
    glVertex3f(-4.8, 25, 59);
    glVertex3f(-5.1, 25, 59);
    glEnd();
    //end

    //tiang kanan
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(5.1, 0, 60);
    glVertex3f(4.8, 0, 60);
    glVertex3f(4.8, 0, 59);
    glVertex3f(5.1, 0, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.1, 25, 60);
    glVertex3f(4.8, 25, 60);
    glVertex3f(4.8, 25, 59);
    glVertex3f(5.1, 25, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.1, 25, 60);
    glVertex3f(4.8, 25, 60);
    glVertex3f(4.8, 25, 59);
    glVertex3f(5.1, 25, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(4.8, 0, 60);
    glVertex3f(4.8, 25, 60);
    glVertex3f(4.8, 25, 59);
    glVertex3f(4.8, 0, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.1, 0, 60);
    glVertex3f(5.1, 25, 60);
    glVertex3f(5.1, 25, 59);
    glVertex3f(5.1, 0, 59);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.1, 0, 60);
    glVertex3f(4.8, 0, 60);
    glVertex3f(4.8, 25, 60);
    glVertex3f(5.1, 25, 60);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.1, 0, 59);
    glVertex3f(4.8, 0, 59);
    glVertex3f(4.8, 25, 59);
    glVertex3f(5.1, 25, 59);
    glEnd();
    //end
}

void lemari(int lx, int lz){
    glColor3f(0.55, 0.27, 0.07);
    //pinggiran kiri
    glBegin(GL_QUADS);
    glVertex3f(-20.0+lx, 0.0, -100+lz);
    glVertex3f(-20.0+lx, 20.0, -100+lz);
    glVertex3f(-20.0+lx, 20.0, -95+lz);
    glVertex3f(-20.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 0.0, -100+lz);
    glVertex3f(-21.0+lx, 20.0, -100+lz);
    glVertex3f(-21.0+lx, 20.0, -95+lz);
    glVertex3f(-21.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 0.0, -100+lz);
    glVertex3f(-21.0+lx, 20.0, -100+lz);
    glVertex3f(-21.0+lx, 20.0, -95+lz);
    glVertex3f(-21.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0+lx, 0.0, -95+lz);
    glVertex3f(-20.0+lx, 20.0, -95+lz);
    glVertex3f(-21.0+lx, 20.0, -95+lz);
    glVertex3f(-21.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0+lx, 0.0, -100+lz);
    glVertex3f(-20.0+lx, 20.0, -100+lz);
    glVertex3f(-21.0+lx, 20.0, -100+lz);
    glVertex3f(-21.0+lx, 0.0, -100+lz);
    glEnd();
    //end

    //pinggiran kanan
    glBegin(GL_QUADS);
    glVertex3f(-15.0+lx, 0.0, -100+lz);
    glVertex3f(-15.0+lx, 20.0, -100+lz);
    glVertex3f(-15.0+lx, 20.0, -95+lz);
    glVertex3f(-15.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.0+lx, 0.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -95+lz);
    glVertex3f(-16.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.0+lx, 0.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -95+lz);
    glVertex3f(-16.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-15.0+lx, 0.0, -95+lz);
    glVertex3f(-15.0+lx, 20.0, -95+lz);
    glVertex3f(-16.0+lx, 20.0, -95+lz);
    glVertex3f(-16.0+lx, 0.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-15.0+lx, 0.0, -100+lz);
    glVertex3f(-15.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 0.0, -100+lz);
    glEnd();
    //end

    //tempat buku
    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -95+lz);
    glVertex3f(-21.0+lx, 20.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 19.0, -100+lz);
    glVertex3f(-16.0+lx, 19.0, -100+lz);
    glVertex3f(-16.0+lx, 19.0, -95+lz);
    glVertex3f(-21.0+lx, 19.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 20.0, -100+lz);
    glVertex3f(-16.0+lx, 19.0, -100+lz);
    glVertex3f(-21.0+lx, 19.0, -100+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 20.0, -95+lz);
    glVertex3f(-16.0+lx, 20.0, -95+lz);
    glVertex3f(-16.0+lx, 19.0, -95+lz);
    glVertex3f(-21.0+lx, 19.0, -95+lz);
    glEnd();
    //end

    //tempat buku
    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 10.0, -100+lz);
    glVertex3f(-16.0+lx, 10.0, -100+lz);
    glVertex3f(-16.0+lx, 10.0, -95+lz);
    glVertex3f(-21.0+lx, 10.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 9.0, -100+lz);
    glVertex3f(-16.0+lx, 9.0, -100+lz);
    glVertex3f(-16.0+lx, 9.0, -95+lz);
    glVertex3f(-21.0+lx, 9.0, -95+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 10.0, -100+lz);
    glVertex3f(-16.0+lx, 10.0, -100+lz);
    glVertex3f(-16.0+lx, 9.0, -100+lz);
    glVertex3f(-21.0+lx, 9.0, -100+lz);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.0+lx, 10.0, -95+lz);
    glVertex3f(-16.0+lx, 10.0, -95+lz);
    glVertex3f(-16.0+lx, 9.0, -95+lz);
    glVertex3f(-21.0+lx, 9.0, -95+lz);
    glEnd();
    //end
}

void loopLemari(){
    int lx, lz;
    for(lx = 0; lx < 40; lx+=5){
        for(lz = 0; lz < 20; lz+=10){
            lemari(lx, lz);
        }
    }
}

void mejaKursi(){
    //meja
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 10.0, -30.0);
    glVertex3f(-5.0, 10.0, -30.0);
    glVertex3f(-5.0, 10.0, -45.0);
    glVertex3f(-10.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 10.0, -30.0);
    glVertex3f(-10.0, 0.0, -30.0);
    glVertex3f(-10.0, 0.0, -45.0);
    glVertex3f(-10.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, -45.0);
    glVertex3f(-5.0, 0.0, -45.0);
    glVertex3f(-5.0, 10.0, -45.0);
    glVertex3f(-10.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, -30.0);
    glVertex3f(-5.0, 0.0, -30.0);
    glVertex3f(-5.0, 10.0, -30.0);
    glVertex3f(-10.0, 10.0, -30.0);
    glEnd();
    //end

    //meja
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 10.0, -30.0);
    glVertex3f(5.0, 10.0, -30.0);
    glVertex3f(5.0, 10.0, -45.0);
    glVertex3f(0.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 10.0, -30.0);
    glVertex3f(0.0, 0.0, -30.0);
    glVertex3f(0.0, 0.0, -45.0);
    glVertex3f(0.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, -45.0);
    glVertex3f(5.0, 0.0, -45.0);
    glVertex3f(5.0, 10.0, -45.0);
    glVertex3f(0.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, -30.0);
    glVertex3f(5.0, 0.0, -30.0);
    glVertex3f(5.0, 10.0, -30.0);
    glVertex3f(0.0, 10.0, -30.0);
    glEnd();
    //end

    //meja
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 10.0, -30.0);
    glVertex3f(15.0, 10.0, -30.0);
    glVertex3f(15.0, 10.0, -45.0);
    glVertex3f(10.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 10.0, -30.0);
    glVertex3f(10.0, 0.0, -30.0);
    glVertex3f(10.0, 0.0, -45.0);
    glVertex3f(10.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, -45.0);
    glVertex3f(15.0, 0.0, -45.0);
    glVertex3f(15.0, 10.0, -45.0);
    glVertex3f(10.0, 10.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, -30.0);
    glVertex3f(15.0, 0.0, -30.0);
    glVertex3f(15.0, 10.0, -30.0);
    glVertex3f(10.0, 10.0, -30.0);
    glEnd();
    //end

    //kursi
    glColor3f(0.96, 0.64, 0.36);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 5.0, -30.0);
    glVertex3f(-2.0, 5.0, -30.0);
    glVertex3f(-2.0, 5.0, -45.0);
    glVertex3f(-7.0, 5.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 5.0, -30.0);
    glVertex3f(-2.0, 5.0, -30.0);
    glVertex3f(-2.0, 0.0, -30.0);
    glVertex3f(-7.0, 0.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 5.0, -45.0);
    glVertex3f(-2.0, 5.0, -45.0);
    glVertex3f(-2.0, 0.0, -45.0);
    glVertex3f(-7.0, 0.0, -45.0);
    glEnd();

    glColor3f(0.96, 0.64, 0.36);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 5.0, -30.0);
    glVertex3f(-7.0, 0.0, -30.0);
    glVertex3f(-7.0, 0.0, -45.0);
    glVertex3f(-7.0, 5.0, -45.0);
    glEnd();
    //end

    //kursi
    glColor3f(0.96, 0.64, 0.36);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 5.0, -30.0);
    glVertex3f(7.0, 5.0, -30.0);
    glVertex3f(7.0, 5.0, -45.0);
    glVertex3f(2.0, 5.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(2.0, 5.0, -30.0);
    glVertex3f(7.0, 5.0, -30.0);
    glVertex3f(7.0, 0.0, -30.0);
    glVertex3f(2.0, 0.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(2.0, 5.0, -45.0);
    glVertex3f(7.0, 5.0, -45.0);
    glVertex3f(7.0, 0.0, -45.0);
    glVertex3f(2.0, 0.0, -45.0);
    glEnd();

    glColor3f(0.96, 0.64, 0.36);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 5.0, -30.0);
    glVertex3f(2.0, 0.0, -30.0);
    glVertex3f(2.0, 0.0, -45.0);
    glVertex3f(2.0, 5.0, -45.0);
    glEnd();
    //end

    //kursi
    glColor3f(0.96, 0.64, 0.36);
    glBegin(GL_QUADS);
    glVertex3f(12.0, 5.0, -30.0);
    glVertex3f(17.0, 5.0, -30.0);
    glVertex3f(17.0, 5.0, -45.0);
    glVertex3f(12.0, 5.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(12.0, 5.0, -30.0);
    glVertex3f(17.0, 5.0, -30.0);
    glVertex3f(17.0, 0.0, -30.0);
    glVertex3f(12.0, 0.0, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(12.0, 5.0, -45.0);
    glVertex3f(17.0, 5.0, -45.0);
    glVertex3f(17.0, 0.0, -45.0);
    glVertex3f(12.0, 0.0, -45.0);
    glEnd();

    glColor3f(0.96, 0.64, 0.36);
    glBegin(GL_QUADS);
    glVertex3f(12.0, 5.0, -30.0);
    glVertex3f(12.0, 0.0, -30.0);
    glVertex3f(12.0, 0.0, -45.0);
    glVertex3f(12.0, 5.0, -45.0);
    glEnd();
    //end

}

void jendela_kelas_kanan(){
//base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -32.5);
    glVertex3f(21.2, 19.0, -35.5);
    glVertex3f(21.2, 5.0, -35.5);
    glVertex3f(21.2, 5.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -32.5);
    glVertex3f(21.5, 19.0, -32.5);
    glVertex3f(21.5, 5.0, -32.5);
    glVertex3f(21.2, 5.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -35.5);
    glVertex3f(21.5, 19.0, -35.5);
    glVertex3f(21.5, 5.0, -35.5);
    glVertex3f(21.2, 5.0, -35.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -32.5);
    glVertex3f(21.2, 19.0, -35.5);
    glVertex3f(21.5, 19.0, -35.5);
    glVertex3f(21.5, 19.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 5.0, -32.5);
    glVertex3f(21.2, 5.0, -35.5);
    glVertex3f(21.5, 5.0, -35.5);
    glVertex3f(21.5, 5.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -39.5);
    glVertex3f(21.2, 19.0, -42.5);
    glVertex3f(21.2, 5.0, -42.5);
    glVertex3f(21.2, 5.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -39.5);
    glVertex3f(21.5, 19.0, -39.5);
    glVertex3f(21.5, 5.0, -39.5);
    glVertex3f(21.2, 5.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -42.5);
    glVertex3f(21.5, 19.0, -42.5);
    glVertex3f(21.5, 5.0, -42.5);
    glVertex3f(21.2, 5.0, -42.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 19.0, -39.5);
    glVertex3f(21.2, 19.0, -42.5);
    glVertex3f(21.5, 19.0, -42.5);
    glVertex3f(21.5, 19.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(21.2, 5.0, -39.5);
    glVertex3f(21.2, 5.0, -42.5);
    glVertex3f(21.5, 5.0, -42.5);
    glVertex3f(21.5, 5.0, -39.5);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(21.5, 19.0, -32.5);
    glVertex3f(21.5, 19.0, -35.5);
    glVertex3f(21.5, 5.0, -35.5);
    glVertex3f(21.5, 5.0, -32.5);
    glEnd();
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(21.5, 19.0, -39.5);
    glVertex3f(21.5, 19.0, -42.5);
    glVertex3f(21.5, 5.0, -42.5);
    glVertex3f(21.5, 5.0, -39.5);
    glEnd();
    //end
}

void jendela_kelas_kiri(){
//base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -32.5);
    glVertex3f(-21.2, 19.0, -35.5);
    glVertex3f(-21.2, 5.0, -35.5);
    glVertex3f(-21.2, 5.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -32.5);
    glVertex3f(-21.5, 19.0, -32.5);
    glVertex3f(-21.5, 5.0, -32.5);
    glVertex3f(-21.2, 5.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -35.5);
    glVertex3f(-21.5, 19.0, -35.5);
    glVertex3f(-21.5, 5.0, -35.5);
    glVertex3f(-21.2, 5.0, -35.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -32.5);
    glVertex3f(-21.2, 19.0, -35.5);
    glVertex3f(-21.5, 19.0, -35.5);
    glVertex3f(-21.5, 19.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 5.0, -32.5);
    glVertex3f(-21.2, 5.0, -35.5);
    glVertex3f(-21.5, 5.0, -35.5);
    glVertex3f(-21.5, 5.0, -32.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -39.5);
    glVertex3f(-21.2, 19.0, -42.5);
    glVertex3f(-21.2, 5.0, -42.5);
    glVertex3f(-21.2, 5.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -39.5);
    glVertex3f(-21.5, 19.0, -39.5);
    glVertex3f(-21.5, 5.0, -39.5);
    glVertex3f(-21.2, 5.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -42.5);
    glVertex3f(-21.5, 19.0, -42.5);
    glVertex3f(-21.5, 5.0, -42.5);
    glVertex3f(-21.2, 5.0, -42.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 19.0, -39.5);
    glVertex3f(-21.2, 19.0, -42.5);
    glVertex3f(-21.5, 19.0, -42.5);
    glVertex3f(-21.5, 19.0, -39.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-21.2, 5.0, -39.5);
    glVertex3f(-21.2, 5.0, -42.5);
    glVertex3f(-21.5, 5.0, -42.5);
    glVertex3f(-21.5, 5.0, -39.5);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-21.5, 19.0, -32.5);
    glVertex3f(-21.5, 19.0, -35.5);
    glVertex3f(-21.5, 5.0, -35.5);
    glVertex3f(-21.5, 5.0, -32.5);
    glEnd();
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-21.5, 19.0, -39.5);
    glVertex3f(-21.5, 19.0, -42.5);
    glVertex3f(-21.5, 5.0, -42.5);
    glVertex3f(-21.5, 5.0, -39.5);
    glEnd();
    //end
}

void pintu_belakang_bangunan(){
//base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -50.2);
    glVertex3f(7.0, 18.0, -50.2);
    glVertex3f(7.0, 0.0, -50.2);
    glVertex3f(-7.0, 0.0, -50.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -50.2);
    glVertex3f(-7.0, 0.0, -50.2);
    glVertex3f(-7.0, 0.0, -50.5);
    glVertex3f(-7.0, 18.0, -50.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(7.0, 18.0, -50.2);
    glVertex3f(7.0, 0.0, -50.2);
    glVertex3f(7.0, 0.0, -50.5);
    glVertex3f(7.0, 18.0, -50.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -50.2);
    glVertex3f(7.0, 18.0, -50.2);
    glVertex3f(7.0, 18.0, -50.5);
    glVertex3f(-7.0, 18.0, -50.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 0.0, -50.2);
    glVertex3f(7.0, 0.0, -50.2);
    glVertex3f(7.0, 0.0, -50.5);
    glVertex3f(-7.0, 0.0, -50.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.6, 18.0, -50.3);
    glVertex3f(0.4, 18.0, -50.3);
    glVertex3f(0.4, 0.0, -50.3);
    glVertex3f(0.6, 0.0, -50.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 18.0, -50.3);
    glVertex3f(0.6, 0.0, -50.3);
    glVertex3f(0.6, 0.0, -50.4);
    glVertex3f(0.6, 18.0, -50.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.4, 18.0, -50.3);
    glVertex3f(0.4, 0.0, -50.3);
    glVertex3f(0.4, 0.0, -50.4);
    glVertex3f(0.4, 18.0, -50.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 18.0, -50.3);
    glVertex3f(0.4, 18.0, -50.3);
    glVertex3f(0.4, 18.0, -50.4);
    glVertex3f(0.6, 18.0, -50.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 0.0, -50.3);
    glVertex3f(0.4, 0.0, -50.3);
    glVertex3f(0.4, 0.0, -50.4);
    glVertex3f(0.6, 0.0, -50.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -50.5);
    glVertex3f(7.0, 18.0, -50.5);
    glVertex3f(7.0, 0.0, -50.5);
    glVertex3f(-7.0, 0.0, -50.5);
    glEnd();
    //end
}

void pintu_perpus(){
//base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -79.8);
    glVertex3f(7.0, 18.0, -79.8);
    glVertex3f(7.0, 0.0, -79.8);
    glVertex3f(-7.0, 0.0, -79.8);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -79.8);
    glVertex3f(-7.0, 0.0, -79.8);
    glVertex3f(-7.0, 0.0, -79.5);
    glVertex3f(-7.0, 18.0, -79.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(7.0, 18.0, -79.8);
    glVertex3f(7.0, 0.0, -79.8);
    glVertex3f(7.0, 0.0, -79.5);
    glVertex3f(7.0, 18.0, -79.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -79.8);
    glVertex3f(7.0, 18.0, -79.8);
    glVertex3f(7.0, 18.0, -79.5);
    glVertex3f(-7.0, 18.0, -79.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 0.0, -79.8);
    glVertex3f(7.0, 0.0, -79.8);
    glVertex3f(7.0, 0.0, -79.5);
    glVertex3f(-7.0, 0.0, -79.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.6, 18.0, -79.7);
    glVertex3f(0.4, 18.0, -79.7);
    glVertex3f(0.4, 0.0, -79.7);
    glVertex3f(0.6, 0.0, -79.7);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 18.0, -79.7);
    glVertex3f(0.6, 0.0, -79.7);
    glVertex3f(0.6, 0.0, -79.6);
    glVertex3f(0.6, 18.0, -79.6);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.4, 18.0, -79.7);
    glVertex3f(0.4, 0.0, -79.7);
    glVertex3f(0.4, 0.0, -79.6);
    glVertex3f(0.4, 18.0, -79.6);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 18.0, -79.7);
    glVertex3f(0.4, 18.0, -79.7);
    glVertex3f(0.4, 18.0, -79.6);
    glVertex3f(0.6, 18.0, -79.6);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 0.0, -79.7);
    glVertex3f(0.4, 0.0, -79.7);
    glVertex3f(0.4, 0.0, -79.6);
    glVertex3f(0.6, 0.0, -79.6);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 18.0, -79.5);
    glVertex3f(7.0, 18.0, -79.5);
    glVertex3f(7.0, 0.0, -79.5);
    glVertex3f(-7.0, 0.0, -79.5);
    glEnd();
    //end
}

void pintu_skyway(){
//pintu bangunan
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 20.1, -50.2);
    glVertex3f(7.0, 20.1, -50.2);
    glVertex3f(7.0, 29.9, -50.2);
    glVertex3f(-7.0, 29.9, -50.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 20.1, -50.2);
    glVertex3f(-7.0, 29.9, -50.2);
    glVertex3f(-7.0, 29.9, -50.5);
    glVertex3f(-7.0, 20.1, -50.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(7.0, 20.1, -50.2);
    glVertex3f(7.0, 29.9, -50.2);
    glVertex3f(7.0, 29.9, -50.5);
    glVertex3f(7.0, 20.1, -50.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 20.1, -50.2);
    glVertex3f(7.0, 20.1, -50.2);
    glVertex3f(7.0, 20.1, -50.5);
    glVertex3f(-7.0, 20.1, -50.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 29.9, -50.2);
    glVertex3f(7.0, 29.9, -50.2);
    glVertex3f(7.0, 29.9, -50.5);
    glVertex3f(-7.0, 29.9, -50.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.6, 20.1, -50.3);
    glVertex3f(0.4, 20.1, -50.3);
    glVertex3f(0.4, 29.9, -50.3);
    glVertex3f(0.6, 29.9, -50.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 20.1, -50.3);
    glVertex3f(0.6, 29.9, -50.3);
    glVertex3f(0.6, 29.9, -50.4);
    glVertex3f(0.6, 20.1, -50.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.4, 20.1, -50.3);
    glVertex3f(0.4, 29.9, -50.3);
    glVertex3f(0.4, 29.9, -50.4);
    glVertex3f(0.4, 20.1, -50.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 20.1, -50.3);
    glVertex3f(0.4, 20.1, -50.3);
    glVertex3f(0.4, 20.1, -50.4);
    glVertex3f(0.6, 20.1, -50.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 29.9, -50.3);
    glVertex3f(0.4, 29.9, -50.3);
    glVertex3f(0.4, 29.9, -50.4);
    glVertex3f(0.6, 29.9, -50.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 20.1, -50.5);
    glVertex3f(7.0, 20.1, -50.5);
    glVertex3f(7.0, 29.9, -50.5);
    glVertex3f(-7.0, 29.9, -50.5);
    glEnd();
    //end
//end
//perpus
//base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 29.9, -79.8);
    glVertex3f(7.0, 29.9, -79.8);
    glVertex3f(7.0, 20.1, -79.8);
    glVertex3f(-7.0, 20.1, -79.8);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 29.9, -79.8);
    glVertex3f(-7.0, 20.1, -79.8);
    glVertex3f(-7.0, 20.1, -79.5);
    glVertex3f(-7.0, 29.9, -79.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(7.0, 29.9, -79.8);
    glVertex3f(7.0, 20.1, -79.8);
    glVertex3f(7.0, 20.1, -79.5);
    glVertex3f(7.0, 29.9, -79.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 29.9, -79.8);
    glVertex3f(7.0, 29.9, -79.8);
    glVertex3f(7.0, 29.9, -79.5);
    glVertex3f(-7.0, 29.9, -79.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 20.1, -79.8);
    glVertex3f(7.0, 20.1, -79.8);
    glVertex3f(7.0, 20.1, -79.5);
    glVertex3f(-7.0, 20.1, -79.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.6, 29.9, -79.7);
    glVertex3f(0.4, 29.9, -79.7);
    glVertex3f(0.4, 20.1, -79.7);
    glVertex3f(0.6, 20.1, -79.7);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 29.9, -79.7);
    glVertex3f(0.6, 20.1, -79.7);
    glVertex3f(0.6, 20.1, -79.6);
    glVertex3f(0.6, 29.9, -79.6);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.4, 29.9, -79.7);
    glVertex3f(0.4, 20.1, -79.7);
    glVertex3f(0.4, 20.1, -79.6);
    glVertex3f(0.4, 29.9, -79.6);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 29.9, -79.7);
    glVertex3f(0.4, 29.9, -79.7);
    glVertex3f(0.4, 29.9, -79.6);
    glVertex3f(0.6, 29.9, -79.6);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.6, 20.1, -79.7);
    glVertex3f(0.4, 20.1, -79.7);
    glVertex3f(0.4, 20.1, -79.6);
    glVertex3f(0.6, 20.1, -79.6);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-7.0, 29.9, -79.5);
    glVertex3f(7.0, 29.9, -79.5);
    glVertex3f(7.0, 20.1, -79.5);
    glVertex3f(-7.0, 20.1, -79.5);
    glEnd();
    //end
//end
}

void tampil(void){
    glPushMatrix();

    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    gluLookAt(0.0f, 50.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    platform();
    loopJendela();
    pintuUtama();
    pintuBelakang();
    pintu_belakang_bangunan();
    pintu_perpus();
    jendelaBelakang();
    jendelaBelakang2();
    jendela_kelas_kanan();
    jendela_kelas_kiri();
    loopPohon();
    gedung_baris_depan();
    gedung_baris_2();
    gedung_setelah_depan();
    gedung_belakang_perkiraan();//iki iso dadi kelas
    gedung_tambahan();//mungkin iso dadi perpus
    hiasan1();
    pintu_skyway();
    skyway();
    atap_setengah();
    cover_atap();
    bendera();
    mejaKursi();
    loopLemari();

    glPopMatrix();
    glutSwapBuffers();
}

void idle(){
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else mouseDown = false;
}

void mouseMotion(int x, int y){
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y){
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

void ukuran(int lebar, int tinggi){
    if (tinggi == 0) {
        tinggi = 1;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
