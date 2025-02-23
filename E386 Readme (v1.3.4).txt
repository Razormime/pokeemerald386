=======================================================================================================
	Pokemon Emerald: 386 Version (v1.3.4) - Razormime
=======================================================================================================

=======================================================================================================
	Table of Contents
=======================================================================================================
	0) Introduction - PLEASE READ
	1) Soft-Spoiler Guide (General information)
	2) Hard-Spoiler Guide (Detailed information) - Try to avoid reading this
	3) Things you *maybe* WISH I would change, but won't
	4) HOW TO USE THE PATCH
	5) Updates and Save Files - Returning players, please read!
	6) Special Thank You's
	7) How to Contact Me

=======================================================================================================
	0)Introduction
=======================================================================================================
		Pokemon Emerald 386's main goal is to give players the opportunity to encounter and to also
	obtain at least one of every Pokemon available in generation 3, thereby completing the Pokedex
	without the need to connect to or interact with other games or events. This project DOES NOT try to
	increase/decrease difficulty; add modern mechanics; change lore; "fix" balancing "issues" with the
	original Emerald release; or include post-gen 3 pokemon, evolutions, items, etc. - There are plenty
	of really amazing hacks that do all of this (and more), and I encourage you to try those as well!
	Please, before writing a review, consider what this hack intends to do, and if it met its goal, and
	if this was outlined well-enough before investing your time into it.
	
		With that being said, understand that Pokemon Emerald was "missing" a LOT of Pokemon! So, to
	keep things as organic as possible, I have tried to include various methods to obtaining them, and
	to "spread out" their appearances or events so that at no point in the playthrough does it feel as
	if they all were just dumped into the game at once. I have re-worked certain events in the game so
	that they might offer different rewards than before, or I have modified in-game trades, or I might
	have developed a few new rooms in an existing cave or something to ensure that the methods feel as
	organic as possible. In addition, to compliment the massive amount of pokemon added to the world, I
	also have unlocked the National Pokedex from the start of the game - it would be such a chore to
	need to beat the Elite 4 before you were allowed to hunt all of the new monsters. Another related
	goal was to give players some way of having extra access to TMs, tutor-moves, and evolution items,
	so that players have the freedom to develop more than one pokemon dream team; but I also wanted to
	avoid breaking the game by doing things like making TMs infinitely usable (for example), instead I
	tried to find a good balance, and I encourage you to review the rest of this readme for the various
	solutions I've implemented. Also, keep in mind, that by having a larger pool of Pokemon to catch
	as you progress, the game *might* be easier than you remember (or vanilla Emerald guides reflect)
	in some places; but this is something which is unnavoidable.
	
		The last thing I've tried to do is to make it so that the game helps you find all the monsters
	without the need to keep this readme file! So, for example, some NPC battles have been slightly
	altered to include the "new" Pokemon I've introduced into the wild, creating an "event" where the
	pokedex registers the monster as seen, and allowing players to find that Pokemon in the wild. The
	NPCs which have been affected may have already been, or have now been re-positioned in such a way
	that players cannot progress past them without actually battling them. This was done so that the
	opportunity to trigger the pokedex is not accidentally skipped. The instances of these changed NPC
	battles are as few as possible, and do not include key battles like Gym Leaders or Rival battles -
	I did NOT want to change so much in the game. Changes to the teams can be one of two ways: Pokemon
	were ADDED to the trainer's team, or new Pokemon were EXCHANGED for old Pokemon on their teams. I
	suppose that in the few events where these trainers were once optional and had smaller teams, and
	have now become unavoidable and have larger teams, this *might* make the game a smidge harder than
	players might remember (or vanilla Emerald guides reflect), so maybe it balances out? Other help
	comes along in the form of NPC dialogue, or a traveler's journal left open on a desk - If you check
	with everyone and explore, you will NOT need a guide to find the "new" Pokemon. If there are any
	Pokemon which are not encountered in NPC battles or hinted at in some way, it is because they are
	vanilla Emerald Pokemon which have not been changed, meaning that THOSE pokemon can still be found
	by using any printed or online guide for Emerald (I have not removed any wild Pokemon from a route).
	NPCs which sell from 'upgradable' item lists will also say something along the lines of "come back
	and check later for even more stuff" - they may not say when or what triggers them to get the new
	stuff, but they will alert you to the idea that they are worth coming back to (regular Town Marts
	will not hint at the upgrade for the TM they will carry after the Gym Battle, however).

		One last thing: I have worked very hard on this hack, and had even had to start completely
	over at one point due to a computer failure (and I was almost finished, too). I have made sure to
	personally check and verify each addition or change that I made by actually playing the game and
	triggering the scenarios (not just looking at the data, but actually doing the trade; starting
	the static encounter and running, defeating, and catching the monster; collecting the item, etc).
	I have also played through the game from a fresh save file all the way to beating the Elite 4 and
	interacting with any/all of the post-game changes to make sure they work. I have also had a few
	volunteers help me beta test by playing through on different hardware and different emulators. I
	really wanted v1.0 to be as solid as possible. However, I may have overlooked some interesting
	missing content that I may be able to add, like an event-only battle move or something that is not
	obtainable because the Super Duper Pokemon Summer Event 2006 (fake example) is long gone. Basically,
	the game *might* need future updates, but I want you to know that I consider this release to be
	pretty solid, and you should feel confident that if you start a save file on v1.0, you will have a
	good time (and that, if needed, you should be able to update and keep your save file, no-problem).


=======================================================================================================
	1) Soft-Spoiler Guide
