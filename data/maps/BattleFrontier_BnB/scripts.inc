.set LOCALID_OLGA, 1
.set LOCALID_AZURIL, 2

BattleFrontier_BnB_MapScripts::
	.byte 0


BattleFrontier_RestHouse1_Gamecube1::
	lock
	goto_if_set FLAG_MET_OLGA, BattleFrontier_RestHouse1_Gamecube2
	msgbox BattleFrontier_RestHouse1_Gamecube_Text, MSGBOX_SIGN
	release
	end

BattleFrontier_RestHouse1_Gamecube2::
	goto_if_set FLAG_GOT_CUBE_JIRACHI, BattleFrontier_RestHouse1_GamecubeFinished
	msgbox BattleFrontier_RestHouse1_Gamecube_Text2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RestHouse1_GamecubeNO
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkToPlayGamecube
	waitmovement 0
	msgbox BattleFrontier_RestHouse1_Gamecube_TextYES, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	fadeoutbgm 1
	playbgm MUS_C_COMM_CENTER, FALSE
	delay 30
	msgbox BattleFrontier_RestHouse1_Gamecube_PreparingGameboy_Text, MSGBOX_SIGN
	playse SE_M_COSMIC_POWER
	waitse
	playse SE_SHINY
	waitse
	showmonpic SPECIES_JIRACHI, 10, 3
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
	delay 80
	waitmoncry
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_JIRACHI
	givemon SPECIES_JIRACHI, 5, ITEM_LIECHI_BERRY
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_RestHouse1_JirachiParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_RestHouse1_JirachiPC
	hidemonpic
	fadeoutbgm 1
	delay 30
	playbgm MUS_B_FRONTIER, FALSE
	fadescreen FADE_FROM_BLACK
	goto Common_EventScript_NoMoreRoomForPokemon
	end

WalkToPlayGamecube:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_RestHouse1_GamecubeNO::
	msgbox BattleFrontier_RestHouse1_Gamecube_TextNO, MSGBOX_SIGN
	release
	end

BattleFrontier_RestHouse1_GamecubeFinished::
	msgbox BattleFrontier_RestHouse1_Gamecube_TextFinished, MSGBOX_SIGN
	release
	end

BattleFrontier_RestHouse1_JirachiParty::
	call GamecubeReceivedJirachiFanfare
//	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
//	goto_if_eq VAR_RESULT, NO, Gamecube_EventScript_ReceivedJirachi
//	call Common_EventScript_GetGiftMonPartySlot
//	call Common_EventScript_NameReceivedPartyMon
	goto Gamecube_EventScript_ReceivedJirachi
	end

BattleFrontier_RestHouse1_JirachiPC::
	call GamecubeReceivedJirachiFanfare
//	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
//	goto_if_eq VAR_RESULT, NO, Gamecube_JirachiTransferredToPC
//	call Common_EventScript_NameReceivedBoxMon
	goto Gamecube_JirachiTransferredToPC
	end

Gamecube_JirachiTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto Gamecube_EventScript_ReceivedJirachi
	end

GamecubeReceivedJirachiFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_JIRACHI
	playfanfare MUS_OBTAIN_ITEM
	message Gamecube_Text_ObtainedJirachi
	waitmessage
	waitfanfare
//	bufferspeciesname STR_VAR_1, SPECIES_JIRACHI
	return

Gamecube_EventScript_ReceivedJirachi::
	hidemonpic
	closemessage
	fadeoutbgm 1
	delay 30
	playbgm MUS_B_FRONTIER, FALSE
	fadescreen FADE_FROM_BLACK
	setflag FLAG_GOT_CUBE_JIRACHI
	releaseall
	end

BattleFrontier_RestHouse1_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox BattleFrontier_RestHouse1_Azurill_Text, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_RestHouse1_Traveler::
	lock
	faceplayer
	goto_if_set FLAG_MET_OLGA, BattleFrontier_RestHouse1_Met_Traveler
	msgbox BattleFrontier_RestHouse1_Traveler_Text1, MSGBOX_DEFAULT
	applymovement LOCALID_OLGA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_OLGA, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_RestHouse1_Traveler_Text2, MSGBOX_DEFAULT
	setflag FLAG_MET_OLGA
	release
	end

BattleFrontier_RestHouse1_Met_Traveler::
	msgbox BattleFrontier_RestHouse1_Traveler_Text3, MSGBOX_DEFAULT
	applymovement LOCALID_OLGA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_OLGA, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_RestHouse1_Traveler_Text2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RestHouse1_Notebook::
	lock
	goto_if_set FLAG_MET_OLGA, BattleFrontier_RestHouse1_Notebook_Ready
	msgbox BattleFrontier_RestHouse1_Notebook_Not_Yet_Text
	release
	end

