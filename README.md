🎟️ Queue Management System — C++

<p align="center">
<img src="https://capsule-render.vercel.app/api?type=rounded&color=0:141E30,100:243B55&height=180&section=header&text=QUEUE%20MANAGEMENT&fontSize=35&fontColor=ffffff&animation=fadeIn&fontAlignY=45&desc=C%2B%2B%20%7C%20Data%20Structures%20%7C%20OOP&descAlignY=70&descSize=16" width="100%"/>
</p>

<p align="center">
<img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus"/>
<img src="https://img.shields.io/badge/Data%20Structures-Queue-orange?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Data%20Structures-Stack-purple?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Programming-OOP-success?style=for-the-badge"/>
</p>

<p align="center">
<b>A Simple and Efficient Customer Queue Management System Built with C++.</b>
</p>

📌 About The Project

Queue Management System is a C++ project designed to simulate a real-world customer service management system.

It helps organize customer tickets, manage waiting lists, calculate estimated waiting times, and serve customers efficiently.

The project demonstrates the practical use of Object-Oriented Programming (OOP) and fundamental data structures such as Queue and Stack.

✨ Features
Icon	Feature	Description
🎫	Issue Tickets	Generate unique ticket numbers automatically.
⏱️	Waiting Time	Calculate estimated customer waiting time.
📊	Queue Information	Display total, served, and waiting clients.
➡️	RTL Display	Print tickets from right to left.
⬅️	LTR Display	Print tickets from left to right using Stack.
🧾	Print All Tickets	Display complete information for active tickets.
👨‍💼	Serve Next Client	Remove and serve the next customer.
📅	Date & Time	Record the ticket issuance date and time.
🛠️ Technologies Used
C++ — Main programming language.
STL Queue — Managing customer tickets.
STL Stack — Reversing ticket display order.
OOP — Classes, Objects, and Encapsulation.
Date & Time — Using a custom clsDate class.
🧠 Core Concepts
1. Queue — FIFO

The system uses the First In, First Out principle.

The first customer who joins the queue is the first customer served.

2. Stack — LIFO

A temporary Stack is used to reverse the order of tickets when displaying them from Left to Right.

3. Waiting Time Calculation
cpp
WaitingTime = WaitingClients * TimePerClient;

4. Automatic Ticket Generation

Example:

text
A1 → A2 → A3 → A4 → A5


Each ticket receives a unique sequential number.

💻 Main Class
cpp
class clsQueueLine


The project is based on a class responsible for managing the customer queue.

Constructor
cpp
clsQueueLine(string CodeNumber, int TimeNeed);


Initializes the queue prefix and the estimated service time per customer.

Available Methods
Method	Description
IssueTicket()	Generates and adds a new ticket.
PrintInfo()	Displays general queue statistics.
PrintTicketsLineRTL()	Displays tickets Right to Left.
PrintTicketsLineLTR()	Displays tickets Left to Right.
PrintAllTickets()	Prints detailed information for all tickets.
ServeNextClient()	Serves the next customer in the queue.
🚀 Getting Started
Requirements
C++ Compiler (GCC, MinGW, or Visual Studio).
C++11 or later.
Compile
bash
g++ main.cpp -o QueueSystem

Run

Windows:

bash
QueueSystem.exe


Linux / macOS:

bash
./QueueSystem

📂 Project Structure
text
Queue-Management-System/
│
├── main.cpp
├── clsQueueLine.h
├── clsDate.h
└── README.md

🎯 Learning Objectives

Through this project, I practiced:

Understanding Queue and Stack data structures.
Applying FIFO and LIFO principles.
Developing reusable C++ classes.
Applying Object-Oriented Programming.
Managing customer tickets.
Calculating estimated waiting times.
Working with STL containers.
Organizing real-world service workflows.
🔮 Future Improvements
Add multiple service lines.
Add ticket cancellation.
Improve waiting-time updates after serving customers.
Add priority queues.
Save ticket information to files.
Create a graphical user interface (GUI).
👨‍💻 Author

Your Name

<p align="center">
<img src="https://img.shields.io/badge/Made%20With-❤️%20%26%20C%2B%2B-red?style=for-the-badge"/>
</p>

<p align="center">
⭐ If you find this project useful, consider giving it a star!
</p>

<p align="center">
<i>Keep Learning. Keep Building. Keep Improving.</i>
</p>

<p align="center">
© 2026 Queue Management System | C++
</p>
