
#include <stdio.h> // for va_list et al

extern int VDebugPrintF(const char* format, va_list& argList);

extern int DebugPrintF(const char* format, ...);

extern int g_verbosity;
extern void VerboseDebugPrintF(int verbosity,const char* format, ...);

int InitDebugLogFile();
int CloseDebugLogFile();
int OutputDebugLog(const char* message);
void AssertPrintF(const char* format, char* file, int line, ...);
void AssertPrintF(const char* format, char* file, int line, ...);

#ifdef _DEBUG
#define LOG(format, ...)            DebugPrintF(format, __VA_ARGS__)
#define VLOG(verbosity,format, ...) VerboseDebugPrintF(verbosity,format, __VA_ARGS__)
#define DebugLogOpen()              InitDebugLogFile()
#define DebugLogClose()             CloseDebugLogFile()
#else
// Logging Statement, format like printf
#define LOG(format, ...) 
// Logging Statement, format like printf, only appears with verbose enabled.
#define VLOG(verbosity,format, ...)
#define DebugLogOpen() 
#define DebugLogClose() 
#endif
