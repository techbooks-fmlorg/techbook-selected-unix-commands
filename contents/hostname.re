#@# 

=={hostname} @<term>{hostname}

このコマンドを実行したコンピュータの@<idx>{ホスト名((ほすとめい))<<>>を表示する((をひょうじする))}。
SSH接続している場合、接続先のホスト名が表示される。
また、Unix 系の OS (Debian や Ubuntu など)ではホスト名の確認に加えて、ホスト名を設定することができる。
以下に、ホスト名の確認と設定の実行例を示す。

#@# X-TODO footnote ?
#@# X-TODO hostname column 場所のチューニング 
//note[column-hostname][ホスト名]{

@<B>{ホスト名}とは、
各機器に便宜上つける名前である。
たいていは、サーバの役割が分かるような名前をつける。

//}

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



==== 実行例 (ホスト名の設定) （注：Unix 系 OS 限定・Windowsは不可）



//list[][][fontsize=xx-small]{
$ hostname <設定したいホスト名>
//}





==== 実行結果 (ホスト名の設定)



//list[][][fontsize=xx-small]{
$ hostname debian.sample
//}



//list[][][fontsize=xx-small]{
$ hostname
debian.sample
//}


ホスト名の設定を行う場合、実行しても設定結果が出力されるわけではないため、改めて hostname コマンドなどを実行し確認する必要がある。
ただし、ホスト名の設定には管理者 (root) 権限が必要となるため、多くの場合、hostname コマンドの前に sudo コマンドをつけなくてはいけない。
また、hostname コマンドで設定したホスト名は恒久的には変更されず、再起動すると設定前のホスト名に変更される。

//note[column-set-hostname][ホスト名を設定する]{

hostnameコマンドでホスト名をつける作業は（できないわけではないが）めったに行わない。

OSの各種設定は@<idx>{/etc}以下の設定ファイルを適切に編集し、
再起動、
設定が反映されていることを確認するべきである

//}
