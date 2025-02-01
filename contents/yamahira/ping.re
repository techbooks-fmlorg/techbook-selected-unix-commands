#@# 

=={ping} ping

ターゲットの生死を確認するコマンド

1秒に1つのデータグラムを送信し、受信した応答内容を出力する。割り込みを受信したときに(Ctrl-C)、往復情報とパケット損失統計を計算し、簡約して出力する。ホスト間のネットワーク接続の安定性を検証する用途で利用する。

#@# X-TODO: ソナーの話は脚注か？
備考：
潜水艦のソナーに由来する。
（アクティブ）ソナーとは
「潜水艦から音波を出し、障害物から反射してくる音波を分析する」ことで水中の様子をさぐる仕組みのこと。
水中でのレーダーと考えれば良い。
@<code>{ping}コマンドは、それのサイバースペース版

=== 書式

//list[][][fontsize=xx-small]{
$ ping [options] ターゲット
//}
「ターゲット」はドメイン名かIPアドレス

=== 実行例

==== 実行例 

//list[][][fontsize=xx-small]{
$ ping IPアドレス
//}





==== 実行結果 （成功パターン:10.252.0.11から応答があったとき）



//list[][][fontsize=xx-small]{
$ ping 10.252.0.11
PING 10.252.0.11 (10.252.0.11) 56(84) bytes of data.
64 bytes from 10.252.0.11: icmp_seq=1 ttl=64 time=0.039 ms
64 bytes from 10.252.0.11: icmp_seq=2 ttl=64 time=0.042 ms
64 bytes from 10.252.0.11: icmp_seq=3 ttl=64 time=0.020 ms
64 bytes from 10.252.0.11: icmp_seq=4 ttl=64 time=0.018 ms
64 bytes from 10.252.0.11: icmp_seq=5 ttl=64 time=0.038 ms
64 bytes from 10.252.0.11: icmp_seq=6 ttl=64 time=0.017 ms
64 bytes from 10.252.0.11: icmp_seq=7 ttl=64 time=0.018 ms
^C                                    ※Ctrl-Cを打ち込んだ行
--- 10.252.0.11 ping statistics ---
7 packets transmitted, 7 received, 0% packet loss, time 6151ms
rtt min/avg/max/mdev = 0.017/0.027/0.042/0.010 ms
//}
出力の読み方

 *  icmp_seq:	pingを送信した回数
 *  ttl:		ルータの通過数(初期値-通過数)
 *  time:	送受信の往復の時間
 ** 7 packets transmitted, 7 received, 0% packet loss, time 6151ms -> パケット損失が0%



==== 実行結果 （失敗パターン:10.252.0.127から応答がなかったとき）



//list[][][fontsize=xx-small]{
$ ping 10.252.0.127
PING 10.252.0.127 (10.252.0.127) 56(84) bytes of data.
From 10.252.0.11 icmp_seq=1 Destination Host Unreachable
From 10.252.0.11 icmp_seq=2 Destination Host Unreachable
From 10.252.0.11 icmp_seq=3 Destination Host Unreachable
From 10.252.0.11 icmp_seq=4 Destination Host Unreachable
From 10.252.0.11 icmp_seq=5 Destination Host Unreachable
From 10.252.0.11 icmp_seq=6 Destination Host Unreachable
^C                                    ※Ctrl-Cを打ち込んだ行
--- 10.252.0.127 ping statistics ---
7 packets transmitted, 0 received, +6 errors, 100% packet loss, time 6152ms
pipe 4
//}

 *  icmp_seq:	pingを送信した回数
 *  ttl:	ルータの通過数(初期値-通過数)
 *  time:	送受信の往復の時間
 ** 7 packets transmitted, 0 received, +6 errors, 100% packet loss, time 6152ms
    -> パケット損失が100%
