#include "Device.h"
#include "Request.h"
#include "RandomFunctions.h"
#include "Exit.h"
#include <math.h>

void Device::ReceiveRequestAndWait(Query& query, Exit& exit) {
	if ((Device::currentCooldown <= 0) && (!query.CurrentQuery.empty())) {
		Device::contained = query.CurrentQuery.front();
		query.CurrentQuery.pop_front();
		Device::contained->state = REQUEST_IN_DEVICE;
		Device::currentCooldown = ceil(RandomFunctions::generateExponential(Device::M_cooldown));	
	}
	else {
		Device::currentCooldown--;
		if (Device::contained != NULL) {
			Device::contained->currentLivingTime++;
			if (Device::currentCooldown <= 0) {
				exit.requestsOut.push_back(Device::contained);
				Device::contained->state = REQUEST_SUCCESS;
				Device::contained = NULL;
			}
		}		
	}
}

Device::Device(int M_cooldown) {
	Device::M_cooldown = M_cooldown;
	Device::currentCooldown = 0;
	Device::contained = NULL;
}