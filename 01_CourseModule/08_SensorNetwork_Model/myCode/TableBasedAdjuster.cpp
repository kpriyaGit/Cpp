#include "TableBasedAdjuster.h"

TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y)
{
	this->breakpoints[x]=y;
	return *this;
}

float TableBasedAdjuster::adjust(float value) const
{
	float adjustedVal = value;

	if(this->breakpoints.empty()){
		return adjustedVal;
	}

	float k_min = this->breakpoints.begin()->first;
	float v_min = this->breakpoints.begin()->second;
	float k_max = this->breakpoints.rbegin()->first;
	float v_max = this->breakpoints.rbegin()->second;

	//If u <= k_min then a = v_min - (k_min - u)
	if(value <= k_min){
		adjustedVal = v_min - (k_min - value);
	}

	//If u >= k_max then a = v_max + (u - k_max)
	else if(value >= k_max){
		adjustedVal = v_max + (value - k_max);
	}

	else{
		float kn = this->breakpoints.begin()->first;
		float vn = this->breakpoints.begin()->second;
		for(auto i = ++this->breakpoints.begin(); i!=this->breakpoints.end();i++){
			float kn1 = i->first;
			float vn1 = i->second;
			/*interpolation of Y in (X,Y) from (x1, y1) and (x2,y2)
			Y = (    ( (X-x1) / (x2-x1) ) * (y2 - y1)   ) + y1*/
			if ((value > kn) && (value <= kn1)) {
				adjustedVal = (((value - kn) / (kn1 - kn)) * (vn1 - vn))  + vn;
			}

			kn = i->first;
			vn = i->second;
		}
	}
	return adjustedVal;
}
