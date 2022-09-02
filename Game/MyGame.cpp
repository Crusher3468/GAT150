#include "MyGame.h"
#include "Engine.h"
#include "GameComponents/EnemyComponent.h"

void MyGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);

	m_scene = std::make_unique<neu::Scene>();

	rapidjson::Document document;

	std::vector<std::string> sceneNames = { "scenes/Prefabs.txt", "scenes/Tilemap.txt", "scenes/level.txt" };

	for (auto sceneName : sceneNames)
	{
		bool success = neu::json::Load(sceneName, document);
		if (!success)
		{
			LOG("error could not load scene %s", sceneName.c_str());
			continue;
		}

		m_scene->Read(document);
	}
	m_scene->Initialize();

	neu::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&MyGame::OnAddPoints, this, std::placeholders::_1));
	neu::g_eventManager.Subscribe("EVENT_PLAYER_DEAD", std::bind(&MyGame::OnAddPoints, this, std::placeholders::_1));

	m_gameState = gameState::TileScreen;
}

void MyGame::Shutdown()
{
	m_scene->RemoveAll();
}

void MyGame::Update()
{
	switch (m_gameState)	
	{
	case gameState::TileScreen:
		{
		auto component = m_scene->GetActorFromName("Title");
		if (component) component->SetActive(true);
		m_lives = 3;
		}

		if (neu::g_inputSystem.GetKeyState(neu::key_space) == neu::InputSystem::State::Held)
		{
			std::cout << "enter" << std::endl;

			m_scene->GetActorFromName("Title")->SetActive(false);

			m_gameState = gameState::startLevel;
		}
		break;

	case gameState::startLevel:
		m_scene->GetActorFromName("Score")->SetActive(true);
		m_scene->GetActorFromName("Health")->SetActive(true);

		/*for (int i = 0; i < 10; i++)
		{
			auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");
			actor->m_transform.position = { neu::randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}*/
		m_gameState = gameState::game;
		break;
	case gameState::game:
		{
			auto score = m_scene->GetActorFromName("Score");
			auto component = score->GetComponent<neu::TextComponent>();
			if (component)
			{
				component->SetText(std::to_string(m_score));
			}
		}
		{
			auto health = m_scene->GetActorFromName("Health");
			auto component = health->GetComponent<neu::TextComponent>();
			auto player = m_scene->GetActorFromName("Player");
			if (player)
			{
				auto pcomponent = player->GetComponent<neu::PlayerComponent>();
				if (component)
				{
					component->SetText(std::to_string((int)pcomponent->health));
				}
			}
		}
		break;
	case gameState::playerDead:
		m_scene->GetActorFromName("Death")->SetActive(true);

		m_stateTimer -= neu::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_scene->GetActorFromName("Death")->SetActive(false);
			m_gameState = (m_lives > 0) ? gameState::startLevel : gameState::gameOver;
		}
		break;
	case gameState::gameOver:
		break;
	default:
		break;
	}

	m_scene->Update();
}

void MyGame::Draw(neu::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnNotify(const neu::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		OnAddPoints(event);
	}

	if (event.name == "EVENT_PLAYER_DEAD")
	{
		OnPlayerDead(event);
	}
}

void MyGame::OnAddPoints(const neu::Event& event)
{
	AddScore(std::get<int>(event.data));
}

void MyGame::OnPlayerDead(const neu::Event& event)
{
	m_gameState = gameState::playerDead;
	m_lives--;
	m_stateTimer = 3;
}