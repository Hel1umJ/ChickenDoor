-Dependencies: wiringPi

-Install Dependencies on raspberry pi so the .so files are available for use by your executable.


-Install instructions:
https://learn.sparkfun.com/tutorials/raspberry-gpio/c-wiringpi-setup
https://forums.raspberrypi.com/viewtopic.php?t=350016


1. Clone repo: https://github.com/WiringPi/WiringPi
2. Run build script:
    -do ./build debian
    -then do sudo ./build (this installs libs in default lib directories on system)

    -verify with gpio -v

    -Note: Have to use debian option first and not just /build, /build segfaults.
    
3. Link lib into projects using -lwiringPi

-Upload raspberry pi OS: https://ubuntu.com/tutorials/how-to-install-ubuntu-desktop-on-raspberry-pi-4#2-prepare-the-sd-card

-Headless raspberry pi setup: https://www.tomshardware.com/reviews/raspberry-pi-headless-setup-how-to,6028.html 

-raspberry pi doc + pinout: https://www.raspberrypi.com/documentation/computers/raspberry-pi.html

-wiringPi pinout: https://pinout.xyz/pinout/wiringpi


Alternative library that isnt depreciated: pigpio
https://abyz.me.uk/rpi/pigpio/download.html




