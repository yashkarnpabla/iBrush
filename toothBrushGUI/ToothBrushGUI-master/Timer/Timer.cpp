#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h>
#include <thread>
#include "Timer.h"
using namespace std;

/**
 * @brief Creates a timer and sets it run as a thread in the background.
 * @param seconds Number of seconds the timer will run for, 120 by default
 */ 
Timer::Timer(int seconds) {
    this->change = false;
    this->seconds = seconds;
    this->running = false;
    this->waiting = false;
    run = new thread(&Timer::runTimer, this);
}

/**
 * @brief Runs timer and turns off toothbrush when it is done.
 */ 
void Timer::runTimer() {
	running = true;// Timer is running
	while (running) {
		if (change) {// User wants to change time
			waiting = true;
			while (change);// Waiting for the time to change
			waiting = false;// No longer waiting
		}

		if (seconds == 0) {// Timer has finished
			// THIS IS WHERE THE TOOTHBRUSH TURNS OFF 
			//This is where we would have signaled to the runToothBrush.cpp class that the timer is now off
			//The runToothBrush.cpp's run method would then return an integer to the startWindow class notifying it to finish program execution. 
			running = false;// No longer running
			break;// Exit loop
		}
		sleep(1);// Waiting for 1 second
		seconds--;
	}
}

/**
 * @brief get time left on the timer.
 * @return seconds left
 */
int Timer::getTime() {
	return seconds;
}

/**
 * @brief Set time left on the timer.
 * @param seconds Number of seconds the user wants the timer to run for.
 */
void Timer::setTime(int seconds) {
	if (running) {// Timer is currently running
		change = true;// Letting timer know the user wants to change the time left
		while (!waiting);// Timer isn't waiting yet
		this->seconds = seconds;// Change time left
		change = false;// Letting the timer go again
	}
	else {// Timer is not running
		this->seconds = seconds;// Change time left
		run = new thread(&Timer::runTimer, this);// Start the timer
	}
}
/**
 * @brief Makes sure timer ends before it is deleted
 */
Timer::~Timer() {
	if (run->joinable()) run->join();// If timer is still running, let it finish
}
