# ENGR103-reaction_game

## Game Descritption
In Reaction Time Challenge, players put their reflexes to the test in a fast-paced game of reaction time. The game aims to measure how quickly players can respond to a visual cue by pressing either A or B button. With each round, the pressure builds as players strive to beat their previous record and achieve lightning-fast reaction times.

### Rules
Game Start:
The game starts by turning on the NeoPixel LED, indicating that a round is about to begin.
Reacting to the Cue:

The NeoPixel LED turns off at random intervals, acting as a visual cue for the player to react.
Players must quickly press either Button A or Button B as soon as the LED turns off.

Scoring:
If the correct button is pressed within the designated time frame, the buzzer sounds, indicating a successful reaction.
Players receive one point for each successful reaction.
If the time frame elapses or the wrong button is pressed, the buzzer sounds to indicate a failed reaction, and no points are awarded.

Rounds:
The game consists of a predetermined number of rounds (e.g., 10 rounds).
After each round, the game proceeds to the next round, maintaining the score achieved in previous rounds.

Final Score:
At the end of the game (after completing all rounds), the final score is displayed.
The final score represents the total number of successful reactions achieved throughout the game.

Game Reset:
To start a new game, players can restart the program or press a dedicated reset button.
The objective of the Reaction Time Challenge is to achieve the highest possible score by reacting quickly and accurately to visual cues. Players can compete against themselves or challenge friends to beat their reaction time scores.

#### Inputs and Outputs
Button A: This button is assigned to control the "Reaction A" action.
Button B: This button is assigned to control the "Reaction B" action.
Sensors Used:

NeoPixel LED: The NeoPixel LED serves as a visual cue for the player to react. Its function is to turn on and off at random intervals.
Buzzer: The buzzer produces sound feedback, indicating a successful or failed reaction.
Raw Ranges and Mapping:
