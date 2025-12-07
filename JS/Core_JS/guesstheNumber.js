/* Simple CLI based game to guess a random generated number (between 1 and 100) */
const input = require("prompt-sync")();
// Backed -->
const generateRandomNumber = () => {
  return Math.floor(Math.random() * 100) + 1;
};

const generateHint = (number, rangeSize) => {
  let halfRange = Math.floor(rangeSize / 2);
  let lowerBound = Math.max(0, number - halfRange); // Avoid going below 0
  let upperBound = Math.min(100, number + halfRange); // Avoid going above 100, as 100 is the maximum number + halfRange;

  return { min: lowerBound, max: upperBound };
};

const calculateScore = (totalChances, usedChances, hintsUsed) => {
  const baseScore = 100;
  const penaltyPerWrongGuess = 6; // aggressive deduction
  const penaltyPerHint = 5; // hints cost bonus points

  let wrongGuesses = totalChances - usedChances;
  let totalPenalty =
    wrongGuesses * penaltyPerWrongGuess + hintsUsed * penaltyPerHint;

  return Math.max(0, baseScore - totalPenalty);
};

// Frontend -->
const playGame = () => {
  let number = generateRandomNumber();
  let rangeSize = 100;
  let chances = 10;

  let affirm = input("Do you want to play? (y/n): ").toLowerCase();

  if (affirm !== "y") {
    console.log("Maybe next time!");
    return;
  }

  console.log("Generating number, your game will start in 3 seconds...");
  setTimeout(() => {
    console.clear();
    gameLoop();
  }, 3000);

  function gameLoop() {
    let totalChances = chances;
    let hintsUsed = 0;

    while (chances--) {
      // console.log("\x1b[2J\x1b[0f"); // ANSI escape codes to clear + move cursor top

      let guess = Number(input("Enter your guess: "));

      if (guess === number) {
        console.log("🎉 You won!");
        let finalScore = calculateScore(totalChances, chances + 1, hintsUsed);
        console.log(`Score: ${finalScore}`);
        return;
      }

      if (chances < 5) {
        let hint = generateHint(number, rangeSize);
        rangeSize = Math.floor(rangeSize / 2);
        hintsUsed++;
        console.log(`Hint: The number is between ${hint.min} and ${hint.max}`);
      }

      console.log(`Chances left: ${chances}`);
    }

    console.log(`😢 You lost! The number was ${number}`);
  }
};

playGame();
