#@# 

== cat

ファイルの内容を確認するコマンド。複数のファイルの内容を確認することも可能。設定ファイルをエディターで開くと壊れる恐れがあるため、内容をまず確認すると安全。



===== 実行例 



//list[][][fontsize=xx-small]{
  cat sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  red


  blue
  yellow
//}



=== オプション一覧




==== -n




行番号を表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  cat -n sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1 red
  2 
  3
  4 blue
  5 yellow
//}


==== -b 


  

空行を飛ばして行番号を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  cat -b sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1 red


  2 blue
  3 yellow
//}


- @<strong>{-s} 

  

連続した空行を1行にする。




===== 実行例　



//list[][][fontsize=xx-small]{
  cat -s sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  red

  blue
  yellow
//}

