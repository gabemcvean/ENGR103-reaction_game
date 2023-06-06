#include <Adafruit_CircuitPlayground.h>

int score = 0;
int rounds = 10;
bool gameActive = false;

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(10); 
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
  CircuitPlayground.setPixelColor(0, 255, 0, 0); 
  
  delay(2000);  
  
  for (int i = 0; i < rounds; i++) {
    playRound(i + 1);
  }
  
  endGame();
}

void playRound(int roundNumber) {
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(0, 0, 255, 0);  
  
  delay(random(500, 2000));  
  CircuitPlayground.clearPixels();
  
  long startTime = millis();
  bool buttonPressed = false;
  
  while (millis() - startTime < 1500) {  
    if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) {
      buttonPressed = true;
      break;
    }
  }
  
  if (buttonPressed) {
    if (score < rounds) {
      handleReaction(chooseCorrectButton(), true); 
      score++;
    }
  } else {
    handleReaction('X', false);  
  }
  
  Serial.print("Round ");
  Serial.print(roundNumber);
  Serial.print(": Score=");
  Serial.println(score);
  
  delay(2000);  
}

void endGame() {
  gameActive = false;
  
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(0, 255, 255, 255); 
  
  Serial.print("Final Score: ");
  Serial.println(score);
  
  if (score == rounds) {
    CircuitPlayground.playTone(262, 250); 
  }
  
  delay(5000);  
  startGame();
}

void handleReaction(int reaction, bool correct) {
  if (correct) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);  
    }
    CircuitPlayground.playTone(1000, 200);
    delay(200);  
    CircuitPlayground.clearPixels(); 
  } else {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 255, 0, 0);  
    }
    CircuitPlayground.playTone(500, 1000);  
    delay(200);  
    CircuitPlayground.clearPixels();  
  }
}

int chooseCorrectButton() {
  return random(2) == 0 ? 'A' : 'B';  
}