=======================================================================================================
A) Fixed Vanilla Bugs, Glitches and Misc.
	+ Pokemon Emerald 386 patch can be verified.
	+ The Real-Time-Clock (RTC) can be reset. (useful for emulators which don't keep track of time)
	+ The missing Zigzagoon from the cable-car is restored and has its intended chances of appearing.
	+ Bag-Menu sounds updated.
	+ Snow effect fixed and updated.
	+ Fixed dismounting from surf into grass animation.
	+ Real World references changed to no longer mention the real world.

B) Text + People Changes
	+ Main Move Tutor can teach pre-evolution moves.
	+ One-Time Move Tutors will now reset after defeating the Elite 4 (will need to be reset each time).
	+ Some instances of NPC/sign/event dialogue has been rewritten to accomodate insertion of content. 
	+ Some NEW NPCs added to compliment changes or give hints.
	+ Some EXISTING NPCs altered: Positions, Battles, Gifts, Trades, Events, Hints, etc.

C) Shops and Items
	+ A few items have moved from their original locations to make room for new rewards.
	+ All TMs which were once finite (limited) will become available to purchase (unlimited) somewhere.
	+ A few Game-Corner-only TMs have a bonus hidden-item location somewhere.
	+ Luxury Ball unlocked as a store item at some point.
	+ Deep Sea Evolutionairy Items each have one pickup location in the world.
	+ Bonus evolutionairy items like Moon Stones given extra locations to be found or as gifts.
	+ Bonus hold-items given as gifts or can be found.
	+ Rare Berries are now obtainable in-game and with repeat methods.
	+ Five unobtainable Decorations are now available.

D) Areas
	+ A few areas have had small changes.
	+ A few areas have been expanded (extra rooms in a cave, for example)
	+ One new "house" added.

E) Pokemon
	+ The missing Zigzagoon from the cable-car is restored and has its intended chances of appearing.
	+ Deoxys learned move-set updated to include all version exclusive moves from R/S and FR/LG.
	+ Legendary Pokemon Event Tickets are all restored! (see: Mew, Deoxys, Lati@s, Ho-oh + Lugia)
	+ Legendary Pokemon Beast-Trio, Bird-Trio, Mewtwo, Celebii and Jirachi all have new "events".
	+ ALL Fossil-Pokemon are found as Fossils someplace. Fossil Regenerator updated accordingly.
	+ Trade-Based evolution Pokemon have the opportunity to trade-evolve and stay with you.
	+ Ruby & Sapphire exclusive Pokemon added to their appropriate routes.
	+ Missing wild Pokemon from Kanto and Johto spread out across Hoenn in logical places.
	+ Each Starter Pokemon from all 3 regions available.
	+ In-Game trades have all been re-done for important Pokemon
	+ Emerald 1%-rate Pokemon have had an increase in appearance rates to make-up for the fact that
		single player playthroughs will not be able to take advantage of record-mixing "outbreaks."


=======================================================================================================
	2) HARD-SPOILER GUIDE !!!
=======================================================================================================
I REALLY think that reading this might ruin much of the fun, but if you must...

.
.
.

A) Fixed Vanilla Bugs, Glitches and Misc.
	+ Pokemon Emerald 386 patch can be verified.
		+ Cacnea replaces Lotad in Prof Birch Speech to show a succesful patch.
		+ PC in Devon Corp (2F) shows current "E386" patch-update version.
	+ The Real-Time-Clock (RTC) can be reset.
		+Press and hold LEFT + SELECT + B at the title screen.
	+ The missing Zigzagoon from the cable-car is restored and has its intended chances of appearing.
	+ Bag-Menu updated to use more comfortable Fire Red / Leaf Green sounds.
	+ Snow effect fixed to continue to snow, and updated to produce hail when battling.
	+ Fixed dismounting from surf into grass animation: Now lands IN grass, not ON grass.
	+ Real World references changed to no longer mention the real world.
		+ Delibird's Pokedex entry: was Mt.Everest, is now Mt.Avalanche (from Pokemon Mystery Dungeon).
		+ Regice's Pokedex Entry: was Antarctic Ice, is now Glacial Ice.
		+ Poliwrath's Pokedex Entry: was Pacific Ocean, is now Largest Oceans.

