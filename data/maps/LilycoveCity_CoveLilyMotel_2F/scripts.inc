LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_Stereo::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_2F_EventScript_Stereo2
	msgbox NoBGMSelectionText, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Stereo2::
	msgbox BGMSelectionText, MSGBOX_DEFAULT
	waitmessage
	closemessage
	multichoice 17, 0, MULTI_UNUSED_SSTIDAL_4, FALSE
	switch VAR_RESULT
	case 0, BGM_ST_Anne
	case 1, BGM_Viridian_Forest_Select
	case 2, BGM_Lavender_Town_Select
	case 3, BGM_Pokemon_Tower_Select
	case 4, BGM_Pokemon_Mansion_Select
	case 5, BGM_Silph_CO_Select
	case 6, BGM_Rocket_Hideout_Select
	case 7, BGM_Cancel
	case MULTI_B_PRESSED, BGM_Cancel
	end

BGM_ST_Anne::
	playse SE_RG_BALL_CLICK
	waitse
	fadeoutbgm 1
	playbgm MUS_RG_SS_ANNE, TRUE
	release
	end

BGM_Viridian_Forest_Select::
	playse SE_RG_BALL_CLICK
	waitse
	fadeoutbgm 1
	playbgm MUS_RG_VIRIDIAN_FOREST, TRUE
	release
	end

BGM_Lavender_Town_Select::
	playse SE_RG_BALL_CLICK
	waitse
	fadeoutbgm 1
	playbgm MUS_RG_LAVENDER, TRUE
	release
	end

BGM_Pokemon_Tower_Select::
	playse SE_RG_BALL_CLICK
	waitse
	fadeoutbgm 1
	playbgm MUS_RG_POKE_TOWER, TRUE
	release
	end

BGM_Pokemon_Mansion_Select::
	playse SE_RG_BALL_CLICK
	waitse
	fadeoutbgm 1
	playbgm MUS_RG_POKE_MANSION, TRUE
	release
	end

BGM_Silph_CO_Select::
	playse SE_RG_BALL_CLICK
	waitse
	fadeoutbgm 1
	playbgm MUS_RG_SILPH, TRUE
	release
	end

BGM_Rocket_Hideout_Select::
	playse SE_RG_BALL_CLICK
	waitse
	fadeoutbgm 1
	playbgm MUS_RG_ROCKET_HIDEOUT, TRUE
	release
	end

BGM_Cancel::
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

NoBGMSelectionText:
	.string "There's a stereo here…$"

BGMSelectionText:
	.string "The stereo has a video game OST\n"
	.string "loaded into it!\p"
	.string "Which track sounds interesting…$"

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "I'm the GAME DESIGNER.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a POKéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This POKéDEX is completely filled!\n"
	.string "You really must love POKéMON!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Me? You're talking to me?\n"
	.string "I'm the PROGRAMMER.\p"
	.string "I wonder what the SLOTS are\n"
	.string "like here.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
	.string "POKéMON of HOENN interesting?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "The girl TUBERS, they're cute, hey?\n"
	.string "To battle against a cute TUBER…\p"
	.string "Whoop, it's so awesome!\p"
	.string "And the TWINS! Aren't they cute?\n"
	.string "A 2-on-2 battle with TWINS…\p"
	.string "Whoop, it's unbearably fun!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this POKéMON\n"
	.string "CONTEST thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough TRAINERS.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
	.string "the whole works!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: I think it does take strategy\n"
	.string "to win a CONTEST.\p"
	.string "Devising CONTEST strategies is one way\n"
	.string "of becoming a better TRAINER, I'd say.$"

