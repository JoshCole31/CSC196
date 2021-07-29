#include "EventSystem.h"

namespace jc{
	void EventSystem::Startup()
	{
	}

	void EventSystem::Shutdown()
	{
	}

	void EventSystem::Update(float dt)
	{
	}

	void EventSystem::Subcribe(const std::string& name, function_t function)
	{
		Observer observer;
		observer.function = function;

		observers[name].push_back(observer);
	}

	void EventSystem::Notify(const Event& event)
	{
		auto& ebentObservers = observers[event.name];
		for (auto& observer : ebentObservers)
		{
			observer.function(event);
		}
	}

}