#pragma once
#include "Math/Vector2.h"
#include "Math/Color.h"
#include<vector>
#include "Base/System.h"

namespace jc
{

	class ParticleSystem : public GraphicsSystem
	{
	private:
		struct Particle
		{
			Vector2 position;
			Vector2 prevposition;
			Vector2 velocity;
			Color color;
			float lifetime;
			bool isActive{false};

			static bool IsNotActive(Particle particle) { return particle.isActive == false; }
		};

	public:
		void Startup() override;
		void Shutdown() override;

		void Update(float dt) override;
		void Draw(Core::Graphics& graphics) override;

		void Create(const Vector2& position, size_t count, float lifetime, const Color& color, float speed);
		void Create(const Vector2& position, size_t count, float lifetime, const std::vector<Color>& colors, float speed,float angle,float angleRange);

	private:
		std::vector<Particle> particles;
	};

}