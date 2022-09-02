#include "PhysicsComponent.h"
#include "Engine.h"

void neu::PhysicsComponent::Update()
{
	velocity += acceleration * g_time.deltaTime;
	m_owner->m_transform.position += velocity * g_time.deltaTime;

	velocity *= m_damping;
	acceleration = Vector2::zero;
}

bool neu::PhysicsComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool neu::PhysicsComponent::Read(const rapidjson::Value& value)
{
	READ_DATA(value, m_damping);
	READ_DATA(value, acceleration);
	READ_DATA(value, velocity);

	return true;
}
