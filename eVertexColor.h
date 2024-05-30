#pragma once

enum eVertexColor
{
	WHITE, // Vertex has not been visited yet
	GREY, // Vertex is being visited (discovered but not fully explored)
	BLACK // Vertex and all its neighbors have been fully explored
};