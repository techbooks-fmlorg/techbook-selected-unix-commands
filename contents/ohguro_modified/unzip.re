#@# 

== unzip

圧縮されたzipファイルから、ファイルを取り出す（解凍する）コマンド。

===== 実行例 

//list[][][fontsize=xx-small]{
  unzip [解凍したいファイルの名前]
//}

===== 実行結果

test1.txtとtest2.txtが格納されたexample.zipを解凍。

//list[][][fontsize=xx-small]{
  $ unzip example.zip
    // example.zipが解凍したいファイルの名前

 Archive:  example.zip
  extracting: text1.txt               
  extracting: text2.txt  
//}