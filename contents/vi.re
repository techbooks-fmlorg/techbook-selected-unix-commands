#@# 

=={vi} @<term>{vi}

Linuxを含むUnixベースのOSで利用できるテキスト@<idx>{エディタ((えでぃた))}。
viは、キーボードのみでの編集を前提にしたコマンドラインベースのエディタであり、
テキスト編集のためにキーボードショートカットを使用する。


=== 書式

//list[][][fontsize=xx-small]{
$ vi [options] [file ..]
//}


=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ vi ファイル名
//}

==== 実行結果

 * ファイル名を指定して起動する
 * そのファイルが実行したディレクトリに無ければ、ファイルを新たに作成する
 * その後エディタ画面になる
    

=== コマンドモードと入力モード

viには@<B>{モード}という考え方があり、モードごとに挙動が異なる。
@<B>{コマンドモード}と@<B>{入力モード}の２つがある。
vi起動時のモードはコマンドモードになっている。

エディタとして期待される「文字などを入力できる状態」が「入力モード」だ。
コマンドモードは、その他の制御を行う状態で、
Wordでいえば画面上にある様々なボタンに対応する。


=== よく使うコマンドの紹介

//table[table-vi-commands][viのコマンドモードで知っておくと便利なコマンド]{
コマンド	説明
--------------------------------------------
ZZ		上書き保存しつつ終了
:wq		上書き保存しつつ終了
:q!		保存せずに（変更を廃棄して）、終了
:w		上書き保存（保存のみ）
yy		カーソルのある行をコピー(クリップボードへコピー)
p,P		ペースト
dd		カーソルのある行を削除
x		カーソル下の一文字を削除
//}

==== モード変更

===== i,a

コマンドモードから入力モードへ移行する。入力位置は
iキーでは現在のカーソル位置に文字が挿入される（insertのi）。
aキーではカーソル位置の右から文字が挿入される（appendのa）。

===== esc

入力モードからコマンドモードへ移行する。

==== ファイルの保存と終了

コマンドモードから以下のコマンドを実行することで保存及びエディタを終了することができる。
コマンドは画面下部で入力できる。

===== ZZ

shiftを押しながらzを二回たたくというシンプルな方法。
なぜかメジャーな方法と認識されていないらしい。
不思議。

@<B>{変更があれば上書き保存}される、
@<B>{変更がないなら即終了}という動作をする。
変更を捨てたい場合は、次の@<code>{:q!}を使うこと

===== :q!

@<B>{変更内容を保存せずに終了}する場合には@<code>{:q!}だけを入力する。

===== :w

いわゆる「@<B>{上書き保存}」。
変更内容を保存する場合に入力する。この場合、エディタは続行する。

===== :wq

いわゆる「上書き保存」をしつつ「終了」。
変更内容を保存して終了する場合に入力する。

==== コピー＆ペースト

コマンドモードから以下のコマンドを実行することで、コピー及びペーストができる。

入力モードの場合に、マウスでコピー＆ペーストも可能だ。
マウスで文字列をドラックして選択して右クリックをした後、
コピーを選択することで、文字列のコピーができる。
同様に貼り付ける場合は、ペーストしたい位置にカーソルを移動後、
右クリックしてペーストを選択することで、文字列のペーストができる。

===== yy

カーソル位置の行をコピーする。

===== 数値 +yy

カーソル位置以下の数値分の行を一括でコピーする。

===== p,P

コピーした行をペーストする。
pであればカーソルの一つ下の行に、Pであればカーソルの一つ上の行にペーストする。


=== 実行例 （コマンドモードでの操作）

次のような４行のファイルがあるとする。
今、カーソルは１行目の右端にある
//list[][][fontsize=xx-small]{
siritori|←カーソル位置 
ringo
gorira
raion
//}

説明の都合上、以下では左端に行番号をつけるが実際には無いことに注意されたい。
//list[][][fontsize=xx-small]{
1 siritori|←カーソル位置 
2 ringo
4 gorira
4 raion
//}


===== 実行例1

//list[][][fontsize=xx-small]{
1 siritori|←カーソル位置 
2 ringo
3 gorira
4 raion
//}
ここで、
コマンドモードに移行し、
@<code>{4yy}を入力する
（1行目〜4行目がコピーされた、いわゆるクリップボードへコピーされた状態）


===== 実行例2

//list[][][fontsize=xx-small]{
実行例1の続き
1 siritori
2 ringo
3 gorira
4 raion
5 |←カーソル位置 
//}
入力モードで5行目を作成（当然カーソルも移動している）し、
コマンドモードに戻り、
@<code>{p}を入力すると

===== 実行結果

//list[][][fontsize=xx-small]{
1 siritori
2 ringo
3 gorira
4 raion
5
6 siritori
7 ringo
8 gorira
9 raion
//}
6行目から9行目に（クリップボードから）1〜4行目の内容がコピーされた。

まとめると次のような操作をしたことになる。

 *  実行例1
 ** 4yyでカーソルの位置を含めて4行分(1行目～4行目)をコピー
 *  実行例2
 ** カーソルが5行目にあるところでpを実行した
 ** pは「カーソルから一つ下の行へのコピー」なので、
    5行目には何も書かれずに、
    6行目から実行例1でコピーしたテキスト(1〜4行目)が書かれる
    (コピー＆ペーストされた)。


//note[vi-learning-cost][viは使えたほうが良いのか？]{

実運用環境では、エディタがviしか入っていないUnix/Linux環境もありうるので、
最低限のvi操作方法は知っておいたほうが良い。

ただ、viの学習コストを考えると、
すなおにnanoをインストールして使う方が良いと思う
（客先の場合にはnanoを入れさせてもらう交渉をする）。
nanoについては@<secref>{nano}節を参照。
//}

//note[vi-colon-command][コマンドに:が付いたり付かなかったりするのは何故？]{

@<idx>{:<<>>で始めるコマンド((ではじめるこまんど))}は@<idx>{ex}コマンドを呼び出す呪文だ。
exとは何か？というとviの一つ前に開発されていた@<idx>{エディタ((えでぃた))}で、
実際のところviとexは同じプログラムへの異なるインターフェイスである。

こういう@<idx>{インターネット古代史((いんたーねっとこだいし))}は@<idx>{BSD}のマニュアルにはきちんと書いてあるが:-)、
vi(@<idx>{vim==>>vi})のマニュアルには書いていないようである
（少なくともDebian同梱のviには無い）。
まぁ古代史を知らなくとも困らないが、
我々の道具が何故このような形に落ち着いているのか興味ありませんか？
（「わたし、気になります！」というIT古典部気質の人は、
@<idx>{エンジニア適性((えんじにあてきせい))}があると思う）

//}
