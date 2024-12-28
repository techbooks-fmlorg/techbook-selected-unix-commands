#@# 

== sudo
ルート権限(ほぼすべての操作が可能な権限)を持たないユーザーがコマンド単位でルート権限を受け取れる。
動作にはコマンドが必須
===== 実行例

//list[][][fontsize=xx-small]{
$ sudo
//}
===== 実行結果

//list[][][fontsize=xx-small]{
usage: sudo -h | -K | -k | -V
usage: sudo -v [-AknS] [-g group] [-h host]
            [-p prompt] [-u user]
usage: sudo -l [-AknS] [-g group] [-h host]
            [-p prompt] [-U user] [-u user]
            [command]
usage: sudo [-AbEHknPS] [-r role] [-t type]
            [-C num] [-g group] [-h host]
            [-p prompt] [-u user]
            [VAR=value] [-i|-s] [<command>]
usage: sudo -e [-AknS] [-r role] [-t type]
            [-C num] [-g group] [-h host]
            [-p prompt] [-u user] file ...
//}

=== ルート権限の特長
==== IDが変わる
一般的にユーザーに取り決められたIDだがルート権限を持つユーザー(root)のidは0のため
sudoを利用したコマンドに限りIDが変更される
===== 実行例
//list[][][fontsize=xx-small]{
$ id -u //自身のIDについて確認できる

$ sudo id -u
//}
===== 実行結果
//list[][][fontsize=xx-small]{
$ id -u
1000

$ sudo id -u
0
//}
sudoを使う時と使わないときでIDが変化していることがわかる


==== ポート開放
ポート番号(通信に使用するプログラムを識別するための番号、0～65535まで設定可能)を指定する際
ルート権限がなければポート番号:1～1023までを直接利用できないが、ルート権限を持つことで、ポートを利用できる。
===== 実行例

//list[][][fontsize=xx-small]{
    $ python3 -m http.server 80
    ※80番ポートを利用してhttpサーバーを立てろという意味
    $ sudo python3 -m http.server 80
//}
===== 実行結果

//list[][][fontsize=xx-small]{
    $ python3 -m http.server 80
    PermissionError: [Errno 13] Permission denied //権限がありませんという表記

    $ sudo python3 -m http.server 80
    Serving HTTP on 0.0.0.0 port 80 (http://0.0.0.0:80/) //httpサーバーが開いている時の表記

//}
sudoなしだと権限が80番ポートを開く権限がないため、httpサーバーを開けないが
sudoを使うことで80番ポートを開く権限があるため、httpサーバーを開くことができる
==== 注意点

root権限を持つユーザーはセキュリティ上狙われやすいユーザーであるため、直接ルートユーザーにログインするのではなく、
権限を持たないユーザーでログインして必要な場合にsudoコマンドを利用してルート権限を利用してください。