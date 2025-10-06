# Project 1: Basic LED Blink

## Overview
This is the first project in the STM32 beginner series. It demonstrates basic GPIO output control by blinking the onboard LED on the Blue Pill development board.

## Learning Objectives
- Understand STM32 HAL library basics
- Learn GPIO output configuration
- Practice basic timing with HAL_Delay()
- Set up development environment

## Hardware Requirements
- STM32F103C8T6 Blue Pill board
- ST-Link programmer
- USB cable

## Hardware Connections
No external connections required - uses onboard LED on PC13.

## Software Features
- Simple LED toggle using HAL_GPIO_TogglePin()
- 500ms delay between toggles
- Infinite loop operation
- Basic error handling

## Key Functions Used
- `HAL_Init()` - Initialize HAL library
- `SystemClock_Config()` - Configure system clock
- `MX_GPIO_Init()` - Initialize GPIO ports
- `HAL_GPIO_TogglePin()` - Toggle GPIO pin state
- `HAL_Delay()` - Blocking delay function

## Code Structure
```c
int main(void)
{
  // Initialize HAL and peripherals
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  
  // Main loop
  while (1)
  {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(500);
  }
}
```

## Expected Behavior
- Onboard LED (PC13) blinks ON and OFF every 500ms
- LED should blink continuously after programming

## Troubleshooting
- **LED not blinking**: Check power connections and programming
- **LED always on/off**: Verify GPIO configuration
- **Programming fails**: Check ST-Link connections and drivers

## Next Steps
After completing this project, move to Project 2 to learn about GPIO input handling with switches.

## Modifications to Try
1. Change blink rate by modifying delay value
2. Try different GPIO pins with external LEDs
3. Implement different blink patterns (fast/slow alternating)
4. Add multiple LEDs for more complex patterns