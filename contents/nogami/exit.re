#@# 

== exit

sshやsudoコマンドでログインしたときにログアウトできる。
ターミナルの画面にいる場合はターミナルが閉じる。

===== 実行例1

前提としてsshコマンドでEC2(AWSのサービスの一つ)にログインしている
//list[][][fontsize=xx-small]{
admin@16.32.64.128$exit
//}
===== 実行結果1

//list[][][fontsize=xx-small]{
 admin@16.32.64.128$ exit
Script done.
Connection to 16.32.64.128 closed.
user:~$   
※ssh先からログアウトしてログイン以前のターミナルに戻った
//}

===== 実行例2

//list[][][fontsize=xx-small]{
※実行例1の続き
user$ exit
//}
===== 実行結果2

//list[][][fontsize=xx-small]{
 exit
※ターミナルの画面が閉じる
//}