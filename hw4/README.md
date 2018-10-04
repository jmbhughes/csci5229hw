# HW4: James Marcus hughes

## Description
In this homework, I built upon my three-dimensional scene consisting 
of a couple mugs, a couple ferris wheels, and a ferris wheel seat. We now have the ability to 
view them in several interesting ways:

1. Orthogonal overhead
2. Perspective overhead
3. Perspective first person navigation

My viewing for 1 and 2 are linked, i.e. adjusting the view in one and switching to the other will be reflected. 
However, 3 is an independent viewer since their height is fixed .  

## Build Instructions
Use `make` to build.

## Run Instructions
Run `hw4` executable with no parameters. 

### Keybindings
To interact with the world, rotate your view using the arrow keys. 
To exit, click `escape`.
- `1` : switches to orthogonal overhead view
- `2` : switches to perspective overhead view
- `3` : switches to perspective first person view
- `esc` : closes the program
- `arrow keys`: in the overhead views, the arrow keys rotate the world so that the world moves
beneath you: left/right adjust azimuth while up/down adjust altitude; in the first person view,
the arrow keys allow you to move through the world, the forward/back keys allow you to walk forward 
or backwards while left/right adjusts where you're pointing (in azimuth). 
Your camera cannot tilt up and down and stays at a fixed height.

## Approximate time
I spent three hours on this homework, some was updating the scene while the rest was adding the new 
viewing geometries. 
