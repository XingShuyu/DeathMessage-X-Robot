#include <HookAPI.h>
#include "Global.h"
#include <mc/ActorDamageSource.hpp>
#include <mc/ActorDamageByActorSource.hpp>
#include <mc/ActorDamageByBlockSource.hpp>
#include <mc/ActorDamageByChildActorSource.hpp>

TInstanceHook(
    DRES, 
    "?getDeathMessage@ActorDamageSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource,
    string a1,
    Actor* a2
) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    return res;
}

TInstanceHook(
    DRES, 
    "?getDeathMessage@ActorDamageByActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource,
    string a1,
    Actor* a2
) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    return res;
}

TInstanceHook(
    DRES, 
    "?getDeathMessage@ActorDamageByBlockSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource,
    string a1,
    Actor* a2
) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    return res;
}

TInstanceHook(
    DRES, 
    "?getDeathMessage@ActorDamageByChildActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource,
    string a1,
    Actor* a2
) {
    auto res = original(this, a1, a2);
    auto ads = (ActorDamageSource*)this;
    res.first = getDeathMsg(a1, a2, ads, res.first);
    return res;
}