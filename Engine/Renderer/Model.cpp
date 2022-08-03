#include "Model.h"
#include "../Core/File.h"
#include<sstream>
#include<iostream>

namespace neu
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}

	void Model::Draw(neu::Renderer& renderer, const Vector2& position, float angle, float scale)
	{
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			Vector2 p2 = Vector2::Rotate((m_points[static_cast<std::vector<neu::Vector2, std::allocator<neu::Vector2>>::size_type>(i) + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Load(const std::string& filename)
	{
		std::string buffer;

		ReadFile(filename, buffer);

		std::istringstream stream(buffer);
		stream >> m_color;
		std::string line;
		std::getline(stream, line);

		size_t numpoints = std::stoi(line);

		for (size_t i = 0; i < numpoints; i++)
		{
			Vector2 point;

			stream >> point;

			m_points.push_back(point);
		}
	}
	float Model::CalculateRadius()
	{
		float radius = 0;

		for (auto& point : m_points)
		{
			if (point.Length() > radius) radius = point.Length();
		}

		return radius;
	}
}
