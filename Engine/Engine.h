#pragma once
#include "Audio/AudioSystem.h"
#include "Base/Actor.h"
#include "Base/Scene.h"

#include"Graphics/ParticleSystem.h"
#include "Graphics/Shape.h"

#define NOMINMAX

#include "Math/Color.h"
#include "Math/Vector2.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/Random.h"
#include "core.h"

#include<vector>
#include<memory>
#include<algorithm>
#include "Framework/EventSystem.h"
#include "Framework/ResourceSystem.h"

namespace jc
{
	class Engine
	{
	public:
		void Startup();
		void Shutdown();
		
		void Update(float dt);
		void Draw(Core::Graphics& graphics);

		template<typename T>
		T* Get();

	private:
		std::vector<std::unique_ptr<System>> systems;

	};
	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if(dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}
		return nullptr;
	}
}