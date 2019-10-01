////////////////////////////////////////////////////////////////////
//DeRap: animals\sus_scrofa\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Oct 01 13:53:03 2019 : 'file' last modified on Mon Aug 26 15:09:43 2019
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
	class DZ_Animals_sus_scrofa
	{
		units[] = {"Animal_SusScrofa"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Animals"};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Animal_SusScrofa: AnimalBase
	{
		simulation = "dayzanimal";
		scope = 2;
		model = "\DZ\animals\sus_scrofa\sus_scrofa.p3d";
		displayName = "$STR_CfgVehicles_Animal_SusScrofa0";
		descriptionShort = "$STR_CfgVehicles_Animal_SusScrofa1";
		aiAgentTemplate = "Herbivores_SusScrofa";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLabels[] = {1.0,0.7,0.5,0.3,0.0};
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 5000;
				};
			};
			class DamageZones
			{
				class Zone_Belly
				{
					canBleed = 1;
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 1;
					};
					class Blood
					{
						hitpoints = 5000;
						transferToGlobalCoef = 1;
					};
					class Shock
					{
						hitpoints = 5000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 5;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0.66;
							};
							class Blood
							{
								damage = 5;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.66;
							};
							class Blood
							{
								damage = 5;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"Zone_Belly"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.25;
				};
				class Zone_Chest
				{
					canBleed = 1;
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 5;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 2;
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
						class FragGrenade
						{
							class Health
							{
								damage = 2;
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
					};
					componentNames[] = {"Zone_Chest"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.25;
				};
				class Zone_Head
				{
					canBleed = 1;
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 1;
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
						class Projectile
						{
							class Health
							{
								damage = 1;
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
						class FragGrenade
						{
							class Health
							{
								damage = 1;
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
					};
					componentNames[] = {"Zone_Head"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.75;
				};
				class Zone_Legs
				{
					canBleed = 0;
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.1;
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
						class Projectile
						{
							class Health
							{
								damage = 0.1;
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
						class FragGrenade
						{
							class Health
							{
								damage = 0.1;
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
					};
					componentNames[] = {"Zone_Legs"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.25;
				};
				class Zone_Neck
				{
					canBleed = 1;
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.75;
							};
							class Blood
							{
								damage = 5;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0.66;
							};
							class Blood
							{
								damage = 5;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.66;
							};
							class Blood
							{
								damage = 5;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"Zone_Neck"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.25;
				};
				class Zone_Pelvis
				{
					canBleed = 0;
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.2;
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
						class Projectile
						{
							class Health
							{
								damage = 0.2;
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
						class FragGrenade
						{
							class Health
							{
								damage = 0.2;
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
					};
					componentNames[] = {"Zone_Pelvis"};
					transferToZonesNames[] = {"Zone_Spine"};
					transferToZonesCoefs[] = {0.5};
					fatalInjuryCoef = 0.25;
				};
				class Zone_Spine
				{
					canBleed = 1;
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0.66;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0.66;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"Zone_Spine"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.25;
				};
			};
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "PigSteakMeat";
				count = 13;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedPelt
			{
				item = "WildboarPelt";
				count = 1;
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.4,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 2;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
		};
		class enfanimsys
		{
			meshObject = "dz\animals\sus_scrofa\data\sus_scrofa_skeleton.xob";
			graphname = "dz\animals\animations\!graph_files\Herbivores\Herbivores_Graph.agr";
			defaultinstance = "dz\animals\animations\!graph_files\Herbivores\WildBoar_AnimInstance.asi";
			startnode = "Master_BoarAndPig_SM";
			skeletonName = "sus_scrofa_skeleton.xob";
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = {0.0,0.25,0.8,2.51,6.0,17.0};
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 8;
				};
				class Grazing1
				{
					soundLookupTable = "HoofSmallGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 9;
				};
				class Grazing2
				{
					soundLookupTable = "HoofSmallGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 10;
				};
				class Bodyfall
				{
					soundLookupTable = "HoofSmallBodyfall_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "HoofSmallSettle_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "HoofSmallRest2standA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "HoofSmallRest2standB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "HoofSmallStand2restA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "HoofSmallStand2restB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "HoofSmallStand2restC_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 17;
				};
				class Rub1
				{
					soundLookupTable = "HoofSmallRub1_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 18;
				};
				class Rub2
				{
					soundLookupTable = "HoofSmallRub2_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 19;
				};
				class GrazingHard1
				{
					soundLookupTable = "HoofSmallGrazingHard_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 20;
				};
				class GrazingHard2
				{
					soundLookupTable = "HoofSmallGrazingHard_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 21;
				};
				class GrazingLeave1
				{
					soundLookupTable = "HoofSmallGrazingLeave_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 22;
				};
				class GrazingLeave2
				{
					soundLookupTable = "HoofSmallGrazingLeave_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 23;
				};
			};
			class Sounds
			{
				class HogGrunt_A
				{
					soundSet = "HogGrunt_A_SoundSet";
					noise = "DeerRoarNoise";
					id = 1;
				};
				class HogGrunt_A_Squeal
				{
					soundSet = "HogGrunt_A_Squeal_SoundSet";
					noise = "DeerRoarNoise";
					id = 2;
				};
				class HogGrunt_B
				{
					soundSet = "HogGrunt_B_SoundSet";
					noise = "DeerRoarNoise";
					id = 3;
				};
				class HogGrunt_B_Long
				{
					soundSet = "HogGrunt_B_Long_SoundSet";
					noise = "DeerRoarNoise";
					id = 4;
				};
				class HogGrunt_C
				{
					soundSet = "HogGrunt_C_SoundSet";
					noise = "DeerRoarNoise";
					id = 5;
				};
				class HogGrunt_D
				{
					soundSet = "HogGrunt_D_SoundSet";
					noise = "DeerRoarNoise";
					id = 6;
				};
				class HogGrunt_E
				{
					soundSet = "HogGrunt_E_SoundSet";
					noise = "DeerRoarNoise";
					id = 7;
				};
				class HogGrunt_F
				{
					soundSet = "HogGrunt_F_SoundSet";
					noise = "DeerRoarNoise";
					id = 8;
				};
				class HogGrunt_G
				{
					soundSet = "HogGrunt_G_SoundSet";
					noise = "DeerRoarNoise";
					id = 9;
				};
				class HogGrunt_H
				{
					soundSet = "HogGrunt_H_SoundSet";
					noise = "DeerRoarNoise";
					id = 10;
				};
				class HogGrunt_I
				{
					soundSet = "HogGrunt_I_SoundSet";
					noise = "DeerRoarNoise";
					id = 11;
				};
				class HogSniff
				{
					soundSet = "HogSniff_SoundSet";
					noise = "DeerRoarNoise";
					id = 12;
				};
				class HogSqueal
				{
					soundSet = "HogSqueal_SoundSet";
					noise = "DeerRoarNoise";
					id = 13;
				};
				class HogScratch3
				{
					soundSet = "HogSscratch3_SoundSet";
					noise = "DeerRoarNoise";
					id = 14;
				};
				class HogScratch4
				{
					soundSet = "HogSscratch4_SoundSet";
					noise = "DeerRoarNoise";
					id = 15;
				};
				class HogClaw
				{
					soundSet = "HogClaw_SoundSet";
					noise = "DeerRoarNoise";
					id = 16;
				};
				class HogGrowl1
				{
					soundSet = "HogGrowl1_SoundSet";
					noise = "DeerRoarNoise";
					id = 17;
				};
				class HogGrowl2
				{
					soundSet = "HogGrowl2_SoundSet";
					noise = "DeerRoarNoise";
					id = 18;
				};
				class HogGrowl3
				{
					soundSet = "HogGrowl3_SoundSet";
					noise = "DeerRoarNoise";
					id = 19;
				};
				class HogGrowl4
				{
					soundSet = "HogGrowl4_SoundSet";
					noise = "DeerRoarNoise";
					id = 20;
				};
				class HogGrowl5
				{
					soundSet = "HogGrowl5_SoundSet";
					noise = "DeerRoarNoise";
					id = 21;
				};
			};
			class Damages
			{
				class Bite
				{
					damage = "DeerBiteDamage";
					id = 1;
				};
			};
		};
	};
};
