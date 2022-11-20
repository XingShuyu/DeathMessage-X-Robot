#include <llapi/LoggerAPI.h>
#include <llapi/ServerAPI.h>
#include "version.h"

void PluginInit();

Logger logger(PLUGIN_NAME);

void CheckLangFile(){
    if(!std::filesystem::exists("plugins/DeathMessages/language.json")){
        logger.error("语言文件不存在！死亡信息无法显示！");
    }
    else{
        PluginInit();
    }
}

void CheckProtocolVersion()
{

#ifdef TARGET_BDS_PROTOCOL_VERSION

    auto current_protocol = ll::getServerProtocolVersion();
    if (TARGET_BDS_PROTOCOL_VERSION != current_protocol)
    {
        logger.warn("不兼容的BDS版本！本插件兼容的BDS版本协议: {}，当前BDS版本协议: {}。", TARGET_BDS_PROTOCOL_VERSION, current_protocol);
        logger.warn("如果继续加载本插件，可能导致未知错误或引起服务端崩溃，建议更换适配的插件版本。");
    } 

#endif
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        ll::registerPlugin(
            PLUGIN_NAME,
            PLUGIN_INTRODUCTION,
            ll::Version(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_REVISION, PLUGIN_LLVERSION_STATUS),
            std::map<std::string, std::string>{
                {"Author", PLUGIN_AUTHOR},
            });
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C"
{
    _declspec(dllexport) void onPostInit()
    {
        std::ios::sync_with_stdio(false);
        CheckProtocolVersion();
        CheckLangFile();
    }
}
