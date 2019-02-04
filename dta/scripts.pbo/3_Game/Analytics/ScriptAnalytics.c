// class binded to engine
class StatsEventMeasuresData
{
	string m_CharacterId;		//!< character ID
	int m_TimeInterval;			//!< amount of real time in seconds covered by this event
	int m_DaytimeHour;			//!< current daytime in gameplay (hour in 24h format)
	vector m_PositionStart;		//!< player world position at the start of interval
	vector m_PositionEnd;		//!< player world position at the end of interval
	float m_DistanceOnFoot;		//!< traveled distance on foot (meters) during interval
	
	float m_DistanceVehicle;	//!< traveled distance (meters) in vehicle during interval
	float m_TimeVONIn;			//!< amount of time in seconds with inbound VON during interval
	float m_TimeVONOut;			//!< amount of time in seconds with outbound VON during interval
	int m_CntLootAny;			//!< count of any loot collected during interval
	int m_CntLootFood;			//!< count of any food or consumables collected during interval
	int m_CntLootCloth;			//!< count of cloth collected during interval
	int m_CntLootFirearm;		//!< count of firearms collected during interval
	int m_CntLootAmmo;			//!< count of ammo collected during interval
	int m_CntKillInfected;		//!< count of infected kills during interval
	int m_CntConsumedFood;		//!< count of consumed food during interval
	int m_CntConsumedWater;		//!< count of consumed water during interval
	int m_HealthRestored;		//!< number of health point restored during interval
	int m_CntFiredAmmo;			//!< firearm rounds fired during interval
	int m_CntCraftedItem;		//!< number of items crafted during interval
	
	// listStatus				// state metric of health, hunger, thirst, etc... when event is created/send
	int m_HealthStatus;			//!< state of health (current state)
	int m_BloodStatus;			//!< state of blood (current state)
	int m_SicknessStatus;		//!< state of sickness (current state)
	int m_TemperatureStatus;	//!< state of temperature (current state)
	int m_FoodStatus;			//!< state of food (hunger) (current state)
	int m_HydrationStatus;		//!< state of hydration (thirst) (current state)
};

// class binded to engine
class StatsEventDeathData
{
	string		m_CharacterId;			//!< character ID
	int			m_CharacterLifetime;	//!< lifetime of character in seconds
	string		m_Cause;				//!< cause of death (hunger, sickness, player-killed, zombie-killed...)
	string		m_WeaponName;			//!< name of weapon which caused death
	float		m_Distance;				//!< distance in meters (rounded) from spawn position to death position
	vector		m_Position;				//!< position of player when died
	
	int			m_ListDamages[5];		//!< list of damages (5 values) during last n sec. For example: {20, 80, 0, 0, 0}
};

// class binded to engine
class StatsEventScoredKillData
{
	string		m_CharacterId;		//!< character ID
	string		m_WeaponName;		//!< name of weapon which killed player (victim)
	int			m_KillDistance;		//!< distance in meters (rounded) between killer and victim
	vector		m_PositionKiller;	//!< position of killer
	vector		m_PositionVictim;	//!< position of victim
};

// class binded to engine
class StatsEventDisconnectedData
{
	string		m_CharacterId;	//!< character ID
	string		m_Reason;		//!< reason of disconnect (quit, kick, ban, sign-out...)
};

// class binded to engine
class StatsEventSpawnedData
{
	string		m_CharacterId;	//!< character ID
	int			m_Lifetime;		//!< lifetime of character in seconds
	vector		m_Position;		//!< position of spawn
	int			m_Population;	//!< population of current gameplay (server)
	int			m_DaytimeHour;	//!< current time in hour (hour in 24h)
};


class ScriptAnalytics
{
	//! send event about death to statistic DB
	static proto native void SendPlayerDeath(StatsEventDeathData data);
	
	//! send event about kill to statistic DB
	static proto native void SendPlayerScoredKill(StatsEventScoredKillData data);
	
	//! send event to statistic DB
	static proto native void SendPlayerDisconnected(StatsEventDisconnectedData data);
	
