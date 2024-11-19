SimpleGame Project Setup
To run this project, you will need the following:

OpenGL

GLAD

For Linux (Debian)
Update your package list:

sh
sudo apt update
Install the necessary dependencies:

sh
sudo apt install cmake pkg-config
sudo apt install g++ mesa-utils libglu1-mesa-dev freeglut3 freeglut3-dev mesa-common-dev
sudo apt install libglew-dev libglfw3-dev libglm-dev
Download and setup GLAD:

Visit the GLAD Generator.

Download the ZIP file.

Extract the contents:

Place the include folder into /usr/include.

Place the glad.c file into your project directory.

For Windows
Good luck! Here is a helpful guide: Learn OpenGL