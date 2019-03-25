class ActionFillCoolantCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT = 0.075;

	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousFillCoolant( UAQuantityConsumed.FUEL, TIME_TO_REPEAT );
	}
};

class ActionFillCoolant: ActionContinuousBase
{
	const string RADIATOR_SELECTION_NAME = "radiator";

	void ActionFillCoolant()
	{
		m_CallbackClass = ActionFillCoolantCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_LockTargetOnUse = false;

	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTParent(10);
	}

	override int GetType()
	{
		return AT_FILL_COOLANT;
	}

	override string GetText()
	{
		return "#refill_car";
	}

	override bool IsUsingProxies()
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI tgt_parent = EntityAI.Cast( target.GetParent() );

		if( item.GetQuantity() <= 0 )
			return false;

		if( item.GetLiquidType() != LIQUID_WATER && item.GetLiquidType() != LIQUID_RIVERWATER )
			return false;

		Car car = Car.Cast(tgt_parent);
		if( car && car.GetFluidFraction( CarFluid.COOLANT ) >= 0.95 )
			return false;

		//! TODO:
		//! 1) use some sane default
		//! 2) create some getter(overriden per Car) to differentiate distances for each car type
		float max_action_distance = 3;

		float distance = Math.AbsFloat(vector.Distance(tgt_parent.GetPosition(), player.GetPosition()));

		if( distance <= max_action_distance )
		{
			array<string> selections = new array<string>;
			target.GetObject().GetActionComponentNameList(target.GetComponentIndex(), selections);

			for (int s = 0; s < selections.Count(); s++)
			{
				if ( selections[s] == RADIATOR_SELECTION_NAME )
				{
					return true;
				}
			}
		}

		return false;
	}
};