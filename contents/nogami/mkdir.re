#@# 

== mkdir

ディレクトリを作成できる。

===== 実行例1

//list[][][fontsize=xx-small]{
$ ls
www.py htdocs/ 
※ www.pyというファイルとhtdocsというディレクトリがある。
$ mkdir ディレクトリ名
※ 今回はディレクトリ名としてtestと入力する
$ mkdir test

$mkdir test/dir
//}

===== 実行結果1

//list[][][fontsize=xx-small]{
$ mkdir test

$ls
www.py htdocs/ test/
// testという名前のディレクトリが追加されている
$ ls test //test内のファイル・ディレクトリを確認する
dir/
※ dirという名前のディレクトリが追加されている
//}