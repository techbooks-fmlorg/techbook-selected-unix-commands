= Unixコマンド操作とは

== なぜ今さらUnixの訓練が必要なのか？

「競争力のあるITサービスを作れるようになるため」が答えである。

いまどきは、
ブラウザ上でクリックすれば誰でも定番のITサービスを立ち上げることが出来る。
クラウド体験であれば、これで十分だが、
定番のサービスしか作れないのではITのプロとして食べていけない。

それよりも、
定番を構築できるライバルは世界に何千万人もいることに気づいてほしい。
クラウド体験は何の競争力も産まない。
クラウドサービスで、
独自のITシステムを作りこんだり細かな調整をしようとすれば、
どうしてもクラウドの操作画面の一皮下のOSつまりUnixを触る必要がある。


== Unixは元々が研究者用OS

Unixは素人向けではない。
少人数の研究者/開発者が使う際のOSの理想像といったところだ。
のちに色々なウインドウシステムやアプリを追加して、
素人向けにも使えるようにしてきたが、
非定番の使い方をしようとすると真のUnixが顔を出してくる。
必要最小限、
余計なことは言わない、
いかにキーボードを打つ回数を減らすか？
そういったプロ向けの設計思想が初心者の敷居を高くしている所以だろう。

//image[shell-interactive][左は対話処理のイメージ。右は代表的なターミナル:Teletype Model 33][scale=1.0]

//footnote[tty][Unixのttyという用語は、このTeletypeに由来する]
//footnote[tty33]["Teletype Model 33 - 48930224272" by stiefkind is marked with CC0 1.0]
//footnote[tty33-tape][（IT古典部むけの脚注:-）左端は紙テープに穴(あり/なしで1ビットを表現)をあける機材。この写真はTeletype model 33の中でも、この機材付きモデルのもの]

#@# X-TODO ch1: TSS -> コンピュータ開発史を参照
#@# X-TODO ch1: 図/写真? Teletype model 33, Windows内のTerminal(app), App拡大図
=={interactive} 対話処理

//list[][対話処理（@<img>{shell-interactive}左側を参照）]{
$                 @<balloon>{(1)「入力待ち」の意思表示としてプロンプトを表示}
$ ls              @<balloon>{(1)の状態から、(2)ユーザがlsと入力し、ENTERを押す（Unixにlsの依頼が伝わる）}
www.py htdocs     @<balloon>{(3)（lsの依頼が）処理され、(4)lsの結果が表示される}
$                 @<balloon>{(5)プロンプトを表示（1.の状態に戻った）}
//}

@<img>{shell-interactive}（左）は、給仕（OS）と客（ユーザ）との対話イメージである。
@<img>{shell-interactive}（左）は、上述の操作と対応している。
これがUnixで言うところの対話処理である。

背景事情を少しだけ説明しよう。
@<img>{shell-interactive}（右）の機材は、
1970年代にUnixが開発されていた当時のターミナル@<fn>{tty33}@<fn>{tty}@<fn>{tty33-tape}である。
ほぼ電動タイプライターだ。
タイプすると入力がUnixに伝わり、
処理され、
Unixからの出力が一行ずつ印刷される。
これが、この当時の「コンピュータとの対話」である。

もともと、コンピュータに（一方的に）命令を伝えて、
コンピュータが何時間も計算するという使い方（バッチ処理）が主流だった。
それにくらべれば「対話」であって、現代語の対話とはイメージが異なるだろう。

現代では物理的なターミナルは使われず、
ウィンドウシステム上のターミナルアプリ（ターミナルをエミュレーションするソフトウエア）を使うことが普通だ。
しかしながら、
見かけはモダンになってはいても、
やっていることは@<img>{shell-interactive}から進化していないことを覚えておきたい。
