<div align="center">

  # 🎫 Queue Ticket Machine System (C++)

  <p align="center">
    <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
    <img src="https://img.shields.io/badge/Paradigm-OOP-orange?style=for-the-badge" />
    <img src="https://img.shields.io/badge/Data_Structures-Queue_%26_Stack-yellow?style=for-the-badge" />
    <img src="https://img.shields.io/badge/Status-Active-success?style=for-the-badge" />
  </p>

  <p align="center">
    <b>A clean, efficient C++ queue management system simulating real-world ticketing services.</b>
  </p>

</div>

---

## 🚀 Features

- 🎟️ **Automated Ticket Issuance:** Generates sequential codes (e.g., `A1`, `A2`) and calculates real-time estimated waiting times.
- 🔄 **Queue Visualization:**
  - **RTL View:** Displays active tickets in standard sequence.
  - **LTR View:** Leverages a temporary `stack` structure to seamlessly reverse and display elements.
- 📊 **Detailed Insights:** Inspects full ticket metadata (timestamps, waiting clients, served counts) without altering the original queue state.
- 👥 **Client Service Handling:** Automatically updates counters when serving the next client in line.

---

## 🛠️ Code Architecture

| Component | Type | Description |
| :--- | :--- | :--- |
| **`clsQueueLine`** | Class | Core manager handling queues, stacks, and counters. |
| **`stMyQueueLine`** | Struct | Internal data structure storing ticket metadata. |

---

## 💻 Code Example

```cpp
#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main() {
    // Initialize queue line with prefix 'A' and 10 minutes per client
    clsQueueLine QueueA("A", 10);

    // Issue tickets
    QueueA.IssueTicket();
    QueueA.IssueTicket();

    // Print queue info and tickets
    QueueA.PrintInfo();
    QueueA.PrintTicketsLineRTL();

    return 0;
}
