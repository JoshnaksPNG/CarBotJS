const {Discord, Client, GatewayIntentBits} = require('discord.js');
const {SerialPort} = require("serialport");
const {Readline, ReadlineParser} = require("@serialport/parser-readline");
const Math = require("math.js");
const fs = require("fs");

const TOKEN = "";

const port = new SerialPort({ path: "COM3", baudRate: 9600 });

const parser = new ReadlineParser();
port.pipe(parser);

parser.on("data", (line) => 
{
    console.log(line);
});

const bot = new Client
(
    {
        intents:
        [
            GatewayIntentBits.Guilds,
            GatewayIntentBits.GuildMessages,
            GatewayIntentBits.MessageContent
        ]
    }
);

bot.on("ready", () =>
{
    console.log("Discord Bot Ready");
});

bot.on("messageCreate", (msg) =>
{
    if(msg.channel.name == "car-channel")
    {
        switch (msg.content.toLowerCase())
        {
            //Drive Left
            case "l":
                drive_left();
                break;

            case "2":
                drive_left();
                break;

            case "left":
                drive_left();
                break;

            //Drive Right
            case "r":
                drive_right();
                break;

            case "3":
                drive_right();
                break;

            case "right":
                drive_right();
                break;

            //Drive Foreward
            case "f":
                drive_fore();
                break;

            case "0":
                drive_fore();
                break;

            case "fore":
                drive_fore();
                break;

            case "foreward":
                drive_fore();
                break;

            //Drive Backward
            case "b":
                drive_back();
                break;

            case "1":
                drive_back();
                break;

            case "back":
                drive_back();
                break;

            case "backward":
                drive_back();
                break;
        }
    }
});

bot.login(TOKEN);

function drive_left()
{
    //id 2
    port.write("2");
}

function drive_right()
{
    //id 3
    port.write("3");
}

function drive_fore()
{
    //id 0
    port.write("0");
}

function drive_back()
{
    //id 1
    port.write("1");
}