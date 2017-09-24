# Dashboard
Web app using NodeJS that I use control different things around my apartment

## Hue Control
* Node Module: [node-hue-api](https://github.com/peter-murray/node-hue-api) 
* Sends a request to my Philips Hue Hub.
* Yes this does in fact change my lights so please don't spam the buttons :)
* Feel free to try them out, I might get a good laugh out of it.
* Sorry but the light controls are disabled from 12am-8am, I like my sleep

## TV Remote (WIP)
* Uses an infrared led attached to an arduino sitting in front of the TV
* The adruino is wired to the local server
* signals are sent through the serial
* WIP:Back end has not been implimented with the front end

## Weather
* Node Module: [Forecast](https://www.npmjs.com/package/forecast)
* displays the current temperature in Waterloo (where I go to live)
* Coming soon: Room-temperature through arduino temp sensor

## Connected Devices
* Python module: [pynetgear](https://github.com/balloob/pynetgear)
* Gets a list of devices currently connected to the router
* Coming soon: device manufacterer and who's home

## Schedule (WIP)
* uses googles calendar API
* Should display next 10 events but is not currently working anymore
* More details will display full calendar

## MORE TO COME!!!
