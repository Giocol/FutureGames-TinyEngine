#include "Pickup.h"

Pickup::Pickup(Vector position) 
	: Actor(position, Vector(20), COLOR_GREEN){
	collisionChannel = CollisionChannel::Pickup;
}
