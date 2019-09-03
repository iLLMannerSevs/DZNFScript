////////////////////////////////////////////////////////////////////
//DeRap: sounds_weapons\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Sep 03 15:33:24 2019 : 'file' last modified on Thu Aug 08 21:55:42 2019
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
	class DZ_Sounds_Weapons
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgActionSounds
{
	class craft_rounds
	{
		sounds[] = {"craft_rounds_0"};
		distance = 30;
	};
	class craft_loadMag
	{
		sounds[] = {"craft_loadMag_0"};
		distance = 30;
	};
	class action_punch
	{
		sounds[] = {"punch_swipes_0","punch_swipes_1","punch_swipes_2","punch_swipes_3","punch_swipes_4"};
		distance = 30;
	};
	class impact_flesh
	{
		sounds[] = {"impacts_flesh_0","impacts_flesh_1","impacts_flesh_2","impacts_flesh_3","impacts_flesh_4"};
		distance = 30;
	};
	class empty_arrows
	{
		sounds[] = {"Arrow_empty_0"};
		distance = 20;
	};
	class ammopops_1
	{
		sounds[] = {"ammopops_1"};
		distance = 30;
	};
	class ammopops_2
	{
		sounds[] = {"ammopops_2"};
		distance = 30;
	};
	class ammopops_3
	{
		sounds[] = {"ammopops_3"};
		distance = 30;
	};
	class ammopops_4
	{
		sounds[] = {"ammopops_4"};
		distance = 30;
	};
	class ammopops_5
	{
		sounds[] = {"ammopops_5"};
		distance = 30;
	};
	class ammopops_6
	{
		sounds[] = {"ammopops_6"};
		distance = 30;
	};
};
class CfgSounds
{
	class default
	{
		name = "";
		titles[] = {};
	};
	class craft_rounds_0: default
	{
		sound[] = {"\dz\sounds\effects\crafting\rounds_0",0.1,1,30};
	};
	class craft_loadMag_0: default
	{
		sound[] = {"\dz\sounds\arma2\weapons\rifles\reload-m16-1",0.1,1,30};
	};
	class punch_swipes_0: default
	{
		sound[] = {"\dz\sounds\effects\actions\punch_swipes_0",0.1,1,30};
	};
	class punch_swipes_1: default
	{
		sound[] = {"\dz\sounds\effects\actions\punch_swipes_1",0.1,1,30};
	};
	class punch_swipes_2: default
	{
		sound[] = {"\dz\sounds\effects\actions\punch_swipes_2",0.1,1,30};
	};
	class punch_swipes_3: default
	{
		sound[] = {"\dz\sounds\effects\actions\punch_swipes_3",0.1,1,30};
	};
	class punch_swipes_4: default
	{
		sound[] = {"\dz\sounds\effects\actions\punch_swipes_4",0.1,1,30};
	};
	class impacts_flesh_0: default
	{
		sound[] = {"\dz\sounds\effects\impacts\flesh_0",0.1,1,30};
	};
	class impacts_flesh_1: default
	{
		sound[] = {"\dz\sounds\effects\impacts\flesh_1",0.1,1,30};
	};
	class impacts_flesh_2: default
	{
		sound[] = {"\dz\sounds\effects\impacts\flesh_2",0.1,1,30};
	};
	class impacts_flesh_3: default
	{
		sound[] = {"\dz\sounds\effects\impacts\flesh_3",0.1,1,30};
	};
	class impacts_flesh_4: default
	{
		sound[] = {"\dz\sounds\effects\impacts\flesh_4",0.1,1,30};
	};
	class Arrow_empty_0: default
	{
		sound[] = {"\dz\sounds\weapons\bows\Arrow_eject",0.56234133,1,20};
	};
	class ammopops
	{
		name = "";
		titles[] = {0,""};
	};
	class ammopops_1: ammopops
	{
		sound[] = {"\dz\sounds\weapons\ammo\Ammopops_1",0.1,1,30};
	};
	class ammopops_2: ammopops
	{
		sound[] = {"\dz\sounds\weapons\ammo\Ammopops_2",0.1,1,30};
	};
	class ammopops_3: ammopops
	{
		sound[] = {"\dz\sounds\weapons\ammo\Ammopops_3",0.1,1,30};
	};
	class ammopops_4: ammopops
	{
		sound[] = {"\dz\sounds\weapons\ammo\Ammopops_4",0.1,1,30};
	};
	class ammopops_5: ammopops
	{
		sound[] = {"\dz\sounds\weapons\ammo\Ammopops_5",0.1,1,30};
	};
	class ammopops_6: ammopops
	{
		sound[] = {"\dz\sounds\weapons\ammo\Ammopops_6",0.1,1,30};
	};
};
