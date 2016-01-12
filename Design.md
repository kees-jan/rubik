# Design

The idea is to simulate a Rubik's cube.

## High level design

  * [Fixed cube](http://kees-jan.github.io/rubik/classRubik_1_1FixedCube.html)
  
    Cube cannot be rotated. All faces of the cube can be turned a quarter turn clockwise
    
  * Rotating cube
  
    Fixed cube of which the orientation can be changed
    
  * Cube
  
    Rotating cube with more operations. Turn counter-clockwise, turn
    middle layers, etc. Ultimate goal is to implement all operations
    found [here](http://ruwix.com/the-rubiks-cube/notation/advanced/)
    
## Detailed design

### [Side](http://kees-jan.github.io/rubik/classRubik_1_1Side.html)

Represents one side of a cube. Since a side of a cube has no natural
orientation (top, bottom, left and right pretty soon become
meaningless), a side is orented relative to the color of the center
square of their adjacent sides.

#### [Orientation](http://kees-jan.github.io/rubik/classRubik_1_1Orientation.html)

Used to specify the color of the center squares for each of the four
sides adjacent to the current side. Here, top, bottom, left and right
are used to indicate the orientation to relative to the initial
dataset.

For initializing an Orientation, an approximation of named parameters
is used. This way, one can type

    Orientation o = top(4).left(3).bottom(2).right(1);

which should be more readable than

    Orientation o(4,3,2,1);
