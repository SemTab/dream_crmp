#include "CServerManager.h"
#include <stdint.h>

const char* g_szServerNames[MAX_SERVERS] = {
	"Brilliant RP | Test",
	"Name RP | 01"
};

const CServerInstance::CServerInstanceEncrypted g_sEncryptedAddresses[MAX_SERVERS] = {
	CServerInstance::create("51.75.232.71", 429, 13, 1149, 0),
	CServerInstance::create("51.75.232.71", 429, 13, 1149, 0)
};