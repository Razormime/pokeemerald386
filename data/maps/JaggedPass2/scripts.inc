.set LOCALID_MOLTRES, 1

JaggedPass2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass2_OnResume
	.byte 0

JaggedPass2_OnTransition:
	call_if_set FLAG_CAUGHT_MOLTRES, JaggedPass2_EventScript_HideMoltres
	call_if_unset FLAG_CAUGHT_MOLTRES, JaggedPass2_EventScript_TryShowMoltres
	end

JaggedPass2_EventScript_HideMoltres::
	setflag FLAG_HIDE_MOLTRES
	return

JaggedPass2_EventScript_TryShowMoltres::
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MOLTRES
	return

JaggedPass2_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, JaggedPass2_EventScript_TryRemoveMoltres
	end

JaggedPass2_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MOLTRES
	return

JaggedPass2_EventScript_Moltres::
	lock
	faceplayer
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MOLTRES, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, JaggedPass2_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, JaggedPass2_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, JaggedPass2_EventScript_RanFromMoltres
	setflag FLAG_CAUGHT_MOLTRES
	release
	end

JaggedPass2_EventScript_DefeatedMoltres::
	setflag FLAG_DEFEATED_MOLTRES
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

JaggedPass2_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end
//
//JaggedPass2_EventScript_SunTrigger::
//	setweather WEATHER_SUNNY
//	doweather
//	end
//
//JaggedPass2_EventScript_AshTrigger::
//	setweather WEATHER_VOLCANIC_ASH
//	doweather
//	end
