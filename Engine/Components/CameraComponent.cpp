#include "CameraComponent.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace neu
{
    void neu::CameraComponent::Initialize()
    {
        SetViewport(viewport_size);
    }

    void neu::CameraComponent::Update()
    {
        Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(-m_owner->m_transform.position);
        Matrix3x3 mxRotation = Matrix3x3::CreateRotation(-neu::DegToRad(m_owner->m_transform.rotation));

        m_view = mxTranslation * mxRotation;

        g_renderer.SetViewMatrix(m_view);
    }

    void neu::CameraComponent::SetViewport(const Vector2& size)
    {
        Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(size * 0.5f);

        m_viewport = mxTranslation;
        g_renderer.SetViewportMatrix(m_viewport);
    }

    bool neu::CameraComponent::Write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool neu::CameraComponent::Read(const rapidjson::Value& value)
    {
        READ_DATA(value, viewport_size);

        return true;
    }

}