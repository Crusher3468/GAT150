#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"

struct SDL_Renderer;
struct SDL_Window;

namespace neu
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		void Initialize();
		void Shutdown();

		void CreateWindow(const char* name, int width, int height);
		void BeginFrame();
		void EndFrame();
		void SetClearColor(const Color color) { m_clearColor = color; }

		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(float x, float y);
		void DrawLine(const neu::Vector2& v1, const neu::Vector2& v2, const neu::Color& color);
		void DrawPoint(const neu::Vector2& v, const neu::Color& color);

		int GetWidth() { return m_width; }
		int GetHeight() { return m_height; }

		friend class Text;
		friend class Texture;

	private:
		int m_width = 0;
		int m_height = 0;

		Color m_clearColor{0, 0, 0, 255};

		SDL_Renderer* m_renderer{ nullptr };
		SDL_Window* m_window{ nullptr };
	};

}