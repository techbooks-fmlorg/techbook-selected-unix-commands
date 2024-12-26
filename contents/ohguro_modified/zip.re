#@# 

== zip

ファイルをzip形式で圧縮するコマンド。

===== 実行例 

//list[][][fontsize=xx-small]{
  zip [圧縮後のファイルの名前] [圧縮したいファイルの名前]
//}

===== 実行結果

text1.txtとtext2.txtをexample.zipに圧縮。

//list[][][fontsize=xx-small]{
  $ zip example.zip text1.txt text2.txt
 　 // example.zipが圧縮後のファイルの名前、text1.txt,text2.txtが圧縮したいファイルの名前

   adding: text1.txt (stored 0%)
   adding: text2.txt (stored 0%)
//}