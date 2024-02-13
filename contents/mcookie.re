#@# 

== mcookie

\**X認証システム* で使用するための \**マジッククッキー（魔法のクッキー）* を生成するための \**ユーティリティ* 。

（\* X認証システム : X Window System という GUI を提供するためのプロトコルとディスプレイサーバに関するソフトウェアプロトコルで使用されるセキュリティ機構のこと。）

（\* マジッククッキー : セッション間での認証トークンとして使用されるランダムデータのこと。）

（\* ユーティリティ : コンピュータの分析、構成、最適化、保守のためのソフトウェアの総称。ユーティリティソフトウェアとも呼ばれる。）

具体的には、X認証システムで使用する128ビットのランダムな16進数を生成する。



===== 実行例 

//list[][][fontsize=xx-small]{
mcookie
//}



===== 実行結果 

//list[][][fontsize=xx-small]{
7f5666105aff03809c17dfb9f2d9ae12
//}



=== オプション一覧


  

==== -f もしくは --file FILE



引数（ FILE ）として指定したファイルをクッキーのシードとして使用するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  mcookie -m 1 -f hoge.txt
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  e9f79e7e1edc12fdda16fb3a4dc70e6b
//}



==== -m もしくは --max-size NUM



シードファイルからの読み込み量を制限するオプション。引数（ NUM ）で指定したバイト数をマックスとする。何かしらのファイルやデバイスをシードにする際に指定しないと実行できないため、-f オプションと併用して使用する。

指定するバイトは当たり前だが、そのファイルのディスク使用量以下にする必要がある。以下の実行例で用いている hoge.txt は 5バイトのファイルである。



===== 実行例 

//list[][][fontsize=xx-small]{
  mcookie -m 5 -f hoge.txt
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  17b6822a593be8cab50b8e29cabab42a
//}



==== -v もしくは --verbose



各ソースから読み取ったエントロピーの量とともにランダム性を出所を表示するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  mcookie -m 5 -f create_hoge_files.sh -v 
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  Got 5 bytes from create_hoge_files.sh
  Got 128 bytes from getrandom() function
  f9370557c62ab6c3703b7b614d6ae34f
//}

