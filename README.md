# Arduino Ultrasonic Radar System (Servo + LCD)

This project is an Arduino-based ultrasonic radar system that rotates an ultrasonic sensor using a servo motor and scans the surroundings.

It detects objects, measures their distance and angle, and displays the values on an I2C LCD. When an object is detected within a threshold distance, a buzzer sounds and an LED turns ON.

---

## 🔧 Hardware Used

- Arduino UNO / Nano
- HC-SR04 Ultrasonic Sensor
- Servo Motor 
- I2C 16x2 LCD Display
- Buzzer
- Red LED + Resistor
- Jumper Wires
- 5V Supply

---

## 📦 Required Libraries

Install from Arduino Library Manager:

- **Servo** (built-in)
- **LiquidCrystal_I2C**

---

## 🔌 Pin Connections (As per Code)

### 🎯 Ultrasonic Sensor

| Sensor Pin | Arduino Pin |
|-------------|-------------|
| TRIG | D9 |
| ECHO | D10 |
| VCC | 5V |
| GND | GND |

---

### 🎯 Servo Motor

| Servo Wire | Arduino |
|-------------|----------|
| Signal (Yellow) | D8 |
| VCC (Red) | 5V *(3.3V also works for small servo)* |
| GND (Brown) | GND |

---

### 📺 I2C LCD

| LCD Pin | Arduino |
|----------|----------|
| SDA | A4 |
| SCL | A5 |
| VCC | 5V |
| GND | GND |

---

### 🔔 Buzzer & LED

| Device | Arduino Pin |
|----------|-------------|
| Buzzer | D12 |
| LED | D13 (via resistor) |

---

## ⚙️ Working Logic

- Servo rotates from **15° to 165°**
- Ultrasonic sensor measures distance at each angle
- LCD displays:
  - Angle
  - Distance
- If distance < **30 cm**:
  - Buzzer turns ON
  - LED turns ON
- Servo scans back and forth continuously

---

## ▶️ How to Run

1. Install required libraries
2. Connect hardware as per wiring table
3. Upload code to Arduino
4. Open Serial Monitor (optional)
5. Power the board
6. Radar scanning starts automatically

---

## 📏 Key Parameters
Scan angle range: 15° to 165°
Alert distance: 30 cm
Servo step delay: 7 ms

You can adjust these values in code.

---

## 📷 Circuit Diagram

Circuit diagram image will be added soon. Wiring table is provided above.

---

## 🎥 Working Video

https://www.youtube.com/shorts/wEA1DX8naTU

---

## ⚠️ Notes

- Use external 5V if servo jitters
- Keep GND common for all modules
- I2C LCD address usually 0x27 (may vary)
- Add resistor with LED
- Mount ultrasonic sensor firmly on servo horn

---

## 👨‍💻 Author

Gautam — Robotics & Embedded Projects
