### 📣 어떻게 했능가!!
1. **fork** 를 해준다.
2. ``` git clone {저장소 url} ```작성 => 새로운 파일이 생성된다.
3. ``` git branch {branch_name} ``` 작성 => 새로운 branch 생성
4. ``` git checkout {branch_name} ``` 작성 => 해당 branch로 작업 위치가 변경
5. ``` git add {file_name} ``` 작성
6. ``` git commit -m "WEEKN (순번) 이름" ```   ex) WEEK1 (1) array, vector 📌📌📌
7. ``` git checkout main ``` 작성 => main으로 작업 위치 변경
8. ``` git merge {branch_name} ``` 작성 => merge
9. ``` git push origin main ``` 작성 => push

### ⭐ 주의 해야 할 점
push 하기 전에 항상 pull 해주기!
```
git checkout main
git pull
git checkout {branch_name}
git merge main
```
