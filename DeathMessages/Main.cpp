#include <LoggerAPI.h>
#include "version.h"
#include "Global.h"

extern void DeathMessages();

void CheckTransFile(){
    if(!std::filesystem::exists("plugins/DeathMessages/Translation.json")){
        logger.warn("翻译文件不存在，未命名的生物名字会以英文显示！！");
    }
}

void PluginInit()
{
    Logger(PLUGIN_NAME).info("当前版本 {}.{}.{} ，支持 BDS - 1.19.4x ，版本协议 {}",PLUGIN_VERSION_MAJOR,PLUGIN_VERSION_MINOR,PLUGIN_VERSION_REVISION,TARGET_BDS_PROTOCOL_VERSION);
    Logger(PLUGIN_NAME).info("插件作者 Tsubasa6848");
    CheckTransFile();

    Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent& ev) {
        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),ev.mPlayer->getName() + "加入了游戏"));
        return true;
    });

    Event::PlayerLeftEvent::subscribe([](const Event::PlayerLeftEvent& ev) {
        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),ev.mPlayer->getName() + "退出了游戏"));
        return true;
    });

    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent) {
        Global<Level>->runcmdEx("gamerule showdeathmessages false");
        return true;
    });

    Event::PlayerCmdEvent::subscribe([](const Event::PlayerCmdEvent& ev) {
        if(ev.mCommand == "gamerule showdeathmessages true") return false;
        else return true;
    });
    Event::ConsoleCmdEvent::subscribe([](const Event::ConsoleCmdEvent& ev) {
        if(ev.mCommand == "gamerule showdeathmessages true") return false;
        else return true;
    });
    Event::CmdBlockExecuteEvent::subscribe([](const Event::CmdBlockExecuteEvent& ev) {
        if(ev.mCommand == "gamerule showdeathmessages true") return false;
        else return true;
    });
    Event::NpcCmdEvent::subscribe([](const Event::NpcCmdEvent& ev) {
        if(ev.mCommand == "gamerule showdeathmessages true") return false;
        else return true;
    });

    DeathMessages();
}
