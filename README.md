# STM32 Quadcopter Flight Controller

A modular quadcopter flight controller firmware written for STM32F4 microcontrollers, featuring IBUS receiver input, MPU6050 IMU integration, Kalman filtering, PWM ESC control, and a 250 Hz PID-based stabilization loop.

## Features

- **Microcontroller**: STM32F405 / STM32F446 (HAL-based)
- **IMU**: MPU6050 with Kalman filter-based orientation estimation
- **Receiver**: IBUS protocol over UART with DMA
- **ESC Control**: PWM signal output via TIM3 Channels (1–4)
- **PID Controller**: Cascaded PID loops for Roll, Pitch, and Yaw rate control
- **Motor Mixing**: Basic +X quadcopter mixing logic
- **Modularity**: Cleanly structured `flight_manager`, `sensor_fusion`, `pid`, `motor_control`, and `receiver` modules



## Development Tools
- STM32CubeIDE
- ST-Link v2 for flashing and debugging
- Real-time logging over USB CDC for debugging

## Demo

Motor test sequence and orientation output via USB:
```
Motor 1 (Front Left) - PA6 - ESC Signal Sent: 1500 µs
Motor 2 (Front Right) - PA7 - ESC Signal Sent: 1500 µs
...
Roll: 1.2°, Pitch: 0.8°, Yaw: 2.4°
```

## Getting Started

1. Clone this repo and open in STM32CubeIDE.
2. Flash the firmware using ST-Link.
3. Monitor USB CDC output for sensor data and PID debug info.
4. Modify PID gains and test flight control logic using a test frame.

## License
MIT License
