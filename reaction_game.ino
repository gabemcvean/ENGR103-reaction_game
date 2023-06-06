#include <Adafruit_CircuitPlayground.h>

int score = 0;
int rounds = 10;
bool gameActive = false;

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(10);  // Set brightness to a lower value (0-255)
  Serial.begin(9600);
  
  startGame();
}

void loop() {
  if (gameActive) {
    if (CircuitPlayground.leftButton()) {
      handleReaction('A', true);
    } else if (CircuitPlayground.rightButton()) {
      handleReaction('B', true);
    }
  }
}

void startGame() {
  score = 0;
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(0, 255, 0, 0);  // Red color to indicate game start
  
  delay(2000);  // Wait for 2 seconds
  
  for (int i = 0; i < rounds; i++) {
    playRound(i + 1);
  }
  
  endGame();
}

void playRound(int roundNumber) {
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(0, 0, 255, 0);  // Green color to indicate round start
  
  delay(random(500, 2000));  // Random delay between 0.5 and 2 seconds
  CircuitPlayground.clearPixels();
  
  long startTime = millis();
  bool buttonPressed = false;
  
  while (millis() - startTime < 1500) {  // 1.5 seconds time frame to react
    if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) {
      buttonPressed = true;
      break;
    }
  }
  
  if (buttonPressed) {
    if (score < rounds) {
      handleReaction(chooseCorrectButton(), true);  // Correct reaction, all LEDs light up green
      score++;
    }
  } else {
    handleReaction('X', false);  // Failed reaction, all LEDs light up red
  }
  
  Serial.print("Round ");
  Serial.print(roundNumber);
  Serial.print(": Score=");
  Serial.println(score);
  
  delay(2000);  // Delay between rounds
}

void endGame() {
  gameActive = false;
  
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(0, 255, 255, 255);  // White color to indicate game end
  
  Serial.print("Final Score: ");
  Serial.println(score);
  
  if (score == rounds) {
    CircuitPlayground.playTone(262, 250);  // Play "Mario win" sound
  }
  
  delay(5000);  // Wait for 5 seconds before restarting the game
  startGame();
}

void handleReaction(int reaction, bool correct) {
  if (correct) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);  // Set all LEDs to green for correct reaction
    }
    CircuitPlayground.playTone(1000, 200);  // Beep to indicate successful reaction
    delay(200);  // Delay to keep LEDs on briefly
    CircuitPlayground.clearPixels();  // Turn off LEDs
  } else {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 255, 0, 0);  // Set all LEDs to red for failed reaction
    }
    CircuitPlayground.playTone(500, 1000);  // Longer beep to indicate failed reaction
    delay(200);  // Delay to keep LEDs on briefly
    CircuitPlayground.clearPixels();  // Turn off LEDs
  }
}

int chooseCorrectButton() {
  return random(2) == 0 ? 'A' : 'B';  // Randomly choose Button A or Button B as the correct button
}
