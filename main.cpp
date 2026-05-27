#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	// Initialize GLFW
	glfwInit();



	// Set OpenGL version to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile = No backwards compatibility, only modern OpenGL functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create a window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Dashboard", NULL, NULL);
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
	glViewport(0, 0, 800, 800);

	// Set the clear color and clear the screen
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// Swaps front and back buffers, displaying the cleared screen
	glfwSwapBuffers(window);



	// Main loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	// Destroy window and terminate GLFW
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}