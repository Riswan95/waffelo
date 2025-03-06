Game Description
• Cakes, the main character, has turned into a walking pancake. He must now collect different types of waffles so that he can move forward and find a way to turn back. These powers include, shooting berries, walking underwater without drowning, jump really high, shrinking down to size and punching blocks out of the way.


Main Feature – Waffle Collectibles
Feature: Berry Waffle
•	Status: Completed
•	Overview: Allows Cakes to shoots up to 3 bullets
•	How it was implemented: A bullet object is first created. A bullet is then created into the “Waffelo” file as an array, bulletMax. The array is then loaded with three bullets in the initialize function. An array of VECTOR2s is also created. This is so that the velocity can be determined and used.

Feature: Bullet
•	Status: Completed
•	Overview: Allows a bullet to be created so that it can be shot
•	How it was implemented: When a bullet is created, its position is set at the center of Cake’s height and at the center +/- half its width. This is so that the bullet is created at its hand. When Cake looks to the right, a flip boolean is used to check if he its sprite is flipped horizontally (movement) is true or false. If he is looking to the right, the boolean is false and he is able to shoot a bullet at center + half its width. However, if he is looking left, the flip will be true and instead, the bullet will be created at the left of Cakes as the bullet is set to Cake’s center while subtracting his width.
Every time a bullet is created, an integer value named “bull” is increased by 1. This is to allow the next bullet to be used. After the bullet’s position is set, the bullet is then set horizontally using setX incrementally by updating the frametime and multiplying the x velocity (VECTOR2 array) by (-) 700. Similar to whether it is flipped horizontally is set to true or false. If it is true, it goes left, constantly being subtracted. If false, it goes to the right, constantly being added.
Once 3 bullets are used up, the player cannot shoot anymore as an “if” loop prevents it. If the player however is able to obtain another berry waffle, the “bull” is set to 0 again.
When the bullet collides with an enemy, it is able to kill it by setting the enemy’s scale to 0.

Feature: Bubble Waffle
•	Status: Completed
•	Overview: Allows Cakes to have a bubble around him so that he can walk underwater with getting damaged.
•	How it was implemented: A boolean, waffleBubble, and an image, bubble, is first created within the Cake class. This is so that the bubble draw function can be created within the cake. The boolean is then altered by using get/set methods to change it. The bubble is also drawn at a transparency level so that it gives off a more visual effect. If the bubble is true, it prevents water damage to be done to it.  When Cakes obtains another waffle, the boolean is simply turned off and he is no longer able to have a bubble and walk underwater without damage.
Feature: JumpHigh Waffle
•	Status: Completed
•	Overview: Allows cakes to jump much higher than he normally would be able to
•	How it was implemented: A VECTOR 2 was firstly created. An if loop is created whereby a boolean, jumpHighAct is set to false. Within the loop, normal jumping occurs, and a counter is decreased every time the player jumps. This counter is only set to 2. However, when the loop turns true after collision with the jumpHigh waffle, Cakes jumpForce multiplies the y velocity by 1.75 times. Slightly higher than the average jump height of a full double jump. Also, a normal jump consist of two jumps. However, when high jumping, he is no longer able to do that and the counter is immediately set to 0.

Feature: Shrink Waffle
•	Status: Completed
•	Overview: Allows Cakes to shrink and pass through objects he normally would not be able to do
•	How it was implemented: Cakes scale is set to a scale of 0 at an incremental rate of multiplying the frameTime by the scale of 0.5f. Once the scale hits half of Cakes size, he stops shrinking. If he obtains another waffle, the boolean, shrinkAct would be turned false and would grow back at the same incremental rate as before till he’s back to normal size. 

Feature: Strength Waffle
•	Status: Completed
•	Overview: Allows cakes to punch through cracked barriers
•	How it was implemented: When collided with the strength waffle, the boolean, strengthAct, is set to true. If he approaches a breakable tile, he is able to demolish it by pressing the E Key. This is because the scale of the breakable is set to 0. However, if the boolean is set to false, the x velocity is set to a negative number of 200, preventing Cakes from moving pass it from the left. The reason why it is one-sided is due to the fact that the game will not have Cakes coming from the right.

Main Feature: Main Menu
Main Feature: Start
•	Status: Completed
•	Overview: Allows the player to enter the play screen
•	How it was implemented: The menu was implemented under an if condition, menuOn, whereby if it was true, the main menu would pop out. This is then set to false after the player presses the start button. The function will see that menuOn is now false and will not run.

