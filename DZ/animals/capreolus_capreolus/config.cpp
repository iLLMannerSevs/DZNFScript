////////////////////////////////////////////////////////////////////
//DeRap: animals\capreolus_capreolus\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 22 23:14:56 2019 : 'file' last modified on Tue Aug 20 22:53:28 2019
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
	class DZ_Animals_capreolus_capreolus
	{
		units[] = {"Animal_CapreolusCapreolus"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Animals"};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Animal_CapreolusCapreolus: AnimalBase
	{
		simulation = "dayzanimal";
		scope = 2;
		model = "\DZ\animals\capreolus_capreolus\capreolus_capreolus.p3d";
		displayName = "$STR_CfgVehicles_Animal_CapreolusCapreolus0";
		descriptionShort = "$STR_CfgVehicles_Animal_CapreolusCapreolus1";
		aiAgentTemplate = "Herbivores_CapreolusCapreolus";
		injuryLevels[] = {1.0,0.5,0.2,0.0};
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
				item = "DeerSteakMeat";
				count = 10;
				quantityMinMaxCoef[] = {0.3,7};
			};
			class ObtainedPelt
			{
				item = "DeerPelt";
				count = 1;
				quantityCoef = 0.5;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.25,0.5};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.5};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
		};
		class enfanimsys
		{
			meshObject = "dz\animals\capreolus_capreolus\data\capreolus_capreolus_skeleton.xob";
			graphname = "dz\animals\animations\!graph_files\Herbivores\Herbivores_Graph.agr";
			defaultinstance = "dz\animals\animations\!graph_files\Herbivores\RoeDeerSkeleton_AnimInstance.asi";
			startnode = "MasterDeers_SM";
			skeletonName = "capreolus_capreolus_skeleton.xob";
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 8;
				};
				class Grazing1
				{
					soundLookupTable = "HoofMediumGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 9;
				};
				class Grazing2
				{
					soundLookupTable = "HoofMediumGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 10;
				};
				class Bodyfall
				{
					soundLookupTable = "HoofMediumBodyfall_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "HoofMediumSettle_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "HoofMediumRest2standA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "HoofMediumRest2standB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "HoofMediumStand2restA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "HoofMediumStand2restB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "HoofMediumStand2restC_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 17;
				};
				class Rub1
				{
					soundLookupTable = "HoofMediumRub1_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 18;
				};
				class Rub2
				{
					soundLookupTable = "HoofMediumRub2_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 19;
				};
			};
			class Sounds
			{
				class DeerBleat
				{
					soundSet = "DeerBleat_SoundSet";
					noise = "DeerRoarNoise";
					id = 1;
				};
				class DoeBleat
				{
					soundSet = "DoeBleat_SoundSet";
					noise = "DeerRoarNoise";
					id = 2;
				};
				class DeerBreath
				{
					soundSet = "DeerBreath_SoundSet";
					noise = "DeerRoarNoise";
					id = 3;
				};
				class DeerBark
				{
					soundSet = "DeerBark_SoundSet";
					noise = "DeerRoarNoise";
					id = 4;
				};
				class DoeBark
				{
					soundSet = "DoeBark_SoundSet";
					noise = "DeerRoarNoise";
					id = 5;
				};
				class RoeBark
				{
					soundSet = "RoeBark_SoundSet";
					noise = "DeerRoarNoise";
					id = 6;
				};
				class DeerCall
				{
					soundSet = "DeerCall_SoundSet";
					noise = "DeerRoarNoise";
					id = 7;
				};
				class DeerCallFear
				{
					soundSet = "DeerCallFear_SoundSet";
					noise = "DeerRoarNoise";
					id = 8;
				};
				class DeerGrunt
				{
					soundSet = "DeerGrunt_SoundSet";
					noise = "DeerRoarNoise";
					id = 9;
				};
				class DeerRoar
				{
					soundSet = "DeerRoar_SoundSet";
					noise = "DeerRoarNoise";
					id = 10;
				};
				class DeerRoarLong
				{
					soundSet = "DeerRoarLong_SoundSet";
					noise = "DeerRoarNoise";
					id = 11;
				};
				class DeerRoarShort
				{
					soundSet = "DeerRoarShort_SoundSet";
					noise = "DeerRoarNoise";
					id = 12;
				};
				class DeerSnort
				{
					soundSet = "DeerSnort_SoundSet";
					noise = "DeerRoarNoise";
					id = 13;
				};
				class RoeBarkX1
				{
					soundSet = "RoeBarkX1_SoundSet";
					noise = "DeerRoarNoise";
					id = 14;
				};
				class RoeBarkX1_Tail
				{
					soundSet = "RoeBarkX1_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 15;
				};
				class RoeBarkX2
				{
					soundSet = "RoeBarkX2_SoundSet";
					noise = "DeerRoarNoise";
					id = 16;
				};
				class RoeBarkX2_Tail
				{
					soundSet = "RoeBarkX2_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 17;
				};
				class RoeBarkX3
				{
					soundSet = "RoeBarkX3_SoundSet";
					noise = "DeerRoarNoise";
					id = 18;
				};
				class RoeBarkX3_Tail
				{
					soundSet = "RoeBarkX3_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 19;
				};
				class RoeBarkX4
				{
					soundSet = "RoeBarkX4_SoundSet";
					noise = "DeerRoarNoise";
					id = 20;
				};
				class RoeBarkX4_Tail
				{
					soundSet = "RoeBarkX4_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 21;
				};
				class RoeBarkX5
				{
					soundSet = "RoeBarkX5_SoundSet";
					noise = "DeerRoarNoise";
					id = 22;
				};
				class RoeBarkX5_Tail
				{
					soundSet = "RoeBarkX5_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 23;
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
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = {0.0,0.13,0.53,2.13,4.41,11.76};
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
};
