#@# 

=={host} @<term>{host}

コマンドの引数を検索し、
その引数に紐づくドメイン名やIPアドレスの情報を出力する。
よく使う操作に次のものがある。

 * 正引き: 引数がドメイン名 -> @<idx>{IPアドレス((あいぴーあどれす))<<>>を出力((をしゅつりょく))}
 * 逆引き: 引数がIPアドレス -> @<idx>{ドメイン名((どめいんめい))<<>>を出力((をしゅつりょく))}


==== 書式

//list[][][fontsize=xx-small]{
$ host 名前
//}
「名前」の部分にはドメイン名やIPアドレスを指定する

以下に「@<idx>{正引き((せいびき))}」と「@<idx>{逆引き((ぎゃくびき))}」の実行例を示す。


==== 実行例 （正引き：ドメイン名を指定する）

//list[][][fontsize=xx-small]{
$ host ドメイン名
//}


==== 実行結果 （例：host portal.net.fml.org と入力した場合）

//list[][][fontsize=xx-small]{
$ host portal.net.fml.org
portal.net.fml.org has address 210.128.53.254
//}

出力(portal.net.fml.org has ...)右端のIPアドレス（210.128.53.254）部分が、
回答（引数のドメイン名に紐づくIPアドレス）である。


==== 実行例 （逆引き：ip アドレスを指定する）

//list[][][fontsize=xx-small]{
$ host IPアドレス
//}


==== 実行結果 (例：host 210.128.53.254 と入力した場合)

//list[][][fontsize=xx-small]{
$ host 210.128.53.254
254.53.128.210.in-addr.arpa domain name pointer portal.net.fml.org.
//}

出力(254.53.128.210. ...)行の右端、
domain name pointerの右に続く
@<code>{portal.net.fml.org}という文字列部分が回答である。
引数（210.128.53.254）に紐づくドメイン名になっている。


//note[host-dig-and-nslookup][host, dig, nslookupコマンド]{

@<idx>{host} と似たコマンドとして、@<idx>{dig} と @<idx>{nslookup} も存在する。
これら3つのうち、どれがデフォルトで使えるか？はOSごとにマチマチなので注意しよう。
もちろんインストールすれば、どの環境でも使用できる。

ちなみに、Windows の場合は、nslookup コマンドが標準搭載されている。

//}
