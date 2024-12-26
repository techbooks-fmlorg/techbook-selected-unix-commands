#@# 

== unzip

圧縮されたzipファイルから、ファイルを取り出すコマンド。

===== 実行例 

test1.txtとtest2.txtが格納されたexample.zipを解凍。

//list[][][fontsize=xx-small]{
  unzip example.zip
//}

===== 実行結果

//list[][][fontsize=xx-small]{
 Archive:  example.zip
  extracting: text1.txt               
  extracting: text2.txt  
//}