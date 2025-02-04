#@# 

=={ip} ip

ネットワークデバイスやルーティング、ポリシーなどの表示や変更ができる。
演習で使うのは
@<code>{ip a}
と
@<code>{ip r}
だけだろうから、これくらいは覚えておきたい


=== 書式

//list[][][fontsize=xx-small]{
$ ip [ options ] OBJECT COMMAND
$ ip [ options ] OBJECT help
//}

 * OBJECT部分では、
   @<B>{address}（IPアドレス）や
   @<B>{route}（経路情報）など、
   ネットワークの構成要素を指定する。
 * COMMAND部分には、そのOBJECTごとのコマンドが利用できる。
 * COMMANDを指定しない場合は、たいてい情報の表示が行われる。
   たとえば、
   @<code>{ip address}
   は
   @<code>{ip address show}
   と同じ意味に解釈され、現在のIPアドレス情報が表示される
 * もしCOMMANDが分からない場合は、
   OBJECTに関わらずhelpコマンドを指定すればヘルプメッセージが表示される


=== 実行例: IPアドレス情報を調べる （ip address）

address オブジェクト（省略してaも可）を用いて、
ネットワークインターフェース(データを送受信するための接続ポイント)に関連するIPアドレス情報を確認できる。

==== 実行例

//list[][][fontsize=xx-small]{
$ ip address
$ ip a  
//}
どちらも同じ結果が出力される。

==== 実行結果

//list[][][fontsize=xx-small]{
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
   〜省略〜
2: enp4s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 9001 qdisc mq state UP group default qlen 1000
    link/ether 0a:16:41:0c:9e:43 brd ff:ff:ff:ff:ff:ff
    inet 172.31.13.152/20 brd 172.31.15.255 scope global ens5
       valid_lft forever preferred_lft forever
    inet6 fe80::816:41ff:fe0c:9e43/64 scope link 
       valid_lft forever preferred_lft forever
3: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default 
   〜省略〜
//}

最重要の確認項目は次の２つ。

 *  inet:	ipv4アドレス/サブネットマスクが記載されている。
 ** 上の例では、172.31.13.152/20
 *  link/ether:	MACアドレス(各ネットワークインターフェースに割り当てられた一意の物理アドレス)が書かれている。
 ** 上の例では、0a:16:41:0c:9e:43

左端の数字に特別な意味はない。
@<code>{2: enp4s0:}の@<code>{enp4s0}部分はネットワークインターフェイスの名前である。
この名前はOSが割り当てるため、OSやハードウエア構成によって異なる値を取ることに注意。
あくまでもenp4s0は一例である。
一昔前までLinuxではeth0のような名前の付け方をしていたが、
最近、enp4s0のようなハードウエア情報に基づく名前の付け方に変わった
（最初からそうしておけばよかったのに！と思ったあなたは同志です:-）


=== 実行例: IPアドレス情報を調べる （ip route）

route オブジェクト（省略してrも可）を指定すると、
ルーティング(ネットワークの経路情報)を出力する。

==== 実行例

//list[][][fontsize=xx-small]{
$ ip route
$ ip r
//}
どちらも同じ結果が出力される。

==== 実行結果

//list[][][fontsize=xx-small]{
default via 210.128.53.201 dev enp3s8 onlink 
210.128.53.200/29 dev enp3s8 proto kernel scope link src 210.128.53.204 
210.128.53.208/29 dev enp1s0 proto kernel scope link src 210.128.53.209 
210.128.53.216/29 via 210.128.53.212 dev enp1s0 
210.128.53.224/29 via 210.128.53.212 dev enp1s0 
210.128.53.232/29 via 210.128.53.212 dev enp1s0 
210.128.53.248/29 dev enp2s0 proto kernel scope link src 210.128.53.249
//}

 * 1行目のdefault行はデフォルトルートの情報
 ** デフォルトルートとは、宛先がマッチしない場合の転送先ルータ。
    「マッチしない」とは2行目以降のネットワークに該当するものがないこと
 ** @<code>{default via 210.128.53.201}の@<code>{210.128.53.201}が転送先
 ** dev enp3s8 は210.128.53.201が存在するネットワークのインターフェイス（デバイス）名。
    一つのPCにネットワークインターフェイスは複数ありうるので、それを区別するための情報。
    このenp3s8のような名前は@<code>{ip address show}で表示されていたことを思い出せ
 * 2行目以降はネットワーク（IPアドレス/マスク）ごとのルーティング情報
 ** 例えば2行目の@<code>{210.128.53.200/29}は、
    @<code>{210.128.53.200/29}というアドレス範囲への通信のルーティング情報
 ** dev enp3s8のenp3s8は、
    @<code>{210.128.53.200/29}が存在するネットワークのインターフェイス（デバイス）名。
 ** src 210.128.53.204のIPアドレスはネットワークインターフェイス（デバイス）のIPアドレス。    つまりenp3s8に付いているIPアドレスと同じ


//note[column-ip][ipコマンドによる設定変更は原則おこなわない]{

ipコマンドによる設定変更も可能だが、
これは障害対応の場合にのみ許される作業と考えておいたほうがよい。

通常、ネットワークの設定は/etc以下の設定ファイルにもとづきOS起動時に行われる。
ネットワーク関連の変更は/etc以下を適切に変更後、再起動してOSに設定してもらうべきである

ちなみに、オブジェクト指向言語っぽい書き方をすれば、次のようになるだろう。
Unixはスペース区切りなので、これを上のように表記すると考えてほしい
//list[][][fontsize=xx-small]{
ip->OBJECT->COMMAND();

例：IPアドレスを表示せよ
ip->address->show();
//}

//}
