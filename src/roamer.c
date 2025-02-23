#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "pokedex.h"
#include "battle_tower.h" // GetHighestLevelInPlayerParty declaration

//================= RoamersPlus Config =================\\
// Set to TRUE to allow roaming to every Route
#define ROAM_THE_ENTIRE_MAP FALSE
// 1 in 4 chance for a roamer to replace other encounters
#define ROAMER_ENCOUNTER_MODULO 4
// 1 in 6 chance for a stalker to replace other encounters
#define STALKER_ENCOUNTER_MODULO 10
// Scaling roamer level will be equal to your highest level pokemon's level plus this constant
#define SCALING_LEVEL_MODIFIER -5
// Self Explanatory
#define SCALED_LEVEL_CAP 70
// If TRUE, scaling roamers will evolve at appropriate levels
#define SCALING_ROAMER_EVOLUTION FALSE
//================= Config End =========================\\

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 0
// Stalkers can move to other map groups
#define ROAMER_MAP_GROUP 0

enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};

//#define ROAMER (&gSaveBlock1Ptr->roamer)
//EWRAM_DATA static u8 sLocationHistory[3][2] = {0};
//EWRAM_DATA static u8 sRoamerLocation[2] = {0};
#define ROAMER(index) (&gSaveBlock1Ptr->roamer[index])
EWRAM_DATA static u8 sLocationHistory[ROAMER_COUNT][3][2] = {0};
EWRAM_DATA static u8 sRoamerLocation[ROAMER_COUNT][2] = {0};
EWRAM_DATA u8 gEncounteredRoamerIndex = 0;

#define ___ MAP_NUM(UNDEFINED) // For empty spots in the location table

// Note: There are two potential softlocks that can occur with this table if its maps are
//       changed in particular ways. They can be avoided by ensuring the following:
//       - There must be at least 2 location sets that start with a different map,
//         i.e. every location set cannot start with the same map. This is because of
//         the while loop in RoamerMoveToOtherLocationSet.
//       - Each location set must have at least 3 unique maps. This is because of
//         the while loop in RoamerMove. In this loop the first map in the set is
//         ignored, and an additional map is ignored if the roamer was there recently.
//       - Additionally, while not a softlock, it's worth noting that if for any
//         map in the location table there is not a location set that starts with
//         that map then the roamer will be significantly less likely to move away
//         from that map when it lands there.
static const u8 sRoamerLocations[][6] =
#if !ROAM_THE_ENTIRE_MAP
{
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE134), ___ },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), ___, ___ },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE118), ___, ___ },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), ___, ___, ___ },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), ___, ___, ___ },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), MAP_NUM(ROUTE122), MAP_NUM(ROUTE123), ___, ___ },
    { MAP_NUM(ROUTE122), MAP_NUM(ROUTE121), MAP_NUM(ROUTE123), ___, ___, ___ },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE122), MAP_NUM(ROUTE118), ___, ___, ___ },
    { MAP_NUM(ROUTE124), MAP_NUM(ROUTE121), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), ___, ___ },
    { MAP_NUM(ROUTE125), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE126), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE127), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), MAP_NUM(ROUTE128), ___, ___ },
    { MAP_NUM(ROUTE128), MAP_NUM(ROUTE127), MAP_NUM(ROUTE129), ___, ___, ___ },
    { MAP_NUM(ROUTE129), MAP_NUM(ROUTE128), MAP_NUM(ROUTE130), ___, ___, ___ },
    { MAP_NUM(ROUTE130), MAP_NUM(ROUTE129), MAP_NUM(ROUTE131), ___, ___, ___ },
    { MAP_NUM(ROUTE131), MAP_NUM(ROUTE130), MAP_NUM(ROUTE132), ___, ___, ___ },
    { MAP_NUM(ROUTE132), MAP_NUM(ROUTE131), MAP_NUM(ROUTE133), ___, ___, ___ },
    { MAP_NUM(ROUTE133), MAP_NUM(ROUTE132), MAP_NUM(ROUTE134), ___, ___, ___ },
    { MAP_NUM(ROUTE134), MAP_NUM(ROUTE133), MAP_NUM(ROUTE110), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};
