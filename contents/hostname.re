#@# 

//footnote[hostname][@<B>{ホスト名}とは、各機器に便宜上つける名前だ。たいてい、サーバの役割が分かる名前をつける。@<br>{}例：メールサーバはmail、ファイルサーバはfs]

=={hostname} @<term>{hostname}

このコマンドを実行したコンピュータの@<idx>{ホスト((ほすと))<<>>名を表示する((めいをひょうじする))}@<fn>{hostname}。
SSH接続している場合、接続先のホスト名が表示されることに注意。
また、Unix 系の OS (@<idx>{Debian} や @<idx>{Ubuntu} など)ではホスト名の確認に加えて、ホスト名を設定することができる。
以下に、ホスト名の確認と設定の実行例を示す。


==== 書式

//list[][][fontsize=xx-small]{
$ hostname
//}


==== 実行例 (ホスト名の確認)



//list[][][fontsize=xx-small]{
$ hostname
//}





==== 実行結果 (ホスト名の確認)



//list[][][fontsize=xx-small]{
$ hostname
ip-172-31-9-130
//}



この場合、「ip-172-31-9-130」がホスト名となる
（注： Windows はこのホスト名の確認のみ行うことができる）。



==== 実行例 (ホスト名の設定)（注：Unix 系 OS 限定・Windowsは不可）@<fn>{column-set-hostname} 



//list[][][fontsize=xx-small]{
$ hostname <設定したいホスト名>
//}





==== 実行結果 (ホスト名の設定)



//list[][][fontsize=xx-small]{
$ hostname debian.example.co.jp
//}



//list[][][fontsize=xx-small]{
$ hostname
debian.example.co.jp
//}


ホスト名の設定を行う場合、実行しても設定結果が出力されるわけではないため、改めて hostname コマンドなどを実行し確認する必要がある。
ただし、ホスト名の設定には管理者 (root) @<idx>{権限((けんげん))}が必要となるため、多くの場合、hostname コマンドの前に sudo コマンドをつけなくてはいけない。
また、hostname コマンドで設定したホスト名は恒久的には変更されず、再起動すると設定前のホスト名に変更される。

//footnote[column-set-hostname][hostnameコマンドでホスト名をつける作業は通常おこなわない。OSの各種設定は@<idx>{/etc}以下の設定ファイルを適切に編集し、再起動、設定が反映されていることを確認するべきである]
