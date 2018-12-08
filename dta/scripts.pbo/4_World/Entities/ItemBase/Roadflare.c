/*
	Author: Boris Vacula
	Description: The flare has 3 burning states during which it uses different particle effects while illumnatingthe environment. After it burns up, it still releases smoke for a while.
	When the flare is dropped while its burning, it is stood up on its stands. This makes the shadows, illumination and particles stand out better.
*/

enum RoadflareBurningState
{
	NOT_BURNING,
	INITIAL_BURN,
	MAIN_BURN,
	FINAL_BURN,
	SMOKE_ONLY
};

enum RoadflareModelStates
{
	DEFAULT,
	UNCAPPED_UNIGNITED,
	UNCAPPED_IGNITED,
	UNCAPPED_BURNED_OUT
};

class Roadflare : ItemBase
{
	// Burning
	static protected const int 	INITIAL_BURNING_STATE_TIME = 5;
	static protected const int 	FINAL_BURNING_STATE_TIME = 60;
	static protected vector		m_FlameLocalPos = "0 0.285 0";
	private int					m_BurningState = RoadflareBurningState.NOT_BURNING;
	
	// Particles
	protected Particle 			m_ParInitialFire;
	protected Particle 			m_ParMainFire;
	protected Particle 			m_ParFinalFire;
	protected Particle 			m_ParJustSmoke;
	
	static protected int 		PARTICLE_INIT_FIRE 		= ParticleList.ROADFLARE_BURNING_INIT;
	static protected int 		PARTICLE_MAIN_FIRE 		= ParticleList.ROADFLARE_BURNING_MAIN;
	static protected int 		PARTICLE_FINAL_FIRE 	= ParticleList.ROADFLARE_BURNING_ENDING;
	static protected int 		PARTICLE_FINAL_SMOKE 	= ParticleList.ROADFLARE_BURNING_SMOKE;
	
	// Sounds
	protected SoundOnVehicle		m_LoopSoundEntity;
	static protected const string	BURNING_SOUND 		= "roadflareLoop";
	static protected const int		BURNING_NOISE_RANGE = 30;
	
	// Timers
	ref Timer 					m_FinalSmokeTimer;
	
	// Ignition states
	private int					m_ModelState = RoadflareModelStates.DEFAULT;
	
	// Selections
	static const string 		STANDS_FOLDED 			= "Sticks_Flare_Folded";
	static const string 		STANDS_UNFOLDED 		= "Sticks_Flare_Unfolded";
	static const string			FLARE_CAP 				= "Flare_cap";
	static const string			UNIGNITED_TIP 			= "Pristine";
	static const string			IGNITED_TIP 			= "Burning";
	static const string			EXTINGUISHED_TIP 		= "Burned_out";
	
	static const int			SELECTION_Burning 		= 0;
	static const int			SELECTION_Burned_out	= 1;
	static const int			SELECTION_Pristine 		= 2;
	static const int			SELECTION_All	 		= 3;
	
	static const string			DEFAULT_TEXTURE 		= "dz\\gear\\consumables\\data\\road_flare_co.paa";
	static const string			BURNING_TEXTURE 		= "dz\\gear\\consumables\\data\\road_flare_e_co.paa";
	
	static const string			DEFAULT_MATERIAL 		= "dz\\gear\\consumables\\data\\road_flare.rvmat";
	static const string			BURNING_MATERIAL 		= "dz\\gear\\consumables\\data\\road_flare_on.rvmat";

	void Roadflare()
	{
		RegisterNetSyncVariableInt("m_BurningState");
	}
	
	// Use RoadflareModelStates enum
	void SetModelState(int enum_state)
	{
		m_ModelState = enum_state;
		UpdateModelSelections();
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if ( GetGame() )
		{
			if ( m_LoopSoundEntity != NULL )
			{
				GetGame().ObjectDelete( m_LoopSoundEntity );
			}
			
			delete m_FinalSmokeTimer;
		}
		
		DestroyAllParticles();
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write( m_ModelState );
	}
	
	override void OnStoreLoad(ParamsReadContext ctx)
	{
		super.OnStoreLoad(ctx);
		
		int state;
		ctx.Read(state);
		SetModelState(state);
	}
	
