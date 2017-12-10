#include "cranktypea.h"


bool CrankTypeA::consolidateSlide(SlideBlock *compound)
{
    compound1 = compound;
}

bool CrankTypeA::consolidateCrank(Crank *compound)
{
    compound2 = compound;
}
