#include <HookAPI.h>
#include "Global.h"
#include <mc/ActorDamageSource.hpp>
#include <mc/ActorDamageByActorSource.hpp>
#include <mc/ActorDamageByBlockSource.hpp>
#include <mc/ActorDamageByChildActorSource.hpp>
#include <mc/ActorUniqueID.hpp>
#include <mc/EnderCrystal.hpp>
#include <ScheduleAPI.h>

float fallHeight = -1;
bool isCrystal = false;
ActorUniqueID uid = -1;

TInstanceHook(bool, "?die@Mob@@UEAAXAEBVActorDamageSource@@@Z", Mob, ActorDamageSource* ads) {
    if (isPlayer() || isTame()) {
        if (getLastHurtByMobTime() != 0) {
            auto hm = getLastHurtByMob();
            uid = hm->getActorUniqueId();
        }
        if (ads->getCause() == ActorDamageCause::Fall) {
            fallHeight = getFallDistance();
        }
    }
    return original(this, ads);
}

TInstanceHook(bool, "?_hurt@EnderCrystal@@MEAA_NAEBVActorDamageSource@@M_N1@Z", EnderCrystal, ActorDamageSource& a1, float a2, bool a3, bool a4){
    auto res = original(this, a1, a2, a3, a4);
    isCrystal = true;
    Schedule::nextTick([](){
        isCrystal = false;
    });
    return res;
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    if (a2->isPlayer() == false) {
        a1 = Trans(a2);
    }
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    fallHeight = -1;
    uid = -1;
    return res;
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageByActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    if (a2->isPlayer() == false) {
        a1 = Trans(a2);
    }
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    fallHeight = -1;
    uid = -1;
    return res;
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageByBlockSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    if (a2->isPlayer() == false) {
        a1 = Trans(a2);
    }
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    fallHeight = -1;
    uid = -1;
    return res;
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageByChildActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    if (a2->isPlayer() == false) {
        a1 = Trans(a2);
    }
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    fallHeight = -1;
    uid = -1;
    return res;
}