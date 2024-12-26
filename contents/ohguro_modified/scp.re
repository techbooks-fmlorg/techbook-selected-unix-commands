#@# 

== scp

SSHを利用して、自分のコンピュータのファイルを他のコンピュータに転送する。
scpは、「Secure Copy」の略。

実際に使う際は、コピー元のパスと保存先のパスを指定する。

===== 実行例 

sampleファイルを、exampleサーバのhome/test

//list[][][fontsize=xx-small]{
  $ scp sample.txt testuser@example:/home/test/
//}




=== オプション一覧



==== -r




コピーしたい対象がディレクトリの場合に使用する。


===== 実行例 

sampledirファイルを、exampleサーバのhome/test

//list[][][fontsize=xx-small]{
  scp -r sampledir testuser@example:/home/test/
//}