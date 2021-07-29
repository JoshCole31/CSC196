#pragma once
#include "Base/Actor.h"

class Asteroid : public jc::Actor
{
public:
	Asteroid(const jc::Transform& transform, std::shared_ptr<jc::Shape> shape, float speed) : jc::Actor{ transform, shape }, speed{ speed }{}

	void Update(float dt)override;
	void OnCollision(Actor* actor)override;
private:
	float speed = { 200 };

};