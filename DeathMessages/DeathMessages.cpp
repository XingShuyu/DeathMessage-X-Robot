#include "Global.h"

extern string Trans(Actor* en);

void DeathMessages(){
    Event::MobDieEvent::subscribe([](const Event::MobDieEvent& ev) {
        auto pl = ev.mMob;
        auto source = ev.mDamageSource;
        auto cause = source->getCause();
        if(pl->isPlayer() || pl->isTame()){   
            if(pl->getTypeName() == "minecraft:zombie_horse" || pl->getTypeName() == "minecraft:skeleton_horse"){
                return true;
            }
            else if(source->isEntitySource() == false){
                if(cause == ActorDamageCause::All){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被一道音波尖啸抹除了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被一道音波尖啸抹除了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被一道音波尖啸抹除了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被一道音波尖啸抹除了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Anvil){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被坠落的铁砧压扁了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被坠落的铁砧压扁了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被坠落的铁砧压扁了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被坠落的铁砧压扁了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::EntityExplosion){
                    Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "爆炸了"));
                    Global<Level>->broadcastText(Trans((Actor*)pl) + "爆炸了",TextType::RAW);
                    return true;
                }
                else if(cause == ActorDamageCause::BlockExplosion){
                    Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被[刻意的游戏设计]杀死了"));
                    Global<Level>->broadcastText(Trans((Actor*)pl) + "被[刻意的游戏设计]杀死了",TextType::RAW);
                    return true;
                }
                else if(cause == ActorDamageCause::Charging || cause == ActorDamageCause::Projectile || cause == ActorDamageCause::EntityAttack || cause == ActorDamageCause::Override || cause == ActorDamageCause::Piston || cause == ActorDamageCause::Temperature || cause == ActorDamageCause::None){
                    Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "死了"));
                    Global<Level>->broadcastText(Trans((Actor*)pl) + "死了",TextType::RAW);
                    return true;
                }
                else if(cause == ActorDamageCause::Contact){
                    if(pl->getLastHurtByMobTime() == 0){
                        if(pl->getBlockSource()->getBlock(pl->getBlockPos()).getTypeName() == "minecraft:sweet_berry_bush"){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被甜浆果丛刺死了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被甜浆果丛刺死了",TextType::RAW);
                            return true;
                        }
                        else{
                            if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush"){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被甜浆果丛刺死了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "被甜浆果丛刺死了",TextType::RAW);
                                return true;
                            }
                            else if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y-1,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus"){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被戳死了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "被戳死了",TextType::RAW);
                                return true;
                            }
                            else{
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "死了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "死了",TextType::RAW);
                                return true;
                            }
                        }
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(pl->getBlockSource()->getBlock(pl->getBlockPos()).getTypeName() == "minecraft:sweet_berry_bush"){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被甜浆果丛刺死了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被甜浆果丛刺死了",TextType::RAW);
                            return true;
                        }
                        else{
                            if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:sweet_berry_bush" ||pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:sweet_berry_bush"){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被甜浆果丛刺死了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被甜浆果丛刺死了",TextType::RAW);
                                return true;
                            }
                            else if(pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x-1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y-1,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z-1).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z).getTypeName() == "minecraft:cactus" || pl->getBlockSource()->getBlock(pl->getBlockPos().x+1,pl->getBlockPos().y,pl->getBlockPos().z+1).getTypeName() == "minecraft:cactus"){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时撞上了仙人掌"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时撞上了仙人掌",TextType::RAW);
                                return true;
                            }
                            else{
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "死于" + Trans((Actor*)mob)));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "死于" + Trans((Actor*)mob),TextType::RAW);
                                return true;
                            }
                        }
                    }
                }
                else if(cause == ActorDamageCause::Drowning){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "淹死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "淹死了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时淹死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时淹死了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Fall){
                    if(pl->getLastHurtByMobTime() == 0){
                        if(pl->getPosOld().y - pl->getPosition().y > 1.0){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "注定要摔死"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "注定要摔死",TextType::RAW);
                            return true; 
                        }
                        else if(pl->getPosOld().y - pl->getPosition().y >= 0.155534 && pl->getPosOld().y - pl->getPosition().y <= 1.0){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "从高处摔了下来"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "从高处摔了下来",TextType::RAW);
                            return true;
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "落地过猛"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "落地过猛",TextType::RAW);
                            return true;
                       }    
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            if(pl->getPosOld().y - pl->getPosition().y >= 0.155534){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "因为" + Trans((Actor*)mob) + "注定要摔死"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "因为" + Trans((Actor*)mob) + "注定要摔死",TextType::RAW);
                                return true;
                            }
                            else{
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "试图逃离" + Trans((Actor*)mob) + "时落地过猛"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "试图逃离" + Trans((Actor*)mob) + "时落地过猛",TextType::RAW);
                                return true;
                            }
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "因为" + Trans((Actor*)mob) + "使用了" + mob->getHandSlot()->getCustomName() + "注定要摔死"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "因为" + Trans((Actor*)mob) + "使用了" + mob->getHandSlot()->getCustomName() + "注定要摔死",TextType::RAW);
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::FallingBlock){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被下落的方块压扁了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被下落的方块压扁了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被下落的方块压扁了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被下落的方块压扁了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Fire){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "浴火焚身"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "浴火焚身",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时踏入了火中"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时踏入了火中",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::FireTick){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被烧死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被烧死了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被烤得酥脆"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被烤得酥脆",TextType::RAW);
                            return true;
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与持有" + mob->getHandSlot()->getCustomName() + "的" + Trans((Actor*)mob) + "战斗时被烤得酥脆"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在与持有" + mob->getHandSlot()->getCustomName() + "的" + Trans((Actor*)mob) + "战斗时被烤得酥脆",TextType::RAW);
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Fireworks){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "随着一声巨响消失了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "随着一声巨响消失了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时随着一声巨响消失了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时随着一声巨响消失了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::FlyIntoWall){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "感受到了动能"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "感受到了动能",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时感受到了动能"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时感受到了动能",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Freezing){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "冻死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "冻死了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans((Actor*)mob) + "冻死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "冻死了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Lava){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "试图在熔岩里游泳"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "试图在熔岩里游泳",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时试图在熔岩里游泳"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时试图在熔岩里游泳",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Lightning){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被闪电击中"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被闪电击中",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被闪电击中"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被闪电击中",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Wither){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "凋零了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "凋零了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时凋零了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时凋零了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Magma){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "发现了地板是熔岩做的"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "发现了地板是熔岩做的",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "因" + Trans((Actor*)mob) + "而步入危险之地"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "因" + Trans((Actor*)mob) + "而步入危险之地",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Stalactite){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被坠落的钟乳石刺穿了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被坠落的钟乳石刺穿了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被坠落的钟乳石刺穿了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被坠落的钟乳石刺穿了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Stalagmite){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被石笋刺穿了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被石笋刺穿了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被石笋刺穿了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时被石笋刺穿了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Starve){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "饿死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "饿死了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时饿死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时饿死了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Suffocation){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在墙里窒息而亡"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在墙里窒息而亡",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时在墙里窒息而亡"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时在墙里窒息而亡",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Thorns){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "死了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图伤害" + Trans((Actor*)mob) + "时被杀"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图伤害" + Trans((Actor*)mob) + "时被杀",TextType::RAW);
                            return true;
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图伤害" + Trans((Actor*)mob) + "时" + mob->getHandSlot()->getCustomName() + "被杀"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图伤害" + Trans((Actor*)mob) + "时" + mob->getHandSlot()->getCustomName() + "被杀",TextType::RAW);
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Void || cause == ActorDamageCause::Suicide){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "掉出了这个世界"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "掉出了这个世界",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "与" + Trans((Actor*)mob) + "不共戴天"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "与" + Trans((Actor*)mob) + "不共戴天",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Magic){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被魔法杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被魔法杀死了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "被魔法杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "被魔法杀死了",TextType::RAW);
                        return true;
                    }
                }
            }
            else{
                auto en = source->getEntity();
                if(cause == ActorDamageCause::Magic){
                    if(en->isAlive() == false){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被不为人知的魔法杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被不为人知的魔法杀死了",TextType::RAW);
                        return true;
                    }
                    else if(en->getTypeName() == "minecraft:ender_dragon"){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "的龙息烤熟了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "的龙息烤熟了",TextType::RAW);
                        return true;
                    }
                    else if(en->getHandSlot()->getCustomName() == ""){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "使用的魔法杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "使用的魔法杀死了",TextType::RAW);
                        return true;
                    }
                    else{
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "使用" + en->getHandSlot()->getCustomName() + "杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "使用" + en->getHandSlot()->getCustomName() + "杀死了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::EntityAttack){
                    if(pl->getLastHurtCause() == ActorDamageCause::Fall && pl->getNoActionTime() <= 60 && pl->getLastHurtDamage() >= 10){
                        if(en->getHandSlot()->getCustomName() == ""){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "摔伤得太重并被" + Trans(en) + "完结了生命"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "摔伤得太重并被" + Trans(en) + "完结了生命",TextType::RAW);
                            return true;
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "摔伤得太重并被" + Trans(en) + "用" + en->getHandSlot()->getCustomName() + "完结了生命"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "摔伤得太重并被" + Trans(en) + "用" + en->getHandSlot()->getCustomName() + "完结了生命",TextType::RAW);
                            return true;
                        }
                    }
                    else if(en->getTypeName() == "minecraft:bee"){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "蛰死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "蛰死了",TextType::RAW);
                        return true;
                    }
                    else if(en->getHandSlot()->getCustomName() == ""){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "杀死了",TextType::RAW);
                        return true;
                    }
                    else{
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "使用" + en->getHandSlot()->getCustomName() + "杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "使用" + en->getHandSlot()->getCustomName() + "杀死了",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::EntityExplosion){
                    if(en->getOwner() != nullptr){
                        if(en->getTypeName() == "minecraft:wither_skull" || en->getTypeName() == "minecraft:wither_skull_dangerous"){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "发射的头颅射中了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "发射的头颅射中了",TextType::RAW);
                            return true;
                        }
                        else if(en->getOwner() != nullptr){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "炸死了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "炸死了",TextType::RAW);
                            return true;
                        }
                    }
                    else{
                        if(en->getTypeName() == "minecraft:tnt"){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被Minecraft炸死了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被Minecraft炸死了",TextType::RAW);
                            return true;
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "炸死了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "炸死了",TextType::RAW);
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Projectile){
                    if(en->getOwner() != nullptr){
                        if(en->getTypeName() == "minecraft:arrow"){
                            if(en->getOwner()->getHandSlot()->getCustomName() == ""){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "射杀"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "射杀",TextType::RAW);
                                return true;
                            }
                            else{
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "用" + en->getOwner()->getHandSlot()->getCustomName() + "射杀"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "用" + en->getOwner()->getHandSlot()->getCustomName() + "射杀",TextType::RAW);
                                return true;
                            }
                        }
                        else if(en->getTypeName() == "minecraft:small_fireball"){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "用火球烤死了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "用火球烤死了",TextType::RAW);
                            return true;
                        }
                        else if(en->getTypeName() == "minecraft:thrown_trident"){
                            if(en->getOwner()->getHandSlot()->getCustomName() == ""){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "刺穿了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "刺穿了",TextType::RAW);
                                return true;
                            }
                            else{
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "用" + en->getOwner()->getHandSlot()->getCustomName() + "刺穿了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "用" + en->getOwner()->getHandSlot()->getCustomName() + "刺穿了",TextType::RAW);
                                return true;
                            }
                        }
                        else if(en->getTypeName() == "minecraft:llama_spit"){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "的口水淹死了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "的口水淹死了",TextType::RAW);
                            return true;
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "射杀"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en->getOwner()) + "射杀",TextType::RAW);
                            return true;
                        }
                    }
                    else{
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被" + Trans(en) + "杀死了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被" + Trans(en) + "杀死了",TextType::RAW);
                    }
                }
                else if(cause == ActorDamageCause::All){
                    if(pl->getLastHurtByMobTime() == 0){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "被一道音波尖啸抹除了"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "被一道音波尖啸抹除了",TextType::RAW);
                        return true;
                    }
                    else{
                        auto mob = pl->getLastHurtByMob();
                        if(mob->getHandSlot()->getCustomName() == ""){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被一道音波尖啸抹除了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离" + Trans((Actor*)mob) + "时被一道音波尖啸抹除了",TextType::RAW);
                            return true;
                        }
                        else{
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图逃离持有" + mob->getHandSlot()->getCustomName() + "的" + Trans((Actor*)mob) + "时被一道音波尖啸抹除了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图逃离持有" + mob->getHandSlot()->getCustomName() + "的" + Trans((Actor*)mob) + "时被一道音波尖啸抹除了",TextType::RAW);
                            return true;
                        }
                    }
                }
                else if(cause == ActorDamageCause::Thorns){
                    if(en->getHandSlot()->getCustomName() == ""){
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图伤害" + Trans(en) + "时被杀"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图伤害" + Trans(en) + "时被杀",TextType::RAW);
                        return true;
                    }
                    else{
                        Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在试图伤害" + Trans(en) + "被" + en->getHandSlot()->getCustomName() + "杀死"));
                        Global<Level>->broadcastText(Trans((Actor*)pl) + "在试图伤害" + Trans(en) + "被" + en->getHandSlot()->getCustomName() + "杀死",TextType::RAW);
                        return true;
                    }
                }
                else if(cause == ActorDamageCause::Fireworks){
                    if(en->getOwner() != nullptr){
                        if(en->getOwner() == (Mob*)pl){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "随着一声巨响消失了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "随着一声巨响消失了",TextType::RAW);
                            return true;
                        }
                        else{
                            auto mob = en->getOwner();
                            if(mob->getHandSlot()->getCustomName() == ""){
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时随着一声巨响中消失了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时随着一声巨响中消失了",TextType::RAW);
                                return true;
                            }
                            else{
                                Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "随着" + mob->getHandSlot()->getCustomName() + "用" + Trans((Actor*)mob) + "发射的烟花发出的巨响消失了"));
                                Global<Level>->broadcastText(Trans((Actor*)pl) + "随着" + mob->getHandSlot()->getCustomName() + "用" + Trans((Actor*)mob) + "发射的烟花发出的巨响消失了",TextType::RAW);
                                return true;
                            }
                        }
                    }
                    else{
                        if(pl->getLastHurtByMobTime() == 0){
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "随着一声巨响消失了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "随着一声巨响消失了",TextType::RAW);
                            return true;
                        }
                        else{
                            auto mob = pl->getLastHurtByMob();
                            Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时随着一声巨响消失了"));
                            Global<Level>->broadcastText(Trans((Actor*)pl) + "在与" + Trans((Actor*)mob) + "战斗时随着一声巨响消失了",TextType::RAW);
                            return true;
                        }
                    }               
                }
                else{
                    Logger("Server").info("{}",fmt::format(fg(fmt::color::yellow),Trans((Actor*)pl) + "死于" + Trans(en)));
                    Global<Level>->broadcastText(Trans((Actor*)pl) + "死于" + Trans(en),TextType::RAW);
                    return true;
                }
            }
            return true;
        }
        else return true;    
    });
    
}