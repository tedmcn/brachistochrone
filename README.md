# Team Name: DocileDolphins

---

Cleophas Kalekem, Ted McNulty, Chong Swee, Jiaxuan (Amy) Wu

Software Systems

2/27/2017

## Project 1 Final Report

### Big Idea/Abstract

Our project is to showcase a custom physics engine coded in C/C++ using OpenGL. We selected our model to be the Brachistochrone curve, to illustrate how the custom physics engine works. The model is comprised of three ramps, one being the B curve. On top of each ramp is a sphere and the sphere that rolls down the B curve will always be the fastest. 

### Background

Our team is comprised of students that had little to no practice with graphics engineering, but all noted an interest in this domain. We decided to create a custom physics engine so that in the broader space, we can understand about the code behind enabling physics in a graphics engine and learn about the components and math behind physics. We were inspired by a YouTuber, Vsauce, who uploaded a video with MythBuster’s Adam Savage, where they created a physical model of the B curve. We wanted to generate this idea virtually in a graphics engine, choosing OpenGL which allowed us to implement our custom physics engine to demonstrate our knowledge in C and C++. 

### Implementation

We were able to create a physics engine which accurately models the physics of a bouncing ball, both on a flat plane and an angled plane. This also consists of an accurate gravity simulation where each item affected by gravity will slowly approach free-fall under gravity (as opposed to just having the y-velocity of each time set to -9.8 manually). Furthermore, the engine also needed to have accurate collision detection between a plane (represented as a scaled cube for our purposes) and a sphere. Lastly, we were able to create this engine strictly with formulas related to projectile motion and similar fields of physics (formulas such as the dot product and cross product of vectors, or calculating position, velocity, and acceleration given a difference in time).

Given our problem space, there is really only one major decision for us to make regarding the design implementation of this project (since a lot of the implementation is out of ours hands, being it’s physics), which is choosing an algorithm for collision detection. There are 3 main ways we found to create collision detection:

1. Bounding boxes
2. Bounding spheres
3. Separating Axis theorem

  Bounding boxes, takes every object and it frames a box around it, as small as possible, this box acts as a hitbox for the object, and can be effective for many shapes, but for something like a sphere, it loses its effectiveness. If an object approaches the sphere within the box from the direction of one of the corners of the box, the collision detection will report a collision sooner than it should.

  So bounding boxes are effective for cube-like shapes, but we are dealing mostly with a sphere so we also considered bounding spheres. This takes the same concept, but instead of surrounding the object with a box for a hitbox, we surround it with a sphere. This is actually easier to calculate than a bounding box collision since all we have to do is make sure the distance between two objects are less than their radii. Again, this algorithm falls short for non-sphere objects.

  Finally we considered the Separating Axis-Theorem, which is a professional algorithm which is specifically designed for collision detection between complex polygons, instead of simple cubes or spheres. As you might suspect, because this algorithm can handle such complex shapes it sacrifices a lot of run time (as it needs to compare every face to every other face, instead of just every object to every other object). Not only would this algorithm slow our simulation down significantly, but it also can only handle convex polygons, not concave polygons (like a slope). With these facts, we decided Separating Axis-Theorem would not be helpful. 

  We compromised by implementing a cross between bounding boxes and bounding spheres by implementing bounding boxes for the cube-like objects and bounding spheres for sphere-like object. We believe this was the correct choice as we could set up the simulation with just spheres and cubes, and it gave us a chance to write our own Cube/Sphere collision detection algorithm.



<a href="http://www.youtube.com/watch?feature=player_embedded&v=nYlgMGgmB3k
" target="_blank"><img src="http://img.youtube.com/vi/nYlgMGgmB3k/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>               <a href="http://www.youtube.com/watch?feature=player_embedded&v=-zgPDSpFw68
" target="_blank"><img src="http://img.youtube.com/vi/-zgPDSpFw68/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>



When we were only one weekend away from turning in this report, we had multiple options on how to complete this project, since we were not entirely sure yet if we could showcase a custom physics engine using the B curve. Our options included to:
Go ahead with original plan with demonstrating B curve by figuring out how to detect collision using colliders, vectors, vertices, or faces.
Create a plane and bounce a ball on the plane, with gravity implemented, which can demonstrate our custom physics engine.
Have a ball bouncing around hitting the borders of the GUI.
Have ball bounce on some vertices of the B curve, instead of rolling down the curve.
Have a ball bounce around a cube.

With option one, which was our stated minimal viable product, we took our professor’s advice that it may be beyond our reach at this point. When asked about our roadblock, on how to detect collision, it might be easier to use triangles or circles to detect when the ball and B curve would intersect. Our best decision was to work on options 2, 4 and 5. 
Making a physics engine was an interesting, but challenging project for our group. I think we expected it to be much easier than what it turned out. 
