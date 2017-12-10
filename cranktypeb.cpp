#include "cranktypeb.h"


bool CrankTypeB::consolidateOutputBlock(OutputBlock *compound)
{
    compound2 = compound;
    compoundPosition2 = compound2->getcompoundPosition(this);
}

bool CrankTypeB::consolidateCrank(Crank *compound)
{
    compound1 = compound;
}

void CrankTypeB::somethingBlockConsolidate(OutputBlock *compound)
{
    consolidateOutputBlock(compound);
}

