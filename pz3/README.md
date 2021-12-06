## Практическое задание 3

1. Провести контроль тестового покрытия
2. Разработать цепочку Git actions, которая:
  - Извлечет исходный код из git
  - Скомпилирует
  - Запустит модульные тесты
  - Проведет статический анализ (опционально)
  - Проведет контроль тестового покрытия (опционально)
  - Сформирует docker образ (опционально)

## Запуск gcov
 ```
 make
 ./container_test
 gcov main.cpp
 ```
 или 
  ```
 make
 make gcov
 ```

## Gcov result

<img src="/pic/gcovResult.png" width=50% height=50%>

## GithubAction with Gtest result

<img src="/pic/githubActionGtest.png" width=75% height=75%>

