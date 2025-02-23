MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

FishingBook_EventScript::
	lockall
	msgbox MossdeepCity_House3_FishingBook, MSGBOX_DEFAULT
	goto MossdeepCity_House3_EventScript_ChooseBookChapter
	end

MossdeepCity_House3_EventScript_ChooseBookChapter::
	message MossdeepCity_House3_Text_ReadWhichTopic
	waitmessage
	multichoice 18, 0, MULTI_UNUSED_51, FALSE
	switch VAR_RESULT
	case 0, MossdeepCity_House3_EventScript_OldRodFishing
	case 1, MossdeepCity_House3_EventScript_GoodRodFishing
	case 2, MossdeepCity_House3_EventScript_SuperRodFishing
	case 3, MossdeepCity_House3_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, MossdeepCity_House3_EventScript_ExitTopicSelect
	end

MossdeepCity_House3_EventScript_OldRodFishing::
	msgbox MossdeepCity_House3_Text_ExplainOldRodFish, MSGBOX_DEFAULT
	goto MossdeepCity_House3_EventScript_ChooseBookChapter
	end

MossdeepCity_House3_EventScript_GoodRodFishing::
	msgbox MossdeepCity_House3_Text_ExplainGoodRodFish, MSGBOX_DEFAULT
	goto MossdeepCity_House3_EventScript_ChooseBookChapter
	end

MossdeepCity_House3_EventScript_SuperRodFishing::
	msgbox MossdeepCity_House3_Text_ExplainSuperRodFish, MSGBOX_DEFAULT
	goto MossdeepCity_House3_EventScript_ChooseBookChapter
	end

MossdeepCity_House3_EventScript_ExitTopicSelect::
	releaseall
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_SuperRodFishermanNephew::
	lock
	faceplayer
	msgbox MossdeepCity_House3_Text_SuperRodNephewText, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hey there, TRAINER!\n"
	.string "A SUPER ROD really is super!\p"
	.string "Say all you want, but this baby can\n"
	.string "catch POKéMON off the seafloor!\p"
	.string "What do you think?\n"
	.string "You want it, don't you?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "You bet, you bet!\n"
	.string "After all, a SUPER ROD is really super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "If there's any water, try dropping in\n"
	.string "your ROD and see what bites!\p"
	.string "If you need some ideas for what you\n"
	.string "might want to catch, check the guide\l"
	.string "in the bookshelf near the TV.\p"
	.string "That guide never fails me!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hunh?\n"
	.string "Don't you like to fish?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Go after the seafloor POKéMON with\n"
	.string "your SUPER ROD.$"

MossdeepCity_House3_Text_SuperRodNephewText:
	.string "Yesterday, uncle took me out deep sea\n"
	.string "fishing near PACIFIDLOG TOWN!\p"
	.string "I caught my first POKéMON, QWILFISH!\n"
	.string "Yup, me and QWILSON are best buds!$"

MossdeepCity_House3_FishingBook:
	.string "There's a fishing guide-book here…\p"
	.string "Many fish in the HOENN region can\n"
	.string "only be encountered by fishing.\p"
	.string "The species of fish encountered\n"
	.string "is dependant on fishing location\l"
	.string "and the qaulity of the fishing ROD.$"

MossdeepCity_House3_Text_ReadWhichTopic:
	.string "Which type of fishing are you\n" 
	.string "interested in?$"

MossdeepCity_House3_Text_ExplainOldRodFish:
	.string "If properly cared for, an OLD ROD\n"
	.string "may still be able to hook MAGIKARP,\l"
	.string "SHELLDER, GOLDEEN, TENTACOOL,\l"
	.string "KRABBY and FEEBAS.$"

MossdeepCity_House3_Text_ExplainGoodRodFish:
	.string "A fully functional GOOD ROD will\n"
	.string "be able to hook MAGIKARP,\p"
	.string "SHELLDER, GOLDEEN, TENTACOOL,\n"
	.string "KRABBY, FEEBAS, WAILMER,\p"
	.string "BARBOACH, CARVANHA, LUVDISC,\n"
	.string "POLIWAG, SLOWPOKE, and DRATINI.$"

MossdeepCity_House3_Text_ExplainSuperRodFish:
	.string "Being made of superior materials,\n"
	.string "the SUPER ROD can hook MAGIKARP,\p"
	.string "GYARADOS, SHELLDER, CORPHISH,\n"
	.string "WAILMER, CARVANHA, SHARPEDO,\p"
	.string "BARBOACH, WHISCASH, CORSOLA,\n"
	.string	"LUVDISC, POLIWAG, POLIWHIRL,\p"
	.string "HORSEA, STARYU, TENTACOOL,\n"
	.string "TENTACRUEL, KRABBY, KINGLER,\p"
	.string "GOLDEEN, SEAKING, QWILFISH,\n"
	.string "SLOWPOKE, SLOWBRO, and DRATINI.$"
