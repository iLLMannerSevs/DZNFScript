class MainMenuStats extends ScriptedWidgetEventHandler
{
	protected Widget m_Root;
	
	protected Widget m_TimeSurvived;
	protected TextWidget m_TimeSurvivedValue;
	
	protected Widget m_PlayersKilled;
	protected TextWidget m_PlayersKilledValue;
	
	protected Widget m_InfectedKilled;
	protected TextWidget m_InfectedKilledValue;
	
	protected Widget m_DistanceTraveled;
	protected TextWidget m_DistanceTraveledValue;
	
	protected Widget m_LongRangeShot;
	protected TextWidget m_LongRangeShotValue;
	
	void MainMenuStats( Widget root )
	{
		m_Root = root;
		
		m_TimeSurvived = m_Root.FindAnyWidget( "TimeSurvived" );
		m_TimeSurvivedValue = TextWidget.Cast( m_Root.FindAnyWidget( "TimeSurvivedValue" ) );
		
		m_PlayersKilled = m_Root.FindAnyWidget( "PlayersKilled" );
		m_PlayersKilledValue = TextWidget.Cast( m_Root.FindAnyWidget( "PlayersKilledValue" ) );
		
		m_InfectedKilled = m_Root.FindAnyWidget( "InfectedKilled" );
		m_InfectedKilledValue = TextWidget.Cast( m_Root.FindAnyWidget( "InfectedKilledValue" ) );
		
		m_DistanceTraveled = m_Root.FindAnyWidget( "DistanceTraveled" );
		m_DistanceTraveledValue = TextWidget.Cast( m_Root.FindAnyWidget( "DistanceTraveledValue" ) );
		
		m_LongRangeShot = m_Root.FindAnyWidget( "LongRangeShot" );
		m_LongRangeShotValue = TextWidget.Cast( m_Root.FindAnyWidget( "LongRangeShotValue" ) );
	}
		
	void ShowStats()
	{
		m_Root.Show( true );
		UpdateStats();
	}
	
	void HideStats()
	{
		m_Root.Show( false );
	}
	
	void UpdateStats()
	{
		PlayerBase player;
		MissionMainMenu mission_main_menu = MissionMainMenu.Cast( GetGame().GetMission() );
		
		#ifdef PLATFORM_WINDOWS
			player = mission_main_menu.GetIntroScenePC().GetIntroCharacter().GetCharacterObj();
		#endif
		#ifdef PLATFORM_CONSOLE
			player = mission_main_menu.GetIntroSceneXbox().GetIntroSceneCharacter();
		#endif
		
		if ( player )
		{
			float stat_value;
			string stat_text;
			
			m_TimeSurvivedValue.SetText( GetTimeString( player.StatGet( AnalyticsManagerServer.STAT_PLAYTIME ) ) );
			m_PlayersKilledValue.SetText( GetValueString( player.StatGet( AnalyticsManagerServer.STAT_PLAYERS_KILLED ) ) );
			m_InfectedKilledValue.SetText( GetValueString( player.StatGet( AnalyticsManagerServer.STAT_INFECTED_KILLED ) ) );
			m_DistanceTraveledValue.SetText( GetDistanceString( player.StatGet( AnalyticsManagerServer.STAT_DISTANCE ) ) );
			m_LongRangeShotValue.SetText( GetDistanceString( player.StatGet( AnalyticsManagerServer.STAT_LONGEST_SURVIVOR_HIT ), true ) );
		}
	}
	
	protected string GetTimeString( float total_time )
	{
		if( total_time < 0 )
			return "0h";
	
		int time_seconds = total_time; 							//convert total time to int
		string time_string;
		
		int hours = time_seconds / 3600;
		if ( hours > 0 )
		{
			time_string += GetValueString( hours ) + "h";		//hours
		}
		
		time_string += " ";										//separator
		
		int minutes = ( time_seconds % 3600 ) / 60;
		time_string += GetValueString( minutes ) + "m";			//minutes
		
		return time_string;
	}
	
	protected string GetDistanceString( float total_distance, bool meters_only = false )
	{
		if( total_distance < 0 )
			return "0m";
	
		int distance_meters = total_distance;
		string distance_string;
		
		int kilometers = distance_meters / 1000;
		if ( kilometers > 0 && !meters_only )
		{
			distance_string += GetValueString( kilometers ) + "km";			//kilometers
			distance_string += " ";											//separator
		}
		else
		{
			distance_string += GetValueString( distance_meters ) + "m";		//meters
		}
		
		return distance_string;
	}
	
	protected string GetValueString( float total_value )
	{
		if( total_value < 0 )
			return "0";
	
		int value = total_value;
		string out_string;
		
		if ( value >= 1000 )
		{
			string value_string = value.ToString();
			
			int count;		
			int first_length = value_string.Length() % 3;		//calculate position of the first separator
			if ( first_length > 0 )
			{
				count = 3 - first_length;
			}
			
			for ( int i = 0; i < value_string.Length(); ++i )
			{
				out_string += value_string.Get( i );
				count ++;
				
				if ( count >= 3 )
				{
					out_string += " ";			//separator
					count = 0;
				}
			}
		}
		else
		{
			out_string = value.ToString();
		}
		
		return out_string;
	}
}