B) Text + People Changes
	+ Main Move Tutor can teach pre-evolution moves.
		+ Pokemon must be at least 5 levels above when the pre-evolution would have learned the move.
	+ One-Time Move Tutors will now reset after defeating the Elite 4 (will need to be reset each time).
		+ Double-Edge in Sootopolis
		+ Dynamic Punch in Mossdeep
		+ Explosion in Pacifidlog Town
		+ Fury Cutter in Verdanturf Town
		+ Metronome in Fallarbor Town
		+ Mimic in Lavaridge Town
		+ Rollout in Mauville City
		+ Sleep Talk in Fortree City
		+ Substitute in Lilycove
		+ Swagger in Slateport City
	+ Some instances of NPC/sign/event dialogue has been rewritten to accomodate insertion of content.
		+ Flavor text for defeating or running from Sudowoodo or Bird-Trio battles added.
		+ Various minor changes to NPC dialogue change tense or plurality, depending on situation.
	+ Some NEW NPCs added to compliment changes or give hints.
		+ NPC in Devon Corp helps you trade Pokemon with yourself.
		+ NPC in Battle Frontier helps player locate trade locations and what is offered and requested.
		+ NPC in Battle Frontier adds flavor text to new "Bed & Breakfast" house.
		+ NPC in Battle Frontier gives the alternate tent decoration with a hint on how to get it.
		+ NPC in Mossdeep hints at where to fish for Qwilfish.
		+ NPC in Sootopolis hints at how to find Shellder (and Clamperl).
		+ NPC in Lavaridge Pokecenter for new trade. - See section  "E) POKEMON."
		+ NPCs (x2) on route 106 add flavor text to the Lapras event.
		+ NPC in Slateport alerts player to unlockable TM mart.
	+ Some EXISTING NPCs altered: Positions, Battles, Gifts, Trades, Events, Hints, etc.
		+ Prof.Birch Events:
			+ Previous National Pokedex expansion event changed to Roaming Beast-Trio event intro.
			+ Previous Hoenn-dex completion event "Johto starter gift" changed to "Kanto fighting gift."
			+ More details for both events in section "E) Pokemon"
		+ Rival
			+ After defeating the Elite 4, your rival will tell you that they've uploaded ther dex
			data for "seen" Pokemon to a PC in Prof Birch's Lab. At any time after this, you may
			choose to share your dex "seen" data with them via the PC. If you do so, "seen" data
			will be uploaded to your dex for many (not all) Pokemon, allowing you to track them
			without the need for this readme or online guides. SPECIAL NOTE: Players who have already
			defeated the Elite 4 on previous versions of the hack (v1.0 or v1.1) must simply defeat
			the Elite 4 again to unlock the feature on the PC in Birch's Lab. However, your rival will
			not say anything about it. - Essentially reveals locations for all basic-form Pokemon added
			to the hack (EXCLUDES evolved forms, babies, static encounters, gifts, trades & legendaries).
		+ SUPER ROD Fisherman
			+ When receiving the SUPER ROD, they will inform you that they have a fishing guide-book
			on the bookshelf in the room. Checking this book allows you to see which species of
			Pokemon each ROD is capable of catching (but not location or rarity). Can be helpful
			when tracking Pokemon with the Pokedex and you are unsure if the encounter is SURF or not.
		+ TRADERS:
			+ All are in original spots, but with new details. - See section "E) POKEMON"
		+ NPC in Fortree expanded dialogue hints at where to find Yanma.
		+ Shop-keepers in Slateport: expanded dialogue, including hints, for expanded merch list.
			+ Doll Seller: See section "C) Shops and Items."
			+ TM Seller: See section "C) Shops and Items."
		+ BATTLES:
			+ Hiker Clark (Route 116)
			+ Bug Catcher Lyle (Petalburg Woods)
			+ Youngster Timmy (Route 110)
			+ Camper Travis (Route 111)
			+ Breeder Lydia (Route 117)
			+ Camper Shane (Route 114)
			+ Hiker Trent (Route 112)
			+ Black Belt Takao (Dewford Gym)
			+ Magma Grunt #12 (Magma Hideout 4F)
			+ Magma Grunt #13 (Magma Hideout 4F)
			+ Fisherman Wade (Route 118)
			+ Ranger Catherine (Route 119)
			+ Bird Keeper Perry (Route 118)
			+ Swimmer Spencer (Route 124)
			+ Hex Maniac Tasha (Mt.Pyre 4F)
			+ Hiker Eric (Jagged Pass)
			+ Psychic William (Mt.Pyre 3F)
			+ Sr & Jr Kim and Iris (Route 125)
			+ Breeder Myles (Route 121)
			+ Breeder Pat (Route 121)
			+ Cooltrainer Quincy (Victory Road 1F)
			+ Ninjaboy Jaiden (Route 115)
			+ Guitarist Kirk (Mauville Gym)
			+ Kindler Jeff (Lavaridge Gym)
			+ Dragon Tamer Aaron (Route 134)
			+ Youngster Deandre (Route 118)
			+ Birdkeeper Colin (Route 120)
			+ Youngster Davis (Route 123)
			+ Cooltrainer Jazmyn (Route 123)
			+ Cooltrainer Hope (Victory Road 1F)
			+ Guitarist Joseph (Route 110)
			+ Kindler Bernie (Route 114)
			+ Swimmer Declan (Route 124)
			+ Swimmer Grace (Route 124)
			+ Ninjaboy Takashi (Route 119)
			+ Pokefan Vanessa (Route 121)

