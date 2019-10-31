class FishingActionData : ActionData
{
	const float FISHING_SUCCESS 		= 0.2;
	const float FISHING_BAIT_LOSS 		= 0.05;
	const float FISHING_HOOK_LOSS 		= 0.015;
	const float FISHING_DAMAGE 			= 5.0;
	const float FISHING_GARBAGE_CHANCE 	= 0.2;
	
	bool 		m_IsSurfaceSea;
	int 		m_FishingResult = -1;
	float 		m_RodQualityModifier = 0;
	ItemBase 	m_Bait;
}

class ActionFishingNewCB : ActionContinuousBaseCB
{
	FishingActionData 	m_ActionDataFishing;
	ref array<string> 	m_JunkTypes = {"Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey"};
	
	override void CreateActionComponent()
	{
		EnableStateChangeCallback();
		m_ActionData.m_ActionComponent = new CAContinuousRepeatFishing(3.0);
	}
	
	override void EndActionComponent()
	{
		m_ActionDataFishing = FishingActionData.Cast(m_ActionData);
		
		if (!m_ActionDataFishing)
		{
			super.EndActionComponent();
			return;
		}
		
		if ( m_ActionDataFishing.m_State == UA_FINISHED )
		{
			if ( m_ActionDataFishing.m_FishingResult == 1 )
				SetCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
			else if ( m_ActionDataFishing.m_FishingResult == 0 )
				SetCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
		}
		else if (m_ActionDataFishing.m_State == UA_CANCEL )
		{
			ActionContinuousBase action = ActionContinuousBase.Cast(m_ActionDataFishing.m_Action);
			if(action.HasAlternativeInterrupt())
			{
				SetCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
			}
			else
			{
				SetCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
			}
			m_Canceled = true;
			return;
		}
		else
		{
			if ( m_ActionDataFishing.m_FishingResult == 1 )
				SetCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
			else if ( m_ActionDataFishing.m_FishingResult == 0 )
				SetCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
		}
		m_ActionDataFishing.m_State = UA_FINISHED;
	}
	
	void HandleFishingResultSuccess()
	{
		//Print("HandleFishingResultSuccess");
		if (!GetGame().IsMultiplayer() || GetGame().IsServer())
		{
			ItemBase fish;
			ItemBase hook;
			
			if (!m_ActionDataFishing.m_Bait)
				m_ActionDataFishing.m_Bait = ItemBase.Cast(m_ActionDataFishing.m_MainItem.FindAttachmentBySlotName("Bait"));
			
			hook = ItemBase.Cast(GetGame().CreateObject(m_ActionDataFishing.m_Bait.ConfigGetString("hookType"),m_ActionDataFishing.m_Player.GetPosition(), false));
			
			if (hook)
			{
				MiscGameplayFunctions.TransferItemProperties(m_ActionDataFishing.m_Bait,hook);
				hook.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
			}
			m_ActionDataFishing.m_Bait.Delete();
			
			float rnd = Math.RandomFloatInclusive(0.0,1.0);
			if (rnd > m_ActionDataFishing.FISHING_GARBAGE_CHANCE)
			{
				if (m_ActionDataFishing.m_IsSurfaceSea)
					fish = ItemBase.Cast(GetGame().CreateObject("Mackerel",m_ActionDataFishing.m_Player.GetPosition(), false));
				else
					fish = ItemBase.Cast(GetGame().CreateObject("Carp",m_ActionDataFishing.m_Player.GetPosition(), false));
			}
			else
			{
				string junk_type = m_JunkTypes.Get(Math.RandomInt(0,m_JunkTypes.Count()));
				fish = ItemBase.Cast(GetGame().CreateObject(junk_type,m_ActionDataFishing.m_Player.GetPosition(), false));
				fish.SetHealth("","Health",fish.GetMaxHealth("","Health") * 0.1);
			}
			
			if (fish)
				fish.SetWet(0.3);
			
			m_ActionDataFishing.m_MainItem.AddHealth(m_ActionDataFishing.FISHING_DAMAGE);
		}
	}
	
	void HandleFishingResultFailure()
	{
		//Print("HandleFishingResultFailure");
		if (!GetGame().IsMultiplayer() || GetGame().IsServer())
		{
			if (Math.RandomFloatInclusive(0.0,1.0) > m_ActionDataFishing.FISHING_HOOK_LOSS)
			{
				ItemBase hook;
				
				if (!m_ActionDataFishing.m_Bait)
					m_ActionDataFishing.m_Bait = ItemBase.Cast(m_ActionDataFishing.m_MainItem.FindAttachmentBySlotName("Bait"));
				
				hook = ItemBase.Cast(GetGame().CreateObject(m_ActionDataFishing.m_Bait.ConfigGetString("hookType"),m_ActionDataFishing.m_Player.GetPosition(), false));
				if (hook)
					MiscGameplayFunctions.TransferItemProperties(m_ActionDataFishing.m_Bait,hook);
			}
			m_ActionDataFishing.m_Bait.Delete();
			
			m_ActionDataFishing.m_MainItem.AddHealth(m_ActionDataFishing.FISHING_DAMAGE);
		}
	}
	
