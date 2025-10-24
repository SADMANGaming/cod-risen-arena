// Cmd_AddCommand : 0042c3b0

#include <windows.h>
#include "functions.hpp"
#include <cctype>

Com_DPrintf_t Com_DPrintf = (Com_DPrintf_t)0x435820;
Com_Printf_t Com_Printf = (Com_Printf_t)0x4357B0;
Com_Error_t Com_Error = (Com_Error_t)0x435AD0;

Cmd_AddCommand_t Cmd_AddCommand = (Cmd_AddCommand_t)0x428840;
Cmd_TokenizeString_t Cmd_TokenizeString = (Cmd_TokenizeString_t)0x4286D0;

idkwhat_t idkwhat = (idkwhat_t)0x4483F0;
NET_CompareBaseAdr_t NET_CompareBaseAdr = (NET_CompareBaseAdr_t)0x4490C0;
/////////////////// ###### GSC ####### ////////////////////////
// Scr_ExecThread_t Scr_ExecThread = (Scr_ExecThread_t)0x481E10;
// Scr_ExecEntThread_t Scr_ExecEntThread = (Scr_ExecEntThread_t)0x481EC0;
// Scr_FreeThread_t Scr_FreeThread = (Scr_FreeThread_t)0x482070;
SL_ConvertToString_t SL_ConvertToString = (SL_ConvertToString_t)0x46F7E0; //set
// Scr_MakeArray_t Scr_MakeArray = (Scr_MakeArray_t)0x483330;
// Scr_AddArray_t Scr_AddArray = (Scr_AddArray_t)0x483380;
Scr_Error_t Scr_Error = (Scr_Error_t)0x200A05AC; //set game_mp

Scr_GetNumParam_t Scr_GetNumParam = (Scr_GetNumParam_t)0x200A0534; //set game_mp
// Scr_GetPointerType_t Scr_GetPointerType = (Scr_GetPointerType_t)0x482FC0;
Scr_GetType_t Scr_GetType = (Scr_GetType_t)0x47DA20; //set

Scr_AddInt_t Scr_AddInt = (Scr_AddInt_t)0x47DB60; //set
Scr_AddBool_t Scr_AddBool = (Scr_AddBool_t)0x47DB40; //set
Scr_AddString_t Scr_AddString = (Scr_AddString_t)0x47DCE0; //set
Scr_AddVector_t Scr_AddVector = (Scr_AddVector_t)0x47DDB0;	//set
Scr_AddUndefined_t Scr_AddUndefined = (Scr_AddUndefined_t)0x47DBC0; //set
Scr_AddEntity_t Scr_AddEntity = (Scr_AddEntity_t)0x483140;

Scr_GetFunction_t Scr_GetFunction = (Scr_GetFunction_t)0x20034C00; //set
Scr_GetMethod_t Scr_GetMethod = (Scr_GetMethod_t)0x20034D00; //set

Com_PrintMessage_t Com_PrintMessage = (Com_PrintMessage_t)0x435620; //set
SV_GetPlayerByNum_t SV_GetPlayerByNum = (SV_GetPlayerByNum_t)0x451BA0;
SV_DropClient_t SV_DropClient = (SV_DropClient_t)0x453D80;

// not gsc
NET_AdrToString_t NET_AdrToString = (NET_AdrToString_t)0x00449150;

