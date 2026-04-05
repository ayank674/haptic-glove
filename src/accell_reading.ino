#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

// Complementary filter variables
float roll = 0, pitch = 0;      // Fused angles
const float alpha = 0.98;       // Gyro weight
unsigned long lastTime = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) delay(10);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("MPU6050 ready!");

  lastTime = millis();
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0; // time delta in seconds
  lastTime = now;

  //Accel roll and pitch calc
  float rollAcc = atan2(a.acceleration.y, 
                sqrt(a.acceleration.x*a.acceleration.x + a.acceleration.z*a.acceleration.z)) * 180.0 / PI;
  float pitchAcc = atan2(-a.acceleration.x, 
                         sqrt(a.acceleration.y*a.acceleration.y + a.acceleration.z*a.acceleration.z)) 
                         * 180.0 / PI;

  //Gyro Integration
  float rollGyro  = roll + g.gyro.x * dt * 180.0 / PI;
  float pitchGyro = pitch + g.gyro.y * dt * 180.0 / PI;

  //Gyro+accel contribution
  roll  = alpha * rollGyro  + (1.0 - alpha) * rollAcc;
  pitch = alpha * pitchGyro + (1.0 - alpha) * pitchAcc;

  //Gravity to account for
  float gx = 9.81 * sin(pitch * PI/180.0);
  float gy = -9.81 * sin(roll * PI/180.0) * cos(pitch * PI/180.0);
  float gz = 9.81 * cos(roll * PI/180.0) * cos(pitch * PI/180.0);

  float linAccX = a.acceleration.x - gx-1.22;
  float linAccY = a.acceleration.y - gy;
  float linAccZ = a.acceleration.z - gz+0.96;

  //Print time
  Serial.print("Roll: "); Serial.print(roll, 2);
  Serial.print("  Pitch: "); Serial.print(pitch, 2);
  Serial.print("  LinAccX: "); Serial.print(linAccX, 2);
  Serial.print("  LinAccY: "); Serial.print(linAccY, 2);
  Serial.print("  LinAccZ: "); Serial.println(linAccZ, 2);

  delay(10); // ~100 Hz
}