#@# 

== gzip

ファイルの圧縮および伸張を行うためのUNIXおよびLinuxコマンド。  
gzipは、データの圧縮と解凍に広く使用されており、通常は.gzという拡張子がついたファイルに適用される。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gzip -v text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt:     68.6% -- replaced with text.txt.gz
//}



=== オプション一覧






==== -d もしくは --decompress




指定したファイルを解凍する。  

圧縮ファイルにのみ実行可能。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gzip -v -d text.txt.gz
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt.gz:     68.6% -- replaced with text.txt
//}


==== -f もしくは --force 


  

ファイルが複数のリンクを持っている場合や、対応するファイルが既に存在する場合、または圧縮データが端末から読み取られたり端末に書き込まれたりしている場合であっても、強制的に圧縮または解凍を行う。  

-fが指定されず、同じファイルが存在する場合、既存のファイルを上書きするかどうかを確認するためにプロンプトを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -f text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  -fを指定した場合
  text.txt:     68.6% -- replaced with text.txt.gz
//}


//list[][][fontsize=xx-small]{
  -fを指定せず、同じファイルが存在する場合
  gzip: text.txt.gz already exists; do you wish to overwrite (y or n)? y
  text.txt:     68.6% -- replaced with text.txt.gz
//}



==== -k もしくは --keep 


  

入力したファイルを消去しない。  

デフォルトは消去。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -k text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt:   68.6% -- created text.txt.gz
//}



==== -l もしくは --list 


  

圧縮ファイルに対して実行することで以下の内容を表示する。  

- compressed size: 圧縮ファイルのサイズ  

- uncompressed size: 非圧縮ファイルのサイズ  

- ratio:  圧縮率 (不明な場合は0.0%)  

- uncompressed_name: 非圧縮ファイルの名前



===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -l text.txt.gz
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  compressed        uncompressed  ratio  uncompressed_name
         242                 685  68.6%  text.txt
//}



==== -n もしくは --no-name 


  

圧縮時には、元のファイル名とタイムスタンプを保存しない。  

解凍時には、元のファイル名を復元しない（圧縮されたファイル名から gzip の接尾辞だけを削除する）。また元のタイムスタンプも復元しない（圧縮されたファイルからコピーしない）。このオプションは、解凍時にデフォルトで適用される。



===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -n text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}



==== -N もしくは --name 


  

圧縮時には、常に元のファイル名とタイムスタンプを保存する。  

解凍時には、元のファイル名とタイムスタンプを復元する（それらが存在する場合）。このオプションは、ファイル名の長さに制限があるか、またはファイルの転送後にタイムスタンプが失われた場合に有用。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -N text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}



==== -q もしくは --quiet 


  

実行内容や警告文などを表示しない




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -q text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  無し
//}


==== -r もしくは --recursive 


  

指定したディレクトリや複数のファイルを再帰的に処理する。
//list[][][fontsize=xx-small]{
  .
  ├─text
  │   ├─text0.txt
  │   ├─text1.txt
//}


上記のディレクトリ構造に対して実行する




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -r -v text
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text/text0.txt:     3.3% -- replaced with text/text0.txt.gz
  text/text1.txt:     5.0% -- replaced with text/text1.txt.gz
//}


==== -v もしくは --verbose 


  

処理内容を出力する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  text.txt:     68.6% -- replaced with text.txt.gz
//}


==== -\<#> もしくは --fast もしくは --best 


  

指定された数字 # を使用して圧縮の速度を調整する。  

1または--fastは最速の圧縮メソッド（圧縮が少ない）を示し、-9または--bestは最遅の圧縮メソッド（最大の圧縮）を示す。デフォルトの圧縮レベルは-6。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -9 text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}



