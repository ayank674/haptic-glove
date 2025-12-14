# HAPTIC GLOVE

A smart glove which tracks hand and finger movement. This movement could be used for variety for tasks such as gaming, physics simulations and hand controlled robots.

## Current Development Stage

Design/Planning stage.

## TODO Tasks

While I'm providing a starter information on each of these, remember to do your own reasearch and point out anything stupid I might have included. Also, feel free to go beyond the points include things you find are better or needed for this project.

This must be a group effort!!!

- [ ] Select a MCU and Bluetooth Serial
    - A Lightweight development board with space constraints as well as low power consumption.
    - A Bluetooth Serial module to communicate with the host computer (your Laptop). This would not be needed if using boards like ESP32 which have bluetooth antenna built in.

- [ ] Select sensors to sense the finger movement and hand tracking/orientation.
    - There are quite some options for finger movements. Try to compare benefits and disadvantages of each:
        - Hall Effect Sensor
        - Potentiometer
        - A Flex sensor
    - The hand tracking might require some sophisticated sensor. Possible a combination of gyroscope and accelerometer. I'm not quite sure (would appreciate if someone does deep research on this).
    - Based on the selection of the sensor, you'd have to figure if a custom PCB is needed or an overkill for this. Try to talk with person selecting the MCU as he'd know what connections are neccessary.

- [ ] Select a simulation software to convert our sensor information into something tangible on the host screen. There might be a lot of physics simulation softwares. Main task would be to find how to interact with it. You can build your own simulation as well if you feel (but i won't recommend as it is not worth rn)

- [ ] Try to document the process so we can just keep a record of what's happening. You can update this doc explaining your decision and why you choose one thing over other. Overall, just keep everyone in the team updated to make sure all of us have equal understanding and ownership of this thing
