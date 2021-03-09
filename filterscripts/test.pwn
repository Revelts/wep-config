#include <a_samp>
#include <wep-config>


public OnFilterScriptInit()
{
    return 1;
}

public OnFilterScriptExit()
{
    return 1;
}

//This call back as an example, its a same thing with other callback just different bodypart!
public OnPlayerShootHead(playerid, targetid, Float:amount, weaponid)
{

    // - This will give notification 
    new name[MAX_PLAYER_NAME+1];
    GetPlayerName(targetid, name, sizeof(name));
    SendClientMessage(targetid, -1, "Someone just shoot your head!");
    SendClientMessage(playerid, -1, "You shoot %s's head", name);

    // - This will set target to instantly death 
    SetPlayerHealth(targetid, 0);

    // - This will make player lifesteal
    new Float:health;
    GetPlayerHealth(playerid, health);
    SetPlayerHealth(playerid, health+amount);
    return 1;
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    /* -This will check if there are any bullet hit playerid torso while they shooting their weapon
        it will automatically make the playerid fall / apply animation*/

    if(IsBulletHitTorso(playerid))
        ApplyAnimation(playerid, "PED", "ko_skid_back", 4.1, 0, 0, 0, 1, 0, 1);
    
    return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    /* This will automatically set player's health to 0 or ..-
        ..- set player to death one there is a bullet hit his head while they enter a vehicle!*/

    if(IsBulletHitHead(playerid))
        SetPlayerHealth(playerid, 0);

    return 1;
}