#include "Query.h"
#include "Request.h"
#include <list>

void Query::UpdateRequests(Exit& exit) {
	if (Query::CurrentQuery.empty()) return;
	for (std::list<Request*>::iterator iter = Query::CurrentQuery.begin(); iter != Query::CurrentQuery.end(); iter++) {
		if (iter._Ptr->_Myval->currentWaitingTime >= iter._Ptr->_Myval->maxWaitingTime) {
			iter._Ptr->_Myval->state = REQUEST_LOST;
			exit.requestsOut.push_back(iter._Ptr->_Myval);
			iter = Query::CurrentQuery.erase(iter);
			//if (iter == Query::CurrentQuery.end()) return;
			if (Query::CurrentQuery.empty()) return;
		}
		iter._Ptr->_Myval->currentLivingTime++;
		iter._Ptr->_Myval->currentWaitingTime++;
	}
}

Query::Query() {

}