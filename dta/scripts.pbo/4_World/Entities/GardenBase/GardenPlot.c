class GardenPlot extends GardenBase
{
	Object 	m_ClutterCutter;
	const string COMPATIBLE_SURFACES[] = {"cp_dirt", "cp_broadleaf_dense1", "cp_broadleaf_dense2", "cp_broadleaf_sparse1", "cp_broadleaf_sparse2", "cp_conifer_common1", "cp_conifer_common2", "cp_conifer_moss1", "cp_conifer_moss2", "cp_grass", "cp_grass_tall", "cp_gravel", "cp_rock", "textile_carpet_int"};
	static const int COMPATIBLE_SURFACES_COUNT = 14; // Count if elements of COMPATIBLE_SURFACES array
	
	void GardenPlot()
	{
		SetBaseFertility(0.75);
	}
	
	override void EEInit()
	{	
		super.EEInit();
	}	
	
	override void OnStoreLoad( ParamsReadContext ctx )
	{				
		if ( !m_ClutterCutter )
		{		
			m_ClutterCutter = GetGame().CreateObject( "ClutterCutter6x6", GetPosition(), false );
			m_ClutterCutter.SetOrientation( GetOrientation() );
		}
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if (m_ClutterCutter  &&  GetGame())
		{
			GetGame().ObjectDelete(m_ClutterCutter);
			m_ClutterCutter = NULL;
		}
	}

	override int GetGardenSlotsCount()
	{
		return 9;
	}

	void RefreshSlots()
	{
		HideSelection("slotDigged_01");
		HideSelection("slotDigged_02");
		HideSelection("slotDigged_03");
		HideSelection("slotDigged_04");
		HideSelection("slotDigged_05");
		HideSelection("slotDigged_06");
		HideSelection("slotDigged_07");
		HideSelection("slotDigged_08");
		HideSelection("slotDigged_09");
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementStarted( Man player )
	{
		RefreshSlots();
	}
	
	override void OnHologramBeingPlaced( Man player )
	{
		RefreshSlots();
	}
	
	override void OnPlacementComplete( Man player )
	{				
		super.OnPlacementComplete( player );
				
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
			
		if ( GetGame().IsMultiplayer()  &&  GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			// To properly move the clutter cutter from spawn position, it must be deleted and created again.
			if (m_ClutterCutter)
			{
				GetGame().ObjectDelete(m_ClutterCutter);
				m_ClutterCutter = NULL;
			}
			
			if (!m_ClutterCutter)
			{		
				m_ClutterCutter = GetGame().CreateObject( "ClutterCutter6x6", GetPosition(), false );
				m_ClutterCutter.SetOrientation( orientation );
			}
		}
	}
	
	override bool CanBePlaced( Man player, vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType( position[0], position[2], surface_type );
		
		for (int i=0; i < COMPATIBLE_SURFACES_COUNT; i++)
		{
			if (COMPATIBLE_SURFACES[i] == surface_type)
			{
				return true;
			}
		}
		
		return false;
	}
}