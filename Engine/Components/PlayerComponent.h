#pragma once
#include "Framework\Component.h"
#include "Physics/Collision.h"
#include "CharacterComponent.h"

namespace neu
{
	class PlayerComponent : public CharacterComponent
	{
	public:
		CLASS_DECLARATION(PlayerComponent)
		PlayerComponent() = default;

		void Initialize() override;
		void Update() override;

		// Inherited via ICollision
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;
		virtual void OnNotify(const Event& event) override;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float jump = 300;

		int m_groundCount = 0;
	};
}