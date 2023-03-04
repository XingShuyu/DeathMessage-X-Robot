#include <LoggerAPI.h>
#include "version.h"
#include "Global.h"

extern void DeathMessages();

void CheckFile(){
    if(!std::filesystem::exists("plugins/DeathMessages/Translation.json")){
        Logger(PLUGIN_NAME).warn("翻译文件不存在，请在server.properties添加一行'language=zh_CN'，否则未命名的生物名字会以游戏内名称显示（默认英语）！！");
    }
    if(!std::filesystem::exists("logs/DeathLog.log")){
        WriteAllFile("logs/DeathLog.log","//Death Log");
    }
}

void PluginInit()
{
    Logger(PLUGIN_NAME).info("当前版本 {}.{}.{}",PLUGIN_VERSION_MAJOR,PLUGIN_VERSION_MINOR,PLUGIN_VERSION_REVISION);
    Logger(PLUGIN_NAME).info("插件作者 Tsubasa6848");
    CheckFile();
    logger.setFile("logs/DeathLog.log",true);
    Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent& ev) {
        logger.info("{}",fmt::format(fg(fmt::color::yellow),ev.mPlayer->getName() + "加入了游戏"));
        return true;
    });
    Event::PlayerLeftEvent::subscribe([](const Event::PlayerLeftEvent& ev) {
        logger.info("{}",fmt::format(fg(fmt::color::yellow),ev.mPlayer->getName() + "退出了游戏"));
        return true;
    });
    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent) {
        Global<Level>->runcmdEx("gamerule showdeathmessages true");
        return true;
    });
}
