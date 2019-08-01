////////////////////////////////////////////////////////////////////
//DeRap: weapons_firearms\Izh18\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 15:00:20 2019 : 'file' last modified on Thu Jun 20 10:22:38 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

//(8 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	destructno = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class DZ_Weapons_Firearms_IZH18
	{
		units[] = {"ShotgunIzh43","ShotgunIzh43_Sawedoff"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class cfgWeapons
{
	class Rifle_Base;
	class Izh18_Base: Rifle_Base
	{
		scope = 0;
		weight = 3200;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.5,10,170,4,10};
		ironsightsExcludingOptics[] = {"HuntingOptic"};
		DisplayMagazine = 0;
		WeaponLength = 0.981055;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		magazines[] = {};
		ejectType = 3;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\izh18\izh18_reload",0.8,1,20};
		reloadSound[] = {"",0.05623413,1,20};
		reloadAction = "ReloadIZH18";
		shotAction = "";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"IZH18_Shot_SoundSet","IZH18_Tail_SoundSet","IZH18_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"IZH18_silencerHomeMade_SoundSet","IZH18_silencerHomeMadeTail_SoundSet","IZH18_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\izh18\izh18_shot_0",1,1,800};
			begin2[] = {"dz\sounds\weapons\firearms\izh18\izh18_shot_1",1,1,800};
			soundBegin[] = {"begin1",0.56,"begin2",0.5};
			reloadTime = 1;
			recoil = "recoil_izh18";
			recoilProne = "recoil_izh18_prone";
			dispersion = 0.001;
			magazineSlot = "magazine";
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\AK101\akSilenced",1,1,300};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					overridePoint = "Usti hlavne";
				};
				class ChamberFlash
				{
					overridePoint = "dust_point";
					overrideParticle = "weapon_dust_izh18_01";
				};
			};
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {200};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 200;
			distanceZoomMax = 200;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class walkErc_L
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 1;
				};
				class walkErc_R
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_R_SoundSet";
					id = 2;
				};
				class runErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 3;
				};
				class runErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_R_SoundSet";
					id = 4;
				};
				class sprintErc_L
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 5;
				};
				class sprintErc_R
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 6;
				};
				class walkCro_L
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 21;
				};
				class walkCro_R
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 22;
				};
				class runCro_L
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 23;
				};
				class runCro_R
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 24;
				};
				class walkProne_L
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 31;
				};
				class walkProne_R
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 32;
				};
				class runProne_L
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 33;
				};
				class runProne_R
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 34;
				};
				class jumpErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 35;
				};
				class jumpErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 36;
				};
				class landFootErc_L
				{
					soundSet = "Weapon_Movement_Rifle_landFootErc_SoundSet";
					id = 37;
				};
				class landFootErc_R
				{
					soundSet = "Weapon_Movement_Rifle_landFootErc_SoundSet";
					id = 38;
				};
				class walkRasErc_L
				{
					soundSet = "Weapon_Movement_Rifle_walkRasErc_SoundSet";
					id = 51;
				};
				class walkRasErc_R
				{
					soundSet = "Weapon_Movement_Rifle_walkRasErc_SoundSet";
					id = 52;
				};
				class runRasErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runRasErc_SoundSet";
					id = 53;
				};
				class runRasErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runRasErc_SoundSet";
					id = 54;
				};
				class HandStep_L
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 61;
				};
				class HandStep_R
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 62;
				};
				class HandStep_Hard_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 63;
				};
				class HandStep_Hard_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 64;
				};
				class landFeetErc
				{
					soundSet = "Weapon_Movement_Rifle_landFeetErc_SoundSet";
					id = 100;
				};
				class Weapon_Movement_Rifle_Walk
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 101;
				};
				class Weapon_Movement_Rifle_Run
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 102;
				};
				class Weapon_Movement_Rifle_Sprint
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 103;
				};
				class Weapon_Movement_Rifle_Land
				{
					soundSet = "Weapon_Movement_Rifle_landFeetErc_SoundSet";
					id = 104;
				};
				class Char_Gestures_Hand_Grab_Rifle
				{
					soundSet = "Char_Gestures_Hand_Grab_FabricRifle_SoundSet";
					id = 892;
				};
				class drop
				{
					soundset = "rifle_drop_SoundSet";
					id = 898;
				};
				class bodyfall_rifle_light
				{
					soundSet = "pickUpRifleLight_SoundSet";
					id = 13400;
				};
				class bodyfall_rifle
				{
					soundset = "pickUpRifle_SoundSet";
					id = 13401;
				};
			};
		};
	};
	class Izh18: Izh18_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Izh180";
		descriptionShort = "$STR_cfgWeapons_Izh181";
		model = "\dz\weapons\firearms\Izh18\Izh18.p3d";
		attachments[] = {"weaponWrap"};
		itemSize[] = {9,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\Izh18\data\Izh18_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\Izh18\data\Izh18.rvmat"};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_izh18_01";
					ignoreIfSuppressed = 1;
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\Izh18\data\Izh18.rvmat"}},{0.7,{"DZ\weapons\firearms\Izh18\data\Izh18.rvmat"}},{0.5,{"DZ\weapons\firearms\Izh18\data\Izh18_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\Izh18\data\Izh18_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\Izh18\data\Izh18_destruct.rvmat"}}};
				};
			};
		};
	};
	class SawedoffIzh18: Izh18
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_SawedoffIzh180";
		descriptionShort = "$STR_cfgWeapons_SawedoffIzh181";
		model = "\dz\weapons\firearms\Izh18\Izh18_sawedoff.p3d";
		lootCategory = "Crafted";
		itemSize[] = {5,2};
		weight = 2800;
		attachments[] = {};
		recoilModifier[] = {1,1,1};
		firespreadangle = 3;
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"IZH18_Shot_SoundSet","IZH18_Tail_SoundSet","IZH18_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"IZH18_silencerHomeMade_SoundSet","IZH18_silencerHomeMadeTail_SoundSet","IZH18_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_0",1.7782794,1,1000};
			begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_1",1.7782794,1,1000};
			begin3[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_2",1.7782794,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 1;
			dispersion = 0.08;
			recoil = "recoil_izh18sawedoff";
			recoilProne = "recoil_izh18sawedoff";
		};
	};
};
