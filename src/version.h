#pragma once
#define PLUGIN_VERSION_BETA 0
#define PLUGIN_VERSION_SELF 1
#define PLUGIN_VERSION_RELEASE 2

#define PLUGIN_NAME "DeathMessages"
#define PLUGIN_INTRODUCTION "Java版死亡信息"
#define PLUGIN_AUTHOR "Tsubasa6848"

#define PLUGIN_VERSION_MAJOR 4
#define PLUGIN_VERSION_MINOR 3
#define PLUGIN_VERSION_REVISION 1
#define PLUGIN_VERSION_BUILD 0
#define PLUGIN_VERSION_STATUS 2

#define __TO_VERSION_STRING(ver) #ver
#define TO_VERSION_STRING(ver) __TO_VERSION_STRING(ver)

#if PLUGIN_VERSION_STATUS == PLUGIN_VERSION_BETA

#define PLUGIN_FILE_VERSION_FLAG VS_FF_DEBUG
#define PLUGIN_LLVERSION_STATUS ll::Version::Beta
#define PLUGIN_FILE_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION.PLUGIN_VERSION_ACTIONS BETA)

#elif PLUGIN_VERSION_STATUS == PLUGIN_VERSION_SELF

#define PLUGIN_FILE_VERSION_FLAG 0x0L
#define PLUGIN_LLVERSION_STATUS ll::Version::Release
#define PLUGIN_FILE_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION.PLUGIN_VERSION_ACTIONS)

#else

#define PLUGIN_FILE_VERSION_FLAG 0x0L
#define PLUGIN_LLVERSION_STATUS ll::Version::Release
#define PLUGIN_FILE_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION.PLUGIN_VERSION_ACTIONS)

#endif

#define FILE_VERSION_BLOCK_HEADER 0x04004B0L
#define FILE_VERSION_COMPANY_NAME PLUGIN_AUTHOR
#define FILE_VERSION_LEGAL_COPYRIGHT "Copyright (C) 2022"
#define FILE_VERSION_FILE_DESCRIPTION PLUGIN_INTRODUCTION
#define FILE_VERSION_FILE_VERSION_STRING PLUGIN_FILE_VERSION_STRING
#define FILE_VERSION_INTERNAL_NAME PLUGIN_NAME
#define FILE_VERSION_ORIGINAL_FILENAME PLUGIN_NAME ".dll"
#define FILE_VERSION_PRODUCT_NAME FILE_VERSION_INTERNAL_NAME
#define FILE_VERSION_PRODUCT_VERSION_STRING PLUGIN_FILE_VERSION_STRING
#define FILE_VERSION_FILE_VERSION PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_REVISION, PLUGIN_VERSION_BUILD
#define FILE_VERSION_PRODUCT_VERSION FILE_VERSION_FILE_VERSION
