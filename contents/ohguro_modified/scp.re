#@# 

== scp

SSHを利用して、自分のコンピュータのファイルを他のコンピュータに転送する。
scpは、「Secure Copy」の略。

実際に使う際は、コピー元のパスと保存先のパスを指定する。

===== 実行例 

sampleファイルを、exampleサーバのhome/test

//list[][][fontsize=xx-small]{
  scp [コピー元のファイルパス] [コピー先のファイルパス]
//}

//list[][][fontsize=xx-small]{
  $ scp sample.txt testuser@example:/home/test/
    // 「sample.txt」がコピー元のファイル名、「testuser@example:/home/test/」がコピー先のファイルパス
    // testuserがコピー先のユーザ名、exampleがドメイン名（サーバ名）
    // ipアドレスでの指定も可能




=== オプション一覧



==== -r




コピーしたい対象がディレクトリの場合に使用する。


===== 実行例 

sampledirファイルを、exampleサーバのhome/test

//list[][][fontsize=xx-small]{
  scp -r sampledir testuser@example:/home/test/
//}