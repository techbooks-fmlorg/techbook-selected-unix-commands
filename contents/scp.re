#@#

//footnote[ssh-protocol][SSH (Secure SHell) protocol]

=={scp} @<term>{scp}

SSHプロトコル@<fn>{ssh-protocol}を利用して、自分のコンピュータのファイルを他のコンピュータに転送するコマンド。
scpは「Secure Copy」の略。

=== 書式

//list[][][fontsize=xx-small]{
$ scp [options] SOURCE... TARGET
//}

 * 基本的に@<code>{cp}コマンドのSSH版。
   「@<code>{scp コピー元ファイル コピー先ファイル}」のように使う。
   コピー元/コピー先ファイルはネットワークの向こう側でも良いところが@<code>{cp}コマンドと異なる。
   @<secref>{cp}節も参照
 * @<code>{cp}コマンドと同じく、TARGET部分はディレクトリでも良い   
 * @<code>{cp}コマンドと同じく、
   TARGETがディレクトリの場合、「SOURCE...」の部分は複数のファイルでも良い

=== 実行例

==== 実行例 

sampleファイルを、exampleという名のサーバ上の/home/testディレクトリへコピーしたい

//list[][][fontsize=xx-small]{
$ scp sample.txt testuser@example:/home/test/
//}

 * 「sample.txt」がコピー元のファイル名
 * 「testuser@example:/home/test/」がコピー先のファイルパス
 ** testuserがコピー先のユーザ名@<br>{}(exampleサーバにログインする際のユーザ名)
 ** exampleがドメイン名（サーバ名）
 ** ホスト名(この例ではexample)の部分はIPアドレスでもよい


=== 知っていると便利なオプション: @<term>{-r}

コピーしたい対象がディレクトリの場合に使用する。
指定したディレクトリ以下すべてをコピーする
（再帰的（recursive）のr）。

//note[-r][-r 再帰的（recursive）オプション]{
@<idx>{-r}オプションは「@<term>{再帰((さいき))}」を意味するコマンドが多いので覚えておくと良い。
もっとも@<idx>{chmod}のように再帰に@<idx>{-r}ではなく@<idx>{-R}を使うものもあるのだが...
@<br>{}
そのうち体が覚えるので、いくつかの例外以外は@<idx>{-r}は再帰と覚えておいて間違いない。
ようするに定番オプションの付け方には規則性があるという話である。
//}

==== 実行例 

sampledirディレクトリ以下すべてを、サーバexampleの/home/testディレクトリへコピーする

//list[][][fontsize=xx-small]{
$ scp -r sampledir testuser@example:/home/test/
//}


//note[scp][scp SOURCE... TARGET/]{

TARGETがディレクトリの場合、
コピー先がディレクトリであることを強調するために
右端に@<B>{@<code>{/}}を付けることが多い。
つまり右端の@<code>{/}は付けても付けなくても良いが、
(a) ドキュメントを読む人にコマンドの意図を伝えようとする心がけは大事
(b) (たまに、うっかりエラーを回避できることもある <- 生きる知恵)

//}
