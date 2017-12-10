#include "cranktypeb.h"


bool CrankTypeB::consolidateOutputBlock(OutputBlock *compound)
{
    compound2 = compound;
}

bool CrankTypeB::consolidateCrank(Crank *compound)
{
    compound1 = compound;
}

