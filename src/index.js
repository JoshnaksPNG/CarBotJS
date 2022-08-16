const {Discord, Client, GatewayIntentBits} = require('discord.js');
const {SerialPort} = require("serialport");
const {Readline, ReadlineParser} = require("@serialport/parser-readline");
const Math = require("math.js");
const fs = require("fs");

const TOKEN = JSON.parse(fs.readFileSync("./src/config.json")).token;

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
    port.write("~");
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

            //Drive Short Left
            case "sl":
                drive_sleft();
                break;

            case "6":
                drive_sleft();
                break;

            case "sleft":
                drive_sleft();
                break;

            //Drive Short Right
            case "sr":
                drive_sright();
                break;

            case "7":
                drive_sright();
                break;

            case "sright":
                drive_sright();
                break;

            //Drive Short Foreward 4
            case "sf":
                drive_sfore();
                break;

            case "4":
                drive_sfore();
                break;

            case "sfore":
                drive_sfore();
                break;

            case "sforeward":
                drive_sfore();
                break;

            //Drive Short Backward 5
            case "sb":
                drive_sback();
                break;

            case "5":
                drive_sback();
                break;

            case "sback":
                drive_sback();
                break;

            case "sbackward":
                drive_sback();
                break;
        }
    }
});

bot.login(TOKEN);

//Drive Functions
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

//Short Drive Functions
function drive_sleft()
{
    //id 6
    port.write("6");
}

function drive_sright()
{
    //id 7
    port.write("7");
}

function drive_sfore()
{
    //id 4
    port.write("4");
}

function drive_sback()
{
    //id 5
    port.write("5");
}