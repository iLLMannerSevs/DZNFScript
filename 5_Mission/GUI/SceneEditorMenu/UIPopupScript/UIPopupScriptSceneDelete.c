class UIPopupScriptSceneDelete extends UIPopupScript
{
	private ButtonWidget 	m_BtnYes;
	private ButtonWidget 	m_BtnNo;
	private string			m_DeleteScene;
	
	//================================================
	// UIPopupScriptSceneDelete
	//================================================	
	void UIPopupScriptSceneDelete(Widget wgt)
	{
		m_BtnYes	= wgt.FindAnyWidget("btn_ppp_sn_dlt_yes");
		m_BtnNo		= wgt.FindAnyWidget("btn_ppp_sn_dlt_no");
	}

	//================================================
	// OnClick
	//================================================	
	bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		if ( w == m_BtnYes )
		{
			PluginSceneManager editor = GetPlugin(PluginSceneManager);
			
			editor.SceneDelete(m_DeleteScene);
			
			PopupBack();
			
			return true;
		}
		else if ( w == m_BtnNo )
		{
			m_DeleteScene = STRING_EMPTY;
			PopupBack();
			return true;
		}
		
		return false;
	}

	bool SetDeleteName(string scene_name)
	{
		m_DeleteScene = scene_name;
	}
}
