#pragma once
#include <functional>

class Event
{
private:
	using Callback = std::function<void()>;
	std::vector<Callback> callbacks;

public:
	// �C�x���g��ǉ�
	void AddEvent(Callback callback)
	{
		callbacks.push_back(callback);
	}

	// �C�x���g�����s
	void RunEvent()
	{
		for (const auto& callback : callbacks) {
			callback();
		}
	}
};