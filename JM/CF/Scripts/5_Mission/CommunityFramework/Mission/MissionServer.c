modded class MissionServer
{
	protected bool m_bLoaded;

	void MissionServer()
	{
		m_bLoaded = false;
	}

	void ~MissionServer()
	{
	}

	override void OnInit()
	{
		super.OnInit();
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
	}

	override void OnMissionFinish()
	{
		super.OnMissionFinish();
	}

	void OnMissionLoaded()
	{
	}

	override void OnUpdate( float timeslice )
	{
		if( !m_bLoaded && !GetDayZGame().IsLoading() )
		{
			m_bLoaded = true;
			OnMissionLoaded();
		} else {
			super.OnUpdate( timeslice );
		}
	}

	override void InvokeOnConnect( PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect( player, identity );
		
		GetLogger().Send( identity );
	}

}
