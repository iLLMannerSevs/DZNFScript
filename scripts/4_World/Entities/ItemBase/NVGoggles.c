class NVGoggles extends PoweredOptic_Base
{
	bool 		m_IsLowered;
	bool 		m_InitOnSpawn;
	ItemBase 	m_Strap;
	ref Timer 	m_WorkCheckTimer;
	
	void NVGoggles()
	{
		if (!m_InitOnSpawn)
		{
			m_InitOnSpawn = true;
		}
		m_WorkCheckTimer = new Timer;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionViewOptics);
		AddAction(ActionViewBinoculars);
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached( item, slot_name );
		
		if ( GetCompEM().CanWork() && m_IsLowered )
			m_WorkCheckTimer.Run(0.1,this,"SwitchOnNVGCheck",null,true);
			//GetCompEM().SwitchOn();
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached( item, slot_name );
		
		GetCompEM().SwitchOff();
	}
	
	override void OnWasAttached ( EntityAI parent, int slot_id )
	{
		super.OnWasAttached(parent, slot_id);
		RotateGoggles(true);
		
		m_Strap = ItemBase.Cast(parent);
	}
	
	override void OnWasDetached ( EntityAI parent, int slot_id )
	{
		super.OnWasDetached(parent, slot_id);
		RotateGoggles(true);
		
		m_Strap = null;
		
		PlayerBase player;
		if ( PlayerBase.CastTo(player, parent.GetHierarchyRootPlayer()) )
		{
			if ( parent && Clothing.Cast(parent) )
			{
				Clothing.Cast(parent).UpdateNVGStatus(player,false);
			}
		}
	}
	
	override void OnWorkStart()
	{
		PlayerBase player;
		EntityAI headgear;
		EntityAI glasses;
		if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) && m_Strap )
		{
			headgear = player.FindAttachmentBySlotName("Headgear");
			glasses = player.FindAttachmentBySlotName("Eyewear");
			if (headgear == m_Strap || glasses == m_Strap)
				player.SetNVGWorking(true);
		}
	}
	
	override void OnWorkStop()
	{
		PlayerBase player;
		if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) )
			player.SetNVGWorking(false);
	}
	
	override void OnWork( float consumed_energy )
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			PlayerBase player;
			if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) && !player.IsNVGWorking() )
			{
				player.SetNVGWorking(true);
			}
		}
	}
	
	void LoweredCheck() //check for animation state, if another player lowered them first (or solve by synced variable)
	{
		if ( GetAnimationPhase("rotate") != m_IsLowered )
		{
			m_IsLowered = GetAnimationPhase("rotate");
		}
	}
	
	void RotateGoggles(bool state)
	{
		//if ( GetAnimationPhase("rotate") != state ) //useless?
			SetAnimationPhase("rotate",!state);
		m_IsLowered = !state;
		
		if ( GetCompEM() )
		{
			if ( !state && GetCompEM().CanWork() )
				GetCompEM().SwitchOn();
			else
				GetCompEM().SwitchOff();
		}
	}
	
	void SwitchOnNVGCheck()
	{
		GetCompEM().SwitchOn();
		if (GetCompEM().IsSwitchedOn())
		{
			m_WorkCheckTimer.Stop();
		}
	}
	
	override bool IsNVG()
	{
		return true;
	}
}
