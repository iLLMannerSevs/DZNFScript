class ChernarusMap_Open extends ItemMap
{
	protected bool m_ItemChanged;
	
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{
		super.OnItemLocationChanged(old_owner,new_owner);
		
		PlayerBase player = PlayerBase.Cast(old_owner);
		if (player/* && !m_ItemChanged*/)
		{
			if (GetGame().IsServer())
			{
				MiscGameplayFunctions.TurnItemIntoItem(this, "ChernarusMap", player); //changes map on player death/drop
				//m_ItemChanged = true;
			}
			/*else if ((!GetGame().IsMultiplayer() || GetGame().IsClient()) && GetGame().GetUIManager().IsMenuOpen(MENU_MAP))
			{
				GetGame().GetUIManager().CloseMenu(MENU_MAP);
			}*/
		}
	}
	
	/*override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		
		MiscGameplayFunctions.TurnItemIntoItem(this, "ChernarusMap", player); //changes map on player death/drop
	}*/
}