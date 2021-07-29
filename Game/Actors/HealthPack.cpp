#include "HealthPack.h"
#include "Projectile.h"
#include "Engine.h"
#include "Player.h"

void HealthPack::Update(float dt)
{
	Actor::Update(dt);

	
}

void HealthPack::OnCollision(Actor* actor)
{
	if (dynamic_cast<Player*>(actor))
	{
		destroy = true;
		scene->engine->Get<jc::ParticleSystem>()->Create(transform.position, 200, 1, jc::Color::Green, 50);
		scene->engine->Get<jc::AudioSystem>()->PlayAudio("explosion");
		jc::Event event;
		event.name = "Heal";
		event.data = 1;
		scene->engine->Get<jc::EventSystem>()->Notify(event);
	}
}