#include "callbacksList.h"

NTSTATUS enumCmCallbacks()
{
	DebugLog("CmCallbacks:\n");

	PVOID listHead = 0xfffff8070634ad98;

	PCM_CALLBACK_ENTRY cmList = (PCM_CALLBACK_ENTRY)listHead;
	PCM_CALLBACK_ENTRY currEntry = cmList;
	
	while (TRUE)
	{
		if (currEntry->function)
			DebugLog("callback addr: %p, cookie: %llx\n", currEntry->function, currEntry->cookie.QuadPart);
	
		if (MmIsAddressValid(currEntry->callbackListEntry.Flink))
			currEntry = currEntry->callbackListEntry.Flink;
		else break;
	
		if (currEntry == cmList) break;
	}

	return STATUS_SUCCESS;
}
