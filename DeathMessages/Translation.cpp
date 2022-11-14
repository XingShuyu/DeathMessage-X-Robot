#include "Global.h"

string getLanguage(Actor* en){
    auto name = en->getTypeName();
	try {
		nlohmann::json transjson;
		std::ifstream JsonFile("plugins/DeathMessages/Translation.json");
		if (JsonFile) {
			JsonFile >> transjson;
		}
		else {
			return CommandUtils::getActorName(*en);
		}
		return transjson[name].get<string>();
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