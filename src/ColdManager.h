#pragma once
#include "Bridge.h"
#include <sstream>
#include <vector>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <Dbghelp.h>
#include "SteamStubBypass/SteamStub.h"

namespace ColdAPI_General
{
	const char* GetCountryFromLanguage(const char* Language);
	const char* ColdAPI_GetSteamInstallPath();
	void SetOverlayNotification(int Value);
	bool IsOverlayNeededOrEnabled();
	bool OverlayNeedsPresent();
	int InitInterfaces();
	void* ProvideInterface(int type, const char* Version, bool ScanForName);
	void* ContextInitializzation(void* Input);
	bool ReadIni();
	const char* FormatTheString(const char* Format, const char* ValueS, uint64_t ValueU);
}
namespace ColdAPI_DLC
{
	bool GetDLCByIndex(int iDLC, unsigned int* pAppID, bool* pbAvailable, char* pchName, int cchNameBufferSize);
	bool IsDLCAvailable(uint32_t Appid);
	int GetDlCCount();
}
namespace ColdAPI_Storage
{
	const char* ConnectDirectoryToFile(const char* FileName);
	const char* ConnectUGCDirectoryToFile(const char* FileName);
	const char* GetStorageDirectory();
	const char* GetUGCDirectory();
	void FillFileStructure(const char* Directory);
	void Storage_Initializzation();
}
namespace ColdAPI_InitAndShutDown
{
	bool ColdClientInitializzation();
	void ColdClientShutDown();
}