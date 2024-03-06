#pragma once
#include <vector>

class TimerSystem {
public:
	using Callback = void(*) ();

	void addTimer(float duration, Callback callback);
	void update();

private:
	struct Timer {
		float startTime = 0.f;
		float duration = 0.f;
		Callback callback = nullptr;
	};
	
	std::vector<Timer> timers;
};