#pragma once
#include "Base/Actor.h"

class Projectile : public jc::Actor
{
public:
	Projectile(const jc::Transform& transform, std::shared_ptr<jc::Shape> shape, float speed) : jc::Actor{ transform, shape }, speed{ speed }{}

	void Update(float dt)override;
private:
	float lifetime{ 1 };
	float speed = { 600 };
};