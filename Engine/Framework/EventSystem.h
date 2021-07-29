#pragma once
#include "Base/System.h"
#include "Math/Vector2.h"
#include "Math/Transform.h"
#include <string>
#include<functional>
#include <map>
#include <list>
#include <variant>


namespace jc
{
	struct Event 
	{
	std:: string name;
	std::variant<int, bool, float, Vector2, std::string> data;
	};


	class EventSystem : public System
	{
	public:
		using function_t = std::function<void(const Event&)>;

		virtual void Startup() override;
		virtual void Shutdown() override;
		virtual void Update(float dt) override;

		void Subcribe(const std::string& name, function_t function);
		void Notify(const Event& event);

	private:
		struct Observer
		{
			function_t function;

		};
	private:
		std::map<std::string, std::list<Observer>> observers;


	};


}