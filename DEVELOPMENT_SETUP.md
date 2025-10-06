# Development Environment Setup

This guide helps you set up your development environment for STM32 programming with these beginner projects.

## Software Requirements

### Primary Development Environment
**STM32CubeIDE** (Recommended)
- Free IDE from STMicroelectronics
- Integrated STM32CubeMX for configuration
- Built-in debugging support
- Download: https://www.st.com/en/development-tools/stm32cubeide.html

### Alternative Development Environments

#### Option 1: STM32CubeMX + IDE of Choice
- **STM32CubeMX**: For project generation and configuration
- **IDE Options**: 
  - Keil MDK-ARM
  - IAR Embedded Workbench
  - System Workbench for STM32 (SW4STM32)
  - PlatformIO with VS Code

#### Option 2: Command Line Development
- **ARM GCC Toolchain**: For compilation
- **OpenOCD**: For programming and debugging
- **Text Editor**: VS Code, Vim, Emacs, etc.
- **Make**: For build automation

## Hardware Requirements

### Programmer/Debugger
**ST-Link V2** (Recommended)
- Official STMicroelectronics programmer
- Supports SWD and JTAG
- Real-time debugging capability
- Clone versions available but may have limitations

**Alternative Programmers**:
- J-Link (more expensive but more features)
- Black Magic Probe
- Built-in ST-Link on Nucleo boards

### Development Board
**STM32F103C8T6 Blue Pill**
- Affordable and widely available
- Arduino-like form factor
- 64KB Flash, 20KB RAM
- 72MHz ARM Cortex-M3

## Installation Guide

### STM32CubeIDE Installation

#### Windows
1. Download STM32CubeIDE installer
2. Run installer as administrator
3. Follow installation wizard
4. Install ST-Link drivers when prompted

#### Linux (Ubuntu/Debian)
```bash
# Download the installer from ST website
# Make it executable
chmod +x st-stm32cubeide_*.sh

# Run installer
sudo ./st-stm32cubeide_*.sh

# Install additional dependencies if needed
sudo apt-get install libncurses5
```

#### macOS
1. Download macOS installer (.dmg)
2. Mount the disk image
3. Drag STM32CubeIDE to Applications folder
4. Install ST-Link drivers separately if needed

### Driver Installation

#### ST-Link Drivers
**Windows**: Usually installed automatically with STM32CubeIDE

**Linux**: 
```bash
# Clone ST-Link repository
git clone https://github.com/stlink-org/stlink.git
cd stlink

# Build and install
make clean
make
sudo make install
sudo ldconfig

# Set up udev rules
sudo cp config/udev/rules.d/* /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
```

**macOS**: Download separate ST-Link driver package from ST website

## Project Setup

### Creating a New Project

#### Using STM32CubeIDE
1. File → New → STM32 Project
2. Select STM32F103C8Tx from part number search
3. Choose project name and location
4. Select "Empty" template for learning purposes

#### Manual Project Setup
1. Create project directory structure:
```
Project_Name/
├── Core/
│   ├── Inc/
│   └── Src/
├── Drivers/
│   └── STM32F1xx_HAL_Driver/
└── Startup/
```

### Importing Existing Projects
1. File → Import → General → Existing Projects into Workspace
2. Browse to project directory
3. Select project and click Finish

### STM32CubeMX Configuration

#### Basic Setup Steps
1. Open STM32CubeMX (integrated in CubeIDE)
2. Select your microcontroller (STM32F103C8Tx)
3. Configure clock settings:
   - HSI as system clock source
   - PLL enabled with appropriate multiplier
   - System clock = 72MHz
4. Configure GPIO pins as needed
5. Generate code

#### Pin Configuration Examples
- **Output Pin**: Set as GPIO_Output, Push Pull, No Pull, Low Speed
- **Input Pin**: Set as GPIO_Input, No Pull (or Pull Up/Down as needed)
- **Interrupt Pin**: Set as GPIO_EXTI_Rising/Falling, enable NVIC

## Programming and Debugging

### Connecting Hardware
1. Connect ST-Link to Blue Pill:
   - ST-Link 3.3V → Blue Pill 3.3V
   - ST-Link GND → Blue Pill GND
   - ST-Link SWDIO → Blue Pill DIO
   - ST-Link SWCLK → Blue Pill DCLK

2. Set Blue Pill boot jumpers:
   - BOOT0 → 0 (normal operation)
   - BOOT1 → 0 (normal operation)

### Programming the Device

#### Using STM32CubeIDE
1. Build project (Ctrl+B)
2. Right-click project → Run As → STM32 C/C++ Application
3. Select debug probe (ST-Link)
4. Click OK to program and run

#### Using Command Line
```bash
# Using OpenOCD
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -c "program project.elf verify reset exit"

# Using st-flash
st-flash write project.bin 0x8000000
```

### Debugging

#### Debug Configuration
1. Create debug configuration in IDE
2. Set breakpoints in code
3. Start debugging session
4. Use debug controls:
   - Step Over (F6)
   - Step Into (F5)
   - Continue (F8)
   - Variables view
   - Memory view

#### Common Debug Techniques
- **LED Indicators**: Use LEDs to show program state
- **Breakpoints**: Stop execution at specific points
- **Variable Watch**: Monitor variable values
- **Memory Inspection**: Check register and memory contents

## Troubleshooting

### Common Issues

#### Programming Problems
**Error: "No ST-Link detected"**
- Check USB connection
- Verify driver installation
- Try different USB port
- Check ST-Link LED indicators

**Error: "Target not found"**
- Check SWD connections
- Verify power supply to Blue Pill
- Check boot jumper settings
- Try lower SWD frequency

#### Build Problems
**Missing Header Files**
- Verify HAL library inclusion
- Check include paths in project settings
- Ensure proper project structure

**Linker Errors**
- Check memory settings in linker script
- Verify all source files are included
- Check for symbol name conflicts

#### Runtime Problems
**Program Not Running**
- Check if program counter is at correct address
- Verify clock configuration
- Check for infinite loops in initialization
- Use debugger to step through code

### Advanced Debugging

#### Using SWV (Serial Wire Viewer)
1. Enable SWV in debug configuration
2. Configure ITM for printf debugging
3. Use ITM_SendChar() for debug output

#### Logic Analyzer Usage
- Monitor digital signals
- Verify timing relationships
- Debug communication protocols
- Check interrupt timing

## Best Practices

### Project Organization
- Use consistent naming conventions
- Comment your code thoroughly
- Organize files logically
- Version control with Git

### Development Workflow
1. Plan your project structure
2. Configure hardware in CubeMX
3. Write and test code incrementally
4. Use version control for changes
5. Document your work

### Code Quality
- Follow consistent coding style
- Use meaningful variable names
- Add function headers and comments
- Test edge cases
- Handle error conditions

## Additional Resources

### Documentation
- STM32F103 Reference Manual
- STM32F103 Datasheet
- STM32 HAL Library Documentation
- ARM Cortex-M3 Programming Manual

### Online Communities
- STM32 Community Forum
- Reddit r/embedded
- Stack Overflow (stm32 tag)
- Discord embedded development servers

### Learning Resources
- STMicroelectronics YouTube channel
- STM32 MOOCs and webinars
- Embedded systems textbooks
- Online embedded programming courses

This setup guide should get you started with STM32 development. Remember that embedded programming has a learning curve, so be patient and systematic in your approach.