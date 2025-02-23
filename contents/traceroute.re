#@# 

=={traceroute} @<term>{traceroute}

宛先にパケットを送信し、宛先までに通過する各ルータのIPアドレスを記録する。記録されたIPアドレスによって、宛先のホストまでのネットワーク経路を可視化するために利用する。

歴史的には@<B>{traceroute}コマンドが初出で、
ほとんどのUnix/Linuxで利用できるのは@<B>{traceroute}コマンドである。
当然@<idx>{Debian}/GNU Linuxにも存在する（デフォルトでは入っていないかもしれないが、その時はapt install traceroute）。
ただし、
なぜか@<idx>{Ubuntu}には@<B>{traceroute}ではなく@<B>{tracepath}コマンドが入っているらしい@<fn>{vocareum-terminal}。

@<B>{traceroute}と@<B>{tracepath}の基本的な使い方は一緒なので、
詳細は@<B>{tracepath}@<secref>{tracepath}節を参照

//footnote[vocareum-terminal][少なくともAWS Academy(vocareum)の環境ではtracepathしか使えない]


=== 書式

//list[][][fontsize=xx-small]{
$ traceroute [options] DESTINATION
//}
 * DESTINATIONはホスト名かIPアドレス
 * @<B>{-n} オプションあり


//note[][Windowsでもネットワーク障害切り分けにpingとtracertが使える]{
Windowsのコマンドプロンプトでも@<B>{@<idx>{ping}}と@<B>{@<idx>{tracert}}コマンド(@<idx>{traceroute<<>>Windows版---((ういんどうずばん))})が利用できる。
ただしMicrosoftが再実装したものらしく、
オプションがUnixと異なるため注意が必要だ。
それでも非常時の障害きりわけには有効なので、
Windowsにもパチモノが搭載されていることを覚えておこう。
//}
