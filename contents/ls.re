#@# 

=={ls} @<term>{ls}

いま作業している場所（ディレクトリ）内のディレクトリやファイルの情報を表示する

=== 書式

//list[][][fontsize=xx-small]{
$ ls [option] [FILE]...
//}

 * 引数がない場合、現在のディレクトリの情報を表示する
 * 引数のファイル（群）やディレクトリ（群）の個数は可変長
 * 引数のファイルやディレクトリは混在してよい


=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ ls
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ ls
htdocs python.py test.txt
//}
このディレクトリにはhtdocs python.py test.txtがある。

=== 知っていると便利なオプション: -l (エル,limaのl)

数字の1ではなく英語小文字のエル、lima の l。
ファイル・ディレクトリの権限が確認できる。
@<idx>{権限((けんげん))}の読み方は
@<secref>{chmod}節を参照

==== 実行例

//list[][][fontsize=xx-small]{
$ ls -l
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ ls -l
drwxr-xr-x 2 user group  4096 Sep 08:14:44 htdocs
-rw-r--r-- 1 user group 10239 Dec 08 15:36 python.py
-rw-r--r-- 1 user group 10239 Sep 08 15:38 test.txt
//}

 * @<B>{d,r,w,x,-}という文字列の意味は、それぞれ以下のとおり
 ** 左端の@<B>{d}はディレクトリを意味する。@<B>{-}はファイルである
 ** @<B>{r}は読み取り権限、@<B>{w}は書き込み権限である。
    @<B>{x}はファイルとディレクトリで意味が異なる。
    ファイルの場合は実行権限つまり「プログラムとして実行できる」という意味。
    ディレクトリの場合、そのディレクトリの中を見たり/中へ移動できるという意味@<fn>{ls-searchable}
 *  1行目の@<code>{htdocs}は（左端がdなので）ディレクトリ
 ** ユーザは@<B>{rwx}、
    グループ(グループ名:groupに属しているユーザ)の権限は@<B>{r-x}、
    他者@<fn>{ls-other}の権限も@<B>{r-x}である
 ** @<B>{r}と@<B>{x}は共通なので、
    @<B>{全ユーザがディレクトリの中を見ることが出来て、かつディレクトリ内に移動も可能}
 ** @<B>{w}があるのはユーザだけなので、
    @<B>{ユーザ本人のみがディレクトリに書き込める（htdocs内に新たにファイルやディレクトリを作成できる）}
 *  2行目と3行目はファイル
 ** python.pyとtest.txtは左端が@<B>{-}となっているのでファイル
 ** ユーザの権限は@<B>{rw-}なので、ユーザ（user）は@<B>{読み書き可能}
 ** groupに属するユーザは@<B>{r--}なので@<B>{読み取りのみ可能}
 ** 他者も同様に@<B>{r--}なので@<B>{読み取りのみ可能}

//footnote[ls-other][他者(others)とは、ユーザつまりファイルのオーナー（所有者）でもなく、ファイルのグループにも属していないユーザ]

=== 知っていると便利なオプション: -a

隠しファイル・隠しディレクトリを含めた全てのファイルを表示する。

==== 実行例

//list[][][fontsize=xx-small]{
$ ls -a
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ ls -a
.ssh .bash_history test.txt htdocs python.py 
//}
隠しディレクトリである.sshと隠しファイルの.bash_historyも表示されている。


//footnote[ls-searchable][原語のsearchable(検索〜)も不明瞭。正確な説明は難しい（@<hd>{chmod}節も参照）]
