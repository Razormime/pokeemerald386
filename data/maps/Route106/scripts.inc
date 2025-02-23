Route106_MapScripts::
	.byte 0

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Lapras_Tuber::
	goto_if_set FLAG_CAUGHT_LAPRAS, Route106_EventScript_Lapras_Tuber_No_Roar
	goto_if_set FLAG_DEFEATED_LAPRAS, Route106_EventScript_Lapras_Tuber_No_Roar
	msgbox TuberText_LaprasRoar, MSGBOX_NPC
	end

Route106_EventScript_Lapras_Tuber_No_Roar::
	msgbox TuberText_LaprasNoRoar, MSGBOX_NPC
	end

Route106_EventScript_Lapras_Tuber2::
	goto_if_set FLAG_CAUGHT_LAPRAS, Route106_EventScript_Lapras_Tuber_No_Roar2
	goto_if_set FLAG_DEFEATED_LAPRAS, Route106_EventScript_Lapras_Tuber_No_Roar2
	msgbox Tuber2Text_LaprasRoar, MSGBOX_NPC
	end

Route106_EventScript_Lapras_Tuber_No_Roar2::
	msgbox Tuber2Text_LaprasNoRoar, MSGBOX_NPC
	end

Route106_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

TuberText_LaprasRoar:
	.string "We wanna make this our hideout.\p"
	.string "But we can hear something in there…$"

TuberText_LaprasNoRoar:
	.string "This island is our hideout now!\p"
	.string "…unless the monster comes back…$"

Tuber2Text_LaprasRoar:
	.string "I think a monster is trapped deep in\n"
	.string "the cave, but I cant see anything…$"

Tuber2Text_LaprasNoRoar:
	.string "The monster is gone!\p"
	.string "…we hope…$"
