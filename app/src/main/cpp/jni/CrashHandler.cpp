#include "main.h"
#include "util/crashlytics.h"
#include "CStackTrace.h"
#include "CrashHandler.h"

#include <android/log.h>
#include <sys/system_properties.h>

#define PROP_VALUE_MAX  92

extern char g_bufRenderQueueCommand[200];
extern uintptr_t g_dwRenderQueueOffset;

struct sigaction act_old;
struct sigaction act1_old;
struct sigaction act2_old;
struct sigaction act3_old;
struct sigaction act4_old;
struct sigaction act5_old;
struct sigaction act6_old;
struct sigaction act7_old;

#define SIGEMT 7

void PrintSymbols(void* pc, void* lr)
{
	Dl_info info_pc, info_lr;

	if (dladdr(pc, &info_pc) != 0) {
		CrashHandler::Log(weikton("PC: %s"), info_pc.dli_sname);
	}

	if (dladdr(lr, &info_lr) != 0) {
		CrashHandler::Log(weikton("LR: %s"), info_lr.dli_sname);
	}
}

void SIGBUS_handler(int signum, siginfo_t* info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act3_old.sa_sigaction)
		act3_old.sa_sigaction(signum, info, contextPtr);

	if (info->si_signo == SIGBUS)
	{
		CrashHandler::Report(context, info, "SIGBUS");
		exit(0);
	}
}

void SIGSEGV_handler(int signum, siginfo_t *info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act_old.sa_sigaction)
		act_old.sa_sigaction(signum, info, contextPtr);

	if(info->si_signo == SIGSEGV)
	{
		CrashHandler::Report(context, info, "SIGSEGV");

		exit(0);
	}
}

void SIGFPE_handler(int signum, siginfo_t* info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act2_old.sa_sigaction)
		act2_old.sa_sigaction(signum, info, contextPtr);

	if (info->si_signo == SIGFPE)
	{
		CrashHandler::Report(context, info, "SIGFPE");

		exit(0);
	}
}

void SIGABRT_handler(int signum, siginfo_t* info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act1_old.sa_sigaction)
		act1_old.sa_sigaction(signum, info, contextPtr);

	if (info->si_signo == SIGABRT)
	{
		CrashHandler::Report(context, info, "SIGABRT");

		exit(0);
	}
}

void SIGILL_handler(int signum, siginfo_t* info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act4_old.sa_sigaction)
		act4_old.sa_sigaction(signum, info, contextPtr);

	if (info->si_signo == SIGILL)
	{
		CrashHandler::Report(context, info, "SIGILL");
		exit(0);
	}
}

void SIGEMT_handler(int signum, siginfo_t* info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act5_old.sa_sigaction)
		act5_old.sa_sigaction(signum, info, contextPtr);

	if (info->si_signo == SIGEMT)
	{
		CrashHandler::Report(context, info, "SIGEMT");
		exit(0);
	}
}

void SIGURG_handler(int signum, siginfo_t* info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act6_old.sa_sigaction)
		act6_old.sa_sigaction(signum, info, contextPtr);

	if (info->si_signo == SIGURG)
	{
		CrashHandler::Report(context, info, "SIGURG");
		exit(0);
	}
}

void SIGPIPE_handler(int signum, siginfo_t* info, void* contextPtr)
{
	auto* context = (ucontext_t*)contextPtr;

	if (act7_old.sa_sigaction)
		act7_old.sa_sigaction(signum, info, contextPtr);

	if (info->si_signo == SIGPIPE)
	{
		CrashHandler::Report(context, info, "SIGPIPE");
		exit(0);
	}
}

#define CRASHER_NAME_A "crasher"
#define CRASHER_NAME_B "crasher"

