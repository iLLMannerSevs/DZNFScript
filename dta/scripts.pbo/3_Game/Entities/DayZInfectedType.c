class DayZInfectedAttackType
{
	float m_Distance; // [m]
	int m_Pitch; // 1 = up, 0 = center, -1 = down
	int m_Type; // int argument for attack command
	float m_Subtype; // float argument for attack command
	string m_AmmoType; // ammotype from config
	int m_IsHeavy; // 0 - light attack; 1 - heavy attack;
	float m_Cooldown; // [s]
	float m_Probability; // [0..1]
};

enum DayZInfectedAttackGroupType
{
	CHASE,
	FIGHT
}

class DayZInfectedType extends DayZCreatureAIType
{
	//--------------------------------------------------------
	// Public
	//--------------------------------------------------------
	//! register hit components for AI melee (used by attacking AI)
	void RegisterHitComponentsForAI()
	{
		m_HitComponentsForAI = new array<ref DayZAIHitComponent>;

		//! registers default hit compoent for the entity
		m_DefaultHitComponent = "Torso";

		//! register hit components that are selected by probability
		DayZAIHitComponentHelpers.RegisterHitComponent(m_HitComponentsForAI, "Head", 2);
		DayZAIHitComponentHelpers.RegisterHitComponent(m_HitComponentsForAI, "LeftArm", 50);
		DayZAIHitComponentHelpers.RegisterHitComponent(m_HitComponentsForAI, "Torso", 65);
		DayZAIHitComponentHelpers.RegisterHitComponent(m_HitComponentsForAI, "RightArm", 50);
		DayZAIHitComponentHelpers.RegisterHitComponent(m_HitComponentsForAI, "LeftLeg", 50);
		DayZAIHitComponentHelpers.RegisterHitComponent(m_HitComponentsForAI, "RightLeg", 50);
	}

	void RegisterAttacks()
	{
		//! --------------------------------------------------------------------------------
		//!
		//! RegisterAttack(Group Type, Distance, Pitch, Type, Subtype, AmmoType, Cooldown, Probability);
		//!
		//! --------------------------------------------------------------------------------

		//! chase group
		m_ChaseAttacksGroup = new array<ref DayZInfectedAttackType>;

		//! center attack
		RegisterAttack(DayZInfectedAttackGroupType.CHASE, 1.5,  0, 0, 1, "MeleeZombie", 0, 1.0, 1.0); // center left & light
		RegisterAttack(DayZInfectedAttackGroupType.CHASE, 1.5,  0, 1, 1, "MeleeZombie", 0, 1.0, 1.0); // center right & light

		//! --------------------------------------------------------------------------------
		//! fight group
		m_FightAttacksGroup = new array<ref DayZInfectedAttackType>;

		//! up attack
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.0,  1, 0, 0, "MeleeZombie", 0, 1.0, 0.7); // up left & light
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.0,  1, 1, 0, "MeleeZombie", 0, 1.0, 0.7); // up right & light
		
		//! center attack
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.0,  0, 0, 1, "MeleeZombie", 0, 1.0, 1.0); // center left & light
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.0,  0, 1, 1, "MeleeZombie", 0, 1.0, 1.0); // center right & light
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.5,  0, 2, 1, "MeleeZombie_Heavy", 1, 2.0, 0.6); // center left & heavy
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.5,  0, 3, 1, "MeleeZombie_Heavy", 1, 2.0, 0.6); // center right & heavy
		
		//! down attack
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.5,  -1, 0, 2, "MeleeZombie", 0, 1.0, 1.0); // down left & light
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.5,  -1, 1, 2, "MeleeZombie", 0, 1.0, 1.0); // down right & light
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.5,  -1, 2, 2, "MeleeZombie_Heavy", 1, 2.0, 0.8); // down left & heavy
		RegisterAttack(DayZInfectedAttackGroupType.FIGHT, 2.5,  -1, 3, 2, "MeleeZombie_Heavy", 1, 2.0, 0.8); // down right & heavy
	}
	
	DayZInfectedAttackType ChooseAttack(DayZInfectedAttackGroupType pAttackGroupType, float pDistance, int pPitch)
	{
		ref array<ref DayZInfectedAttackType> attackGroup = GetAttackGroup(pAttackGroupType);
		float rnd = Math.RandomFloat01();
		float highestUtility = -1;
		DayZInfectedAttackType mostSuitableAttack = NULL;
		
		for( int i = 0; i < attackGroup.Count(); ++i )
		{
			DayZInfectedAttackType attackType = attackGroup.Get(i);
			float utility = ComputeAttackUtility(attackType, pDistance, pPitch, rnd);
			if( utility <= 0 )
				continue;
			
			if( utility > highestUtility )
			{
				mostSuitableAttack = attackType;
				highestUtility = utility;
			}
		}
		
		return mostSuitableAttack;
	}

	string GetHitComponentForAI()
	{
		string hitComp;
		
		if (DayZAIHitComponentHelpers.SelectMostProbableHitComponent(m_HitComponentsForAI, hitComp))
		{
			return hitComp;
		}	
		
		return GetDefaultHitComponent();
	}
	
	string GetDefaultHitComponent()
	{
		return m_DefaultHitComponent;
	}
	
	//--------------------------------------------------------
	// Protected
	//--------------------------------------------------------
	
	protected void RegisterAttack(DayZInfectedAttackGroupType pAttackGroupType, float pDistance, int pPitch, int pType, float pSubtype, string pAmmoType, int pIsHeavy, float pCooldown, float pProbability)
	{
		DayZInfectedAttackType newType = new DayZInfectedAttackType();
		
		newType.m_Distance = pDistance;
		newType.m_Pitch = pPitch;
		newType.m_Type = pType;
		newType.m_Subtype = pSubtype;
		newType.m_AmmoType = pAmmoType;
		newType.m_IsHeavy = pIsHeavy;
		newType.m_Cooldown = pCooldown;
		newType.m_Probability = pProbability;
		
		GetAttackGroup(pAttackGroupType).Insert(newType);
	}
	
	protected float ComputeAttackUtility(DayZInfectedAttackType pAttackType, float pTargetDistance, int pPitch, float pProbability)
	{
		// pitch
		if( pAttackType.m_Pitch != pPitch )
			return 0;

		// distance
		float distDiff = pAttackType.m_Distance - pTargetDistance;
		if( distDiff < 0 )
			return 0;
		float distDiffFrac = distDiff / 10;
		float utilityDistance = (1 - distDiffFrac) * 100; // distance is most important
		
		// probability
		float probDiff = pAttackType.m_Probability - pProbability;
		if( probDiff < 0 )
			return 0;
		float utilityProbability = (1 - probDiff) * 10; // distance is most important
		
		// total
		return utilityDistance + utilityProbability;
	}

	protected ref array<ref DayZInfectedAttackType> GetAttackGroup(DayZInfectedAttackGroupType pType)
	{
		switch( pType )
		{
		case DayZInfectedAttackGroupType.CHASE:
			return m_ChaseAttacksGroup;
			
		case DayZInfectedAttackGroupType.FIGHT:
			return m_FightAttacksGroup;
		}
		
		return NULL;
	}
	
	//--------------------------------------------------------
	// Members
	//--------------------------------------------------------
	
	//! selected & sorted targets by utility function
	private ref array<ref DayZInfectedAttackType> m_ChaseAttacksGroup;
	private ref array<ref DayZInfectedAttackType> m_FightAttacksGroup;

	//! Melee hit components (AI targeting)	
	protected ref array<ref DayZAIHitComponent> m_HitComponentsForAI;
	protected string m_DefaultHitComponent;
}