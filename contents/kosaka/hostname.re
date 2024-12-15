#@# 

== hostname

このコマンドを打ち込んだコンピュータのホスト名を表示する。
ssh接続などをしている場合、接続先のホスト名が表示される。
また、Unix 系の OS (Debian や Ubuntu など)ではホスト名の確認に加えて、ホスト名を設定することができる。
以下に、ホスト名の確認と設定の実行例を示す。



===== 実行例 (ホスト名の確認)



//list[][][fontsize=xx-small]{
  $ hostname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ hostname
  ip-172-31-9-130
//}



この場合、「ip-172-31-9-130」がホスト名となる。
※ Windows はこのホスト名の確認のみ行うことができる。



===== 実行例 (ホスト名の設定) ※ Unix 系 OS 限定・Windowsは不可



//list[][][fontsize=xx-small]{
  $ hostname <設定したいホスト名>
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ hostname　debian.sample
  
//}



//list[][][fontsize=xx-small]{
  $ hostname
  debian.sample
//}


ホスト名の設定を行う場合、実行しても設定結果が出力されるわけではないため、改めて hostname コマンドなどを実行し確認する必要がある。
また、hostname コマンドで設定したホスト名は恒久的には変更されず、再起動すると設定前のホスト名に変更される。