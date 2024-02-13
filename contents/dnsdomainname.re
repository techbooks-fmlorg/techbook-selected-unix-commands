#@# 

== dnsdomainname

ドメイン名を表示する

システムの設定やネットワークにより静的に設定されるため使用頻度は低い



===== 実行例 



//list[][][fontsize=xx-small]{
  dnssomainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示されない
//}




=== オプション一覧



==== -a




ドメインネームの別名も表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dnsdomainname -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示されない
//}


==== -A 


  

全てのホスト名をFQDN(ドメイン名を省略)で表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -A
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VirtualBox
//}


==== -b 


  

設定したホスト名を、ずっと有効にする




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -b
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示なし
//}


==== -d 


  

DNSのドメイン名を表示する

詳細表示しようとするとFQDNと誤解されるため使用頻度は低い




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -d
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示なし
//}


==== -f 


  

ホスト名をFQDNで表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -f
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VitualBox
//}


==== -F 


  

ホスト名をファイルから読み込む




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -F example.com
  dnsdomainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  example.com
//}


==== -i 


  

ホスト名に対応するIPアドレスを表示する

このオプションが使えない場合は代わりに「-I」オプションを使う




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  127.0.1.1
//}


==== -I 


  

設定されているすべてのホスト名に対応するIPアドレスを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -I
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  10.0.2.15
//}


==== -s 


  

短縮表現のホスト名を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -s
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VitualBox
//}


==== -y 


  

NISドメイン名(NISの仕組みで使われるドメイン名)を表示・設定する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dnsdomainname -y domainname
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname
//}

