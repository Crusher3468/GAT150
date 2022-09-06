#include "Engine.h"
#include "MyGame.h"
#include <iostream>

int main()
{
	neu::InitializeMemory();
	neu::SetFilePath("../Assets");

	neu::g_renderer.Initialize();
	neu::g_inputSystem.Initialize();
	neu::g_audioSystem.Initialize();
	neu::g_resources.Initialize();
	neu::g_physicsSystem.Initialize();
	neu::g_eventManager.Initialize();

	neu::Engine::Instance().Register();

	neu::g_renderer.CreateWindow("Neumont", 800, 600);
	neu::g_renderer.SetClearColor(neu::Color{ 60, 60, 60, 255 });


	std::unique_ptr<MyGame> game = std::make_unique<MyGame>();
	game->Initialize();

	bool quit = false;
		while (!quit)
		{
			neu::g_time.Tick();
			neu::g_inputSystem.Update();
			neu::g_audioSystem.Update();
			neu::g_physicsSystem.Update();
			neu::g_eventManager.Update();

			if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;
			if (neu::g_inputSystem.GetKeyDown(neu::key_restart))
			{
				neu::g_physicsSystem.Shutdown();
				neu::g_resources.Shutdown();
				neu::g_renderer.Shutdown();
				neu::g_audioSystem.Shutdown();
				neu::g_inputSystem.Shutdown();
				neu::g_eventManager.Shutdown();
				
				main();
			}

			game->Update();

			neu::g_renderer.BeginFrame();

			game->Draw(neu::g_renderer);
			
			neu::g_renderer.EndFrame();
		}

		game->Shutdown();
		game.reset();

		neu::Factory::Instance().Shutdown();

		neu::g_physicsSystem.Shutdown();
		neu::g_resources.Shutdown();
		neu::g_renderer.Shutdown();
		neu::g_audioSystem.Shutdown();
		neu::g_inputSystem.Shutdown();
		neu::g_eventManager.Shutdown();

}