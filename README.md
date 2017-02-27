Team Name: DocileDolphins


Members: Cleophas Kalekem, Ted McNulty, Chong Swee, Jiaxuan (Amy) Wu

Software Systems

2/27/2017

Project 1 Final Report

### Big Idea/Abstract

Our project is to showcase a custom physics engine coded in C/C++ using OpenGL. We selected our model to be the Brachistochrone curve, to illustrate how the custom physics engine works. The model is comprised of three ramps, one being the B curve. On top of each ramp is a sphere and the sphere that rolls down the B curve will always be the fastest. 

### Background

Our team is comprised of students that had little to no practice with graphics engineering, but all noted an interest in this domain. We decided to create a custom physics engine so that in the broader space, we can understand about the code behind enabling physics in a graphics engine and learn about the components and math behind physics. We were inspired by a YouTuber, Vsauce, who uploaded a video with MythBuster’s Adam Savage, where they created a physical model of the B curve. We wanted to generate this idea virtually in a graphics engine, choosing OpenGL which allowed us to implement our custom physics engine to demonstrate our knowledge in C and C++. 

### Implementation
1. We accomplished a lot in terms of the broader space, but felt we could have dived a bit deeper into coding. 
2. Accomplishments:
3. We were able to play around with Blender and OpenGL tutorials.
4. We were able to understand the math behind the Brachistochrone curve
5. We were able to generate C code that allowed us to have a falling ball in OpenGL
6. We were able to load the B curve model from Blender into OpenGL using .obj extension. 
7. We were able to generate C++ code that allowed us to have a ball affected by gravity.
8. We were able to generate C++ code that allowed us to have a ball bouncing inside a cube.

When we were only one weekend away from turning in this report, we had multiple options on how to complete this project, since we were not entirely sure yet if we could showcase a custom physics engine using the B curve. Our options included to:
Go ahead with original plan with demonstrating B curve by figuring out how to detect collision using colliders, vectors, vertices, or faces.
Create a plane and bounce a ball on the plane, with gravity implemented, which can demonstrate our custom physics engine.
Have a ball bouncing around hitting the borders of the GUI.
Have ball bounce on some vertices of the B curve, instead of rolling down the curve.
Have a ball bounce around a cube.

With option one, which was our stated minimal viable product, we took our professor’s advice that it may be beyond our reach at this point. When asked about our roadblock, on how to detect collision, it might be easier to use triangles or circles to detect when the ball and B curve would intersect. Our best decision was to work on options 2, 4 and 5. 
Making a physics engine was an interesting, but challenging project for our group. I think we expected it to be much easier than what it turned out. 
