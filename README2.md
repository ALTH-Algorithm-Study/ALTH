### 📣 어떻게 했능가!!
1. **fork** 를 해준다.
2. ``` git clone {저장소 url} ```작성 => 새로운 파일이 생성된다.
3. ``` git branch {branch_name} ``` 작성 => 새로운 branch 생성
4. ``` git checkout {branch_name} ``` 작성 => 해당 branch로 작업 위치가 변경
5. ``` git add {file_name} ``` 작성
6. ``` git commit -m "[자신이름] 날짜 시간 update " ```   ex) ```[원민재] 0211 13:25```  📌📌📌
7. ``` git checkout main ``` 작성 => main으로 작업 위치 변경
8. ``` git merge {branch_name} ``` 작성 => merge
9. ``` git push origin main ``` 작성 => push

### ⭐ 주의 해야 할 점
push 하기 전에 항상 pull 해주기!
```
git checkout main
git pull upstream main // ALTH 레포 자신의 레포로 pull 하기
git push origin main // 내 레포에 반영하기
git checkout {branch_name}
git merge main
```
### 그 외
1. push를 할 때는 <어떻게 했능가!!>의 4번부터 9번까지 해주면 된다.
2. commit으로 하나하나 작성해주려고 하니까 귀찮아서 폴더를 만들었다.
3. 배가 고프다!!!
4. 열심히 하자!
5. 겸이는 아프지 말어라~
