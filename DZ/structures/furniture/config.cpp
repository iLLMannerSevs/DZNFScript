////////////////////////////////////////////////////////////////////
//DeRap: structures_furniture\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Oct 31 18:22:57 2019 : 'file' last modified on Thu Oct 03 10:17:17 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class DZ_Structures_Furniture
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Structures"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAlmara_open
	{
		scope = 2;
		model = "\DZ\structures\Furniture\Cases\almara\almara_open.p3d";
		autocenter = "false";
		reversed = "false";
		animated = "false";
		shadow = "false";
		proxyDisplayName = "Wardrobe";
		simulation = "alwaysshow";
		class Cargo
		{
			itemsCargoSize[] = {6,3};
			allowOwnedCargoManipulation = 1;
			openable = "true";
		};
	};
};
