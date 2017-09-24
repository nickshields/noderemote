# NodeRemote.me
NodeRemote is a Node.js Application that works as a universal remote when paired with an Arduino.

## Features:
The Remote currently works with the IR device protocols that are found in the Arduino IR Library.
As of September 2017, these include: 
* NEC
* SONY
* PANASONIC
* JVC
* RC5
* RC6
* LG
* RAW (Which works for a lot of TV's)
There are a few others, but they will be added later on.
If you don't see your TV/Device manufacturer above, don't completely disregard this project.
A lot of TV's use the same protocol, and from my findings, NEC is a very popular protocol.
In other words, still give this a try :)


## Software/Hardware Requirements:
In order to take advantage of NodeRemote, you'll need the following:
* Linux/Unix PC with Node.js installed. (A raspberry pi works great)
* An Arduino with a VS1838B IR Receiver and an IR LED, a breadboard and sufficient wiring to complete the circuit.
* All the circuit parts cost less than $10 total on eBay, so this is a pretty cheap 'smart' remote.
Here is a picture of how the circuit should look:


## Setup:
* Clone this repository.
* Run npm install to install all the dependencies.
* Edit scripts/arduino.js and change the device location on line 8 to the location of your arduino (ie: '/dev/ttyACM1')
* Run npm start to start the web app.
* Visit localhost:8080 to see the app running. 


## How to Use the Web App:
Assuming you have everything running, the remote isn't much use without any commands defined into it. Scroll to the bottom of the app and flick the coniguration switch. Here's how to program the remote:
1. Put the remote you are trying to manipulate up to the IR Receiver and push the button that you would like to add to the remote. 
2. Click the corresponding button on the NodeApp. You may need to push it twice.
3. Turn off configuration mode, put the Arduino setup near the device you are trying to control and try controlling the device.
4. If everything worked, then great!

If it didn't, please check the server log for any errors. 
Feel free to add issues to the project. I will surely look into them. 
