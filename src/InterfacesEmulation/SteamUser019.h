#pragma once
#include "../Bridge.h"
#include "../public SDK/ISteamUser019.h"

class SteamUserIn019 : public ISteamUser019
{
public:
	HSteamUser GetHSteamUser()
	{
		return NULL;
	}

	bool BLoggedOn()
	{
		return Steam_Config::OnlineMod;
	}

	CSteamID GetSteamID()
	{
		return CSteamID(Steam_Config::UserID);
	}

	int InitiateGameConnection(void* pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure)
	{
		return cbMaxAuthBlob;
	}

	void TerminateGameConnection(uint32 unIPServer, uint16 usPortServer)
	{
		return;
	}

	void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo = "")
	{
		return;
	}

	bool GetUserDataFolder(char* pchBuffer, int cubBuffer)
	{
		const char* mydir = ColdAPI_Storage::GetStorageDirectory();

		std::memcpy(pchBuffer, mydir, cubBuffer);
		return true;
	}

	void StartVoiceRecording()
	{
		return;
	}

	void StopVoiceRecording()
	{
		return;
	}

	EVoiceResult GetAvailableVoice(uint32* pcbCompressed, uint32* pcbUncompressed_Deprecated = 0, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated = 0)
	{
		return k_EVoiceResultOK;
	}

	EVoiceResult GetVoice(bool bWantCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten, bool bWantUncompressed_Deprecated = false, void* pUncompressedDestBuffer_Deprecated = 0, uint32 cbUncompressedDestBufferSize_Deprecated = 0, uint32* nUncompressBytesWritten_Deprecated = 0, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated = 0)
	{
		return k_EVoiceResultOK;
	}

	EVoiceResult DecompressVoice(const void* pCompressed, uint32 cbCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten, uint32 nDesiredSampleRate)
	{
		return k_EVoiceResultOK;
	}

	uint32 GetVoiceOptimalSampleRate()
	{
		return NULL;
	}

	HAuthTicket GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
	{
		return NULL;
	}

	EBeginAuthSessionResult BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID)
	{
		return k_EBeginAuthSessionResultOK;
	}

	void EndAuthSession(CSteamID steamID)
	{
		return;
	}

	void CancelAuthTicket(HAuthTicket hAuthTicket)
	{
		return;
	}

	EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID)
	{
		return k_EUserHasLicenseResultHasLicense;
	}

	bool BIsBehindNAT()
	{
		return true;
	}

	void AdvertiseGame(CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer)
	{
		return;
	}

	SteamAPICall_t RequestEncryptedAppTicket(void* pDataToInclude, int cbDataToInclude)
	{

		// Create a new fake ticket

		std::memset(TicketData, 0, sizeof(TicketData));
		std::memcpy(TicketData, pDataToInclude, min(cbDataToInclude, sizeof(TicketData)));

		auto RequestID = SteamCallback::RegisterCall(true);
		auto Response = new EncryptedAppTicketResponse_t();

		Response->m_eResult = k_EResultOK;
		SteamCallback::CreateNewRequest(Response, sizeof(*Response), Response->k_iCallback, RequestID);

		return RequestID;
	}

	bool GetEncryptedAppTicket(void* pTicket, int cbMaxTicket, uint32 * pcbTicket)
	{
		std::memcpy(pTicket, TicketData, min(cbMaxTicket, (unsigned int)sizeof(TicketData)));
		*pcbTicket = sizeof(TicketData);
		return true;
	}

	int GetGameBadgeLevel(int nSeries, bool bFoil)
	{
		return NULL;
	}

	int GetPlayerSteamLevel()
	{
		return 10;
	}

	SteamAPICall_t RequestStoreAuthURL(const char* pchRedirectURL)
	{
		return NULL;
	}

	bool BIsPhoneVerified()
	{
		return true;
	}

	bool BIsTwoFactorEnabled()
	{
		return true;
	}

	bool BIsPhoneIdentifying()
	{
		return false;
	}

	bool BIsPhoneRequiringVerification()
	{
		return false;
	}
};