C) Shops and Items
	+ All TMs which were once finite (limited) will become available to purchase (unlimited) somewhere:
	
	(NOTE: I had experimented with re-usable TMs but found that this had both broke the base difficulty
	(however difficult you may or may not find it as-is) by allowing players to swap moves on-the-fly,
	without sacrifice, in an area like the Elite 4 challenge; as well as making certain locations and
	shops redundant (like the Game Corner, Lilycove Dept store, TM seller, etc.). I feel that, now, with
	these upgrading shops ONLY carrying the TMs which were originally finite (and not including Game
	Corner prizes), but still costing money, and must be unlocked after progress says "you should have
	been able to find the 'pickup' location of the TM first", players can still have a somewhat vanilla
	experience on the initial adventure, but also be able to change moves and use TMs without worry.
	ALSO, TM21 'Frustration' and TM27 'Return' can already by infinitely obtained in Pacifidlog Town, So
	they have not been given another infinite position.)
	
		+ Most rare TMs (finite in orig. Emerald) can now be unlocked at TM seller in Slateport Market:
			(NOTE 1: The shop must first be unlocked the original way: Get TM43 from NPC on Route 111.)
			(NOTE 2: The shop will initially only carry the original Emerald TMs:)
			+ TM10 (Hidden Power)
			+ TM43 (Secret Power)
		--- The 1st expansion will unlock after obtaining the Heat Badge (4th badge) to include:
			+ TM01 (Focus Punch)
			+ TM05 (Roar)
			+ TM06 (Toxic)
			+ TM07 (Hail)
			+ TM09 (Bullet Seed)
			+ TM28 (Dig)
			+ TM36 (Sludge Bomb)
			+ TM37 (Sandstorm)
			+ TM41 (Torment)
			+ TM45 (Attract)
			+ TM46 (Theif)
			+ TM47 (Steel Wing)
		--- The 2nd expansion will unlock after obtaining the Rain Badge (8th badge) to include:
			+ TM02 (Dragon Claw)
			+ TM11 (Sunny Day)
			+ TM12 (Taunt)
			+ TM18 (Rain Dance)
			+ TM19 (Giga Drain)
			+ TM22 (Solarbeam)
			+ TM23 (Iron Tail)
			+ TM26 (Earthquake)
			+ TM30 (Shadow Ball)
			+ TM31 (Brick Break)
			+ TM44 (Rest)
			+ TM48 (Skill Swap)
			
		+ TMs from Gym Leaders unlock in that town's mart after earning the corresponding badge:
			+ TM39 (Rock Tomb)   : Rustboro Mart
			+ TM08 (Bulk Up)     : Slateport Mart (because Dewford has no mart)
			+ TM34 (Shock Wave)  : Mauville Mart
			+ TM50 (Overheat)    : Lavaridge Mart
			+ TM42 (Facade)      : Petalburg Mart
			+ TM40 (Arial Ace)   : Fortree Mart
			+ TM04 (Calm Mind)   : Mossdeep Mart
			+ TM03 (Water Pulse) : Sootopolis Mart
			
		+ The final TM is found post-game on the SS Tidal, so is unlocked by defeating the Elite 4:
			+ TM49 (Snatch)      : Ever Grande Pokemon League Mart
		
	+ A few Game-Corner-only TMs have a bonus hidden-item location somewhere.
		+ To help with the extra pokemon and time grinding Mauville Game Corner for coins, I have given
		a few of the TMs from the Game Corner an extra finite 'pickup' somewhere in the world:
			+ TM13 (Ice Beam)    : as a Hidden Item in Articuno's room
			+ TM32 (Double Team) : as a Hidden Item in Lapras' room
			+ TM35 (Flamethrower): as a Hidden Item in Moltres' area
			+ TM29 (Psychic)     : as a Hidden Item in Mewtwo's room
			- TM24 (Thunderbolt) : already has a bonus event so was not given an extra.

	+ LUXURY BALL unlocked after defeating the Elite 4: can be bought in the Lilycove Dept. Store
	
	+ Deep Sea Evolutionairy Items each have one pickup location in the world.
		+ DEEP SEA TOOTH: Now found in the Granite Cave (x1). - No longer from Captain Stern.
		+ DEEP SEA SCALE: Now found in the Shoal Cave (x1).- No longer from Captain Stern.
	
	+ BONUS evolutionairy items given extra locations to be found or as gifts.
		+ UPGRADE
			+ Devon Corp 2F: Comes with Gift Porygon
		+ MOON STONES
			+ Meteor Falls: 2 EXTRA Hidden, 1 EXTRA visible pickup
			+ Mossdeep Space Center B1F: Given as a gift which refreshes with each Elite 4 victory.
		+ SUN STONES
			+ Jagged Pass Expansion: 1 visible Item Ball
			+ Mossdeep Space Center B1F: Given as a gift which refreshes with each Elite 4 victory.
		+ FIRE STONES
			+ Jagged Pass Expansion: 1 hidden item which refreshes with each Elite 4 victory.
			+ Fiery Path Expansion: 1 visible item ball
			+ Route 124: Red Shard will respawn after each Elite 4 victory.
		+ THUNDER STONES
			+ Route 124: Yellow Shard will respawn after each Elite 4 victory.
		+ WATER STONES
			+ Route 124: Blue Shard will respawn after each Elite 4 victory.
			+ Slateport: Hidden Waterstone on rock on beach near parasol.
		+ LEAF STONES
			+ Route 124: Green Shard will respawn after each Elite 4 victory.
		+ METAL COATS
			+ New Mauville: 1 visible item ball pickup
			+ Mossdeep Space Center B1F: Hidden in trash can, will respawn after each Elite 4 victory.
		+ DRAGON SCALE
			+ Granite Cave Expansion B3F: 1 hidden item pickup
		+ KINGS ROCKS
			+ Granite Cave Expansion B3F: 1 hidden item pickup
			+ Shoal Cave: visible item 
			+ Altering Cave Expansion B1F: 1 visible item pickup
		+ HEART SCALES
			+ Route 128: Hidden Pickups here will respawn after each Elite 4 victory. (NPC gives hint).
			
	+ Bonus hold-items given as gifts or can be found.
		+ TWISTED SPOON
			+ Mt.Pyre Summit: Hidden item pickup
		+ SEA INCENSE
			+ Granite Cave expansion B1F: Hidden Item pickup will respawn after each Elite 4 victory.
		+ LUCKY EGG
			+ Altering Cave Expansion: visible item pickup
		+ NEVERMELT ICE
			+ Shoal Cave Ice Room: visible item pickup
		+ MAGNET
			+ New Mauville: hidden item near Zapdos
		+ METAL POWDER
			+ Altering Cave B2F: hidden item pickup
			
	+ BERRIES:
		+ Some Rare Berries have a hidden pickup location which respawns after each Elite 4 victory
			+ SALAC BERRY:   Hidden near Battle Frontier B&B
			+ GANLON BERRY:  Hidden near Battle Frontier B&B
			+ APICOT BERRY:  Hidden near Battle Frontier B&B
			
		+ Some uncommon or rare berries have been given to wild pokemon. Catch or use thief to obtain:
			+ WIKI BERRY:   Commonly held by Murkrow
			+ MAGO BERRY:   Commonly held by Meowth
			+ AGUAV BERRY:  Commonly held by Mankey
			+ PETAYA BERRY: Commonly held by Teddiursa
			
		+ In vanilla Emerald, The Berry Master's Wife on Route 123 would give special berries only ONCE
		after giving special phrases. If a player waits 24 hours and tries the same phrase again, she 
		would give a random COMMON berry. NOW the random berry list she pulls from is made-up of only
		the RARE berries she gives for the special phrases AND three additional berries, allowing
		players to repeatably obtain these rare berries:
			+ SPELON BERRY: (phrase: GREAT BATTLE)
			+ PAMTRE BERRY: (phrase: CHALLENGE CONTEST (Need contest pass)
			+ WATMEL BERRY: (phrase: OVERWHELMING LATIAS (after Latias pokedex entry)
			+ DURIN BERRY:  (phrase: COOL LATIOS (after Latios pokedex entry)
			+ BELUE BERRY:  (phrase: SUPER HUSTLE)
			+ SALAC BERRY:  (Also a hidden pickup)
			+ GANLON BERRY: (Also a hidden pickup)
			+ LIECHI BERRY: (Also Comes with Jirachi)
		
		+ Just like in vanilla Emerald, the following berries can only be obtained ONCE, however,
		I have updated the amount given from ONE to THREE of each berry:
			+ LANSAT BERRY: Scott's Gift for obtaining all Battle Frontier Silver Symbols (x3)
			+ STARF BERRY: Scott's Gift for obtaining all Battle Frontier Silver Symbols (x3)
		
		+ For a complete list of ALL BERRY locations (vanilla + E386) please refer to the special
		"E386 BERRY GUIDE" text file included with the patch download. 
	
	+ Five previously unobtainable Decorations are now available:
		+ R/S exclusive Seedot DOLL: Buy at Slateport Market Doll Seller
		+ Regi-trio DOLLS: Slateport Market Doll Seller unlocks after CATCHING ALL 3 REGI Pokemon.
		+ The "other" tent which you do not pick as your prize in the Trick House becomes a gift from
		an NPC found in the Battle Frontier AFTER defeating the Tick House and claiming the first tent.

D) Areas
	+ A few areas have had small changes:
		+ Some areas which did not have wild Pokemon now do (either fishing or walking/surfing).
		+ To either provide more grass tiles for hunting Pokemon or force a few battles with NPCs.
	+ A few areas have been expanded (extra rooms in a cave, for example):
		+ Granite Cave
		+ Fiery Path
		+ Jagged Pass
		+ Altering Cave
	+ One new "house" added:
		+ Battle Frontier Bed & Breakfast

E) Pokemon
	(i) Any pokemon which does not appear in this readme will have its original vanilla location.
	
	+ Deoxys learned move-set updated to include all version exclusive moves from R/S and FR/LG.
		+ Teleport (level 13)
		+ Taunt (level 17)
		+ Superpower (level 28)
		+ Snatch (level 31)
		+ Cosmic Power (level 36)
		+ Zap Cannon (level 42)
		+ Hyper Beam (level 51)
		
	+ Legendary Pokemon Event Tickets are all restored!
		(NOTE: As normal, tickets cannot be used until after beating the Elite 4).
		
	+ Trade-Based evolution Pokemon have the opportunity to trade-evolve and stay with you.
		(NOTE: New Scientist at Devon Corp helps you trade Pokemon with yourself.)
		
	+ In-Game trades have all been re-done for important Pokemon
		(NOTE: Checking Olga's notebook in the Battle Frontier can remind you where these all are)

	+ HOENN
		(NOTE 1: Ruby & Sapphire exclusive Pokemon have been added to their appropriate routes.)
		(NOTE 2: Emerald 1%-rate Pokemon have had an increase in appearance rates to make-up for
		single-player playthroughs not being able to take advantage of record-mixing "outbreaks.")
		+ TREECKO: Route 119
		+ MUDKIP: Route 114 (Walk / Surf)
		+ TORCHIC: Mt.Chimney, Jagged Pass
		+ SURSKIT: R.102 (5% Surf, 1% Land); Routes: 114, 117, and 120 (all Surf)
		+ SEEDOT: R.102, R.117, R.120 (still only 1% for this route)
		+ NUZLEAF: R.114
		+ MEDITITE: Mt.Pyre Outside, Victory Road B1F
		+ MEDICHAM: Victory Road B1F, Victory Road B2F
		+ ROSAELIA: R.117
		+ ZANGOOSE: R.114
		+ LUNATONE: Meteor Falls (Split 50/50 with SOLROCK)
		+ HUNTAIL: Self-Trade Clamperl holding a DEEP SEA TOOTH
		+ GOREBYSS: Self-Trade Clamperl holding a DEEP SEA SCALE
		+ JIRACHI: Given as a gift from the Gamecube in the Battle Frontier Bed & Breakfast.
		+ DEOXYS: AURORA TICKET is given to you in the Mossdeep Space Center basement
		+ LATI@S: EON TICKET is given to you when arriving at the Battle Frontier

	+ KANTO
		+ BULBASAUR: NPC Trade - Fortree City (for Duskull)
		+ SQUIRTLE: NPC Trade - Pacifidlog Town (for Dratini)
		+ CHARMANDER: NPC Trade - Fallarbor Town (for Larvitar)
		+ ALAKAZAM: Self-Trade Kadabra
		+ MACHAMP: Self-Trade Machoke
		+ GOLEM: Self-Trade Graveler
		+ GENGAR: Self-Trade Haunter
		+ CATERPIE: Petalburg Woods
		+ WEEDLE: Petalburg Woods
		+ PIDGEY: Route 104
		+ RATTATA: New Mauville
		+ RATICATE: New Mauville
		+ SPEAROW: Route 104
		+ EKANS: Route 111, Route 112, Route 113, Mirage Tower
		+ NIDORAN (M): Routes 101, 102, 103
		+ NIDORAN (F): Routes 101, 102, 103
		+ CLEFIARY: Meteor Falls
		+ PARAS: R.114
		+ VENONAT: Petalburg Woods, R.104
		+ DIGLETT: Desert Underpass
		+ DUGTRIO: Desert Underpass
		+ MEOWTH: R.116
		+ MANKEY: Granite Cave
		+ GROWLITHE: Mt.Chimney, Jagged Pass
		+ POLIWAG: Safari Zone NW + SW + SE (Good Rod), Altering Cave (Good & Super Rod)
		+ POLIWHIRL: Altering Cave B1F (Super Rod), Altering Cave B2F + B3F (Surf / Super Rod) 
		+ BELLSPROUT: R.119
		+ PONYTA: Mt.Chimney, Jagged Pass
		+ SLOWPOKE: R.120 (Surf), Altering Cave 1F (Walk), B1F (Walk / Surf / Good & Super Rod), B2F + B3F (Good & Super Rod)
		+ SLOWBRO: Altering Cave B1F - B3F: (Walk / Surf / Super Rod)
		+ GOLDUCK: Altering Cave B3F (Walk / Surf)
		+ FARFETCH'D: R.118, R.123
		+ SEEL: Abandoned Ship (Walk / Surf)
		+ SHELLDER: Outer Sealed Chamber (All fishing rods), R.124 (Dive), R.126 (Dive)
		+ GASTLY: Mt.Pyre (Inside and Outside)
		+ ONIX: Magma Hideout, Altering Cave B2F + B3F
		+ DROWZEE: R.121, R.123
		+ HYPNO: Altering Cave B2F + B3F
		+ HORSEA: Granite Cave (Surf + Super Rod)
		+ KRABBY: Outer Sealed Chamber (Walking / All fishing rods), Abandoned Ship (Walking / Good & Super Rod), Granite Cave (Walking / Good & Super Rod)
		+ KINGLER:  Outer Sealed Chamber (Walking / Super Rod), Abandoned Ship (Walk / Super Rod)
		+ EXEGGCUTE: R.120
		+ CUBONE: Desert R.111
		+ HITMONLEE: Prof. Birch event (complete Hoenn Dex), evolve Tyrogue 
		+ HITMONCHAN: Prof. Birch event (complete Hoenn Dex), evolve Tyrogue
		+ LICKITUNG: Altering Cave B2F + B3F
		+ CHANSEY: Altering Cave B2F + B3F, Safari Zone South
		+ TANGELA: R.119, R.120
		+ KANGASKHAN: Altering Cave B2F + B3F
		+ MR.MIME: Safari Zone SW
		+ SCYTHER: Safari Zone South
		+ JYNX: Shoal Ice Cave
		+ ELECTABUZZ: New Mauville
		+ MAGMAR: Fiery Path, Magma Hideout
		+ TAUROS: Safari Zone North
		+ LAPRAS: Static Encounter in Granite Cave
		+ EEVEE: NPC Trade - For Meowth   (Rustboro)
		+ PORYGON: Gift - Rustboro City (Devon Corp 2F)
		+ AERODACTYL: OLD AMBER found in Jagged Pass
		+ KABUTO: DOME FOSSIL found in Granite Cave
		+ OMANYTE: HELIX FOSSIL found in Shoal Cave
		+ SNORLAX: NPC Trade - For Hariyama (Battle Frontier)
		+ DRATINI: Granite Cave (Surf / Good & Super Rod)
		+ ARTICUNO: Static encounter in the Shoal Cave Ice Room
		+ ZAPDOS: Static Encounter in New Mauville
		+ MOLTRES: Static Encounter in the Jagged Pass expansion
		+ MEWTWO: Static encounter in the Altering Cave
		+ MEW: OLD SEA MAP can be found in the Abandoned Ship hidden rooms
		
	+ JOHTO
		+ CHIKORITA: Gift for saving Weather Institute (collect in Fortree Pokecenter)
		+ TOTODILE: Gift for deliver the SCANNER to Capt.Stern (in Slateport)
		+ CYNDAQUIL: Gift for delivering METEORITE to Prof.Cozmo (in Fallarbor)
		+ POLITOAD: Trade Poliwhirl holding a KINGS ROCK
		+ SLOWKING: Trade Slowpoke holding a KINGS ROCK
		+ STEELIX: Trade Onix holding a METAL COAT
		+ SCIZOR: Trade Scyther holding a METAL COAT
		+ KINGDRA: Trade Seadra holding a DRAGONS SCALE
		+ PORYGON 2: Trade Porygon holding an UPGRADE
		+ SENTRET: R.118, R.123
		+ FURRET: R.118, R.123
		+ HOPPIP: R.110
		+ HITMONTOP: Prof. Birch event (complete Hoenn Dex), evolve Tyrogue
		+ YANMA: R.119, R.120
		+ MURKROW: R.122, Mt.Pyre (outside areas)
		+ MISDREAVUS: Mt.Pyre
		+ HOUNDOUR: Jagged Pass, Mt.Chimney
		+ UNOWN: Inner Sealed Chamber (all forms have equal rates: A-Z & !?)
		+ DUNSARCE: Outer Sealed Chamber
		+ QWILFISH: Routes 129-134 (Super Rod)
		+ SNEASEL: Shoal Ice Cave
		+ SWINUB: Shoal Ice Cave
		+ DELIBIRD: Shoal Ice Cave
		+ TEDDIURSA: Altering Cave 1F
		+ URSARING: Altering Cave B2F-B3F
		+ MANTINE: Routes 124-128 (Surf)
		+ LARVITAR: Route 111
		+ ENTEI: Starts roaming land after Elite 4 (Pokedex-upgrade event will help track)
		+ RAIKOU: Starts roaming land after Elite 4 (Pokedex-upgrade event will help track)
		+ SUICUNE: Starts roaming land and water after Elite 4 (Pokedex-upgrade event will help track)
		+ HO-OH: MYSTIC TICKET can be found in the Artisan Cave at the Battle Frontier
		+ LUGIA: MYSTIC TICKET can be found in the Artisan Cave at the Battle Frontier
		+ CELEBI: Starts roaming after Elite 4 (Note: Cannot be tracked with Pokedex)
		
	+ RE-SPAWN SAFETY:
		(NOTE: GROUDON and KYOGRE STILL DO NOT RESPAWN IF DEFEATED)
		
		+ If DEFEATED, but NOT CAUGHT, the following Pokemon respawn by defeating the Elite 4:
			+ MEW
			+ MEWTWO
			+ LUGIA
			+ HO-OH
			+ ARTICUNO
			+ ZAPDOS
			+ MOLTRES
			+ DEOXYS
			+ LATI@S (The Southern Island encounter; NOT the roamer!)
			+ SUDOWOODO
			+ LAPRAS
		
		+ If DEFEATED, but NOT CAUGHT, the following Pokemon respawn after one day:
			+ SUICUNE
			+ ENTEI
			+ RAIKOU
			+ LATI@S (The Roamer, NOT the Southern Island encounter!)
		
		+ CELEBI respawns immediately after being defeated or run from.


=======================================================================================================
	3) Things you *might* WISH that I would change, but won't:
=======================================================================================================
	+ Easier FEEBAS: Feebas is still a pain in the butt. This was this Pokemon's gimmick, and I did not
		want to take that away from it. When you finally catch the jerk, you can totally feel like you
		did actually catch this jerk, for real.
	
	+ Easier Grimer: Grimer really does have a 2% chance at appearing in its location. This encounter
		rate is frustratingly low, but like Feebas... it's vanilla and I'm leaving it alone.
	
	+ Repeatable LANSAT and STARF berries: I didn't want to soften the importance of these berries as
		prizes for their challenges so I decided against alternate methods to obtain them. However, as
		a compromise, you are gifted 3 of each to make losing them a little more difficult. Be careful.
		
	+ HM Items: a popular change to rom-hacks is making field-use items to replace HMs (like a SURFBOARD
		instead of SURF, for example). Again, my hack is a pure nostalgia trip (which you can complete), 
		and does not aim to modernize stuff like this. I think they are great additions to "bigger" more
		robust rom-hacks, but not to my humble diet-vanilla hacks.
		
	+ Running in-doors, ultra-fast text, speed enhancments, etc: As before, just trying to make a super
		humble vanilla nostalgia trip. I also want to run in Pacifidlog, but I need to draw a line.
		
	+ Night-time colors: 2 reasons I did not go for this: the first being the usual "nostalgic vanilla,"
		and the second is that I see a lot of hacks with this change need constant updates for whatever
		reason (it must be quite tedious to do correctly, so bravo to those who get it right), and I did
		not want my hack to need constant updates after release (which is why I tested so much before
		releasing).
		
	+ DECAPITALIZING: Again, somehow, innevitably something gets overlooked and I would need to go back
		in and decap something, update, repeat. But it's a VANILLA NOSTALGIA DREAM and not worth it.
		
	+ Anything Else and Everything Else: Consider that everyone gets something different out of playing
		through a Pokemon game, and no single hack can please everyone. This hack is for "semi-purist"
		players who wanna complete dexes but don't want to invest in old hardware and methods or feel
		like they cheated by using cheat-codes. This is for people who don't want a MODERN version
		of Emerald, it's for those who want the OLD version of Emerald... only completable.
		
	+ Jirachi event: You *might* have seen another Emerald hack do it similar to the way I've done it
		here. If it is the rom-hack I'm thinking of, it is because it was a sugestion I made in that
		developers Discord group. At that time I felt overwhelmed with doing an Emerald hack, myself,
		and was anticipating their hack, and they were asking for suggestions. I actually do not know
		if they did use it, and I obviosuly cannot be upset if they went with the idea. I want to say
		that they had a fantastic hack in progress, and I wish them all the luck with it. I simply
		wanted to do my own hack, and I also really liked my idea.

=======================================================================================================
	4) HOW TO USE THE PATCH... (aka "Why won't this game run?")
