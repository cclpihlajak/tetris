#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 40
#define PI 3.14159265359

// Screen buffer
char buffer[HEIGHT][WIDTH];
float zBuffer[HEIGHT][WIDTH];

// 3D point structure
typedef struct {
    float x, y, z;
} Point3D;

// Cube vertices
Point3D cube[8] = {
    {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
    {-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1}
};

// Cube edges (pairs of vertex indices)
int edges[12][2] = {
    {0,1}, {1,2}, {2,3}, {3,0},  // back face
    {4,5}, {5,6}, {6,7}, {7,4},  // front face
    {0,4}, {1,5}, {2,6}, {3,7}   // connecting edges
};

void clearBuffer() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            buffer[i][j] = ' ';
            zBuffer[i][j] = 0;
        }
    }
}

void rotateX(Point3D *p, float angle) {
    float y = p->y;
    float z = p->z;
    p->y = y * cos(angle) - z * sin(angle);
    p->z = y * sin(angle) + z * cos(angle);
}

void rotateY(Point3D *p, float angle) {
    float x = p->x;
    float z = p->z;
    p->x = x * cos(angle) + z * sin(angle);
    p->z = -x * sin(angle) + z * cos(angle);
}

void rotateZ(Point3D *p, float angle) {
    float x = p->x;
    float y = p->y;
    p->x = x * cos(angle) - y * sin(angle);
    p->y = x * sin(angle) + y * cos(angle);
}

void projectAndDraw(Point3D p, char c) {
    // Simple perspective projection
    float distance = 5.0;
    float scale = 10.0;
    float z = p.z + distance;
    
    if (z <= 0) return;  // Behind camera
    
    int x = (int)(WIDTH / 2 + (p.x * scale * distance) / z);
    int y = (int)(HEIGHT / 2 - (p.y * scale * distance) / z);
    
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        if (z > zBuffer[y][x]) {
            buffer[y][x] = c;
            zBuffer[y][x] = z;
        }
    }
}

void drawLine(Point3D p1, Point3D p2, char c) {
    // Simple line drawing using linear interpolation
    int steps = 50;
    for (int i = 0; i <= steps; i++) {
        float t = (float)i / steps;
        Point3D p;
        p.x = p1.x + (p2.x - p1.x) * t;
        p.y = p1.y + (p2.y - p1.y) * t;
        p.z = p1.z + (p2.z - p1.z) * t;
        projectAndDraw(p, c);
    }
}

void render(float angleX, float angleY, float angleZ) {
    clearBuffer();
    
    // Rotate and draw cube
    Point3D rotated[8];
    for (int i = 0; i < 8; i++) {
        rotated[i] = cube[i];
        rotateX(&rotated[i], angleX);
        rotateY(&rotated[i], angleY);
        rotateZ(&rotated[i], angleZ);
    }
    
    // Draw edges
    char chars[] = {'#', '*', '+', 'o', '.', '-', '|', '='};
    for (int i = 0; i < 12; i++) {
        int v1 = edges[i][0];
        int v2 = edges[i][1];
        char c = chars[i % 8];
        drawLine(rotated[v1], rotated[v2], c);
    }
    
    // Display buffer
    printf("\033[H\033[J");  // Clear screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(buffer[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    printf("\033[?25l");  // Hide cursor
    
    float angleX = 0, angleY = 0, angleZ = 0;
    
    while (1) {
        render(angleX, angleY, angleZ);
        
        angleX += 0.03;
        angleY += 0.02;
        angleZ += 0.01;
        
        usleep(30000);  // ~33 FPS
    }
    
    printf("\033[?25h");  // Show cursor
    return 0;
}
