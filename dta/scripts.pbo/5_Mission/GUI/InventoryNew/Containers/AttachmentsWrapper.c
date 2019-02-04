class AttachmentsWrapper: Container
{
	ref Attachments m_Attachments;
	
	void SetParent( Attachments atts )
	{
		m_Attachments = atts;
	}
	
	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.AttachmentsWrapper;
	}
	
	override void Select()
	{
		m_Attachments.Select();
	}
	
	override void Combine()
	{
		
	}
	
	override void TransferItemToVicinity()
	{
		m_Attachments.TransferItemToVicinity();
	}
	
	override void TransferItem()
	{
		m_Attachments.TransferItem();
	}
	
	override void EquipItem()
	{
		m_Attachments.EquipItem();
	}
	
	override bool CanEquip()
	{
		return m_Attachments.CanEquip();
	}
	
	override bool CanCombine()
	{
		return m_Attachments.CanCombine();
	}
	
	override bool CanCombineAmmo()
	{
		return false;
	}
	
	override bool IsEmpty()
	{
		return m_Attachments.IsEmpty();
	}
	
	override bool IsItemActive()
	{
		return m_Attachments.IsItemActive();
	}

	override bool IsItemWithQuantityActive()
	{
		return m_Attachments.IsItemWithQuantityActive();
	}
	
	override EntityAI GetFocusedEntity()
	{
		return m_Attachments.GetFocusedEntity();
	}
}
