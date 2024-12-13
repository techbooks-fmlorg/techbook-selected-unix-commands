#@# 

== tracepath

宛先にパケットを送信し、宛先までに通過する各ルータのIPアドレスを記録する。記録されたIPアドレスによって、宛先のホストまでのネットワーク経路を可視化するために利用する。



===== 実行例 



//list[][][fontsize=xx-small]{
  tracepath IPアドレス
//}





===== 実行結果　（192.159.190.35 nintendo.com）



//list[][][fontsize=xx-small]{
	$ tracepath 192.159.190.35
	1?: [LOCALHOST]                      pmtu 1280
	1:  LAPTOP-A860U3T2.mshome.net                            1.443ms
	1:  LAPTOP-A860U3T2.mshome.net                            0.383ms
	2:  unifi.localdomain                                     1.811ms
	3:  10.252.0.1                                            1.910ms
	4:  118.23.89.234                                         4.303ms
	5:  118.23.89.77                                          5.230ms
	6:  221.184.5.205                                         6.879ms
	7:  122.1.245.193                                        18.817ms
	8:  122.1.245.206                                        21.827ms
	9:  ae-9.a03.tokyjp05.jp.bb.gin.ntt.net                  19.898ms
	10:  ae-5.r32.tokyjp05.jp.bb.gin.ntt.net                  19.778ms asymm 11
	11:  ae-4.r27.snjsca04.us.bb.gin.ntt.net                 128.045ms
	12:  ae-0.a02.sttlwa01.us.bb.gin.ntt.net                 120.781ms asymm 13
	13:  ae-0.comcast.sttlwa01.us.bb.gin.ntt.net             116.382ms
	14:  be-1211-cs02.portland.or.ibone.comcast.net          147.274ms asymm 16
	15:  be-36131-arsc1.burien.wa.seattle.comcast.net        136.669ms asymm 16
	16:  ae-501-ar01.seattle.wa.seattle.comcast.net          121.145ms asymm 17
	17:  be-2-sur02.bellevue.wa.seattle.comcast.net          152.747ms asymm 20
	18:  be-1-sur03.bellevue.wa.seattle.comcast.net          149.624ms asymm 19
	19:  50.231.28.130                                       128.459ms asymm 18
	20:  no reply
	21:  no reply
	22:  no reply
	23:  no reply
	24:  no reply
	25:  no reply
	26:  no reply
	27:  no reply
	28:  no reply
	29:  no reply
	30:  no reply
			Too many hops: pmtu 1280
			Resume: pmtu 1280
 
  ------------------------------------------------------------------------
  ※出力の読み方
	ホスト名:ae-5.r32.tokyjp05.jp.bb.gin.ntt.net　＜－　東京にあるルータ
	ホスト名:be-1-sur03.bellevue.wa.seattle.comcast.net　＜－　アメリカのAmazon社が持っているルータ　  
	通信時間:19.778ms asymm 11

	日本のサーバからアメリカのAmazon社のサーバを経由していることが分かる
//}



=== オプション一覧




==== -n




出力結果をIPアドレスのみにする。



===== 実行例 



//list[][][fontsize=xx-small]{
  tracepath -n IPアドレス
//}





===== 実行結果　（192.159.190.35 nintendo.com）



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
	21:  no reply
	22:  no reply
	23:  no reply
	24:  no reply
	25:  no reply
	26:  no reply
	27:  no reply
	28:  no reply
	29:  no reply
	30:  no reply
			Too many hops: pmtu 1280
			Resume: pmtu 1280
			
	------------------------------------------------------------------------
  ※出力の読み方
	IPアドレス:129.250.5.109
	通信時間:19.778ms asymm 11
//}