#else
{
    { MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE103), ___, ___, ___ },
    { MAP_NUM(ROUTE102), MAP_NUM(ROUTE101), MAP_NUM(ROUTE103), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE103), MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE110), ___, ___ },
    { MAP_NUM(ROUTE104), MAP_NUM(ROUTE102), MAP_NUM(ROUTE105), MAP_NUM(ROUTE116), MAP_NUM(ROUTE115), ___ },
    { MAP_NUM(ROUTE105), MAP_NUM(ROUTE104), MAP_NUM(ROUTE106), ___, ___, ___ },
    { MAP_NUM(ROUTE106), MAP_NUM(ROUTE105), MAP_NUM(ROUTE107), ___, ___, ___ },
    { MAP_NUM(ROUTE107), MAP_NUM(ROUTE106), MAP_NUM(ROUTE108), ___, ___, ___ },
    { MAP_NUM(ROUTE108), MAP_NUM(ROUTE107), MAP_NUM(ROUTE109), ___, ___, ___ },
    { MAP_NUM(ROUTE109), MAP_NUM(ROUTE108), MAP_NUM(ROUTE110), MAP_NUM(ROUTE134), ___, ___ },
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE109), MAP_NUM(ROUTE103) },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE113), MAP_NUM(ROUTE112) },
    { MAP_NUM(ROUTE112), MAP_NUM(ROUTE111), MAP_NUM(ROUTE113), ___, ___, ___ },
    { MAP_NUM(ROUTE113), MAP_NUM(ROUTE111), MAP_NUM(ROUTE114), MAP_NUM(ROUTE112), ___, ___ },
    { MAP_NUM(ROUTE114), MAP_NUM(ROUTE113), MAP_NUM(ROUTE115), ___, ___, ___ },
    { MAP_NUM(ROUTE115), MAP_NUM(ROUTE114), MAP_NUM(ROUTE116), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE116), MAP_NUM(ROUTE115), MAP_NUM(ROUTE117), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE118), MAP_NUM(ROUTE116), ___ },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), ___, ___, ___ },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), ___, ___, ___ },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), MAP_NUM(ROUTE122), MAP_NUM(ROUTE124), ___, ___ },
    { MAP_NUM(ROUTE122), MAP_NUM(ROUTE121), MAP_NUM(ROUTE123), ___, ___, ___ },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE122), MAP_NUM(ROUTE118), ___, ___, ___ },
    { MAP_NUM(ROUTE124), MAP_NUM(ROUTE121), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), ___, ___ },
    { MAP_NUM(ROUTE125), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE126), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE127), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), MAP_NUM(ROUTE128), ___, ___ },
    { MAP_NUM(ROUTE128), MAP_NUM(ROUTE127), MAP_NUM(ROUTE129), ___, ___, ___ },
    { MAP_NUM(ROUTE129), MAP_NUM(ROUTE128), MAP_NUM(ROUTE130), ___, ___, ___ },
    { MAP_NUM(ROUTE130), MAP_NUM(ROUTE129), MAP_NUM(ROUTE131), ___, ___, ___ },
    { MAP_NUM(ROUTE131), MAP_NUM(ROUTE130), MAP_NUM(ROUTE132), ___, ___, ___ },
    { MAP_NUM(ROUTE132), MAP_NUM(ROUTE131), MAP_NUM(ROUTE133), ___, ___, ___ },
    { MAP_NUM(ROUTE133), MAP_NUM(ROUTE132), MAP_NUM(ROUTE134), ___, ___, ___ },
    { MAP_NUM(ROUTE134), MAP_NUM(ROUTE133), MAP_NUM(ROUTE110), MAP_NUM(ROUTE109), ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};
#endif

static const u8 sTerrestrialLocations[][6] =
{
    { MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE103), ___, ___, ___ },
    { MAP_NUM(ROUTE102), MAP_NUM(ROUTE101), MAP_NUM(ROUTE103), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE103), MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE110), ___, ___ },
    { MAP_NUM(ROUTE104), MAP_NUM(ROUTE102), MAP_NUM(ROUTE115), MAP_NUM(ROUTE116), ___, ___ },
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE103), ___ },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE113), MAP_NUM(ROUTE112) },
    { MAP_NUM(ROUTE112), MAP_NUM(ROUTE111), MAP_NUM(ROUTE113), ___, ___, ___ },
    { MAP_NUM(ROUTE113), MAP_NUM(ROUTE111), MAP_NUM(ROUTE114), MAP_NUM(ROUTE112), ___, ___ },
    { MAP_NUM(ROUTE114), MAP_NUM(ROUTE113), MAP_NUM(ROUTE115), ___, ___, ___ },
    { MAP_NUM(ROUTE115), MAP_NUM(ROUTE114), MAP_NUM(ROUTE116), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE116), MAP_NUM(ROUTE115), MAP_NUM(ROUTE117), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE118), MAP_NUM(ROUTE116), ___ },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), ___, ___, ___ },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), ___, ___, ___ },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), MAP_NUM(ROUTE123), ___, ___, ___ },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE121), MAP_NUM(ROUTE118), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

