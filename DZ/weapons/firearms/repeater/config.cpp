////////////////////////////////////////////////////////////////////
//DeRap: weapons_firearms\repeater\config.bin
//Produced from mikero's Dos Tools Dll version 7.37
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Fri Nov 22 16:14:00 2019 : 'file' last modified on Fri Nov 15 10:00:56 2019
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
	class DZ_Weapons_Firearms_Repeater
	{
		units[] = {"Repeater"};
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
	class Repeater_Base: Rifle_Base
	{
		scope = 0;
		animName = "Repeater";
		weight = 2720;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 7;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_357"};
		magazines[] = {};
		ejectType = 0;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\rossim92\rossim92_reload_0",0.8,1,20};
		reloadSound[] = {"dz\sounds\weapons\firearms\rossim92\rossim92_cycle_0",0.8,1,20};
		reloadSkips[] = {0.21,0.35,0.48,0.59,0.69,0.78};
		reloadAction = "ReloadRepeater";
		shotAction = "ReloadRepeaterShot";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Repeater_Shot_SoundSet","Repeater_Tail_SoundSet","Repeater_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Repeater_silencerHomeMade_SoundSet","Repeater_silencerHomeMadeTail_SoundSet","Repeater_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\rossim92\rossim92_single_0",3.9810717,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\rossim92\rossim92_single_1",3.9810717,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 1;
			recoil = "recoil_repeater";
			recoilProne = "recoil_repeater_prone";
			dispersion = 0.001;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
	};
	class Repeater: Repeater_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Repeater0";
		descriptionShort = "$STR_cfgWeapons_Repeater1";
		model = "\dz\weapons\firearms\repeater\repeater.p3d";
		attachments[] = {"weaponWrap","suppressorImpro"};
		itemSize[] = {9,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\repeater\data\repeater_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\repeater\data\repeater.rvmat"};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\firearms\repeater\data\repeater.rvmat","DZ\weapons\firearms\repeater\data\repeater_damage.rvmat","DZ\weapons\firearms\repeater\data\repeater_destruct.rvmat"};
		};
	};
};
