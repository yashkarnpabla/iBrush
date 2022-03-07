#ifndef Timer_H
#define Timer_H
#include <thread>

/**
 * @brief This class is a timer that runs the toothbrush for 2 minutes, but can change if the user wants.
 * @author Nick Hamel
 */
class Timer{
	private:
		int seconds;// How long the timer has left
		bool running, change, waiting;// flags for if the timer is running, user wants to change time, and timer waiting for time to change, respectively
		void runTimer();
		std::thread *run;

	public:
		Timer(int seconds = 120);
		int getTime();
		void setTime(int seconds);
		~Timer();
};

#endif
