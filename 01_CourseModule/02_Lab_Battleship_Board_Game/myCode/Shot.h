/*
 * Shot.h
 *
 *  Created on: 09-Dec-2021
 *      Author: kpriya
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"
/**
 * The class that represents a shot in this game by the Own/Opponent Player
 */
class Shot
{
private:
	/**
	 * Private attribute that represents the target spot for shooting on a grid
	 */
	GridPosition targetPostion;
public:
	/**
	 * Attribute that contains all possible results of a shot
	 * NONE  - shot did not hit any ship.
	 * HIT - A part of ship was hit.
	 * SUNKEN - All the parts of ship are hit. Hence the ship sunk.
	 */
	typedef enum {
		NONE,
		HIT,
		SUNKEN}Impact;
	/**
	 * Parameterized constructor that initialized the shot with its target position
	 * @param targetPostion
	 */
	Shot(GridPosition targetPostion);
	/**
	 * Destructor
	 */
	~Shot();
	/**
	 * Getter Method that provides the targetPostion
	 * @returns reference to targetPostion
	 */
	const GridPosition& getTargetPostion() const;
};

#endif /* SHOT_H_ */
