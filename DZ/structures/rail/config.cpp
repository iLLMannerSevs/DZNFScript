////////////////////////////////////////////////////////////////////
//DeRap: structures_rail\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 29 19:48:31 2019 : 'file' last modified on Tue Jul 23 11:43:49 2019
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
	class DZ_Structures_Rail
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Land_Rail_Station_Big: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Rail\Houses\Rail_Station_Big.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodFrontOpen";
				soundClose = "doorWoodFrontClose";
				soundLocked = "doorWoodFrontRattle";
				soundOpenABit = "doorWoodFrontOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
		};
	};
	class Land_Rail_Station_Small: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Rail\Houses\Rail_Station_Small.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors4
			{
				displayName = "door 4";
				component = "Doors4";
				soundPos = "doors4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
		};
	};
	class Land_Rail_Warehouse_Small: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Rail\Houses\Rail_Warehouse_Small.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodSlideOpen";
				soundClose = "doorWoodSlideClose";
				soundLocked = "doorWoodSlideRattle";
				soundOpenABit = "doorWoodSlideOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodSlideOpen";
				soundClose = "doorWoodSlideClose";
				soundLocked = "doorWoodSlideRattle";
				soundOpenABit = "doorWoodSlideOpenABit";
			};
		};
	};
};
