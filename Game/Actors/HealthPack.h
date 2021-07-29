#pragma once
#include "Base/Actor.h"

class HealthPack : public jc::Actor
{
public:
	HealthPack( jc::Vector2 v, std::shared_ptr<jc::Shape> shape, float speed) : jc::Actor{ v, shape }, speed{ speed }{}

	void Update(float dt)override;
	void OnCollision(Actor* actor)override;
private:
	float speed = { 200 };

};
