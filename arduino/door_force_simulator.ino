/*
  Regional Door Force Simulator
  Accounts for wind patterns in 4 Indian regions + manual force input
*/

// Region-wise base wind forces (N)
const float REGIONS[4][2] = {
  {1, 50.0},  // Western Coastal (High wind)
  {2, 40.0},  // Eastern Himalayan Foothills
  {3, 30.0},  // North Indian Plains
  {4, 10.0}   // Deccan Plateau (Low wind)
};

// Entity thresholds (Total force = Wind + Manual)
const float COW = 1000.0;
const float GOAT = 300.0;
const float DOG = 215.0;
const float ANGRY = 180.0;
const float HAPPY = 75.0;
const float CAT = 50.0;
const float CHILD_SAD = 30.0;
const float ELDERLY = 20.0;

// Door constants
const float DOOR_INERTIA = 20.0;  // kg·m²
const float DOOR_WIDTH = 1.0;     // meters
const float MAX_ANGLE = 90.0;     // degrees

float regionalWind = 0.0;

void setup() {
  Serial.begin(9600);
  printRegionMenu();
}

void loop() {
  if (!regionalWind) {
    handleRegionSelection();
  } else {
    handleForceInput();
  }
  delay(100);
}

void printRegionMenu() {
  Serial.println("\nSelect Indian Region:");
  Serial.println("1. Western Coastal (High wind)");
  Serial.println("2. Eastern Himalayan Foothills");
  Serial.println("3. North Indian Plains");
  Serial.println("4. Deccan Plateau (Low wind)");
  Serial.print("Enter choice (1-4): ");
}

void handleRegionSelection() {
  if (Serial.available() > 0) {
    int choice = Serial.parseInt();
    if (choice >= 1 && choice <= 4) {
      regionalWind = REGIONS[choice-1][1];
      Serial.print("\nSelected Region ");
      Serial.print(choice);
      Serial.print(" - Base wind force: ");
      Serial.print(regionalWind, 1);
      Serial.println("N");
      Serial.println("Enter manual force (N):");
    } else {
      Serial.println("Invalid region! Try again.");
      printRegionMenu();
    }
    while(Serial.available()) Serial.read(); // Clear buffer
  }
}

void handleForceInput() {
  if (Serial.available() > 0) {
    float manualForce = Serial.parseFloat();
    Serial.read(); // Clear newline
    
    if (manualForce <= 0 || manualForce > 1000) {
      Serial.println("Error: Enter 0-1000N");
    } else {
      float totalForce = regionalWind + manualForce;
      processForce(totalForce);
    }
    Serial.println("\nEnter new manual force (N):");
  }
}

void processForce(float totalForce) {
  float angle = calculateAngle(totalForce);
  String entity = identifyEntity(totalForce);
  
  Serial.print("Total Force: ");
  Serial.print(totalForce, 1);
  Serial.print("N (Wind: ");
  Serial.print(regionalWind, 1);
  Serial.print("N + Manual: ");
  Serial.print(totalForce - regionalWind, 1);
  Serial.print("N) → Door angle: ");
  Serial.print(angle, 1);
  Serial.print("° → Entity: ");
  Serial.println(entity);
}

float calculateAngle(float force) {
  float angle = (0.5 * (force * DOOR_WIDTH) / DOOR_INERTIA) * (180.0/PI);
  return min(angle, MAX_ANGLE);
}

String identifyEntity(float totalForce) {
  if (totalForce >= COW)        return "Cow";
  if (totalForce >= GOAT)       return "Goat";
  if (totalForce >= DOG)        return "Dog";
  if (totalForce >= ANGRY)      return "Angry person";
  if (totalForce >= HAPPY)      return "Happy person";
  if (totalForce >= CAT)        return "Cat";
  if (totalForce >= CHILD_SAD)  return "Child/Sad person";
  if (totalForce >= ELDERLY)    return "Elderly person";
  return "Unknown";
}
