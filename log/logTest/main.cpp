
#include "..\log.h"

#pragma comment(lib, "log")

int main(){

	CLog log;

	log.setDirectory(L"log");

	log.setPrintGroup(LOG_GROUP::LOG_ERROR | LOG_GROUP::LOG_SYSTEM);

	log.log(L"test.txt", LOG_GROUP::LOG_DEBUG, L"%d", 1);
	log.log(L"test.txt", LOG_GROUP::LOG_ERROR, L"%d", 2);
	log.log(L"test.txt", LOG_GROUP::LOG_SYSTEM, L"%d", 3);

	return 0;

}