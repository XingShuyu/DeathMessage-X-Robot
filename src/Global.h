#pragma once
#include "version.h"
#include <iostream>
#include <LoggerAPI.h>
#include <Global.h>
#include <EventAPI.h>
#include <mc/Player.hpp>
#include <mc/Actor.hpp>
#include <mc/Mob.hpp>
#include <mc/ActorDamageSource.hpp>
#include <mc/CommandUtils.hpp>
#include <mc/ItemStack.hpp>
#include <mc/Vec3.hpp>
#include <mc/Level.hpp>
#include <mc/Block.hpp>
#include <mc/BlockSource.hpp>
#include <mc/LevelSettings.hpp>
#include <stdio.h>
#include <WinNls.h>
#include <FMT/color.h>
#define DRES std::pair<std::string, std::vector<std::string>>
using namespace std;
extern Logger logger;
extern string Trans(Actor* en);
extern string getMsg(string reason, string die, Actor* killer, Actor* tryes, string weapon);
extern string getDeathMsg(std::string name, Actor* en, ActorDamageSource* ads, std::string orimsg);
extern void deathLog(std::string str);
extern ActorUniqueID uid;
extern float dmg;
extern std::unordered_set<std::string> MsgType;
extern void SubscribeDeath();
extern bool isCrystal;
