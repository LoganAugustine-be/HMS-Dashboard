#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

class VAO
{
	public:
		// ID reference for VAO
		GLuint ID;
		// Constructor that generates a VAO
		VAO();

		// Links a VBO attribut to the VAO
		void LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type,  GLsizeiptr stride, void* offset);
		// Binds the VAO
		void Bind();
		// Unbinds the VAO
		void Unbind();
		// Deletes the VAO
		void Delete();

};

#endif