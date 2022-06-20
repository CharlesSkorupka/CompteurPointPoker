#ifndef QUINTEFLUSH_H_INCLUDED
#define QUINTEFLUSH_H_INCLUDED
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include "Card.h"
#include "Suite.h"
#include "Color.h"

std::vector<int> quinteFlush(std::vector <Card> hand);

#endif // QUINTEFLUSH_H_INCLUDED
