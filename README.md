# HAPTIC GLOVE

A smart glove which tracks hand and finger movement. This movement could be used for variety for tasks such as gaming, physics simulations and hand controlled robots.

## Current Development Stage

Design/Planning stage.

## Important Updates

- We've tested the [A1324LUA-T](https://www.allegromicro.com/en/products/sense/linear-and-angular-position/linear-sensors-1d/a1324-5-6) sensor.
- I have re-ordered the [N35](https://www.digikey.com/en/products/detail/radial-magnets-inc/8193/555328?s=N4IgTCBcDaIDoBcAEg4AgCwDYCcBaAjAAwFo4ByAIiALoC%2BQA) magnets.
- I also ordered the [Accelerometer](https://www.digikey.com/en/products/detail/adafruit-industries-llc/3886/10709725) sensor. This would be used to track the hand position and orientation of it. It communicates with the I2C protocol.
- Additionally, I got 5 [Potentioemeter](https://www.digikey.com/en/products/detail/tt-electronics-bi/P091S-FC20BR10K/2408860). These would be used to measure the bend on the knucle of each hand. I chose this idea so we could combine readings from nultiple sensores i.e Hall Effect and Potentiometer to eliminate any noises or irregularities in sensing data. Also, I think multi-sensor sensing is always safer and better choice for a project.

## TODO Tasks

While I'm providing a starter information on each of these, remember to do your own reasearch and point out anything stupid I might have included. Also, feel free to go beyond the points include things you find are better or needed for this project.

This must be a group effort!!!

- [ ] Select a MCU and Bluetooth Serial
    - A Lightweight development board with space constraints as well as low power consumption.
    - A Bluetooth Serial module to communicate with the host computer (your Laptop). This would not be needed if using boards like ESP32 which have bluetooth antenna built in.

- [x] Select sensors to sense the finger movement and hand tracking/orientation.
    - There are quite some options for finger movements. Try to compare benefits and disadvantages of each:
        - Hall Effect Sensor
            - Would be small and streamlined
            - Very cool
            - Hall effect sensors could interfer with other Hall effect sensors nearby (would need to test various magnet strengths)
            - Would need to be calibrated in order to output accurate distance readings
            - Potentially good options: [Hall-Sensor](https://www.allegromicro.com/en/products/sense/linear-and-angular-position/linear-sensors-1d/a1324-5-6)
            - Thing to consider:
                - This is a linear sensor so voltage changes linearly with the field.
                - Field usually is proportional to 1/r^3. How would you translate this voltage to possible distance or bend of the finger?? Maybe some kinda linear or quadratic fit could work.
                - What magnets to use and how would orientation of the magnets affect strength.
                - Also consider the our finger curl would majorly not be in a single axis. How important would this fact be as we would bend our joints in almost 90 degrees.

        - Potentiometer
            - Probably the most reliable option
            - Would need some way to mechanically turn potentiometer with finger movement
            - Not as cool as Hall effect sensors
            - Potentially good option: [Potentiometer](https://www.digikey.com/en/products/detail/tt-electronics-bi/P091S-QC15BR50K/2408861?gclsrc=aw.ds&gad_source=1&gad_campaignid=20243136172&gbraid=0AAAAADrbLljAaYyrH2StYB2OtgEJ8E_fF&gclid=CjwKCAiA9aPKBhBhEiwAyz82J6oq35BpvMt4HSuEcbuBFEe52bV97d_MmbQ3v2_BS-f8GoTKQrzsoRoCMi0QAvD_BwE)
        - A Flex sensor
            - Would be the smallest option (could be put inside of or even woven into glove)
            - Known to be unreliable and difficult to work with

    - The hand tracking might require some sophisticated sensor. Possible a combination of gyroscope and accelerometer. I'm not quite sure (would appreciate if someone does deep research on this).
    - Based on the selection of the sensor, you'd have to figure if a custom PCB is needed or an overkill for this. Try to talk with person selecting the MCU as he'd know what connections are neccessary.

- [ ] Once the magnets arrive, model the hall effect sensor readings to the finger position. We'd need some kind of mathematical model to create a mapping for it. You can either use a machine learning model or just a simple quadratic or cubic model. Choose this or any other option that we find to be feasible for real time processing and has decent accuracy.
      
- [ ] To place the potentiometer on the hand, we'll need to create some kind of CAD and attach it to maybe a rolling spring. The more it spins, the more our hand would be considered bent. [Here's](https://www.youtube.com/watch?v=1ZJNX8JCDOc) a good example on how our spool could look like. You can come up with some newer and interesting designs as well if you can!

- [ ] Select a simulation software to convert our sensor information into something tangible on the host screen. There might be a lot of physics simulation softwares. Main task would be to find how to interact with it. You can build your own simulation as well if you feel (but i won't recommend as it is not worth rn)

- [ ] Try to document the process so we can just keep a record of what's happening. You can update this doc explaining your decision and why you choose one thing over other. Overall, just keep everyone in the team updated to make sure all of us have equal understanding and ownership of this thing
