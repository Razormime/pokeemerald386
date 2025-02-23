.set LOCALID_MEWTWO, 1

AlteringCave_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_B3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_B3F_OnResume
	.byte 0

AlteringCave_B3F_OnTransition:
	call_if_set FLAG_CAUGHT_MEWTWO, AlteringCave_B3F_EventScript_HideMewtwo
	call_if_unset FLAG_CAUGHT_MEWTWO, AlteringCave_B3F_EventScript_TryShowMewtwo
	end

AlteringCave_B3F_EventScript_HideMewtwo::
	setflag FLAG_HIDE_MEWTWO
	return

AlteringCave_B3F_EventScript_TryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEWTWO
	return

AlteringCave_B3F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_B3F_EventScript_TryRemoveMewtwo
	end

AlteringCave_B3F_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MEWTWO
	return

AlteringCave_B3F_EventScript_Mewtwo::
	lock
	faceplayer
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MEWTWO, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_B3F_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_B3F_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_B3F_EventScript_RanFromMewtwo
	setflag FLAG_CAUGHT_MEWTWO
	release
	end

AlteringCave_B3F_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryTeleportedAway
	end

AlteringCave_B3F_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryTeleportedAway
	end
