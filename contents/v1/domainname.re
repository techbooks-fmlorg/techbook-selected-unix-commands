#@# 

== domainname

ネットワーキングやドメイン関連の設定を行う際に使用される

しかし、シンプルな構文と変更の即時変更の観点からhostnameコマンドが推奨される場合が多い
また、dnsdomainnameとも互換性がある



===== 実行例 



//list[][][fontsize=xx-small]{
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname
//}




=== オプション一覧






==== -a




ドメイン名の別名も表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  domainname -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示されない
//}


==== -A 


  

全てのホスト名をFQDN(ドメイン名を省略)で表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -A
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VirtualBox
//}


==== -b 


  

設定したホスト名を、ずっと有効にする




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -b
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname
//}


==== -d 


  

DNSのドメイン名を表示する

詳細表示しようとするとFQDNと誤解されるため使用頻度は低い




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -d
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname -d
//}


==== -f 


  

ホスト名をFQDNで表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -f
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VirtualBox
//}


==== -F 


  

ホスト名をファイルから読み込む




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo domainname -F file.txt
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Hello
//}


==== -i 


  

ホスト名に対応するIPアドレスを表示する

このオプションが使えない場合は代わりに「-I」オプションを使う




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -i
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  127.0.1.1
//}


==== -I 


  

設定されているすべてのホスト名に対応するIPアドレスを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -I
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  10.0.2.15
//}


==== -s 


  

短縮表現のホスト名を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -s
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VitualBox
//}


==== -y 


  

NISドメイン名(NISの仕組みで使われるドメイン名)を表示・設定する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo domainname -y domainname1
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname1
//}

