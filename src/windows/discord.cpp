#include "discord.hpp"
#include "functions.hpp"
#include "libs/discord/discord_rpc.h"
#include "libs/discord/discord_register.h"
#include <thread>
#include <string>
#include <ctime>


// Reference: https://github.com/callofduty4x/CoD4x_Client_pub

struct discordData_s {
	unsigned int nextupdatetime;
	// char joinSecret[256];
	// char partyId[33];
	// int privclients;
	// int maxclients;
};
static struct discordData_s discordData;

void Discord_StatusDemo() {
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "Watching a demo";
	discordPresence.largeImageKey = "main_small";

	Discord_UpdatePresence(&discordPresence);
}

void Discord_StatusIdle() {
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "Looking to play";
	discordPresence.largeImageKey = "main_small";

	Discord_UpdatePresence(&discordPresence);
}

void Discord_StatusJoining() {
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "Connecting to a server";
	discordPresence.largeImageKey = "main_small";

	Discord_UpdatePresence(&discordPresence);
}

void Discord_StatusPlaying() {
	char* info = clc_stringData + clc_stringOffsets[0];

	const char* hostname_p = Info_ValueForKey(info, "sv_hostname");
	char hostname[64] = { 0 };
	Q_strncpyz(hostname, hostname_p, sizeof(hostname));
	const char* mapname_p = Info_ValueForKey(info, "mapname");
	char mapname[64] = { 0 };
	Q_strncpyz(mapname, mapname_p, sizeof(mapname));
	const char* mapnameClean_p = Info_ValueForKey(info, "mapname");
	char mapnameClean[64] = { 0 };
	Q_strncpyz(mapnameClean, mapnameClean_p, sizeof(mapnameClean));
	const char* gametype_p = Info_ValueForKey(info, "g_gametype");
	char gametype[64] = { 0 };
	Q_strncpyz(gametype, gametype_p, sizeof(gametype));

	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));

	discordPresence.state = Com_GametypeName(gametype, false);
	discordPresence.details = Com_CleanHostname(hostname, false);
	discordPresence.largeImageKey = mapname;
	discordPresence.largeImageText = Com_CleanMapname(mapnameClean); // for some reason this needs a whole new buffer

	int player_count = *(int*)CGAME_OFF(0x3020B9FC);
	if(player_count > 0 && player_count < 65) {
		discordPresence.partySize = player_count;
		discordPresence.partyMax = atoi(Info_ValueForKey(info, "sv_maxclients"));
	}
	
	Discord_UpdatePresence(&discordPresence);
}

void Discord_Update() {
	if (discordData.nextupdatetime < *cls_realtime) {
		discordData.nextupdatetime = *cls_realtime + 10 * 1000; // 10 seconds

		if (*clc_demoplaying) {
			Discord_StatusDemo();
		} else if (*cls_state == 6) { // CA_ACTIVE
			Discord_StatusPlaying();
		} else if (*cls_state == CA_CONNECTING || *cls_state == CA_CHALLENGING)
		{
			Discord_StatusJoining();
		} else {
			Discord_StatusIdle();
		}
	}
}

void CL_DiscordInitialize() {
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	// handlers.joinGame = Discord_JoinGame;
	// handlers.joinRequest = Discord_JoinRequest;
	Discord_Initialize("1423916494277971999", &handlers, 1, NULL);

	Discord_StatusIdle();
}

void CL_DiscordFrame() {
	Discord_Update();
}

void CL_DiscordShutdown() {
	Discord_Shutdown();
}