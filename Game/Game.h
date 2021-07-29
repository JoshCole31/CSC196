#pragma once
#include"Engine.h"

class Game
{
public:
	enum class eState
	{
		Title,
		StartGame,
		StartLevel,
		Game,
		Gameover
	};

public:

	void Initialize();
	void Shutdown();

	void Update(float dt);
	void Draw(Core::Graphics& graphics);

private:
	void UpdateTitle(float dt);
	void UpdateLevelStart(float dt);

	void OnAddPoints(const jc::Event& event);
	void OnPlayerHit(const jc::Event& event);
	void OnHeal(const jc::Event& event);
	void OnRockdistroyed(const jc::Event& event);
	void OnSpawnEnemys(const jc::Event& event);
	void OnSpawnAsteroids(const jc::Event& event);
	
public:
	std::unique_ptr <jc::Engine> engine;
	std::unique_ptr <jc::Scene> scene;

private:
	eState state = eState::Title;
	float stateTimer = 0.0f;

	void (Game::* stateFunction)(float) = nullptr;


	size_t score = 0;
	int lives = 3;



};
