'use strict'
var SerialPort = require("serialport");

var options = {
	"baudRate":115200,
	"encoding":'utf8'
}
var serialport = new SerialPort("/dev/cu.usbmodem1421", options);
var commandData = require("./TV_Commands.json");

var SerialCommunication = function() {
	serialport.on('open', function() {
		//opens connection with serial port
		console.log("serial port opened");
	});
};

SerialCommunication.prototype.write = function(buttonVal) {
	var dictionary = {};
	dictionary["NEC"] = 0;
	dictionary["SONY"] = 1;
	dictionary["PANASONIC"] = 2;
	dictionary["JVC"] = 3;
	dictionary["RC5"] = 4;
	dictionary["RC6"] = 5;
	dictionary["UNKNOWN"] = 6;
	dictionary["LG"] = 7;
	dictionary["AIWA"] = 8;
	dictionary["WHYNTER"] = 9;


	var signal = commandData.commands[buttonVal].int;
	var tv_type = dictionary[commandData.commands[buttonVal].protocol];
	var bits = commandData.commands[buttonVal].bitRate;

	console.log("Sending Command: " + signal + "\n")
	serialport.write(tv_type + "\n");
    serialport.write(bits + "\n");
	serialport.write(signal + "\n");
};

SerialCommunication.prototype.configure = function(buttonVal) {
	var code = serialport.read();
	var test = code.toString('utf8');
	var res = test.split(" ");
	console.log(res);
	var fs = require('fs');
	var fileName = './TV_Commands.json';
	var file = require(fileName);
	file.commands[buttonVal].protocol = res[0];
    file.commands[buttonVal].int = res[1];
    file.commands[buttonVal].bitRate = res[2];
	fs.writeFile(fileName, JSON.stringify(file), function (err) {
  	if (err) return console.log(err);
  	console.log(JSON.stringify(file));
  	console.log('writing to ' + fileName);
	});
	return code;
};

module.exports = SerialCommunication;
