#include "Config.h"
#include <vector>
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Polygon.h"



GLFWwindow* window;

Polygon BackgroundFrame;

GLfloat vertices[] = {
		 20.0f,  20.0f, 0.0f, 0.5f, 0.8f, 0.2f, // top right
		 20.0f, 0.0f, 0.0f, 0.5f, 0.8f, 0.2f, // bottom right
		 0.0f,  0.0f, 0.0f, 0.5f, 0.8f, 0.2f, // bottom left
		 0.0f,  20.0f, 0.0f, 0.5f, 0.8f, 0.2f, // top left 
};
GLuint indices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
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


	std::vector<Polygon> allPolygons;
	
	Polygon polygon1 = Polygon(vertices, sizeof(vertices)/sizeof(*vertices), indices, 6);
	allPolygons.push_back((Polygon)polygon1);

	Polygon polygon2;
	allPolygons.push_back((Polygon)polygon2);


	BackgroundFrame.data = BackgroundFrame.combineAllPolygonData(allPolygons);
	BackgroundFrame.vertices = BackgroundFrame.data.vertices;
	BackgroundFrame.indices = BackgroundFrame.data.indices;

	Shader shaderProgram("default.vert", "default.frag");



	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(BackgroundFrame.vertices.data(), BackgroundFrame.vertices.size());
	EBO EBO1(BackgroundFrame.indices.data(), BackgroundFrame.indices.size());
	
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3*sizeof(float)));
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
		//Draw the triangle using the GL_TRIANGLES primitive, with 0 vertices offset and 3 vertices to draw
		glDrawElements(GL_TRIANGLES, BackgroundFrame.indices.size(), GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		// Handle all GLFW events
		glfwPollEvents();
	}

	// De-allocate all resources once they've outlived their purpose
	/*VAO1.Delete();
	VBO1.Delete();	
	EBO1.Delete();*/
	shaderProgram.Delete();

	
	// Destroy window and terminate GLFW
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}