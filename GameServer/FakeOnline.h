
#pragma once

#include "User.h"
#include <fstream>
#include <vector> // Añadir para std::vector
#include <string>  // Añadir para std::string
#include "FakeOnline.h"

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
	// --- NUEVO ---
	// No es necesario añadir nada aquí para este enfoque básico
	// --- FIN NUEVO ---
};

class CFakeOnline
{
public:
	CFakeOnline();

	void RestoreFakeOnline();
	void AttemptRandomBotComment(int aIndex);  // <- LÍNEA AGREGADAs
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
	bool GetTargetPlayer(LPOBJ lpObj, int SkillNumber, int* MonsterIndex); // OK
	bool GetTargetMonster(LPOBJ lpObj, int SkillNumber, int* MonsterIndex); // OK
	//===
	void SendSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendMultiSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendDurationSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendRFSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber);
	void SendSkill(LPOBJ lpObj, int Target, int Skill);
	bool CheckRequireUseSkill(LPOBJ lpObj, int SkillID, int TargetID);
	void	GuiYCParty(int aIndex, int bIndex);
	// --- NUEVAS FUNCIONES Y MIEMBROS ---
	void InitializeBotPhrases();
	// --- FIN NUEVAS FUNCIONES Y MIEMBROS ---
	

public:

	std::map<std::string, OFFEXP_DATA> m_Data;
	int AccountsRestored;
	DWORD TimeFakeLogIn;

	//HANDLE File;
	//bool FileLoaded;
	//std::fstream File;

private:
    // ... (otros miembros existentes como m_OfflineExpList)
	std::vector<OFFEXP_DATA> m_OfflineExpList; // Asegúrate que esta línea existe

	// --- NUEVOS MIEMBROS ---
	std::vector<std::string> m_BotPhrases;
	DWORD m_dwLastCommentTick[MAX_OBJECT]; // Para controlar la frecuencia por bot
	// --- FIN NUEVOS MIEMBROS ---

	//std::string GetRandomBotPhrase(bool realPlayerNearby);

};

// Declaraciones para soporte de frases desde archivo externo
	void LoadBotPhrasesFromFile(const char* filename);
							 
extern std::vector<std::string> g_BotPhrasesGeneral;
extern std::vector<std::string> g_BotPhrasesNear;
extern std::vector<std::string> g_BotPhrasesInParty; // <- LÍNEA AGREGADA: Para frases en party
extern std::vector<std::string> g_BotPhrasesPVP; // ++ NUEVA LÍNEA PARA FRASES PVP ++
extern CFakeOnline s_FakeOnline;

#endif