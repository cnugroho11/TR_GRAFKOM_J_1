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
    //transparansi
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //end
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
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
    glVertex3f(-10.0, 0.0, -5.0);
    glVertex3f(10.0, 0.0, -5.0);
    glVertex3f(10.0, 20.0, -5.0);
    glVertex3f(-10.0, 20.0, -5.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 5.0);
    glVertex3f(10.0, 0.0, 5.0);
    glVertex3f(10.0, 20.0, 5.0);
    glVertex3f(-10.0, 20.0, 5.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 5.0);
    glVertex3f(10.0, 0.0, -5.0);
    glVertex3f(10.0, 20.0, -5.0);
    glVertex3f(10.0, 20.0, 5.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 5.0);
    glVertex3f(-10.0, 0.0, -5.0);
    glVertex3f(-10.0, 20.0, -5.0);
    glVertex3f(-10.0, 20.0, 5.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, 5.0);
    glVertex3f(-10.0, 0.0, -5.0);
    glVertex3f(10.0, 0.0, -5.0);
    glVertex3f(10.0, 0.0, 5.0);
    glEnd();

    glColor3f(1.0, 0.65, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 20.0, 5.0);
    glVertex3f(-10.0, 20.0, -5.0);
    glVertex3f(10.0, 20.0, -5.0);
    glVertex3f(10.0, 20.0, 5.0);
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

void gedung_baris_2(){
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

void gedung_setelah_depan(){

    //gedung tengah
    glColor3f(1.0, 0.0, 0.0);
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
    glColor3f(1.0, 0.0, 1.0);
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
    glColor3f(1.0, 0.0, 1.0);
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
    glColor3f(1.0, 1.0, 0.0);
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
    glColor3f(1.0, 1.0, 0.0);
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
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-20.0, 0.0, -50.0);
    glVertex3f(20.0, 0.0, -50.0);
    glVertex3f(20.0, 30.0, -50.0);
    glVertex3f(-20.0, 30.0, -50.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 0.0, -25.0);
    glVertex3f(20.0, 0.0, -25.0);
    glVertex3f(20.0, 30.0, -25.0);
    glVertex3f(-20.0, 30.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(20.0, 0.0, -25.0);
    glVertex3f(20.0, 0.0, -50.0);
    glVertex3f(20.0, 30.0, -50.0);
    glVertex3f(20.0, 30.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 0.0, -25.0);
    glVertex3f(-20.0, 0.0, -50.0);
    glVertex3f(-20.0, 30.0, -50.0);
    glVertex3f(-20.0, 30.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 0.0, -25.0);
    glVertex3f(-20.0, 0.0, -20.0);
    glVertex3f(20.0, 0.0, -20.0);
    glVertex3f(20.0, 0.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-20.0, 30.0, -25.0);
    glVertex3f(-20.0, 30.0, -50.0);
    glVertex3f(20.0, 30.0, -50.0);
    glVertex3f(20.0, 30.0, -25.0);
    glEnd();
    //gedung belakang tengah end
}

void jendelaKiriDepan (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 19.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 19.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 16.0 -yy, 10.2);
    glVertex3f(-30.0+xx, 16.0 -yy, 10.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 19.0 -yy, 10.2);
    glVertex3f(-30.0+xx, 16.0 -yy, 10.2);
    glVertex3f(-30.0+xx, 16.0 -yy, 10.5);
    glVertex3f(-30.0+xx, 19.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-27.0+xx, 19.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 16.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 16.0 -yy, 10.5);
    glVertex3f(-27.0+xx, 19.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 19.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 19.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 19.0 -yy, 10.5);
    glVertex3f(-30.0+xx, 19.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 16.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 16.0 -yy, 10.2);
    glVertex3f(-27.0+xx, 16.0 -yy, 10.5);
    glVertex3f(-30.0+xx, 16.0 -yy, 10.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 19.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 19.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 16.0 -yy, 10.3);
    glVertex3f(-28.6+xx, 16.0 -yy, 10.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 19.0 -yy, 10.3);
    glVertex3f(-28.6+xx, 16.0 -yy, 10.3);
    glVertex3f(-28.6+xx, 16.0 -yy, 10.4);
    glVertex3f(-28.6+xx, 19.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.4+xx, 19.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 16.0 -yy, 10.3);
    glVertex3f(-28.4+xx, 16.0 -yy, 10.4);
    glVertex3f(-28.4+xx, 19.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 19.0-yy, 10.3);
    glVertex3f(-28.4+xx, 19.0-yy, 10.3);
    glVertex3f(-28.4+xx, 19.0-yy, 10.4);
    glVertex3f(-28.6+xx, 19.0-yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-28.6+xx, 16.0-yy, 10.3);
    glVertex3f(-28.4+xx, 16.0-yy, 10.3);
    glVertex3f(-28.4+xx, 16.0-yy, 10.4);
    glVertex3f(-28.6+xx, 16.0-yy, 10.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-30.0+xx, 19.0-yy, 10.5);
    glVertex3f(-27.0+xx, 19.0-yy, 10.5);
    glVertex3f(-27.0+xx, 16.0-yy, 10.5);
    glVertex3f(-30.0+xx, 16.0-yy, 10.5);
    glEnd();
    //end
}

