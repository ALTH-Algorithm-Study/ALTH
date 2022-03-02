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

### 🚨 이상한 에디터가 뜬다 ! 
뭔가 충돌이 나서 merge가 자동적으로 되지 않을 때 나오는 에디터입니다       
무조건 이걸로 해결해야지! 하지 마시고 뭐가 문제인지 충분히 생각 후 괜찮다 생각되면 그때 사용하세용          
![Untitled](https://user-images.githubusercontent.com/80443295/156373356-765e8268-36ae-4599-8222-de906a4896bf.png)
```
i // i 키를 눌러서 insert 모드로 바꾸기
// 노란색 부분에 commit message 적기
// esc 키를 눌러서 insert 모드에서 나가기
:wq // :wq를 누르면 merge 성공
```
