////////////////////////////////////////////////////////////////////
//DeRap: weapons_firearms\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 20 16:37:17 2019 : 'file' last modified on Tue Aug 13 08:21:44 2019
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
	class DZ_Weapons_Firearms
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Weapons"};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class Mode_Safe: Mode_SemiAuto
{
	magazines[] = {};
};
class cfgWeapons
{
	class Rifle_Base;
};
