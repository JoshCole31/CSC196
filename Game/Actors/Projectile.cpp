#include "Projectile.h"
#include "Engine.h"

void Projectile::Update(float dt)
{
	Actor::Update(dt);

	lifetime -= dt; //countdown method
	if (lifetime <= 0) destroy = true;

	transform.position += jc::Vector2::Rotate(jc::Vector2::right, transform.rotation) * speed * dt;
	transform.position.x = jc::Wrap(transform.position.x, 0.0f, 800.0f);
	transform.position.y = jc::Wrap(transform.position.y, 0.0f, 600.0f);

	std::vector<jc::Color> colors = { jc::Color::White,jc::Color::Red,jc::Color::Green,jc::Color::Blue,jc::Color::cyan,jc::Color::Purple,jc::Color::Black,jc::Color::Orange,jc::Color::Yellow, };
	scene->engine->Get<jc::ParticleSystem>()->Create(transform.position, 10, 0.5f, jc::Color::Red, 30); //colors[jc::RandomRangeInt(0, colors.size())]
}