// Info_SetValueForKey_t Info_SetValueForKey = (Info_SetValueForKey_t)0x44B150; //set game_mp
// Info_ValueForKey_t Info_ValueForKey = (Info_ValueForKey_t)0x44ADA0;
Info_SetValueForKey_Big_t Info_SetValueForKey_Big = (Info_SetValueForKey_Big_t)0x44B300;
//451BA0 
Cmd_RemoveCommand_t Cmd_RemoveCommand = (Cmd_RemoveCommand_t)0x428990;
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
char* va(const char* format, ...)
{
	va_list argptr;
#define MAX_VA_STRING 32000
	static char temp_buffer[MAX_VA_STRING];
	static char string[MAX_VA_STRING]; // in case va is called by nested functions
	static int index = 0;
	char* buf;
	int len;

	va_start(argptr, format);
	vsnprintf(temp_buffer, sizeof(temp_buffer), format, argptr); // ✅ correct function & usage
	va_end(argptr);

	len = strlen(temp_buffer);
	if (len >= MAX_VA_STRING)
	{
		Com_Error(ERR_DROP, "Attempted to overrun string in call to va()\n");
	}
	if (len + index >= MAX_VA_STRING - 1)
	{
		index = 0;
	}
	buf = &string[index];
	memcpy(buf, temp_buffer, len + 1);
	index += len + 1;

	return buf;
}


void __cdecl Com_sprintf(char* dest, int size, const char* fmt, ...)
{
	int ret;
	va_list argptr;

	va_start(argptr, fmt);
	ret = vsnprintf(dest, size, fmt, argptr);
	va_end(argptr);
	if (ret == -1)
	{
		Com_Printf("Com_sprintf: overflow of %i bytes buffer\n", size);
	}
}

int Q_stricmpn(const char* s1, const char* s2, int n)
{
	int c1, c2;
	do
	{
		c1 = *s1++;
		c2 = *s2++;

		if (!n--) {
			return 0;       // strings are equal until end point
		}

		if (c1 != c2) {
			if (c1 >= 'a' && c1 <= 'z') {
				c1 -= ('a' - 'A');
			}
			if (c2 >= 'a' && c2 <= 'z') {
				c2 -= ('a' - 'A');
			}
			if (c1 != c2) {
				return c1 < c2 ? -1 : 1;
			}
		}
	} while (c1);

	return 0;       // strings are equal
}

int Q_stricmp(const char* s1, const char* s2)
{
	return (s1 && s2) ? Q_stricmpn(s1, s2, 99999) : -1;
}


