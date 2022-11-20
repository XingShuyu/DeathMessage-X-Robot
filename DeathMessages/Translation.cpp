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

string Trans(Actor* en){
    if(en->getNameTag() != ""){
        return CommandUtils::getActorName(*en);
    }
    else{
        return getLanguage(en);
    }
}

string getMsg(string reason, string die, string kill, string weapon){
	try {
		nlohmann::json msgjson;
		std::ifstream LangFile("plugins/DeathMessages/language.json");
		if (LangFile) {
			LangFile >> msgjson;
			auto oristr = msgjson[reason].get<string>();
			auto prestr = ReplaceStr(oristr, "{1}", die);
			auto endstr = ReplaceStr(prestr, "{2}", kill);
			auto finalstr = ReplaceStr(endstr, "{3}", weapon);
			return finalstr;
		}
		else {
			return "";
		}
	}
	catch(...) {
		logger.error("Failed to get the deathmessage of {}",reason);
		return "";
	}
}

string getMsg(string reason, string die, string kill){
	try {
		nlohmann::json msgjson;
		std::ifstream LangFile("plugins/DeathMessages/language.json");
		if (LangFile) {
			LangFile >> msgjson;
			auto oristr = msgjson[reason].get<string>();
			auto prestr = ReplaceStr(oristr, "{1}", die);
			auto finalstr = ReplaceStr(prestr, "{2}", kill);
			return finalstr;
		}
		else {
			logger.error("Failed to get the deathmessage of {}",reason);
			return "";
		}
	}
	catch(...) {
		return "";
	}
}

string getMsg(string reason, string die){
	try {
		nlohmann::json msgjson;
		std::ifstream LangFile("plugins/DeathMessages/language.json");
		if (LangFile) {
			LangFile >> msgjson;
			auto oristr = msgjson[reason].get<string>();
			auto finalstr = ReplaceStr(oristr, "{1}", die);
			return finalstr;		
		}
		else {
			return "";
		}
	}
	catch(...) {
		logger.error("Failed to get the deathmessage of {}",reason);
		return "";
	}
}
