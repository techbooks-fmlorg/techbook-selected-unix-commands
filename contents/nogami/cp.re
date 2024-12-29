#@# 

== cp
ファイルをコピーできる。
$ cp コピー元 コピー先　と用いる。 
===== 実行例
//list[][][fontsize=xx-small]{
$ tree //ディレクトリ内のファイル・ディレクトリをツリー形式で表示する。
.
├──htdocs
└─test.txt
$ cp test.txt test2.txt

$ tree
//}
===== 実行結果

//list[][][fontsize=xx-small]{
$ cp test.txt test2.txt
$ tree
.
├──htdocs
├──test2.txt
└──test.txt
//}
作成したtest2.txtファイルはtest.txtファイルの中身は同じである。
===== 実行例
//list[][][fontsize=xx-small]{
$ tree

.
├──htdocs
└─test.txt
$ cp test.txt htdocs/test2.txt

$ tree
//}
===== 実行結果

//list[][][fontsize=xx-small]{
$ cp test.txt test2.txt

$ tree
.
├──htdocs
│   └──test2.txt
└──test.txt
//}
htdocs内にもtest2をコピーできる。