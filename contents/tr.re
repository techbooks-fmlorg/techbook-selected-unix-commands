
#@# 

== tr

標準入力から文字を変換、スクイーズ、削除し、標準出力に書き出す。


===== 実行例 


//list[][][fontsize=xx-small]{
cat file1.txt | tr a-z a  (file1の中身を出力し、aからzまでの文字を全てaに置き換えるという意味)
//}



===== 実行結果 


//list[][][fontsize=xx-small]{
aaaaa,aaaaa!!
I aa Laaaa.
//}


=== オプション一覧


  

==== -d もしくは --delete



「-d」オプションで、指定した文字を削除することができる。一例として、Windows環境で作成したファイルの改行コードを、Linux環境向けに置き換えるといった用途に使用できる。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat file1.txt | tr -d ami
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  hello,world!!
  I  Lnux.
//}



==== -s もしくは --squeeze-repeats



指定した文字が1回だけ出現するように置き換える。一例として、複数改行して間が大きく空いている文書などの間も縮めることができる。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat file1.txt | tr -s a
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  hello,world!!
  I am Linux.
//}



==== -t もしくは --truncate-set1



置換する文字列の長さや個数に合わせて置換が行われる。連続している文字列は一つに集約されて出力される。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat file1.txt | tr  -s hel! HEL?
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  HELo,worLd?
  I am Linux.
//}


