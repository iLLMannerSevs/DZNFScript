////////////////////////////////////////////////////////////////////
//DeRap: weapons_launchers\m203\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 20 16:37:21 2019 : 'file' last modified on Sat Jul 20 11:54:57 2019
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
	class DZ_Weapons_Launchers_M203
	{
		units[] = {"M203"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class Rifle_Base;
	class M203Base: Rifle_Base
	{
		scope = 1;
	};
	class M203: M203Base
	{
		scope = 2;
		model = "\DZ\weapons\launchers\m203\m203.p3d";
	};
	class M203_Standalone: M203Base
	{
		scope = 2;
		model = "\DZ\weapons\launchers\m203\m203.p3d";
	};
};
