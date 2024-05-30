#ifndef EXCHANGE_PROCESSING
#define EXCHANGE_PROCESSING
#include "dollar.h"
#include "euro.h"
#include "pound.h"
#include "yen.h"

Ruble** CreateExchanges();
Ruble** ChangeRates(Ruble** exchanges);
void    PrintRates(Ruble** exchanges);
Ruble** ChangeRates(Ruble** exchanges);
void    PrintBalance(Ruble** exchanges);
Ruble** ChangeBalance(Ruble** exchanges);
void    DeleteExchanges(Ruble** exchanges);


#endif /* EXCHANGE_PROCESSING */