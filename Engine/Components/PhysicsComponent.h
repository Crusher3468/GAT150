#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace neu
{
	class PhysicsComponent : public Component
	{

	public:
		CLASS_DECLARATION(PhysicsComponent)
		PhysicsComponent() = default;

		void Update() override;
		virtual void ApplyForce(const Vector2& force) { acceleration += force; }

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Vector2 velocity;
		Vector2 acceleration;

		float m_damping = 1;
	};
}
