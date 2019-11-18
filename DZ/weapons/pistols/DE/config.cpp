////////////////////////////////////////////////////////////////////
//DeRap: weapons_pistols\DE\config.bin
//Produced from mikero's Dos Tools Dll version 7.37
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Mon Nov 18 16:17:46 2019 : 'file' last modified on Fri Nov 15 10:04:31 2019
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
	class DZ_Pistols_DE
	{
		units[] = {"DE_Gold"};
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
	class DE_Base: Pistol_Base
	{
		scope = 0;
		weight = 1500;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		discreteDistance[] = {100};
		discreteDistanceInitIndex = 1;
		value = 0;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"Mag_DE_9rnd"};
		chamberableFrom[] = {"Ammo_357"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\FNX45\FNX_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\waltherP1\WaltherP1_reload_00",0.8,1,20};
		reloadAction = "ReloadRugerP1";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"DEG_Shot_SoundSet","DEG_Tail_SoundSet","DEG_InteriorTail_SoundSet"};
			reloadTime = 0.18;
			recoil = "recoil_DE";
			recoilProne = "recoil_DE_prone";
			dispersion = 0.006;
			magazineSlot = "magazine";
			begin1[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_2",1,1,700};
			begin2[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_1",1,1,700};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin1",0.33333,"begin2",0.33333};
			beginSilenced_Pro1[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced",1,1,60};
			beginSilenced_Pro2[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced2",1,1,60};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro1",0.5,"beginSilenced_Pro2",0.5},{"beginSilenced_HomeMade",1}};
		};
	};
	class DE: DE_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_DE0";
		descriptionShort = "$STR_cfgWeapons_DE1";
		model = "\dz\weapons\pistols\DE\DE.p3d";
		attachments[] = {};
		itemSize[] = {3,2};
		hiddenSelectionsTextures[] = {"dz\weapons\pistols\DE\data\gold_DE_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\pistols\DE\data\gold_de.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\DE\data\gold_de.rvmat"}},{0.7,{"DZ\weapons\pistols\DE\data\gold_de.rvmat"}},{0.5,{"DZ\weapons\pistols\DE\data\gold_de_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\DE\data\gold_de_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\DE\data\gold_de_destruct.rvmat"}}};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyDE: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistol";
		model = "\dz\weapons\pistols\DE\DE.p3d";
	};
};
