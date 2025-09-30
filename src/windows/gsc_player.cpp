#include "gsc_player.hpp"
#include "codra_server.hpp"
void gsc_player_getHWID(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_getHWID() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t* client = &svs.clients[id];
    if (!client) {
        stackError("gsc_player_getHWID() client %i not found", id);
        stackPushUndefined();
        return;
    }

    char* userinfo = client->userinfo;
    if (!userinfo) {
        stackError("gsc_player_getHWID() userinfo for client %i not found", id);
        stackPushUndefined();
        return;
    }

    std::string hwid = Info_ValueForKey(userinfo, "cl_hwid");
    if (hwid.empty()) {
        hwid = "unknown";
    }

    stackPushString(const_cast<char*>(hwid.c_str()));
    
}

void gsc_player_isBannedHWID(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_isBannedHWID() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t* client = &svs.clients[id];
    if (!client) {
        stackError("gsc_player_isBannedHWID() client %i not found", id);
        stackPushUndefined();
        return;
    }

    char* userinfo = client->userinfo;
    if (!userinfo) {
        stackError("gsc_player_isBannedHWID() userinfo for client %i not found", id);
        stackPushUndefined();
        return;
    }

    std::string hwid = Info_ValueForKey(userinfo, "cl_hwid");
    if (hwid.empty()) {
        hwid = "unknown";
    }

    bool banned = checkHWIDBan(hwid);
    if(!banned)
        stackPushBool(qfalse);
    else
        stackPushBool(qtrue);
}