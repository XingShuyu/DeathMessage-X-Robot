#include "Global.h"
#include <mc/ActorUniqueID.hpp>
#include <RemoteCallAPI.h>
auto sendGroupMessage = RemoteCall::importAs<void(std::string Str)>("SparkAPI", "sendGroupMessage");

void SendGroupMsg(string msg) {
    if (RemoteCall::hasFunc("SparkAPI", "sendGroupMessage")) {
        return sendGroupMessage(msg);
    }
}

void deathLog(std::string str) {
    while (str.find("§") != std::string::npos) {
        str = str.replace(str.find("§"), 3, "");
    }
    SendGroupMsg(str);
    logger.info(str);
}

std::string getDeathMsg(std::string name, Actor* en, ActorDamageSource* ads, std::string orimsg) {
    if (orimsg.length() > 65565) {
        return getMsg("death.attack.even_more_magic", name, nullptr, nullptr, "");
    }
    Actor* killer = nullptr;
    if (ads->isEntitySource()) {
        if (ads->isChildEntitySource()) {
            killer = ads->getEntity()->getOwner();
        }
        else {
            killer = ads->getEntity();
        }
    }
    Actor* tryes = nullptr;
    if (killer == nullptr && uid != -1) {
        tryes = Global<Level>->getEntity(uid);
    }
    std::string weapon = "";
    if (killer != nullptr){
        weapon = killer->getHandSlot()->getCustomName();
    }
    else if(tryes != nullptr) {
        weapon = tryes->getHandSlot()->getCustomName();
    }
    if (!orimsg.starts_with("death.attack.") && !orimsg.starts_with("death.fell.")) {
        return orimsg;
    }
    auto adc = ads->getCause();
    switch (adc)
    {
    case ActorDamageCause::Anvil:
        return getMsg("death.attack.anvil.item", name, killer, tryes, weapon);
    case ActorDamageCause::BlockExplosion:
        if (tryes != nullptr) {
            return getMsg("death.attack.explosion.player", name, killer, tryes, weapon);
        }
        if (isCrystal) {
            return getMsg("death.attack.explosion", name, killer, tryes, weapon);
        }
        return getMsg("death.attack.badRespawnPoint.message", name, killer, tryes, weapon);
    case ActorDamageCause::EntityAttack:
        if (ads->isEntitySource()) {
            auto en = ads->getEntity();
            if (en->isPlayer()) {
                return getMsg("death.attack.player.item", name, killer, nullptr, weapon);
            }
            if (en->getTypeName() == "minecraft:bee") {
                return getMsg("death.attack.sting.item", name, killer, tryes, weapon);
            }
            return getMsg("death.attack.mob.item", name, killer, tryes, weapon);
        }
        return getMsg("death.attack.generic.item", name, killer, tryes, "");
    case ActorDamageCause::EntityExplosion:
        if (ads->isEntitySource()) {
            if (ads->getEntity()->getTypeName() == "minecraft:wither_skull" || ads->getEntity()->getTypeName() == "minecraft:wither_skull_dangerous") {
                return getMsg("death.attack.witherSkull.item", name, killer, tryes, weapon);
            }
            return getMsg("death.attack.explosion.player", name, killer, tryes, weapon);
        }
        return getMsg("death.attack.explosion", name, killer, tryes, weapon);
    case ActorDamageCause::Contact:
        if (orimsg == "death.attack.cactus") {
            return getMsg("death.attack.cactus.item", name, killer, tryes, weapon);
        }
        else if (orimsg == "death.attack.sweetBerry") {
            return getMsg("death.attack.sweetBerry.item", name, killer, tryes, weapon);
        }
        return getMsg("death.attack.generic.item", name, killer, tryes, "");
    case ActorDamageCause::Drowning:
        return getMsg("death.attack.drown.item", name, killer, tryes, weapon);
    case ActorDamageCause::Fall:
        if (killer != nullptr) {
            return getMsg("death.fell.finish.item", name, killer, tryes, weapon);
        }
        if (orimsg == "death.attack.fall") {
            return getMsg("death.attack.fall.item", name, killer, tryes, weapon);
        }
        if (orimsg == "death.fell.accident.generic") {
            if (tryes != nullptr) {
                if (weapon == "") {
                    return getMsg("death.fell.assist", name, killer, tryes, weapon);
                }
                return getMsg("death.fell.assist.item", name, killer, tryes, weapon);
            }
            if (fallHeight >= 100) {
                return getMsg("death.fell.killer", name, nullptr, nullptr, weapon);
            }
            else {
                return getMsg("death.fell.accident.generic", name, nullptr, nullptr, weapon);
            }
        }
        return getMsg("death.attack.generic.item", name, killer, tryes, "");
    case ActorDamageCause::FallingBlock:
        return getMsg("death.attack.fallingBlock.item", name, killer, tryes, weapon);
    case ActorDamageCause::Fire:
        return getMsg("death.attack.inFire.item", name, killer, tryes, weapon);
    case ActorDamageCause::FireTick:
        return getMsg("death.attack.onFire.item", name, killer, tryes, weapon);
    case ActorDamageCause::Fireworks:
        return getMsg("death.attack.fireworks.item", name, killer, tryes, weapon);
    case ActorDamageCause::FlyIntoWall:
        return getMsg("death.attack.flyIntoWall.item", name, killer, tryes, weapon);
    case ActorDamageCause::Freezing:
        return getMsg("death.attack.freeze.item", name, killer, tryes, weapon);
    case ActorDamageCause::Lava:
        return getMsg("death.attack.lava.item", name, killer, tryes, weapon);
    case ActorDamageCause::Lightning:
        return getMsg("death.attack.lightningBolt.item", name, killer, tryes, weapon);
    case ActorDamageCause::Wither:
        return getMsg("death.attack.wither.item", name, killer, tryes, weapon);
    case ActorDamageCause::Magic:
        if (killer == nullptr) {
            return getMsg("death.attack.magic", name, nullptr, nullptr, weapon);
        }
        return getMsg("death.attack.indirectMagic.item", name, killer, nullptr, weapon);
    case ActorDamageCause::Magma:
        return getMsg("death.attack.magma.item", name, killer, tryes, weapon);
    case ActorDamageCause::Stalactite:
        return getMsg("death.attack.stalactite.item", name, killer, tryes, weapon);
    case ActorDamageCause::Stalagmite:
        return getMsg("death.attack.stalagmite.item", name, killer, tryes, weapon);
    case ActorDamageCause::Starve:
        return getMsg("death.attack.starve.item", name, killer, tryes, weapon);
    case ActorDamageCause::Suffocation:
        return getMsg("death.attack.inWall.item", name, killer, tryes, weapon);
    case ActorDamageCause::SonicBoom:
        if (killer != nullptr) {
            if (killer->getTypeName() == "minecraft:warden") {
                return getMsg("death.attack.sonicBoom", name, nullptr, nullptr, weapon);
            }
        }
        return getMsg("death.attack.sonicBoom.item", name, killer, tryes, weapon);
    case ActorDamageCause::Thorns:
        if (killer == nullptr && tryes == nullptr) {
            return getMsg("death.attack.generic", name, killer, tryes, "");
        }
        if (weapon == "") {
            return getMsg("death.attack.thorns", name, killer, tryes, "");
        }
        return getMsg("death.attack.thorns.item", name, killer, tryes, weapon);
    case ActorDamageCause::Void:
        return getMsg("death.attack.outOfWorld.item", name, killer, tryes, weapon);
    case ActorDamageCause::Suicide:
        return getMsg("death.attack.suicide.item", name, killer, tryes, weapon);
    case ActorDamageCause::Projectile:
        if (ads->isEntitySource()) {
            auto pn = ads->getEntity()->getTypeName();
            if (pn == "minecraft:small_fireball") {
                return getMsg("death.attack.fireball.item", name, killer, nullptr, weapon);
            }
            else if (pn == "minecraft:thrown_trident") {
                return getMsg("death.attack.trident.item", name, killer, nullptr, weapon);
            }
            else if (pn == "minecraft:llama_spit") {
                return getMsg("death.attack.spit", name, killer, nullptr, weapon);
            }
            else if (pn == "minecraft:shulker_bullet") {
                return getMsg("death.attack.bullet", name, killer, nullptr, weapon);
            }
            else if (pn == "minecraft:arrow") {
                return getMsg("death.attack.arrow.item", name, killer, nullptr, weapon);
            }
            else if (pn == "minecraft:snowball" || pn == "minecraft:egg" || pn == "minecraft:ender_pearl") {
                return getMsg("death.attack.thrown.item", name, killer, nullptr, weapon);
            }
        }
        return getMsg("death.attack.generic.item", name, killer, tryes, "");
    default:
        return getMsg("death.attack.generic.item", name, killer, tryes, "");
    }
}