#undef ___
#define NUM_LOCATION_SETS (ARRAY_COUNT(sRoamerLocations) - 1)
#define NUM_TERRESTRIAL_SETS (ARRAY_COUNT(sTerrestrialLocations) - 1)
#define NUM_LOCATIONS_PER_SET (ARRAY_COUNT(sRoamerLocations[0]))

//void ClearRoamerData(void)
void StopAllRoamers(void)
{
//    memset(ROAMER, 0, sizeof(*ROAMER));
//    ROAMER->species = SPECIES_LATIAS;
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        StopRoamer(i);
}

//void ClearRoamerLocationData(void)
static void ClearRoamerLocationHistory(u8 index)
{
//    u8 i;
	u32 i;

//    for (i = 0; i < ARRAY_COUNT(sLocationHistory); i++)
	for (i = 0; i < ARRAY_COUNT(sLocationHistory[index]); i++)
    {
//        sLocationHistory[i][MAP_GRP] = 0;
//        sLocationHistory[i][MAP_NUM] = 0;
		sLocationHistory[index][i][MAP_GRP] = 0x7F; // 0 is Petalburg city
        sLocationHistory[index][i][MAP_NUM] = 0x7F; // 0x7F is MAP_NONE
    }
//
//    sRoamerLocation[MAP_GRP] = 0;
//    sRoamerLocation[MAP_NUM] = 0;
}

