////////////////////////////////////////////////////////////////////
//DeRap: weapons_explosives\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 22 23:18:36 2019 : 'file' last modified on Sat Jul 20 20:35:25 2019
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
	class DZ_Weapons_Explosives
	{
		units[] = {"SmokeGrenade","FlashGrenade","Grenade","GrenadeRDG5","smokegrenade_rdg2"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgAmmo
{
	class DefaultAmmo;
	class RGD5Grenade_Ammo: DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 3;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 0.4;
			class Health
			{
				damage = 50;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
	class M67Grenade_Ammo: DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 5;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 0.4;
			class Health
			{
				damage = 50;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
	class FlashGrenade_Ammo: DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 5;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		slowdownThreshold = 100;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Flashgrenade_Explosion_SoundSet","Flashgrenade_Explosion_Tail_SoundSet"};
		class DamageApplied
		{
			type = "FragGrenade";
			class Health
			{
				damage = 5;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
		};
		class NoiseExplosion
		{
			strength = 60;
			type = "shot";
		};
	};
	class LandFuelFeed_Ammo: DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 5;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		class DamageApplied
		{
			type = "FragGrenade";
			class Health
			{
				damage = 50;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Grenade_Base;
	class RGD5Grenade: Grenade_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_RGD5Grenade0";
		descriptionShort = "$STR_CfgVehicles_RGD5Grenade1";
		model = "\dz\weapons\explosives\frag_RGD5.p3d";
		weight = 350;
		lootTag[] = {"Military_east"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\frag_RGD5_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\explosives\data\frag_RGD5.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\explosives\data\frag_RGD5.rvmat"}},{0.7,{"DZ\weapons\explosives\data\frag_RGD5.rvmat"}},{0.5,{"DZ\weapons\explosives\data\frag_RGD5_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\frag_RGD5_damage.rvmat"}},{0.0,{"DZ\weapons\explosives\data\frag_RGD5_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Grenade_unpin
				{
					soundSet = "Grenade_unpin_SoundSet";
					id = 201;
				};
				class turnOnRadio_Pin
				{
					soundSet = "Grenade_pin_SoundSet";
					id = 1006;
				};
			};
		};
	};
	class M67Grenade: Grenade_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_M67Grenade0";
		descriptionShort = "$STR_CfgVehicles_M67Grenade1";
		model = "\dz\weapons\explosives\grenade.p3d";
		weight = 400;
		lootTag[] = {"Military_west"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\grenade_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\explosives\data\grenade.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.7,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.5,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0.0,{"DZ\weapons\explosives\data\grenade_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Grenade_unpin
				{
					soundSet = "Grenade_unpin_SoundSet";
					id = 201;
				};
				class turnOnRadio_Pin
				{
					soundSet = "Grenade_pin_SoundSet";
					id = 1006;
				};
			};
		};
	};
	class M18SmokeGrenade_ColorBase: Grenade_Base
	{
		displayName = "$STR_CfgVehicles_M18SmokeGrenade_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_M18SmokeGrenade_ColorBase1";
		model = "\dz\weapons\explosives\smokegrenade.p3d";
		rotationFlags = 17;
		lootTag[] = {"Military_west"};
		weight = 500;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"dz\weapons\explosives\data\smokegrenade.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\explosives\data\smokegrenade.rvmat"}},{0.7,{"DZ\weapons\explosives\data\smokegrenade.rvmat"}},{0.5,{"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"}},{0.0,{"DZ\weapons\explosives\data\smokegrenade_destruct.rvmat"}}};
				};
			};
		};
		class EnergyManager
		{
			energyAtSpawn = 90;
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Unpin
				{
					soundSet = "SmokegGrenades_M18_oneshot_ignite_SoundSet";
					id = 201;
				};
			};
		};
	};
	class M18SmokeGrenade_Red: M18SmokeGrenade_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_red_co.paa"};
	};
	class M18SmokeGrenade_Green: M18SmokeGrenade_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_green_co.paa"};
	};
	class M18SmokeGrenade_Yellow: M18SmokeGrenade_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_yellow_co.paa"};
	};
	class M18SmokeGrenade_Purple: M18SmokeGrenade_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_violet_co.paa"};
	};
	class M18SmokeGrenade_White: M18SmokeGrenade_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_white_co.paa"};
	};
	class RDG2SmokeGrenade_ColorBase: Grenade_Base
	{
		displayName = "$STR_CfgVehicles_RDG2SmokeGrenade_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_RDG2SmokeGrenade_ColorBase1";
		model = "\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		rotationFlags = 17;
		lootTag[] = {"Military_east","Police"};
		weight = 300;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"dz\weapons\explosives\data\smokegrenade_rdg2.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\explosives\data\smokegrenade_rdg2.rvmat"}},{0.7,{"DZ\weapons\explosives\data\smokegrenade_rdg2.rvmat"}},{0.5,{"DZ\weapons\explosives\data\smokegrenade_rdg2_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\smokegrenade_rdg2_damage.rvmat"}},{0.0,{"DZ\weapons\explosives\data\smokegrenade_rdg2_destruct.rvmat"}}};
				};
			};
		};
		class EnergyManager
		{
			energyAtSpawn = 90;
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Unpin
				{
					soundSet = "SmokegGrenades_RDG2_oneshot_ignite_SoundSet";
					id = 201;
				};
			};
		};
	};
	class RDG2SmokeGrenade_Black: RDG2SmokeGrenade_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_rdg2_black_co.paa"};
	};
	class RDG2SmokeGrenade_White: RDG2SmokeGrenade_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\smokegrenade_rdg2_white_co.paa"};
	};
	class FlashGrenade: Grenade_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FlashGrenade0";
		descriptionShort = "$STR_CfgVehicles_FlashGrenade1";
		model = "\dz\weapons\explosives\flashbang.p3d";
		rotationFlags = 17;
		weight = 300;
		lootTag[] = {"Military_east","Military_west","Police"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\flashbang_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\explosives\data\flashbang.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\explosives\data\flashbang.rvmat"}},{0.7,{"DZ\weapons\explosives\data\flashbang.rvmat"}},{0.5,{"DZ\weapons\explosives\data\flashbang_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\flashbang_damage.rvmat"}},{0.0,{"DZ\weapons\explosives\data\flashbang_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Grenade_unpin
				{
					soundSet = "Grenade_unpin_SoundSet";
					id = 201;
				};
				class turnOnRadio_Pin
				{
					soundSet = "Grenade_pin_SoundSet";
					id = 1006;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyfrag_RGD5: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "tripWireAttachment";
		model = "\dz\weapons\explosives\frag_RGD5.p3d";
	};
	class Proxygrenade: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "tripWireAttachment";
		model = "\dz\weapons\explosives\grenade.p3d";
	};
	class Proxysmokegrenade: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "tripWireAttachment";
		model = "\dz\weapons\explosives\smokegrenade.p3d";
	};
	class Proxysmokegrenade_rdg2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "tripWireAttachment";
		model = "\dz\weapons\explosives\smokegrenade_rdg2.p3d";
	};
	class Proxyflashbang: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "tripWireAttachment";
		model = "\dz\weapons\explosives\flashbang.p3d";
	};
};