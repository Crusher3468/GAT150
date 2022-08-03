#include "Engine.h"

int main()
{
	int i = 10;
	float f = 3.5f;
	bool b = true;
	const char* s = "ethan!!!";

	printf("hello World %d %.2f %b %s  \n", i, f, b, s);

	neu::InitializeMemory();
	neu::SetFilePath("../Assets");

	neu::g_renderer.Initialize();
	neu::g_inputSystem.Initialize();
	neu::g_audioSystem.Initialize();

	neu::g_renderer.CreateWindow("Neumont", 800, 600);
	neu::g_renderer.SetClearColor(neu::Color{ 60, 60, 60, 255 });

	bool quit = false;
		while (!quit)
		{
			neu::g_time.Tick();
			neu::g_inputSystem.Update();
			neu::g_audioSystem.Update();

			if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;
			if (neu::g_inputSystem.GetKeyDown(neu::key_restart))
			{
				neu::g_renderer.Shutdown();
				neu::g_audioSystem.Shutdown();
				neu::g_inputSystem.Shutdown();
				main();
			}

			neu::g_renderer.BeginFrame();

			neu::g_renderer.EndFrame();
		}
		
		neu::g_renderer.Shutdown();
		neu::g_audioSystem.Shutdown();
		neu::g_inputSystem.Shutdown();

}