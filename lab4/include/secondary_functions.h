#ifndef SECONDARY_FUNCTIONS
#define SECONDARY_FUNCTIONS

int    StoiExceptionsProcessing();
void   StoiExceptionsProcessing(char);
int    StoiExceptionsProcessing(int range);
double ReadDouble();
double RandomDouble(double lower_bound = -100.0,
                    double upper_bound = 100.0);
int    RandomInt(int lower_bound = 5, int upper_bound = 15);
char*  RandomString(int lower_bound = 5, int upper_bound = 15);

#endif /* SECONDARY_FUNCTIONS */