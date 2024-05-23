#include "main.h"

void setup()
{
  Serial.begin(9600);
  pinMode(RelayPin, OUTPUT);
  lcd.begin(lcdNumCols, lcdLine);
  lcd.clear();
  lcd.print("Batery status");
  lcd.setCursor(0, 1);
  lcd.print("Temperature");
  delay(2000);
  lcd.clear();
  dht.begin();

  for (int i = 0; i < DeviceCount; i++)
  {
    ExtantionDevice *t = devices.GetForInitDevice();
    if (t->GetPin() != UINT8_MAX)
    {
      pinMode(t->GetPin(), OUTPUT);
      devices.SetupOffedCount(-1);
      digitalWrite(t->GetPin(), HIGH);
      t->SetupEnable(true);
    }
  }

  pinMode(BuzzerPin, OUTPUT);
}

void loop()
{
  int inpuValue0 = analogRead(A0);
  double voltage0 = (map(inpuValue0, 0, 1023, 0, sensor_max) + offset) / 100;
  float temp = dht.readTemperature();
  TemperatureStatus t = getTemperatureStatus(temp);
  if (lastStatus != t || lastVoltage != voltage0)
  {
    Serial.println(voltage0);
    if (voltage0 > 12.0 || voltage0 < 9.0)
    {
      for (int i = 0; i < DeviceCount; i++)
      {
        ExtantionDevice *dev = devices.GetNextPriorityForOff();
        if (dev->GetIsEnable())
        {
          dev->SetupEnable(false);
          digitalWrite(dev->GetPin(), LOW);
          devices.SetupOffedCount(1);
        }
      }

      tone(BuzzerPin, 1000);
      delay(500);
      noTone(BuzzerPin);
    }
    else if (voltage0 >= 11 && voltage0 <= 12)
    {
      for (int i = 0; i < devices.GetOffedCount(); i++)
      {
        ExtantionDevice *dev = devices.GetDeviceByPriorityOn();
        if (!dev->GetIsEnable())
        {
          dev->SetupEnable(true);
          digitalWrite(dev->GetPin(), HIGH);
          devices.SetupOffedCount(-1);
        }
      }

      tone(BuzzerPin, 1000);
      delay(500);
      noTone(BuzzerPin);
    }
    else if (voltage0 >= 10 && voltage0 < 11)
    {

      for (int i = 0; i < devices.GetOffedCount(); i++)
      {
        ExtantionDevice *dev = devices.GetDeviceByPriorityOn();
        if (dev->GetPin() != UINT8_MAX && !dev->GetIsEnable())
        {
          dev->SetupEnable(true);
          digitalWrite(dev->GetPin(), HIGH);
          devices.SetupOffedCount(-1);
        }
      }

      ExtantionDevice *dev = devices.GetNextPriorityForOff();
      digitalWrite(dev->GetPin(), LOW);
      dev->SetupEnable(false);
      devices.SetupOffedCount(1);

      tone(BuzzerPin, 1000);
      delay(500);
      noTone(BuzzerPin);
    }
    else if (voltage0 >= 9 && voltage0 < 10)
    {
      for (int i = 0; i < DeviceCount; i++)
      {
        ExtantionDevice *dev = devices.GetNextPriorityForOff();
        if (dev->GetPin() != UINT8_MAX && !dev->GetIsEnable())
        {
          dev->SetupEnable(false);
          digitalWrite(dev->GetPin(), LOW);
          devices.SetupOffedCount(1);
        }
      }

      ExtantionDevice *dev = devices.GetDeviceByPriorityOn();
      dev->SetupEnable(true);
      digitalWrite(dev->GetPin(), HIGH);
      devices.SetupOffedCount(-1);

      tone(BuzzerPin, 1000);
      delay(500);
      noTone(BuzzerPin);
    }

    lcd.clear();
    lcd.print("Batery Temperature:");
    lcd.setCursor(0, 1);  
    lcd.print(read(t) + String((char)58) + String(temp) + String((char)223) + "C") ;
    lcd.setCursor(0, 2);
    lcd.print("Voltage - " + String(voltage0) + "V");

    if (lastStatus != t && t == TemperatureStatus::Critical)
    {
      tone(BuzzerPin, 5000);
      delay(1000);
      noTone(BuzzerPin);
    }

    lastStatus = t;
    lastVoltage = voltage0;
  }
  if (lastStatus == TemperatureStatus::Medium || lastStatus == TemperatureStatus::Critical)
  {
    if (!isCoolerOn)
    {
      digitalWrite(RelayPin, HIGH);
      isCoolerOn = true;
    }
    lcd.setCursor(0, 3);
    lcd.print("Coller is ON");
  }
  else
  {
    digitalWrite(RelayPin, LOW);
    isCoolerOn = false;
    lcd.setCursor(0, 3);
    lcd.print("Coller is OFF");
  }

  delay(1000);
}

String read(TemperatureStatus status)
{
   if(status == TemperatureStatus::Low){
      return String("Low");
   }
   else if(status == TemperatureStatus::Medium){
      return String("Medium");
   }
   else if(status == TemperatureStatus::Critical){
      return String("Critical");
   }
   return String();
}