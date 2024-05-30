#ifndef EXCHANGE_PROCESSING
#define EXCHANGE_PROCESSING
#include "dollar.h"
#include "euro.h"
#include "pound.h"
#include "yen.h"

Ruble** CreateExchanges();
Ruble** ChangeRates(Ruble** exchanges);
void    PrintRates(Ruble** exchanges);
Ruble** ChangeRates(Ruble** exchanges, double new_rates[]);
void    PrintBalance(Ruble** exchanges);
Ruble** ChangeBalance(Ruble** exchanges, double new_balance);
void    DeleteExchanges(Ruble** exchanges);


#endif /* EXCHANGE_PROCESSING */