#@# 

== exit

sshやsudoコマンドでログインしたときにログアウトできる。
ターミナルの画面にいる場合はターミナルが閉じる。

===== 実行例1

//list[][][fontsize=xx-small]{
※sshコマンドでログインしている
admin(IPアドレス)$exit
//}
===== 実行結果1

//list[][][fontsize=xx-small]{
 exit
Script done.
Connection to IPアドレス closed.
user_name:~$   
※ssh先からログアウトしてログイン以前のターミナルに戻った
//}

===== 実行例2

//list[][][fontsize=xx-small]{
※実行例1の続き
user_name$exit
//}
===== 実行結果2

//list[][][fontsize=xx-small]{
 exit
※ターミナルの画面が閉じる
//}