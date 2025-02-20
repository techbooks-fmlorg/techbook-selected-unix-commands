#@# 

=={exit} @<term>{exit}

sshやsudoコマンドでログインしたときに@<term>{ログアウト((ろぐあうと))}できる。
Windowsなどで、
ターミナルアプリの画面でexitコマンドを実行した場合は、そのターミナルアプリごと閉じてしまうことに注意


=== 書式

//list[][][fontsize=xx-small]{
$ exit
//}


=== 実行例

以下、Windows上のターミナルアプリ上でsshコマンドを実行し、
EC2(AWSのサービスの一つ)上に作成したDebianのサーバにSSHログインしている前提とする

#@# X-TODO: Windowsのターミナル画面の図が欲しいところ
//list[][][fontsize=xx-small]{
Windowsのターミナルアプリ ---(SSH)---> Debian GNU/Linxu (EC2)
//}


==== 実行例1 （EC2からログアウトする）

//list[][][fontsize=xx-small]{
admin@16.32.64.128$ exit
//}
Debian上で@<B>{exit}コマンドを実行する

==== 実行結果1

//list[][][fontsize=xx-small]{
admin@16.32.64.128$ exit
Script done.
Connection to 16.32.64.128 closed.
user:~$   
//}
ssh先からログアウトして、Windowsのターミナルに戻る。
出力例の最終行@<code>{user:~$ }はSSH元のPCのターミナルに戻ってきた様子。

#@# X-TODO user:~$ -> windows example


#@# X-TODO: これはWindowsのターミナル画面の図を貼るべきなのでは？
==== 実行例2 （Windowsのターミナルアプリからログアウトする）

//list[][][fontsize=xx-small]{
user$ exit
//}
（実行例1の続きで）いまはWindowsのターミナルに戻っている。
その上で、もういちどexitを実行すると

#@# X-TODO user:~$ -> windows example

==== 実行結果2

ターミナルアプリの画面ごと閉じてしまう
