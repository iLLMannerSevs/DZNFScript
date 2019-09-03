////////////////////////////////////////////////////////////////////
//DeRap: weapons_shotguns\Izh43\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Sep 03 15:36:46 2019 : 'file' last modified on Mon Aug 12 12:21:44 2019
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
	class DZ_Weapons_Shotguns_Izh43
	{
		units[] = {"ShotgunIzh43","ShotgunIzh43_Sawedoff"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Weapons"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class Muzzle_Base;
class OpticsInfoShotgun;
class cfgWeapons
{
	class Shotgun_Base;
	class Izh43Shotgun_Base: Shotgun_Base
	{
		scope = 0;
		lootTag[] = {"Civilian","Hunting"};
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_12gaPellets","Ammo_12gaSlug","Mag_12gaSnaploader_2Rnd"};
		magazines[] = {};
		ejectType = 3;
		reloadSkips[] = {0.48,0.81};
		drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.005623413,1};
		reloadMagazineSound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_reloading",1.0,1,20};
		reloadSound[] = {};
		soundBullet[] = {};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke";
					muzzleIndex = 0;
				};
				class SmokeCloud2
				{
					overrideParticle = "weapon_shot_winded_smoke";
					muzzleIndex = 0;
				};
				class SmokeCloud3BadlyDamaged
				{
					overrideParticle = "weapon_shot_winded_smoke";
					onlyWithinHealthLabel[] = {3,4};
					muzzleIndex = 0;
				};
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_mp133_01";
					illuminateWorld = 1;
					muzzleIndex = 0;
				};
				class BadlyDamagedChamberSmoke
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart";
					overrideDirectionPoint = "Nabojniceend";
					onlyWithinHealthLabel[] = {3,4};
					muzzleIndex = 0;
				};
				class BadlyDamagedChamberSmokeRaise
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart";
					onlyWithinHealthLabel[] = {3,4};
					muzzleIndex = 0;
				};
				class SmokeCloud_2
				{
					overrideParticle = "weapon_shot_winded_smoke";
					overridePoint = "Usti hlavne_2";
					muzzleIndex = 1;
				};
				class SmokeCloud2_2
				{
					overrideParticle = "weapon_shot_winded_smoke";
					overridePoint = "Usti hlavne_2";
					muzzleIndex = 1;
				};
				class SmokeCloud3BadlyDamaged_2
				{
					overrideParticle = "weapon_shot_winded_smoke";
					overridePoint = "Usti hlavne_2";
					onlyWithinHealthLabel[] = {3,4};
					muzzleIndex = 1;
				};
				class MuzzleFlash_2
				{
					overrideParticle = "weapon_shot_mp133_01";
					overridePoint = "Usti hlavne_2";
					illuminateWorld = 1;
					muzzleIndex = 1;
				};
				class BadlyDamagedChamberSmoke_2
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart_2";
					overrideDirectionPoint = "Nabojniceend";
					onlyWithinHealthLabel[] = {3,4};
					muzzleIndex = 1;
				};
				class BadlyDamagedChamberSmokeRaise_2
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart_2";
					onlyWithinHealthLabel[] = {3,4};
					muzzleIndex = 1;
				};
			};
			class OnOverheating
			{
				maxOverheatingValue = 4;
				shotsToStartOverheating = 1;
				overheatingDecayInterval = 3;
				class SmokingBarrel
				{
					overrideParticle = "smoking_barrel_small";
				};
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen = 1;
					overrideParticle = "smoking_barrel_small";
					overridePoint = "Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart";
				};
			};
		};
		muzzles[] = {"this","SecondMuzzle"};
		reloadAction = "ReloadShotgunIZH43";
		shotAction = "";
		hiddenSelections[] = {"camo"};
		simpleHiddenSelections[] = {"bullet","bullet2"};
		modes[] = {"Single","Burst"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"IZH43_Shot_SoundSet","IZH43_Tail_SoundSet","IZH43_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_0",1,1,800};
			begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_1",1,1,800};
			begin3[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_2",1,1,800};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			reloadTime = 1;
			recoil = "recoil_doublebarrel";
			recoilProne = "recoil_doublebarrel_prone";
			dispersion = 0.01;
			firespreadangle = 1.5;
			magazineSlot = "magazine";
		};
		class Burst: Mode_Burst
		{
			soundSetShot[] = {"IZH43double_Shot_SoundSet","IZH43_Tail_SoundSet","IZH43_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43double_close_0",1,1,900};
			begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43double_close_1",1,1,900};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.01;
			recoil = "recoil_doublebarrel_double";
			recoilProne = "recoil_doublebarrel";
			dispersion = 0.01;
			magazineSlot = "magazine";
			firespreadangle = 1.5;
		};
		class OpticsInfo: OpticsInfoShotgun{};
		class SecondMuzzle: Muzzle_Base
		{
			chamberSize = 1;
			muzzlePos = "usti hlavne_2";
			muzzleEnd = "konec hlavne_2";
			cartridgePos = "nabojnicestart_2";
			cartridgeVel = "nabojniceend_2";
			modes[] = {"Single","Burst"};
			magazines[] = {};
			chamberableFrom[] = {"Ammo_12gaPellets","Ammo_12gaSlug","Mag_12gaSnaploader_2Rnd"};
			barrelArmor = 1000.0;
			initSpeedMultiplier = 1.0;
			irDistance = 0.0;
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.005623413,1};
			soundBullet[] = {};
			class Single: Mode_SemiAuto
			{
				soundSetShot[] = {"IZH43_Shot_SoundSet","IZH43_Tail_SoundSet","IZH43_InteriorTail_SoundSet"};
				begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_0",1,1,800};
				begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_1",1,1,800};
				begin3[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_2",1,1,800};
				soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
				reloadTime = 1;
				recoil = "recoil_doublebarrel";
				recoilProne = "recoil_doublebarrel_prone";
				dispersion = 0.01;
				firespreadangle = 1.5;
				magazineSlot = "magazine";
			};
			class Burst: Mode_Burst
			{
				soundSetShot[] = {"IZH43double_Shot_SoundSet","IZH43_Tail_SoundSet","IZH43_InteriorTail_SoundSet"};
				begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43double_close_0",1,1,900};
				begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43double_close_1",1,1,900};
				soundBegin[] = {"begin1",0.5,"begin2",0.5};
				reloadTime = 0.01;
				recoil = "recoil_doublebarrel_double";
				recoilProne = "recoil_doublebarrel";
				dispersion = 0.01;
				magazineSlot = "magazine";
				firespreadangle = 1.5;
			};
		};
	};
	class Izh43Shotgun: Izh43Shotgun_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Izh43Shotgun0";
		descriptionShort = "$STR_cfgWeapons_Izh43Shotgun1";
		model = "\dz\weapons\shotguns\Izh43\izh43.p3d";
		attachments[] = {"weaponWrap"};
		itemSize[] = {9,6};
		recoilModifier[] = {1,1,1};
		hiddenSelectionsTextures[] = {"dz\weapons\shotguns\Izh43\data\izh43_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\shotguns\Izh43\data\izh43.rvmat"};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\shotguns\Izh43\data\izh43.rvmat","DZ\weapons\shotguns\Izh43\data\izh43_damage.rvmat","DZ\weapons\shotguns\Izh43\data\izh43_destruct.rvmat"};
		};
	};
	class SawedoffIzh43Shotgun: Izh43Shotgun_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_SawedoffIzh43Shotgun0";
		descriptionShort = "$STR_cfgWeapons_SawedoffIzh43Shotgun1";
		model = "\dz\weapons\shotguns\Izh43\izh43_sawedoff.p3d";
		attachments[] = {"weaponWrap"};
		itemSize[] = {6,5};
		recoilModifier[] = {1,1,1};
		firespreadangle = 3;
		hiddenSelectionsTextures[] = {"dz\weapons\shotguns\Izh43\data\izh43_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\shotguns\Izh43\data\izh43.rvmat"};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\shotguns\Izh43\data\izh43.rvmat","DZ\weapons\shotguns\Izh43\data\izh43_damage.rvmat","DZ\weapons\shotguns\Izh43\data\izh43_destruct.rvmat"};
		};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"IZH43sawed_Shot_SoundSet","IZH43_Tail_SoundSet","IZH43_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_0",1.7782794,1,1000};
			begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_1",1.7782794,1,1000};
			begin3[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_2",1.7782794,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			dispersion = 0.02;
			firespreadangle = 1.5;
			recoil = "recoil_sawedoff";
			recoilProne = "recoil_sawedoff";
		};
		class Burst: Mode_Burst
		{
			soundSetShot[] = {"IZH43sawedDouble_Shot_SoundSet","IZH43_Tail_SoundSet","IZH43_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43double_close_0",3.1622777,1,1000};
			begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43double_close_1",3.1622777,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333};
			reloadTime = 0.01;
			recoil = "recoil_sawedoff_double";
			recoilProne = "recoil_sawedoff_double";
			dispersion = 0.02;
			magazineSlot = "magazine";
			firespreadangle = 1.5;
		};
	};
};
