#@# 

== aws

AWS(Amazon Web Serviceの略。Amazonが提供するクラウドコンピューティングサービス)のサービスを利用することができる。
動作にはコマンド(AWSのサービス)が必須。

===== 実行例

//list[][][fontsize=xx-small]{
$ aws
//}
===== 実行結果

//list[][][fontsize=xx-small]{
To see help text, you can run:

  aws help
  aws <command> help
  aws <command> <subcommand> help

aws: error: the following arguments are required: command
//}
aws単体だとエラーが表示される
=== aws後部のコマンド
==== s3
AWSのサービスの一つである、S3(ストレージサービス、データの長期保存、URLを発行し静的なWebサイト(事前にHTMLを作成しその通りに動くサイト)を公開することなどができる)を利用できる。
パケット(S3のデータを保管しているもの)内部を確認する際はlsを利用する。データを送受信する際は、cp,sync(cpはファイル・syncはディレクトリの中身を基本的に送受信する)を利用する。

===== 実行例

//list[][][fontsize=xx-small]{
パケットの確認 $ aws s3 ls S3 URI(S3のURLのようなもの)
※S3 URIはS3://設定した名前 という形式である。

ファイルの送信 $ aws s3 cp ファイル名 S3 URI

ファイルの受信 $ aws s3 cp S3 URI/ファイル名 (ファイルを入れたいディレクトリ名/)受信したときのファイル名
※データの受信の際にディレクトリを指定しなかった場合は、現在開いているディレクトリに保存される。

データの送信 $ aws s3 sync ディレクトリ名 S3 URI

データの受信 $ aws s3 sync S3 URI ディレクトリ名

$ aws s3 ls s3://b2902900
test.txt

$ ls //現在開いているディレクトリ内のファイルを確認している
test2.txt htdocs
test2とhtdocsという名前のディレクトリがある

$ aws s3 cp test2.txt s3://b2902900

$ aws s3 cp s3://b2902900 test.txt

$ aws s3 ls 

$ ls

//}
===== 実行結果

//list[][][fontsize=xx-small]{
$ aws s3 ls s3://b2902900
test.txt    test2.txt

$ ls
test.txt    test2.txt
//}
この結果からs3のパケットにはtest2.txtがローカルから送信されて、ローカルにはtest.txtがパケットから受信したのがわかる。

===== 実行例

//list[][][fontsize=xx-small]{
$ cd htdocs //htdocsディレクトリに移動

$ ls 
hello.py w3.py
$ aws s3 ls s3://b2902900
test.txt test2.txt

$ aws s3 sync ./ s3://b2902900　// ./はカレントディレクトリ(今開いてるディレクトリ)を表している。

$ aws s3 ls s3://b2902900

$ aws s3 sync s3://b2902900 ./

$ ls

//}
===== 実行結果

//list[][][fontsize=xx-small]{
$ aws s3 ls s3://b2902900
hello.py test.txt test2.txt w3.py

$ ls
hello.py test.txt test2.txt w3.py
//}
syncコマンドでs3://b2902900にhello.pyとw3.pyがアップロードされ、s3://b2902900内に4つのファイルが入り、
その後syncコマンドでb2902900から計4つのファイルを受信している。