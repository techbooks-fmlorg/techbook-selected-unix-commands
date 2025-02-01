#@# 

=={ls} ls

いま作業している場所（ディレクトリ）内のディレクトリやファイルの情報を表示する

=== 書式

//list[][][fontsize=xx-small]{
$ ls [OPTION] [FILE]...
//}

 * 引数がない場合、現在のディレクトリの情報を表示する
 * 引数のファイルやディレクトリは可変長
 * 引数のファイルやディレクトリは混在してよい


=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ ls
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ ls
htdocs python.py test.txt
//}
このディレクトリにはhtdocs python.py test.txtがある。

=== 知っていると便利なオプション

==== -l オプション

ファイル・ディレクトリの権限が確認できる。
権限については@<code>{chmod}コマンドに詳しく記載されている
（詳細は@<secref>{chmod}節を参照）

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
python.pyとtest.txtは最初に-となっているのでファイル、最初のrwxがrw-のためuserは読み書き可能、groupに属するユーザーは次のrwxがr--なので読み取り可能、それ以外のユーザーは3つ目のrwxがr--なので読み可能であることを示してる。

==== -a オプション

隠しファイル・隠しディレクトリを含めた全てのファイルを確認できる。

===== 実行例

//list[][][fontsize=xx-small]{
$ ls -a
//}

===== 実行結果

//list[][][fontsize=xx-small]{
$ ls -a
.ssh .bash_history test.txt htdocs python.py 
//}
隠しディレクトリである.sshと隠しファイルの.bash_historyも表示されている。
