////////////////////////////////////////////////////////////////////
//DeRap: plants\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 20 16:33:36 2019 : 'file' last modified on Wed Jul 24 10:01:38 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class DZ_Plants
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
	class ChristmasTree: HouseNoDestruct
	{
		model = "DZ\plants\tree\t_PiceaAbies_2s_xmas.p3d";
	};
};
class CfgNonAIVehicles
{
	class BushHard;
	class BushHard_b_betulaHumilis_1s: BushHard{};
	class BushHard_b_corylusAvellana_1f: BushHard{};
	class BushHard_b_corylusAvellana_2s: BushHard{};
	class BushHard_b_crataegusLaevigata_1s: BushHard{};
	class BushHard_b_crataegusLaevigata_2s: BushHard{};
	class BushHard_b_naked_2s: BushHard{};
	class BushHard_b_prunusSpinosa_1s: BushHard{};
	class BushHard_b_prunusSpinosa_2s: BushHard{};
	class BushHard_b_rosaCanina_1s: BushHard{};
	class BushHard_b_rosaCanina_2s: BushHard{};
	class BushHard_b_sambucusNigra_1s: BushHard{};
	class BushHard_b_sambucusNigra_2s: BushHard{};
	class BushHard_t_BetulaPendula_2w: BushHard{};
	class TreeSoft;
	class TreeHard;
	class TreeHard_t_BetulaPendula_1f: TreeHard{};
	class TreeHard_t_BetulaPendula_1fb: TreeHard{};
	class TreeHard_t_BetulaPendula_1s: TreeHard{};
	class TreeHard_t_BetulaPendula_2f: TreeHard{};
	class TreeHard_t_BetulaPendula_2fb: TreeHard{};
	class TreeHard_t_BetulaPendula_2fc: TreeHard{};
	class TreeHard_t_BetulaPendula_2s: TreeHard{};
	class TreeHard_t_BetulaPendula_3f: TreeHard{};
	class TreeHard_t_BetulaPendula_3fb: TreeHard{};
	class TreeHard_t_BetulaPendula_3fc: TreeHard{};
	class TreeHard_t_BetulaPendula_3s: TreeHard{};
};
