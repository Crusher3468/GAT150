#include "PlayerComponent.h"
#include "Framework/Game.h"
#include "Engine.h"
#include <iostream>

namespace neu
{
	void PlayerComponent::Initialize()
	{
		CharacterComponent::Initialize();
	}

	void PlayerComponent::Update()
	{
		Vector2 direction = Vector2::zero;
		if (g_inputSystem.GetKeyState(key_left) == InputSystem::State::Held)
		{
			direction = Vector2::left;
		}

		if (g_inputSystem.GetKeyState(key_right) == InputSystem::State::Held)
		{
			direction = Vector2::right;
		}

		Vector2 velocity;
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			float multiplier = (m_groundCount > 0) ? 1 : 0.2f;

			component->ApplyForce(direction * speed);
			velocity = component->velocity;

		}

		if (m_groundCount > 0 && g_inputSystem.GetKeyState(key_up) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * jump);
			}
		}
	}
	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			Event event;
			event.name = "EVENT_ADD_PONITS";
			event.data = 100;
			g_eventManager.Notify(event);

			other->SetDestroy();
		}
		
		if (other->GetTag() == "Enemy")
		{
			Event event;
			event.name = "EVENT_DAMAGE";
			event.data = damage;
			event.reciever = other;

			g_eventManager.Notify(event);
		}

		if (other->GetTag() == "Ground")
		{
			m_groundCount++;
		}
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		if (other->GetTag() == "Ground");
	}

	void PlayerComponent::OnNotify(const Event& event)
	{
		if (event.name == "EVENT_DAMAGE")
		{
			health -= std::get<float>(event.data);
			std::cout << health << std::endl;
			if (health <= 0)
			{
				Event event;
				event.name = "EVENT_PLAYER_DEAD";

				g_eventManager.Notify(event);
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		CharacterComponent::Read(value);
		READ_DATA(value, jump);

		return true;
	}
}
