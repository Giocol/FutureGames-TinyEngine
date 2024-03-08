#include "TimerSystem.h"
#include "Engine/TinyEngine.h"

void TimerSystem::addTimer(float duration, bool isRecurring, Callback callback) {
	Timer timer;
	timer.startTime = engCurrentTime();
	timer.duration = duration;
	timer.isRecurring = isRecurring;
	timer.callback = callback;
	
	timers.push_back(timer);
}

void TimerSystem::update() {
	for (int i = 0; i < timers.size(); i++) {
		if (engTimePassedSince(timers[i].startTime) >= timers[i].duration) {
			timers[i].callback();
			if (timers[i].isRecurring) {
				timers[i].startTime = engCurrentTime();
			}
			else {
				timers.erase(timers.begin() + i);
				i--;
			}
		}
	}
}
