= 頭文字が w のコマンド

#@# 

== wc

テキストファイルの行数や単語数、文字数、バイト数を表示するコマンド

単語は、空白や改行文字で区切られたものを数える

ファイルがない場合は標準入力を読み込む

オプションにより改行、単語、文字、バイト、最大行長の順に選択することができる

wc 



===== 実行例 



//list[][][fontsize=xx-small]{
  wc file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1 1 6 file.txt
//}



=== オプション一覧




==== -c もしくは --bytes




バイト数を出力する



===== 実行例 



//list[][][fontsize=xx-small]{
  wc -c file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  6 file.txt
//}


==== -m もしくは --chars 


  

文字数を出力する




===== 実行例　



//list[][][fontsize=xx-small]{
  wc -m file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  6 file.txt
//}


==== -l もしくは --lines 


  

行数を出力する




===== 実行例　



//list[][][fontsize=xx-small]{
  wc -l file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1 file.txt
//}


==== --files0-from=F 


  

ファイルに入力されているNULL文字で区切られたファイル名のリストを指定する



"--files0-from=-"とした場合、ファイルを標準入力から読み込む


sortやfindと併用して使い、ファイルサイズなどを出力できる




===== 実行例　



//list[][][fontsize=xx-small]{
  wc -m -files0-from=filename.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  6 /home/ubuntu/file.txt
//}


==== -L もしくは --max-line-length 


  

最大の表示幅を出力する




===== 実行例　



//list[][][fontsize=xx-small]{
  wc -L file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  5 file.txt
//}


==== -w もしくは --words 


  

単語数を出力する




===== 実行例　



//list[][][fontsize=xx-small]{
  wc -w file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1 file.txt
//}

