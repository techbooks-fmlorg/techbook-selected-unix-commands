#@# 

== ip
ネットワークデバイスやルーティング、ポリシーなどの表示と変更できる。
動作にはオブジェクトが必須。
===== 実行例

//list[][][fontsize=xx-small]{
$ip
//}
===== 実行結果

//list[][][fontsize=xx-small]{
Usage: ip [ OPTIONS ] OBJECT { COMMAND | help }
       ip [ -force ] -batch filename
where  OBJECT := { link | address | addrlabel | route | rule | neighbor | ntable |
                   tunnel | tuntap | maddress | mroute | mrule | monitor | xfrm |
                   netns | l2tp | fou | tcp_metrics | token | netconf }
       OPTIONS := { -V[ersion] | -s[tatistics] | -d[etails] | -r[esolve] |
                    -h[uman-readable] | -iec |
                    -f[amily] { inet | inet6 | ipx | dnet | mpls | bridge | link } |
                    -4 | -6 | -I | -D | -B | -0 |
                    -l[oops] { maximum-addr-flush-attempts } | -br[ief] |
                    -o[neline] | -t[imestamp] | -ts[hort] | -b[atch] [filename] |
                    -rc[vbuf] [size] | -n[etns] name | -a[ll] | -c[olor]}
//}
ipコマンドで利用可能なオブジェクト・オプションについて示されている。
=== サブコマンド
ネットワークインターフェース(データを送受信するための接続ポイント)に関連するIPアドレス情報を確認できる。
==== address a
===== 実行例

//list[][][fontsize=xx-small]{
$ip address
$ip a  
※どちらも同じ結果が出力される。
//}
===== 実行結果

//list[][][fontsize=xx-small]{
qlen 1
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: ens5: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 9001 qdisc mq state UP group default qlen 1000
    link/ether 0a:16:41:0c:9e:43 brd ff:ff:ff:ff:ff:ff
    inet 172.31.13.152/20 brd 172.31.15.255 scope global ens5
       valid_lft forever preferred_lft forever
    inet6 fe80::816:41ff:fe0c:9e43/64 scope link 
       valid_lft forever preferred_lft forever
3: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default 
    link/ether 02:42:74:ff:c1:b0 brd ff:ff:ff:ff:ff:ff
    inet 172.17.0.1/16 brd 172.17.255.255 scope global docker0
       valid_lft forever preferred_lft forever
//}
qlen:キューの長さ(2つ目がens5,3つ目にdocker0という名称がついている。)
inet4:ipv4アドレス/サブネットマスクが記載されている。
inet6:ipv6アドレスが記載されている。
mtu:1回に送信できるデータパケットの最大サイズ
link/ether:MACアドレス(各ネットワークインターフェースに割り当てられた一意の物理アドレス)が書かれている。

==== route r
ルーティング(ネットワークの経路情報)を出力する。
===== 実行例

//list[][][fontsize=xx-small]{
$ip route
$ip r
※どちらも同じ結果が出力される。
//}
===== 実行結果

//list[][][fontsize=xx-small]{
default via 210.128.53.201 dev enp3s8 onlink 
210.128.53.200/29 dev enp3s8 proto kernel scope link src 210.128.53.204 
210.128.53.208/29 dev enp1s0 proto kernel scope link src 210.128.53.209 
210.128.53.216/29 via 210.128.53.212 dev enp1s0 
210.128.53.224/29 via 210.128.53.212 dev enp1s0 
210.128.53.232/29 via 210.128.53.212 dev enp1s0 
210.128.53.248/29 dev enp2s0 proto kernel scope link src 210.128.53.249
//}
default:デフォルトゲートウェイ(宛先がルーティングテーブルに存在しない場合に転送するルーター)
via ipアドレス:次に情報を渡されるルーターのipアドレスを示している。
dev enp:送信元のネットワークデバイス名
proto kernel:ルートを作成したルーティングプロトコル
scope link:送信先の範囲、linkなら自分のグループのネットワークであることを示している。
src ipアドレス:送信元のネットワークデバイスのipアドレス
