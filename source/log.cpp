#include "..\headers\log.h"

void CLog::operator()(const wchar_t* fileName, LOG_GROUP printGroup, const wchar_t* format, ...){
	
	if((unsigned __int64)(_printGroup & printGroup) == 0){
		return ;
	}

	size_t fileNameLen = wcslen(fileName);

	size_t fullFileNameLen = fileNameLen + _directoryLen + 2;
	wchar_t* fullFileName = new wchar_t[fullFileNameLen];
				
	StringCchPrintf(fullFileName, fullFileNameLen, L"%s\\%s", _directory, fileName);


	lock(); 
	do{
		
		FILE* file;

		_wfopen_s(&file, fullFileName, L"a");
		if (file == nullptr) {
			CDump::crash();
			break;
		}
		
		va_list vaList;
		va_start(vaList, format);

		vfwprintf_s(file, format, vaList);
		fwprintf_s(file, L"\n");

		va_end(vaList);

		fclose(file);

	} while (false);

	delete[] fullFileName;
	unlock();
}

void CLog::setPrintGroup(LOG_GROUP printGroup){

	_printGroup = printGroup;

}

void CLog::setDirectory(const wchar_t* dirName){

	_directory = (wchar_t*)dirName;

	_directoryLen = wcslen(dirName);

	int wmkdirResult = _wmkdir(dirName);
	if (wmkdirResult == -1) {
		errno_t err;
		_get_errno(&err);
		CDump::crash();
	}

}

CLog::CLog(){

	_directory = nullptr;
	_directoryLen = 0;
	ZeroMemory(&_printGroup, sizeof(LOG_GROUP));

	InitializeSRWLock(&_lock);

}