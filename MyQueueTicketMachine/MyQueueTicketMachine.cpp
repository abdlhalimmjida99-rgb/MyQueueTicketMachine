//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main()
{

    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    cout << "\nPay Bills Queue Info:\n";
    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsLineLTR();
    PayBillsQueue.PrintTicketsLineRTL();

    PayBillsQueue.PrintAllTickets();
    PayBillsQueue.PrintInfo();
   PayBillsQueue.ServeNextClient();
   PayBillsQueue.ServeNextClient();  PayBillsQueue.PrintInfo();

   PayBillsQueue.IssueTicket();
   PayBillsQueue.PrintAllTickets();
    cout << "\nPay Bills Queue After Serving One client\n";
    PayBillsQueue.PrintInfo();

    cout << "\nSubscriptions Queue Info:\n";

    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();


    SubscriptionsQueue.PrintInfo();

    SubscriptionsQueue.PrintTicketsLineRTL();
    SubscriptionsQueue.PrintTicketsLineLTR();

    SubscriptionsQueue.PrintAllTickets();

    SubscriptionsQueue.ServeNextClient();
    cout << "\nSubscriptions Queue After Serving One client\n";
    SubscriptionsQueue.PrintInfo();


    return 0;
}
