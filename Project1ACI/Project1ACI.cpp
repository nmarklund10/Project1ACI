// Project1ACI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	//Create new output file
	FILE* file;
	file = fopen("C:\\Users\\Public\\sys.txt", "w");
	if (file == NULL) {
		printf("File could not be created!\n");
		return 1;
	}

	//Get basic system info
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	fprintf(file, "System Information:\n");
	fprintf(file, "-----------------------------------\n");
	fprintf(file, "  OEM ID:  %d\n", info.dwOemId);
	fprintf(file, "  Page Size:  %d\n", info.dwPageSize);
	fprintf(file, "  Min Application Address:  %lx\n", info.lpMinimumApplicationAddress);
	fprintf(file, "  Max Application Address:  %lx\n", info.lpMaximumApplicationAddress);
	fprintf(file, "  Active Processor Mask:  %d\n", info.dwActiveProcessorMask);
	fprintf(file, "  Number of Processors:  %d\n", info.dwNumberOfProcessors);
	fprintf(file, "  Processor Type:  %d\n", info.dwProcessorType);
	fprintf(file, "  Allocation Granularity:  %d\n", info.dwAllocationGranularity);
	fprintf(file, "  Processor Architecture:  %d\n", info.wProcessorArchitecture);
	fprintf(file, "  Processor Level:  %d\n", info.wProcessorLevel);
	fprintf(file, "  Processor Revision:  %lx\n", info.wProcessorRevision);
	fprintf(file, "-----------------------------------\n\n");

	//get basic OS info
	OSVERSIONINFO osInfo;
	osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (GetVersionEx(&osInfo) == 0) {
		printf("OS info could not be retrieved!\n");
		fclose(file);
		return 2;
	}
	fprintf(file, "OS Information:\n");
	fprintf(file, "-----------------------------------\n");
	fprintf(file, "  Major Version:  %d\n", osInfo.dwMajorVersion);
	fprintf(file, "  Minor Version:  %d\n", osInfo.dwMinorVersion);
	fprintf(file, "  Build Number:  %d\n", osInfo.dwBuildNumber);
	fprintf(file, "  Platform ID:  %d\n", osInfo.dwPlatformId);
	fprintf(file, "  Service Pack:  %s\n", osInfo.szCSDVersion);
	fprintf(file, "-----------------------------------");

	//Hide File
	wchar_t* hidden_file = L"C:\\Users\\Public\\sys.txt"; // To avoid incompatibility in GetFileAttributes()
	int attr = GetFileAttributes(hidden_file);
	if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
		SetFileAttributes(hidden_file, attr | FILE_ATTRIBUTE_HIDDEN);
	}

	//Clean Up
	fclose(file);
    return 0;
}

