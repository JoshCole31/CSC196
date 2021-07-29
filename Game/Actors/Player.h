#pragma once
#include "Base/Actor.h"
#include "Engine.h"

class Player : public jc::Actor
{
public:
	Player(const jc::Transform& transform, std::shared_ptr<jc::Shape> shape, float speed);

	void Initialize() override;
	void Update(float dt)override;
	void OnCollision(Actor* actor)override;
	void OnPlayerDead(const jc::Event& event);

private:
	float fireTimer{ 0 };
	float fireRate{ 0.2f };
	float speed = {600};
	jc::Vector2 velocity;
};