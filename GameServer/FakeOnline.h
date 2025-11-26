#pragma once
#include "User.h"
#include <fstream>
#include <vector>
#include <string>

#if USE_FAKE_ONLINE == TRUE

struct OFFEXP_DATA
{
	char Account[11];
	char Password[11];
	char Name[11];
	WORD SkillID;
	WORD UseBuffs[3];
	int TuNhatItem;
	int TuDongReset;
	int GateNumber;
	int MapX;
	int MapY;
	int PhamViTrain;
	int TimeReturn;
	int PostKhiDie;
	int PVPMode;
	int PartyMode;
	int MoveRange;
};

class CFakeOnline
{
public:
	CFakeOnline();
	void RestoreFakeOnline();
	void AttemptRandomBotComment(int aIndex);
	OFFEXP_DATA* GetOffExpInfo(LPOBJ lpObj);
	OFFEXP_DATA* GetOffExpInfoByAccount(LPOBJ lpObj);
	void LoadFakeData(char* path);
	void AddToList(LPOBJ lpObj);
	void DelFromList(char* account);
	void WriteToFile();
	void FakeAttackProc(LPOBJ lpObj);
	void Attack(int UserIndex);
	void OnAttackAlreadyConnected(LPOBJ lpObj);
	int NhatItem(int aIndex);
	void QuayLaiToaDoGoc(int aIndex);
	void PostChatMSG(LPOBJ lpObj);
	int	IndexMsgMin;
	int	IndexMsgMax;
	void SuDungMauMana(int aIndex);
	void TuDongBuffSkill(int aIndex);
	void TuDongDanhSkill(int aIndex);
	bool GetTargetPlayer(LPOBJ lpObj, int SkillNumber, int* MonsterIndex);
	bool GetTargetMonster(LPOBJ lpObj, int SkillNumber, int* MonsterIndex);
	void SendSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendMultiSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendDurationSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendRFSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendSkill(LPOBJ lpObj, int Target, int Skill);
	bool CheckRequireUseSkill(LPOBJ lpObj, int SkillID, int TargetID);
	void GuiYCParty(int aIndex, int bIndex);
	void InitializeBotPhrases();

public:
	std::map<std::string, OFFEXP_DATA> m_Data;
	int AccountsRestored;
	DWORD TimeFakeLogIn;

private:
	std::vector<OFFEXP_DATA> m_OfflineExpList;
	std::vector<std::string> m_BotPhrases;
	DWORD m_dwLastCommentTick[MAX_OBJECT];
};

// IMPORTANTE: Declaraciones globales FUERA del condicional #if
extern std::vector<std::string> g_BotPhrasesGeneral;
extern std::vector<std::string> g_BotPhrasesNear;
extern std::vector<std::string> g_BotPhrasesInParty;

extern CFakeOnline s_FakeOnline;

// Helper functions (not class members)
void LoadBotPhrasesFromFile(const char* filename);
std::string GetRandomBotPhrase(bool realPlayerNearby, bool inParty);

#endif