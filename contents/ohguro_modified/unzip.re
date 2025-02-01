#@# 

=={unzip} unzip

圧縮されたzipファイルから、ファイルを取り出す（解凍する）コマンド。
@<code>{zip}コマンドの反対（@<secref>{zip}も参照）

=== 書式

//list[][][fontsize=xx-small]{
$ unzip [options] 解凍したいファイル名
//}


=== 実行例

test1.txtとtest2.txtが格納されたexample.zipを解凍することを考える

==== 実行例 

//list[][][fontsize=xx-small]{
$ unzip example.zip
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ unzip example.zip
 Archive:  example.zip
  extracting: text1.txt               
  extracting: text2.txt  
//}
