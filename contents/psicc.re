#@# 

== psicc(途中)

色管理プロファイルを適用するとコマンドツール。ICC（International Color Consortium）プロファイルを使用して、画像やグラフィックスの色空間を変更するために使用する。


=== オプション一覧




==== -b




-bオプションを使用すると、プロファイルの変換を行う際に、画像やグラフィックスのバックアップファイルを作成できる。



===== 実行例 



//list[][][fontsize=xx-small]{
  psicc -b input.icc output.icc
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  バックアップファイルが作成される: "input.icc"ファイルは、変換前の状態を保持したバックアップファイルとして保存される。バックアップファイルの名前は通常、元のファイル名に".bak"などの拡張子が追加されることがある。例えば、"input.icc"のバックアップファイルは"input.icc.bak"となる場合がある。
//}


==== -c precision 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}



==== -i profile 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}




==== -n gridpoints 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}




==== -o profile 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}



==== -t intent 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}


