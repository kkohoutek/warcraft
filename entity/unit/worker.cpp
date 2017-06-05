#include "worker.h"

Worker::Worker(QPointF pos) : Unit(pos, 1, 0, 0, 0)
{
}

void Worker::gatherGold(Goldmine *source, Building *destination){
    currentGoldmine = source;
    goldDestination = destination;
    currentTree = NULL;
    setTarget(currentGoldmine->pos());
}

void Worker::gatherLumber(Tree *source, Building *destination){
    currentTree = source;
    lumberDestination = destination;
    currentGoldmine = NULL;
    setTarget(currentTree->pos());
}

void Worker::stopGathering(){
    currentGoldmine = NULL;
    currentTree = NULL;
}

bool Worker::isGatheringGold(){
    return currentGoldmine != NULL;
}

bool Worker::isGatheringLumber(){
    return currentTree = NULL;
}
