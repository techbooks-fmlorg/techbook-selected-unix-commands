#@# 

== nano

ファイル名を指定することで、指定したファイルを編集することができる。
ファイル指定をしない場合や存在しないファイルを指定したときは起動すると新規ファイルを作成し、編集ができる。
同様のテキストエディタとして、vi/vimが挙げられるが、モード変更を使用せず、
画面下部に書かれているショートカットを用いることでコピーやペースト等が行える。

===== 実行例

//list[][][fontsize=xx-small]{
nano ファイル名
//}

===== 実行結果

//list[][][fontsize=xx-small]{
ファイル名を指定して起動する
そのファイルが実行したディレクトリに無ければ作成する
その後エディタ画面になり、文字を入力できるようになる
//}

=== ショートカットについて

上記で説明した通り、nanoエディタを起動した際に、以下のような
ショートカットについての説明が確認できる。また、ショートカットについて
^という文字があるが、これはwindowsならctrl、macならcommandを示している。

//image[nano]

==== ctrl OR command +x

nanoエディタ画面から抜けるときに使用する。
これを使用した際に、保存するかどうか聞かれるのでするときはyを、しないときはnを押す。
yを押した場合、保存するファイルの名前を聞かれるので、そのままの名前ではEnterを押すと元の画面に戻る。
もし、違う名前で保存したい場合はファイル名を変更してEnterを押すことで保存される。
nを押した場合、保存せずに元の画面に戻る

==== ctrl OR command +6

後述するカット及びコピーを範囲選択する際の
始点となる部分をカーソル位置で決定する。

==== alt OR option +6

ctrl OR command +6で選択した始点からこのショートカットを利用した際のカーソル位置、
もしくはカーソルの行のコピーができる。

==== ctrl OR command +k

ctrl OR command +6で選択した始点からこのショートカットを利用した際のカーソル位置、
もしくはカーソルの行の削除ができる。

==== ctrl OR command +u

ctrl OR command+k,alt OR option +6で最後に選択したテキストをペーストできる

==== マウス操作

nanoでは文字列をドラックして選択して右クリックをした後、
コピーを選択することで、文字列のコピーができる。
同様に貼り付ける場合は、ペーストしたい位置にカーソルを移動後、
右クリックしてペーストを選択することで、文字列のペーストができる。