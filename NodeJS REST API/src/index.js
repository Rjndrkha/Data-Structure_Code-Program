console.clear();
const { Client, Collection, Intents, version } = require("discord.js");
const chalk = require("chalk");
const fs = require("fs");
require("dotenv").config;

const express = require("express");
const { type } = require("express/lib/response");
const app = express();

const client = new Client({
  intents: new Intents(32767),
  partials: ["MESSAGE", "CHANNEL", "USER", "REACTION"],
  shards: "auto",
  restTimeOffset: 0,
});

client.on("ready", () => {
  client?.manager?.init(client.user.id);

  console.log(chalk.bold.white(`[Client] ${client.user.username} is Online!`));

  console.table({
    "Bot User:": `${client.user.tag}`,
    "Guild(s):": `${client.guilds.cache.size} Servers`,
    "Watching:": `${client.users.cache.size} Members`,
    "Discord.js:": `v${version}`,
    "Node.js:": `${process.version}`,
    "Plattform:": `${process.platform} ${process.arch}`,
    "Memory:": `${(process.memoryUsage().heapUsed / 1024 / 1024).toFixed(2)} MB / ${(process.memoryUsage().rss / 1024 / 1024).toFixed(2)} MB`,
  });
  client.user.setPresence({
    status: "online",
  });
  client.user.setActivity({
    name: "API",
    type: "LISTENING",
  });
});

client.login(process.env.TOKEN || "OTYzMjc4Nzg4NTMwMTU5NjQ4.YlTxSA.Nh3FcUnSHjvUdS8Q2BxEF6mQYUg");

const Dashboard = require("./app/app");
Dashboard(client);
