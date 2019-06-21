class Entity extends ObjectTyped
{
	proto native void DisableSimulation(bool disable);

	//! returns simulation timestamp
	proto native int GetSimulationTimeStamp();

	//! Return animation phase of animation on object.
	proto native float GetAnimationPhase(string animation);
	
	//! Process animation on object. Animation is defined in config file. Wanted animation phase is set to phase.
	proto native void SetAnimationPhase(string animation, float phase);

	//! Returns skeleton's bone index of named proxy selection.
	proto native int GetBoneIndex( string proxySelectionName );

	//! Returns proxy object that corresponds given bone inside skeleton.
	proto native Object GetBoneObject( int boneIndex );
	
	//! Turns on/off invisibility
	proto native void SetInvisible(bool invisible);

	/**
	\brief Client event on transformation update from network
	@param pos, world space position
	@param ypr, world space orientation in radians in form of Yaw/Pitch/Roll
	@return true if visual cut (won't do any interpolation) should be done after calling this callback
	\note object up vector is always y-axis
	*/
	bool OnNetworkTransformUpdate(out vector pos, out vector ypr);
};
