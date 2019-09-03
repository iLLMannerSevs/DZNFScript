////////////////////////////////////////////////////////////////////
//DeRap: weapons_pistols\magnum\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Sep 03 15:36:44 2019 : 'file' last modified on Wed Aug 14 11:04:49 2019
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
	class DZ_Pistols_Magnum
	{
		units[] = {"magnum"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class Pistol_Base;
	class Magnum_Base: Pistol_Base
	{
		scope = 0;
		lootTag[] = {"Civilian"};
		weight = 1400;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		value = 0;
		chamberSize = 6;
		chamberedRound = "";
		magazines[] = {};
		chamberableFrom[] = {"Ammo_357","Mag_357Speedloader_6Rnd"};
		chamberTime = 0.5;
		cartridgeCreateTime[] = {0.8};
		drumReloadStart = 1.0;
		drumReloadEnd = 0.8;
		ejectType = 9;
		recoilModifier[] = {1,1,1};
		drySound[] = {"DZ\sounds\weapons\firearms\magnum\Magnum_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\magnum\magnum_reload2",0.8,1,20};
		reloadAction = "ReloadPistolMagnum";
		bullet1[] = {"",0.17782794,1,15};
		bullet2[] = {"",0.17782794,1,15};
		bullet3[] = {"",0.17782794,1,15};
		bullet4[] = {"",0.17782794,1,15};
		bullet5[] = {"",0.31622776,1,15};
		bullet6[] = {"",0.31622776,1,15};
		bullet7[] = {"",0.31622776,1,15};
		bullet8[] = {"",0.31622776,1,15};
		bullet9[] = {"",0.17782794,1,15};
		bullet10[] = {"",0.17782794,1,15};
		bullet11[] = {"",0.17782794,1,15};
		bullet12[] = {"",0.17782794,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Magnum_Shot_SoundSet","Magnum_Tail_SoundSet","Magnum_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_2",1,1,700};
			begin2[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_1",1,1,700};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.25;
			recoil = "recoil_magnum";
			recoilProne = "recoil_magnum_prone";
			dispersion = 0.02;
			magazineSlot = "magazine";
		};
	};
	class Magnum: Magnum_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Magnum0";
		descriptionShort = "$STR_cfgWeapons_Magnum1""Combat Magnum"""". It was first introduced in 1955, the same year as Smith & Wesson's M29 .44 Magnum.""";
		model = "\dz\weapons\pistols\magnum\magnum.p3d";
		itemSize[] = {4,2};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\pistols\magnum\data\magnum.rvmat","DZ\weapons\pistols\magnum\data\magnum_damage.rvmat","DZ\weapons\pistols\magnum\data\magnum_destruct.rvmat"};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxymagnum: ProxyAttachment
	{
		scope = 2;
	};
};
