#include "Config.h"

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"


GLFWwindow* window;

// Vertecies Coordinates
GLfloat vertices[] = {
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
};

// Indices for vertices order
GLuint indices[] = {
		0, 3, 5, // first triangle
		3, 2, 4,  // second triangle
		5, 4, 1   // third triangle
};

int main() {
	// Initialize GLFW
	glfwInit();
	// Set OpenGL version to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile = No backwards compatibility, only modern OpenGL functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create a window
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	// Check if window creation was successful
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Make the window display to screen
	glfwMakeContextCurrent(window);

	// Load OpenGL function pointers using GLAD
	gladLoadGL();

	// Set the viewport to cover the new window
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	// Main loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1], BACKGROUND_COLOR[2], BACKGROUND_COLOR[3]);
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGl to use the Shader Program we created
		shaderProgram.Activate();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw the triangle using the GL_TRIANGLES primitive, with 0 vertices offset and 3 vertices to draw
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		// Handle all GLFW events
		glfwPollEvents();
	}

	// De-allocate all resources once they've outlived their purpose
	VAO1.Delete();
	VBO1.Delete();	
	EBO1.Delete();
	shaderProgram.Delete();

	// Destroy window and terminate GLFW
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}