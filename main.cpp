#include <GL/glut.h>
#include <cmath>
#include <vector>

struct Star { float x, y; };
std::vector<Star> stars;
float angles[9] = {0}; 
float speeds[9] = {1.5, 1.2, 1.0, 0.8, 0.6, 0.4, 0.3, 0.2, 4.0}; 
float distances[9] = {60, 90, 130, 170, 220, 280, 330, 380, 25};

void drawFilledCircle(float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (int i = 0; i <= 360; i++) {
        float rad = i * 3.14159 / 180.0;
        glVertex2f(cos(rad) * r, sin(rad) * r);
    }
    glEnd();
}

void drawPlanet(float dist, float angle, float size, float r, float g, float b, bool isMoon = false) {
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    glTranslatef(dist, 0, 0);
    glColor3f(r, g, b);
    drawFilledCircle(size);
    if (!isMoon && dist == 130) { 
        drawPlanet(25, angles[8], 4, 0.8, 0.8, 0.8, true);
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPointSize(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for (auto& s : stars) glVertex2f(s.x, s.y);
    glEnd();

    glPushMatrix();
    glTranslatef(400, 300, 0);
    
    glColor3f(1.0, 0.9, 0.0);
    drawFilledCircle(35);

    drawPlanet(60,  angles[0], 5,  0.7, 0.7, 0.7); // Mercury
    drawPlanet(90,  angles[1], 8,  1.0, 0.6, 0.0); // Venus
    drawPlanet(130, angles[2], 9,  0.0, 0.5, 1.0); // Earth
    drawPlanet(170, angles[3], 7,  1.0, 0.2, 0.0); // Mars
    drawPlanet(220, angles[4], 18, 0.8, 0.6, 0.4); // Jupiter
    drawPlanet(280, angles[5], 15, 0.9, 0.8, 0.6); // Saturn
    drawPlanet(330, angles[6], 11, 0.5, 0.8, 0.9); // Uranus
    drawPlanet(380, angles[7], 11, 0.2, 0.3, 1.0); // Neptune

    glPopMatrix();
    glutSwapBuffers();
}

void timer(int) {
    for(int i = 0; i < 9; i++) {
        angles[i] += speeds[i];
        if (angles[i] > 360) angles[i] -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glClearColor(0.0, 0.0, 0.05, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    for (int i = 0; i < 200; i++) {
        stars.push_back({(float)(rand() % 800), (float)(rand() % 600)});
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Extended Solar System");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}