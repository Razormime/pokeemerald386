.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_CHIKORITA, SCRIPT_ExplainChikorita
	msgbox FortreeCity_PokemonCenter_1F_Text_OfferChikorita, MSGBOX_NPC
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 10, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, ReceiveGiftChikoritaParty
	goto_if_eq VAR_RESULT, 1, ReceiveGiftChikoritaPC
	msgbox NoRoomForChikoritaText, MSGBOX_DEFAULT
	release
	end

ReceiveGiftChikoritaParty::
	call GotChikorita_Fanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SCRIPT_ExplainChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SCRIPT_ExplainChikorita
	end

ReceiveGiftChikoritaPC::
	call GotChikorita_Fanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SCRIPT_SendChikoritaToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SCRIPT_SendChikoritaToPC
	end

SCRIPT_SendChikoritaToPC::
	call Common_EventScript_TransferredToPC
	goto SCRIPT_ExplainChikorita
	end

GotChikorita_Fanfare::
	setflag FLAG_GOT_CHIKORITA
	playfanfare MUS_OBTAIN_ITEM
	message PlayerReceivedSpecialChikoritaText
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	return

SCRIPT_ExplainChikorita::
	msgbox FortreeCity_PokemonCenter_1F_Text_AfterChikorita, MSGBOX_DEFAULT
	release
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Listen, kid, are you working\n"
	.string "on a POKéDEX?\p"
	.string "Hmm… Go to the SAFARI ZONE.\n"
	.string "That's my suggestion.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, you have a POKéNAV!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about POKéNAV's\n"
	.string "MATCH CALL system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered TRAINERS anytime.\p"
	.string "It also shows you which TRAINERS\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those DEVON guys\n"
	.string "sure know what they're doing!$"

FortreeCity_PokemonCenter_1F_Text_OfferChikorita:
	.string "You must be {PLAYER}!\p"
	.string "My son is a researcher at the\n"
	.string "WEATHER INSTITUTE on ROUTE 119.\p"
	.string "He called and told me what happened\n"
	.string "there, and that you saved them!\p"
	.string "Let me give you this POKéMON for\n"
	.string "saving my baby!$"

NoRoomForChikoritaText:
	.string "Oh! It seems that you need to make\n"
	.string "room for this POKéMON…$"

PlayerReceivedSpecialChikoritaText:
	.string "{PLAYER} received CHIKORITA!$"

FortreeCity_PokemonCenter_1F_Text_AfterChikorita:
	.string "It doesn't matter how old they get,\n"
	.string "a woman's child is always her baby.$"
