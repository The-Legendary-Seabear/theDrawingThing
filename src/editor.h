#pragma once
#include "shape.h"
#include <vector>
#include <array>


class Editor {
public:
	Editor();
	~Editor();

	void update();
	void draw();

private:

	Shape* create(Shape::Type type);
	void clearAll();
	float m_size = 20;
	Shape::Type m_type = Shape::Type::Circle;
	const std::array<Color, 8> m_colors = { WHITE, GREEN, RED, BLUE, PURPLE, SKYBLUE, MAGENTA, BLACK };
	int m_colorIndex = 0;

	Shape* m_shape = nullptr;
	std::vector<Shape*> m_shapes;
};
