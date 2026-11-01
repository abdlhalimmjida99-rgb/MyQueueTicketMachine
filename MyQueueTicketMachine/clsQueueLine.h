#pragma once
#include <iostream>
#include <queue>
#include "clsDate.h"
#include <string>
#include <stack>
using namespace std;

class clsQueueLine
{
private:
	// Structure to hold ticket and client information
	struct stMyQueueLine
	{
		string _CodeNumber;     // Full ticket code (e.g., A1, A2...)
		int _TimeServes = 0;    // Expected service time for the client
		string _TimeAndDate;    // Ticket issue date and time
		int WaitingClient = 0;  // Current number of waiting clients
		int _ClientNumber = 1;  // Sequential number for the next client
		int _TimeNeed = 0;      // Time required per client
		string _CodePrefix = "";// Line prefix symbol (e.g., A or B)
		int ServedClient = 0;   // Number of clients already served
	};

	int _TotalClient = 0;               // Total number of issued tickets
	queue<stMyQueueLine> _IssueTicket;     // Original queue holding client tickets
	queue<stMyQueueLine> _TempIssueTicket; // Temporary queue used for operations like printing without losing data
	stMyQueueLine MyQueueLine;             // Temporary object of the struct to handle current data

public:
	// 1. Constructor: Initializes the line prefix and time needed per client
	clsQueueLine(string CodeNumber, int TimeNeed)
	{
		MyQueueLine._CodePrefix = CodeNumber;
		MyQueueLine._TimeNeed = TimeNeed;
	}

	// 2. IssueTicket Method: Creates a new ticket and pushes it to the queue
	void IssueTicket()
	{
		MyQueueLine._TimeServes = MyQueueLine.WaitingClient * MyQueueLine._TimeNeed; // Calculate waiting time
		MyQueueLine._TimeAndDate = clsDate::GetSystemDateTimeString();            // Record current system date and time
		MyQueueLine.WaitingClient++;                                               // Increment waiting clients count
		MyQueueLine._CodeNumber = MyQueueLine._CodePrefix + to_string(MyQueueLine._ClientNumber++); // Build ticket code
		_IssueTicket.push(MyQueueLine);                                            // Add ticket to the queue
		_TotalClient++;                                                            // Increment total tickets count
	}

	// 3. PrintInfo Method: Prints general queue statistics
	void PrintInfo()
	{
		cout << "\n\n\t\t\t-------------------------\n";
		cout << "\t\t\t\t Queue Info\n";
		cout << "\t\t\t-------------------------\n";
		cout << "\t\t\t\t   " << MyQueueLine._CodePrefix << endl;
		cout << "\t\t\t  Total Ticked   = " << _TotalClient << endl;
		cout << "\t\t\t  Served Client  = " << MyQueueLine.ServedClient << endl;
		cout << "\t\t\t  Waiting Client = " << MyQueueLine.WaitingClient << endl;
		cout << "\t\t\t-------------------------\n\n";
	}

	// 4. PrintTicketsLineRTL Method: Prints tickets line from Right to Left using a temporary queue
	void PrintTicketsLineRTL()
	{
		if (_IssueTicket.empty()) // Exit if the queue is empty
		{
			return;
		}
		_TempIssueTicket = _IssueTicket; // Copy original queue to temp queue to preserve it
		cout << "\t\t\tTicket: ";

		for (int i = _TempIssueTicket.size(); i > 0; i--)
		{
			MyQueueLine = _TempIssueTicket.front();
			cout << MyQueueLine._CodeNumber << "<--";
			_TempIssueTicket.pop(); // Remove printed item from the temporary queue only
		}
		cout << endl << endl;
	}

	// 5. PrintTicketsLineLTR Method: Prints tickets line from Left to Right using a temporary stack to reverse order
	void PrintTicketsLineLTR()
	{
		stack<stMyQueueLine> SectempQueue; // Temporary stack to reverse elements order
		_TempIssueTicket = _IssueTicket;
		cout << "\t\t\tTicket: ";

		if (!_TempIssueTicket.empty())
		{
			while (!_TempIssueTicket.empty()) // Push elements to stack to automatically reverse them (LIFO)
			{
				SectempQueue.push(_TempIssueTicket.front());
				_TempIssueTicket.pop();
			}
		}
		for (int i = SectempQueue.size(); i > 0; i--)
		{
			MyQueueLine = SectempQueue.top();
			cout << MyQueueLine._CodeNumber << "-->";
			SectempQueue.pop();
		}
		cout << endl << endl;
	}

	// 6. PrintAllTickets Method: Prints full details of all active tickets
	void PrintAllTickets()
	{
		if (_IssueTicket.empty())
		{
			return;
		}
		_TempIssueTicket = _IssueTicket;

		for (int i = _IssueTicket.size(); i > 0; i--)
		{
			// Note: Popping directly from _IssueTicket requires restoring it later from _TempIssueTicket
			MyQueueLine = _IssueTicket.front();

			cout << "\n\n\t\t\t    - - -Ticket- - -\n";
			cout << "\t\t\t-------------------------\n\n";
			cout << "\t\t\t\t  " << MyQueueLine._CodeNumber << endl << endl;
			cout << "\t\t\t" << MyQueueLine._TimeAndDate << endl;
			cout << "\t\t\tWaiting Client = " << MyQueueLine.WaitingClient << endl;
			cout << "\t\t\tServer Time In ";
			cout << "\t" << MyQueueLine._TimeServes << " Minutes \n";
			cout << "\t\t\t-------------------------\n\n";
			_IssueTicket.pop();
		}
		_IssueTicket = _TempIssueTicket; // Restore original queue elements so they are not lost
	}

	// 7. ServeNextClient Method: Removes the next client in line and updates counters
	bool ServeNextClient()
	{
		if (_IssueTicket.empty()) // Return false if no clients are left in the queue
		{
			return false;
		}
		else {
			_IssueTicket.pop();          // Remove the front client from the queue (service provided)
			MyQueueLine.ServedClient++;  // Increment served clients count
			MyQueueLine.WaitingClient--; // Decrement waiting clients count
			return true;
		}
	}
};