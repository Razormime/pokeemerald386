.set LOCALID_NURSE, 1
.set LOCALID_LANETTE, 4
.set LOCALID_TRADE_KID, 5

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_CHARMANDER_TRADE_DONE, FallarborTown_PokemonCenter_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_CHARMANDER
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FallarborTown_PokemonCenter_1F_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborTown_PokemonCenter_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_PokemonCenter_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FallarborTown_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox FallarborTown_PokemonCenter_1F_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_CHARMANDER_TRADE_DONE
	applymovement LOCALID_TRADE_KID, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox FallarborTown_PokemonCenter_1F_Text_WellThatsFineToo, MSGBOX_DEFAULT
	applymovement LOCALID_TRADE_KID, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FallarborTown_PokemonCenter_1F_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	applymovement LOCALID_TRADE_KID, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_TradeCompleted::
	msgbox FallarborTown_PokemonCenter_1F_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	applymovement LOCALID_TRADE_KID, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Oh, hello.\n"
	.string "You are?\p"
	.string "Okay, your name's {PLAYER}{KUN}.\n"
	.string "I can see that you're a TRAINER.\p"
	.string "So that means you use the POKéMON\n"
	.string "Storage System I developed.\p"
	.string "How I arrived at that conclusion is\n"
	.string "a simple deductive process.\p"
	.string "You spoke to me because you wanted\n"
	.string "to access something on this PC.\p"
	.string "Oh, I'm sorry. I'm LANETTE.\p"
	.string "Honestly, I'm glad to meet you--it's\n"
	.string "great you're using the Storage System.\p"
	.string "If you could, please visit me at home.\n"
	.string "My house is on ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "I wonder what POKéMON looked like\n"
	.string "long, long ago?\p"
	.string "Maybe the FOSSIL MANIAC at the edge\n"
	.string "of town will know.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "In the fields of FALLARBOR, we plant\n"
	.string "seedlings of hardy trees that thrive\l"
	.string "even in volcanic ash.$"

FallarborTown_PokemonCenter_1F_Text_WouldYouLikeToTrade:
	.string "I have a cool {STR_VAR_2}!\n"
	.string "Have you heard of it?\l"
	.string "It's really very awesome.\p"
	.string "I can trade you my CHARMANDER\n"
	.string "if you trade me a LARVITAR.\p"
	.string "Would you like to trade me a {STR_VAR_1}\n"
	.string "for my cool {STR_VAR_2}?$"

FallarborTown_PokemonCenter_1F_Text_PromiseIllBeGoodToIt:
	.string "Oh, it's awesome!\n"
	.string "Thank you!\l"
	.string "I promise I'll be cool to it!\p"
	.string "You better be cool to my old\n"
	.string "{STR_VAR_2}, too!$"

FallarborTown_PokemonCenter_1F_Text_DontTradeForAnythingButMon:
	.string "Uh, that's not the right POKéMON.\n"
	.string "I really just want a cool LARVITAR.$"

FallarborTown_PokemonCenter_1F_Text_WellThatsFineToo:
	.string "Oh, you don't want to trade?\n"
	.string "Well, that's cool, I guess.\l"
	.string "Maybe someone else has one…$"

FallarborTown_PokemonCenter_1F_Text_SkittySoMuchCuterThanImagined:
	.string "How awesome! LARVITAR\n"
	.string "is one of the coolest POKéMON!$"

