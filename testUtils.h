void incrementTestCount();
void incrementPassCount();
void testFailed(const char* fileName, int lineNumber);
void testStarted(const char* name);

#define ASSERT(expr) \
	testStarted(__FUNCTION__);\
	if(expr){\
		incrementPassCount();\
	} else{\
		testFailed(__FILE__,__LINE__);\
	}\
	incrementTestCount()
