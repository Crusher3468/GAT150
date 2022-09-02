#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"
#include "Engine.h"

void neu::ModelComponent::Update()
{
}

void neu::ModelComponent::Draw(Renderer& renderer)
{
	m_model->Draw(renderer, m_owner->m_transform);
}

bool neu::ModelComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool neu::ModelComponent::Read(const rapidjson::Value& value)
{
	std::string model_name;
	READ_DATA(value, model_name);

	m_model = g_resources.Get<Model>(model_name);

	return true;
}
