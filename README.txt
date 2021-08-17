Digger 2020 project
Serves:
Shira Alfasi: 208175737
Sara Zeitlin: 209181874

About the project in general:
 A desktop app of the Digger game,  developed in C++ by using the principles of OOP. GUI development using the SFML library. The game has several levels with difficulties that increased.
The game will be "real-time", clock-driven, non-turn-based.
Collision in walls or between figures:
A definition of a collision is when there is an overlapping point between the relevant blocking rectangles, i.e. the rectangle
The blocking block and the rectangle blocking the blocking block or rectangles of the two colliding figures
(Digger and Monster).
We implemented the accessibility by a blocking rectangle as requested.
Restrictions and "bonuses" per player:
At each stage a time limit is set (in addition to the limit on the number of stones that are allowed to be "eaten", that is
Read from the file).
If the set time has elapsed, it is considered the disqualification of the player (descending "alive") and the stage begins anew (i.e. the whole stage begins anew, including the stones "eaten").

Another addition is the “gifts” scattered throughout the stage. The player collects the gift by "stepping" on it. Types
The gifts we have realized are:
1. Addition to the number of stones that are allowed to be "eaten".
2. Increasing the allotted time (assuming there is a time limit at this point).
3. Add a score.

Stages of the game:
We provided four steps
File format:
The first row contains four numbers: the number of rows in the stage, the number of columns and the number of stones
The luxury of eating, and also the time limit to combine (in seconds)
It is followed by rows as the number of rows defined with the notations # (wall), @ (stone), / (Digger),! (Monster), (D diamond) and a space for the empty squares. In addition, the + ("Gift") checkmark may appear.
All the steps will appear in one file, you can add steps in the BOARD file which will include in the first row the number of rows and the number of columns.
We assume the file is OK.

Score:
 For each diamond - 15 points, for the end of a stage - 20 points.


"Special" monsters:
In addition to the regular type of monsters we have defined so far, we will add a new type of monsters.
The choice of whether a monster is a normal or "special" monster is made randomly in the creation of the monster at the beginning of the stage
Both smart and random monsters can pass where there is a gift, but they obviously cannot take it.
The smart monsters can climb rocks, in addition they chase the player faster by calculating Manhattan.
(Remember, the information about the location of the monsters and their number we get by reading from the file).

Information display:
We show the player the number of points he has accumulated, the number of disqualifications he has left, the number of stones he is allowed to eat and the time he has left, as well as the number of the current stage.

move:
Although using a graphic screen we can also move the characters diagonally, seemingly, we will still leave
The shifts only in straight lines along the axes (so that we do not have a problem with the accessibility), so also the player's keys remain as they are arrows to move to one of the four sides respectively; Pressing the keys remains as it was
Only this time it is recognized with SFML events instead of getch.
The difference is that now we are not running in turn but by the clock. In any case, the rate of movement will not be based on the rate of receipt of the pressed key events, which is not uniform, but on the duration of the click and the clock.
The click only determines whether the player will move and in which direction he will move, when we want to move it. The displacement
The practice is carried out according to the elapsed time. When the player is stopped (even without getting stuck in an obstacle):
The player will continue to move even if he has left the key, and pressing the space bar will now be used to stop instead.

Displacement speeds:
The player's speed is: 150
The speed of the monster is: 130
The player is faster than the monster so that he can escape from it and that she will not eat it in a second ...

Necessary conditions for the plan: walls blocking in all directions.

Departments:
GAME OBJECT
It is a class from which everyone inherits - and in fact from it everyone realizes a painting function.

DYNAMIC:
Is a class from which all classes of static objects are inherited, ie PLAYER and MONSTER.

STATIC:
It is a class from which all classes of static objects are inherited, ie wall, stone, diamond ...

SMARTMONSTER:
A department that is responsible for all the care of the smart monsters is an heiress from MONSTER

ORIGINAL SAMPLES:
A department responsible for all care of ordinary monsters is a successor to MONSTER.

LEVEL:
Department responsible for all stages reading Each stage and stage ...
Stage transitions etc ..

INFORMATION DISPLAY:
Department responsible for displaying information.

CONST:
A class that holds all the constants of the game for us.

BOARD:
This department is responsible for all readings of the file.

BUTTON:
It is a department that is responsible for the buttons for entering and exiting the game.
The BUTTONSTART and BUTTONSTOP classes inherit from the BUTTON class

 RESOURCE:
Is a class from which we load all the images.

MNUE:
It is a department that is actually responsible for the entry and exit buttons.
