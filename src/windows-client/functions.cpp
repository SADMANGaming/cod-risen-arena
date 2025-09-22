// Cmd_AddCommand : 0042c3b0

#include <windows.h>
#include "functions.hpp"
#include <cctype>

Com_DPrintf_t Com_DPrintf = (Com_DPrintf_t)0x435820;
Com_Printf_t Com_Printf = (Com_Printf_t)0x4357B0;
Com_Error_t Com_Error = (Com_Error_t)0x435AD0;

Cmd_AddCommand_t Cmd_AddCommand = (Cmd_AddCommand_t)0x428840;

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