BattleFrontier_RestHouse1_Notebook_Ready::
	msgbox BattleFrontier_RestHouse1_Notebook_Text1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RestHouse1_Notebook_Finished0
	msgbox BattleFrontier_RestHouse1_Notebook_Trade1_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RestHouse1_Notebook_Finished
	msgbox BattleFrontier_RestHouse1_Notebook_Trade2_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RestHouse1_Notebook_Finished
	msgbox BattleFrontier_RestHouse1_Notebook_Trade3_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RestHouse1_Notebook_Finished
	msgbox BattleFrontier_RestHouse1_Notebook_Trade4_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RestHouse1_Notebook_Finished
	msgbox BattleFrontier_RestHouse1_Notebook_Trade5_Text, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RestHouse1_Notebook_Finished0:
	release
	end

BattleFrontier_RestHouse1_Notebook_Finished:
	msgbox BattleFrontier_RestHouse1_Notebook_Finished_Reading_Text, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RestHouse1_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

BattleFrontier_RestHouse1_Gamecube_Text:
	.string "It's a Nintendo GameCube.\p"
	.string "There's a POKéMON COLOSSEUM\n"
	.string "game case next to it…$"

BattleFrontier_RestHouse1_Gamecube_Text2:
	.string "It's a Nintendo GameCube.\p"
	.string "Oh! the disc inside is some\n"
	.string "kind of bonus disc…\p"
	.string "Should I check it out?$"

BattleFrontier_RestHouse1_Gamecube_TextNO:
	.string "Maybe later…$"

BattleFrontier_RestHouse1_Gamecube_TextYES:
	.string "Alright, let's see what this\n"
	.string "is all about…$"

BattleFrontier_RestHouse1_Gamecube_PreparingGameboy_Text:
	.string "Preparing the Game Boy Advance\n"
	.string "system, Game Pak and cable…\p"
	.string "You will now receive JIRACHI\n"
	.string "as a gift…\p"
	.string "The Nintendo GameCube is communicating\n"
	.string "with the Game Boy Advance system…\p"
	.string "Please do not turn off the power or\n"
	.string "unplug the Nintendo GameCube Game Boy\l"
	.string "Advance cable…$"

Gamecube_Text_ObtainedJirachi:
	.string "You got JIRACHI!\n"
	.string "Please take good care of it.$"

BattleFrontier_RestHouse1_Gamecube_TextFinished:
	.string "It's a Nintendo GameCube.\p"
	.string "There's a POKéMON COLOSSEUM\n"
	.string "game case next to it.$"

BattleFrontier_RestHouse1_Azurill_Text:
	.string "OSZIN: Rurii!$"

BattleFrontier_RestHouse1_Traveler_Text1:
	.string "Oh, hello! My name is OLGA,\n"
	.string "Nice to meet you!\p"
	.string "OSZIN and I are just finishing up\n"
	.string "a long journey through HOENN and\l"
	.string "are resting here before we head out\l"
	.string "on our next big adventure!\p"
	.string "Right now I'm digitizing the journal\n"
	.string "we've made of all the fun people\l"
	.string "and POKéMON that we've met here…$"

BattleFrontier_RestHouse1_Traveler_Text2:
	.string "You can play the GameCube or look\n"
	.string "at my travel notes if you want,\l"
	.string "I don't mind…$"

BattleFrontier_RestHouse1_Traveler_Text3:
	.string "Oh, hey {PLAYER}!\p"
	.string "Don't mind me, I'm still digitizing the\n"
	.string "journal of all the fun people and\l"
	.string "POKéMON that OSZIN and I've met here…$"

BattleFrontier_RestHouse1_Notebook_Not_Yet_Text:
	.string "Looks like a journal…\n"
	.string "I should ask before reading it…$"

BattleFrontier_RestHouse1_Notebook_Text1:
	.string "It's opened to a page titled\n"
	.string "“POKéMON Traders of HOENN.”\p"
	.string "…Keep reading?$"

BattleFrontier_RestHouse1_Notebook_Trade1_Text:
	.string "In RUSTBORO, JAYVEE wants to trade\n"
	.string "his EEVEE for a MEOWTH.\p"
	.string "…Keep reading?$"

BattleFrontier_RestHouse1_Notebook_Trade2_Text:
	.string "ANTON, in FALLARBOR, will trade away\n"
	.string "a CHARMANDER for a LARVITAR.\p"
	.string "…Keep reading?$"

BattleFrontier_RestHouse1_Notebook_Trade3_Text:
	.string "FORTREE CITY's ROMAN is offering\n"
	.string "his BULBASAUR for a DUSKULL.\p"
	.string "…Keep reading?$"

BattleFrontier_RestHouse1_Notebook_Trade4_Text:
	.string "In PACIFIDLOG TOWN, SKYLER wants to\n"
	.string "trade his SQUIRTLE for a DRATINI.\p"
	.string "…Keep reading?$"

BattleFrontier_RestHouse1_Notebook_Trade5_Text:
	.string "At the BATTLE FRONTIER, JENNY wants\n"
	.string "to trade her SNORLAX for a HARIYAMA.\p"
	.string "OLGA: I wonder if these trainers\n"
	.string "have found trading partners yet…$"

BattleFrontier_RestHouse1_Notebook_Finished_Reading_Text:
	.string "OLGA: I wonder if these trainers\n"
	.string "have found trading partners yet…$"
