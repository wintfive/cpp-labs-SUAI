#ifndef EXCHANGE_PROCESSING
#define EXCHANGE_PROCESSING
#include "dollar.h"
#include "euro.h"
#include "pound.h"
#include "yen.h"

Ruble** CreateExchanges();
void    PrintRates(Ruble** exchanges);
Ruble** ChangeRates(Ruble** exchanges);
void    DeleteExchanges(Ruble** exchanges);


#endif /* RUBLE */