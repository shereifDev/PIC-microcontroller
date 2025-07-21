

# The Embedded Chamber ⚙️

"The Embedded Chamber" is an interactive escape room game built on an PIC18 microcontroller. It's a fun and challenging project designed to make learning embedded systems a hands-on experience involving logic, imagination, and engineering.

---

## 📖 Story

You are trapped in a high-tech electronic chamber. Your only path to freedom is to solve a series of interactive electronic puzzles. An LCD screen will be your guide, and a keypad will be your interface to the system. Every success brings you closer to escaping, but every mistake introduces new challenges.

---

## 🎮 Gameplay & Puzzle Stages

The game consists of six distinct stages that you must solve sequentially to escape.

### Stage 1: Logic Gate Puzzle

* **Objective:** Solve a logic equation shown on the LCD (e.g., `1 AND 0 = ?`).
* **Player Action:** Enter the correct binary answer (0 or 1) using the keypad.
* **Feedback:**

  * **Correct:** The LCD displays "Correct".
  * **Wrong:** A buzzer beeps, and the next stage becomes more difficult.

### Stage 2: Power Bridge

* **Objective:** The LCD will display the instruction "Light only GREEN".
* **Player Action:** Use three switches, each controlling a different colored LED, to fulfill the instruction.
* **Feedback:**

  * **Correct:** The green LED turns on.
  * **Wrong:** All LEDs flash, and the buzzer sounds an alert.

### Stage 3: Motor Lock Challenge

* **Objective:** The LCD displays an "encrypted" angle as a math problem (e.g., Angle = 180-90).
* **Player Action:** Solve the equation and enter the resulting angle via the keypad.
* **Feedback:**

  * **Correct:** A motor, simulating a lock, rotates to the correct angle.
  * **Wrong:** The motor rotates in the opposite direction, providing confusing feedback.

### Stage 4: 7-Segment Math Gate

* **Objective:** Solve a simple math problem shown on the LCD (e.g., `7+2=?`).
* **Player Action:** Enter the result on the keypad.
* **Feedback:**

  * **Correct:** The 7-segment display shows the result, and the LCD confirms "Access Code Accepted". A hint for the next stage is revealed.
  * **Wrong:** The 7-segment display shows a random incorrect digit to confuse the player.

### Stage 5: Relay Puzzle (Cooling System)

* **Objective:** The LCD prompts you to enter a 4-digit "Coolant Code".
* **Player Action:** Enter the correct code, which was displayed as an encrypted hint in a previous stage.
* **Feedback:**

  * **Correct:** A relay activates, simulating the cooling system turning on.
  * **Wrong:** The LCD shows "Overheat! Retry".

### Stage 6: Final Gate (Mixed Logic)

* **Objective:** Solve the final puzzle by calculating a code based on your journey.
* **Player Action:** Enter the code derived from the formula `CODE = A + S + L`, where:

  * `A` is the number of currently lit LEDs.
  * `S` is the motor's angle from Stage 3 divided by 30.
  * `L` is the last key you pressed to solve the previous puzzle.
* **Feedback:**

  * **Correct:** The LCD displays "YOU ESCAPED THE CHAMBER".
  * **Wrong:** The LCD displays "System Resetting...".

---

## 🔌 Hardware Requirements

* **Microcontroller:** PIC18F4620
* **Display:** LCD Screen
* **Input:** Keypad and Switches
* **Output:** LEDs (Red, Green, Blue), Buzzer, Motor, 7-Segment Display, Relay

---

## 💻 Implementation Details

* **State Management:** The game's progress is tracked using a state machine. Progress variables are stored in RAM.
* **Input Handling:** All hardware interactions are managed via polling.
* **Design Philosophy:** The project is built with a modular design, with each stage developed and tested separately to ensure reliability and reusability.


