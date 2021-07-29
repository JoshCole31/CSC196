#include "Asteroid.h"
#include "Projectile.h"
#include "Engine.h"
#include "Player.h"

void Asteroid::Update(float dt)
{
	Actor::Update(dt);

	transform.position += jc::Vector2::Rotate(jc::Vector2::right, transform.rotation) * speed * dt;
	transform.position.x = jc::Wrap(transform.position.x, 0.0f, 800.0f);
	transform.position.y = jc::Wrap(transform.position.y, 0.0f, 600.0f);
}

void Asteroid::OnCollision(Actor* actor)
{
	if (dynamic_cast<Projectile*>(actor) && actor->tag == "Player")
	{
		
		jc::Vector2 p = { transform.position.x, transform.position.y};
		jc::Event event;
		event.name = "SpawnPowerUP";
		//jc::Vector2 p{ transform.position };
		event.data = p;
		scene->engine->Get<jc::EventSystem>()->Notify(event);
		actor->destroy = true;
		destroy = true;
		scene->engine->Get<jc::ParticleSystem>()->Create(transform.position, 200, 1, jc::Color::White, 50);
		scene->engine->Get<jc::AudioSystem>()->PlayAudio("explosion");
		
		jc::Event event2;
		event2.name = "spawnAsteroids";
		event2.data = jc::RandomRange(1, 2);
		scene->engine->Get<jc::EventSystem>()->Notify(event2);

		event.name = "AddPoints";
		event.data = 50;
		scene->engine->Get<jc::EventSystem>()->Notify(event);
		
	}
	if (dynamic_cast<Player*>(actor))
	{
		destroy = true;
		scene->engine->Get<jc::ParticleSystem>()->Create(transform.position, 200, 1, jc::Color::White, 50);
		scene->engine->Get<jc::AudioSystem>()->PlayAudio("explosion");
		jc::Event event2;
		event2.name = "PlayerHit";
		event2.data = 1;
		scene->engine->Get<jc::EventSystem>()->Notify(event2);
	}
}
