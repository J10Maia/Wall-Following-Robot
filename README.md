# 🤖 Wall Following Robot

![Robot GIF](https://media.giphy.com/media/xT9IgzoKnwFNmISR8I/giphy.gif)

## Overview

The Wall Following Robot is an autonomous robotic system designed to follow walls or obstacles using ultrasonic sensors. This project showcases my skills in embedded systems, real-time processing, and robotics. The robot can navigate environments by detecting and maintaining a specific distance from walls, making it ideal for applications in confined or structured spaces.

## 🎥 Video Demonstration

Check out the Wall Following Robot in action! Watch the video demonstration on [YouTube](https://youtu.be/18UAGtivYn0).

[![Wall Following Robot Video](https://img.youtube.com/vi/18UAGtivYn0/0.jpg)](https://youtu.be/18UAGtivYn0)

## 🚀 Features

- **Autonomous Navigation:** The robot autonomously follows walls using ultrasonic sensors.
- **Obstacle Detection:** Capable of detecting obstacles and adjusting its path to avoid collisions.
- **Real-Time Processing:** Implements real-time decision-making algorithms to ensure smooth navigation.
- **Embedded Systems:** Designed with efficient embedded systems, integrating hardware and software seamlessly.

## 🛠️ Technologies Used

- **C Programming:** Core logic and algorithms implemented in C.
- **Arduino:** Used for interfacing with sensors and controlling the robot's movements.
- **Ultrasonic Sensors:** Employed for precise distance measurement and wall detection.
- **Motor Control:** Efficient motor control for smooth navigation.

## 📦 Repository Structure

- `/src` - Contains the source code for the project.
- `/docs` - Documentation and schematics.
- `/hardware` - Details about the components and assembly of the robot.

## 📝 Setup Instructions

### Preparing your PC

#### Software to Download

* Visual Studio Code: [VSCode](https://code.visualstudio.com/download)
* Distributed version control system: [Git](https://git-scm.com/downloads)
* USB driver installation made easy: [Zadig](https://github.com/pbatard/libwdi/releases/download/v1.5.0/zadig-2.8.exe)

#### Installation Sequence

1. **Enable Long Paths in Windows:**
   * Open *Regedit*
   * Navigate to `HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\FileSystem`
   * Set `LongPathsEnabled` to `1`.

2. **Install Git:**
   * Download and install [Git](https://git-scm.com/downloads).
   * Open *Git CMD* and run the following command:
     ```bash
     git config --global core.longpaths true
     ```
   * Reboot your system to apply changes.

3. **Install Visual Studio Code:**
   * Download and install [VSCode](https://code.visualstudio.com/download).

4. **Set up PlatformIO in VSCode:**
   * Open VSCode and click the Extensions Icon (on the sidebar).
   * Search for "PlatformIO" in the marketplace.
   * Install PlatformIO and restart VSCode when prompted.

### Compiling the Project

1. **Open the Project in VSCode:**
   * Choose `File -> Open Folder...` and select the folder where the project is located.

2. **Build the Firmware:**
   * On the first run, PlatformIO may take some time to download the necessary compiler, tools, and libraries.
   * Once everything is installed, click the checkmark icon at the bottom of the VSCode window to build the firmware.

## 🌟 Future Enhancements

- **Improved Obstacle Avoidance:** Enhance the algorithm for more complex environments.
- **Path Planning:** Integrate path planning for navigating predefined routes.
- **Speed Optimization:** Fine-tune motor controls for smoother and faster navigation.

## 📫 Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

 [![LinkedIn](https://img.shields.io/badge/-LinkedIn-blue?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/joao10maia/)
 [![Email](https://img.shields.io/badge/-Email-D14836?style=flat&logo=gmail&logoColor=white)](mailto:joaomaia@live.com.pt)

---

Feel free to fork this repository, contribute, or simply explore the code!
