class Epinephrine: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionInjectEpinephrineTarget);
		AddAction(ActionInjectEpinephrineSelf);
	}
	
	override void OnApply(PlayerBase player)
	{
		player.GiveShock(100);
		player.GetStaminaHandler().SetStamina(100);
	}
};
