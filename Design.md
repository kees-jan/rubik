# Design

The idea is to simulate a Rubik's cube.

## High level design

  * Fixed cube
  
    Cube cannot be rotated. All faces of the cube can be turned a quarter turn clockwise
    
  * Rotating cube
  
    Fixed cube of which the orientation can be changed
    
  * Cube
  
    Rotating cube with more operations. Turn counter-clockwise, turn middle layers, etc.
    
## Detailed design

### [Side](http://kees-jan.github.io/rubik/classRubik_1_1Side.html)

Represents one side of a cube. Since a side of a cube has no natural
orientation (top, bottom, left and right pretty soon become
meaningless), a side is orented relative to the color of the center
square of their adjacent sides.