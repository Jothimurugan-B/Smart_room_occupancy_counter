# Automated Room Occupancy & Smart Lighting Control System

This project implements an intelligent room monitoring system that automatically **counts people entering and exiting** a room and controls **lighting based on real-time occupancy**. It reduces manual monitoring and minimizes energy wastage by ensuring lights turn **ON only when the room is occupied**.

---

## 🔧 Features
- Automatic people counting using IR sensors  
- Smart lighting control based on occupancy  
- Real-time occupancy display on LCD  
- EEPROM data storage using **I²C communication protocol**  
- Built on ARM7 (LPC2129) microcontroller  

---

## 🛠 Technologies Used
- **ARM7 (LPC2129)**
- **IR Sensors**
- **EEPROM (I²C Interface)**
- **LCD Interface**
- **Embedded C**
- **I²C Communication Protocol**

---

## 📂 Repository Contents
- ARM7 (LPC2129) source code  
- I²C-based EEPROM interface  
- Sensor interface code  
- LCD display module  
- Main occupancy & lighting control logic  

---

## 🚀 How It Works
1. IR sensors detect entry/exit events.  
2. The controller updates occupancy count.  
3. Count is stored in EEPROM via **I²C**.  
4. LCD displays the real-time occupancy.  
5. Lights turn **ON if count > 0** and **OFF if count = 0**.

---

## 📘 Applications
- Classrooms  
- Offices  
- Labs  
- Conference halls  
- Smart buildings  

---
