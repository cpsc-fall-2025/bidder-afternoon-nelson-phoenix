#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// INSTRUCTIONS
// ============================================================================
// 1. Implement the three functions below.
// 2. You may use the main() function at the bottom to test your code locally.
// 3. Do not change the function signatures.
// ============================================================================

// DONE Implement this function to return a vector of strings
// containing the names of everyone on your team.
std::vector<std::string> GetTeamMembers() {
  std::vector<std::string> names{"Nelson Vargas", "Phoenix Castillo"};
  return names;
}

// DONE Implement this function to return a string that describes
// the strategy your logic uses to bid (e.g., "We bid high early on").
std::string GetStrategy() {
  return "We divide the number of rounds by three, we divide the budget evenly "
         "between that middle of the three round divisions, leftover gets "
         "dumped at the beginning of the last division\n";
}

// DONE Implement the bidding logic.
// parameters:
//   rounds: The total number of rounds in the game.
//   budget: The total points available to spend across all rounds.
//   output_filename: The name of the file where the bids should be written.
//
// Logic:
//   1. Calculate how much to bid in each round.
//   2. Open 'output_filename' for writing.
//   3. Write the bid for each round on a new line in the file.
//
// Constraints:
//   - You must write exactly 'rounds' number of lines.
//   - The sum of all bids must not exceed 'budget'.
//   - Bids must be non-negative integers.
void GenerateBids(int rounds, int budget, std::string output_filename) {
  std::ofstream file{output_filename};
  int rnd_div{rounds / 3};
  int index{1};
  int bids{budget / rnd_div};
  for (; index <= rnd_div; index++) {
    file << 0 << "\n";
  }
  for (; index <= rnd_div * 2; index++) {
    file << bids << "\n";
    budget -= bids;
    if (rounds % 3 == 1 && index == rnd_div * 2) {
      file << budget << "\n";
      budget = 0;
    } else if (rounds % 3 == 2 && index == rnd_div * 2) {
      bids = budget / 2;
      file << bids << "\n";
      file << bids << "\n";
      budget = 0;
    }
  }
  for (; index <= rnd_div * 3; index++) {
    file << 0 << "\n";
  }
}

// ============================================================================
// MAIN FUNCTION
// Use this to test your code.
// This function will be ignored by the "make test" command.
// ============================================================================
int main() {
  // You can write code here to call your functions and see if they work.
  // Example:
  // GenerateBids(10, 100, "test_output.txt);
  GenerateBids(100, 100, "test_output.txt");
  return 0;
}
