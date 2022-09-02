#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

class MyGame : public neu::Game, public neu::INotify
{
public:
	enum gameState
	{
		TileScreen,
		startLevel,
		game,
		playerDead,
		gameOver,
	};

	// Inherited via Game
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(neu::Renderer& renderer) override;

	void OnNotify(const neu::Event& event) override;
	void OnAddPoints(const neu::Event& event);
	void OnPlayerDead(const neu::Event& event);

private:
	gameState  m_gameState = gameState::TileScreen;
	float m_stateTimer = 0;
	int m_lives = 3;

};