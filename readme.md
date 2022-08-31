# Log
로깅을 위한 클래스

## 사전 세팅
- setDirectory
  > 함수를 호출하여 로그를 저장할 위치를 설정한다.
- setPrintGroup
  > 로그를 출력할 그룹을 설정한다.
  > 아래와 같이 정의되어 있다.
  > or 연산을 통해 여러 그룹을 지정할 수 있다.
  > 설정한 그룹과 로그의 그룹이 맞지 않으면 로깅되지 않는다.
  > ```
  > enum class LOG_GROUP{
  >		LOG_DEBUG  = 0x1,
  >		LOG_ERROR  = 0x2,
  > 	LOG_SYSTEM = 0x4 
  > };
  > ```

## 사용법
```
CLog log;
log.setDirectory(L"log");
log.setPrintGroup(LOG_GROUP::LOG_DEBUG);

log(L"log.txt", LOG_GROUP::LOG_SYSTEM, L"log 1, line : %d", __LINE__); // 출력되지 않음
log(L"log.txt", LOG_GROUP::LOG_DEBUG, L"log 2, line : %d", __LINE__); // 출력됨
```
