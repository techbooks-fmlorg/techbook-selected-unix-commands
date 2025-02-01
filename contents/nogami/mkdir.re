#@# 

=={mkdir} mkdir

ディレクトリを作成する

=== 書式

//list[][][fontsize=xx-small]{
$  mkdir [OPTION]... DIRECTORY...
//}

 * 引数は必須。作成するディレクトリを少なくとも1つ指定する必要がある
 * 引数は可変長。作成したいディレクトリは、引数として複数つなげて書けば良い。
   スペース区切り


=== 実行例

==== 実行例1

現状の確認だが、
//list[][][fontsize=xx-small]{
$ ls
www.py htdocs/ 
//}
現在のディレクトリには、
www.pyというファイルとhtdocsというディレクトリがある。

//list[][][fontsize=xx-small]{
$ mkdir test
$ mkdir test/dir
//}
いま、新たに@<code>{test}ディレクトリを作成した。
さらに、
@<code>{test}ディレクトリの下に
@<code>{dir}ディレクトリを作成した


==== 実行結果1

//list[][][fontsize=xx-small]{
$ mkdir test
$ ls
www.py htdocs/ test/
//}
testという名前のディレクトリが追加されている

//list[][][fontsize=xx-small]{
$ ls test
dir/
//}
test内のファイル・ディレクトリを確認すると、
dirという名前のディレクトリが追加されていることが分かる
