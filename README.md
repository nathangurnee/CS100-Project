# Snake
 ## Authors:
 [Julia Bayless](https://github.com/jbayl006)
 [Nathan Gurnee](https://github.com/nathangurnee)
 [Sulaiman Ahmed](https://github.com/sulaiman-ahmed)
 
## Project Description
### Why is it important or interesting to you?
  We decided to do Snake as our project because it seemed like an interesting choice and gamefication of learning is something we all as a group wholeheartedly agree with. We want to be able to make something we could use in a fun way,  while at the same time keeping the complexity.
 ### What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 * C++ - Language used for implementation of game functionality.
 * OpenGL - Graphics API used to render game.
 * GLFW - Library used with OpenGL to handle I/O and creation of OpenGL instances.
 ### What will be the input/output of your project?
 * Input - Keystrokes made by user.
 * Output - Movement of snake, display of game.
 ### What are the three design patterns you will be using?
 1. **Composite** - We want to have a base class for our graphic, since we will be re-drawing the graphic every frame. The graphic itself will consist of three subclasses - the snake, the food, and the border of the playing space. These will be drawn to the screen differently, based on which class calls the draw function.
 2. **Visitor** - We will need to implement some functionality to move the snake. As the snake eats the food and grows, we will have to slightly change how the snake moves across the screen. Using the Visitor pattern, we can tweak the snake’s movement without affecting the snake class itself.
 3. **Singleton** - There will only be a single instance of the snake being drawn over the course of the game. This snake will change in size and movement, but it will still be the same snake. This pattern will ensure that we use the same snake object every draw call.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
