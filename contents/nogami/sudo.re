#@# 

=={sudo} sudo

ルート権限(ほぼすべての操作が可能な権限)を持たない一般ユーザーが、
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

一般的にユーザーに取り決められたIDだがルート権限を持つユーザー(root)のidは0のため
sudoを利用したコマンドに限りIDが変更される

===== 実行例

@<code>{id}コマンドにより自身のIDについて確認できる
（@<secref>{id}節を参照）
//list[][][fontsize=xx-small]{
$ id -u
//}
sudoをつけて実行する場合は次のようにする
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
sudoを使う時と使わないときでIDが変化していることがわかる


=== 特権ポートでサーバを起動する

ネットワークでは、通信を識別するために、
ネットワークの入出力口（ソケット）に識別番号（ポート番号）をつけている。
当然サーバが待ち受けするポートもある。
広く利用されている（公的性が高い）サーバが使うポート番号には1024未満が割り当てられており、
特権ポートと呼ばれている。
このポートを利用する際、つまりサーバを起動する際には、ルート権限が必要である

sudoコマンドを利用することで、この制限を回避し、サーバを起動することが出来るようになる


===== 実行例

一般ユーザが、デフォルトのポート番号80番でPythonのサーバを起動しようとする例
//list[][][fontsize=xx-small]{
$ python3 -m http.server 80
//}

sudoコマンドをつけて、一般ユーザが、デフォルトのポート番号80番でPythonのサーバを起動しようとする例
//list[][][fontsize=xx-small]{
$ sudo python3 -m http.server 80
//}


===== 実行結果

デフォルトのポート番号80番でPythonのサーバを起動しようとすると、
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
sudoなしだと権限が80番ポートを開く権限がないため、httpサーバーを開けないが
sudoを使うことで80番ポートを開く権限があるため、httpサーバーを開くことができる


=== 注意点

root権限を持つユーザーはセキュリティ上狙われやすいユーザーであるため、
直接ルートユーザーにログインするのではなく、
権限を持たないユーザーでログインし、
必要な場合にsudoコマンドを利用してルート権限を利用すること
