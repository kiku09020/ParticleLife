#pragma once
#include <functional>

class Event
{
private:
	using Callback = std::function<void()>;
	std::vector<Callback> callbacks;

public:
	// イベントを追加
	void AddEvent(Callback callback)
	{
		callbacks.push_back(callback);
	}

	// イベントを実行
	void RunEvent()
	{
		for (const auto& callback : callbacks) {
			callback();
		}
	}
};