void Info_RemoveKey(char* s, const char* key)
{
	char* start;
	char pkey[MAX_INFO_KEY];
	char value[MAX_INFO_VALUE];
	char* o;

	if (strlen(s) >= MAX_INFO_STRING) {
		Com_Error(ERR_DROP, "Info_RemoveKey: oversize infostring [%s] [%s]", s, key);
	}

	if (strchr(key, '\\')) {
		return;
	}

	while (1)
	{
		start = s;
		if (*s == '\\') {
			s++;
		}
		o = pkey;
		while (*s != '\\')
		{
			if (!*s) {
				return;
			}
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value;
		while (*s != '\\' && *s)
		{
			if (!*s) {
				return;
			}
			*o++ = *s++;
		}
		*o = 0;

		if (!Q_stricmp(key, pkey)) {
			// rain - arguments to strcpy must not overlap
			//strcpy (start, s);	// remove this part
			memmove(start, s, strlen(s) + 1); // remove this part
			return;
		}

		if (!*s) {
			return;
		}
	}

}

const char* Info_ValueForKey(const char* s, const char* key) //FIXME: overflow check?
{
	char pkey[BIG_INFO_KEY];
	static char value[2][BIG_INFO_VALUE];   // use two buffers so compares
	// work without stomping on each other
	static int valueindex = 0;
	char* o;

	if (!s || !key) {
		return "";
	}

	if (strlen(s) >= BIG_INFO_STRING) {
		Com_Error(ERR_DROP, "Info_ValueForKey: oversize infostring [%s] [%s]", s, key);
	}

	valueindex ^= 1;
	if (*s == '\\') {
		s++;
	}
	while (1)
	{
		o = pkey;
		while (*s != '\\')
		{
			if (!*s) {
				return "";
			}
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value[valueindex];

		while (*s != '\\' && *s)
		{
			*o++ = *s++;
		}
		*o = 0;

		if (!Q_stricmp(key, pkey)) {
			return value[valueindex];
		}

		if (!*s) {
			break;
		}
		s++;
	}

	return "";
}



void Info_RemoveKey_Big(char* s, const char* key)
{
	char* start;
	char pkey[BIG_INFO_KEY];
	char value[BIG_INFO_VALUE];
	char* o;

	if (strlen(s) >= BIG_INFO_STRING) {
		Com_Error(ERR_DROP, "Info_RemoveKey_Big: oversize infostring [%s] [%s]", s, key);
	}

	if (strchr(key, '\\')) {
		return;
	}

	while (1)
	{
		start = s;
		if (*s == '\\') {
			s++;
		}
		o = pkey;
		while (*s != '\\')
		{
			if (!*s) {
				return;
			}
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value;
		while (*s != '\\' && *s)
		{
			if (!*s) {
				return;
			}
			*o++ = *s++;
		}
		*o = 0;

		if (!Q_stricmp(key, pkey)) {
			memmove(start, s, strlen(s) + 1);  // safe string shift
			return;
		}

		if (!*s) {
			return;
		}
	}
}


void Info_SetValueForKey(char *s, const char *key, const char *value) {
	char newi[MAX_INFO_STRING];

	if (strlen(s) >= MAX_INFO_STRING) {
		Com_Error(ERR_DROP, "Info_SetValueForKey: oversize infostring [%s] [%s] [%s]", s, key, value);
	}

	if (strchr(key, '\\') || strchr(value, '\\')) {
		Com_Printf("Can't use keys or values with a \\\n");
		return;
	}

	if (strchr(key, ';') || strchr(value, ';')) {
		Com_Printf("Can't use keys or values with a semicolon\n");
		return;
	}

	if (strchr(key, '\"') || strchr(value, '\"')) {
		Com_Printf("Can't use keys or values with a \"\n");
		return;
	}

	Info_RemoveKey(s, key);
	if (!value || !strlen(value)) {
		return;
	}

	Com_sprintf(newi, sizeof(newi), "\\%s\\%s", key, value);

	if (strlen(newi) + strlen(s) > 0x17f) {
		Com_Printf("Info string length exceeded\n");
		return;
	}

	strcat(s, newi);
}


char *Cvar_InfoString_RAH(int bit)
{
    static char info[MAX_INFO_STRING];
    char *info_ptr = info;
    info[0] = 0;

    // traverse using explicit offset
    for (cvar_t *var = *(cvar_t **)0x0163B404; var; 
         var = *(cvar_t **)((char *)var + 36)) // 36 = offset of 'next'
    {
        if (var->flags & bit && var->name && var->string)
            Info_SetValueForKey(info, var->name, var->string);
    }

    return info;
}




void Q_strncpyz(char *dest, const char *src, int destsize) {
	if (!src) {
		Com_Error(ERR_FATAL, "Q_strncpyz: NULL src");
	}
	if (destsize < 1) {
		Com_Error(ERR_FATAL, "Q_strncpyz: destsize < 1");
	}

	strncpy(dest, src, destsize - 1);
	dest[destsize - 1] = 0;
}

char* Q_CleanStr(char* string, bool colors) {
	char* d;
	char* s;
	int c;

	s = string;
	d = string;
	while ((c = *s) != 0) {
		if (Q_IsColorString(s) && !colors) {
			s++;
		}
		else if (c >= 0x20 && c <= 0x7E) {
			*d++ = c;
		}
		s++;
	}
	*d = '\0';

	return string;
}



#define MAX_HOSTNAME_LENGTH 1024
char* Com_CleanHostname(char* string, bool colors) {
	static char hostname[MAX_HOSTNAME_LENGTH];
	Q_strncpyz(hostname, string, sizeof(hostname));

	// Remove symbols (and colors for RPC).
	Q_CleanStr(hostname, colors);

	// Check if hostname is empty when symbols are removed.
	if (hostname[0] == '\0') strncpy(hostname, "Unnamed Server", sizeof(hostname));

	// Remove leading spaces.
	int i = 0;
	while (isspace(hostname[0]) || hostname[0] == '!' || hostname[0] == '\'') {
		i = 0;
		while (hostname[i]) {
			hostname[i] = hostname[i + 1];
			i++;
		}
	}

	// Check if hostname is empty when leading spaces are removed.
	if (hostname[0] == '\0') strncpy(hostname, "Unnamed Server", sizeof(hostname));

	// Check if hostname is empty when colors are removed.
	if (colors) {
		char tempHostname[MAX_HOSTNAME_LENGTH];
		Q_strncpyz(tempHostname, hostname, sizeof(tempHostname));
		Q_CleanStr(tempHostname, false);
		if (tempHostname[0] == '\0') strncpy(hostname, "Unnamed Server", sizeof(hostname));
	}

	return hostname;
}

char* Com_CleanMapname(char* mapname) {
	for (int i = 0; mapname[i]; i++) // All to lowercase.
		mapname[i] = tolower(mapname[i]);

	if (strstr(mapname, "mp_") != NULL || strstr(mapname, "xp_") != NULL) // Remove mp_ and xp_ prefixes.
		mapname = mapname + 3;

	mapname[0] = toupper(mapname[0]); // First letter uppercase.

	for (int i = 0; mapname[i]; i++) { // Replace _ with space and uppercase next letter.
		if (mapname[i] == '_') {
			mapname[i] = ' ';
			mapname[i + 1] = toupper(mapname[i + 1]);
		}
	}

	return mapname;
}

const char* GetStockGametypeName(char* gt) {
	char s[64] = { 0 };
	Q_strncpyz(s, gt, sizeof(s));

	if (!strcmp(s, "dm"))
		return "Deathmatch";
	else if (!strcmp(s, "tdm"))
		return "Team Deathmatch";
	else if (!strcmp(s, "re"))
		return "Retrieval";
	else if (!strcmp(s, "bel"))
		return "Behind Enemy Lines";
	else if (!strcmp(s, "sd"))
		return "Search & Destroy";

	return nullptr;
}

const char* Com_GametypeName(char* gt, bool colors) { // Keep colors for loading screen, remove for RPC.
	if (!gt || !*gt) return "Unknown Gametype";

	const char* name = GetStockGametypeName(gt);
	if (!name) name = gt;

	if (name)
		return name;
	else
		return (colors) ? gt : Q_CleanStr(gt);
}




#define DO( src,dest )	  \
	copy[0] = s[src];	\
	copy[1] = s[src + 1];	\
	sscanf( copy, "%x", &val );	  \
	( (struct sockaddr_ipx *)sadr )->dest = val

qboolean Sys_StringToSockaddr(const char *s, struct sockaddr *sadr) {
	struct hostent  *h;
	int val;
	char copy[MAX_STRING_CHARS];

	memset(sadr, 0, sizeof(*sadr));

	// check for an IPX address
	// rain - too easy to falsely match a real hostname
	//	if( ( strlen( s ) == 21 ) && ( s[8] == '.' ) ) {
	((struct sockaddr_in *)sadr)->sin_family = AF_INET;
	((struct sockaddr_in *)sadr)->sin_port = 0;

	if (s[0] >= '0' && s[0] <= '9') {
		*(int *)&((struct sockaddr_in *)sadr)->sin_addr = inet_addr(s);
	}
	else {
		if ((h = gethostbyname(s)) == 0) {
			return qfalse;
		}
		*(int *)&((struct sockaddr_in *)sadr)->sin_addr = *(int *)h->h_addr_list[0];
	}

	return qtrue;
}

void SockadrToNetadr(struct sockaddr *s, netadr_t *a) {
	a->type = NA_IP;
	*(int *)&a->ip = ((struct sockaddr_in *)s)->sin_addr.s_addr;
	a->port = ((struct sockaddr_in *)s)->sin_port;
}

void NetadrToSockadr(netadr_t *a, struct sockaddr *s) {
	memset(s, 0, sizeof(*s));

	if (a->type == NA_BROADCAST) {
		((struct sockaddr_in *)s)->sin_family = AF_INET;
		((struct sockaddr_in *)s)->sin_port = a->port;
		((struct sockaddr_in *)s)->sin_addr.s_addr = INADDR_BROADCAST;
	}
	else if (a->type == NA_IP)    {
		((struct sockaddr_in *)s)->sin_family = AF_INET;
		((struct sockaddr_in *)s)->sin_addr.s_addr = *(int *)&a->ip;
		((struct sockaddr_in *)s)->sin_port = a->port;
	}
}

qboolean Sys_StringToAdr(const char *s, netadr_t *a) {
	struct sockaddr sadr;

	if (!Sys_StringToSockaddr(s, &sadr)) {
		return qfalse;
	}

	SockadrToNetadr(&sadr, a);
	return qtrue;
}

//tmp relocation
short   BigShort(short l) {
	byte b1, b2;

	b1 = l & 255;
	b2 = (l >> 8) & 255;

	return (b1 << 8) + b2;
}

qboolean    NET_StringToAdr(const char *s, netadr_t *a) {
	qboolean r;
	char base[MAX_STRING_CHARS];
	char    *port;

	if (!strcmp(s, "localhost")) {
		memset(a, 0, sizeof(*a));
		a->type = NA_LOOPBACK;
		return qtrue;
	}

	// look for a port number
	Q_strncpyz(base, s, sizeof(base));
	port = strstr(base, ":");
	if (port) {
		*port = 0;
		port++;
	}

	r = Sys_StringToAdr(base, a);

	if (!r) {
		a->type = NA_BAD;
		return qfalse;
	}

	// inet_addr returns this if out of range
	if (a->ip[0] == 255 && a->ip[1] == 255 && a->ip[2] == 255 && a->ip[3] == 255) {
		a->type = NA_BAD;
		return qfalse;
	}

	if (port) {
		a->port = BigShort((short)atoi(port));
	}
	else {
		a->port = BigShort(28960);
	}

	return qtrue;
}

int Cmd_Argc() {
	return *(int*)0x8930F0;
}

char** cmd_argv = (char**)0x890BF0;

char* Cmd_Argv(int index) {
	if (index >= Cmd_Argc())
		return "";
	return cmd_argv[index];
}

msg_t *MSG_BeginReading(msg_t *msg)
{
    msg->readcount = 0;
    msg->bit = 0;
    return msg;
}


int MSG_ReadBits(msg_t *msg, int numBits)
{
    int result = 0;
    int bitIndex = 0;

    for (int i = 0; i < numBits; i++)
    {
        int byteOffset = msg->bit >> 3;         // which byte
        int bitOffset  = msg->bit & 7;          // which bit in byte

        if (byteOffset >= msg->cursize)
            break; // prevent overflow

        int value = (msg->data[byteOffset] >> bitOffset) & 1;

        result |= value << bitIndex;

        bitIndex++;
        msg->bit++;
    }

    return result;
}


int MSG_ReadLong( msg_t *msg ) {
	int	c;
	
	c = MSG_ReadBits( msg, 32 );
	if ( msg->readcount > msg->cursize ) {
		c = -1;
	}	
	
	return c;
}

int MSG_ReadByte(msg_t *msg)
{
    if (msg->readcount >= msg->cursize)
        return -1; // no more data

    int value = msg->data[msg->readcount];
    msg->readcount++;
    return value & 0xFF; // ensure unsigned byte
}


char *MSG_ReadStringLine( msg_t *msg ) {
	static char	string[MAX_STRING_CHARS];
	int		l,c;

	l = 0;
	do {
		c = MSG_ReadByte(msg);		// use ReadByte so -1 is out of bounds
		if (c == -1 || c == 0 || c == '\n') {
			break;
		}
		// translate all fmt spec to avoid crash bugs
		if ( c == '%' ) {
			c = '.';
		}
		string[l] = c;
		l++;
	} while (l < sizeof(string)-1);
	
	string[l] = 0;
	
	return string;
}
