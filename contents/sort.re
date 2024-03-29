#@# 

== sort

ファイルの内容をソートし、標準出力に出力する。1文字目が同値だった場合、2文字目で判断する。3文字目以降も同様にソートしていく。また、ソートの結果をファイルに出力するためには、リダイレクトを行う。以下の実行例にリダイレクトの書式を示す。実行結果には出力先のファイルであるoutput1.txtの内容を記述する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sort ex1.txt > output1.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1
  22
  24
  477
  5666
  677
  999
//}



=== オプション一覧




==== -n




数値として並び替える。



===== 実行例 



//list[][][fontsize=xx-small]{
  sort ex1.txt -n
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1
  22
  24
  477
  677
  999
  56666
//}


==== -r 


  

降順でソートする。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex1.txt -r
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  999
  677
  56666
  477
  24
  22
  1
//}


==== -t 


  

項目の区切り文字を指定する。後述の-kオプションと組み合わせて使用されることが多い。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex2.txt -t :
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  goto:50
  kawai:19
  kudo:44
  ohira:300
//}


==== -k 


  

ソートの基準となる項目を指定してソートする。前述の-tオプションで区切り文字を指定し、このオプションで区切られた項目を指定してソートする。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex2.txt -t ":" -k 2
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  kawai:19
  ohira:300
  kudo:44
  goto:50
//}


==== -u 


  

重複したデータを削除して出力する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex3.txt -u
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  11
  111
  222
  333
  444
  555
//}


==== -f 


  

大文字と小文字を区別せずにソートする。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex4.txt -f
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  nagoya
  OSAKA
  osaka
  TOKYO
  tokyo
//}


==== -c 


  

指定したファイルの内容がソートされているかどうかチェックする。正しくソートされている場合は何も出力されないが、正しくソートされていない場合はエラーを出力する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex1.txt -c
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  sort: ex1.txt:4: 順序が不規則: 477
//}


==== -m 


  

ソートは行わず、指定した2個のファイルをつなげて出力する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex1.txt -m ex2.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1
  24
  56666
  477
  999
  677
  22
  kawai:19
  ohira:300
  goto:50
  kudo:44
//}


==== -o 


  

パスで指定したファイルに出力する。実行結果には出力先のファイルの内容を記述する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex1.txt -o output2.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1
  22
  24
  477
  56666
  677
  999
//}


==== -R 


  

ランダムにソートする。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex1.txt -R
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  56666
  24
  677
  1
  999
  477
  22
//}


==== --debug 


  

ソートの際に注釈をつける。




===== 実行例　



//list[][][fontsize=xx-small]{
  sort ex1.txt --debug
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  sort: `ja_JP.UTF-8' ソートルールを使用してテキストの並び替えを実行しています
  1
  _
  22
  __
  24
  __
  477
  ___
  56666
  _____
  677
  ___
  999
  ___
//}

