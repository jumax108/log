#pragma once

#include <direct.h>
#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>

#include "dump\headers\dump.h"
#pragma comment(lib, "dump\\MSVC\\release\\dump.lib")

enum class LOG_GROUP;

class CLog{
	
public:

	CLog();

	void setDirectory(const wchar_t* dirName);
	void setPrintGroup(LOG_GROUP printGroup);

	void operator()(const wchar_t* fileName, LOG_GROUP printGroup, const wchar_t* format, ...);

private:

	inline void lock();
	inline void unlock();

	wchar_t* _directory;
	size_t _directoryLen;
	LOG_GROUP _printGroup;
	SRWLOCK _lock;
};

enum class LOG_GROUP{
	LOG_DEBUG  = 0x1,
	LOG_ERROR  = 0x2,
	LOG_SYSTEM = 0x4
};

inline LOG_GROUP operator|(LOG_GROUP left, LOG_GROUP right){
	return (LOG_GROUP)((unsigned __int64)left | (unsigned __int64)right);		
}

inline LOG_GROUP operator&(LOG_GROUP left, LOG_GROUP right){
	return (LOG_GROUP)((unsigned __int64)left & (unsigned __int64)right);		
}

void CLog::lock() {
	AcquireSRWLockExclusive(&_lock);
}

void CLog::unlock() {
	ReleaseSRWLockExclusive(&_lock);
}