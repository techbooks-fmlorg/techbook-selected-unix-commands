#@# 

== aa-enabled

AppArmor(Linuxのセキュリティプロファイルを結びつけることで、ネットワークアクセスやRaw socketアクセス、ファイルへの読み書き実行などの機能に制限をかけることができるプログラム。例えば、あるプログラムに対して、参照しかしないファイルへの書き込み、利用するはずがないファイルへのアクセス、関係がない別のプログラムの呼び出しを禁止できる。"/etc/apparmor/parser.conf"に記述された通りに制限がかけられる。)の状態を確認するためのコマンド。AppArmorが有効になっている場合は"Yes"、無効になっている場合は"No"が出力される。



===== 実行例 



//list[][][fontsize=xx-small]{
  aa-enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}



=== オプション一覧




==== -q




何も出力しない。単にAppArmorが有効になっているかどうかを判断するための終了コード。



===== 実行例 



//list[][][fontsize=xx-small]{
  aa-enabled -q
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -x 


  

AppArmorが有効であるとみなされるには、共有LSMインターフェイスへの排他的アクセスが必要。




===== 実行例　



//list[][][fontsize=xx-small]{
  aa-enabled -x
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}


