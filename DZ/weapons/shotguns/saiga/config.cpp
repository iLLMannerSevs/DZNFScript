////////////////////////////////////////////////////////////////////
//DeRap: weapons_shotguns\saiga\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 14:30:16 2019 : 'file' last modified on Mon Apr 08 17:48:22 2019
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
	class DZ_Weapons_Firearms_SaigaK
	{
		units[] = {"Saiga12K"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
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
	class Saiga12KShotgun_Base: Shotgun_Base
	{
		scope = 0;
		weight = 3600;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_12gaPellets","Ammo_12gaSlug"};
		magazines[] = {"Mag_Saiga_5Rnd","Mag_Saiga_8Rnd","Mag_Saiga_Drum20Rnd"};
		magazineSwitchTime = 0.2;
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		reloadAction = "ReloadAKM";
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\akm\Akm_reload",0.8,1,20};
		drySound[] = {"dz\sounds\weapons\firearms\SKS\SKS_dry",0.5,1,20};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Saiga12_Shot_SoundSet","Saiga12_Tail_SoundSet","Saiga12_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_0",1,1,800};
			begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_1",1,1,800};
			begin3[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_2",1,1,800};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			reloadTime = 0.1;
			recoil = "recoil_Saiga12";
			recoilProne = "recoil_Saiga12_prone";
			dispersion = 0.01;
			firespreadangle = 1.5;
			magazineSlot = "magazine";
			beginSilenced_Pro[] = {"dz\sounds\weapons\firearms\AK101\akSilenced",1,1,200};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\AK101\akSilenced",1,1,300};
			soundBeginExt[] = {{"beginSilenced_Pro",1},{"beginSilenced_HomeMade",1}};
		};
		class OpticsInfo: OpticsInfoShotgun{};
	};
	class Saiga12KShotgun: Saiga12KShotgun_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Saiga12KShotgun0";
		descriptionShort = "$STR_cfgWeapons_Saiga12KShotgun1";
		model = "\dz\weapons\shotguns\saiga\saiga.p3d";
		attachments[] = {"weaponButtstockSaiga","weaponOpticsAK","weaponWrap"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\shotguns\saiga\data\saiga.rvmat"}},{0.7,{"DZ\weapons\shotguns\saiga\data\saiga.rvmat"}},{0.5,{"DZ\weapons\shotguns\saiga\data\saiga_damage.rvmat"}},{0.3,{"DZ\weapons\shotguns\saiga\data\saiga_damage.rvmat"}},{0.0,{"DZ\weapons\shotguns\saiga\data\saiga_destruct.rvmat"}}};
				};
			};
		};
	};
};