	void UpdateModelSelections()
	{
		switch (m_ModelState)
		{
			case RoadflareModelStates.DEFAULT:			
				
				ShowSelection(FLARE_CAP);
				ShowSelection(UNIGNITED_TIP);
			
				HideSelection(IGNITED_TIP);
				HideSelection(EXTINGUISHED_TIP);
			
				SetObjectTexture(SELECTION_Pristine, DEFAULT_TEXTURE);
				SetObjectMaterial(SELECTION_Pristine, DEFAULT_MATERIAL);
				
				break;
				
			case RoadflareModelStates.UNCAPPED_UNIGNITED:			
				
				ShowSelection(UNIGNITED_TIP);
				
				HideSelection(FLARE_CAP);
				HideSelection(IGNITED_TIP);
				HideSelection(EXTINGUISHED_TIP);
			
				SetObjectTexture(SELECTION_Pristine, DEFAULT_TEXTURE);
				SetObjectMaterial(SELECTION_Pristine, DEFAULT_MATERIAL);
				
				break;
				
			case RoadflareModelStates.UNCAPPED_IGNITED:
				
				ShowSelection(IGNITED_TIP);
				
				HideSelection(UNIGNITED_TIP);
				HideSelection(FLARE_CAP);
				HideSelection(EXTINGUISHED_TIP);
				
				// No texture/material change here because the model already contains them
				
				break;	
				
			case RoadflareModelStates.UNCAPPED_BURNED_OUT:
				
				ShowSelection(EXTINGUISHED_TIP);
				
				HideSelection(UNIGNITED_TIP);
				HideSelection(FLARE_CAP);
				HideSelection(IGNITED_TIP);
			
				SetObjectTexture(SELECTION_Burned_out, DEFAULT_TEXTURE);
				SetObjectMaterial(SELECTION_Burned_out, DEFAULT_MATERIAL);
			
				break;
		}
	}
	
	// When the flare starts burning
	override void OnWorkStart()
	{
		SwitchLight(true);
		
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer())
			m_LoopSoundEntity = PlaySoundLoop(BURNING_SOUND, BURNING_NOISE_RANGE);
		
