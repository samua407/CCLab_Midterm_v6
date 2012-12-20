
//LED INT
int ledPinGloves = 12;
int ledPinUmbrella = 10;
int ledPinSunnies = 11;
int ledPinDust =
int ledPinPower = 

//SENSOR INT - TEMP
int sensorPinTemp = A0;

//SENSOR INT - SUNNIES
int sensorPinSunnies = A2;      
int sunniesValue = 0;  
int newSunniesValue;

//SENSOR INT - HUMID
float sensorPinHumid = A1;
float humidityValue = 0;
float relHumid = 0;



void setup()
{
  Serial.begin(9600);
  pinMode(ledPinGloves, OUTPUT);
  pinMode (ledPinUmbrella, OUTPUT);
  pinMode (ledPinSunnies, OUTPUT);
  pinMode (sensorPinTemp, INPUT);
  pinMode (sensorPinHumid, INPUT);
  
}
///////////////////////////////////////////////////////////////////////////
void loop()
{
  //while (Serial.available() == 0);
  //int val = Serial.read() - '0';

/////Temp Input - from adafruit tutorial

  // converting reading to voltage
  int readingGloves = analogRead(sensorPinTemp);  
  float voltageGloves = readingGloves * 5.0;
  voltageGloves /= 1024.0; 

  //convert to Celsius
  float temperatureC = (voltageGloves - 0.5) * 100;

  //convert to Fahrenheight
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
  Serial.println(temperatureF);
  
  
  
/////Sunnies Input///////////////////////////////////
  sunniesValue = analogRead(sensorPinSunnies);
  newSunniesValue = map(sunniesValue, 0, 1023, 0, 100);
  //Serial.println(newSunniesValue);



/////Humidity Input - from http://arduino.cc/forum/index.php/topic,19961.0.html#11///////////////////////////////////
  humidityValue = analogRead(sensorPinHumid);
  relHumid = ((((humidityValue/1023)*5)-0.8)/3.1)*100;
  Serial.println(relHumid);

delay(300);





/////Gloves Output///////////////////////////////////
  if (temperatureF <= 45) 
  {
    Serial.println("Don't forget your gloves!"); 
    digitalWrite(ledPinGloves, HIGH);
  }

  if (temperatureF >= 46)
  {
    Serial.println("You don't need gloves.");
    digitalWrite(ledPinGloves, LOW);
  }

/////Umbrella Output///////////////////////////////////
  if (relHumid >= 70)
  {
    Serial.println("Don't forget your umbrella!");
    digitalWrite(ledPinUmbrella, HIGH);
  }

  if (relHumid = 4)
  {
    Serial.println("You don't need an umbrella.");
    digitalWrite(ledPinUmbrella, LOW);
  }

/////Sunnies Output
  if (newSunniesValue >= 20)
  {
    Serial.println("Don't forget your sunnies!");
    digitalWrite(ledPinSunnies, HIGH);
  }

  if (newSunniesValue <= 19)
  {
    Serial.println("You don't need your sunnies.");
    digitalWrite(ledPinSunnies, LOW);
  }
    Serial.flush();

}


