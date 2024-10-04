#include <GLFW/glfw3.h>
#include <math.h>

// Function to draw a circle
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)num_segments; // Angle in radians
        float x = r * cosf(theta); // Calculate the x component
        float y = r * sinf(theta); // Calculate the y component
        glVertex2f(x + cx, y + cy); // Output the vertex
    }
    glEnd();
}

int main(void) {
    // Initialize the library
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Circle Drawing", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render here, e.g. using OpenGL commands
        glClear(GL_COLOR_BUFFER_BIT);

        // Set up coordinate system for 2D drawing
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-320, 320, -240, 240, -1, 1); // Set orthogonal 2D view (adjust the values for different sizes)

        // Set up the circle's properties and draw it
        glColor3f(1.0, 1.0, 1.0); // White color
        drawCircle(0, 0, 100, 100); // Draw a circle at (0, 0) with radius 100 and 100 segments

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
