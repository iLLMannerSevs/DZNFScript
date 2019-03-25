class PlayerBaseClient extends PlayerBase
{	
	static private ScriptedLightBase m_PersonalLight;
	
	void PlayerBaseClient()
	{
		if (!m_PersonalLight  &&  ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ))
		{
			m_PersonalLight = ScriptedLightBase.CreateLight(PersonalLight, "0 0 0");
		}
	}
}