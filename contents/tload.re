#@# 

== tload


現在のシステムの負荷(load average)を指定されたttyにグラフで表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  tload
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
   0.52, 0.58, 0.59
  *

  *

  *

  *

  *      
//}


=== オプション一覧




==== -s


画面上の縦軸を設定する。load average 1に対応するグラフのひと目盛が、指定した文字分になる。したがって小さい値を設定するとスケールは大きくなる。逆も同じ。





===== 実行例 



//list[][][fontsize=xx-small]{
  tload -s 10
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0.52, 0.58, 0.59
  ----------
  **********
  **********
  **********
  **********
  **********
  **********
//}


==== -d 


  

グラフの更新間隔を秒単位で指定する。




===== 実行例　



//list[][][fontsize=xx-small]{
  tload -d 10
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
   0.52, 0.58, 0.59
  *

  *

  *

  *

  *
//}