=======================================================================================================
	+ The rom hack you just downloaded cannot be played by itself! It must be applied to an original, 
	legit copy of this exact .gba rom: "Pokemon - Emerald Version (USA, Europe)" <- I cannot tell you
	where or how to find that exact titled rom, but if you have it, then you can follow these steps to
	make Pokemon Emerald 386:
		1) Unzip the .zip file to get to the .ips file
		2) Put the Pokemon Emerald 386.ips file and your copy of the Pokemon Emerald .gba in a folder
		3) Apply the patch (.ips file) to the game (.gba file) using only ONE of these two options:
			+ Online Patcher: https://www.romhacking.net/patch/
			+ Offline Patcher: https://www.romhacking.net/utilities/240/
		4) The file created by the patcher is the full Pokemon Emerald 386 patched game, and can now
		be played on your favorite GBA emulator or flashed to a cart! To be sure that the patch is
		applied correctly, watch out for a Cacnea in Prof.Birch speech when starting a new game - If
		you see Cacnea, the patch is a success! If the Pokemon is a Lotad, you may have missed a step
		or used a bad rom.

=======================================================================================================
	5) Patch Updates & Old Save Files
=======================================================================================================
	1.3.4 Added one Waterstone and fixed a typo in dialogue which only appeared once.
	1.3.3 Removed Enigma Berry from the added v1.3 berries. Swapped around a few berry locations.
	1.3.2 Fixed a minor collision issue with two tiles in Jagged Pass (issue started in 1.3)
	1.3.1 Fixed an issue with Apicot berry being given as a berry (issue started in 1.3)
	1.3   Rare berry inclusions. Tile improvements in one area.
	1.2   Added Rival Pokedex "seen" help + Fishing Rod Guide Book. Also moved one NPC by two tiles.
	1.1   Rephrased text for when/if you run from the Sudowoodo, and fixed collision with 1 rock.
	1.0   Emerald 386 released.

	USING OLD SAVE FILES:
		+ YOU SHOULD NOT USE ANY ORIGINAL VANILLA EMERALD SAVES WITH THIS EMERALD 386 PATCH!
		+ However, you CAN update from older Emerald 386 versions and continue using that save file...

	To update Emerald 386 from previous versions to new versions safely, follow these instructions:
		0: Check newest update: https://www.pokecommunity.com/threads/pokemon-emerald-386.530669/
		1: Save your current game UPSTAIRS in a Pokemon Center and exit the emulator.
		2: Make a backup of your current Pokemon Emerald 386 ROM ".gba" and save file ".sav/.srm"
		   (and any .rtc files) and put them in a second backup folder somewhere safe.
		3: Patch a CLEAN copy of "Pokemon - Emerald Version (USA, Europe)" with current patch version
		   (DO NOT PATCH NEW E386 VERSION TO OLD E386 VERSION ROM!!! --- USE A CLEAN VANILLA ROM!!!)
		4: Replace the PREVIOUS Emerald 386 ".gba" file with the NEW one in the folder your emulator
		   reads from (never replace the backups).
		5: Make sure your .gba and .sav/.srm (and possibly .rtc) names all match.
		6: Verify the update by checking the PC on the second floor of the Devon Corp in Rustboro city.
		
		### CAUTION: It's possible that updating may wipe-out planted berries. Be sure to harvest
		### rare berries before doing an update. If berries are lost, check the "E386 BERRY GUIDE.txt"
		### file for detailed info on how to obtain fresh berries. - I've had only one report of this
		### and have not been able to reproduce the issue myself.

