#@#  -p, -v options

=={cp} cp

ファイルをコピーする


=== 書式

//list[][][fontsize=xx-small]{
$ cp コピー元 コピー先
//}


=== 実行例

以下の実行例では、@<B>{tree}コマンドで現階層以下のファイルやディレクトリ状況を表示する。
この@<B>{tree}コマンドとは、
ディレクトリ内のファイル・ディレクトリをツリー形式で表示するコマンドである
（詳細は@<secref>{tree}を参照）

==== 実行例１

いま作業しているディレクトリ以下には、次のようにhtdocsフォルダとtest.txtがある。

//list[][][fontsize=xx-small]{
$ tree
.
├──htdocs
└─test.txt
//}

コピーを実行する
//list[][][fontsize=xx-small]{
$ cp test.txt test2.txt
//}


==== 実行結果１

//list[][][fontsize=xx-small]{
$ cp test.txt test2.txt
$ tree
.
├──htdocs
├──test2.txt
└──test.txt
//}
作成したtest2.txtファイルとtest.txtファイルの中身は同じである。


==== 実行例２

引数を次のようにすれば、htdocs内にtest2.txtをコピーできる。

//list[][][fontsize=xx-small]{
$ cp test.txt htdocs/test2.txt
//}

==== 実行結果２

//list[][][fontsize=xx-small]{
$ cp test.txt htdocs/test2.txt

$ tree
.
├──htdocs
│   └──test2.txt
└──test.txt
//}

