#!/usr/bin/env node

import chalk from 'chalk';
import inquirer from 'inquirer';
import gradient from 'gradient-string';
import chalkAnimation from 'chalk-animation';
import figlet from 'figlet';
import { createSpinner } from 'nanospinner';

let userName;

const sleep = () => new Promise((h) => setTimeout(h, 3000));

async function header() {
    const rainbowHeader = chalkAnimation.rainbow(
        'Become a Node.js Expert!\n'
    );
    await sleep();
    rainbowHeader.stop();

    console.log(`
    ${chalk.bgGreen('HOW TO PLAY')} 
    I'm the Node.js in your computer.
    If you get any question wrong, I will be ${chalk.bgRed('killed')}
    So get all the questions right to win the special prize and keep me alive...
  `);
}

async function handleAnswer(isTrue) {
    const checking = createSpinner("Checking answer...").start();
    await sleep();

    if (isTrue) {
        checking.success({ text: `Nice job ${userName}. Keep it up!\n-----------------` })
    } else {
        checking.error({ text: `FALSE! ${userName}. Game Over. ` })
        process.exit(1)
    }
}

async function askName() {
    const inputs = await inquirer.prompt({
        name: "player_name",
        type: "input",
        message: "What is your name ?\n",
        default () {
            return "Player";
        }
    });
    userName = inputs.player_name;
};

function winner() {
    console.clear();
    figlet(`Congrats ${userName} !\nYou're A Node.js Expert!`, (err, data) => {
        console.log(gradient.summer.multiline(data) + '\n');

        console.log(
            chalk.green(
                `Programming isn't about what you know; it's about making the command line look cool`
            )
        );
        process.exit(0);
    });
}

async function q1() {
    const inputs = await inquirer.prompt({
        name: "q1",
        type: "list",
        message: "What is Node.js ?\n",
        choices: [
            "A programming language",
            "A JavaScript framework",
            "A JavaScript runtime",
            "An operating system"
        ],
    });
    return handleAnswer(inputs.q1 == "A JavaScript runtime");
}

async function q2() {
    const inputs = await inquirer.prompt({
        name: "q2",
        type: "list",
        message: "Who's the creator of Node.js?\n",
        choices: [
            "Linus Torvalds",
            "Sedat Kapanoglu",
            "Brendan Eich",
            "Ryan Dahl"
        ],
    });
    return handleAnswer(inputs.q2 == "Ryan Dahl");
}

async function q3() {
    const inputs = await inquirer.prompt({
        name: "q3",
        type: "list",
        message: "How many types of API functions are available in Node.js?\n",
        choices: [
            "4",
            "5",
            "2",
            "3"
        ],
    });
    return handleAnswer(inputs.q3 == "2");
}

async function q4() {
    const inputs = await inquirer.prompt({
        name: "q4",
        type: "list",
        message: "Which of the following is NOT a Node.js module?\n",
        choices: [
            "querystring",
            "http",
            "url",
            "fsutil"
        ],
    });
    return handleAnswer(inputs.q4 == "fsutil");
}

async function q5() {
    const inputs = await inquirer.prompt({
        name: "q5",
        type: "list",
        message: "What is NPM?\n",
        choices: [
            "Node Playable Menu",
            "Node Package Menu",
            "Node Package Manager",
            "Node Pending Manager"
        ],
    });
    return handleAnswer(inputs.q5 == "Node Package Manager");
}

async function q6() {
    const inputs = await inquirer.prompt({
        name: "q6",
        type: "list",
        message: "What is callback hell?\n",
        choices: [
            "A group with a certain equality between its members",
            "A JavaScript framework",
            "Result of using so much for loops in JavaScript",
            "The situation where callbacks are nested within other callbacks several levels deep."
        ],
    });
    return handleAnswer(inputs.q6 == "The situation where callbacks are nested within other callbacks several levels deep.");
}

//--------------
console.clear();
await header();
await askName();
await q1();
await q2();
await q3();
await q4();
await q5();
await q6();
await winner();