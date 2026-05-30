# HMS Dashboard 2027
The dashboard for HMS FSAE for the 2027 season.

## Goals at a Glance
[Switching from Python to C++](#Switching-from-Python-to-C++) 
    - Optimize the code
    - Write clean code
    - Write clear and concise comments
[Have well maintained documentation](#Documation) 
    - A custom file with all of the functions and/or classes in the program including their uses and why they were added.
[Modularity of the dashboard GUI](#Modularity-of-Ui) 
    - Make classes for broad GUI elements
    - Separate file for GUI elements to be add and or changed

## Changes from Previous Versions
### Switching from using Python to C++
    Instead of using Python and the library Kivy as our backend and GUI respectively we will now be using C++ with OpenGL to handle the backend and GUI of the program with the libraries GLAD and GLFW to streamline the process of developing graphics with OpenGL.

#### Reason for the switch
    Switching from Python to C++ wasn’t made off of a whim but has a had a good amount of thought behind it. One of the other contenders to switch to was C which has a lot of the benefits of C++ as well as being even lower level it allows for more optimization and custom garbage collection. However, C was quickly out of the question as one benefit of a higher-level language is accessibility, one of the goals of the new dashboard is to be accessible to new people joining the club so they may change it if they wish to. Another reason why C was not chosen was due to it not being object oriented, an object oriented language would allow for modular class structure for the UI elements which is another goal of this transition to C++. Due to these factors as well as others such as the popularity of C++ it was believed that people joining the club would already have an understanding of C++. There are many other reasons for switch to C++ or even more broadly why we switched from Python below.

    Most notability C++ is lighter-weight than Python shrinking file sizes. C++ is also a lower-level language allowing for more freedom and flexibility which allows for more room for optimization and customization within the backend of the program.

    Another reason for the switch is the had used the graphics library Kivy which made it difficult to create classes to allow for cleaner code and modularity of components in the dashboard as it required its own file and was its own unique language that integrated with python through a .kv file which didn’t support typical Python class structure, so all classes had to be coded at the top of the .kv file making it hard to quickly change the dashboard as the complexity of classes grew. The change to C++ with our graphics being handled directly by OpenGL would allow for the classes of the classes to be written directly in C++ and in separate files which would allow for the front-end GUI elements to stay separate from the backend. This switch would also allow for a custom file that the Ergonomics team can edit to change how the dashboard looks so they don’t have to parse through the code or ask someone on the Electrical team to make a change.

### Documentation
    This project will not only document when and why changes to the code were made but will also document the custom functions/classes in the code and their uses, how to maintain file structure, how to write comments, amend code in the program, and update the documentation.

    The reason for this is not to restrict or deter people from trying to change the code but to ensure that the changes to the program are purposeful and to leave no confusion in the process of changing anything related to the program so it may be maintained for years to come.

### Modularity of Ui
    One of the goals of this project is to allow for modularity of the GUI as well as making it as easy as possible to change, move, add, or remove Ui elements from the dashboard.

#### How
    This will be done by having a file structure that separates the backend elements from the GUI and Ui elements allowing easier navigation of the program. We will also aim to have many custom classes that will generalize a lot of what OpenGL allows to be done so the GUI can be quickly changed and there is less repetitive lines in the code leading to cleaner code.