	override void OnStateChange(int pOldState, int pCurrentState)
	{
		if (pCurrentState == STATE_NONE && m_ActionDataFishing)
		{
			if (m_ActionDataFishing.m_FishingResult == 1 && pOldState == STATE_LOOP_END)
			{
				HandleFishingResultSuccess();
			}
			else if (m_ActionDataFishing.m_FishingResult == 0 && pOldState == STATE_LOOP_END2)
			{
				HandleFishingResultFailure();
			}
		}
	}
};

class ActionFishingNew: ActionContinuousBase
{
	void ActionFishingNew()
	{
		m_CallbackClass = ActionFishingNewCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_FISHING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool HasTarget()
	{
		return false;
	}
	
	override bool HasAlternativeInterrupt()
	{
		return true;
	}
	
	override string GetText()
	{
		return "#start_fishing";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase bait;
		
		FishingRod_Base_New rod = FishingRod_Base_New.Cast(item);
		
		if (rod)
		{
			bait = ItemBase.Cast(rod.FindAttachmentBySlotName("Bait"));
		}
		
		if (bait && !bait.IsRuined())
		{
			if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
				return true;
			
			vector pos_cursor = target.GetCursorHitPos();
			if (pos_cursor == vector.Zero)
				return false;
			
			if ( GetGame().SurfaceIsPond(pos_cursor[0],pos_cursor[2]) || GetGame().SurfaceIsSea(pos_cursor[0],pos_cursor[2]) )
				return true;
		}
		
		return false;
	}
	
	override ActionData CreateActionData()
	{
		FishingActionData action_data = new FishingActionData;
		return action_data;
	}
	
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data))
		{
			vector pos_cursor = action_data.m_Target.GetCursorHitPos();
			if (GetGame().SurfaceIsSea(pos_cursor[0],pos_cursor[2]))
			{
				FishingActionData.Cast(action_data).m_IsSurfaceSea = true;
			}
			FishingRod_Base_New rod = FishingRod_Base_New.Cast(action_data.m_MainItem);
			if (rod)
			{
				FishingActionData.Cast(action_data).m_RodQualityModifier = rod.GetFishingEffectivityBonus();
			}
			return true;
		}
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		action_data.m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_ACTION);
		FishingActionData.Cast(action_data).m_FishingResult = EvaluateFishingResult(action_data);
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		action_data.m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_ACTION);
		FishingActionData.Cast(action_data).m_FishingResult = EvaluateFishingResult(action_data);
	}
	
	override void OnStartClient( ActionData action_data )
	{
		FishingRod_Base_New rod = FishingRod_Base_New.Cast(action_data.m_MainItem);
		rod.AnimateFishingRod(true);
	}
	override void OnStartServer( ActionData action_data )
	{
		FishingRod_Base_New rod = FishingRod_Base_New.Cast(action_data.m_MainItem);
		rod.AnimateFishingRod(true);
	}
	
	override void OnEndClient( ActionData action_data )
	{
		FishingRod_Base_New rod = FishingRod_Base_New.Cast(action_data.m_MainItem);
		rod.AnimateFishingRod(false);
	}
	override void OnEndServer( ActionData action_data )
	{
		FishingRod_Base_New rod = FishingRod_Base_New.Cast(action_data.m_MainItem);
		rod.AnimateFishingRod(false);
	}
	
	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		
		if( HasTarget() )
		{
			ctx.Write(action_data.m_Target.GetCursorHitPos());
		}
	}
	
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{		
		super.ReadFromContext(ctx, action_recive_data);
		
		if( HasTarget() )
		{
			vector cursor_position;
			if ( !ctx.Read(cursor_position) )
				return false;
			action_recive_data.m_Target.SetCursorHitPos(cursor_position);
		}
		return true;
	}
	
	int EvaluateFishingResult(ActionData action_data)
	{
		FishingActionData fad = FishingActionData.Cast(action_data);
		float rnd = fad.m_Player.GetRandomGeneratorSyncManager().GetRandom01(RandomGeneratorSyncUsage.RGSGeneric);
		float daytime_modifier = 1;
		float chance;
		
		daytime_modifier = GetGame().GetDayTime();
		if ( (daytime_modifier > 18 && daytime_modifier < 22) || (daytime_modifier > 5 && daytime_modifier < 9) )
		{
			daytime_modifier = 1;
		}
		else
		{
			daytime_modifier = 0.5;
		}
		chance = 1 - ((fad.FISHING_SUCCESS * daytime_modifier) + fad.m_RodQualityModifier);
		
		if (rnd > chance)
		{	
			return 1;
		}
		else if (rnd < fad.FISHING_BAIT_LOSS)
		{
			return 0;
		}
		
		return -1;
	}
};