	//! send event about player status to statistic DB
	static proto native void SendPlayerMeasures(StatsEventMeasuresData data);
	
	//! send event about spawning to statistic DB
	static proto native void SendPlayerSpawned(StatsEventSpawnedData data);
	
	
	
	//------------------------------------------------------------
	
	// send stats data with log
	static void PlayerDeath(StatsEventDeathData data)
	{
		if (true)
		{
			Print("StatsEventDeathData | CharacterId: '" + data.m_CharacterId + "'; CharacterLifetime: " + data.m_CharacterLifetime + "; Cause: '" + data.m_Cause + "'; WeaponName: '" + data.m_WeaponName + "'; Distance: " + data.m_Distance + "; position: " + data.m_Position);
		}
		
		SendPlayerDeath(data);
	}
	
	// send stats data with log
	static void PlayerScoredKill(StatsEventScoredKillData data)
	{
		if (true)
		{
			Print("StatsEventScoredKillData | CharacterId: '" + data.m_CharacterId + "'; WeaponName: '" + data.m_WeaponName + "'; KillDistance: " + data.m_KillDistance + "; PositionKiller: " + data.m_PositionKiller + "; PositionVictim: " + data.m_PositionVictim);
		}
		
		SendPlayerScoredKill(data);
	}
	
	// send stats data with log
	static void PlayerDisconnected(StatsEventDisconnectedData data)
	{
		if (true)
		{
			Print("StatsEventDisconnectedData | CharacterId: " + data.m_CharacterId + "; Reason: " + data.m_Reason);
		}
		
		SendPlayerDisconnected(data);
	}
	
	// send stats data with log
	static void PlayerMeasures(StatsEventMeasuresData data)
	{
		if (true)
		{
			Print("StatsEventMeasuresData 1 | CharacterId: '" + data.m_CharacterId + "'; TimeInterval: " + data.m_TimeInterval + "; DaytimeHour: " + data.m_DaytimeHour + "; PositionStart: " + data.m_PositionStart + "; PositionEnd: " + data.m_PositionEnd + "; DistanceOnFoot: " + data.m_DistanceOnFoot);
			Print("StatsEventMeasuresData 2 | DistanceVehicle: " + data.m_DistanceVehicle + "; TimeVONIn: " + data.m_TimeVONIn + "; TimeVONOut: " + data.m_TimeVONOut + "; CntLootAny: " + data.m_CntLootAny + "; CntLootFood: " + data.m_CntLootFood + "; CntLootCloth: " + data.m_CntLootCloth +  "; CntLootFirearm: " + data.m_CntLootFirearm + "; CntLootAmmo: " + data.m_CntLootAmmo + "; CntKillInfected: " + data.m_CntKillInfected + "; CntConsumedFood: " + data.m_CntConsumedFood + "; CntConsumedWater: " + data.m_CntConsumedWater + "; HealthRestored: " + data.m_HealthRestored + "; CntFiredAmmo : " + data.m_CntFiredAmmo + "; CntCraftedItem: " + data.m_CntCraftedItem);
			Print("StatsEventMeasuresData 3 | HealthStatus: " + data.m_HealthStatus + "; BloodStatus: " + data.m_BloodStatus + "; SicknessStatus: " + data.m_SicknessStatus + "TemperatureStatus: " + data.m_TemperatureStatus + "; FoodStatus: " + data.m_FoodStatus + "; HydrationStatus: " + data.m_HydrationStatus);
		}
		
		SendPlayerMeasures(data);
	}
	
	// send stats data with log
	static void PlayerSpawned(StatsEventSpawnedData data)
	{
		if (true)
		{
			Print("StatsEventSpawnedData | CharacterId: '" + data.m_CharacterId + "'; Lifetime: " + data.m_Lifetime + "; Position: " + data.m_Position + "; Population: " + data.m_Population + "; DaytimeHour: " + data.m_DaytimeHour);
		}
		
		SendPlayerSpawned(data);
	}
};