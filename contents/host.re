#@# 

=={host} @<term>{host}

host コマンドの引数を検索し、
その引数に紐づくドメイン名やIPアドレスの情報を出力する。
よく使う操作に次のものがある。

 * 正引き: 引数がドメイン名 -> @<idx>{IPアドレス((あいぴーあどれす))<<>>を出力((をしゅつりょく))}
 * 逆引き: 引数がIPアドレス -> @<idx>{ドメイン名((どめいんめい))<<>>を出力((をしゅつりょく))}

//note[domainname][ドメイン名]{

@<idx>{ドメイン名((どめいんめい))}とは、インターネット上で個々のコンピュータやネットワークを識別し、接続先を指定するために使用される名称の一部のことである。
身近な例をあげれば、
私たち個人がそれぞれ生活する場所の住所 (すなわち、インターネット上における私たち個人の住所) と同義である

//}


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

@<idx>{host} コマンドと似たような出力をするコマンドとして、他には @<idx>{dig} と @<idx>{nslookup} コマンドが存在する。ただし、dig と nslookup コマンドはインストールしていないと使用できない。
Windows の場合は、host コマンドの代わりに nslookup コマンドが標準搭載されておりインストールすることなく使用できる。dig コマンドはインストールが必要となる。
使用している OS によって使用できるかどうかが異なる場合があるため、注意が必要である。

//}
