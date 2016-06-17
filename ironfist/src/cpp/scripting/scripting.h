#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <map>
#include <list>

enum MapVarType {MAPVAR_TYPE_STRING, MAPVAR_TYPE_NUMBER, MAPVAR_TYPE_TABLE, MAPVAR_TYPE_BOOLEAN, MAPVAR_TYPE_ERROR};

// luaTable: map: key -> <type, value>
typedef std::map<std::string, std::pair<MapVarType, std::string>> luaTable;
// luaSubTables: list subtable IDs
typedef std::list<std::string> luaSubTables;
// luaTables: map tableId -> pair<luaTable, subtables>
typedef std::map<std::string, std::pair<luaTable, luaSubTables>> luaTables;

extern std::string MAPVARS_TABLE_ROOT;

struct mapVariable {
	MapVarType type;
	std::string singleValue;
	luaTables tableValues;
};

void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

void DisplayError();

bool isTable(MapVarType);
bool isStringNumBool(MapVarType);

MapVarType StringToMapVarType(std::string);

std::map <std::string , mapVariable > GetMapVariables();

void SetMapVariables(std::map<std::string, mapVariable>);

void ErrorLoadingMapVariable(std::string&, const std::string&);

#endif