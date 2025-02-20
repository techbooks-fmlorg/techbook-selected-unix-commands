#@# 

=={aws} @<term>{aws}

awsコマンドを使うと、
コマンドラインからAWSサービスを利用することができる。

AWS固有のコマンドなので、当然Unix標準ではない。
EC2のOSイメージではawsコマンドが標準搭載されていることが多いようだが、
OSによっては別途インストールが必要である

=== 書式

//list[][][fontsize=xx-small]{
$ aws [options] command subcommand [parameters]
//}

 * command部分とsubcommand部分の指定は必須である
 ** command部分にはサービス名（例：ec2、s3）を指定する
 ** subcommand部分では、そのcommandサービス固有の動作指定を行う
 * [options]と[parameters]はオプション


=== 実行例

==== 実行例 （引数がなくエラー、ヘルプメッセージが表示される）

//list[][][fontsize=xx-small]{
$ aws
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ aws
To see help text, you can run:

  aws help
  aws <command> help
  aws <command> <subcommand> help

aws: error: the following arguments are required: command
//}
aws単体だとエラーが表示される。

備考：これは、
コマンドの使い方がわからない場合に、
「わざとエラーを起こしてヘルプメッセージを表示させる」という技。
ほぼ、どんなときでも使える便利な技なので身につけたいところだ。


=== @<idx>{aws<<>> s3} subcommand

awsで使えるコマンドは様々であるが、今回はサービスの一つであるS3のみを紹介する。

@<B>{S3（Simple Storage Service）}はAWSを代表するサービスの一つである。
きわめて耐久性が高く、
@<B>{99.999999999％（イレブン・ナイン）を超えるデータ耐久性}を唱う。

S3の代表的な使い方は
「@<idx>{ストレージ((すとれーじ))}サービス（データの長期保存）」と
「@<idx>{静的Webサイト((せいてきうえぶさいと))}(事前にHTMLを作成し、その通りに動くサイト)の公開」である

S3を利用する際には、まず@<B>{バケット}と呼ばれるファイルの入れ物を作成する。
これはUnixのディレクトリやWindowsのフォルダに相当するものと考えて良い。
ユーザは、このバケットにファイルをアップロードしていくことになる

awsコマンドでS3サービスを呼び出す場合、command部分にはs3を指定する。
subcommandで様々なファイル操作が行える。例：

 * バケットの内部を確認する際は ls 
 * データの送受信は cp もしくは sync
 ** cpはファイル、syncはバケットとフォルダを同期
 ** 注：操作方法はcpもsyncも同じなのでsyncの実行例は省略する


==== 前提

以下の実行例では、次の前提がある

 *  @<code>{$ }は、AWSのEC2にログインしている状態での操作である
 ** 今は、ユーザadminのホームディレクトリ(/home/admin)にいる
 ** このディレクトリにはwww.pyファイルとhtdocsディレクトリがある
 *  AWS S3の管理画面で、事前にバケットは作成済
 ** バケット名はtestBucket
 *  バケットはURLで指定する。
     書式は@<code>{プロトコル://バケット名}
 ** @<code>{s3://testBucket}

=== 実行例: S3バケットの中身を確認する (@<idx>{aws<<>> s3 ls})

@<code>{aws s3 ls}でバケットの中身を確認できる。
lsコマンドの素直な拡張といえる
（@<secref>{ls}節も参照）

==== 書式

//list[][][fontsize=xx-small]{
$ aws s3 ls バケットのURL
//}

==== 実行例

//list[][][fontsize=xx-small]{
$ aws s3 ls s3://testBucket
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ aws s3 ls s3://testBucket
hello.py
//}
バケットにファイルhello.pyがあると表示されている



=== 実行例: ファイルをS3に送る (@<idx>{aws<<>> s3 cp})

EC2上のwww.pyをS3バケットにコピーする

==== 書式

//list[][][fontsize=xx-small]{
$ aws s3 cp ファイル名 バケットのURL
//}

==== 実行例

//list[][][fontsize=xx-small]{
$ aws s3 cp ファイル名 s3://testBucket
//}

==== 実行結果

//list[][][fontsize=xx-small]{
$ aws s3 cp www.py s3://testBucket
//}

無事にコピーされたかどうか？は、@<code>{aws s3 ls}コマンドを再度実行してみるか、AWS S3の管理画面で確認する
//list[][][fontsize=xx-small]{
$ aws s3 ls s3://testBucket
hello.py   www.py
//}


=== 実行例: S3からファイルを取り出す (aws s3 cp)

==== 書式

//list[][][fontsize=xx-small]{
$ aws s3 cp s3://testBucket/ファイル名 .
$ aws s3 cp s3://testBucket/ファイル名 ファイル名
$ aws s3 cp s3://testBucket/ファイル名 ディレクトリ名
//}

==== 実行例

//list[][][fontsize=xx-small]{
$ aws s3 cp s3://testBucket/hello.py hello.py
//}
S3バケットにあるhello.pyをec2内にhello.pyという名前でコピーする

==== 実行結果

//list[][][fontsize=xx-small]{
$ aws s3 cp s3://testBucket/hello.py hello.py
$ ls
hello.py   www.py   htdocs
//}
EC2上にhello.pyファイルが増えたことが分かる
