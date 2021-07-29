#include "Enemy.h"
#include "Projectile.h"
#include "Engine.h"
#include "Player.h"

void Enemy::Update(float dt)
{
	Actor::Update(dt);

	if (scene->GetActor<Player>()) {

		jc::Vector2 direction = scene->GetActor<Player>()->transform.position - transform.position;
		jc::Vector2 forward = jc::Vector2::Rotate(jc::Vector2::right,transform.rotation);

		float turnAngle = jc::Vector2::SignedAngle(forward, direction.Normalized());
		transform.rotation = transform.rotation + turnAngle * (3 * dt);

		//transform.rotation =jc::Lerp(transform.rotation, transform.rotation+turnAngle, 2 * dt);

		float angle = jc::Vector2::Angle(forward,direction.Normalized());

		fireTimer -= dt;
		if (fireTimer <= 0 && angle<=jc::DegToRad(50))
		{
			fireTimer = fireRate;			
			jc::Transform t = transform;
			t.scale = 0.5f;

			std::unique_ptr<Projectile> projectile = std::make_unique<Projectile>(t, scene->engine->Get<jc::ResourceSystem>()->Get<jc::Shape>("projectile.txt"), 600.0f);
			projectile->tag = "Enemy";
			scene->Addactor(std::move(projectile));
			scene->engine->Get<jc::AudioSystem>()->PlayAudio("EnemyShoot");
		}
		scene->engine->Get<jc::ParticleSystem>()->Create(transform.position, 3, 2, jc::Color::Orange,20);
	}

	transform.position += jc::Vector2::Rotate(jc::Vector2::right, transform.rotation) * speed * dt;
	transform.position.x = jc::Wrap(transform.position.x, 0.0f, 800.0f);
	transform.position.y = jc::Wrap(transform.position.y, 0.0f, 600.0f);
}

void Enemy::OnCollision(Actor* actor)
{
	if (dynamic_cast<Projectile*>(actor) && actor->tag =="Player")
	{
		actor->destroy = true;

		destroy = true;
		scene->engine->Get<jc::ParticleSystem>()->Create(transform.position, 200, 1, jc::Color::White, 30);
		scene->engine->Get<jc::AudioSystem>()->PlayAudio("explosion");
		jc::Event event;
		event.name = "AddPoints";
		event.data = 300;
		scene->engine->Get<jc::EventSystem>()->Notify(event);

		
		jc::Event event2;
		event2.name = "spawnEnemys";
		event2.data = jc::RandomRange(0,3);
		scene->engine->Get<jc::EventSystem>()->Notify(event2);
	}
	if (dynamic_cast<Player*>(actor))
	{
		destroy = true;
		scene->engine->Get<jc::ParticleSystem>()->Create(transform.position, 200, 1, jc::Color::White, 30);
		scene->engine->Get<jc::AudioSystem>()->PlayAudio("explosion");
	}

}
