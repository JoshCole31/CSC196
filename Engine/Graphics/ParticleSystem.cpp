#include "ParticleSystem.h"
#include"Math/Random.h"
namespace jc 
{

	void ParticleSystem::Startup()
	{
		particles.resize(3000);
	}

	void ParticleSystem::Shutdown()
	{
		particles.clear();
	}

	void ParticleSystem::Update(float dt)
	{
		for (Particle& particle : particles)
		{
			if (particle.isActive)
			{
				particle.lifetime -= dt;
				particle.isActive = particle.lifetime > 0;
				particle.prevposition = particle.position;
				particle.position += particle.velocity * dt;
		
			}
		}

	}

	void ParticleSystem::Draw(Core::Graphics& graphics)
	{
		for (const Particle& particle : particles)
		{
			if (particle.isActive) 
			{
			graphics.SetColor(particle.color);
			graphics.DrawLine(particle.position.x, particle.position.y, particle.prevposition.x, particle.prevposition.y);
			}

		}

	}

	void ParticleSystem::Create(const Vector2& position, size_t count, float lifetime, const Color& color, float speed)
	{
		for (size_t i = 0; i < count;i++)
		{
			auto particle = std::find_if(particles.begin(), particles.end(),Particle::IsNotActive);
			if (particle != particles.end()) 
			{
				particle->isActive = true;
				particle->lifetime = lifetime;
				particle->position = position;
				particle->prevposition = position;
				particle->color = color;

				particle->velocity = Vector2{ RandomRange(-1,1),RandomRange(-1,1)}*(speed * Random());
			}
		}
	}

	void ParticleSystem::Create(const Vector2& position, size_t count, float lifetime, const std::vector<Color>& colors, float speed, float angle, float angleRange)
	{
		for (size_t i = 0; i < count; i++)
		{
			auto particle = std::find_if(particles.begin(), particles.end(), Particle::IsNotActive);
			if (particle != particles.end())
			{
				particle->isActive = true;
				particle->lifetime = lifetime;
				particle->position = position;
				particle->prevposition = position;
				particle->color = colors[rand() % colors.size()];

				particle->velocity = (jc::Vector2::Rotate(jc::Vector2::right,angle +jc::RandomRange(-angleRange,angleRange)))*(speed * Random());
			}
		}
	}

}