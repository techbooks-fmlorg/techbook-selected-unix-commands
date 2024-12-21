#@# 

== ss

ネットワーク通信で利用する「ソケット」についての情報などを出力できる。

===== 実行例

//list[][][fontsize=xx-small]{
$ss
//}
===== 実行結果

//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port                
user ESTAB      0      0        * 1031009                         * 0                    
user ESTAB      0      0       /run/systemd/journal/stdout 874     * 10967                
----------省略-------------
tcp   ESTAB      0      0      172.31.1.171:41136                　172.31.101.90:nfs 
//}
Netid:ネットワーク識別子
State:ソケットの状態(ESTABなら接続中、LISTENから接続待ちなどの状態がある。)
Recv-Q:アプリケーションが読み取ってないデータ量(0ならデータを適切に処理している)
Send-Q:アプリケーションが送信していないデータ量(0ならすべてのデータを送信している)
Local Address:Port :ソケット通信におけるローカル側のソケットファイルパスまたはIPアドレスとポート番号を示している。
Peer Address:Port :ソケット通信における接続先(ピア)側のソケットファイルパスまたはIPアドレスとポート番号を示している。

=== オプション一覧

==== -l
接続待ち状態(StateがLesten)のソケットのみを表示する。
===== 実行例

//list[][][fontsize=xx-small]{
$ ss -l
//}
===== 実行結果

//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port
u_str LISTEN     0      128    /root/.pm2/pub.sock 24878          * 0                    
u_str LISTEN     0      128    /root/.pm2/rpc.sock 24879          * 0  
----------省略-------------
tcp   LISTEN     0      128      *:56958                          *:*
//}
StateがLestenのもののみが表示されている。

====　-4
IPv4のソケットの情報だけを表示する。
===== 実行例

//list[][][fontsize=xx-small]{
$ ss -4  
//}
===== 実行結果

//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port                
udp   ESTAB      0      0      127.0.0.1:57674                127.0.0.1:57674                
tcp   ESTAB      0      0      127.0.0.1:6081                 127.0.0.1:35634                
tcp   ESTAB      0      0      127.0.0.1:35000                127.0.0.1:48549
----------省略-------------
//}
省略されているが、Netidがudpまたはtcp、Addressがipv4の表記(x.x.x.x)のみを示している。

==== -n
名前解決を行わない(プロトコル名やドメイン名が表示されない)
==== -l4n
これまで説明したオプションをl,4,nの順番で行う。

===== 実行例

//list[][][fontsize=xx-small]{
$ss -l4n
//}
===== 実行結果

//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q     Local Address:Port       Peer Address:Port
tcp   LISTEN     0      128        *:59707                  *:*                  
tcp   LISTEN     0      128        *:40603                  *:*     
----------省略-------------
//}