=======================================================================================================
	6) Special Thank You
=======================================================================================================
	+ First, I need to thank everyone involved in the Pokeemerald Disassembly project. Obviously, none
	of what I've planned to do here would be possible. It is a lot of hard work to create and maintain
	the project, and I am very very grateful to them. By extension, I want to thank everyone involved
	with pret and its extensions like the discord group. They, alongside branched discord groups, like
	RH Hideout, have been invaluable resources to turn to when I had encountered road-blocks. Everyone
	who has contributed to the wiki via forum posts in the form of walkthroughs or tutorials for nifty
	features also deserve massive thanks. Team Aqua's Hideout video tutorials for features was also an
	amazing resource I couldn't have lived without, so "Thank You" to them, too! Specific users from
	these resources for specific changes are as follows:
	
		+ Mgriffin: Project setup and Porymap troubleshooting
		+ Jaizu: Porymap troubleshooting, tutorial on sound changing
		+ Zatsu: Some NPC movement scripting
		+ Lunos: Help with, and creating tutorials for Script Specials, Overworld and UNOWN expansions.
		+ Sbird: Project setup
		+ ShinyDragonHunter: UNOWN encounter troubleshooting
		+ TheXaman: Their tutorial on in-game self trading
		+ DD: Roaming Beast Expansion (name changed as they did not want to be credited)
		+ Louroboros: Tutorial on enabling RTC-changing
		+ Alex D, daniilS and Samu for tutorials on changing + updating snow effects
		+ ghoulslash: Surf dismount fix tutorial
		+ devolov: pre-evolution move tutor tutorial
		+ Goppier: Mt.Chimney cable car documentary
		+ Cawt: Helping solve a berry issue
	
	+ I want to thank my beta testers, JAYVEE1473 and Tellz, who volunteered to test and continually
	update their beta versions as we went along, refining elements, or squashing bugs.
	
	+ I want to thank everyone who has taken the time to write informative, but spoiler-free reviews
	for my previous rom-hacks on romhacking.net so far:
		
		+ Crystal 251: 
			Arindur
			SteRossetto
			Incantator (also for Yellow 151)
			ThegreatBen
			Aizumi
			KevCfcNo1
			
		+ Yellow 151
			Vomer (also for Blue 151)
			Greenknight9000
			Pudupuda
			NordicNugz
		
		+ Blue 151
			KennieJim
			ClaudeDixon
			headfallsoff
			Pokemonfan98
	
	+ The Pokemon documentation sites Bulbagarden/Bulbapedia and Serebii.net
		+ https://bulbapedia.bulbagarden.net/wiki/Main_Page
		+ https://www.serebii.net
	
	+ ProjectPokemon.org, and especially VictorV111 for his save-file which I used for testing.
		+ https://projectpokemon.org/home/files/file/3834-pokémon-emerald/
	
	+ GameFAQs, and especially verbalillusion for their Berry FAQ (v0.991).
		+ https://gamefaqs.gamespot.com/gba/921905-pokemon-emerald-version/faqs/38369
	
	+ I also want to thank you, whoever you are, for downloading and taking a chance with my hack (and
	especially if you took the time to read this novel of a readme file). I worked really hard to teach
	myself new skills so that the project would feel as natural and original as possible. I wanted to
	avoid cringy dialogue and I also wanted to avoid adulterating the 'soul' of the original game.

	+ "Thank you all" - Razormime

=======================================================================================================
	7) How to Contact Me
=======================================================================================================
	+ If, for whatever reason, this document does not answer your questions, has left something out, or
	you simply want to discuss the hack, feel free to message me on my PokeCommunity page or join my
	Discord server. Be aware that my Discord group has multiple channels which target my Twitch stream
	community as well, and as such, you will be expected to accept and follow the same rules (but can
	opt-out of the roles and even mute those channels):
	
		+ Pokecommunity: https://www.pokecommunity.com/members/razormime.972604/
		+ Discord (be sure to select your roles and interests): https://discord.gg/Cb2H8FPmDG