////////////////////////////////////////////////////////////////////
//DeRap: weapons_pistols\mkii\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Mon Sep 16 14:14:07 2019 : 'file' last modified on Wed Aug 14 11:04:51 2019
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
	class DZ_Pistols_mkii
	{
		units[] = {"mkii"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class Pistol_Base;
	class MKII_Base: Pistol_Base
	{
		scope = 0;
		weight = 1300;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.5,10,280,4,10};
		WeaponLength = 0.560518;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"Mag_MKII_10Rnd"};
		chamberableFrom[] = {"Ammo_22"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\FNX45\FNX_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\MkII\MkII_reload",0.7,1,20};
		reloadAction = "ReloadRugerMK2";
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"AmphibianS_Shot_SoundSet","AmphibianS_Tail_SoundSet","AmphibianS_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AmphibianS_silencerHomeMade_SoundSet","AmphibianS_silencerHomeMadeTail_SoundSet","AmphibianS_InteriorTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\MkII\MkII_close_0",0.8,1,80};
			begin2[] = {"dz\sounds\weapons\firearms\MkII\MkII_close_1",0.8,1,80};
			begin3[] = {"dz\sounds\weapons\firearms\MkII\MkII_close_2",0.8,1,80};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\MkII\MkII_close_2",0.02,1,20};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 0.08;
			recoil = "recoil_mkii";
			recoilProne = "recoil_mkii_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 8.0;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoPistol
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
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 1;
				};
				class walkErc_R
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_R_SoundSet";
					id = 2;
				};
				class runErc_L
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 3;
				};
				class runErc_R
				{
					soundSet = "Weapon_Movement_Pistol_runErc_R_SoundSet";
					id = 4;
				};
				class sprintErc_L
				{
					soundSet = "Weapon_Movement_Pistol_sprintErc_SoundSet";
					id = 5;
				};
				class sprintErc_R
				{
					soundSet = "Weapon_Movement_Pistol_sprintErc_SoundSet";
					id = 6;
				};
				class walkCro_L
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 21;
				};
				class walkCro_R
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 22;
				};
				class runCro_L
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 23;
				};
				class runCro_R
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 24;
				};
				class walkProne_L
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 31;
				};
				class walkProne_R
				{
					soundSet = "Weapon_Movement_Pistol_walkCro_SoundSet";
					id = 32;
				};
				class runProne_L
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 33;
				};
				class runProne_R
				{
					soundSet = "Weapon_Movement_Pistol_runCro_SoundSet";
					id = 34;
				};
				class jumpErc_L
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 35;
				};
				class jumpErc_R
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 36;
				};
				class landFootErc_L
				{
					soundSet = "Weapon_Movement_Pistol_landFootErc_SoundSet";
					id = 37;
				};
				class landFootErc_R
				{
					soundSet = "Weapon_Movement_Pistol_landFootErc_SoundSet";
					id = 38;
				};
				class walkRasErc_L
				{
					soundSet = "Weapon_Movement_Pistol_walkRasErc_SoundSet";
					id = 51;
				};
				class walkRasErc_R
				{
					soundSet = "Weapon_Movement_Pistol_walkRasErc_SoundSet";
					id = 52;
				};
				class runRasErc_L
				{
					soundSet = "Weapon_Movement_Pistol_runRasErc_SoundSet";
					id = 53;
				};
				class runRasErc_R
				{
					soundSet = "Weapon_Movement_Pistol_runRasErc_SoundSet";
					id = 54;
				};
				class HandStep_L
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 61;
				};
				class HandStep_R
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 62;
				};
				class HandStep_Hard_L
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 63;
				};
				class HandStep_Hard_R
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 64;
				};
				class landFeetErc
				{
					soundSet = "Weapon_Movement_Pistol_landFeetErc_SoundSet";
					id = 100;
				};
				class Weapon_Movement_Pistol_Walk
				{
					soundSet = "Weapon_Movement_Pistol_walkErc_L_SoundSet";
					id = 101;
				};
				class Weapon_Movement_Pistol_Run
				{
					soundSet = "Weapon_Movement_Pistol_runErc_L_SoundSet";
					id = 102;
				};
				class Weapon_Movement_Pistol_Sprint
				{
					soundSet = "Weapon_Movement_Pistol_sprintErc_SoundSet";
					id = 103;
				};
				class Weapon_Movement_Pistol_Land
				{
					soundSet = "Weapon_Movement_Pistol_landFeetErc_SoundSet";
					id = 104;
				};
				class pickup
				{
					soundSet = "pickUpPistol_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "pistol_drop_SoundSet";
					id = 898;
				};
				class bodyfall_pistol
				{
					soundSet = "pickUpPistol_SoundSet";
					id = 13400;
				};
			};
		};
	};
	class MKII: MKII_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_MKII0";
		descriptionShort = "$STR_cfgWeapons_MKII1";
		model = "\dz\weapons\pistols\mkii\rugerMKII.p3d";
		attachments[] = {};
		itemSize[] = {4,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\mkii\data\ruger_metal_1.rvmat"}},{0.7,{"DZ\weapons\pistols\mkii\data\ruger_metal_1.rvmat"}},{0.5,{"DZ\weapons\pistols\mkii\data\ruger_metal_1_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\mkii\data\ruger_metal_1_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\mkii\data\ruger_metal_1_destruct.rvmat"}}};
				};
			};
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_fnx_02";
				};
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 1;
				maxOverheatingValue = 7;
				overheatingDecayInterval = 1;
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
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxymkii: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistol";
		model = "\dz\weapons\pistols\mkii\rugerMKII.p3d";
	};
};
