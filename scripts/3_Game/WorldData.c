//! Keeps information about currently loaded world, like temperature
class WorldData
{
	protected float m_DayTemperature;
	protected float m_NightTemperature;
	protected Weather m_Weather;
	
	void WorldData()
	{
		Init();
	}
	
	void Init()
	{
		m_DayTemperature = GetDayTemperatureFromConfig();
		m_NightTemperature = GetNightTemperatureFromConfig();
		m_Weather = g_Game.GetWeather();
	}
	
	float GetDayTemperature()
	{
		return m_DayTemperature;
	}

	float GetNightTemperature()
	{
		return m_NightTemperature;
	}

	protected float GetDayTemperatureFromConfig()
	{
		float dayTemp = 10;

		if (g_Game.ConfigIsExisting("cfgWorlds CAWorld Weather dayTemperature"))
		{
			dayTemp = g_Game.ConfigGetFloat("cfgWorlds CAWorld Weather dayTemperature");
		}
		
		return dayTemp;
	}
	
	protected float GetNightTemperatureFromConfig()
	{
		float nightTemp = 6;

		if (g_Game.ConfigIsExisting("cfgWorlds CAWorld Weather dayTemperature"))
		{
			nightTemp = g_Game.ConfigGetFloat("cfgWorlds CAWorld Weather nightTemperature");
		}
		
		return nightTemp;
	}

	bool WeatherOnBeforeChange( EWeatherPhenomenon type, float actual, float change, float time )
	{
		// default behaviour is same like setting MissionWeather (in Weather) to true
		return false;
	}
};