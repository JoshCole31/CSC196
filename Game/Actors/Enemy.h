#pragma once
#include "Base/Actor.h"

class Enemy : public jc::Actor
{
public:
	Enemy(const jc::Transform& transform, std::shared_ptr<jc::Shape> shape, float speed) : jc::Actor{ transform, shape }, speed{ speed }{}

	void Update(float dt)override;
	void OnCollision(Actor* actor)override;
private:
	float speed = { 200 };
	float fireTimer{ 0 };
	float fireRate{ 0.8f };
};