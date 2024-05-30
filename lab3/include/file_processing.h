#ifndef FILE_PROCESSING
#define FILE_PROCESSING
#include "dollar.h"
#include "euro.h"
#include "pound.h"
#include "yen.h"

Ruble** InputFileProcessing(Ruble** exchanges);
void    OutputFileProcessing(Ruble** exchanges);
void    FileRecovery();
void    CorruptedFile();

#endif /* FILE_PROCESSING */