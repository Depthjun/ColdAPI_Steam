#pragma once
#include "../Bridge.h"
#include "../public SDK/ISteamUser007.h"


class SteamUserIn007 : public ISteamUser007
{
public:
	HSteamUser GetHSteamUser()
	{
		return NULL;
	}

	void LogOn(CSteamID steamID)
	{
		return;
	}
	void LogOff()
	{
		return;
	}

	bool BLoggedOn()
	{
		return Steam_Config::OnlineMod;
	}

	CSteamID GetSteamID()
	{
		return CSteamID(Steam_Config::UserID);
	}

	bool SetRegistryString(ERegistrySubTree eRegistrySubTree, const char* pchKey, const char* pchValue)
	{
		return false;
	}
	bool GetRegistryString(ERegistrySubTree eRegistrySubTree, const char* pchKey, char* pchValue, int cbValue)
	{
		return false;
	}
	bool SetRegistryInt(ERegistrySubTree eRegistrySubTree, const char* pchKey, int iValue)
	{
		return false;
	}
	bool GetRegistryInt(ERegistrySubTree eRegistrySubTree, const char* pchKey, int* piValue)
	{
		return false;
	}

	int InitiateGameConnection(void* pBlob, int cbMaxBlob, CSteamID steamID, CGameID nGameAppID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void* pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey)
	{
		return cbMaxBlob;
	}

	void TerminateGameConnection(uint32 unIPServer, uint16 usPortServer)
	{
		return;
	}

	void TrackAppUsageEvent(CGameID gameID, EAppUsageEvent eAppUsageEvent, const char* pchExtraInfo = "")
	{
		return;
	}

	void RefreshSteam2Login()
	{
		return;
	}
};