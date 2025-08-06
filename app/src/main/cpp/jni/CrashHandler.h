#pragma once

namespace CrashHandler {
	void Initialise();
	void Log(const char* fmt, ...);
	void Report(void* contextPtr, siginfo_t* info, const char* sign);
};