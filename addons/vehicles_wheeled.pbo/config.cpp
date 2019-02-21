////////////////////////////////////////////////////////////////////
//DeRap: vehicles_wheeled\config.bin
//Produced from mikero's Dos Tools Dll version 7.03
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Thu Feb 21 08:59:30 2019 : 'file' last modified on Mon Feb 04 12:34:33 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

//(12 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxisy = 2,
	destructno = 0,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class DZ_Vehicles_Wheeled
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CarWheel: Inventory_Base
	{
		InteractActions[] = {573};
		SingleUseActions[] = {577};
		simulation = "carwheel";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
	class CarDoor: Inventory_Base
	{
		scope = 1;
		InteractActions[] = {1043,1042,573};
		SingleUseActions[] = {548};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Window
				{
					class Health
					{
						hitpoints = 50;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{""}}};
					};
					componentNames[] = {"dmgZone_window"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Doors
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{""}}};
					};
					componentNames[] = {"dmgZone_doors"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
	};
	class Car;
	class CarScript: Car
	{
		InteractActions[] = {1047,1035};
		rotationFlags = 64;
		storageCategory = 4;
		insideSoundCoef = 0.9;
		fuelCapacity = 50;
		brakeFluidCapacity = 1;
		oilCapacity = 4;
		coolantCapacity = 6;
		brakeFluidLeakDebit[] = {0.0,0.0};
		oilLeakDebit[] = {0.0,0.0};
		coolantLeakDebit[] = {0.0,0.0};
		brakeFluidForceCoef[] = {0.0,1.0,1.0,1.0};
		damageFromOil[] = {0.0,0.0,1.0,0.0};
		damageFromCoolant[] = {0.0,0.0,1.0,0.0};
		engineBeltSlot = "EngineBelt";
		batterySlot = "CarBattery";
		electricPowerResName = "power";
		electricConsumptionIgnition = 3001;
		electricConsumptionEngine = 0.0;
		electricConsumptionLights = 0.0;
		electricOutputEngine = 5.0;
		selectionDashboard = "light_dashboard";
		selectionLightFrontL = "light_left";
		selectionLightFrontR = "light_right";
		selectionBrakeLights = "light_break";
		class Crew
		{
			class Driver
			{
				actionSel = "seat_driver";
				proxyPos = "crewDriver";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
				isDriver = 1;
			};
			class CoDriver
			{
				actionSel = "seat_coDriver";
				proxyPos = "crewCoDriver";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
		};
		class SimulationModule
		{
			class Axles
			{
				class Front
				{
					class Wheels
					{
						class Left
						{
							inventorySlot = "";
							animTurn = "turnfrontleft";
							animRotation = "wheelfrontleft";
							animDamper = "damperfrontleft";
							wheelHub = "wheel_1_1_damper_land";
						};
						class Right
						{
							inventorySlot = "";
							animTurn = "turnfrontright";
							animRotation = "wheelfrontright";
							animDamper = "damperfrontright";
							wheelHub = "wheel_2_1_damper_land";
						};
					};
				};
				class Rear
				{
					class Wheels
					{
						class Left
						{
							inventorySlot = "";
							animTurn = "turnbackleft";
							animRotation = "wheelbackleft";
							animDamper = "damperbackleft";
							wheelHub = "wheel_1_2_damper_land";
						};
						class Right
						{
							inventorySlot = "";
							animTurn = "turnbacktright";
							animRotation = "wheelbackright";
							animDamper = "damperbackright";
							wheelHub = "wheel_2_2_damper_land";
						};
					};
				};
			};
		};
		attachments[] = {"CarBattery","LightBulb","SparkPlug","V3SWheel_1_1","V3SWheel_2_1"};
		engineVitalParts[] = {"SparkPlug","CarBattery"};
		electricalVitalParts[] = {"CarBattery","HeadlightH7"};
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
		class ViewPilot
		{
			initFov = 0.769;
			minFov = 0.4143;
			maxFov = 1.192;
			initFovEXT = 0.73;
			minFovEXT = 0.4143;
			maxFovEXT = 0.95;
			initAngleX = 0;
			minAngleX = -85;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		class AnimationSources
		{
			class DoorsDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCoDriver: DoorsDriver{};
			class DoorsHood: DoorsDriver{};
			class DoorsTrunk: DoorsDriver{};
			class HideDestroyed_1_1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class HideDestroyed_1_2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class HideDestroyed_2_1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class HideDestroyed_2_2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class AnimHitWheel_1_1
			{
				source = "Hit";
				hitpoint = "HitWheel_1_1";
				raw = 1;
			};
			class AnimHitWheel_1_2: AnimHitWheel_1_1
			{
				hitpoint = "HitWheel_1_2";
			};
			class AnimHitWheel_2_1: AnimHitWheel_1_1
			{
				hitpoint = "HitWheel_2_1";
			};
			class AnimHitWheel_2_2: AnimHitWheel_1_1
			{
				hitpoint = "HitWheel_2_2";
			};
			class HitDoorsHood: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsHood";
			};
			class HitDoorsTrunk: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsTrunk";
			};
			class HitDoorsDrivers: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsDriver";
			};
			class HitDoorsCoDrivers: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsCoDriver";
			};
			class HitDoorsCargo: AnimHitWheel_1_1
			{
				hitpoint = "HitDoorsCargo";
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust_start";
				direction = "exhaust_end";
				effect = "ExhaustsEffect";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[] = {1.0,0.8,0.6,1.0};
				brightness = 30.0;
				radius = 70;
				angle = 120;
				angleInnerRatio = 0.25;
				dayLight = 1;
				flareAngleBias = 40.0;
				position = "light_left";
				direction = "light_left_dir";
				hitpoint = "dmgZone_lights";
				selection = "dmgZone_lights";
			};
			class Right: Left
			{
				position = "light_right";
				direction = "light_right_dir";
				hitpoint = "dmgZone_lights";
				selection = "dmgZone_light";
			};
		};
	};
	class HatchbackWheel: CarWheel
	{
		scope = 2;
		displayName = "$STR_HatchbackWheel0";
		descriptionShort = "$STR_hatchbackwheel1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel.p3d";
		weight = 15000;
		itemSize[] = {6,6};
		itemBehaviour = 0;
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
		rotationFlags = 4;
		physLayer = "item_large";
		radiusByDamage[] = {0,0.362,0.3,0.3,0.9998,0.25,0.9999,0.2};
		radius = 0.35;
		width = 0.18;
		tyreRollResistance = 0.015;
		tyreTread = 0.7;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel.rvmat"}},{0.7,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel.rvmat"}},{0.5,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_damage.rvmat"}},{0.3,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_damage.rvmat"}},{0.0,{"DZ\vehicles\wheeled\OffroadHatchback\data\niva_wheel_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackWheel_Ruined: CarWheel
	{
		scope = 2;
		displayName = "$STR_HatchbackWheel0";
		descriptionShort = "$STR_hatchbackwheel1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel_destroyed.p3d";
		weight = 10000;
		itemSize[] = {6,6};
		itemBehaviour = 0;
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
		rotationFlags = 4;
		physLayer = "item_large";
		radius = 0.2;
		width = 0.17;
		tyreRollResistance = 1;
		tyreTread = 0.5;
	};
	class HatchbackDoors_Driver: CarDoor
	{
		scope = 2;
		displayName = "$STR_HatchbackDoors_Driver0";
		descriptionShort = "$STR_HatchbackDoors_Driver1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Driver.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "NivaDriverDoors";
		rotationFlags = 8;
		physLayer = "item_large";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth{};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_door.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_door_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_door_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class HatchbackDoors_CoDriver: HatchbackDoors_Driver
	{
		displayName = "$STR_HatchbackDoors_CoDriver0";
		descriptionShort = "$STR_HatchbackDoors_CoDriver1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_coDriver.p3d";
		itemBehaviour = 0;
		inventorySlot = "NivaCoDriverDoors";
		rotationFlags = 4;
	};
	class HatchbackHood: CarDoor
	{
		scope = 2;
		displayName = "$STR_HatchbackHood0";
		descriptionShort = "$STR_HatchbackHood1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Hood.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "NivaHood";
		rotationFlags = 2;
		physLayer = "item_large";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_hood.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_hood_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_hood_destruct.rvmat"}}};
				};
			};
		};
	};
	class HatchbackTrunk: CarDoor
	{
		scope = 2;
		displayName = "$STR_HatchbackTrunk0";
		descriptionShort = "$STR_HatchbackTrunk1";
		model = "\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Trunk.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "NivaTrunk";
		rotationFlags = 1;
		physLayer = "item_large";
		class DamageSystem: DamageSystem
		{
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_backdoor.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_backdoor_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_backdoor_destruct.rvmat"}}};
					};
				};
			};
		};
	};
	class OffroadHatchback: CarScript
	{
		scope = 2;
		displayName = "$STR_OffroadHatchback0";
		descriptionShort = "$STR_OffroadHatchback1";
		model = "\dz\vehicles\wheeled\OffroadHatchback\OffroadHatchback.p3d";
		InteractActions[] = {1048,1035};
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","SparkPlug","NivaDriverDoors","NivaCoDriverDoors","NivaHood","NivaTrunk","NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
		dashboardMatOn = "dz\vehicles\wheeled\offroadhatchback\data\niva_dashboard_light.rvmat";
		dashboardMatOff = "dz\vehicles\wheeled\offroadhatchback\data\niva_dashboard.rvmat";
		frontReflectorMatOn = "dz\vehicles\wheeled\offroadhatchback\data\niva_lights.rvmat";
		frontReflectorMatOff = "dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat";
		fuelCapacity = 42;
		fuelConsumption = 11;
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			drive = "DRIVE_AWD";
			airDragCoefficient = 0.995;
			class Steering
			{
				increaseSpeed[] = {0,45,60,23,100,12};
				decreaseSpeed[] = {0,80,60,40,90,20};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 1.0;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4.0;
				gentleCoef = 0.75;
			};
			class Engine
			{
				inertia = 0.15;
				torqueMax = 114;
				torqueRpm = 3400;
				powerMax = 53.7;
				powerRpm = 5400;
				rpmIdle = 850;
				rpmMin = 900;
				rpmClutch = 1350;
				rpmRedline = 6000;
				rpmMax = 8000;
			};
			class Gearbox
			{
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
				timeToUncoupleClutch = 0.3;
				timeToCoupleClutch = 0.45;
				maxClutchTorque = 260;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle = 30;
					finalRatio = 4.1;
					brakeBias = 0.6;
					brakeForce = 4000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1700;
						stiffness = 40000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_1";
							inventorySlot = "NivaWheel_1_1";
						};
						class Right: Right
						{
							animDamper = "damper_2_1";
							inventorySlot = "NivaWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle = 0;
					finalRatio = 4.1;
					brakeBias = 0.4;
					brakeForce = 3800;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 1800;
						stiffness = 40000;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper = "damper_1_2";
							inventorySlot = "NivaWheel_1_2";
						};
						class Right: Right
						{
							animDamper = "damper_2_2";
							inventorySlot = "NivaWheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,30};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources: AnimationSources
		{
			class SeatDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.8;
			};
			class SeatCoDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.8;
			};
			class damper_1_1
			{
				source = "user";
				initPhase = 0.4857;
				animPeriod = 1;
			};
			class damper_2_1: damper_1_1{};
			class damper_1_2
			{
				source = "user";
				initPhase = 0.4002;
				animPeriod = 1;
			};
			class damper_2_2: damper_1_2{};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 1;
					};
					componentNames[] = {"dmgZone_chassis"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Front
				{
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Fender_1_1","Fender_2_1","Engine","Reflector_1_1","Reflector_2_1","WindowFront"};
					transferToZonesThreshold[] = {0.5,0.8,0.8,0.5,1.0,1.0,0.1};
					transferToZonesCoefs[] = {0.8,0.6,0.6,0.6,0.05,0.05,0.7};
					memoryPoints[] = {"dmgZone_front"};
					componentNames[] = {"dmgZone_front"};
					fatalInjuryCoef = -1;
					inventorySlotsCoefs[] = {0.3,0.3};
					inventorySlots[] = {"NivaHood","CarRadiator"};
				};
				class Reflector_1_1
				{
					class Health
					{
						hitpoints = 10;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\headlights_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\glass_i_damage.rvmat"}},{0.3,{}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\glass_i_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Front","Fender_1_1","Engine"};
					transferToZonesCoefs[] = {1.0,1.0,1.0};
					memoryPoints[] = {"dmgZone_lights_1_1"};
					componentNames[] = {"dmgZone_lights_1_1"};
					fatalInjuryCoef = -1;
					inventorySlotsCoefs[] = {1.0,0.3,0.3};
					inventorySlots[] = {"Reflector_1_1","NivaHood","CarRadiator"};
				};
				class Reflector_2_1: Reflector_1_1
				{
					transferToZonesNames[] = {"Front","Fender_2_1","Engine"};
					transferToZonesCoefs[] = {1.0,1.0,1.0};
					memoryPoints[] = {"dmgZone_lights_2_1"};
					componentNames[] = {"dmgZone_lights_2_1"};
					inventorySlotsCoefs[] = {1.0,0.3,0.3};
					inventorySlots[] = {"Reflector_1_1","NivaHood","CarRadiator"};
				};
				class Back
				{
					class Health
					{
						hitpoints = 1500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Fender_1_2","Fender_2_2","WindowLR","WindowRR"};
					transferToZonesCoefs[] = {0.3,0.3,0.2,0.2};
					memoryPoints[] = {"dmgZone_back"};
					componentNames[] = {"dmgZone_back"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"NivaTrunk"};
				};
				class Roof
				{
					class Health
					{
						hitpoints = 700;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_destruct.rvmat"}}};
					};
					memoryPoints[] = {"dmgZone_roof"};
					componentNames[] = {"dmgZone_roof"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Fender_1_1
				{
					class Health
					{
						hitpoints = 1200;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_destruct.rvmat"}}};
					};
					transferToZonesNames[] = {"Front","Engine","Reflector_1_1","WindowFront"};
					transferToZonesThreshold[] = {0.2,0.5,0.9,0.5};
					transferToZonesCoefs[] = {0.3,0.6,0.6,0.4};
					memoryPoints[] = {"dmgZone_fender_1_1"};
					componentNames[] = {"dmgZone_fender_1_1"};
					fatalInjuryCoef = -1;
					inventorySlotsCoefs[] = {0.3,0.3,0.3};
					inventorySlots[] = {"NivaHood","NivaWheel_1_1","NivaDriverDoors"};
				};
				class Fender_1_2: Fender_1_1
				{
					transferToZonesNames[] = {"Back","FuelTank","WindowLR"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					memoryPoints[] = {"dmgZone_fender_1_2"};
					componentNames[] = {"dmgZone_fender_1_2"};
					inventorySlotsCoefs[] = {0.3,0.1};
					inventorySlots[] = {"NivaTrunk","NivaWheel_1_2"};
				};
				class Fender_2_1: Fender_1_1
				{
					transferToZonesNames[] = {"Front","Engine","Reflector_1_1","WindowFront","Battery"};
					transferToZonesThreshold[] = {0.2,0.5,0.9,0.5,0.5};
					transferToZonesCoefs[] = {0.3,0.6,0.6,0.4,0.7};
					memoryPoints[] = {"dmgZone_fender_2_1"};
					componentNames[] = {"dmgZone_fender_2_1"};
					inventorySlotsCoefs[] = {0.3,0.2,31};
					inventorySlots[] = {"NivaHood","NivaWheel_2_1","NivaDriverDoors"};
				};
				class Fender_2_2: Fender_1_1
				{
					transferToZonesNames[] = {"Back","FuelTank","WindowRR"};
					transferToZonesThreshold[] = {0.2,0.2,0.2};
					transferToZonesCoefs[] = {0.3,0.2,0.7};
					memoryPoints[] = {"dmgZone_fender_2_2"};
					componentNames[] = {"dmgZone_fender_2_2"};
					inventorySlotsCoefs[] = {0.3,0.1};
					inventorySlots[] = {"NivaTrunk","NivaWheel_2_2"};
				};
				class WindowFront
				{
					class Health
					{
						hitpoints = 150;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
					memoryPoints[] = {"dmgZone_windowFront"};
					proxyNames[] = {"proxy:\dz\vehicles\wheeled\offroadhatchback\proxy\nivawindow_front"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class WindowLR
				{
					class Health
					{
						hitpoints = 150;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"}},{0.7,{}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"}},{0.0,"hidden"}};
					};
					memoryPoints[] = {"dmgZone_windowLeft"};
					proxyNames[] = {"proxy:\dz\vehicles\wheeled\offroadhatchback\proxy\nivawindow_backl"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class WindowRR: WindowLR
				{
					memoryPoints[] = {"dmgZone_windowRight"};
					proxyNames[] = {"proxy:\dz\vehicles\wheeled\offroadhatchback\proxy\nivawindow_backr"};
				};
				class Engine
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1.0,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"}},{0.7,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva.rvmat"}},{0.5,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"}},{0.3,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_damage.rvmat"}},{0.0,{"dz\vehicles\wheeled\offroadhatchback\data\engine_niva_destruct.rvmat"}}};
					};
					memoryPoints[] = {"dmgZone_engine"};
					componentNames[] = {"dmgZone_engine"};
					fatalInjuryCoef = 0.001;
					inventorySlotsCoefs[] = {0.2,0.2,0.01,0.4};
					inventorySlots[] = {"CarBattery","SparkPlug","EngineBelt","CarRadiator"};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
					};
					componentNames[] = {"dmgZone_fuelTank"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5.0;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,0.7};
					};
					class Cyl3
					{
						radius = 1.0;
						height = 1.5;
						center[] = {0,0,-0.7};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","NivaHood","NivaTrunk","NivaDriverDoors","NivaCoDriverDoors","NivaWheel_Spare_1"};
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2"};
			};
		};
	};
};
class CfgDestroy
{
	class EngineHit
	{
		sound[] = {};
	};
};
class CfgNonAIVehicles
{
	class ProxyFlag;
	class ProxyDriver;
	class ProxyCargo;
	class ProxyAttachment;
	class ProxyFlag_Auto: ProxyFlag{};
	class ProxyFlag_Alone: ProxyFlag{};
	class ProxyV3S_Driver: ProxyDriver{};
	class ProxyV3S_CargoA: ProxyCargo{};
	class ProxyCivilianSedan_Driver: ProxyDriver{};
	class ProxyCivilianSedan_Cargo: ProxyCargo{};
	class ProxyBus_Driver: ProxyDriver{};
	class ProxyBus_Cargo: ProxyCargo{};
	class ProxyHatchback_Cargo: ProxyCargo{};
	class ProxyEnduro_Driver: ProxyDriver{};
	class ProxyEnduro_Cargo: ProxyCargo{};
	class ProxyVehiclePart: ProxyAttachment
	{
		scope = 2;
		simulation = "ProxyInventory";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 0;
	};
	class ProxyNivaWheel: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel.p3d";
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
	};
	class ProxyNivaWheel_destroyed: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaWheel_destroyed.p3d";
		inventorySlot[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","NivaWheel_Spare_1"};
	};
	class ProxyNivaDoors_Hood: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Hood.p3d";
		inventorySlot = "NivaHood";
	};
	class ProxyNivaDoors_Trunk: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Trunk.p3d";
		inventorySlot = "NivaTrunk";
	};
	class ProxynivaDoors_Driver: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_Driver.p3d";
		inventorySlot = "NivaDriverDoors";
	};
	class ProxynivaDoors_coDriver: ProxyVehiclePart
	{
		model = "DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_coDriver.p3d";
		inventorySlot = "NivaCoDriverDoors";
	};
};
