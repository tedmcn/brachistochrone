Team Name:  DocileDolphins

Members: Cleophas Kalekem, Ted McNulty, Chong Swee, Jiaxuan (Amy) Wu 

Software Systems

2/13/2017

Project 1 Preliminary Report

Link to Proposal https://github.com/tedmcn/SoftSysDocileDolphins/blob/master/reports/proposal.md

1) State the goal of your project, ideally including a lower bound you are confident you can achieve and a stretch goal that is more ambitious.  This can be an updated version of the section you wrote in the proposal.

The goal of our project is to visually demonstrate the Brachistochrone curve using OpenGL. Our team has been able to achieve one part of the lower bound, which is being able to visually demonstrate the Brachistochrone curve using the Blender software’s physics engine (demo: https://youtu.be/gyFq77QwwsM)  . 

The second part of the lower bound we are currently in the process of developing is making a custom physics engine to demonstrate the same curve. We have been able to demonstrate the properties of the Brachistochrone curve using the Blender software’s physics engine. We are in the process of demonstrating the Brachistochrone curve on the Blender software’s physics engine as well. Since we are still in the process of creating our custom physics engine, our lower bound is the same: to visually demonstrate at least one cycloid, the Brachistochrone curve, using our custom physics engine. 

Our stretch goals are still the same: to include other factors like friction and angular momentum, to visually demonstrate other curves that stem from cycloids, to visually demonstrate real world applications of cycloids/curves, and to think more in depth about an interactive GUI for the project. 

2) Include a list of each project-related card you completed in Sprints 1 and 2. Annotate each card with a pointer to concrete evidence that the card has been completed (e.g. link to committed code, notes from a reading). If you have cards you can't provide evidence for, or work you did that doesn't have a card, make a note of it and use it to refine your cards for the next sprint.

We used an excel sheet to keep track of our project tasks completed in Sprints 1 and 2.

https://docs.google.com/spreadsheets/d/1zJcwGtZQ8o_Qhf2SpaiDqXceUJUjHyq4G1VVt83ROs0/edit?usp=sharing

3) Show preliminary results from your code. Depending on the project this could be a short demo video, example text sequence of commands and outputs, or some other form. Looking ahead to your final report, (updated versions of) these can serve as your usage examples.

Code in github: https://github.com/tedmcn/SoftSysDocileDolphins/tree/master/src

Link to blender rendered animation:  https://youtu.be/gyFq77QwwsM

Link to gravity demo from our engine: https://youtu.be/WilNkjOIcA0

4) Demonstrate that you have assembled the resources you need to complete the project.  One good way to do that is to update your annotated bibliography (with a pointer to each resource and a few sentences that describe the content) from the proposal.

Annotated bibliography:

http://www.thingiverse.com/thing:2051141 - B-curve file for blender

https://www.youtube.com/watch?v=skvnj67YGmw&t=690s - Vsauce channel’s physical demonstration of the cycloid with Adam Savage. This is the video where our team found inspiration for this project.

https://www.youtube.com/watch?v=qtpaauuGx-Y : This video shows a slow motion of the brachistochrone curve. We found this useful in understanding exactly how the curve works. The video gives a visual illustration of how the balls move down the ramp and which ball reaches the bottom of the ramp the fastest.

https://www.youtube.com/watch?v=Z-qaXZeJT4s - This is another physical demonstration of the brachistochrone

https://www.youtube.com/watch?v=_OAYRV5fjuE&t=6633s: OpenGL tutorial for beginners. This video allowed us to learn OpenGL in two hours.

https://www.youtube.com/watch?v=IkINbW_NMNk: This is a video we will incorporate if we have to make a powerpoint presentation to introduce how a cycloid is form. A visual demonstration can engage the audience more into our project.

http://www.opengl-tutorial.org/beginners-tutorials/ - OpenGL tutorials for beginners. Since we are all new to using OpenGL, we will use this link as a main resource.

http://mathworld.wolfram.com/BrachistochroneProblem.html - This is the resource which we use to understand the math behind deriving the curve. 

https://github.com/bulletphysics/bullet3 - We used the Bullet physics engine to understand physics engines before we started customizing our own. We used other physics engines, but this was the main one. 

https://www.blender.org/ - We used Blender software to import the cycloid ramp. We selected this resource because three of our team members have used Blender prior to this project. We used the Blender physics engine to test the physics for our B curve. 

https://www.youtube.com/playlist?list=PLEETnX-uPtBXm1KEr_2zQ6K_0hoGH6JJ0 - This is a really great video tutorial that covers making a physics engine from scratch. It covers most of the basic topics and even does some example coding on the engine.

http://openglut.sourceforge.net/ - This is the docs for Open GL Utility Toolkit which is a nice OpenGL library that will take care of a lot of the redundant work required when working with OpenGL. It comes with a  lot of functions that make creating the window and specifying window options much easier.

5) Present a product backlog for the next sprint that represents a concrete plan that will keep the entire team productively engaged and get you to your stated goals (this can be a link to your Trello board). If you had trouble putting together evidence for your cards in the previous sprints, adjust your new cards accordingly.

https://trello.com/b/my1FuYhe/softsysdociledolphins

6) Enumerate potential roadblocks and ways instructors can help.  Do you need materials? Do you have show-stopping questions you have not been able to answer?

--Problem with collaborating on the physics engine code because it contains several pieces

--We are going to need to use C++ to properly represent objects in our 3D environment so we may need some resources regarding C objects and classes.
