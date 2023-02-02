#pragma once
#include <windows.h>
#include <WinReg.h>
#include <iostream>

#pragma comment(lib,"Advapi32.lib")
#pragma comment(lib,"User32.lib")

typedef struct regDatas {
	int affinity;
	int clockrate;
	int gpupriority;
	int priority;
	int explorer1;
	int explorer2;
	int localpriority;
	int hostspriority;
	int dnspriority;
	int netbtpriority;
	int nonbesteffortlimit;
	int networkthrottlingindex;
	int systemresponsiveness;
	int size;
	int largesystemcache;
	int maxuserport;
	int tcptimedwaitdelay;
	int tcpnodelay;
	int defaultttl;
	LPCWSTR notusenla;
	LPCWSTR backgroundonly;
	LPCWSTR scheduling;
	LPCWSTR sfio;
};

void runOptimization(int mode);

void createBackup();