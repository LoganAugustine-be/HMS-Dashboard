#include "Polygon.h"

Polygon::Polygon() {
	GLfloat vertTemp[36] = {
		-0.5f,	-0.5f * float(sqrt(3)) / 3,		0.0f,	0.8f, 0.3f, 0.02f,
		0.5f,	-0.5f * float(sqrt(3)) / 3,		0.0f,	0.8f, 0.3f, 0.02f,
		0.0f,	0.5f * float(sqrt(3)) * 2 / 3,	0.0f,	1.0f, 0.6f, 0.32f,
		-0.25f,	0.5f * float(sqrt(3)) / 6,		0.0f,	0.9f, 0.45f, 0.17f,
		0.25f,	0.5f * float(sqrt(3)) / 6,		0.0f,	0.9f, 0.45f, 0.17f,
		0.0f,	-0.5f * float(sqrt(3)) / 3,		0.0f,	0.8f, 0.3f, 0.02f
	};
	for(int i = 0; i < sizeof(vertTemp)/sizeof(GLfloat); i++) {
		this->vertices.push_back(vertTemp[i]);
	}
	GLuint indTemp[9] = {
		0, 3, 5, // first triangle
		3, 2, 4,  // second triangle
		5, 4, 1   // third triangle
	};

	for(int i = 0; i < sizeof(indTemp)/sizeof(GLuint); i++) {
		this->indices.push_back(indTemp[i]);
	}
	
	this->vertData = this->vertices.data();
	this->vertSize = sizeof(std::vector<GLfloat>) + (sizeof(GLfloat) * this->vertices.size());

	this->indData = this->indices.data();
	this->indSize = sizeof(std::vector<GLuint>) + (sizeof(GLuint) * this->indices.size());

}

Polygon::Polygon(GLfloat* vertices, int verticesLength, GLuint* indices, int indicesLength)
{
	for (int i = 0; i < verticesLength; i++) {
		this->vertices.push_back(vertices[i]);
	}
	for (int i = 0; i < indicesLength; i++) {
		this->indices.push_back(indices[i]);
	}
	this->vertData = this->vertices.data();
	this->vertSize = sizeof(std::vector<GLfloat>) + (sizeof(GLfloat) * this->vertices.size());

	this->indData = this->indices.data();
	this->indSize = sizeof(std::vector<GLuint>) + (sizeof(GLuint) * this->indices.size());

}

Polygon::PolygonData Polygon::combineAllPolygonData(std::vector<Polygon> &polygons) {
	std::vector<GLfloat> allVertices;
	std::vector<GLuint> allIndices;
	for (int i = 0; i < polygons.size(); ++i) {
		for (int j = 0; j < (int)polygons[i].vertices.size(); j++) {
			allVertices.push_back(polygons[i].vertices[j]);
			if (j < (int)polygons[i].indices.size()) {
				allIndices.push_back(polygons[i].indices[j]);
			} 
		}
	}
	return { allVertices, allIndices };
}

	

	