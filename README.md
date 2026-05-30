# HMS Dashboard 2027

# Changes from 2026
1. Switching from using Python to using C++
    In previous years we have used Python and the library Kivy the backend and frontend of the dashboard respectively. Now instead it will be programmed in C++ with the UI hadled with OpenGl using the libraries GLAD and GLFW to streamline the integration of OpenGL. 

    This change also allows for further optimization of the code in the dashboard. Since C++ is lighter-weight compared to Python our file size could shrink as well as minimum system requirements to run the dashboard could improve from this change.

2. Modularity 
    Modulatrity plays a large role in how the backend of the dash is/will be programmed to allow for quick GUI changes whether it be which values are displayed or the color of text. This way it will be more effecient for our Ergonomics team to change the look and feel of the dash for the drivers.

# How to Change the Look
