#include "../utils/callbacksList.h"

void thrRoutine()
{
	LARGE_INTEGER sleepTime;
	sleepTime.QuadPart = -1 * 5000 * 1000 * 10;

	while (TRUE)
	{
		enumCmCallbacks();
		KeDelayExecutionThread(KernelMode, FALSE, &sleepTime);
	}
}

NTSTATUS DriverEntry(PDRIVER_OBJECT obj, PUNICODE_STRING path)
{
	UNREFERENCED_PARAMETER(obj);
	UNREFERENCED_PARAMETER(path);

	HANDLE thrHandle = { NULL };

	if (!NT_SUCCESS(PsCreateSystemThread(&thrHandle, THREAD_ALL_ACCESS, NULL, NULL, NULL, (PKSTART_ROUTINE)thrRoutine, NULL)))
		return STATUS_UNSUCCESSFUL;

	ZwClose(thrHandle);

	return STATUS_SUCCESS;
}