void PrintBuildCrashInfo();
void CrashHandler::Report(void* contextPtr, siginfo_t* info, const char* sign)
{
	int iTmpVal = 0;
	auto* context = (ucontext_t*)contextPtr;
	int crashId = (int)rand() % 20000;

    PrintBuildCrashInfo();

	CrashHandler::Log("---------- Armeabi Info ----------");
	CrashHandler::Log(weikton("pid: 0x%X, tid: 0x%X, name: %s  >>> %s <<<"), getpid(), gettid(), CRASHER_NAME_A, CRASHER_NAME_B);
	CrashHandler::Log(weikton("signal %d (%s), code %d (%s), fault addr 0x%X"), info->si_signo, sign, info->si_code, info->si_code == 1 ? "SEGV_MAPERR" : "SEGV_ACCERR", info->si_addr);
	CrashHandler::Log(weikton("r0: 0x%X, r1: 0x%X, r2: 0x%X, r3: 0x%X"), (context)->uc_mcontext.arm_r0, (context)->uc_mcontext.arm_r1, (context)->uc_mcontext.arm_r2, (context)->uc_mcontext.arm_r3); 
	CrashHandler::Log(weikton("r4: 0x%x, r5: 0x%x, r6: 0x%x, r7: 0x%x"), (context)->uc_mcontext.arm_r4, (context)->uc_mcontext.arm_r5, (context)->uc_mcontext.arm_r6, (context)->uc_mcontext.arm_r7); 
	CrashHandler::Log(weikton("r8: 0x%x, r9: 0x%x, sl: 0x%x, fp: 0x%x"), (context)->uc_mcontext.arm_r8, (context)->uc_mcontext.arm_r9, (context)->uc_mcontext.arm_r10, (context)->uc_mcontext.arm_fp); 
	CrashHandler::Log(weikton("ip: 0x%x, sp: 0x%x, lr: 0x%x, pc: 0x%x, cpsr: 0x%X"), (context)->uc_mcontext.arm_ip, (context)->uc_mcontext.arm_sp, (context)->uc_mcontext.arm_lr, (context)->uc_mcontext.arm_pc, (context)->uc_mcontext.arm_cpsr);

	CrashHandler::Log(weikton("\nbase address:"));
	CrashHandler::Log(weikton("#00 libGTASA.so 0x%X"), g_libGTASA);
	CrashHandler::Log(weikton("#01 libSCAnd.so 0x%X"), FindLibrary(weikton("libSCAnd.so")));
	CrashHandler::Log(weikton("#02 libImmEmulatorJ.so 0x%X"), FindLibrary(weikton("libImmEmulatorJ.so")));
	CrashHandler::Log(weikton("#03 libsamp.so 0x%X"), FindLibrary(weikton("libsamp.so")));
	CrashHandler::Log(weikton("#04 libc.so 0x%X"), FindLibrary(weikton("libc.so")));
	CrashHandler::Log(weikton("#05 libEGL.so 0x%X"), FindLibrary(weikton("libEGL.so")));
	CrashHandler::Log(weikton("#06 libGLESv2.so 0x%X"), FindLibrary(weikton("libGLESv2.so")));
	CrashHandler::Log(weikton("#07 libOpenSLES.so 0x%X"), FindLibrary(weikton("libOpenSLES.so")));

	CrashHandler::Log(weikton("\nbacktrace:"));
	CrashHandler::Log(weikton("#00 pc libGTASA.so + 0x%X"), (context)->uc_mcontext.arm_pc - g_libGTASA); 
	CrashHandler::Log(weikton("#01 lr libGTASA.so + 0x%X"), (context)->uc_mcontext.arm_lr - g_libGTASA); 					
	CrashHandler::Log(weikton("#02 pc libSCAnd.so + 0x%X"), (context)->uc_mcontext.arm_pc - FindLibrary(weikton("libSCAnd.so")));
	CrashHandler::Log(weikton("#03 lr libSCAnd.so + 0x%X"), (context)->uc_mcontext.arm_lr - FindLibrary(weikton("libSCAnd.so"))); 			
	CrashHandler::Log(weikton("#04 pc libImmEmulatorJ.so + 0x%X"), (context)->uc_mcontext.arm_pc - FindLibrary(weikton("libImmEmulatorJ.so")));
	CrashHandler::Log(weikton("#05 lr libImmEmulatorJ.so + 0x%X"), (context)->uc_mcontext.arm_lr - FindLibrary(weikton("libImmEmulatorJ.so"))); 			
	CrashHandler::Log(weikton("#06 pc libsamp.so + 0x%X"), (context)->uc_mcontext.arm_pc - FindLibrary(weikton("libsamp.so")));
	CrashHandler::Log(weikton("#07 lr libsamp.so + 0x%X"), (context)->uc_mcontext.arm_lr - FindLibrary(weikton("libsamp.so"))); 		
	CrashHandler::Log(weikton("#08 pc libc.so + 0x%X"), (context)->uc_mcontext.arm_pc - FindLibrary(weikton("libc.so"))); 
	CrashHandler::Log(weikton("#09 lr libc.so + 0x%X"), (context)->uc_mcontext.arm_lr - FindLibrary(weikton("libc.so"))); 
	CrashHandler::Log(weikton("#10 pc libEGL.so + 0x%X"), (context)->uc_mcontext.arm_pc - FindLibrary(weikton("libEGL.so"))); 
	CrashHandler::Log(weikton("#11 lr libEGL.so + 0x%X"), (context)->uc_mcontext.arm_lr - FindLibrary(weikton("libEGL.so"))); 
	CrashHandler::Log(weikton("#12 pc libGLESv2.so + 0x%X"), (context)->uc_mcontext.arm_pc - FindLibrary(weikton("libGLESv2.so"))); 
	CrashHandler::Log(weikton("#13 lr libGLESv2.so + 0x%X"), (context)->uc_mcontext.arm_lr - FindLibrary(weikton("libGLESv2.so"))); 
	CrashHandler::Log(weikton("#14 pc libOpenSLES.so + 0x%X"), (context)->uc_mcontext.arm_pc - FindLibrary(weikton("libOpenSLES.so"))); 
	CrashHandler::Log(weikton("#15 lr libOpenSLES.so + 0x%X"), (context)->uc_mcontext.arm_lr - FindLibrary(weikton("libOpenSLES.so"))); 
																							
	PrintSymbols((void*)((context)->uc_mcontext.arm_pc), (void*)((context)->uc_mcontext.arm_lr)); 															
	CStackTrace::printBacktrace(context);
}

