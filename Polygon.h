#ifndef POLYGON_H
#define POLYGON_H

#include <glad/glad.h>
#include <iostream>
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include <vector>
#include <map>

class Polygon
{
	private:

	protected:
		// Creates a Struct that holds the Polygon class data
		// This allows the data to be returnable from a method as needed
		// Which can be seen in the method combineAllPolygonData
		struct PolygonData {

			std::vector<GLfloat> vertices;
			std::vector<GLuint> indices;
		};

	public:
		PolygonData data;

		// Holds the Vertices data which is all stored as float values formatted as follows:
		//	|		POSITION		|	|		COLOR		|	|
		//		X,		Y,		Z,			R,	  G,	B,
		std::vector<GLfloat> vertices;
		GLfloat* vertData;
		size_t vertSize;
		// Holds the Indices data which determines the order vertices are connected
		// This is important for complex shapes as it can limit the number of vertices required improving performance
		std::vector<GLuint> indices;
		GLuint* indData;
		size_t indSize;

		Polygon();
		Polygon(GLfloat* vertices, int verticesLength, GLuint* indices, int indicesLength);

		// Combines all of the vertice and indice values from the polygons array into two vectors: allVertices and allIndices
		// Then returns a PolygonData struct formatted as { allVertices, allIndices }
		// Runs O(n) || I think ||
		PolygonData combineAllPolygonData(std::vector<Polygon> &polygons);
};

#endif