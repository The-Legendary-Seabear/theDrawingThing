#include "editor.h"
#include "square.h"
#include "circle.h"

Editor::Editor()
{
	m_shape = create(m_type);
}

Editor::~Editor()
{
	clearAll();
	delete m_shape;
}

void Editor::update()
{
	if (IsKeyDown(KEY_RIGHT)) { 
		m_size += 0.5f; 
		m_size = std::min(m_size, 300.0f);
	}
	if (IsKeyDown(KEY_LEFT)) { 
		m_size -= 0.5f; 
		m_size = std::max(m_size, 1.0f);

		if (IsKeyPressed(KEY_UP)) {
			m_colorIndex = ++m_colorIndex % m_colors.size();
			m_shape->setColor(m_colors[m_colorIndex]);
		}
	}

	m_shape->setSize(m_size);

	if (IsKeyPressed(KEY_TAB)) {
		m_type = static_cast<Shape::Type>((static_cast<int>(m_type) + 1) % static_cast<int>(Shape::Type::NumShapes));
		delete m_shape;
		m_shape = create(m_type);
	}

	if (IsKeyPressed(KEY_Z)) clearAll();

	if (IsMouseButtonPressed(0) || (IsMouseButtonDown(0) && IsKeyDown(KEY_LEFT_CONTROL))) {
		m_shapes.push_back(m_shape);
		Shape* shape = create(m_type);
	}
	m_shape->setPosition(GetMousePosition());
	m_shape->update();
	for (auto shape : m_shapes) {
		shape->update();
	}
}

void Editor::draw()
{
	//draw editor shapes
	for (auto shape : m_shapes) {
		shape->draw();

	}
	//draw current shape
	m_shape->draw();
}

Shape* Editor::create(Shape::Type type)
{
	Shape* shape = nullptr;

	switch (type)
	{
	case Shape::Type::Circle:
		shape = new Circle(GetMousePosition(), m_size, m_colors[m_colorIndex]);
		break;
	case Shape::Type::Square:
		shape = new Square(GetMousePosition(), m_size, m_colors[m_colorIndex]);
		break;
	default:
		break;
	}
	return shape;
}

void Editor::clearAll()
{
	for (auto shape : m_shapes) {
		delete shape;
	}
	m_shapes.clear();
}
