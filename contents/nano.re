#@# 

=={nano} @<term>{nano}

Windowsのメモ帳のような@<B>{シンプルな操作方法}の@<idx>{エディタ((えでぃた))}。

ファイル名を指定することで、指定した@<idx>{ファイル((ふぁいる))<<>>を編集する((をへんしゅうする))}ことができる。
ファイル指定をせずに起動した場合や、
存在しないファイルを指定して起動した時は、
新規ファイルの作成・編集ができる。

//note[unix-editors][Unixのエディタ]{

Unixに昔からあるテキストエディタとしては@<idx>{vi}や@<idx>{emacs}が有名だ。
viやvimには複数のモードがあるが、nanoではモード変更などない。
nanoは、モード変更を使用せず、
画面下部に書かれているショートカットを用いることでコピーやペースト等が行える
（この点、nanoの使い勝手はemacsに近いと言えよう）。

//}


#@# X-TODO nano 図のと表の位置調整
//image[nano][nano画面下のヘルプメッセージ（ショートカットのチートシート）][pos=t]

//table[nano-shortkeys][nanoョートカットキー（抜粋）]{
キー		意味
----------------------------------------
Ctrl x		終了する
Ctrl s		上書き保存
Ctrl 6		選択範囲の開始
Alt  6		選択範囲の終了
Ctrl u		ペースト
Ctrl k		いまカーソルのある行をまるごと削除
BackSpace	一文字消去(右から左へ)
DELETE		一文字消去(左から右へ)
//}


=== 書式

//list[][][fontsize=xx-small]{
$ nano [options] ファイル名
//}

=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ nano ファイル名
//}

==== 実行結果

 * ファイル名を指定して起動する
 * そのファイルが実行したディレクトリに無ければ作成する
 * その後エディタ画面になり、文字を入力できるようになる


=== ショートカットについて

上記で説明したとおり、
nanoエディタを起動した際には、
図にあるショートカットの説明が確認できる
（@<imgref>{nano}を参照）。
なお、
ショートカットにある@<B>{^}という文字は、windowsならctrl、macならcommandを示している。

#@# //image[nano][nano画面下のヘルプメッセージ（ショートカットのチートシート）][pos=b]

==== 終了する （ctrl +x もしくは command +x）

nanoエディタ画面から抜けるときに使用する。
これを使用した際に、保存するかどうか聞かれるので、保存するときはyを、保存しないときはnを押す。
yを押した場合、保存するファイルの名前を聞かれるので、そのままの名前ではEnterを押すとターミナルの画面に戻る。
もし、違う名前で保存したい場合はファイル名を変更してEnterを押すことで保存される。
nを押した場合、保存せずにターミナルの画面に戻る

==== 上書き保存する （ctrl +s もしくは command +s）

変更内容を上書き保存する場合に入力する。この場合、エディタは続行する。

==== 選択範囲の開始 （ctrl +6 もしくは command +6）

後述するカット及びコピーを範囲選択する際の
始点となる部分をカーソル位置で決定する。

==== 選択範囲の終了 （alt +6 もしくは option +6）
     
ctrl OR command +6で選択した始点からこのショートカットを利用した際のカーソル位置、
もしくはカーソルの行のコピーができる。

==== 選択範囲の削除 （ctrl +k OR command +k）

ctrl OR command +6で選択した始点からこのショートカットを利用した際のカーソル位置、
もしくはカーソルの行の削除ができる。

==== 選択範囲のペースト （ctrl +u もしくは command +u）

ctrl OR command+k,alt OR option +6で最後に選択したテキストをペーストできる


=== マウス操作

nanoでは文字列をドラックして選択して右クリックをした後、
コピーを選択することで、文字列のコピーができる。
同様に貼り付ける場合は、ペーストしたい位置にカーソルを移動後、
右クリックしてペーストを選択することで、文字列のペーストができる。
