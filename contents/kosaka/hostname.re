#@# 

=={hostname} hostname

このコマンドを実行したコンピュータのホスト名を表示する。
SSH接続している場合、接続先のホスト名が表示される。
また、Unix 系の OS (Debian や Ubuntu など)ではホスト名の確認に加えて、ホスト名を設定することができる。
以下に、ホスト名の確認と設定の実行例を示す。


#@# X-TODO hostname column 場所のチューニング 
//note[column-hostname][ホスト名]{

@<B>{ホスト名}とは、
ネットワークに接続された機器を識別・特定するために、各機器に付けられる名前のことである。
身近で例えると、私たちの氏名や免許証・マイナンバーカードといったその人を象徴するものと同義である。

hostnameコマンドで、@<B>{どこで作業をしているのか？}を確認できる。
つねに、@<B>{どこで作業をしているのか？}を確認することを心がけてほしい

//}

==== 書式

//list[][][fontsize=xx-small]{
$ hostname
//}


==== 実行例 (ホスト名の確認)



//list[][][fontsize=xx-small]{
$ hostname
//}





==== 実行結果



//list[][][fontsize=xx-small]{
$ hostname
ip-172-31-9-130
//}



この場合、「ip-172-31-9-130」がホスト名となる。
※ Windows はこのホスト名の確認のみ行うことができる。



==== 実行例 (ホスト名の設定) ※ Unix 系 OS 限定・Windowsは不可



//list[][][fontsize=xx-small]{
$ hostname <設定したいホスト名>
//}





==== 実行結果



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

OSの各種設定は/etc以下の設定ファイルを適切に編集し、
再起動、
設定が反映されていることを確認するべきである

//}
