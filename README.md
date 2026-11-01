# Queue Ticket Machine System (C++)

A robust and clean C++ implementation of a **Queue Ticket Management System** using Object-Oriented Programming (OOP) principles, Standard Template Library (STL) queues, and stacks. 

This project simulates real-world queue systems (such as those in banks, hospitals, or service centers) where clients draw tickets, track waiting times, and are served sequentially.

---

## 🚀 Features

- **Ticket Generation (`IssueTicket`):** Automatically generates sequential ticket codes based on a custom prefix (e.g., `A1`, `A2`) and calculates estimated waiting times.
- **Queue Visualization (RTL & LTR):** 
  - `PrintTicketsLineRTL()`: Displays the current queue sequence from right to left.
  - `PrintTicketsLineLTR()`: Uses a temporary `stack` data structure to reverse and display elements from left to right.
- **Detailed Ticket View (`PrintAllTickets`):** Iterates through active tickets to display complete details including timestamps and service times without losing original queue data.
- **Client Service Management (`ServeNextClient`):** Handles serving the next client in line, automatically updating waiting counters and served client metrics.

---

## 🛠️ Code Structure

- **`clsQueueLine` Class:** The core class managing the ticketing logic, queues, stacks, and counters.
- **`stMyQueueLine` Struct:** Internal structure holding individual ticket data:
  - `_CodeNumber`: Full ticket code.
  - `_TimeAndDate`: System timestamp of ticket issuance.
  - `WaitingClient` & `ServedClient`: Real-time tracking counters.
  - `_TimeServes` & `_TimeNeed`: Service time estimation metrics.

---

## 💻 Getting Started

### Prerequisites
- A C++ compiler supporting C++11 or later (MSVC, GCC, Clang).
- Visual Studio or any preferred C++ IDE.

### Installation & Usage
1. Clone the repository:
   ```bash
   git clone [https://github.com/YOUR_USERNAME/Queue-Ticket-Machine.git](https://github.com/YOUR_USERNAME/Queue-Ticket-Machine.git)
