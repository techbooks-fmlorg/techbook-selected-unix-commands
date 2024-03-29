#@# 

== aa-teardown

全てのAppArmor(Linuxのセキュリティプロファイルを結びつけることで、ネットワークアクセスやRaw socketアクセス、ファイルへの読み書き実行などの機能に制限をかけることができるプログラム。例えば、あるプログラムに対して、参照しかしないファイルへの書き込み、利用するはずがないファイルへのアクセス、関係がない別のプログラムの呼び出しを禁止できる。"/etc/apparmor/parser.conf"に記述された通りに制限がかけられる。)プロファイルを無効化する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-teardown
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Unloading AppArmor profiles
//}

