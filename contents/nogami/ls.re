#@# 

== ls
ディレクトリ内のディレクトリ・ファイルを確認できる。
===== 実行例
//list[][][fontsize=xx-small]{
$ ls
//}
===== 実行結果

//list[][][fontsize=xx-small]{
$ ls
htdocs python.py test.txt
//}
このディレクトリにはhtdocs python.py test.txtがある。
=== オプション一覧
==== -l
ファイル・ディレクトリの権限が確認できる。
権限についてはコマンド:chmodに詳しく記載されている。
===== 実行例

//list[][][fontsize=xx-small]{
$ ls -l
//}
===== 実行結果

//list[][][fontsize=xx-small]{
drwxr-xr-x 2 user group 4096 Sep 08:14:44 htdocs
-rw-r--r-- 1 user group 10239 Dec 08 15:36 python.py
-rw-r--r-- 1 user group 10239 Sep 08 15:38 test.txt
//}
d,r,w,x,-という文字列があるが、dはディレクトリかどうか、rは読み取り権限、wは書き込み権限、xは実行権限である。
rwxが3回繰り返されているが、それぞれ本人(ユーザー名:user)の権限、グループ(グループ名:groupに属しているユーザー)の権限、その他の権限である。
htdocsは最初にdがついてるためディレクトリ、最初のrwxがrwxのためuserは読み書き実行可能、groupに属するユーザーは次のrwxがrw-なので読み書き可能、それ以外のユーザーは3つ目のrwxがrw-なので読み書き可能であることを示してる。
python.pyとtest.txtは最初に-となっているのでファイル、最初のrwxがrw-のためuserは読み書き可能、groupに属するユーザーは次のrwxがr--なので読み取り可能、それ以外のユーザーは3つ目のrwxがr--なので読み取り可能であることを示してる。
==== -a
隠しファイル・隠しディレクトリを含めたすべてのファイルを確認できる。
===== 実行例

//list[][][fontsize=xx-small]{
$ ls -a
//}
===== 実行結果

//list[][][fontsize=xx-small]{
$ ls -a
.ssh .bash_history test.txt htdocs python.py 
//}
隠しディレクトリである.ssh .bash_historyが表示されている。
