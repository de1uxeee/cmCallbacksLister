#pragma once
#include <ntifs.h>

#define DebugLog(...) DbgPrintEx(NULL, NULL, __VA_ARGS__)

//win11 22000.613

typedef struct _CM_CALLBACK_ENTRY
{
	LIST_ENTRY callbackListEntry;
	LONG preCallListHead;
	LARGE_INTEGER cookie;
	PVOID callerContext;
	PEX_CALLBACK_FUNCTION function;
	UNICODE_STRING altitude;
	LIST_ENTRY objectContextListHead;
} CM_CALLBACK_ENTRY, * PCM_CALLBACK_ENTRY;