#include <HookAPI.h>
#include "Global.h"
#include <mc/ActorDamageSource.hpp>
#include <mc/ActorDamageByActorSource.hpp>
#include <mc/ActorDamageByBlockSource.hpp>
#include <mc/ActorDamageByChildActorSource.hpp>
#include <mc/ActorUniqueID.hpp>
#include <mc/EnderCrystal.hpp>
#include <ScheduleAPI.h>
float dmg = -1;
bool isCrystal = false;

TInstanceHook(bool, "?_hurt@EnderCrystal@@MEAA_NAEBVActorDamageSource@@M_N1@Z", EnderCrystal, ActorDamageSource& a1, float a2, bool a3, bool a4){
    auto res = original(this, a1, a2, a3, a4);
    isCrystal = true;
    Schedule::nextTick([](){
        isCrystal = false;
    });
    return res;
}

TInstanceHook(bool, "?_hurt@Mob@@MEAA_NAEBVActorDamageSource@@M_N1@Z", Mob, ActorDamageSource& ads, float damage, bool a1, bool a2) {
    if (isPlayer() || (isTame() && MsgType.count(getTypeName()))) {
        if (ads.getCause() == ActorDamageCause::Fall) {
            dmg = damage;
        }
    }
    return original(this, ads, damage, a1, a2);
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    dmg = -1;
    uid = -1;
    return res;
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageByActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    dmg = -1;
    uid = -1;
    return res;
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageByBlockSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    dmg = -1;
    uid = -1;
    return res;
}

TInstanceHook(DRES, "?getDeathMessage@ActorDamageByChildActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z", ActorDamageSource, string a1, Actor* a2) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    deathLog(res.first);
    dmg = -1;
    uid = -1;
    return res;
}