void jendelaKananDepan (int yy, int xx){

        //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 19.0 -yy, 10.2);
    glVertex3f(27.0-xx, 19.0 -yy, 10.2);
    glVertex3f(27.0-xx, 16.0 -yy, 10.2);
    glVertex3f(30.0-xx, 16.0 -yy, 10.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 19.0 -yy, 10.2);
    glVertex3f(30.0-xx, 16.0 -yy, 10.2);
    glVertex3f(30.0-xx, 16.0 -yy, 10.5);
    glVertex3f(30.0-xx, 19.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(27.0-xx, 19.0 -yy, 10.2);
    glVertex3f(27.0-xx, 16.0 -yy, 10.2);
    glVertex3f(27.0-xx, 16.0 -yy, 10.5);
    glVertex3f(27.0-xx, 19.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 19.0 -yy, 10.2);
    glVertex3f(27.0-xx, 19.0 -yy, 10.2);
    glVertex3f(27.0-xx, 19.0 -yy, 10.5);
    glVertex3f(30.0-xx, 19.0 -yy, 10.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 16.0 -yy, 10.2);
    glVertex3f(27.0-xx, 16.0 -yy, 10.2);
    glVertex3f(27.0-xx, 16.0 -yy, 10.5);
    glVertex3f(30.0-xx, 16.0 -yy, 10.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 19.0 -yy, 10.3);
    glVertex3f(28.4-xx, 19.0 -yy, 10.3);
    glVertex3f(28.4-xx, 16.0 -yy, 10.3);
    glVertex3f(28.6-xx, 16.0 -yy, 10.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 19.0 -yy, 10.3);
    glVertex3f(28.6-xx, 16.0 -yy, 10.3);
    glVertex3f(28.6-xx, 16.0 -yy, 10.4);
    glVertex3f(28.6-xx, 19.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.4-xx, 19.0 -yy, 10.3);
    glVertex3f(28.4-xx, 16.0 -yy, 10.3);
    glVertex3f(28.4-xx, 16.0 -yy, 10.4);
    glVertex3f(28.4-xx, 19.0 -yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 19.0-yy, 10.3);
    glVertex3f(28.4-xx, 19.0-yy, 10.3);
    glVertex3f(28.4-xx, 19.0-yy, 10.4);
    glVertex3f(28.6-xx, 19.0-yy, 10.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(28.6-xx, 16.0-yy, 10.3);
    glVertex3f(28.4-xx, 16.0-yy, 10.3);
    glVertex3f(28.4-xx, 16.0-yy, 10.4);
    glVertex3f(28.6-xx, 16.0-yy, 10.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(30.0-xx, 19.0-yy, 10.5);
    glVertex3f(27.0-xx, 19.0-yy, 10.5);
    glVertex3f(27.0-xx, 16.0-yy, 10.5);
    glVertex3f(30.0-xx, 16.0-yy, 10.5);
    glEnd();
    //end
}

void jendelaKananMentokDepan (int yy, int xx){
    //base jendela
    glColor4f(0, 0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 20.0 -yy, 0.2);
    glVertex3f(42.0-xx, 20.0 -yy, 0.2);
    glVertex3f(42.0-xx, 17.0 -yy, 0.2);
    glVertex3f(45.0-xx, 17.0 -yy, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 20.0 -yy, 0.2);
    glVertex3f(45.0-xx, 17.0 -yy, 0.2);
    glVertex3f(45.0-xx, 17.0 -yy, 0.5);
    glVertex3f(45.0-xx, 20.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(42.0-xx, 20.0 -yy, 0.2);
    glVertex3f(42.0-xx, 17.0 -yy, 0.2);
    glVertex3f(42.0-xx, 17.0 -yy, 0.5);
    glVertex3f(42.0-xx, 20.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 20.0 -yy, 0.2);
    glVertex3f(42.0-xx, 20.0 -yy, 0.2);
    glVertex3f(42.0-xx, 20.0 -yy, 0.5);
    glVertex3f(45.0-xx, 20.0 -yy, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 17.0 -yy, 0.2);
    glVertex3f(42.0-xx, 17.0 -yy, 0.2);
    glVertex3f(42.0-xx, 17.0 -yy, 0.5);
    glVertex3f(45.0-xx, 17.0 -yy, 0.5);
    glEnd();
    //end

    //teralis tengah
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 20.0 -yy, 0.3);
    glVertex3f(43.4-xx, 20.0 -yy, 0.3);
    glVertex3f(43.4-xx, 17.0 -yy, 0.3);
    glVertex3f(43.6-xx, 17.0 -yy, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 20.0 -yy, 0.3);
    glVertex3f(43.6-xx, 17.0 -yy, 0.3);
    glVertex3f(43.6-xx, 17.0 -yy, 0.4);
    glVertex3f(43.6-xx, 20.0 -yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.4-xx, 20.0 -yy, 0.3);
    glVertex3f(43.4-xx, 17.0 -yy, 0.3);
    glVertex3f(43.4-xx, 17.0 -yy, 0.4);
    glVertex3f(43.4-xx, 20.0 -yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 20.0-yy, 0.3);
    glVertex3f(43.4-xx, 20.0-yy, 0.3);
    glVertex3f(43.4-xx, 20.0-yy, 0.4);
    glVertex3f(43.6-xx, 20.0-yy, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43.6-xx, 17.0-yy, 0.3);
    glVertex3f(43.4-xx, 17.0-yy, 0.3);
    glVertex3f(43.4-xx, 17.0-yy, 0.4);
    glVertex3f(43.6-xx, 17.0-yy, 0.4);
    glEnd();
    //end

    //kaca
    glColor4f(1, 1, 1, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(45.0-xx, 20.0-yy, 0.5);
    glVertex3f(42.0-xx, 20.0-yy, 0.5);
    glVertex3f(42.0-xx, 17.0-yy, 0.5);
    glVertex3f(45.0-xx, 17.0-yy, 0.5);
    glEnd();
    //end
}

void gedung_tambahan(){
    //gedung
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
    glColor3f(1.0, 0.0, 1.0);
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
    glColor3f(1.0, 0.0, 1.0);
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

    //loop jendela depan kiri
    int yj,xj;
    for(xj = 0; xj <= 15; xj += 5){
        for(yj = 0; yj < 15; yj += 5){
            jendelaKiriDepan(xj, yj);
        }
    }
    //end loop

    //loop jendela depan kanan
    for(xj = 0; xj <= 15; xj += 5){
        for(yj = 0; yj < 15; yj += 5){
            jendelaKananDepan(xj, yj);
        }
    }
    //end loop

    //loop jendela kanan mentok depan
    for(xj = 0; xj <= 15; xj += 5){
        for(yj = 0; yj <= 15; yj += 5){
            jendelaKananMentokDepan(xj, yj);
        }
    }
    //end loop


    gedung_baris_depan();
    gedung_baris_2();
    gedung_setelah_depan();
    gedung_belakang_perkiraan();//iki iso dadi kelas
    gedung_tambahan();//mungkin iso dadi perpus
    hiasan1();

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