void CrashHandler::Initialise()
{
	struct sigaction act;
	act.sa_sigaction = SIGSEGV_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &act, &act_old);

	struct sigaction act1;
	act1.sa_sigaction = SIGABRT_handler;
	sigemptyset(&act1.sa_mask);
	act1.sa_flags = SA_SIGINFO;
	sigaction(SIGABRT, &act1, &act1_old);

	struct sigaction act2;
	act2.sa_sigaction = SIGFPE_handler;
	sigemptyset(&act2.sa_mask);
	act2.sa_flags = SA_SIGINFO;
	sigaction(SIGFPE, &act2, &act2_old);

	struct sigaction act3;
	act3.sa_sigaction = SIGBUS_handler;
	sigemptyset(&act3.sa_mask);
	act3.sa_flags = SA_SIGINFO;
	sigaction(SIGBUS, &act3, &act3_old);

	struct sigaction act4;
	act4.sa_sigaction = SIGILL_handler;
	sigemptyset(&act4.sa_mask);
	act4.sa_flags = SA_SIGINFO;
	sigaction(SIGILL, &act4, &act4_old);

	struct sigaction act5;
	act5.sa_sigaction = SIGEMT_handler;
	sigemptyset(&act5.sa_mask);
	act5.sa_flags = SA_SIGINFO;
	sigaction(SIGEMT, &act5, &act5_old);

	struct sigaction act6;
	act6.sa_sigaction = SIGURG_handler;
	sigemptyset(&act6.sa_mask);
	act6.sa_flags = SA_SIGINFO;
	sigaction(SIGURG, &act6, &act6_old);

	struct sigaction act7;
	act7.sa_sigaction = SIGPIPE_handler;
	sigemptyset(&act7.sa_mask);
	act7.sa_flags = SA_SIGINFO;
	sigaction(SIGPIPE, &act7, &act7_old);
}

void CrashHandler::Log(const char* fmt, ...)
{
	char buffer[2048+1] = { '\0' };
	static FILE* flLog = nullptr;

	if (flLog == nullptr && g_pszStorage != nullptr)
	{
		sprintf(buffer, weikton("%sSAMP/%s"), g_pszStorage, crashLogName);
		flLog = fopen(buffer, weikton("a"));
	}

	memset(buffer, 0, sizeof(buffer));

	va_list arg;
	va_start(arg, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, arg);
	va_end(arg);

	__android_log_write(ANDROID_LOG_INFO, weikton("crashdump"), buffer);

	firebase::crashlytics::Log(buffer);

	if (flLog == nullptr) return;
	fprintf(flLog, weikton("%s\n"), buffer);
	fflush(flLog);

	fclose(flLog);
	flLog = nullptr;
}