		SetBurningState(RoadflareBurningState.INITIAL_BURN);
		SetModelState( RoadflareModelStates.UNCAPPED_IGNITED );
	}
	
	// Insert RoadflareBurningState enum index as parameter
	void SetBurningState(int state_number)
	{
		m_BurningState = state_number;
	}
	
	// Insert RoadflareBurningState enum index as parameter. Activates server -> client synchronization
	void SetBurningStateSynchronized(int state_number)
	{
		if ( GetGame().IsServer() )
		{
			m_BurningState = state_number;
			SetSynchDirty();
		}
	}
	
	// Every second of the flare burning
	override void OnWork(float consumed_energy)
	{
		if ( GetGame().IsServer() )
		{
			float burning_time = GetCompEM().GetEnergyMax() - GetCompEM().GetEnergy();
			
			// Update burning states
			if (m_BurningState == RoadflareBurningState.INITIAL_BURN)
			{
				if (burning_time >= INITIAL_BURNING_STATE_TIME)
				{
					SetBurningStateSynchronized(RoadflareBurningState.MAIN_BURN);
				}
			}
			else if(m_BurningState == RoadflareBurningState.MAIN_BURN)
			{
				if ( burning_time >= GetCompEM().GetEnergyMax() - FINAL_BURNING_STATE_TIME )
				{
					SetBurningStateSynchronized(RoadflareBurningState.FINAL_BURN);
				}
			}
			
			// Burn containers of this roadflare. This might be removed if lit roadflare can't be put into inventory.
			EntityAI container_EAI = GetHierarchyParent();
			
			if ( container_EAI  &&  container_EAI.IsInherited(ItemBase)  &&  !container_EAI.IsInherited(TripwireTrap) )
			{
				ItemBase container_IB = ItemBase.Cast( container_EAI );
				
				int c_size = container_IB.GetItemSize();
				if (c_size == 0)
					c_size = 1;
				
				container_IB.AddHealth("","",-10/c_size);
			}
		}
		
		UpdateActiveParticles();
	}
	
	// When the flare stops burning
	override void OnWorkStop()
	{
		if ( GetGame().IsMissionMainMenu() ) // This is singleplayer main menu so no synchronization here!
		{
			SetBurningState(RoadflareBurningState.NOT_BURNING);
			UpdateActiveParticles();
		}
		else
		{
			if ( GetGame().IsServer() )
			{
				SetBurningStateSynchronized(RoadflareBurningState.SMOKE_ONLY);
				SetHealth("","",0);
			}
			
			UpdateActiveParticles();
			m_FinalSmokeTimer = new Timer( CALL_CATEGORY_SYSTEM );
			m_FinalSmokeTimer.Run(60, this, "StopSmoking", NULL, false);
		}
		
		
		if ( m_LoopSoundEntity != NULL && GetGame() != NULL )
		{
			GetGame().ObjectDelete( m_LoopSoundEntity );
		}
		
		SetModelState( RoadflareModelStates.UNCAPPED_BURNED_OUT );
		SwitchLight(false);
	}
	
	// Updates all (in)active particles
	void UpdateActiveParticles()
	{
		if ( GetGame().IsServer()  &&  GetGame().IsMultiplayer() )
			return;
		
		switch (m_BurningState)
		{
			case RoadflareBurningState.NOT_BURNING:			
				
				DestroyAllParticles();
				break;
				
			case RoadflareBurningState.INITIAL_BURN:			
				
				if (!m_ParInitialFire)
				{
					DestroyAllParticles();
					m_ParInitialFire = Particle.Play( PARTICLE_INIT_FIRE, this, m_FlameLocalPos);
					m_ParInitialFire.SetWiggle( 15, 0.3);
				}
				break;
				
			case RoadflareBurningState.MAIN_BURN:
				
				if (!m_ParMainFire)
				{
					m_ParMainFire = Particle.Play( PARTICLE_MAIN_FIRE, this, m_FlameLocalPos);
					m_ParMainFire.SetWiggle( 10, 0.3);
				}
				
				DestroyParticle(m_ParInitialFire);
				
				break;	
				
			case RoadflareBurningState.FINAL_BURN:
				
				if (!m_ParFinalFire)
				{
					DestroyAllParticles();
					m_ParFinalFire = Particle.Play( PARTICLE_FINAL_FIRE, this, m_FlameLocalPos);
					m_ParFinalFire.SetWiggle( 5, 0.3);
				}
				break;
				
			case RoadflareBurningState.SMOKE_ONLY:			
				
				if (!m_ParJustSmoke)
				{
					DestroyAllParticles();
					m_ParJustSmoke = Particle.Play( PARTICLE_FINAL_SMOKE, this, m_FlameLocalPos);
					m_ParJustSmoke.SetWiggle( 3, 0.3);
				}
				break;
		}
	}
	
	// Destroys the given particle
	void DestroyParticle( Particle p )
	{
		if (p)
		{
			p.SetWiggle(0,0);
			p.Stop();
		}
	}
	
	// Destroys all particles
	void DestroyAllParticles()
	{
		DestroyParticle(m_ParInitialFire);
		DestroyParticle(m_ParMainFire);
		DestroyParticle(m_ParFinalFire);
		DestroyParticle(m_ParJustSmoke);
	}
	
	// Stop releasing final smoke
	void StopSmoking()
	{
		SetBurningStateSynchronized(RoadflareBurningState.NOT_BURNING);
		UpdateActiveParticles();
	}
	
	// Inventory manipulation
	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		
		if (m_BurningState != RoadflareBurningState.NOT_BURNING)
		{
			HideSelection(STANDS_FOLDED);
			ShowSelection(STANDS_UNFOLDED);
			
			vector ori_rotate = "180 32 0";
			//vector ori_standing = ori_rotate + GetOrientation(); // TO DO: Use ori_standing when item drop starts working again.
			SetOrientation(ori_rotate);
		}
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if ( m_BurningState != RoadflareBurningState.NOT_BURNING )
		{
			return false;
		}
		
		return true;
	}
	
	override void OnInventoryEnter(Man player)
	{
		super.OnInventoryEnter(player);
		
		HideSelection(STANDS_UNFOLDED);
		ShowSelection(STANDS_FOLDED);
	}
	
	override void OnActivatedByTripWire()
	{
		GetCompEM().SwitchOn();
	}
	
	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return GetCompEM().IsWorking();
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		UpdateActiveParticles();
	}
};