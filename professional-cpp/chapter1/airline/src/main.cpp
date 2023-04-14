#include <iostream>
import airline_ticket;
int main(int argc, char** argv)
{
    AirlineTicket myTicket;
    myTicket.setPassengerName("Sherman T.");
    myTicket.setNumberOfMiles(700);
    double cost { myTicket.calculatePriceInDollars() };
    std::cout << "This ticket will cost $" << cost << std::endl;
    return 0;
}
