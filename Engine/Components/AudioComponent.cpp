#include "AudioComponent.h"
#include "Engine.h"

namespace neu
{
	AudioComponent::~AudioComponent()
	{
		m_channel.Stop();
	}

	void AudioComponent::Initialize()
	{
		if (m_playOnAwake)
		{
			Play();
		}
	}

	void AudioComponent::Update()
	{

	}


	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, m_soundName);
		READ_DATA(value, m_playOnAwake);
		READ_DATA(value, m_volumn);
		READ_DATA(value, m_pitch);
		READ_DATA(value, loop);

		g_audioSystem.AddAudio(m_soundName, m_soundName);

		return true;
	}

	void AudioComponent::Play()
	{
		Stop();
		m_channel = g_audioSystem.PlayAudio(m_soundName, m_volumn, m_pitch, loop);
	}

	void AudioComponent::Stop()
	{
		m_channel.Stop();
	}
}
