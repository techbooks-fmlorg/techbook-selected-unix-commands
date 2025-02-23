#@# 

=={zip} @<term>{zip}

@<idx>{ファイル((ふぁいる))<<>>をzip形式でアーカイブ((をじっぷけいしきであーかいぶ))}するコマンド。
反対は@<code>{unzip}コマンド（@<secref>{unzip}も参照）

=== 書式

//list[][][fontsize=xx-small]{
$ zip [options] アーカイブファイル名 アーカイブしたいファイルの名前...
//}
「アーカイブしたいファイルの名前...」は可変長である。


=== 実行例

text1.txtとtext2.txtをexample.zipにアーカイブする。

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
