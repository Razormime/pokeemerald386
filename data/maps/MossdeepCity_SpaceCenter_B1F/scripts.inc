.set LOCALID_SCIENTIST_1, 1
.set LOCALID_SCIENTIST_2, 2
.set LOCALID_SCIENTIST_3, 3

MossdeepCity_SpaceCenter_B1F_MapScripts::
	.byte 0

MossdeepCity_SpaceCenter_B1F_Temp_Computers::
	lock
	msgbox MossdeepCity_SpaceCenter_B1F_Temp_Computer_Text, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_B1F_Temp_Meteors::
	lock
	msgbox MossdeepCity_SpaceCenter_B1F_Temp_Meteor_Text, MSGBOX_SIGN
	release
	end

//MossdeepCity_SpaceCenter_B1F_Meteorite_Scientist::
//	lock
//	faceplayer
//	msgbox Meteorite_Scientist_Text, MSGBOX_DEFAULT
//	applymovement LOCALID_SCIENTIST_2, Common_Movement_WalkInPlaceFasterRight
//	waitmovement 0
//	release
//	end
//
MossdeepCity_SpaceCenter_B1F_Aurora_Ticket_Scientist::
	lockall
	faceplayer
	goto_if_set FLAG_ITEM_AURORA_TICKET, AlreadyHaveAuroraTicket
	msgbox AuroraTicketOffer, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	goto AlreadyHaveAuroraTicket
	end

AlreadyHaveAuroraTicket::
	msgbox AuroraTicketExplain, MSGBOX_DEFAULT
	applymovement LOCALID_SCIENTIST_1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SCIENTIST_1, Common_Movement_Delay48
	waitmovement 0
	msgbox AuroraTicketExplain2, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_B1F_Moon_Stone_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_SPACE_CENTER_GOT_MOON_STONE, AlreadyHaveMoonStone
	checkitemspace ITEM_MOON_STONE
	goto_if_eq VAR_RESULT, FALSE, NoRoomForMoonStone
	msgbox GetAMoonStoneText, MSGBOX_DEFAULT
	setflag FLAG_ITEM_SPACE_CENTER_GOT_MOON_STONE
	giveitem ITEM_MOON_STONE
	msgbox VisitAgainForMoreMoonStonesText, MSGBOX_DEFAULT
	applymovement LOCALID_SCIENTIST_3, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

AlreadyHaveMoonStone::
	msgbox AlreadyHaveMoonStoneText, MSGBOX_DEFAULT
	applymovement LOCALID_SCIENTIST_3, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

NoRoomForMoonStone::
	msgbox NoRoomForMoonStoneText, MSGBOX_DEFAULT
	applymovement LOCALID_SCIENTIST_3, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_B1F_Sun_Stone_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_SPACE_CENTER_GOT_SUN_STONE, AlreadyHaveSunStone
	checkitemspace ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, NoRoomForSunStone
	msgbox GetASunStoneText, MSGBOX_DEFAULT
	setflag FLAG_ITEM_SPACE_CENTER_GOT_SUN_STONE
	giveitem ITEM_SUN_STONE
	msgbox VisitAgainForMoreSunStonesText, MSGBOX_DEFAULT
	applymovement LOCALID_SCIENTIST_2, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

AlreadyHaveSunStone::
	msgbox AlreadyHaveSunStoneText, MSGBOX_DEFAULT
	applymovement LOCALID_SCIENTIST_2, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

NoRoomForSunStone::
	msgbox NoRoomForSunStoneText, MSGBOX_DEFAULT
	applymovement LOCALID_SCIENTIST_2, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

AuroraTicketOffer:
	.string "Welcome to MOSSDEEP SPACE CENTER!\p"
	.string "Please, take this AURORA TICKET as\n"
	.string "a souvenir!$"

AuroraTicketExplain:
	.string "I kept that extra ticket from a special\n"
	.string "event we did some time ago.\p"
	.string "I was thinking about using it myself,\n"
	.string "but I cant…$"

AuroraTicketExplain2:
	.string "… … … I get seasick easily.$"

GetAMoonStoneText:
	.string "While researching METEORITES, we\n"
	.string "sometimes come across MOON STONES.\p"
	.string "In fact, I'll let you have this one as\n"
	.string "a souvenir!$"

AlreadyHaveMoonStoneText:
	.string "While researching METEORITES, we\n"
	.string "sometimes come across MOON STONES.\p"
	.string "I'll let you have any extras we might\n"
	.string "find, so visit us again!$"

NoRoomForMoonStoneText:
	.string "While researching METEORITES, we\n"
	.string "sometimes come across MOON STONES.\p"
	.string "If you make room in your bag, I'll\n"
	.string "let you have this one as a souvenir!$"

VisitAgainForMoreMoonStonesText:
	.string "I'll let you have any extra MOON\n"
	.string "STONES I find, so visit us again!$"

GetASunStoneText:
	.string "Down in this lab we research\n"
	.string "METEORITES and other space samples.\p"
	.string "We hope to find clues leading to\n"
	.string "new extraterrestrial POKéMON!\p"
	.string "Say, why don't you take this\n"
	.string "SUN STONE as a souvenir?$"

AlreadyHaveSunStoneText:
	.string "Down in this lab we research\n"
	.string "METEORITES and other space samples.\p"
	.string "We hope to find clues leading to\n"
	.string "new extraterrestrial POKéMON!\p"
	.string "If I find any more SUN STONES, I'll\n"
	.string "let you have 'em, no problem!$"

NoRoomForSunStoneText:
	.string "Down in this lab we research\n"
	.string "METEORITES and other space samples.\p"
	.string "We hope to find clues leading to\n"
	.string "new extraterrestrial POKéMON!\p"
	.string "If you make space in your bag, I'll\n"
	.string "give you a SUN STONE as a souvenir!$"

VisitAgainForMoreSunStonesText:
	.string "If I find any more SUN STONES, I'll\n"
	.string "let you have 'em, no problem!$"

MossdeepCity_SpaceCenter_B1F_Temp_Computer_Text:
	.string "“…scanning METEORITE…\n"
	.string "… … … … … … … … … … … … …”\p"
	.string "“…analyzing structure…\n"
	.string "… … … … … … … … … … … … …”\p"
	.string "“… … … … … … … … … … … …\n"
	.string "… … … … … … … … … … … … …”$"
	
MossdeepCity_SpaceCenter_B1F_Temp_Meteor_Text:
	.string "This METEORITE is hooked up to the\n"
	.string "nearby computer… how fascinating!$"

