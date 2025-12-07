// ? simple rock paper scissor game
// ! rock > scissor --> win 
// ! scissor > paper --> win
// ! paper > rock --> win

const prompt = require("prompt-sync")();

// brain function for the computer
const comp = (inp) => {
  // declares the characters for each choice
  const char = {
    rock: "r",
    paper: "p",
    scissor: "s"
  }
  let choice = Math.floor(Math.random() * Object.keys(char).length);
  let comp_choice = Object.keys(char)[choice];

  if(inp === comp_choice) {
    return "It's a tie!";
  } else if (inp === "rock" && comp_choice === "scissor" ||
             inp === "scissor" && comp_choice === "paper" ||
             inp === "paper" && comp_choice === "rock") {
    return `You win! Computer chose ${comp_choice}`;
  } else {
    return `You lose! Computer chose ${comp_choice}`;
  }
};


let inp = prompt("Enter your choice: rock, paper, scissor: ");
console.log(comp(inp));