#@# 

=={mkdir} @<term>{mkdir}

@<idx>{ディレクトリ((でぃれくとり))<<>>を作成する((をさくせいする))}

=== 書式

//list[][][fontsize=xx-small]{
$  mkdir [option]... DIRECTORY...
//}

 * 引数に、作成するディレクトリを少なくとも1つは指定する必要がある
 * 引数は可変長。作成したいディレクトリは、引数として複数つなげて書けば良い。
   Unixなので、いつものように@<B>{スペース区切り}である


=== 実行例

==== 前提

現状の確認は@<code>{ls}コマンドで行える。
//list[][][fontsize=xx-small]{
$ ls
www.py htdocs/ 
//}
いま作業しているディレクトリには、
www.pyというファイルとhtdocsというディレクトリがある。

==== 実行例1

//list[][][fontsize=xx-small]{
$ mkdir test
//}
新たに@<code>{test}ディレクトリを作成し、結果をlsコマンドで確認する。


==== 実行結果1

//list[][][fontsize=xx-small]{
$ mkdir test
$ ls
www.py htdocs/ test/
//}
testという名前のディレクトリが追加されていることが分かる



==== 実行例2

//list[][][fontsize=xx-small]{
$ mkdir test/dir
//}
さらに、
@<code>{test}ディレクトリの下に
@<code>{dir}ディレクトリを作成する


==== 実行結果2

//list[][][fontsize=xx-small]{
$ mkdir test/dir
$ ls test
dir/
//}
test内のファイル・ディレクトリを確認すると、
dirという名前のディレクトリが追加されていることが分かる