//static void CreateInitialRoamerMon(bool16 createLatios)
static void CreateInitialRoamerMon(u8 index, u16 species, u8 level, bool8 isTerrestrial, bool8 doesNotFlee, bool8 isStalker, u16 respawnMode)
{
//    if (!createLatios)
//        ROAMER->species = SPECIES_LATIAS;
	CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    ROAMER(index)->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
    ROAMER(index)->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
    ROAMER(index)->species = species;
    ROAMER(index)->respawnMode = respawnMode;
    ROAMER(index)->daysToRespawn = 0;
    ROAMER(index)->damage = 0;
    ROAMER(index)->level = level;
    ROAMER(index)->status = 0;
    ROAMER(index)->active = TRUE;
    ROAMER(index)->isTerrestrial = isTerrestrial;
    ROAMER(index)->doesNotFlee = doesNotFlee;
    ROAMER(index)->isStalker = isStalker;
    if (level == 0)
        ROAMER(index)->levelScaling = TRUE;
    else
        ROAMER(index)->levelScaling = FALSE;
    sRoamerLocation[index][MAP_GRP] = ROAMER_MAP_GROUP;
    if (!isTerrestrial)
        sRoamerLocation[index][MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
    else
//        ROAMER->species = SPECIES_LATIOS;
//
//    CreateMon(&gEnemyParty[0], ROAMER->species, 40, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
//    ROAMER->level = 40;
//    ROAMER->status = 0;
//    ROAMER->active = TRUE;
//    ROAMER->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
//    ROAMER->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
//    ROAMER->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
//    ROAMER->cool = GetMonData(&gEnemyParty[0], MON_DATA_COOL);
//    ROAMER->beauty = GetMonData(&gEnemyParty[0], MON_DATA_BEAUTY);
//    ROAMER->cute = GetMonData(&gEnemyParty[0], MON_DATA_CUTE);
//    ROAMER->smart = GetMonData(&gEnemyParty[0], MON_DATA_SMART);
//    ROAMER->tough = GetMonData(&gEnemyParty[0], MON_DATA_TOUGH);
//    sRoamerLocation[MAP_GRP] = ROAMER_MAP_GROUP;
//    sRoamerLocation[MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
        sRoamerLocation[index][MAP_NUM] = sTerrestrialLocations[Random() % NUM_TERRESTRIAL_SETS][0];
    ClearRoamerLocationHistory(index);
}

// gSpecialVar_0x8004 here corresponds to the options in the multichoice MULTI_TV_LATI (0 for 'Red', 1 for 'Blue')
void InitRoamer(void)
{
//    ClearRoamerData();
//    ClearRoamerLocationData();
//    CreateInitialRoamerMon(gSpecialVar_0x8004);
//#if !MULTIPLE_ROAMERS_EXAMPLE
    // Vanilla Behaviour
        TryAddRoamer(SPECIES_SUICUNE, 40, FLEES, DAILY_RESPAWN); 
        TryAddTerrestrialRoamer(SPECIES_RAIKOU, 40, FLEES, DAILY_RESPAWN); 
        TryAddTerrestrialRoamer(SPECIES_ENTEI, 40, FLEES, DAILY_RESPAWN); 
		TryAddStalker(SPECIES_CELEBI, 30, DOES_NOT_FLEE, AMPHIBIOUS, INSTANT_RESPAWN);
//        GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_SUICUNE), FLAG_SET_SEEN); 
//        GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_RAIKOU), FLAG_SET_SEEN); 
//        GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ENTEI), FLAG_SET_SEEN); 
//	    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LATIAS), FLAG_SET_SEEN); //Sets Pokedex to seen
//		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LATIOS), FLAG_SET_SEEN);
    if (gSpecialVar_0x8004 == 1)
        TryAddRoamer(SPECIES_LATIOS, 40, FLEES, DAILY_RESPAWN);  
    else
        TryAddRoamer(SPECIES_LATIAS, 40, FLEES, DAILY_RESPAWN);
//#else
//	TryAddRoamer(SPECIES_SUICUNE, 40, FLEES, INSTANT_RESPAWN);
//	TryAddTerrestrialRoamer(SPECIES_RAIKOU, 40, FLEES, INSTANT_RESPAWN);
//	TryAddTerrestrialRoamer(SPECIES_ENTEI, 40, FLEES, INSTANT_RESPAWN);
//    TryAddRoamer(SPECIES_LATIAS, 40, FLEES, WEEKLY_RESPAWN);
//    TryAddRoamer(SPECIES_LATIOS, 40, FLEES, WEEKLY_RESPAWN);
//    TryAddTerrestrialRoamer(SPECIES_PIKACHU, 8, FLEES, DAILY_RESPAWN);
//    TryAddTerrestrialRoamer(SPECIES_PIKACHU, 15, DOES_NOT_FLEE, NO_RESPAWN);
//    TryAddStalker(SPECIES_WEEDLE, 0, DOES_NOT_FLEE, AMPHIBIOUS, INSTANT_RESPAWN);
//    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LATIAS), FLAG_SET_SEEN); //Sets Pokedex to seen
//    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LATIOS), FLAG_SET_SEEN);
//    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_PIKACHU), FLAG_SET_SEEN);
//    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_SUICUNE), FLAG_SET_SEEN);
//	GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_RAIKOU), FLAG_SET_SEEN);
//	GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ENTEI), FLAG_SET_SEEN);
//#endif
}

void UpdateLocationHistoryForRoamer(void)
{
//    sLocationHistory[2][MAP_GRP] = sLocationHistory[1][MAP_GRP];
//    sLocationHistory[2][MAP_NUM] = sLocationHistory[1][MAP_NUM];
	u32 i;
    for (i = 0; i < ROAMER_COUNT; i++)
    {
        sLocationHistory[i][2][MAP_GRP] = sLocationHistory[i][1][MAP_GRP];
        sLocationHistory[i][2][MAP_NUM] = sLocationHistory[i][1][MAP_NUM];

//    sLocationHistory[1][MAP_GRP] = sLocationHistory[0][MAP_GRP];
//    sLocationHistory[1][MAP_NUM] = sLocationHistory[0][MAP_NUM];
	    sLocationHistory[i][1][MAP_GRP] = sLocationHistory[i][0][MAP_GRP];
        sLocationHistory[i][1][MAP_NUM] = sLocationHistory[i][0][MAP_NUM];

//    sLocationHistory[0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
//    sLocationHistory[0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
	    sLocationHistory[i][0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
        sLocationHistory[i][0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
    }
}

//void RoamerMoveToOtherLocationSet(void)
void RoamerMoveToOtherLocationSet(u8 index)
{
    u8 mapNum = 0;
    const u8 (*locations)[6];
    u32 LocationSetCount;

//    if (!ROAMER->active)
	if (!ROAMER(index)->active)
        return;
//
//    sRoamerLocation[MAP_GRP] = ROAMER_MAP_GROUP;
//
//    // Choose a location set that starts with a map
//    // different from the roamer's current map
//    while (1)
	if (ROAMER(index)->isStalker)
    {
//        mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
//        if (sRoamerLocation[MAP_NUM] != mapNum)
		// If moving after fighting the player, stalkers leave the area
        if (IsRoamerAt(index, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
        {
//            sRoamerLocation[index][MAP_GRP] = MAP_GROUP(NONE);
			sRoamerLocation[index][MAP_GRP] = MAP_GROUP(UNDEFINED);
//            sRoamerLocation[index][MAP_NUM] = MAP_NUM(NONE);
			sRoamerLocation[index][MAP_NUM] = MAP_NUM(UNDEFINED);
            return;
        }
        else
        {
//            sRoamerLocation[MAP_NUM] = mapNum;
			//else they always move to the player's area
            sRoamerLocation[index][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
            sRoamerLocation[index][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
            return;
        }
    }


    sRoamerLocation[index][MAP_GRP] = ROAMER_MAP_GROUP;

    if (!ROAMER(index)->isTerrestrial)
    {
        locations = sRoamerLocations;
        LocationSetCount = NUM_LOCATION_SETS;
    }
    else
    {
        locations = sTerrestrialLocations;
        LocationSetCount = NUM_TERRESTRIAL_SETS;
    }
    // Choose a location set that starts with a map
    // different from the roamer's current map
    do {
        mapNum = locations[Random() % LocationSetCount][0];
    } while (sRoamerLocation[index][MAP_NUM] == mapNum);
    sRoamerLocation[index][MAP_NUM] = mapNum;
}

//void RoamerMove(void)
void RoamerMove(u8 index)
{
    u8 locSet = 0;
	if ((Random() % 16) == 0 || ROAMER(index)->isStalker)
//    if ((Random() % 16) == 0)
    {
//        RoamerMoveToOtherLocationSet();
		RoamerMoveToOtherLocationSet(index);
    }
    else
    {
//        if (!ROAMER->active)
		const u8 (*locations)[6];
        u32 LocationSetCount;

        if (!ROAMER(index)->active)
            return;

		if (!ROAMER(index)->isTerrestrial)
        {
            locations = sRoamerLocations;
            LocationSetCount = NUM_LOCATION_SETS;
        }
        else
        {
            locations = sTerrestrialLocations;
            LocationSetCount = NUM_TERRESTRIAL_SETS;
        }
//        while (locSet < NUM_LOCATION_SETS)
		while (locSet < LocationSetCount)
        {
            // Find the location set that starts with the roamer's current map
//            if (sRoamerLocation[MAP_NUM] == sRoamerLocations[locSet][0])
			if (sRoamerLocation[index][MAP_NUM] == locations[locSet][0])
            {
                u8 mapNum;
//                while (1)
//                {
//                    // Choose a new map (excluding the first) within this set
//                    // Also exclude a map if the roamer was there 2 moves ago
//                    mapNum = sRoamerLocations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
//                    if (!(sLocationHistory[2][MAP_GRP] == ROAMER_MAP_GROUP
//                       && sLocationHistory[2][MAP_NUM] == mapNum)
//                       && mapNum != MAP_NUM(UNDEFINED))
//                        break;
//                }
//                sRoamerLocation[MAP_NUM] = mapNum;
				// Choose a new map (excluding the first) within this set
                // Also exclude a map if the roamer was there 2 moves ago
                do {
                    mapNum = locations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                } while ((sLocationHistory[index][2][MAP_GRP] == ROAMER_MAP_GROUP
                        && sLocationHistory[index][2][MAP_NUM] == mapNum)
                        || mapNum == MAP_NUM(UNDEFINED));
                sRoamerLocation[index][MAP_NUM] = mapNum;
                return;
            }
            locSet++;
        }
    }
}

//bool8 IsRoamerAt(u8 mapGroup, u8 mapNum)
bool8 IsRoamerAt(u8 index, u8 mapGroup, u8 mapNum)
{
//    if (ROAMER->active && mapGroup == sRoamerLocation[MAP_GRP] && mapNum == sRoamerLocation[MAP_NUM])
    if (ROAMER(index)->active && mapGroup == sRoamerLocation[index][MAP_GRP] && mapNum == sRoamerLocation[index][MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

//void CreateRoamerMonInstance(void)
void CreateRoamerMonInstance(u8 index)
{
//    u32 status;
	// The roamer's status field is u8, but SetMonData expects status to be u32
    u32 status = ROAMER(index)->status;
    u16 hp;
    struct Pokemon *mon = &gEnemyParty[0];

    ZeroEnemyPartyMons();
//    CreateMonWithIVsPersonality(mon, ROAMER->species, ROAMER->level, ROAMER->ivs, ROAMER->personality);
//// The roamer's status field is u8, but SetMonData expects status to be u32, so will set the roamer's status
//// using the status field and the following 3 bytes (cool, beauty, and cute).
//#ifdef BUGFIX
//    status = ROAMER->status;
//    SetMonData(mon, MON_DATA_STATUS, &status);
#if SCALING_ROAMER_EVOLUTION
    if (ROAMER(index)->levelScaling)
    {
        u16 evoSpecies;

        ROAMER(index)->level = max(max(min(GetHighestLevelInPlayerParty() + SCALING_LEVEL_MODIFIER, SCALED_LEVEL_CAP), MIN_LEVEL), ROAMER(index)->level);
        CreateMonWithIVsPersonality(mon, ROAMER(index)->species, ROAMER(index)->level, ROAMER(index)->ivs, ROAMER(index)->personality);
        evoSpecies = GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, 0);
        while (evoSpecies != SPECIES_NONE)
        {
            ROAMER(index)->species = evoSpecies;
            CreateMonWithIVsPersonality(mon, evoSpecies, ROAMER(index)->level, ROAMER(index)->ivs, ROAMER(index)->personality);
            evoSpecies = GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, 0);
        }
    }
    else
        CreateMonWithIVsPersonality(mon, ROAMER(index)->species, ROAMER(index)->level, ROAMER(index)->ivs, ROAMER(index)->personality);
#else
//    SetMonData(mon, MON_DATA_STATUS, &ROAMER->status);
	if (ROAMER(index)->levelScaling)
        ROAMER(index)->level = max(max(min(GetHighestLevelInPlayerParty() - SCALING_LEVEL_MODIFIER, MAX_LEVEL), MIN_LEVEL), ROAMER(index)->level);
    CreateMonWithIVsPersonality(mon, ROAMER(index)->species, ROAMER(index)->level, ROAMER(index)->ivs, ROAMER(index)->personality);
#endif
//    SetMonData(mon, MON_DATA_HP, &ROAMER->hp);
//    SetMonData(mon, MON_DATA_COOL, &ROAMER->cool);
//    SetMonData(mon, MON_DATA_BEAUTY, &ROAMER->beauty);
//    SetMonData(mon, MON_DATA_CUTE, &ROAMER->cute);
//    SetMonData(mon, MON_DATA_SMART, &ROAMER->smart);
//    SetMonData(mon, MON_DATA_TOUGH, &ROAMER->tough);
	hp = GetMonData(mon, MON_DATA_MAX_HP) - ROAMER(index)->damage;
    SetMonData(mon, MON_DATA_STATUS, &status);
    SetMonData(mon, MON_DATA_HP, &hp);
}

//bool8 TryStartRoamerEncounter(void)
bool8 TryStartRoamerEncounter(bool8 isWaterEncounter)
{
//    if (IsRoamerAt(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
	u32 i;
    for (i = 0; i < ROAMER_COUNT; i++)
    {
//        CreateRoamerMonInstance();
//        return TRUE;
		if (IsRoamerAt(i, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)
            && !(ROAMER(i)->isTerrestrial && isWaterEncounter)
            && ((!ROAMER(i)->isStalker && (Random() % ROAMER_ENCOUNTER_MODULO) == 0)
            || (ROAMER(i)->isStalker && (Random() % STALKER_ENCOUNTER_MODULO) == 0)))
        {
            CreateRoamerMonInstance(i);
            gEncounteredRoamerIndex = i;
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    u16 currentHP = GetMonData(mon, MON_DATA_HP);
    if (currentHP == 0 && CanRoamerRespawn(gEncounteredRoamerIndex))
    {
        ROAMER(gEncounteredRoamerIndex)->damage = 0;
        ROAMER(gEncounteredRoamerIndex)->status = 0;
    }
    else
    {
//        return FALSE;
		ROAMER(gEncounteredRoamerIndex)->damage = GetMonData(mon, MON_DATA_MAX_HP) - GetMonData(mon, MON_DATA_HP);
        ROAMER(gEncounteredRoamerIndex)->status = GetMonData(mon, MON_DATA_STATUS);
    }

    RoamerMoveToOtherLocationSet(gEncounteredRoamerIndex);
}

//void UpdateRoamerHPStatus(struct Pokemon *mon)
void GetRoamerLocation(u8 index, u8 *mapGroup, u8 *mapNum)
{
//    ROAMER->hp = GetMonData(mon, MON_DATA_HP);
//    ROAMER->status = GetMonData(mon, MON_DATA_STATUS);
	*mapGroup = sRoamerLocation[index][MAP_GRP];
    *mapNum = sRoamerLocation[index][MAP_NUM];
}

//    RoamerMoveToOtherLocationSet();
static u8 GetFirstInactiveRoamerIndex()
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (!ROAMER(i)->active && !CanRoamerRespawn(i))
        {
            return i;
        }
    }
    return ROAMER_COUNT;
}

bool8 TryAddRoamer(u16 species, u8 level, bool8 doesNotFlee, u16 respawnMode)
{
    u8 index = GetFirstInactiveRoamerIndex();

    if (index < ROAMER_COUNT)
    {
        CreateInitialRoamerMon(index, species, level, AMPHIBIOUS, doesNotFlee, NOT_STALKER, respawnMode);
        return TRUE;
    }
    // Maximum active roamers: do nothing and let the calling function know
    return FALSE;
}

//void SetRoamerInactive(void)
bool8 TryAddTerrestrialRoamer(u16 species, u8 level, bool8 doesNotFlee, u16 respawnMode)
{
//    ROAMER->active = FALSE;
	u8 index = GetFirstInactiveRoamerIndex();

    if (index < ROAMER_COUNT)
    {
        CreateInitialRoamerMon(index, species, level, TERRESTRIAL, doesNotFlee, NOT_STALKER, respawnMode);
        return TRUE;
    }
    return FALSE;
}

//void GetRoamerLocation(u8 *mapGroup, u8 *mapNum)
bool8 TryAddStalker(u16 species, u8 level, bool8 doesNotFlee, bool8 isTerrestrial, u16 respawnMode)
{
//    *mapGroup = sRoamerLocation[MAP_GRP];
//    *mapNum = sRoamerLocation[MAP_NUM];
	u8 index = GetFirstInactiveRoamerIndex();

    if (index < ROAMER_COUNT)
    {
        CreateInitialRoamerMon(index, species, level, isTerrestrial, doesNotFlee, STALKER, respawnMode);
        return TRUE;
    }
    return FALSE;
}

void StopRoamer(u8 index)
{
    ROAMER(index)->active = FALSE;
    ROAMER(index)->respawnMode = NO_RESPAWN;
    ROAMER(index)->daysToRespawn = 0;
}

void MoveAllRoamersToOtherLocationSets(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        RoamerMoveToOtherLocationSet(i);
}

void MoveAllRoamers(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        RoamerMove(i);
}

bool8 DoesRoamerFlee(void)
{
    return !ROAMER(gEncounteredRoamerIndex)->doesNotFlee;
}

bool8 CanRoamerRespawn(u8 index)
{
    return ROAMER(index)->respawnMode != NO_RESPAWN;
}

void HandleRoamerRespawnTimer(void)
{
    if (ROAMER(gEncounteredRoamerIndex)->respawnMode == INSTANT_RESPAWN)
        return;
    ROAMER(gEncounteredRoamerIndex)->active = FALSE;
    if (ROAMER(gEncounteredRoamerIndex)->respawnMode == DAILY_RESPAWN)
        ROAMER(gEncounteredRoamerIndex)->daysToRespawn = 1;
    else if (ROAMER(gEncounteredRoamerIndex)->respawnMode == WEEKLY_RESPAWN)
        ROAMER(gEncounteredRoamerIndex)->daysToRespawn = 7;
}

void UpdateRoamerRespawns(u16 days)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (ROAMER(i)->daysToRespawn > 0)
        {
            if (ROAMER(i)->daysToRespawn <= days)
            {
                ROAMER(i)->active = TRUE;
                ROAMER(i)->daysToRespawn = 0;
                RoamerMoveToOtherLocationSet(i);
            }
            else
                ROAMER(i)->daysToRespawn -= days;
        }

    }
}
