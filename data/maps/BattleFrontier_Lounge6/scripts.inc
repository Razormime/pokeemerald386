BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Gifter::
	lock
	faceplayer
	goto_if_set GOT_BOTH_TENTS, BattleFrontier_Lounge6_EventScript_Gifter_Got_Both_Tents
	goto_if_set CHOSE_RED_TENT, BattleFrontier_Lounge6_EventScript_Gifter_Get_Blue_Tent
	goto_if_set CHOSE_BLUE_TENT, BattleFrontier_Lounge6_EventScript_Gifter_Get_Red_Tent
	msgbox HaveYouDefeatedTrickMasterText, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Gifter_Get_Blue_Tent::
	msgbox DefeatedTrickMasterText, MSGBOX_DEFAULT
	givedecoration DECOR_BLUE_TENT
	setflag GOT_BOTH_TENTS
	msgbox DefeatedTrickMasterText2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Gifter_Get_Red_Tent::
	msgbox DefeatedTrickMasterText, MSGBOX_DEFAULT
	givedecoration DECOR_RED_TENT
	setflag GOT_BOTH_TENTS
	msgbox DefeatedTrickMasterText2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Gifter_Got_Both_Tents:
	msgbox DefeatedTrickMasterText2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "My POKéMON is a {STR_VAR_2}.\n"
	.string "Do you know it?\l"
	.string "It's quite clever and rather nice.\p"
	.string "This smart one, I could trade with\n"
	.string "pride!\p"
	.string "Would you like to trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Oh, it's adorable!\n"
	.string "Thank you!\l"
	.string "I promise I'll be good to it!\p"
	.string "Oh! I hope you'll be good to\n"
	.string "my {STR_VAR_2}, too!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Oh, I'm sorry!\n"
	.string "I don't intend to trade for anything\l"
	.string "but a {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Oh, you won't?\n"
	.string "Well, that's fine, too.\l"
	.string "Please come visit us again.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Giggle!\n"
	.string "A HARIYAMA is so much cuter than I\l"
	.string "had imagined. I'm delighted!$"

HaveYouDefeatedTrickMasterText:
	.string "Your POKéMON look pretty clever.\n"
	.string "But how about you?\p"
	.string "Do you know the The TRICK MASTER?\n"
	.string "He runs The TRICK HOUSE just south\l"
	.string "of MAUVILLE.\p"
	.string "I'm far too clever for his tricks\n"
	.string "and defeated all his puzzles!\p"
	.string "I bet you couldn't do it in a\n"
	.string "million years! haha!\p"
	.string "What!? you say you can? haha!\n"
	.string "Yeah right! if you ever do it,\l"
	.string "I'll give you the prize I got\l"
	.string "from him! haha!$"

DefeatedTrickMasterText:
	.string "Your POKéMON look pretty clever.\n"
	.string "But how about you?\p"
	.string "Do you know the The TRICK MASTER?\n"
	.string "He runs The TRICK HOUSE just south\l"
	.string "of MAUVILLE.\p"
	.string "I'm far too clever for his tricks\n"
	.string "and defeated all his puzzles!\p"
	.string "I bet you couldn't do it in a\n"
	.string "million years! haha!\p"
	.string "What!? you really did it!?\n"
	.string "… … … …\p"
	.string "Well, I guess I owe you this…$"

DefeatedTrickMasterText2:
	.string "I've learned a valuable lesson\n"
	.string "today…\p"
	.string "It's not nice to doubt people.$"
