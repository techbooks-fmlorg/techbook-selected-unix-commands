#@# 

=={aws} aws

awsコマンドを使うと、
コマンドラインからAWSサービスを利用することができる。

AWS固有のコマンドなので、当然Unix標準ではない。
EC2のOSイメージではawsコマンドが標準搭載されていることが多いようだが、
OSによっては別途インストールが必要である

=== 書式

//list[][][fontsize=xx-small]{
$ aws [options] command subcommand [parameters]
//}
command部分とsubcommand部分の指定は必須である。
[options]と[parameters]はオプション

おおむねcommand部分にはサービス名（例：ec2、s3）を指定する。
subcommand部分では、そのcommandサービス固有の動作指定を行う


=== 実行例 ＜引数がないためエラー＞

//list[][][fontsize=xx-small]{
$ aws
//}

TIPS:
わざとエラーメッセージを表示して、コマンドの使い方を思い出そうとするベテランの技:-)

=== 実行結果

//list[][][fontsize=xx-small]{
$ aws
To see help text, you can run:

  aws help
  aws <command> help
  aws <command> <subcommand> help

aws: error: the following arguments are required: command
//}
aws単体だとエラーが表示される


=== aws s3 subcommand

awsで使えるコマンドは様々であるが、今回はサービスの一つであるS3のみを紹介する。

@<B>{S3（Simple Storage Service）}はAWSを代表するサービスの一つである。
きわめて耐久性が高く、
@<B>{99.999999999％（イレブン・ナイン）を超えるデータ耐久性}を唱うサービス

S3の代表的な使い方は
「ストレージサービス（データの長期保存）」と
「静的Webサイト(事前にHTMLを作成し、その通りに動くサイト)の公開」である

S3を利用する際には、まずバケットと呼ばれるファイルの入れ物を作成する。
これはUnixのディレクトリやWindowsのフォルダに相当するものと考えて良い。
ユーザは、このバケットにファイルをアップロードしていくことになる

awsコマンドでS3サービスを呼び出す場合、command部分にはs3を指定する。
subcommandで様々なファイル操作が行える。
たとえば、
バケットの内部を確認する際はsubcommnadにlsを、
データを送受信する際には、
cpもしくはsync(cpはファイル、syncはバケットとフォルダを同期)をsubcommnadに指定する。

=== 実行例 ＜S3とのファイルのやりとり＞

@<B>{注意：前提としてawsのec2にログインしている状態である。}

バケットの中身を確認する
//list[][][fontsize=xx-small]{
$ aws s3 ls S3-URI(S3のURLのようなもの)
//}
S3-URIは「S3://設定した名前」という形式である。

//list[][][fontsize=xx-small]{
ファイルの送信 $ aws s3 cp ファイル名 S3-URI

ファイルの受信 $ aws s3 cp S3-URI/ファイル名 (ファイルを入れたいディレクトリ名/)受信したときのファイル名
//}
データの受信の際にディレクトリを指定しなかった場合は、現在開いているディレクトリに保存される。

//list[][][fontsize=xx-small]{
admin@16.32.64.128$ aws s3 ls s3://b2902900  #s3(b2902900)内のバケットを確認
hello.py

admin@16.32.64.128$ ls  #現在開いているディレクトリ内のファイルを確認している
www.py   htdocs
www.pyというファイルととhtdocsという名前のディレクトリがある
//}

//list[][][fontsize=xx-small]{
admin@16.32.64.128$ aws s3 cp www.py s3://b2902900
# ec2内のwww.pyをs3(b2902900)にコピーしている
admin@16.32.64.128$ aws s3 cp s3://b2902900/hello.py hello.py
# s3(b2902900)内のバケットにあるhello.pyをec2内にhello.pyという名前でコピーしている
//}

//list[][][fontsize=xx-small]{
admin@16.32.64.128$ aws s3 ls s3://b2902900

$ ls

//}


=== 実行結果(s3 cp)

//list[][][fontsize=xx-small]{
admin@16.32.64.128$ aws s3 ls s3://b2902900
hello.py   www.py

admin@16.32.64.128$ ls
hello.py   www.py   htdocs
//}
この結果からs3のバケットにはwww.pyがEC2から送信されて、EC2にはhello.pyがs3バケットからec2に受信したのがわかる。

=== 実行例(s3 sync)

※前提としてawsのec2にログインしている状態である。
//list[][][fontsize=xx-small]{
データの送信 $ aws s3 sync ディレクトリ名 S3-URI

データの受信 $ aws s3 sync S3-URI ディレクトリ名
admin@16.32.64.128$ cd htdocs  #htdocsディレクトリに移動

admin@16.32.64.128$ ls  #htdocs内のファイルを確認
index.html   index2.html

admin@16.32.64.128$ aws s3 ls s3://b2902900  #s3(b2902900)内のバケットを確認
hello.py   www.py

admin@16.32.64.128$ aws s3 sync ./ s3://b2902900　 # ./はカレントディレクトリ(今開いてるディレクトリ)を表している。
#ec2のカレントディレクトリ(htdocs)をs3(b2902900)内のバケットに送信している

admin@16.32.64.128$ aws s3 ls s3://b2902900  #s3(b2902900)内のバケットを確認

admin@16.32.64.128$ aws s3 sync s3://b2902900 ./
#s3(b2902900)内のバケットをec2のカレントディレクトリ(htdocs)に送信している

admin@16.32.64.128$ ls

//}
=== 実行結果(s3 sync)

//list[][][fontsize=xx-small]{
admin@16.32.64.128$ aws s3 ls s3://b2902900
hello.py   index.html   index2.html   www.py

admin@16.32.64.128$ ls
hello.py   index.html   index2.html   www.py
//}
syncコマンドでs3://b2902900にindex.htmlとindex.htmlがアップロードされ、s3://b2902900内に4つのファイルが入り、
その後syncコマンドでb2902900から計4つのファイルを受信している。
