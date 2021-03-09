#if defined _inc_wep_config
    #undef _inc_wep_config
#endif

#if defined _wepconfig_included
    #endinput
#endif
#define _wepconfig_included

//Library
#include <a_samp>

//Global Variable
enum RWC_PLAYER_DATA 
{
    RWC_PLAYER_FLAG:rwc_Flags
};

enum RWC_PLAYER_FLAG {
    rwc_head,
    rwc_torso,
    rwc_leftarm,
    rwc_rightarm,
    rwc_leftleg,
    rwc_rightleg,
    rwc_groin
};

static rwc_PlayerData[MAX_PLAYERS][RWC_PLAYER_DATA];

//Function
stock static rwc_GetFlag(playerid, RWC_PLAYER_FLAG:flag)
{
	return rwc_PlayerData[playerid][rwc_Flags] & flag;
}

stock static rwc_SetFlag(playerid, RWC_PLAYER_FLAG:flag, status)
{
	if(status)
		return rwc_PlayerData[playerid][rwc_Flags] |= flag;
	else
	    return rwc_PlayerData[playerid][rwc_Flags] &= ~flag;
}

//Function Prototype
forward OnPlayerShootHead(playerid, issuerid, amount, weaponid);
forward OnPlayerShootTorso(playerid, issuerid, amount, weaponid);
forward OnPlayerShootRightArm(playerid, issuerid, amount, weaponid);
forward OnPlayerShootLeftArm(playerid, issuerid, amount, weaponid);
forward OnPlayerShootRightLeg(playerid, issuerid, amount, weaponid);
forward OnPlayerShootLeftLeg(playerid, issuerid, amount, weaponid);
forward OnPlayerShootGroin(playerid, issuerid, amount, weaponid);


stock IsBulletHitHead(playerid)
{
    return rwc_GetFlag(playerid, rwc_head);
}

stock IsBulletHitTorso(playerid)
{
    return rwc_GetFlag(playerid, rwc_torso);
}

stock IsBulletHitLeftArm(playerid)
{
    return rwc_GetFlag(playerid, rwc_leftarm);
}

stock IsBulletHitRightArm(playerid)
{
    return rwc_GetFlag(playerid, rwc_rightarm);
}

stock IsBulletHitRightLeg(playerid)
{
    return rwc_GetFlag(playerid, rwc_rightleg);
}

stock IsBulletHitleftLeg(playerid)
{
    return rwc_GetFlag(playerid, rwc_leftleg);
}

//Timers

forward rwc_ResetFlag(playerid);
public rwc_ResetFlag(playerid)
{
    if(rwc_GetFlag(playerid, rwc_head))
        rwc_SetFlag(playerid, rwc_head, false);

    if(rwc_GetFlag(playerid, rwc_torso))
        rwc_SetFlag(playerid, rwc_torso, false);

    if(rwc_GetFlag(playerid, rwc_leftleg))
        rwc_SetFlag(playerid, rwc_leftleg, false);

    if(rwc_GetFlag(playerid, rwc_rightleg))
        rwc_SetFlag(playerid, rwc_rightleg, false);

    if(rwc_GetFlag(playerid, rwc_rightarm))
        rwc_SetFlag(playerid, rwc_rightarm, false);

    if(rwc_GetFlag(playerid, rwc_leftarm))
        rwc_SetFlag(playerid, rwc_leftarm, false);

    if(rwc_GetFlag(playerid, rwc_groin))
        rwc_SetFlag(playerid, rwc_groin, false);
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
    switch(bodypart)
    {
        case BODY_PART_HEAD: 
        {
            CallRemoteFunction("OnPlayerShootHead", "ddfd", playerid, issuerid, amount, weaponid);
            rwc_SetFlag(playerid, rwc_head, true);
        }
        case BODY_PART_TORSO: 
        {
            CallRemoteFunction("OnPlayerShootTorso", "ddfd", playerid, issuerid, amount, weaponid);
            rwc_SetFlag(playerid, rwc_torso, true);
        }
        case BODY_PART_LEFT_ARM: 
        {
            CallRemoteFunction("OnPlayerShootLeftArm", "ddfd", playerid, issuerid, amount, weaponid);
            rwc_SetFlag(playerid, rwc_leftarm, true);
        }
        case BODY_PART_LEFT_LEG: 
        {
            CallRemoteFunction("OnPlayerShootLeftLeg", "ddfd", playerid, issuerid, amount, weaponid);
            rwc_SetFlag(playerid, rwc_leftleg, true);
        }
        case BODY_PART_RIGHT_ARM: 
        {
            CallRemoteFunction("OnPlayerShootRightArm", "ddfd", playerid, issuerid, amount, weaponid);
            rwc_SetFlag(playerid, rwc_rightarm, true);
        }
        case BODY_PART_RIGHT_LEG: 
        {
            CallRemoteFunction("OnPlayerShootRightLeg", "ddfd", playerid, issuerid, amount, weaponid);
            rwc_SetFlag(playerid, rwc_rightleg, true);
        }
        case BODY_PART_GROIN: 
        {
            CallRemoteFunction("OnPlayerShootGroin", "ddfd", playerid, issuerid, amount, weaponid);
            rwc_SetFlag(playerid, rwc_groin, true);
        }
    }
    SetTimerEx("rwc_ResetFlag", 200, false, "i", playerid);
    #if defined rwc_OnPlayerTakeDamage
        return rwc_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart)
    #else
        return 1;
    #endif
}

#if defined _ALS_OnPlayerTakeDamage
    #undef OnPlayerTakeDamage
#else
    #define _ALS_OnPlayerTakeDamage
#endif
#define OnPlayerTakeDamage rwc_OnPlayerTakeDamage
#if defined rwc_OnPlayerTakeDamage
    forward rwc_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
#endif

