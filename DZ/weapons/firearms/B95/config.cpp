////////////////////////////////////////////////////////////////////
//DeRap: weapons_firearms\B95\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Mon Aug 26 15:31:59 2019 : 'file' last modified on Tue Aug 13 08:21:45 2019
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
	class DZ_Weapons_Firearms_B95
	{
		units[] = {"b95","b95_Black","b95_Green"};
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
	class B95_Base: Rifle_Base
	{
		scope = 0;
		lootTag[] = {"Civilian","Hunting"};
		weight = 2820;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 2;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_308Win","Ammo_308WinTracer","Mag_308WinSnaploader_2Rnd"};
		magazines[] = {};
		ejectType = 3;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.5,1,20};
		reloadAction = "ReloadB95";
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\B95\b95_reload2",0.8,1,20};
		reloadSound[] = {"",0.05623413,1,20};
		shotAction = "";
		tooltip = "_text = _this call fnc_generateTooltip;_text";
		hiddenSelections[] = {"camoGround"};
		modes[] = {"Single","Burst"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"B95_Shot_SoundSet","B95_Tail_SoundSet","B95_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\firearms\B95\b95_close_1",1,1,800};
			begin2[] = {"dz\sounds\weapons\firearms\B95\b95_close_0",1,1,800};
			begin3[] = {"dz\sounds\weapons\firearms\B95\b95_close_1",1,1,800};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.1;
			recoil = "recoil_b95";
			recoilProne = "recoil_b95_prone";
			dispersion = 0.001;
			magazineSlot = "magazine";
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"dz\sounds\weapons\firearms\B95\b95_close_0_double",1,1,900};
			begin2[] = {"dz\sounds\weapons\firearms\B95\b95_close_0_double",1,1,900};
			begin3[] = {"dz\sounds\weapons\firearms\B95\b95_close_0_double",1,1,900};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.01;
			recoil = "recoil_b95_double";
			recoilProne = "recoil_b95";
			dispersion = 0.001;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoRifle{};
	};
	class B95: B95_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_B950";
		descriptionShort = "$STR_cfgWeapons_B951";
		model = "\dz\weapons\firearms\B95\b95.p3d";
		attachments[] = {"weaponWrap","weaponOpticsHunting"};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\B95\data\b95_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\B95\data\b95.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.7,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.5,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\B95\Data\b95_destruct.rvmat"}}};
				};
			};
		};
	};
	class B95_Black: B95
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_B95_Black0";
		color = "Black";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\B95\data\b95_painted.rvmat"};
	};
	class B95_Green: B95
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_B95_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\B95\data\b95_painted.rvmat"};
	};
};
