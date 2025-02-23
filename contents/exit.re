#@#

//image[windows-command-prompt][WindowsのコマンドプロンプトでAWS EC2にsshし、作業後にexitしてWindowsに戻ってきた様子][scale=1.0]

=={exit} @<term>{exit}

sshやsudoコマンドでログインしたときに@<term>{ログアウト((ろぐあうと))}できる（@<img>{windows-command-prompt}）。
Windowsなどの
ターミナルアプリ（例：tetaterm）上でexitコマンドを実行した場合、そのターミナルアプリごと閉じてしまうことに注意
（注：@<img>{windows-command-prompt}は一歩手前の状態。さらにexitを入力すれば、このウインドウごと閉じてしまう）


=== 書式

//list[][][fontsize=xx-small]{
$ exit
//}


=== 実行例

以下、Windowsのターミナルアプリ上でsshコマンドを実行し、
EC2上に作成したDebianのサーバにSSHログインしている前提とする

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
C:\Users\b2902900>
//}
ssh先からログアウトして、Windowsのターミナルに戻る。
出力例の最終行@<code>{C:\Users\b2902900> }はSSH元のPCのターミナルに戻ってきた様子。


==== 実行例2 （Windowsのターミナルアプリからログアウトする）

//list[][][fontsize=xx-small]{
C:\Users\b2902900> exit
//}
（実行例1の続きで）いまはWindowsのターミナルに戻っている。
その上で、もういちどexitを実行すると



==== 実行結果2

ターミナルアプリごと閉じてしまう
