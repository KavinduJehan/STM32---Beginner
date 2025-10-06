# STM32 Beginner Projects
Beginner level Practice on STM32F103C8T6 (Blue Pill)

This repository contains a series of progressive STM32 projects using the HAL library, designed to teach fundamental concepts of embedded programming and prepare for bare metal development.

## Target Hardware
- **Microcontroller**: STM32F103C8T6 (Blue Pill development board)
- **Development Environment**: STM32CubeIDE or similar ARM development environment
- **Programming**: STM32 HAL Library

## Projects Overview

### 1. Basic LED Blink (`01_Basic_LED_Blink/`)
**Purpose**: Introduction to STM32 HAL and basic GPIO output control.

**Features**:
- Simple LED blinking using the onboard LED (PC13)
- HAL_Delay() for timing control
- Basic GPIO initialization and control

**Hardware Connections**:
- LED: PC13 (onboard LED on Blue Pill)

### 2. Switch Controlled LED (`02_Switch_Controlled_LED/`)
**Purpose**: Learn GPIO input handling and basic digital input/output interaction.

**Features**:
- LED turns on when switch is pressed
- Switch debouncing using HAL_Delay()
- GPIO input with internal pull-down resistor

**Hardware Connections**:
- LED: PC13 (onboard LED)
- Switch: PA0 (with internal pull-down)

### 3. Timed LED Blink (`03_Timed_LED_Blink/`)
**Purpose**: Implement state machine programming and edge detection.

**Features**:
- LED blinks exactly 10 times when switch is pressed
- Works regardless of how long the switch is held
- State machine implementation with proper edge detection
- Switch release detection before accepting new input

**Hardware Connections**:
- LED: PC13 (onboard LED)
- Switch: PA0 (with internal pull-down)

### 4. Electronic Dice (Single) (`04_Electronic_Dice_Single/`)
**Purpose**: Learn 7-segment display control and pseudo-random number generation.

**Features**:
- Single 7-segment display showing dice values (1-6)
- Pseudo-random number generation
- Rolling animation effect
- Switch-triggered dice roll

**Hardware Connections**:
- 7-segment display: PB0-PB6 (segments a-g)
- Switch: PA0 (with internal pull-down)

**7-Segment Pin Mapping**:
```
PB0 -> a, PB1 -> b, PB2 -> c, PB3 -> d
PB4 -> e, PB5 -> f, PB6 -> g
```

### 5. Electronic Dice (Dual) (`05_Electronic_Dice_Dual/`)
**Purpose**: Expand to multiple display control and synchronized operations.

**Features**:
- Two 7-segment displays for dual dice
- Independent random number generation for each die
- Synchronized rolling animation
- Enhanced visual effects

**Hardware Connections**:
- Display 1: PB0-PB6 (segments a-g)
- Display 2: PC0-PC6 (segments a-g)
- Switch: PA0 (with internal pull-down)

### 6. Interrupt Project (`06_Interrupt_Project/`)
**Purpose**: Introduction to interrupt-driven programming and real-time systems.

**Features**:
- External interrupt handling (EXTI0 for switch)
- Timer interrupt for periodic LED pattern updates
- Multiple LED pattern modes:
  - OFF: All LEDs off
  - SEQUENTIAL: LEDs light up one after another
  - ALTERNATING: LEDs alternate in groups
  - ALL_BLINK: All LEDs blink together
- Non-blocking operation using interrupts

**Hardware Connections**:
- LED1: PC13 (onboard LED, active low)
- LED2: PB0 (active high)
- LED3: PB1 (active high)
- Switch: PA0 (external interrupt, rising edge)

**Interrupt Configuration**:
- EXTI0: External interrupt for switch (PA0)
- TIM2: Timer interrupt at 4Hz (250ms period)

## Getting Started

### Prerequisites
1. STM32CubeIDE or compatible ARM development environment
2. STM32F103C8T6 Blue Pill development board
3. ST-Link programmer or compatible
4. Breadboard and connecting wires
5. Components as specified in each project

### Building and Flashing
1. Clone this repository
2. Open the desired project folder in STM32CubeIDE
3. Build the project (Ctrl+B)
4. Connect your ST-Link programmer to the Blue Pill
5. Flash the program to the microcontroller

### Project Structure
Each project follows the standard STM32CubeIDE structure:
```
Project_Name/
├── Core/
│   ├── Inc/
│   │   └── main.h
│   └── Src/
│       ├── main.c
│       └── stm32f1xx_it.c (interrupt projects)
└── Drivers/ (HAL library files - to be added)
```

## Learning Progression

This project series is designed to build skills progressively:

1. **Basic I/O**: Start with simple LED control
2. **Input Processing**: Add switch input and debouncing
3. **State Machines**: Implement complex behavior logic
4. **Display Control**: Learn to drive 7-segment displays
5. **Random Generation**: Implement pseudo-random algorithms
6. **Interrupt Handling**: Master real-time programming concepts

## Next Steps

After completing these projects, you'll be ready to:
- Explore bare metal programming (register-level control)
- Work with communication protocols (UART, SPI, I2C)
- Implement PWM for motor control
- Use ADC for sensor readings
- Develop more complex real-time applications

## Hardware Setup Notes

### Blue Pill Pinout Reference
- **PC13**: Onboard LED (active low)
- **PA0**: General purpose I/O, suitable for switch input
- **PB0-PB15**: General purpose I/O ports
- **PC0-PC15**: General purpose I/O ports (except PC13)

### Power Supply
- USB power through ST-Link programmer
- External 3.3V supply if needed
- Ensure proper ground connections

## Troubleshooting

### Common Issues
1. **LED not blinking**: Check power connections and pin configuration
2. **Switch not responding**: Verify pull-up/pull-down resistor configuration
3. **7-segment display not working**: Check pin connections and segment patterns
4. **Interrupt not triggering**: Verify NVIC configuration and pin setup

### Debug Tips
- Use LED indicators to debug program flow
- Check register values in debug mode
- Verify clock configuration for timer projects
- Use oscilloscope to verify signal timing

## Contributing
This is a learning repository. Feel free to suggest improvements or additional projects that would enhance the learning experience.

## License
This project is intended for educational purposes. Feel free to use and modify for learning and teaching.
