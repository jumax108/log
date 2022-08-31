
#include "..\headers\log.h"


int main(){

	CLog log;
	log.setDirectory(L"log");
	log.setPrintGroup(LOG_GROUP::LOG_DEBUG);
	log(L"log.txt", LOG_GROUP::LOG_SYSTEM, L"log 1, line : %d", __LINE__); // ��µ��� ����
	log(L"log.txt", LOG_GROUP::LOG_DEBUG, L"log 2, line : %d", __LINE__); // ��µ�

	return 0;

}