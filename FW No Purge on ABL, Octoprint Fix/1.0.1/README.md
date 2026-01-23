# Kobra2 Neo Firmware 1.0.1

## Changelog

### 1.0.1
- Disabled the ABL purge by adding a toggle set to `false` in `Marlin/src/HAL/STM32/autoGetZoffset.cpp`:
  - `bool enable_filament_purge_on_calibration = false; // Toggle purge during ABL`
  - Guarded the purge moves behind the flag:
    - `thermalManager.set_fan_speed(0, 0);`
    - `thermalManager.setTargetHotend(0, 0);`
    - `unscaled_e_move(LOAD_LENGTH, LOAD_SPEED);`
    - `unscaled_e_move(-UNLOAD_LENGTH, UNLOAD_SPEED);`
