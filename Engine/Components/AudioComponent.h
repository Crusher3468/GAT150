#pragma once
#include "Framework\Component.h"
#include "Audio/AudioChannel.h"

namespace neu
{
	class Actor;

	class AudioComponent : public Component
	{
	public:
		CLASS_DECLARATION(AudioComponent)

		AudioComponent() = default;
		~AudioComponent();

		void Play();
		void Stop();

		void Initialize() override;
		void Update() override;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		AudioChannel m_channel;

		std::string m_soundName;
		bool m_playOnAwake = false;
		float m_volumn = 1;
		float m_pitch = 1;
		bool loop = false;
	};
}