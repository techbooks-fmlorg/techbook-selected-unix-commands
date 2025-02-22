#@# X-TODO: ss のネットワーク周りの説明は要検討、むずかしいだろ、これ

=={ss} @<term>{ss}

コマンド名はsocket statisticsの頭文字。
ネットワーク通信で利用する@<idx>{ソケット((そけっと))<<>>についての情報を出力する((についてのじょうほうをしゅつりょくする))}。

=== 書式

//list[][][fontsize=xx-small]{
$ ss [options]
//}

 * オプションなしでは情報過多
 * 定番の@<code>{ss -l4n}の形で覚えることを推奨


=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ ss
//}

==== 実行結果

//list[][][fontsize=xx-small]{
Netid State  Recv-Q Send-Q Local Address:Port  Peer Address:PortProcess
udp   UNCONN 0      0            0.0.0.0:123        0.0.0.0:*
      〜 省略 〜
tcp   LISTEN 0      128          0.0.0.0:22         0.0.0.0:*          
tcp   LISTEN 0      511          0.0.0.0:80         0.0.0.0:*          
//}
実用上は、開いているポート番号（@<code>{:数字}部分）の確認に使うことが多い。
「IPアドレス：ポート番号」形式の部分はソケットの情報である。
その他の詳細は省略する@<fn>{ss-detail}。

//footnote[ss-detail][きちんとマニュアルに説明がないので、正解はソースコードを参照のこと。@<href>{https://www.kernel.org/pub/linux/utils/net/iproute2/}]




=== 知っていると便利なオプション: -l

数字ではなく英語小文字のエル、lima の l
（listenのlに由来する）。

接続待ち状態(StateがListen)のソケットのみを表示する。
いわゆるサーバプロセスだけを表示したいときに使用する

==== 実行例

//list[][][fontsize=xx-small]{
$ ss -l
//}


==== 実行結果

//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port
u_str LISTEN     0      128    /root/.pm2/pub.sock 24878          * 0                    
u_str LISTEN     0      128    /root/.pm2/rpc.sock 24879          * 0  
      〜 省略 〜
tcp   LISTEN     0      128     *:56958                           *:*
//}
StateがListenのもののみが表示されている。

=== 知っていると便利なオプション: -4

IPv4のソケットの情報だけを表示する。


==== 実行例

//list[][][fontsize=xx-small]{
$ ss -4  
//}

==== 実行結果

//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port                
udp   ESTAB      0      0      127.0.0.1:57674                127.0.0.1:57674                
tcp   ESTAB      0      0      127.0.0.1:6081                 127.0.0.1:35634                
tcp   ESTAB      0      0      127.0.0.1:35000                127.0.0.1:48549
      〜 省略 〜
//}
（上の例では省略されているが）Netidがudpまたはtcp、Addressがipv4の表記(x.x.x.x)のみを示している。

=== 知っていると便利なオプション: -n

名前解決を行わない(プロトコル名やドメイン名が表示されない)


=== 知っていると便利なオプション: -l4n

これまで説明したオプションl,4,nすべてを適用する。おすすめのオプション

==== 実行例

//list[][][fontsize=xx-small]{
$ ss -l4n
//}

==== 実行結果

//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q     Local Address:Port       Peer Address:Port
tcp   LISTEN     0      128        *:59707                  *:*                  
tcp   LISTEN     0      128        *:40603                  *:*     
      〜 省略 〜
//}
