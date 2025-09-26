# Hardware Setup Guide

This document provides detailed hardware setup instructions for all STM32 beginner projects.

## Common Hardware Requirements

### Essential Components
- STM32F103C8T6 Blue Pill development board
- ST-Link V2 programmer (or compatible)
- Breadboard (half-size or full-size)
- Jumper wires (male-to-male, male-to-female)
- USB cable for ST-Link programmer

### Basic Tools
- Wire strippers
- Multimeter (for debugging)
- Oscilloscope (optional, for advanced debugging)

## Project-Specific Hardware

### Project 1: Basic LED Blink
**Components**: None additional (uses onboard LED)

**Connections**:
- No external connections required
- Uses onboard LED on PC13

### Project 2: Switch Controlled LED
**Components**:
- 1x Push button switch
- 1x 10kΩ resistor (optional, using internal pull-down)

**Connections**:
```
PA0 ---- Switch ---- 3.3V
PA0 ---- 10kΩ resistor ---- GND (optional, using internal pull-down)
```

### Project 3: Timed LED Blink
**Components**: Same as Project 2

**Connections**: Same as Project 2

### Project 4: Electronic Dice (Single)
**Components**:
- 1x Common cathode 7-segment display
- 7x 220Ω current limiting resistors
- 1x Push button switch

**7-Segment Display Connections**:
```
Display Pin -> STM32 Pin -> Resistor
a -----------> PB0 -------> 220Ω -> 3.3V
b -----------> PB1 -------> 220Ω -> 3.3V
c -----------> PB2 -------> 220Ω -> 3.3V
d -----------> PB3 -------> 220Ω -> 3.3V
e -----------> PB4 -------> 220Ω -> 3.3V
f -----------> PB5 -------> 220Ω -> 3.3V
g -----------> PB6 -------> 220Ω -> 3.3V
Common cathode -> GND
```

**Switch Connection**:
```
PA0 ---- Switch ---- 3.3V
```

### Project 5: Electronic Dice (Dual)
**Components**:
- 2x Common cathode 7-segment displays
- 14x 220Ω current limiting resistors
- 1x Push button switch

**First Display Connections** (same as Project 4):
```
Display1 Pin -> STM32 Pin -> Resistor
a -----------> PB0 -------> 220Ω -> 3.3V
b -----------> PB1 -------> 220Ω -> 3.3V
c -----------> PB2 -------> 220Ω -> 3.3V
d -----------> PB3 -------> 220Ω -> 3.3V
e -----------> PB4 -------> 220Ω -> 3.3V
f -----------> PB5 -------> 220Ω -> 3.3V
g -----------> PB6 -------> 220Ω -> 3.3V
Common cathode -> GND
```

**Second Display Connections**:
```
Display2 Pin -> STM32 Pin -> Resistor
a -----------> PC0 -------> 220Ω -> 3.3V
b -----------> PC1 -------> 220Ω -> 3.3V
c -----------> PC2 -------> 220Ω -> 3.3V
d -----------> PC3 -------> 220Ω -> 3.3V
e -----------> PC4 -------> 220Ω -> 3.3V
f -----------> PC5 -------> 220Ω -> 3.3V
g -----------> PC6 -------> 220Ω -> 3.3V
Common cathode -> GND
```

### Project 6: Interrupt Project
**Components**:
- 2x External LEDs
- 2x 220Ω current limiting resistors
- 1x Push button switch

**LED Connections**:
```
LED2: PB0 -> 220Ω resistor -> LED anode -> LED cathode -> GND
LED3: PB1 -> 220Ω resistor -> LED anode -> LED cathode -> GND
```

**Switch Connection** (for interrupt):
```
PA0 ---- Switch ---- 3.3V
```

## 7-Segment Display Pinout

### Standard 7-Segment Display
```
    a
   ---
f |   | b
   -g-
e |   | c
   ---
    d
```

### Common Pin Identification
- **Common Cathode**: Connect common pins to GND
- **Common Anode**: Connect common pins to VCC (use this type if available)

Note: The code examples assume common cathode displays. For common anode, invert the GPIO logic.

## Power Supply Considerations

### Blue Pill Power Options
1. **USB Power via ST-Link**: Most convenient for development
2. **External 3.3V Supply**: Use regulated 3.3V source
3. **5V Supply**: Can use 5V input, onboard regulator provides 3.3V

### Current Consumption
- Blue Pill alone: ~10-20mA
- Each LED segment: ~10-20mA
- Total project consumption: Usually < 200mA

## Troubleshooting Hardware Issues

### LED Not Working
- Check power connections (3.3V and GND)
- Verify current limiting resistors
- Test LED polarity
- Measure voltage across LED

### Switch Not Responding
- Check switch connections
- Verify pull-up/pull-down configuration
- Test switch continuity with multimeter
- Check for proper debouncing in software

### 7-Segment Display Problems
- Verify all segment connections
- Check common cathode/anode connection
- Test individual segments
- Verify resistor values
- Check display pinout against datasheet

### Programming Issues
- Ensure ST-Link connections: SWDIO, SWCLK, GND, 3.3V
- Check BOOT0 and BOOT1 jumper positions
- Verify power supply to Blue Pill
- Try different USB cable/port

## Safety Considerations

### Electrical Safety
- Always disconnect power when wiring
- Double-check connections before applying power
- Use appropriate current limiting resistors
- Avoid short circuits

### Component Protection
- Never exceed maximum current ratings
- Use proper voltage levels (3.3V logic)
- Handle components by edges, avoid touching pins
- Store components in anti-static bags when not in use

## Recommended Development Setup

### Breadboard Layout Tips
- Keep power rails clearly marked
- Use consistent wire colors (red=3.3V, black=GND)
- Group related components together
- Leave space between components for probing
- Use short, direct wire paths

### Wire Color Coding
- **Red**: 3.3V power
- **Black**: Ground (GND)
- **Yellow**: Clock signals
- **Blue**: Data signals
- **Green**: Control signals
- **White**: General I/O

This setup will help you maintain organized and debugging-friendly circuits throughout your STM32 learning journey.