Main Feature: Credits
•	Status: Completed
•	Overview: Allows the player to see who credited the game
•	How it was implemented: Firstly, a boolean, creditsOn is initialized. This allowed the boolean to turn on every time the player entered the credits scree. For every creditor we had, a text line was added to the bottom. This made it convenient for us to add whoever credited the game and made it simple to use as well. When the player clicks the escape button, creditsOn is then turned off and the loop stops running, preventing the credits screen from being produced.

Main Feature: Exit
•	Status: Completed
•	Overview: Allows the player to exit the game
•	How it was implemented: When the player clicks Exit, PostQuitMessage(0) is called. This function exits the program.


Cake
•	Cake Movement
o	Status: Completed
o	Overview: to move the cake according to arrow key presses
o	Moving left and Right
	When the keys are pressed, the appropriate velocity is added incrementally to move the player. For example when the right key is pressed velocity.x is incremented by 200 and when left key is pressed velocity.x is incremented by -200 (to reverse the cake). Then as the velocity is incremented the position of the cake is also changing by adding 200 to the previous X position of the cake. This changes the x position of the cake and it shows like the cake is moving.
o	Jumping & gravity
	To stimulate the gravity, a  y velocity (downwards velocity) of 300.0f is always acting upon the cake. When the up arrow key is pressed, a force of (jumpForce) of -300 is set to the y velocity (goes upwards). Then the Y position is constantly changed to show the change of velocity in the cake.
	Also the player can only jump twice when he is in air. So the double jump value is decremented by 1 every time the player jumps. The double jump is then reset back to 2 when the cake lands.


