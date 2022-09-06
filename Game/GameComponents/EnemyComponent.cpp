#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize()
{
    CharacterComponent::Initialize();
    neu::g_eventManager.Subscribe("EVENT_DROP", std::bind(&CharacterComponent::OnNotify, this, std::placeholders::_1), m_owner);
}

void EnemyComponent::Update()
{
    auto actor = m_owner->GetScene()->GetActorFromName("Player");
    if (actor)
    {
        neu::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
        neu::Vector2 force = direction.Normalized() * speed;

        auto component = m_owner->GetComponent<neu::PhysicsComponent>();
        if (component) component->ApplyForce(force);
        
        {
            auto component = m_owner->GetComponent<neu::RenderComponent>();
            if (component)
            {
                component->SetFlipHorizontal(direction.x < 0);
            }
        }
    }
}

void EnemyComponent::OnCollisionEnter(neu::Actor* other)
{
    if (other->GetTag() == "Player")
    {
        if (other->GetTag() == "Player")
        {
            neu::Event event;
            event.name = "EVENT_DAMAGE";
            event.data = damage;
            event.reciever = other;

            neu::g_eventManager.Notify(event);
        }
    }
}

void EnemyComponent::OnCollisionExit(neu::Actor* other)
{
}

void EnemyComponent::OnNotify(const neu::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
        health -= std::get<float>(event.data);
        if (health <= 0)
        {
            m_owner->SetDestroy();
        }
    }

}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}