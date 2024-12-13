#@# 

== vi

Linuxを含むUnixベースのOSで利用できるテキストエディタ。
viは、キーボードのみでの編集を前提にしたコマンドラインベースのエディタであり、
テキスト編集のためにキーボードショートカットを使用する。

===== 実行例
//list[][][fontsize=xx-small]{
vi ファイル名
//}
===== 実行結果
//list[][][fontsize=xx-small]{
ファイル名を指定して起動する
そのファイルが実行したディレクトリに無ければ作成する
その後エディタ画面になる。
//}
=== コマンドモードと入力モード

viでは、コマンドモードと入力モードを基本的に使う。
viコマンドを実行した際はコマンドモードである。

=== コマンド一覧

==== モード変更

===== i,a

コマンドモードから入力モードへ移行する。入力位置は
iキーでは現在のカーソル位置に文字が挿入される。
aキーではカーソル位置の右から文字が挿入される。

===== esc

入力モードからコマンドモードへ移行する。

==== ファイルの保存と終了

コマンドモードから以下のコマンドを実行することで保存及びエディタを終了することができる。
コマンドは画面下部で入力できる。

===== :q!

変更内容を保存せずに終了する場合に入力する。

===== :w

変更内容を保存する場合に入力する。この場合、エディタは続行する。

===== :wq

変更内容を保存して終了する場合に入力する。

=== コピー＆ペースト

コマンドモードから以下のコマンドを実行することで、コピー及びペーストができる。
またマウスでも、文字列をドラックして選択して右クリックをした後、
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

===== 実行例1

//list[][][fontsize=xx-small]{
1 siritori|←カーソル位置 
2 ringo
3 gorira
4 raion
コマンド
4yy
//}

===== 実行例2

//list[][][fontsize=xx-small]{
実行例1の続き
1 siritori
2 ringo
3 gorira
4 raion
5 |←カーソル位置 
コマンド
p
//}

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
-------------------------------------

実行例1
4yyでカーソルの位置を含めて4行分(1行目～4行目)をコピー
実行例2
カーソルが5行目にあり、pはカーソルから一つ下の行へのコピーなので、
5行目には何も書かれずに6行目から実行例1でコピーしたテキストが書かれる。