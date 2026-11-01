#pragma once
#include <iostream>
#include <queue>
#include "clsDate.h"
#include <string>
#include <stack>
using namespace std;
class clsQueueLine
{
	struct stMyQueueLine
	{
		string _CodeNumber;
		int _TimeServes=0;
		string _TimeAndDate;
		int WaitingClient = 0;
		int _ClientNumber=1;
		int _TimeNeed=0;
		string _CodePrefix = "";
		int ServedClient = 0;
	};
	int _TotalClient = 0;
	queue<stMyQueueLine >_IssueTicket;
	queue<stMyQueueLine >_TempIssueTicket;
	stMyQueueLine MyQueueLine;
public :
	clsQueueLine(string CodeNumber , int TimeNeed)
	{
		MyQueueLine._CodePrefix = CodeNumber;
		MyQueueLine._TimeNeed = TimeNeed;
	}
	void IssueTicket()
	{
		MyQueueLine._TimeServes = MyQueueLine.WaitingClient * MyQueueLine._TimeNeed;
		MyQueueLine._TimeAndDate = clsDate::GetSystemDateTimeString();
		MyQueueLine.WaitingClient++;
		MyQueueLine._CodeNumber = MyQueueLine._CodePrefix+to_string(MyQueueLine._ClientNumber++);
		_IssueTicket.push(MyQueueLine);
		_TotalClient++;
	}
	void PrintInfo()
	{
		cout << "\n\n\t\t\t-------------------------\n";
		cout << "\t\t\t\t Queue Info\n";
		cout << "\t\t\t-------------------------\n";
		cout << "\t\t\t\t   " << MyQueueLine._CodePrefix<< endl;
		cout << "\t\t\t  Total Ticked   = " << _TotalClient << endl;
		cout << "\t\t\t  Served Client  = " << MyQueueLine.ServedClient << endl;
		cout << "\t\t\t  Waiting Client = " << MyQueueLine.WaitingClient << endl;
		cout << "\t\t\t-------------------------\n\n";
	}
	void PrintTicketsLineRTL()
	{
		if (_IssueTicket.empty())
		{
			return;
		}
		_TempIssueTicket = _IssueTicket;
		cout << "\t\t\tTicket: " ;
		
		for (int i = _TempIssueTicket.size(); i > 0.; i--)
		{
			MyQueueLine = _TempIssueTicket.front();
			cout << MyQueueLine._CodeNumber << "<--";
			_TempIssueTicket.pop();

		}
		cout << endl << endl;
	}
	void PrintTicketsLineLTR()
	{
		
		stack< stMyQueueLine> SectempQueue;
		_TempIssueTicket = _IssueTicket;
		cout << "\t\t\tTicket: ";
		
		if(!_TempIssueTicket.empty())
		{
			while (!_TempIssueTicket.empty())
			{
				SectempQueue.push(_TempIssueTicket.front());
				_TempIssueTicket.pop();
			}
		}
		for (int i = SectempQueue.size(); i >0.; i--)
		{
			MyQueueLine = SectempQueue.top();
			cout <<  MyQueueLine._CodeNumber << "-->";
			SectempQueue.pop();
		}
		cout << endl << endl;
	}
	void PrintAllTickets()
	{

		if (_IssueTicket.empty())
		{
			return;
		}
		_TempIssueTicket=	_IssueTicket;
		for (int i = _IssueTicket.size(); i >0;i--)
		{
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
		 _IssueTicket=_TempIssueTicket;
		 
	}
	bool ServeNextClient()
	{
		if (_IssueTicket.empty())
		{
			return false;
		}
		else {
			_IssueTicket.pop();
			MyQueueLine.ServedClient++;
			MyQueueLine.WaitingClient--;
			return true;
		}
	}
};

