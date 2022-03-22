//by Changwen
#define R_EN  10
#define R1     9
#define R2     8

#define L_EN   5
#define L1     7
#define L2     6
 
#define slow 64
#define normal 128
#define fast 255
 
int Speed; 
 
void Forward(void){
  analogWrite(R_EN, Speed);
  analogWrite(L_EN, Speed);
  digitalWrite(R1, HIGH);
  digitalWrite(R2 , LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2 , LOW);
}
 
void Backward(void){
  analogWrite(R_EN, Speed);
  analogWrite(L_EN, Speed);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
}

/*
 * This class controls the movement of the robot
 * At each tick, we register turns and if we move or not. Then, the method void Update() should be called.
*/
class Movement
{
public:
  /*
   * This simply constructs the object
  */
  Movement();
  /*
   * Move forward and turn the amount needed. m_AmountToTurn is then reset to 0
  */
  void Update();
  /*
   * Register a turn for the robot.
   * If degree > 0, we turn to the left (trigonometric direction)
   * If degree < 0, we turn to the right (anti-trigonometric direction)
  */
  void Turn(int degree);
  void StartMoving();
  void StopMoving();
private:
  int m_AmountToTurn;
};

void Turnright(void){
  analogWrite(R_EN, Speed);
  analogWrite(L_EN, Speed);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
}
 

void Turnleft(void){
  analogWrite(R_EN, Speed);
  analogWrite(L_EN, Speed);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);

}
void setup() {
  
  Serial.begin(9600);
  pinMode(R_EN, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}
 
void loop() {

  Speed=normal; // Normal Speed
  Turnleft();
  delay(3000);
}
