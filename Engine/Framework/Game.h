#pragma once
#include <memory>

namespace neu
{
	class Renderer;
	class Scene;

	class Game
	{
	public:
		Game() = default;
		virtual ~Game() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;

		int GetScore() { return m_score; }
		int GetHealth() { return m_phealth; }
		int AddScore(int points) { return m_score += points; }
		int CalcHealth(int damage) { return m_phealth -= damage; }

	protected:
		int m_score = 0;
		int m_phealth = 0;
		std::unique_ptr<Scene>m_scene;
	};
}