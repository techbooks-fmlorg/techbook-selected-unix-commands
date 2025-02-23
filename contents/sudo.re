#@# 

//footnote[root-priv][ほぼすべての操作が可能な管理者の権限]

=={sudo} @<term>{sudo}

@<idx>{ルート権限((るーとけんげん))}@<fn>{root-priv}を持たない一般ユーザが、
sudoコマンドを使うと、コマンド単位でルート権限を利用できる

=== 書式

//list[][][fontsize=xx-small]{
$ sudo [options] command [arg ...]
//}

=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ sudo id
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ sudo id
uid=0(root) gid=0(root) groups=0(root)
//}

=== ルート権限の特長

==== IDが変わる

コマンドは実行時の@<idx>{ユーザID((ゆーざあいでぃー))}（@<term>{uid}）と紐付いている。
ルート権限を持つユーザ(root)のuidは0なので、
sudoを利用して実行したコマンドはuid=0で動作する。

===== 実行例

@<code>{id}コマンドに、コマンド実行時のuidを表示させてみよう。

@<code>{id}コマンドにより自身のuidについて確認できる。
（@<secref>{id}節を参照）
//list[][][fontsize=xx-small]{
$ id -u
//}
sudoをつけて実行する場合は次のようにする。
//list[][][fontsize=xx-small]{
$ sudo id -u
//}


===== 実行結果
//list[][][fontsize=xx-small]{
$ id -u
1000
$ sudo id -u
0
//}
sudoを使う時と使わないときでuidが異なることがわかる


=== 特権ポートでサーバを起動する

ネットワークでは、通信を識別するために、
ネットワークの入出力口（@<idx>{ソケット((そけっと))}）に識別番号（@<idx>{ポート番号((ぽーとばんごう))}）をつけている。
当然サーバが待ち受けするポートもある。
広く利用される（公益性が高い）サーバが使うポート番号には@<term>{1024}未満が割り当てられており、
@<term>{特権ポート((とっけんぽーと))}と呼ばれている。
このポートを利用する際、つまりサーバを起動する際には、ルート権限が必要である

sudoコマンドを利用することでルート権限を取得し、特権ポートでサーバを起動することが出来るようになる


===== 実行例

@<idx>{ポート番号((ぽーとばんごう))<<>>80}番でPythonのWWWサーバを起動する例を見てみよう。

//list[][一般ユーザが普通にサーバを起動する場合][fontsize=xx-small]{
$ python3 -m http.server 80
//}

//list[][sudoコマンドをつけて、サーバを起動する場合][fontsize=xx-small]{
$ sudo python3 -m http.server 80
//}


===== 実行結果

HTTPデフォルトのポート番号80番でPythonのWWWサーバを起動しようとすると、
次のように@<code>{PermissionError: [Errno 13] Permission denied}というエラーメッセージが表示され、
異常終了する。
//list[][][fontsize=xx-small]{
$ python3 -m http.server 80
Traceback (most recent call last):
    〜省略〜
PermissionError: [Errno 13] Permission denied
//}

sudoコマンドをつければ起動できるようになる
//list[][][fontsize=xx-small]{
$ sudo python3 -m http.server 80
Serving HTTP on 0.0.0.0 port 80 (http://0.0.0.0:80/) ...
    〜省略〜
//}
sudoなしだと、@<B>{80番ポートを開く権限がない}ため、WWWサーバを起動できない。
sudoを使うことで、@<B>{80番ポートを開く権限得られる}ため、
WWWサーバを起動することができる。


=== 注意点

root権限を持つユーザはセキュリティ上ねらわれやすいユーザであるため、
直接ルートユーザにログインするのではなく、
一般ユーザでログインし、
必要な場合にのみsudoコマンドを利用してルート権限を利用することを心がける。
