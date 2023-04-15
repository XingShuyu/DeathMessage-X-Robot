#include "Global.h"

string getLanguage(Actor* en){
    auto name = en->getTypeName();
	try {
		nlohmann::json transjson;
		std::ifstream JsonFile("plugins/DeathMessages/Translation.json");
		if (JsonFile) {
			JsonFile >> transjson;
			return transjson[name].get<string>();
		}
		else {
			return CommandUtils::getActorName(*en);
		}
	}
	catch(...) {
		return CommandUtils::getActorName(*en);
	}
}

string Trans(Actor* en) {
	if (en->isPlayer()) {
		return ((Player*)en)->getRealName();
	}
    if (en->getNameTag() != "") {
        return CommandUtils::getActorName(*en) + "§r";
    }
    else {
        return getLanguage(en);
    }
}

string getMsg(string reason, string die, Actor* killer, Actor* tryes, string weapon) {
	try {
		if (weapon == "") {
			if (tryes == nullptr) {
				ReplaceStr(reason, ".item", "");
			}
			else {
				ReplaceStr(reason, ".item", ".player");
			}
		}
		nlohmann::json msgjson;
		std::ifstream LangFile("plugins/DeathMessages/Message.json");
		if (LangFile) {
			LangFile >> msgjson;
			auto dmsg = msgjson[reason].get<string>();
			ReplaceStr(dmsg, "%1$s", die);
			if (killer == nullptr && tryes != nullptr) {
				ReplaceStr(dmsg, "%2$s", Trans(tryes));
			}
			else if (killer != nullptr && tryes == nullptr) {
				ReplaceStr(dmsg, "%2$s", Trans(killer));
			}
			if (weapon != "") {
				string weaponname ="[" + weapon + "§r]";
				ReplaceStr(dmsg, "%3$s", weaponname);
			}
			return dmsg;
		}
		else {
			return reason;
		}
	}
	catch(...) {
		return reason;
	}
}