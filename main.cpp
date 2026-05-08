#include <GL/glut.h>
#include <cmath>

float earthAngle = 0.0f;
float moonAngle = 0.0f;

// Midpoint Circle Algorithm from Lecture 5
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;
    glBegin(GL_POINTS);
    while (x <= y) {
        glVertex2i(xc + x, yc + y); glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y); glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x); glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x); glVertex2i(xc - y, yc - x);
        x++;
        if (p < 0) p += 2 * x + 1;
        else { y--; p += 2 * (x - y) + 1; }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 1. Draw Static Sun (Yellow)
    glColor3f(1.0, 1.0, 0.0);
    drawCircle(400, 300, 40);

    // 2. Earth Transformation (Orbiting the Sun)
    glPushMatrix();
        glTranslatef(400, 300, 0);      // Move to Sun's center
        glRotatef(earthAngle, 0, 0, 1); // Orbit rotation
        glTranslatef(200, 0, 0);        // Earth's distance from Sun
        
        glColor3f(0.0, 0.5, 1.0);       // Blue Earth
        drawCircle(0, 0, 20);

        // 3. Moon Transformation (Orbiting the Earth)
        // Since we are inside the Earth's Matrix, (0,0) is now the Earth's center
        glPushMatrix();
            glRotatef(moonAngle, 0, 0, 1); // Moon's rotation around Earth
            glTranslatef(40, 0, 0);        // Moon's distance from Earth
            
            glColor3f(0.8, 0.8, 0.8);      // Grey Moon
            drawCircle(0, 0, 8);
        glPopMatrix(); 

    glPopMatrix(); // Back to Global coordinates

    glutSwapBuffers();
}

void timer(int) {
    earthAngle += 0.5f; // Earth moves slower
    moonAngle += 2.0f;  // Moon moves faster around Earth
    
    if (earthAngle > 360) earthAngle -= 360;
    if (moonAngle > 360) moonAngle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glClearColor(0.0, 0.0, 0.05, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Earth-Moon Orbit System");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}