•	Cake Animation
o	Status: Completed
o	Overview: To change the animation according to the movement of the cake
o	Cake Image
	![image](https://github.com/user-attachments/assets/ed844a99-a838-4916-92c3-a0f2bbfd8c20)
	The cake sprite has 7 columns of images that denotes each state of the cake. When the cake is idle, it uses the first two frames where the cake is moving its arms up and down. When the cake is moving, it uses the next two frames where the cake moves its legs, arms and open closes its mouth. When the bubble ability is activated there’ll be a bubble image over the cake (to be explained in waffle collectible)


Tiles/Objects
•	Drawing of tile and other objects 
o	Status: Completed
o	The game has a 2D array of numbers (mapDesign) to denote each position of the tile and other objects. Other objects includes the waffle the cake can eat and activate the appropriate power and other types of tiles.
![image](https://github.com/user-attachments/assets/c776babe-e498-438c-9f1e-80aa46d56854)
o	The numbers denoting the tile/objects are:
	1 – Tiles
	2 – Water Tiles
	3 – Shrink Waffle
	4 – Berry Waffle
	5 – Bubble Waffle
	6 – High Jump Waffle
	7 – Strength Waffle
	8 – Breakable tiles
o	In the main game render, two loops are running (row and column) to render these tiles/objects. Then when the 2 values are passed in to the 2D array and if it is more than 0 it renders that particular object. For e.g. if the mapDesign[row][col] == 1, it sets a tile object to that position (position is multiplied by the height and width of the tile) and draws the tile graphic image in that position.


•	Collision with Tiles
o	Status: Completed
o	Since the tiles that are drawn are just a graphic image and not an entity, collision will not be detected. So the centre of the cake is retrieved and divided by 72 (size of the tile texture) and round down to a whole number (ceil function). This gives the position of the cake based on the 2D map design array. Then the cake checks for tiles around it based on its direction of movement (velocity x and y). Cake checks for tile below it if it falling, checks above it when it is jumping, checks on the front if it is moving right and checks back if it is moving left. This is done so by (e.g. when moving right) 



o	CakeY = centre y position of cake in mapDesign array, CakeX = centre x position of cake in mapDesign. The code above checks for tiles in front of the cake when it is moving to the right. Then a tile is set to that position (Y = cakeY*tile size, x = cakeX*tile size +1). Then the collision begins when the cake x position + its width is more than or equal to the tiles x position it will reverse in velocity and the cake’s X position is placed before the tile (tiles’ x position – cakes’ width). Similar strategy is used for when moving in other directions as well.

•	Collision with Water
o	Status: Completed
o	There are water tiles where the cake can fall in and damage itself. When the cake’s centre positions are the same as the water tile positions (checked similarly to the way tiles are checked), it will damage cakes health by 1 incrementally. So the player has to stay out of the water, or get the bubble ability to stay alive.

•	Collision with Waffles (power ups)
o	Status: Completed
o	There are up to 5 waffles the cake can eat and get its powers. This is done when the Collision occurs with any of the waffle, the power of the waffle is activated. The kind of powers the player receives is covered under waffle section.
o	After the cake eats the waffle, the waffle is removed by setting its scale to 0. This is prevent the player from eating the same waffle again and again.

•	Collision with breakable Tile
o	Status: Completed
o	There are tiles where the player has to break to pass through. This can only be done if the cake eats the strength waffle. Else, the cake will not be able to pass through the tile.


Screens
•	Pause Menu
o	Status : Completed
o	The game features a pause menu where the player can select up to 3 options. When the player presses pause, the game engine paused is set to true. When player clicks resume the paused is set to false. When the player clicks restart, a restart function is called (restartGame ()). In the function, the position of the cake is set to (0, 0), all the waffles power are deactivated, its scales are set back to 1 again and the points are set back to zero. Also the hOffset (to be explained in horizontal scrolling) is set back to zero again to start the tiles from the beginning. When the main menu is pressed, it brings the player back to the main menu and restart function is called again.

•	Pause Menu button hover
o	Status: Completed
o	The pause menu has 3 buttons as discussed earlier. As an added measure to enhance appearance, the buttons changes in colour when the mouse is hovered over it. This is checked using the mouse position, if there are within the range of the box the button turns green.
<img width="336" alt="image" src="https://github.com/user-attachments/assets/781cbe7f-1865-43b0-81f5-e6dc7e16d0be" />


•	Lose Screen
o	Status: Completed
o	The lose screen appears when the HP of the cake hits zero. A screen pops up and pauses the game. Then the player is able to restart the game or go back to the main menu. The screen also shows the number of points the player have achieved so far.


Main Feature: Enemy & Artificial Intelligence
In order to create a smart looking enemy, Artificial Intelligence (AI) was used. For this, the tile map was converted to a special version specifically for AI use.

Tilemap for AI: Completed
 
Original TileMap in code. Note the integers go up to 8 in the tileMap

Conversion was done by programmatically copying and checking each tile in the TileMap and storing it in the AI during the creation of the enemy.

This specialised tile map converted all tiles that were not platform or water tiles into 0 and leaving the platform and water tiles intact. A second pass on this tileMap was done to create pseudo-nodes to be used for path- finding by denoting the edges of the platforms, with 3 being left edge, 4 being right edge and 5 being freestanding platforms. For each platform tile, it checks the tiles above, to the left and to the right of each tile. 
So for example, if for a platform, the above tile is empty, left tile is empty but the right has a tile then it is a left edge platform tile.

Pathfinding for AI: Partially Completed
Currently this tileMap is used to prevent enemies from falling off a platform. This also prevents the enemy from chasing the player off the platform it is on. However with the design it can easily be extended to allow for the AI to jump towards the player as well as navigate portions of the map towards the player just by checking the tiles ahead of the enemy. Advanced path finding is also doable by checking tiles.

Enemy Collisions with Tilemap: Completed
On collision with the tile, the enemy will get reset to outside the tile. This prevents the enemy from clipping into tiles.

Additionally, with the path finding, the AI avoids obstacles in the way by changing direction away from the obstacle.

Enemy Collisions with Player: Partially completed
On collision with the player, the player is supposed to be damaged or alternatively the enemy is supposed to die depending on the side that the player collides with.

When the player jumps on the head of the enemy, the enemy is supposed to die.
If the player gets hit by the enemy on any other side, the player should get damaged.

However, only the player damage is completed currently. This was implemented by doing Bounding Box collision checking against the player. If collision has occurred, the players health would be reduced.


Player detection: Partially Completed
Originally what was intended was that the AI would check for 3 things before attempting to chase the player.
•	Player within Range: Completed
•	Player within Cone of Vision: Not Completed
•	Player within Line of Sight: Not Completed

Currently only range is completed, it was implemented by getting the distance using pythagoras theorem to get the distance.
Cone of vision was attempted but not implemented. Whilst Line of Sight was not completed.

Shooting Enemy: Not Completed
In addition to a walking enemy, a shooting enemy was intended but not completed as cone of vision was integral to creating a working shooting enemy that wouldn’t attempt to shoot through walls or floors.





