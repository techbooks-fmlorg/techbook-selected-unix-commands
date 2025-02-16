#@# 

=={zip} @<term>{zip}

@<idx>{ファイル((ふぁいる))<<>>をzip形式で圧縮((をじっぷけいしきであっしゅく))}するコマンド。
@<code>{unzip}コマンドの反対（@<secref>{unzip}も参照）

=== 書式

//list[][][fontsize=xx-small]{
$ zip [options] 圧縮後のファイルの名前 圧縮したいファイルの名前...
//}
「圧縮したいファイルの名前...」は可変長である。


=== 実行例

text1.txtとtext2.txtをexample.zipに圧縮する。

==== 実行例 

//list[][][fontsize=xx-small]{
$ zip example.zip test1.txt test2.txt
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ zip example.zip text1.txt text2.txt
   adding: text1.txt (stored 0%)
   adding: text2.txt (stored 0%)
//}
