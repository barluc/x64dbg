#ifndef _ADDRINFO_H
#define _ADDRINFO_H

#include "_global.h"

//superglobal variables
extern sqlite3* userdb;

//typedefs
typedef void (*EXPORTENUMCALLBACK)(uint base, const char* mod, const char* name, uint addr);

//structures
struct MODINFO
{
    uint start;
    uint end;
    char name[32];
};

void dbinit();
bool dbsave();
bool dbload();
void dbclose();
bool modnamefromaddr(uint addr, char* modname);
uint modbasefromaddr(uint addr);
bool apienumexports(uint base, EXPORTENUMCALLBACK cbEnum);
bool commentset(uint addr, const char* text);
bool commentget(uint addr, char* text);
bool commentdel(uint addr);
bool labelset(uint addr, const char* text);
bool labelget(uint addr, char* text);
bool labeldel(uint addr);

#endif // _ADDRINFO_H
