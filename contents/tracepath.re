#@# 

#@# 脚注の位置調整 (DEFERRED)
//footnote[NCOM][NTTコミュニケーション。旧Verioを買収して世界規模の長距離回線を擁するTier-1のキャリア。業界人はNTT COMではなくNCOMと呼ぶ。電車の中で「NCOMが〜」とか電話してる同業者がいるとドキドキするよね？(w)]
//footnote[comcast][アメリカのケーブルテレビ大手]

=={tracepath} @<term>{tracepath}

宛先にパケットを送信し、宛先までに通過する各ルータのIPアドレスを表示する。宛先のホストまでの@<idx>{ネットワーク((ねっとわーく))<<>>経路を可視化((けいろをかしか))}するために利用する。

=== 書式

//list[][][fontsize=xx-small]{
$ tracepath [options] DESTINATION
//}
DESTINATIONはホスト名かIPアドレス


=== 実行例

==== 実行例 

//list[][][fontsize=xx-small]{
$ tracepath IPアドレス
//}

==== 実行結果　（192.159.190.35 nintendo.com）

//list[][][fontsize=xx-small]{
$ tracepath 192.159.190.35
1?: [LOCALHOST]                      pmtu 1280
1:  LAPTOP-A860U3T2.mshome.net                      1.443ms
1:  LAPTOP-A860U3T2.mshome.net                      0.383ms
2:  unifi.localdomain                               1.811ms
3:  10.252.0.1                                      1.910ms
4:  118.23.89.234                                   4.303ms
5:  118.23.89.77                                    5.230ms
6:  221.184.5.205                                   6.879ms
7:  122.1.245.193                                  18.817ms
8:  122.1.245.206                                  21.827ms
9:  ae-9.a03.tokyjp05.jp.bb.gin.ntt.net            19.898ms             @<balloon>{NCOM,東京}
10:  ae-5.r32.tokyjp05.jp.bb.gin.ntt.net           19.778ms asymm 11    @<balloon>{ここまで日本国内}
11:  ae-4.r27.snjsca04.us.bb.gin.ntt.net           128.045ms            @<balloon>{NCOM,サンノゼ}
12:  ae-0.a02.sttlwa01.us.bb.gin.ntt.net           120.781ms asymm 13
13:  ae-0.comcast.sttlwa01.us.bb.gin.ntt.net       116.382ms            @<balloon>{ここまでNCOM}
14:  be-1211-cs02.portland.or.ibone.comcast.net    147.274ms asymm 16   @<balloon>{ここからcomcast}
15:  be-36131-arsc1.burien.wa.seattle.comcast.net  136.669ms asymm 16
16:  ae-501-ar01.seattle.wa.seattle.comcast.net    121.145ms asymm 17
17:  be-2-sur02.bellevue.wa.seattle.comcast.net    152.747ms asymm 20
18:  be-1-sur03.bellevue.wa.seattle.comcast.net    149.624ms asymm 19
19:  50.231.28.130                                 128.459ms asymm 18
20:  no reply
   〜省略〜
30:  no reply
		Too many hops: pmtu 1280
		Resume: pmtu 1280
//} 

出力の読み方：
日本のサーバ〜NCOM@<fn>{NCOM}〜アメリカのComcast@<fn>{comcast}のルータ群を経由していることが分かる。
14番目のルータのドメイン名にはポートランドとある。
サンノゼもポートランドもデータセンター銀座である。
NCOMの海底ケーブルで太平洋を超え（10番目〜11番目）、
サンノゼで陸揚げし、アメリカ西海岸を北上して、ポートランドでcomcastのアメリカ内陸ネットワークに入ったことが読み取れる。



=== 知っていると便利なオプション: @<idx>{-n}

DNSの検索をせずに処理を実行する。


==== 実行例 

//list[][][fontsize=xx-small]{
$ tracepath -n IPアドレス
//}


==== 実行結果 （192.159.190.35 nintendo.com）

//list[][][fontsize=xx-small]{
$ tracepath -n 192.159.190.35
1?: [LOCALHOST]                      pmtu 1280
1:  172.29.208.1                                          1.404ms
1:  172.29.208.1                                          1.343ms
2:  192.168.1.1                                           1.767ms
3:  10.252.0.1                                            3.226ms
4:  118.23.89.234                                         9.273ms
5:  118.23.89.77                                         11.126ms
6:  221.184.5.205                                        12.700ms
7:  122.1.245.193                                        24.420ms
8:  122.1.245.206                                        24.939ms
9:  120.88.53.21                                         25.712ms
10:  129.250.5.109                                        19.804ms asymm 11
11:  129.250.5.78                                        125.279ms
12:  129.250.5.227                                       133.718ms asymm 13
13:  129.250.66.106                                      115.329ms
14:  96.110.44.93                                        128.149ms asymm 15
15:  68.86.93.2                                          129.075ms asymm 17
16:  96.216.153.6                                        144.728ms
17:  69.139.164.126                                      130.598ms asymm 19
18:  68.86.96.142                                        150.784ms asymm 19
19:  50.231.28.130                                       131.109ms asymm 18
20:  no reply
   〜省略〜
   30:  no reply
		Too many hops: pmtu 1280
		Resume: pmtu 1280
//}


//note[-n][-nオプションの意義]{

ネットワーク系のコマンドは、
@<code>{@<term>{-n}}オプションをつけて実行することを心がけたい
（その手のコマンドには普通@<code>{-n}オプションがあるはず）。
なぜなら、
この手のコマンドを実行するのは障害対応時であり、
DNSも確認項目の一つだからだ。
DNS障害に引きづらずに
@<idx>{ネットワーク((ねっとわーく))<<>>の動作確認((のどうさかくにん))}をする必要がある。

//}
