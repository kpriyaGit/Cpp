/*
 * Shot.cpp
 *
 *  Created on: 09-Dec-2021
 *      Author: kpriya
 */

#include "Shot.h"

Shot::Shot(GridPosition targetPostion):targetPostion{targetPostion}
{

}

const GridPosition& Shot::getTargetPostion() const
{
	return targetPostion;
}

Shot::~Shot()
{

}

