#include"Engine.h"

namespace neu
{
	InputSystem g_inputSystem;
	Time g_time;
	Renderer g_renderer;
	AudioSystem g_audioSystem;
	ResourceManager g_resources;
	PhysicsSystem g_physicsSystem;
	EventManager g_eventManager;

	void Engine::Register()
	{
			REGISTER_CLASS(Actor);
			REGISTER_CLASS(AudioComponent);
			REGISTER_CLASS(ModelComponent);
			REGISTER_CLASS(PhysicsComponent);
			REGISTER_CLASS(PlayerComponent);
			REGISTER_CLASS(SpriteComponent);
			REGISTER_CLASS(SpriteAnimComponent);
			REGISTER_CLASS(RBPhysicsComponent);
			REGISTER_CLASS(CollisionComponent);
			REGISTER_CLASS(TilemapComponent);
			REGISTER_CLASS(TextComponent);
			REGISTER_CLASS(CameraComponent);
	}
}