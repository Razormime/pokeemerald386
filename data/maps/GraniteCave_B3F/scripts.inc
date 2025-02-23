.set LOCALID_LAPRAS, 1

GraniteCave_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B3F_OnResume
	.byte 0

GraniteCave_B3F_OnTransition:
	call_if_set FLAG_CAUGHT_LAPRAS, GraniteCave_B3F_EventScript_HideLapras
	call_if_unset FLAG_CAUGHT_LAPRAS, GraniteCave_B3F_EventScript_TryShowLapras
	end

GraniteCave_B3F_EventScript_HideLapras::
	setflag FLAG_HIDE_LAPRAS
	return

GraniteCave_B3F_EventScript_TryShowLapras::
	goto_if_set FLAG_DEFEATED_LAPRAS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LAPRAS
	return

GraniteCave_B3F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, GraniteCave_B3F_EventScript_TryRemoveLapras
	end

GraniteCave_B3F_EventScript_TryRemoveLapras::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LAPRAS
	return

GraniteCave_B3F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_LAPRAS, 20, ITEM_NEVER_MELT_ICE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCave_B3F_EventScript_DefeatedLapras
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCave_B3F_EventScript_RanFromLapras
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCave_B3F_EventScript_RanFromLapras
	setflag FLAG_CAUGHT_LAPRAS
	release
	end

GraniteCave_B3F_EventScript_DefeatedLapras::
	setflag FLAG_DEFEATED_LAPRAS
	setvar VAR_0x8004, SPECIES_LAPRAS
	goto Common_EventScript_LegendaryHidUnderwater
	end

GraniteCave_B3F_EventScript_RanFromLapras::
	setvar VAR_0x8004, SPECIES_LAPRAS
	goto Common_EventScript_LegendaryHidUnderwater
	end
