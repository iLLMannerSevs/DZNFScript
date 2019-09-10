////////////////////////////////////////////////////////////////////
//DeRap: weapons_shotguns\Mp133\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Sep 10 15:12:32 2019 : 'file' last modified on Mon Aug 12 12:21:51 2019
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
	class DZ_Weapons_Shotguns_MP133
	{
		units[] = {"ShotgunMp133","ShotgunMp133_Pistol_Grip"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Weapons"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoShotgun;
class cfgWeapons
{
	class Shotgun_Base;
	class Mp133Shotgun_Base: Shotgun_Base
	{
		scope = 0;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 6;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_12gaPellets","Ammo_12gaSlug"};
		magazines[] = {};
		DisplayMagazine = 0;
		PPDOFProperties[] = {1,0.5,10,140,4,10};
		WeaponLength = 1.03525;
		ejectType = 0;
		recoilModifier[] = {1,1,1};
		cartridgeCreateTime[] = {0.55,0.82};
		reloadSkips[] = {0.26,0.4,0.53,0.64,0.735};
		drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\shotguns\mp133\mp133_reload_0",0.8,1,20};
		reloadSound[] = {"dz\sounds\weapons\shotguns\mp133\mp133_pump_0",1.0,1,20};
		reloadAction = "ReloadMP133";
		shotAction = "ReloadMP133Shot";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke";
				};
				class SmokeCloud2
				{
					overrideParticle = "weapon_shot_winded_smoke";
				};
				class SmokeCloud3BadlyDamaged
				{
					overrideParticle = "weapon_shot_winded_smoke";
					onlyWithinHealthLabel[] = {3,4};
				};
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_mp133_01";
					illuminateWorld = 1;
				};
				class BadlyDamagedChamberSmoke
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart";
					overrideDirectionPoint = "Nabojniceend";
					onlyWithinHealthLabel[] = {3,4};
				};
				class BadlyDamagedChamberSmokeRaise
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart";
					onlyWithinHealthLabel[] = {3,4};
				};
			};
			class OnOverheating
			{
				maxOverheatingValue = 4;
				shotsToStartOverheating = 1;
				overheatingDecayInterval = 3;
				class SmokingBarrel
				{
					overrideParticle = "smoking_barrel_small";
				};
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen = 1;
					overrideParticle = "smoking_barrel_small";
					overridePoint = "Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart";
				};
			};
		};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Mp133_Shot_SoundSet","Mp133_Tail_SoundSet","Mp133_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\shotguns\mp133\mp133_single_0",1,1,800};
			begin2[] = {"dz\sounds\weapons\shotguns\mp133\mp133_single_1",1,1,800};
			begin3[] = {"dz\sounds\weapons\shotguns\mp133\mp133_single_2",1,1,800};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 1;
			recoil = "recoil_Mp133";
			recoilProne = "recoil_Mp133_prone";
			dispersion = 0.01;
			firespreadangle = 1.5;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoShotgun
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {25};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class walkErc_L
				{
					soundSet = "Weapon_Movement_Shotgun_walkErc_L_SoundSet";
					id = 1;
				};
				class walkErc_R
				{
					soundSet = "Weapon_Movement_Shotgun_walkErc_R_SoundSet";
					id = 2;
				};
				class runErc_L
				{
					soundSet = "Weapon_Movement_Shotgun_runErc_L_SoundSet";
					id = 3;
				};
				class runErc_R
				{
					soundSet = "Weapon_Movement_Shotgun_runErc_R_SoundSet";
					id = 4;
				};
				class sprintErc_L
				{
					soundSet = "Weapon_Movement_Shotgun_sprintErc_SoundSet";
					id = 5;
				};
				class sprintErc_R
				{
					soundSet = "Weapon_Movement_Shotgun_sprintErc_SoundSet";
					id = 6;
				};
				class walkCro_L
				{
					soundSet = "Weapon_Movement_Shotgun_walkCro_SoundSet";
					id = 21;
				};
				class walkCro_R
				{
					soundSet = "Weapon_Movement_Shotgun_walkCro_SoundSet";
					id = 22;
				};
				class runCro_L
				{
					soundSet = "Weapon_Movement_Shotgun_runCro_SoundSet";
					id = 23;
				};
				class runCro_R
				{
					soundSet = "Weapon_Movement_Shotgun_runCro_SoundSet";
					id = 24;
				};
				class walkProne_L
				{
					soundSet = "Weapon_Movement_Shotgun_walkCro_SoundSet";
					id = 31;
				};
				class walkProne_R
				{
					soundSet = "Weapon_Movement_Shotgun_walkCro_SoundSet";
					id = 32;
				};
				class runProne_L
				{
					soundSet = "Weapon_Movement_Shotgun_runCro_SoundSet";
					id = 33;
				};
				class runProne_R
				{
					soundSet = "Weapon_Movement_Shotgun_runCro_SoundSet";
					id = 34;
				};
				class jumpErc_L
				{
					soundSet = "Weapon_Movement_Shotgun_runErc_L_SoundSet";
					id = 35;
				};
				class jumpErc_R
				{
					soundSet = "Weapon_Movement_Shotgun_runErc_L_SoundSet";
					id = 36;
				};
				class landFootErc_L
				{
					soundSet = "Weapon_Movement_Shotgun_landFootErc_SoundSet";
					id = 37;
				};
				class landFootErc_R
				{
					soundSet = "Weapon_Movement_Shotgun_landFootErc_SoundSet";
					id = 38;
				};
				class walkRasErc_L
				{
					soundSet = "Weapon_Movement_Shotgun_walkRasErc_SoundSet";
					id = 51;
				};
				class walkRasErc_R
				{
					soundSet = "Weapon_Movement_Shotgun_walkRasErc_SoundSet";
					id = 52;
				};
				class runRasErc_L
				{
					soundSet = "Weapon_Movement_Shotgun_runRasErc_SoundSet";
					id = 53;
				};
				class runRasErc_R
				{
					soundSet = "Weapon_Movement_Shotgun_runRasErc_SoundSet";
					id = 54;
				};
				class HandStep_L
				{
					soundSet = "Weapon_Movement_Shotgun_walkErc_L_SoundSet";
					id = 61;
				};
				class HandStep_R
				{
					soundSet = "Weapon_Movement_Shotgun_walkErc_L_SoundSet";
					id = 62;
				};
				class HandStep_Hard_L
				{
					soundSet = "Weapon_Movement_Shotgun_runErc_L_SoundSet";
					id = 63;
				};
				class HandStep_Hard_R
				{
					soundSet = "Weapon_Movement_Shotgun_runErc_L_SoundSet";
					id = 64;
				};
				class landFeetErc
				{
					soundSet = "Weapon_Movement_Shotgun_landFeetErc_SoundSet";
					id = 100;
				};
				class Weapon_Movement_Shotgun_Walk
				{
					soundSet = "Weapon_Movement_Shotgun_walkErc_L_SoundSet";
					id = 101;
				};
				class Weapon_Movement_Shotgun_Run
				{
					soundSet = "Weapon_Movement_Shotgun_runErc_L_SoundSet";
					id = 102;
				};
				class Weapon_Movement_Shotgun_Sprint
				{
					soundSet = "Weapon_Movement_Shotgun_sprintErc_L_SoundSet";
					id = 103;
				};
				class Weapon_Movement_Shotgun_Land
				{
					soundSet = "Weapon_Movement_Shotgun_landFeetErc_SoundSet";
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
	class Mp133Shotgun: Mp133Shotgun_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Mp133Shotgun0";
		descriptionShort = "$STR_cfgWeapons_Mp133Shotgun1";
		model = "\dz\weapons\shotguns\mp133\mp133.p3d";
		animName = "ShotgunMp133";
		lootTag[] = {"Civilian"};
		attachments[] = {"pistolOptics"};
		itemSize[] = {9,3};
		weight = 3300;
		hiddenSelectionsTextures[] = {"dz\weapons\shotguns\mp133\data\mp133_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\shotguns\mp133\data\mp133.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\shotguns\Mp133\data\mp133.rvmat"}},{0.7,{"DZ\weapons\shotguns\Mp133\data\mp133.rvmat"}},{0.5,{"DZ\weapons\shotguns\Mp133\data\mp133_damage.rvmat"}},{0.3,{"DZ\weapons\shotguns\Mp133\data\mp133_damage.rvmat"}},{0.0,{"DZ\weapons\shotguns\Mp133\data\mp133_destruct.rvmat"}}};
				};
			};
		};
	};
	class Mp133Shotgun_PistolGrip: Mp133Shotgun_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Mp133Shotgun_PistolGrip0";
		descriptionShort = "$STR_cfgWeapons_Mp133Shotgun_PistolGrip1";
		model = "\dz\weapons\shotguns\mp133\mp133_pistol_grip.p3d";
		animName = "ShotgunMp133_Pistol_Grip";
		lootTag[] = {"Police","Military_east","Military_west"};
		attachments[] = {"pistolOptics"};
		itemSize[] = {8,6};
		weight = 3200;
		chamberSize = 4;
		reloadAction = "ReloadMP133_grip";
		shotAction = "ReloadMP133_grip_shot";
		recoilModifier[] = {1,1,1};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\shotguns\Mp133\data\mp133_pistol_grip.rvmat"}},{0.7,{"DZ\weapons\shotguns\Mp133\data\mp133_pistol_grip.rvmat"}},{0.5,{"DZ\weapons\shotguns\Mp133\data\mp133_pistol_grip_damage.rvmat"}},{0.3,{"DZ\weapons\shotguns\Mp133\data\mp133_pistol_grip_damage.rvmat"}},{0.0,{"DZ\weapons\shotguns\Mp133\data\mp133_pistol_grip_destruct.rvmat"}}};
				};
			};
		};
	};
};
