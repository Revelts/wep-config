# wep-config

[![sampctl](https://img.shields.io/badge/sampctl-wep--config-2f2f2f.svg?style=for-the-badge)](https://github.com/Revelt/wep-config)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install Revelt/wep-config
```

Include in your code and begin using the library:

```pawn
#include <wep-config>
```

## Usage

- Update your server body part checker separately with this library!

<!--
Write your code documentation or examples here. If your library is documented in
the source code, direct users there. If not, list your API and describe it well
in this section. If your library is passive and has no API, simply omit this
section.
-->

## Callback

- This callback used to check when player get shot by issuerid on their head
  - playerid : the player that get shot at
  - issuerid : the player that cause the damage
  - amount   : the amount of the damage
  - weaponid : weaponid
```
OnPlayerShootHead(playerid, issuerid, Float:amount, weaponid);
```
- This callback used to check when player get shot by issuerid on their torso
  - playerid : the player that get shot at
  - issuerid : the player that cause the damage
  - amount   : the amount of the damage
  - weaponid : weaponid
```
OnPlayerShootTorso(playerid, issuerid, Float:amount, weaponid);
```
- This callback used to check when player get shot by issuerid on their right arm
  - playerid : the player that get shot at
  - issuerid : the player that cause the damage
  - amount   : the amount of the damage
  - weaponid : weaponid
```
OnPlayerShootRightArm(playerid, issuerid, Float:amount, weaponid);
```
- This callback used to check when player get shot by issuerid on their left arm
  - playerid : the player that get shot at
  - issuerid : the player that cause the damage
  - amount   : the amount of the damage
  - weaponid : weaponid
```
OnPlayerShootLeftArm(playerid, issuerid, Float:amount, weaponid);
```
- This callback used to check when player get shot by issuerid on their right leg
  - playerid : the player that get shot at
  - issuerid : the player that cause the damage
  - amount   : the amount of the damage
  - weaponid : weaponid
```
OnPlayerShootRightLeg(playerid, issuerid, Float:amount, weaponid);
```
- This callback used to check when player get shot by issuerid on their left leg
  - playerid : the player that get shot at
  - issuerid : the player that cause the damage
  - amount   : the amount of the damage
  - weaponid : weaponid
```
OnPlayerShootLeftLeg(playerid, issuerid, Float:amount, weaponid);
```
- This callback used to check when player get shot by issuerid on their groin
  - playerid : the player that get shot at
  - issuerid : the player that cause the damage
  - amount   : the amount of the damage
  - weaponid : weaponid
```
OnPlayerShootGroin(playerid, issuerid, Float:amount, weaponid);
```



## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
