#include "Global.h"

extern string Trans(Actor* en);
extern string getMsg(string reason, string die);
extern string getMsg(string reason, string die, string kill);
extern string getMsg(string reason, string die, string kill, string weapon);

void Deathlog(string Str){
    Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Str));
    Level::broadcastText(Str,TextType::RAW);
}

void DeathMessages(){
    Event::MobDieEvent::subscribe([](const Event::MobDieEvent& ev) {
        auto pl = ev.mMob;
        auto source = ev.mDamageSource;
        auto cause = source->getCause();
        if(pl->isPlayer() || pl->isTame()){   
            string died = Trans((Actor*)pl);
            if(pl->getTypeName() == "minecraft:zombie_horse" || pl->getTypeName() == "minecraft:skeleton_horse"){
                return true;
            }
            else if(source->isEntitySource() == false){
                if(cause == ActorDamageCause::All){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("sonic_boom",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("sonic_boom.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Anvil){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.anvil",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.anvil.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::EntityExplosion){
                    Deathlog(getMsg("none.explode.actor",died));
                    return true;
                }
                else if(cause == ActorDamageCause::BlockExplosion){
                    Deathlog(getMsg("none.explode.block",died));
                    return true;
                }
                else if(cause == ActorDamageCause::Charging || cause == ActorDamageCause::Projectile || cause == ActorDamageCause::EntityAttack || cause == ActorDamageCause::Override || cause == ActorDamageCause::Piston || cause == ActorDamageCause::Temperature || cause == ActorDamageCause::None){
                    Deathlog(getMsg("none.unknown",died));
                    return true;
                }
                else if(cause == ActorDamageCause::Contact){
                    if(pl->getLastHurtByMobTime() == 0){
                        if(pl->getBlockSource()->getBlock(pl->getBlockPos()).getTypeName() == "minecraft:sweet_berry_bush"){
                            Deathlog(getMsg("none.contact.sweet_berry_bush",died));
                            return true;
                        }
                        else{
                            if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush"){
                                Deathlog(getMsg("none.contact.sweet_berry_bush",died));
                                return true;
                            }
                            else if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y-1,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus"){
                                Deathlog(getMsg("none.contact.cactus",died));
                                return true;
                            }
                            else{
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "死了"));
                                Deathlog(getMsg("none.unknown",died));
                                return true;
                            }
                        }
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(pl->getBlockSource()->getBlock(pl->getBlockPos()).getTypeName() == "minecraft:sweet_berry_bush"){
                            Deathlog(getMsg("none.contact.sweet_berry_bush.actor",died,Trans((Actor*)mob)));
                            return true;
                        }
                        else{
                            if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush"){
                                Deathlog(getMsg("none.contact.sweet_berry_bush.actor",died,Trans((Actor*)mob)));
                                return true;
                            }
                            else if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y-1,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus"){
                                Deathlog(getMsg("none.contact.cactus.actor",died,Trans((Actor*)mob)));
                                return true;
                            }
                            else{
                                Deathlog(getMsg("entity.unknown",died,Trans((Actor*)mob)));
                                return true;
                            }
                        }
                    }
                }
                else if(cause == ActorDamageCause::Drowning){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.drowned",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.drowned.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Fall){
                    if(pl->getLastHurtByMobTime() == 0){
                        if(pl->getPosOld().y - pl->getPosition().y > 1.0){
                            Deathlog(getMsg("none.fall.high",died));
                            return true; 
                        }
                        else if(pl->getPosOld().y - pl->getPosition().y >= 0.155534 && pl->getPosOld().y - pl->getPosition().y <= 1.0){
                            Deathlog(getMsg("none.fall",died));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("none.fall.low",died));
                            return true;
                       }    
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            if(pl->getPosOld().y - pl->getPosition().y >= 0.155534){
                                Deathlog(getMsg("none.fall.actor",died,Trans((Actor*)mob)));
                                return true;
                            }
                            else{
                                Deathlog(getMsg("none.fall.low.actor",died,Trans((Actor*)mob)));
                                return true;
                            }
                        }
                        else{
                            Deathlog(getMsg("none.fall.actor.weapon",died,Trans((Actor*)mob),mob->getHandSlot()->getCustomName()));
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::FallingBlock){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.falling_block",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.falling_block.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Fire){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.fire",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.fire.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::FireTick){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.firetick",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            Deathlog(getMsg("none.firetick.actor",died,Trans((Actor*)mob)));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("none.firetick.actor.weapon",died,Trans((Actor*)mob),mob->getHandSlot()->getCustomName()));
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Fireworks){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("firework",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("firework.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::FlyIntoWall){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.fly_to_wall",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.fly_to_wall.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Freezing){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.freezing",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.freezing.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Lava){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.lava",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.lava.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Lightning){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.lightning",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.lightning.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Wither){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.wither",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.lightning.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Magma){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.magma",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.magma.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Stalactite){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.stalactite",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.stalactite.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Stalagmite){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.stalagmite",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.stalagmite.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Starve){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.starve",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.starve.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Suffocation){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.suffocation",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.suffocation.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Thorns){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.unknown",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            Deathlog(getMsg("thorns.actor",died,Trans((Actor*)mob)));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("thorns.actor.weapon",died,Trans((Actor*)mob),mob->getHandSlot()->getCustomName()));
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Void || cause == ActorDamageCause::Suicide){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.void",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.void.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Magic){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("none.magic",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Deathlog(getMsg("none.magic.actor",died,Trans((Actor*)mob)));
                        return true;
                    }
                }
            }
            else{
                auto en = source->getEntity();
                if(cause == ActorDamageCause::Magic){
                    if(en->isAlive() == false){
                        Deathlog(getMsg("entity.magic.unknown",died,Trans(en)));
                        return true;
                    }
                    else if(en->getTypeName() == "minecraft:ender_dragon"){
                        Deathlog(getMsg("entity.magic.dragon",died,Trans(en)));
                        return true;
                    }
                    else if(en->getHandSlot()->getCustomName() == ""){
                        Deathlog(getMsg("entity.magic",died,Trans(en)));
                        return true;
                    }
                    else{
                        Deathlog(getMsg("entity.attack.weapon",died,Trans(en),en->getHandSlot()->getCustomName()));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::EntityAttack){
                    if(pl->getLastHurtCause() == ActorDamageCause::Fall && pl->getNoActionTime() <= 60 && pl->getLastHurtDamage() >= 10){
                        if(en->getHandSlot()->getCustomName() == ""){
                            Deathlog(getMsg("entity.attack.fall",died,Trans(en)));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("entity.attack.fall.weapon",died,Trans(en),en->getHandSlot()->getCustomName()));
                            return true;
                        }
                    }
                    else if(en->getTypeName() == "minecraft:bee"){
                        Deathlog(getMsg("entity.attack.bee",died,Trans(en)));
                        return true;
                    }
                    else if(en->getHandSlot()->getCustomName() == ""){
                        Deathlog(getMsg("entity.attack",died,Trans(en)));
                        return true;
                    }
                    else{
                        Deathlog(getMsg("entity.attack.weapon",died,Trans(en),en->getHandSlot()->getCustomName()));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::EntityExplosion){
                    if(en->getOwner() != nullptr){
                        if(en->getTypeName() == "minecraft:wither_skull" || en->getTypeName() == "minecraft:wither_skull_dangerous"){
                            Deathlog(getMsg("entity.explode.wither_skull",died,Trans(en->getOwner())));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("entity.explode",died,Trans(en->getOwner())));
                            return true;
                        }
                    }
                    else{
                        if(en->getTypeName() == "minecraft:tnt"){
                            Deathlog(getMsg("entity.explode.tnt",died));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("entity.explode",died,Trans(en)));
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Projectile){
                    if(en->getOwner() != nullptr){
                        if(en->getTypeName() == "minecraft:arrow"){
                            if(en->getOwner()->getHandSlot()->getCustomName() == ""){
                                Deathlog(getMsg("entity.projectile.arrow",died,Trans(en->getOwner())));
                                return true;
                            }
                            else{
                                Deathlog(getMsg("entity.projectile.arrow.weapon",died,Trans(en),en->getOwner()->getHandSlot()->getCustomName()));
                                return true;
                            }
                        }
                        else if(en->getTypeName() == "minecraft:small_fireball"){
                            Deathlog(getMsg("entity.projectile.small_fireball",died,Trans(en->getOwner())));
                            return true;
                        }
                        else if(en->getTypeName() == "minecraft:thrown_trident"){
                            if(en->getOwner()->getHandSlot()->getCustomName() == ""){
                                Deathlog(getMsg("entity.projectile.trident",died,Trans(en->getOwner())));
                                return true;
                            }
                            else{
                                Deathlog(getMsg("entity.projectile.trident.weapon",died,Trans(en),en->getOwner()->getHandSlot()->getCustomName()));
                                return true;
                            }
                        }
                        else if(en->getTypeName() == "minecraft:llama_spit"){
                            Deathlog(getMsg("entity.projectile.llama_spit",died,Trans(en->getOwner())));
                            return true;
                        }
                        else if(en->getTypeName() == "minecraft:shulker_bullet"){
                            Deathlog(getMsg("entity.projectile.shulker_bullet",died,Trans(en->getOwner())));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("entity.projectile.arrow",died,Trans(en->getOwner())));
                            return true;
                        }
                    }
                    else{
                        Deathlog(getMsg("entity.attack",died,Trans(en)));
                    }
                }
                else if(cause == ActorDamageCause::All){
                    if(pl->getLastHurtByMobTime() == 0){
                        Deathlog(getMsg("sonic_boom",died));
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            Deathlog(getMsg("sonic_boom.actor",died,Trans((Actor*)mob)));
                            return true;
                        }
                        else{
                            Deathlog(getMsg("sonic_boom.actor.weapon",died,Trans((Actor*)mob),mob->getHandSlot()->getCustomName()));
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Thorns){
                    if(en->getHandSlot()->getCustomName() == ""){
                        Deathlog(getMsg("thorns.actor",died,Trans(en)));
                        return true;
                    }
                    else{
                        Deathlog(getMsg("thorns.actor.weapon",died,Trans(en),en->getHandSlot()->getCustomName()));
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Fireworks){
                    if(en->getOwner() != nullptr){
                        if(en->getOwner() == (Mob*)pl){
                            Deathlog(getMsg("firework",died));
                            return true;
                        }
                        else{
                            auto mob = en->getOwner();
                            if(mob->getHandSlot()->getCustomName() == ""){
                                Deathlog(getMsg("firework.actor",died,Trans((Actor*)mob)));
                                return true;
                            }
                            else{
                                Deathlog(getMsg("firework.actor",died,Trans((Actor*)mob),mob->getHandSlot()->getCustomName()));
                                return true;
                            }
                        }
                    }
                    else{
                        if(pl->getLastHurtByMobTime() == 0){
                            Deathlog(getMsg("firework",died));
                            return true;
                        }
                        else{
                            auto mob = pl->getLastHurtByMob();
                            Deathlog(getMsg("firework.actor",died,Trans((Actor*)mob)));
                            return true;
                        }
                    }               
                }
                else{
                    Deathlog(getMsg("entity.unknown",died,Trans(en)));
                    return true;
                }
            }
            return true;
        }
        else return true;    
    });
}