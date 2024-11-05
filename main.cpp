#include <Arduino.h>

// Definire pini pentru butoane și LED-uri
#define BUTTON_START 2            
#define BUTTON_DIFFICULTY 3       
#define LED_PIN_RED 9             
#define LED_PIN_GREEN 10          
#define LED_PIN_BLUE 11           

// Enum pentru niveluri de dificultate
enum DifficultyLevel { EASY, MEDIUM, HARD };

// Variabile globale pentru starea jocului
int score = 0;                      
String targetWord;                  
bool isGameRunning = false;        
unsigned long gameStartTime;        
unsigned long roundTimeLimit = 30000;
DifficultyLevel gameDifficulty = EASY;

// Prototipuri funcții
void initializeLED(int red, int green, int blue);
void displayNextWord();
void toggleGameState();
void beginGame();
void terminateGame();
void updateDifficulty();
void startCountdown();

// Setup inițial
void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_START, INPUT_PULLUP);
    pinMode(BUTTON_DIFFICULTY, INPUT_PULLUP);
    pinMode(LED_PIN_RED, OUTPUT);
    pinMode(LED_PIN_GREEN, OUTPUT);
    pinMode(LED_PIN_BLUE, OUTPUT);
    
    attachInterrupt(digitalPinToInterrupt(BUTTON_START), toggleGameState, FALLING);
    attachInterrupt(digitalPinToInterrupt(BUTTON_DIFFICULTY), updateDifficulty, FALLING);
    
    initializeLED(255, 255, 255);  // Setare LED pe alb (stare inactivă)
    Serial.println("Apasă butonul de start pentru a începe jocul.");
}

void loop() {
    if (isGameRunning) {
        unsigned long currentTime = millis();
        
        if (currentTime - gameStartTime >= roundTimeLimit) {
            terminateGame();
        } else if (Serial.available()) {
            String input = Serial.readStringUntil('\n');
            input.trim();
            
            if (input.equalsIgnoreCase(targetWord)) {
                score++;
                Serial.println("Corect!");
                initializeLED(0, 255, 0); // LED verde pentru corect
                displayNextWord();
            } else {
                Serial.println("Greșit! Încearcă din nou.");
                initializeLED(255, 0, 0); // LED roșu pentru greșit
            }
        }
    }
}

// Funcție pentru numărătoare inversă cu clipire LED
void startCountdown() {
    for (int i = 3; i > 0; i--) {
        Serial.println(i);
        initializeLED(255, 255, 255); // LED alb
        delay(2500);                   
        initializeLED(0, 0, 0);       
        delay(2500);                   
    }
    initializeLED(0, 255, 0); // LED verde când runda începe
}

// Schimbă dificultatea jocului
void updateDifficulty() {
    delay(50); // Debouncing
    
    gameDifficulty = (gameDifficulty == HARD) ? EASY : static_cast<DifficultyLevel>(gameDifficulty + 1);
    
    Serial.print("Nivel de dificultate selectat: ");
    switch (gameDifficulty) {
        case EASY: Serial.println("Ușor"); break;
        case MEDIUM: Serial.println("Mediu"); break;
        case HARD: Serial.println("Dificil"); break;
    }
}

// Activează sau dezactivează starea jocului
void toggleGameState() {
    delay(50); // Debouncing
    
    if (isGameRunning) {
        terminateGame();
    } else {
        beginGame();
    }
}

// Începe jocul
void beginGame() {
    score = 0;
    isGameRunning = true;
    gameStartTime = millis();
    
    Serial.println("Runda începe...");
    startCountdown();
    displayNextWord();
}

// Termină jocul
void terminateGame() {
    isGameRunning = false;
    initializeLED(255, 255, 255); // LED alb
    Serial.print("Runda s-a încheiat! Scorul tău este: ");
    Serial.println(score);
}

// Afișează următorul cuvânt țintă
void displayNextWord() {
    String wordList[] = {"vibe", "yeet", "simp", "sus", "no cap", "bussin", "bet", "slay", "periodt", "snatched", "drip", "fam", "finna", "lit", "mood", "savage", "stan", "lowkey", "highkey", "flex", "ghosted", "big yikes", "slaps", "goat", "spill the tea"};
    int randomIndex = random(0, 20);
    targetWord = wordList[randomIndex];
    
    Serial.print("Scrie cuvântul: ");
    Serial.println(targetWord);
}

// Setează culoarea LED-ului RGB
void initializeLED(int red, int green, int blue) {
    analogWrite(LED_PIN_RED, red);
    analogWrite(LED_PIN_GREEN, green);
    analogWrite(LED_PIN_BLUE, blue);
}