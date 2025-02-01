#@# 

=={scp} scp

SSHを利用して、自分のコンピュータのファイルを他のコンピュータに転送するコマンド。
scpは「Secure Copy」の略。

実際に使う際は、コピー元のパスと保存先のパスを指定する。

=== 書式

//list[][][fontsize=xx-small]{
$ scp [options] SOURCE... TARGET
//}

 * 基本的に@<code>{cp}コマンドのSSH版。
   @<code>{scp コピー元ファイル コピー先ファイル}のように使う。
   コピー先ファイルがネットワークの向こう側でも良いところが@<code>{cp}と異なる
 * @<code>{cp}コマンドと同じく、
   目的地のTARGET（ターゲット）がディレクトリの場合、「SOURCE...」の部分は複数のファイルでも良い


=== 実行例

==== 実行例 

sampleファイルを、exampleという名のサーバ上の/home/testディレクトリへコピーしたい

//list[][][fontsize=xx-small]{
$ scp sample.txt testuser@example:/home/test/
//}

 *  「sample.txt」がコピー元のファイル名、「testuser@example:/home/test/」がコピー先のファイルパス
 ** testuserがコピー先のユーザ名、exampleがドメイン名（サーバ名）
 *  ホスト名の部分はIPアドレスでもよい


=== 知っていると便利なオプション:  -r

コピーしたい対象がディレクトリの場合に使用する。
指定したディレクトリ以下すべてをコピーする


==== 実行例 

sampledirディレクトリを、サーバexampleの/home/testディレクトリへコピーする

//list[][][fontsize=xx-small]{
$ scp -r sampledir testuser@example:/home/test/
//}
