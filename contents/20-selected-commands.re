= 厳選Unixコマンド

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
ほぼ、どんなときでも便利な技なので身につけたいところだ。





=== aws s3 subcommand




awsで使えるコマンドは様々であるが、今回はサービスの一つであるS3のみを紹介する。

@<B>{S3（Simple Storage Service）}はAWSを代表するサービスの一つである。
きわめて耐久性が高く、
@<B>{99.999999999％（イレブン・ナイン）を超えるデータ耐久性}を唱う。

S3の代表的な使い方は
「ストレージサービス（データの長期保存）」と
「静的Webサイト(事前にHTMLを作成し、その通りに動くサイト)の公開」である

S3を利用する際には、まず@<B>{バケット}と呼ばれるファイルの入れ物を作成する。
これはUnixのディレクトリやWindowsのフォルダに相当するものと考えて良い。
ユーザは、このバケットにファイルをアップロードしていくことになる

awsコマンドでS3サービスを呼び出す場合、command部分にはs3を指定する。
subcommandで様々なファイル操作が行える。例：

 * バケットの内部を確認する際 ls 
 * データの送受信は cp もしくは sync
 ** cpはファイル、syncはバケットとフォルダを同期
 ** 注：操作方法はcpもsyncも同じなのでsyncの実行例は省略する





==== 前提




以下の実行例では、次の前提がある

 *  @<code>{$ }は、AWSのEC2にログインしている状態での操作である
 ** 今は、ユーザadminのホームディレクトリ(/home/admin)にいる
 ** このディレクトリにはwww.pyファイルとhtdocsディレクトリがある想定
 *  事前にAWS S3の管理画面でバケットを作成した
 ** バケット名はtestBucket
 *  バケットはURLで指定する。
     書式は@<code>{プロトコル://バケット名}
 ** @<code>{s3://testBucket}




=== 実行例: S3バケットの中身を確認する (aws s3 ls)




@<code>{aws s3 ls}でバケットの中身を確認できる。
lsコマンドの素直な拡張といえる
（@<secref>{ls}節も参照）




==== 書式




//list[][][fontsize=xx-small]{
$ aws s3 ls バケット
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






=== 実行例: ファイルをS3に送る (aws s3 cp)




EC2上のwww.pyをS3バケットにコピーする




==== 書式




//list[][][fontsize=xx-small]{
$ aws s3 cp ファイル名 バケット
//}




==== 実行例




//list[][][fontsize=xx-small]{
$ aws s3 cp ファイル名 s3://testBucket
//}




==== 実行結果




//list[][][fontsize=xx-small]{
$ aws s3 cp www.py s3://testBucket
//}

コピーされたか？は@<code>{aws s3 ls}するかAWS S3の管理画面で確認できる
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



#@# 




=={chmod} chmod




ファイルやディレクトリの@<B>{パーミッション（アクセス権限）}を変更することができる。  
これにより、ファイルやディレクトリに対する@<B>{読み取り、書き込み、実行}などの権限を設定することができる。




=== 書式




//list[][][fontsize=xx-small]{
$ chmod [オプション] モード ファイル...
//}

 * 「モード」部分には、数値を用いた絶対値指定と、シンボルによる指定がある。
 ** 数値指定では、以下の値を足し合わせた 8 進数を用いる。
    @<table>{table-chmod-number}を参照
 ** シンボルは、
    @<table>{table-chmod-symbol-who}と@<table>{table-chmod-symbol-perm}を参照 
 * 「ファイル...」部分には、
   ファイル、ディレクトリ、複数のファイルやディレクトリを指定できる。

たとえば、所有者に読み込み・書き込み・実行を許可し、グループのメンバに読み込み・実行を許可し、 他者に読み込み・実行を許可する絶対値指定のモードは、 755 (400+200+100+040+010+004+001) となる。

who シンボルの'u','g','o'はそれぞれユーザ、グループ、それ以外に相当する。
'a'シンボルは'ugo'を指定した場合と同じになる。
@<table>{table-chmod-symbol-who}を参照

perm シンボルはモードの各ビットを
@<table>{table-chmod-symbol-perm}
のように表現する。


//table[table-chmod-number][絶対値指定]{
値	説明
----------------------------------------
400	所有者の読み込みを許可。
200	所有者の書き込みを許可。
100	ファイルの場合、所有者の実行を許可。 ディレクトリの場合、所有者の検索を許可。
040	グループのメンバの読み込みを許可。
020	グループのメンバの書き込みを許可。
010	ファイルの場合、グループのメンバの実行を許可。
　	ディレクトリの場合、グループのメンバの検索を許可。
004	他者の読み込みを許可。
002	他者の書き込みを許可。
001	ファイルの場合、他者の実行を許可。 ディレクトリの場合、他者の検索を許可。
//}

//table[table-chmod-symbol-who][シンボル指定(who)]{
だれ	説明
------------------------------------
u	元の、ファイルの所有者許可ビット
g	元の、ファイルのグループ許可ビット
o	元のファイルの所有者とグループ以外の許可ビット
//}

//table[table-chmod-symbol-perm][シンボル指定(perm)]{
権限	説明
------------------------------------
r	読み込み許可ビット
w	書き込み許可ビット
x	実行もしくは検索許可ビット
//}






=== 実行例 




パーミッションが0664(rw-rw-r--)のtext.txtに0644(rw-r--r--)を設定する。

//list[][][fontsize=xx-small]{
$ ls -l ※このコマンドでファイルの権限を確認できる
-rw-rw-r-- 1 admin205 group205 63 Sep 10 16:07 test.txt

$ chmod 644 text.txt
もしくは
$ chmod u=rw,g=r,o=r text.txt

$ ls -l
//}




==== 実行結果




※変更前
-rw-rw-r-- 1 admin205 group205 63 Sep 10 16:07 test.txt

※変更後
-rw-r--r-- 1 admin205 group205 63 Sep 10 16:07 test.txt




==== 解説




パーミッションが0664(rw-rw-r--)のtext.txtに0644(rw-r--r--)を変更された。
text.txtの権限を所有者(admin205)が読み書き可能に、
その他の人(group205に所属する人、それ以外の人)が読み取り可能に変更されている。




=== 知っていると便利なオプション: -v もしくは --verbose




処理されたファイルごとに診断結果を出力する

注意： LinuxとWindowsのみ。伝統のchmodコマンドに、このオプションは無い





==== 実行例 




//list[][][fontsize=xx-small]{
$ chmod -v 614 text.txt
//}




==== 実行結果 




//list[][][fontsize=xx-small]{
$ chmod -v 614 text.txt
'test.txt' モードを 0644 (rw-r--r--) から 0614 (rw---xr--)へ変更しました
//}
-vがない場合は何も表示されない



#@#  -p, -v options




=={cp} cp




ファイルをコピーする





=== 書式




//list[][][fontsize=xx-small]{
$ cp コピー元 コピー先
//}





=== 実行例




以下の実行例では、@<B>{tree}コマンドで現階層以下のファイルやディレクトリ状況を表示する。
この@<B>{tree}コマンドとは、
ディレクトリ内のファイル・ディレクトリをツリー形式で表示するコマンドである
（詳細は@<secref>{tree}を参照）




==== 実行例１




いま作業しているディレクトリ以下には、次のようにhtdocsフォルダとtest.txtがある。

//list[][][fontsize=xx-small]{
$ tree
.
├──htdocs
└─test.txt
//}

コピーを実行する
//list[][][fontsize=xx-small]{
$ cp test.txt test2.txt
//}





==== 実行結果１




//list[][][fontsize=xx-small]{
$ cp test.txt test2.txt
$ tree
.
├──htdocs
├──test2.txt
└──test.txt
//}
作成したtest2.txtファイルとtest.txtファイルの中身は同じである。





==== 実行例２




引数を次のようにすれば、htdocs内にtest2.txtをコピーできる。

//list[][][fontsize=xx-small]{
$ cp test.txt htdocs/test2.txt
//}




==== 実行結果２




//list[][][fontsize=xx-small]{
$ cp test.txt htdocs/test2.txt

$ tree
.
├──htdocs
│   └──test2.txt
└──test.txt
//}




#@# 




=={curl} curl




HTTPリクエストを利用してデータを取得する。
ブラウザの代わりやファイルをダウンロードするといった用途で利用できる。




=== 書式




//list[][][fontsize=xx-small]{
$ curl [オプション] URL
//}




=== 実行例




 https://api.fml.org/dist/lsform.htmlにアクセスする
 



==== 実行例




//list[][][fontsize=xx-small]{
$ curl https://api.fml.org/dist/lsform.html
//}





==== 実行結果




//list[][][fontsize=xx-small]{
$ curl https://api.fml.org/dist/lsform.html
<P>SHOPPING CART
<form method="POST" action="https://api.fml.org/api/lsform/v1">
	<P>item-01
		<input name="item-01"  type="text">
	<P>item-02
		<input name="item-02"  type="text">
	<P>item-03
		<input name="item-03"  type="text">
	<P>
	<input type="submit" value="buy">
</form>
//}

出力の読み方：
URL(https://api.fml.org/dist/lsform.html)で指定したlsform.htmlファイルを取得し、htmlファイルの中身を出力している。

//note[curl][curlを引数なしで実行するとファイルを作成しない]{

curlを引数なしで実行した場合、ファイルは作成しない。
ダウンロードしたコンテンツを、
画面に表示するだけであることに注意。

ファイルとして保存したいなら、次の@<code>{-O}もしくは@<code>{-o}オプションを使うこと
//}





=== 知っていると便利なオプション







==== -o (小文字 o、英小文字のオー、OscarのO)




出力結果をファイルに保存する。




===== 実行例 




//list[][][fontsize=xx-small]{
$ curl -o 保存するファイル名 URL
//}




===== 実行結果 （https://api.fml.org/dist/www.pyの中身を3w.pyに保存する場合）




//list[][][fontsize=xx-small]{
$ curl -o 3w.py https://api.fml.org/dist/www.py
	% Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
																Dload  Upload   Total   Spent    Left  Speed
100  9698  100  9698    0     0  99644      0 --:--:-- --:--:-- --:--:-- 99979

$ ls  ※ディレクトリ内のファイルを確認
3w.py
//}





==== -O (大文字 O、英大文字のオー、OscarのO)




出力結果をリモートファイルと同じ名前で保存する。





===== 実行例 




//list[][][fontsize=xx-small]{
$ curl -O URL
//}





===== 実行結果 （https://api.fml.org/dist/www.pyを保存する場合）




//list[][][fontsize=xx-small]{
$ curl -O https://api.fml.org/dist/www.py
	% Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
																Dload  Upload   Total   Spent    Left  Speed
100  9698  100  9698    0     0  99644      0 --:--:-- --:--:-- --:--:-- 99979

$ ls  ※ディレクトリ内のファイルを確認
www.py
//}




#@# 




=={df} df




Unixのストレージ利用状況を確認できる。




=== 書式




//list[][][fontsize=xx-small]{
$ df 
//}




=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ df 
//}




==== 実行結果




//list[][][fontsize=xx-small]{
Filesystem     1K-blocks    Used Available Use% Mounted on
udev              485284       0    485284   0% /dev
tmpfs              99332     488     98844   1% /run
/dev/xvda1       8025124 1944152   5651764  26% /
tmpfs             496660       0    496660   0% /dev/shm
tmpfs               5120       0      5120   0% /run/lock
/dev/xvda15       126678   11840    114838  10% /boot/efi
tmpfs              99332       0     99332   0% /run/user/1000
//}

読み方は@<table>{df}のとおり

//table[df][dfの読み方]{
dfの一行目	説明
----------------------------------------
Filesystem	各ファイルシステム
1K-blocks	使用できるディスク容量、基本単位はKBである(udevは485284KBである)
Used		使用しているディスク容量
Available	ディスクの空き容量
Use%		ディスクの使用率
Mounted on	どのフォルダでファイルシステムが使えるかを示している
　		(udevは/devというフォルダが使える)。
//}





=== 知っていると便利なオプション







==== -m



MB単位で出力する。(1MB=1024KB)




===== 実行例




//list[][][fontsize=xx-small]{
$　df -m 
//}




===== 実行結果




//list[][][fontsize=xx-small]{
Filesystem     1M-blocks  Used Available Use% Mounted on
udev                 474     0       474   0% /dev
tmpfs                 98     1        97   1% /run
/dev/xvda1          7838  1899      5520  26% /
tmpfs                486     0       486   0% /dev/shm
tmpfs                  5     0         5   0% /run/lock
/dev/xvda15          124    12       113  10% /boot/efi
tmpfs                 98     0        98   0% /run/user/1000   
//}
udevの485284KB/1024=473.9…からMBに変換されていることがわかる。


//note[df][dfをGBやTB単位で表示したい]{

いまどきのストレージは大きいのでMBどころかGBやTB単位で表示してほしいと思うかもしれない。
KBとMBの表示は良いのだが、
それより大きい単位はLinux(GNU)系とBSDでオプションが異なる。

//}

//note[IO-unit][ストレージやIOの基本単位]{

dfに限らずストレージやIO統計のツールでは、表示の単位に気をつけたい。
歴史的にストレージの基本単位は1セクタ512バイトであるが、
ツールの表示が何を単位にしているかは
ツールやOSごとにマチマチであるので注意が必要だ。

セクタ数表示なのか？バイト表示なのか？
1000で割った数字なのか？など気をつける点がいろいろある。
正解はマニュアルを読めとしか言えないのだが...

//}



#@# 




=={exit} exit




sshやsudoコマンドでログインしたときにログアウトできる。
Windowsなどで、
ターミナルアプリの画面でexitコマンドを実行した場合は、そのターミナルアプリごと閉じてしまうことに注意





=== 書式




//list[][][fontsize=xx-small]{
$ exit
//}





=== 実行例




以下、Windows上のターミナルアプリ上でsshコマンドを実行し、
EC2(AWSのサービスの一つ)上に作成したDebianのサーバにSSHログインしている前提とする

#@# X-TODO: Windowsのターミナル画面の図が欲しいところ
//list[][][fontsize=xx-small]{
Windowsのターミナルアプリ ---(SSH)---> Debian GNU/Linxu (EC2)
//}





==== 実行例1 （EC2からログアウトする）




//list[][][fontsize=xx-small]{
admin@16.32.64.128$ exit
//}
Debian上で@<B>{exit}コマンドを実行する




==== 実行結果1




//list[][][fontsize=xx-small]{
admin@16.32.64.128$ exit
Script done.
Connection to 16.32.64.128 closed.
user:~$   
//}
ssh先からログアウトして、Windowsのターミナルに戻る。
出力例の最終行@<code>{user:~$ }はSSH元のPCのターミナルに戻ってきた様子。


#@# X-TODO: これはWindowsのターミナル画面の図を貼るべきなのでは？



==== 実行例2 （Windowsのターミナルアプリからログアウトする）




//list[][][fontsize=xx-small]{
user$ exit
//}
（実行例1の続きで）いまはWindowsのターミナルに戻っている。
その上で、もういちどexitを実行すると




==== 実行結果2




ターミナルアプリの画面ごと閉じてしまう



#@# 




=={host} host




host コマンドの引数を検索し、
その引数に紐づくドメイン名やIPアドレスの情報を出力する。
よく使う操作に次のものがある。

 * 正引き: 引数がドメイン名 -> IPアドレスを出力
 * 逆引き: 引数がIPアドレス -> ドメイン名を出力

//note[domainname][ドメイン名]{

ドメイン名とは、インターネット上で個々のコンピュータやネットワークを識別し、接続先を指定するために使用される名称の一部のことである。
身近な例をあげれば、
私たち個人がそれぞれ生活する場所の住所 (すなわち、インターネット上における私たち個人の住所) と同義である

//}





==== 書式




//list[][][fontsize=xx-small]{
$ host 名前
//}
「名前」の部分にはドメイン名やIPアドレスを指定する

以下に「正引き」と「逆引き」の実行例を示す。





==== 実行例 （正引き：ドメイン名を指定する）




//list[][][fontsize=xx-small]{
$ host ドメイン名
//}





==== 実行結果 （例：host portal.net.fml.org と入力した場合）




//list[][][fontsize=xx-small]{
$ host portal.net.fml.org
portal.net.fml.org has address 210.128.53.254
//}

出力(portal.net.fml.org has ...)右端のIPアドレス（210.128.53.254）部分が、
回答（引数のドメイン名に紐づくIPアドレス）である。





==== 実行例 （逆引き：ip アドレスを指定する）




//list[][][fontsize=xx-small]{
$ host IPアドレス
//}





==== 実行結果 (例：host 210.128.53.254 と入力した場合)




//list[][][fontsize=xx-small]{
$ host 210.128.53.254
254.53.128.210.in-addr.arpa domain name pointer portal.net.fml.org.
//}

出力(254.53.128.210. ...)行の右端、
domain name pointerの右に続く
@<code>{portal.net.fml.org}という文字列部分が回答である。
引数（210.128.53.254）に紐づくドメイン名になっている。


//note[host-dig-and-nslookup][host, dig, nslookupコマンド]{

host コマンドと似たような出力をするコマンドとして、他には dig と nslookup コマンドが存在する。ただし、dig と nslookup コマンドはインストールしていないと使用できない。
Windows の場合は、host コマンドの代わりに nslookup コマンドが標準搭載されておりインストールすることなく使用できる。dig コマンドはインストールが必要となる。
使用している OS によって使用できるかどうかが異なる場合があるため、注意が必要である。

//}



#@# 




=={hostname} hostname




このコマンドを実行したコンピュータのホスト名を表示する。
SSH接続している場合、接続先のホスト名が表示される。
また、Unix 系の OS (Debian や Ubuntu など)ではホスト名の確認に加えて、ホスト名を設定することができる。
以下に、ホスト名の確認と設定の実行例を示す。


#@# X-TODO hostname column 場所のチューニング 
//note[column-hostname][ホスト名]{

@<B>{ホスト名}とは、
ネットワークに接続された機器を識別・特定するために、各機器に付けられる名前のことである。
身近で例えると、私たちの氏名や免許証・マイナンバーカードといったその人を象徴するものと同義である。

hostnameコマンドで、@<B>{どこで作業をしているのか？}を確認できる。
つねに、@<B>{どこで作業をしているのか？}を確認することを心がけてほしい

//}




==== 書式




//list[][][fontsize=xx-small]{
$ hostname
//}





==== 実行例 (ホスト名の確認)






//list[][][fontsize=xx-small]{
$ hostname
//}








==== 実行結果






//list[][][fontsize=xx-small]{
$ hostname
ip-172-31-9-130
//}



この場合、「ip-172-31-9-130」がホスト名となる。
※ Windows はこのホスト名の確認のみ行うことができる。






==== 実行例 (ホスト名の設定) ※ Unix 系 OS 限定・Windowsは不可






//list[][][fontsize=xx-small]{
$ hostname <設定したいホスト名>
//}








==== 実行結果






//list[][][fontsize=xx-small]{
$ hostname debian.sample
//}



//list[][][fontsize=xx-small]{
$ hostname
debian.sample
//}


ホスト名の設定を行う場合、実行しても設定結果が出力されるわけではないため、改めて hostname コマンドなどを実行し確認する必要がある。
ただし、ホスト名の設定には管理者 (root) 権限が必要となるため、多くの場合、hostname コマンドの前に sudo コマンドをつけなくてはいけない。
また、hostname コマンドで設定したホスト名は恒久的には変更されず、再起動すると設定前のホスト名に変更される。

//note[column-set-hostname][ホスト名を設定する]{

hostnameコマンドでホスト名をつける作業は（できないわけではないが）めったに行わない。

OSの各種設定は/etc以下の設定ファイルを適切に編集し、
再起動、
設定が反映されていることを確認するべきである

//}



#@# 




=={id} id




ユーザーIDやユーザー名、グループID、グループ名などの識別情報を出力する。
自分（自分のユーザ名）の役割や権限を確認するために利用する。





==== 書式




//list[][][fontsize=xx-small]{
$ id

$ id ユーザ名
//}
「ユーザ名」を指定しない場合は、このコマンドを実行している「ユーザ名」の情報が表示される。
たとえば、AWSのDebianイメージであれば、通常あなたの使うユーザはadminである。
よって
//list[][][fontsize=xx-small]{
$ id
//}
も
//list[][][fontsize=xx-small]{
$ id admin
//}
も同じようにユーザadminの情報を表示する





=== 実行例







==== 実行例 




//list[][][fontsize=xx-small]{
$ id admin
//}






==== 実行結果 （ユーザ名がadminのユーザ情報を出力する場合）




//list[][][fontsize=xx-small]{
$ id admin
uid=1000(admin) gid=1000(admin) groups=1000(admin),4(adm),20(dialout),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev)
//}
ユーザ名adminのユーザIDや所属グループがわかる

 * uid=1000(admin):				ユーザ名がadmin、ユーザIDが1000
 * gid=1000(admin):				グループ名がadmin、グループIDが1000
 * groups=1000(admin),4(adm),20(dialout):	admin,adm,dialoutグループに所属







==== 実行結果 （自分のユーザ情報を出力する場合）






//list[][][fontsize=xx-small]{
$ id
uid=1000(admin) gid=1000(admin) groups=1000(admin),4(adm),20(dialout),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev)
//}
出力がadminの場合と同じであることに注意してほしい。






==== 実行結果 （ユーザ名がrootのユーザ情報を出力する場合）






//list[][][fontsize=xx-small]{
$ id root
uid=0(root) gid=0(root) groups=0(root)
//}







==== 実行結果 （管理者権限(sudo)を利用し、自分のユーザ情報を出力する場合）






//list[][][fontsize=xx-small]{
$ sudo id
uid=0(root) gid=0(root) groups=0(root)
//}
出力の読み方：
@<code>{sudo id}
は
@<B>{id}コマンドを管理者権限で実行することになるので、
@<code>{id root}
を実行したときと同じ出力になる







=== 知っていると便利なオプション:  -u




ユーザIDのみを出力する。






==== 実行例 






//list[][][fontsize=xx-small]{
$ id -u ユーザ名
//}








==== 実行結果 （ユーザ名がadminのユーザIDを出力する場合）






//list[][][fontsize=xx-small]{
$ id -u admin
1000
//}
ユーザ名adminのユーザIDが1000であることが分かる

#@# X-TODO: TIPS shell script or dockerfile (id -u), footnote ? note ?
このオプションをターミナル上で利用することは少ないが、
シェルスクリプトやDockerfileを書く際には必要な知識である




#@# 




=={ip} ip




ネットワークデバイスやルーティング、ポリシーなどの表示や変更ができる。
演習で使うのは
@<code>{ip a}
と
@<code>{ip r}
だけだろうから、これくらいは覚えておきたい





=== 書式




//list[][][fontsize=xx-small]{
$ ip [ options ] OBJECT COMMAND
$ ip [ options ] OBJECT help
//}

 * OBJECT部分では、
   @<B>{address}（IPアドレス）や
   @<B>{route}（経路情報）など、
   ネットワークの構成要素を指定する。
 * COMMAND部分には、そのOBJECTごとのコマンドが利用できる。
 * COMMANDを指定しない場合は、たいてい情報の表示が行われる。
   たとえば、
   @<code>{ip address}
   は
   @<code>{ip address show}
   と同じ意味に解釈され、現在のIPアドレス情報が表示される
 * もしCOMMANDが分からない場合は、
   OBJECTに関わらずhelpコマンドを指定すればヘルプメッセージが表示される





=== 実行例: IPアドレス情報を調べる （ip address）




address オブジェクト（省略してaも可）を用いて、
ネットワークインターフェース(データを送受信するための接続ポイント)に関連するIPアドレス情報を確認できる。




==== 実行例




//list[][][fontsize=xx-small]{
$ ip address
$ ip a  
//}
どちらも同じ結果が出力される。




==== 実行結果




//list[][][fontsize=xx-small]{
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
   〜省略〜
2: enp4s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 9001 qdisc mq state UP group default qlen 1000
    link/ether 0a:16:41:0c:9e:43 brd ff:ff:ff:ff:ff:ff
    inet 172.31.13.152/20 brd 172.31.15.255 scope global ens5
       valid_lft forever preferred_lft forever
    inet6 fe80::816:41ff:fe0c:9e43/64 scope link 
       valid_lft forever preferred_lft forever
3: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default 
   〜省略〜
//}

最重要の確認項目は次の２つ。

 *  inet:	ipv4アドレス/サブネットマスクが記載されている。
 ** 上の例では、172.31.13.152/20
 *  link/ether:	MACアドレス(各ネットワークインターフェースに割り当てられた一意の物理アドレス)が書かれている。
 ** 上の例では、0a:16:41:0c:9e:43

左端の数字に特別な意味はない。
@<code>{2: enp4s0:}の@<code>{enp4s0}部分はネットワークインターフェイスの名前である。
この名前はOSが割り当てるため、OSやハードウエア構成によって異なる値を取ることに注意。
あくまでもenp4s0は一例である。
一昔前までLinuxではeth0のような名前の付け方をしていたが、
最近、enp4s0のようなハードウエア情報に基づく名前の付け方に変わった
（最初からそうしておけばよかったのに！と思ったあなたは同志です:-）





=== 実行例: IPアドレス情報を調べる （ip route）




route オブジェクト（省略してrも可）を指定すると、
ルーティング(ネットワークの経路情報)を出力する。




==== 実行例




//list[][][fontsize=xx-small]{
$ ip route
$ ip r
//}
どちらも同じ結果が出力される。




==== 実行結果




//list[][][fontsize=xx-small]{
default via 210.128.53.201 dev enp3s8 onlink 
210.128.53.200/29 dev enp3s8 proto kernel scope link src 210.128.53.204 
210.128.53.208/29 dev enp1s0 proto kernel scope link src 210.128.53.209 
210.128.53.216/29 via 210.128.53.212 dev enp1s0 
210.128.53.224/29 via 210.128.53.212 dev enp1s0 
210.128.53.232/29 via 210.128.53.212 dev enp1s0 
210.128.53.248/29 dev enp2s0 proto kernel scope link src 210.128.53.249
//}

 * 1行目のdefault行はデフォルトルートの情報
 ** デフォルトルートとは、宛先がマッチしない場合の転送先ルータ。
    「マッチしない」とは2行目以降のネットワークに該当するものがないこと
 ** @<code>{default via 210.128.53.201}の@<code>{210.128.53.201}が転送先
 ** dev enp3s8 は210.128.53.201が存在するネットワークのインターフェイス（デバイス）名。
    一つのPCにネットワークインターフェイスは複数ありうるので、それを区別するための情報。
    このenp3s8のような名前は@<code>{ip address show}で表示されていたことを思い出せ
 * 2行目以降はネットワーク（IPアドレス/マスク）ごとのルーティング情報
 ** 例えば2行目の@<code>{210.128.53.200/29}は、
    @<code>{210.128.53.200/29}というアドレス範囲への通信のルーティング情報
 ** dev enp3s8のenp3s8は、
    @<code>{210.128.53.200/29}が存在するネットワークのインターフェイス（デバイス）名。
 ** src 210.128.53.204のIPアドレスはネットワークインターフェイス（デバイス）のIPアドレス。    つまりenp3s8に付いているIPアドレスと同じ


//note[column-ip][ipコマンドによる設定変更は原則おこなわない]{

ipコマンドによる設定変更も可能だが、
これは障害対応の場合にのみ許される作業と考えておいたほうがよい。

通常、ネットワークの設定は/etc以下の設定ファイルにもとづきOS起動時に行われる。
ネットワーク関連の変更は/etc以下を適切に変更後、再起動してOSに設定してもらうべきである

ちなみに、オブジェクト指向言語っぽい書き方をすれば、次のようになるだろう。
Unixはスペース区切りなので、これを上のように表記すると考えてほしい
//list[][][fontsize=xx-small]{
ip->OBJECT->COMMAND();

例：IPアドレスを表示せよ
ip->address->show();
//}

//}



#@# 




=={ls} ls




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




=== 知っていると便利なオプション: -l




ファイル・ディレクトリの権限が確認できる。
権限については@<code>{chmod}コマンドに詳しく記載されている
（詳細は@<secref>{chmod}節を参照）




==== 実行例




//list[][][fontsize=xx-small]{
$ ls -l
//}




==== 実行結果




//list[][][fontsize=xx-small]{
$ ls -l
drwxr-xr-x 2 user group 4096 Sep 08:14:44 htdocs
-rw-r--r-- 1 user group 10239 Dec 08 15:36 python.py
-rw-r--r-- 1 user group 10239 Sep 08 15:38 test.txt
//}

 * @<B>{d,r,w,x,-}という文字列の意味は、それぞれ以下のとおり
 ** 左端の@<B>{d}はディレクトリを意味する。かどうか？@<B>{-}はファイルである
 ** @<B>{r}は読み取り権限、@<B>{w}は書き込み権限である。
    @<B>{x}はファイルとディレクトリで意味が異なる。
    ファイルの場合は実行権限つまり「プログラムとして実行できる」という意味。
    ディレクトリの場合、そのディレクトリの中へ移動できるという意味
 *  1行目の@<code>{htdocs}は（左端がdなので）ディレクトリ
 ** ユーザは@<B>{rwx}、
    グループ(グループ名:groupに属しているユーザー)の権限は@<B>{r-x}、
    その他の権限も@<B>{r-x}である
 ** @<B>{r}と@<B>{x}は共通なので、
    @<B>{全ユーザがディレクトリの中を見ることが出来て、かつディレクトリに移動も可能}
 ** @<B>{w}があるのはユーザだけなので、
    @<B>{ユーザ本人のみがディレクトリに書き込める（htdocs内に新たにファイルやディレクトリを作成できる）}
 *  2行目と3行目はファイル
 ** python.pyとtest.txtは左端が@<B>{-}となっているのでファイル
 ** ユーザの権限は@<B>{rw-}なので、ユーザ（user）は@<B>{読み書き可能}
 ** groupに属するユーザーは@<B>{r--}なので@<B>{読み取りのみ可能}
 ** それ以外のユーザーも同様に@<B>{r--}なので@<B>{読み取りのみ可能}




=== 知っていると便利なオプション: -a




隠しファイル・隠しディレクトリを含めた全てのファイルを確認できる。




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



#@# 




=={lsblk} lsblk




利用できるブロックデバイスをツリー状に一覧表示する。

//note[blk][ブロックデバイス]{
ブロックデバイスとは、
ある程度のまとまったデータ量(ブロック)を単位として読み書きすることができる記憶装置のこと。
たとえばHDDやSSDなどが当てはまる。
//}




=== 書式




//list[][][fontsize=xx-small]{
$ lsblk
$ lsblk [options] [device...]
//}

 * 引数がない場合、全ブロックデバイスの情報を表示する
 * 引数で特定のデバイスを指定することも出来る




=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ lsblk
//}




==== 実行結果




//list[][][fontsize=xx-small]{
NAME     MAJ:MIN RM  SIZE RO TYPE MOUNTPOINTS
xvda     202:0    0    8G  0 disk 
├─xvda1  202:1    0  7.9G  0 part /
├─xvda14 202:14   0    3M  0 part 
└─xvda15 202:15   0  124M  0 part /boot/efi
//}
実用上は、左端のデバイス名と右端のマウントポイントだけ見ていれば十分だろう。
詳細は@<table>{lsblk}を参照

#@# X-TODO lsblkの表の位置調整
//table[lsblk][lsblkの表示]{
1行目		説明
----------------------------------------
NAME		デバイスの名前
MAJ:MIN		MAJ（メジャー）はデバイスドライバの番号
　		MIN（マイナー）は同一ドライバを使用するデバイスを区別する番号
　		(ここに表示されているxvdaはすべて同一ドライバを使用している)
RM		取り外し可能かどうかを示している。可能であれば1である。
SIZE		デバイスの容量
RO		読み取り専用かどうかを示している。読み取り専用であれば1である。
TYPE		デバイスのタイプを示している。diskであれば物理ディスク、
　		partであればパーティション(ディスクを論理分割している)を示している。
MOUNTPOINTS	デバイスにファイルシステムがマウントされていればそのパスが表示される
　		(表示されているファイルシステムがデバイスに入力できる)。
//}



#@# 




=={lscpu} lscpu




CPUの情報を表示できる




=== 書式




//list[][][fontsize=xx-small]{
$ lscpu [options]
//}
たいていは引数なしで実行すれば十分





=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ lscpu
//}




==== 実行結果




//list[][][fontsize=xx-small]{
Architecture:             x86_64
  CPU op-mode(s):         32-bit, 64-bit
  Address sizes:          46 bits physical, 48 bits virtual
  Byte Order:             Little Endian
CPU(s):                   1
  On-line CPU(s) list:    0
Vendor ID:                GenuineIntel
  Model name:             Intel(R) Xeon(R) CPU E5-2686 v4 @ 2.30GHz
    CPU family:           6
    Model:                79
    Thread(s) per core:   1
   〜省略〜
Virtualization features:  
  Hypervisor vendor:      Xen
  Virtualization type:    full
   〜省略〜
//}
そもそも@<code>{lscpu}コマンドが実行できる時点で、正常にOSが起動できているはずなので、
障害対応の意味合いは薄い。
実運用上は「CPUのコア数の確認」や「CPUの型番を知りたい」という場面くらいか？
@<table>{lscpu}も参照のこと。


#@# X-TODO lscpu table の場所
//table[lscpu][lscpuの読み方(一部)]{
項目(一部)		説明
------------------------------------------------------------
Architecture		CPUのアーキテクチャを示している。
CPU op			CPUがサポートしてるモード(64bit,32bitアーキテクチャをサポートしている)
Address sizes		物理アドレスと仮想アドレスのサイズを示している
　			(物理アドレス46bit,仮想アドレス48bit)
Byte Order		バイト順序(リトルエンディアンという最下位バイトが最初に来る形式である)
CPU(s)			システムに搭載されてるCPUの数
On-line CPU(s) list	現在使用可能なCPUのリスト(0という名称のCPU1つが使用可能)
//}



#@# 




=={lsmem} lsmem




オンライン状態になっている利用可能なメモリの範囲をリスト表示できる。




=== 書式




//list[][][fontsize=xx-small]{
$ lsmem [options]
//}
たいていはオプション無しで実行して良い




=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ lsmem
//}




==== 実行結果




//list[][][fontsize=xx-small]{
RANGE                                 SIZE  STATE REMOVABLE BLOCK
0x0000000000000000-0x000000003fffffff   1G online       yes   0-7

Memory block size:       128M
Total online memory:       1G
Total offline memory:      0B
//}
実用上はサイズの確認くらいだろう。
@<table>{lsmem}も参照のこと。

#@# X-TODO lsmem table の場所
//table[lsmem][lsmemの読み方]{
項目			説明
------------------------------------------------------------
RANGE			メモリのアドレス範囲(これは1GBを示している。)
Memory block size	1ブロック当たりのサイズ(1GB/8=128MB)
Total online memory	使用可能なメモリサイズ(1GB)
Total offline memory	使用不可能なメモリサイズ(このメモリはすべて利用できる)
//}



#@# 




=={mkdir} mkdir




ディレクトリを作成する




=== 書式




//list[][][fontsize=xx-small]{
$  mkdir [option]... DIRECTORY...
//}

 * 引数のDIRECTORYは必須。作成するディレクトリを少なくとも1つ指定する必要がある
 * 引数は可変長。作成したいディレクトリは、引数として複数つなげて書けば良い。
   スペース区切り





=== 実行例







==== 前提




現状の確認を@<code>{ls}コマンドで行う
//list[][][fontsize=xx-small]{
$ ls
www.py htdocs/ 
//}
現在のディレクトリには、
www.pyというファイルとhtdocsというディレクトリがある。




==== 実行例1




//list[][][fontsize=xx-small]{
$ mkdir test
//}
新たに@<code>{test}ディレクトリを作成する





==== 実行結果1




//list[][][fontsize=xx-small]{
$ mkdir test
$ ls
www.py htdocs/ test/
//}
testという名前のディレクトリが追加されていることが分かる






==== 実行例2




//list[][][fontsize=xx-small]{
$ mkdir test/dir
//}
さらに、
@<code>{test}ディレクトリの下に
@<code>{dir}ディレクトリを作成する





==== 実行結果2




//list[][][fontsize=xx-small]{
$ mkdir test/dir
$ ls test
dir/
//}
test内のファイル・ディレクトリを確認すると、
dirという名前のディレクトリが追加されていることが分かる



#@# 




=={nano} nano




Windowsのメモ帳のような@<B>{シンプルな操作方法のエディタ}。

ファイル名を指定することで、指定したファイルを編集することができる。
ファイル指定をせずに起動した場合や、
存在しないファイルを指定して起動した時は、
新規ファイルの作成・編集ができる。

//note[unix-editors][Unixのエディタ]{

Unixに昔からあるテキストエディタとしてはviやemacsが有名だ。
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



#@# 




=={ping} ping




ターゲットの生死を確認するコマンド。
ホスト間のネットワーク接続の安定性を検証する用途で利用する。

1秒に1つのデータグラムを送信し、受信した応答内容を出力する。出力は無限に続くので、キーボードから中断させる(Ctrl-Cを入力する)ことが必要。終了時には、往復情報とパケット損失統計を計算し、サマリを出力する。




=== 書式




//list[][][fontsize=xx-small]{
$ ping [options] ターゲット
//}
「ターゲット」はドメイン名かIPアドレス




=== 実行例







==== 実行例 




//list[][][fontsize=xx-small]{
$ ping IPアドレス
//}

//table[ping][pingコマンドの出力の読み方]{
キーワード	説明
------------------------------------------------------------
icmp_seq	pingを送信した回数
ttl		ルータの通過数(初期値-通過数)
time		送受信の往復の時間
//}






==== 実行結果 （成功パターン:10.252.0.11から応答があったとき）




//list[][][fontsize=xx-small]{
$ ping 10.252.0.11
PING 10.252.0.11 (10.252.0.11) 56(84) bytes of data.
64 bytes from 10.252.0.11: icmp_seq=1 ttl=64 time=0.039 ms
64 bytes from 10.252.0.11: icmp_seq=2 ttl=64 time=0.042 ms
    〜中略〜
64 bytes from 10.252.0.11: icmp_seq=7 ttl=64 time=0.018 ms
^C                                    ※Ctrl-Cを打ち込んだ行
--- 10.252.0.11 ping statistics ---
7 packets transmitted, 7 received, 0% packet loss, time 6151ms
rtt min/avg/max/mdev = 0.017/0.027/0.042/0.010 ms
//}
最終行
「0% packet loss」
（パケット損失が0%）
から回線品質が良好であることが伺える






==== 実行結果 （失敗パターン:10.252.0.127から応答がなかったとき）






//list[][][fontsize=xx-small]{
$ ping 10.252.0.127
PING 10.252.0.127 (10.252.0.127) 56(84) bytes of data.
From 10.252.0.11 icmp_seq=1 Destination Host Unreachable
    〜中略〜
From 10.252.0.11 icmp_seq=6 Destination Host Unreachable
^C                                    ※Ctrl-Cを打ち込んだ行
--- 10.252.0.127 ping statistics ---
7 packets transmitted, 0 received, +6 errors, 100% packet loss, time 6152ms
pipe 4
//}
最終行に「100% packet loss」とあることから、
パケット損失が100%、
つまりターゲット(10.252.0.127)からの応答がないことが分かる。
ただし、これだけでは、
ターゲットが稼働していないのか、
ネットワーク品質が悪いのか？は不明。
さらに調査する必要がある。


//note[ping][pingの由来]{

pingという単語は潜水艦のソナーに由来する。
（アクティブ）ソナーとは
「潜水艦から音波を出し、障害物から反射してくる音波を分析する」ことで水中の様子をさぐる仕組みのこと。
水中でのレーダーと考えれば良い。
@<code>{ping}コマンドは、それのサイバースペース版

//}



#@# X-TODO psコマンドの「端末」「ターミナル」を統一すること




=={ps} ps




プロセスの情報を表示するコマンド。





=== 書式




//list[][][fontsize=xx-small]{
$ ps [options]
//}

 * 引数なしで実行しても、あまり有益な情報は得られない
 * 典型的な使い方は@<code>{ps auxww}である。この形で覚えることを推奨
 * 書式は歴史的に二系統ある
 ** Linux搭載の@<code>{ps}コマンドは両系統の上位互換にみえる動作をする
 ** 以下では伝統のUnix由来のオプションだけを紹介する
 * psコマンドは、オプションに@<B>{-}をつけてもつけなくても、
   オプションを受け付ける数少ないコマンドである
  （これも古代との互換性を保つため）
   




=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ ps   
//}




==== 実行結果




//list[][][fontsize=xx-small]{
    PID TTY          TIME CMD
1177754 pts/1    00:00:00 bash
1177761 pts/1    00:00:00 ps
//}
自分が実行しているプロセス群が表示されている。
3行目のpsは、いま実行中のpsコマンド自身。
各項目の詳細は@<table>{ps-no-option}を参照。

ちなみに「TTY列が同じ値（pts/1）のみ」であることを覚えておきつつ、
次のaオプション以降を読んでほしい

//table[ps-no-option][psコマンドの基本出力]{
１行目の各項目	説明
------------------------------------------------------
PID		プログラムごとに割り当てられている番号
TTY		プロセスが関連つけられている端末
STAT		プロセスの状態を表している（aオプション指定時）
TIME		プロセスが使用したCPU時間
CMD		実行されているコマンド
//}





=== 知っていると便利なオプション: a 




他の端末（ターミナル）を含めた、端末操作のプロセスを表示する




==== 実行例




//list[][][fontsize=xx-small]{
$ ps a
//}




==== 実行結果




//list[][][fontsize=xx-small]{
    PID TTY      STAT   TIME COMMAND
    656 tty7     Ssl+ 777:24 /usr/lib/xorg/Xorg :0 -seat seat0 -
    657 tty1     Ss+    0:00 /sbin/agetty -o -p -- \u --noclear
1174896 pts/0    Ss+    0:00 -bash
1177754 pts/1    Ss     0:00 -bash
1177757 pts/1    R+     0:00 ps a
//}

TTY列を見ると値が複数あることが分かる。
TTY列は各ユーザに割り当てられた端末である（正確には「（疑似）端末」）。
psの出力例で分かるとおり、pts/1の行が自分がいる@<B>{"端末"}を意味している。
その他のtty1、tty7、pts/0は別の端末である。
この例では、pts/0の行が@<code>{-bash}なので、
自分以外のユーザも同じサーバ上にログインして（＝シェルを起動していて）作業中であることが分かる。

STAT列はプロセスの状態（state）で、
@<table>{ps-stat}を組み合わせた値が表示されている。

//table[ps-stat][psコマンドのSTAT列の読み方]{
STAT列の項目	説明
------------------------------------------------------
R		実行中(CPUを今使っている)
S		待機中(-bashはユーザーからの入力を待っている)
s 		セッションリーダー(sがついてるものがついてないプロセスを呼び出してる)
l		マルチスレッドプロセスであること（複雑なプロセスにつくことが多い）
+		フォアグランドのプロセス状態(画面上で動いてるプログラム)
//}






=== 知っていると便利なオプション: u




プロセスの所有者やCPU・メモリの使用率をわかりやすく表示する。




==== 実行例




//list[][][fontsize=xx-small]{
$ ps u 
//}




==== 実行結果




//list[][][fontsize=xx-small]{
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
h205     1174896  0.0  0.0   9456  7328 pts/0    Ss+  13:53   0:00 -bash
h205     1177754  0.0  0.0   6408  5020 pts/1    Ss   13:58   0:00 -bash
h205     1178343  100  0.0   9388  4864 pts/1    R+   14:00   0:00 ps u 
//}
列の詳細は@<table>{ps-u}を参照。

特に注目する列は、
(1)CPU使用率を意味する%CPU列と、
(2)メモリ使用量を意味するRSS列だろう。
システムが重い時は、
このどちらかの列の値が異常に大きいプロセスが犯人の可能性が高い。

//table[ps-u][ps uで追加表示される列]{
列	 説明
------------------------------------------------------
USER	ユーザーネーム
%CPU	プロセスのCPUの使用率
%MEM	プロセスの物理メモリの使用率
VSZ	仮想メモリを確保しているサイズ
RSS	物理メモリを確保しているサイズ
//}





=== 知っていると便利なオプション: x




端末に紐づかないプロセス(サーバー動作中に動作するシステムのプロセスなど)も表示する。




==== 実行例




//list[][][fontsize=xx-small]{
$ ps x
//}




==== 実行結果




//list[][][fontsize=xx-small]{
    PID TTY      STAT   TIME COMMAND
    800 ?        Ss     0:01 /lib/systemd/systemd --user
    801 ?        S      0:00 (sd-pam)
    816 ?        S<sl   0:00 /usr/bin/pulseaudio --daemonize=no
    〜省略〜
1174895 ?        S      0:00 sshd: h205@pts/0
1174896 pts/0    Ss+    0:00 -bash
1177753 ?        S      0:00 sshd: h205@pts/1
1177754 pts/1    Ss     0:00 -bash
1178609 pts/1    R+     0:00 ps x
//}
TTYが?なものは、バックグラウンドで動作するプロセスのためTTYが割り当たってない




=== 知っていると便利なオプション: aux,auxww




これまで説明したオプションのa,u,xを組み合わせたもの
しかし、auxだと長いコマンドの場合省略されるため、コマンドライン引数をすべて確認したい場合、auxwwとつける




==== 実行例 （ps auxとauxwwの比較）




//list[][][fontsize=xx-small]{
$ ps aux
$ ps auxww
//}




==== 実行結果 （ps auxとauxwwの比較）




//list[][][fontsize=xx-small]{
$ ps aux
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.0 169460 13824 ?        Ss   14:56   0:03 /sbin/init
root           2  0.0  0.0      0     0 ?        S    14:56   0:00 [kthreadd]
    〜省略〜
root       27816  0.0  0.0 1238196 15296 ?       Sl   15:16   0:00 /usr/bin/hogehogehogehoge-v2 -namespace dummy -id c5ca6239
    〜省略〜
//}
省略されているが基本的に全てのプロセスが表示されている。

//list[][][fontsize=xx-small]{
$ ps auxww
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.0 169460 13824 ?        Ss   14:56   0:03 /sbin/init
root           2  0.0  0.0      0     0 ?        S    14:56   0:00 [kthreadd]
    〜省略〜
root       27816  0.0  0.0 1238196 15296 ?       Sl   15:16   0:00 /usr/bin/hogehogehogehoge-v2 -namespace dummy -id c5cadb62398fbbad3823e8e4eaf6003e0d68f1853fed4b4cf9ff1bfe6f39d0270cac8 -address /hoge/hoge/hoge/hoge
    〜省略〜
//}
PID 27816のCOMMAND列を見比べると、
ps auxの場合、コマンドの末尾まで出力されていないことがわかる。



#@# X-TODO pstree にある「親子関係」の説明が必要だろう、脚注？




=={pstree} pstree




プロセスの親子関係をツリー状に表示する。




=== 書式




//list[][][fontsize=xx-small]{
$ pstree [options]
//}




=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ pstree
//}




==== 実行結果




//list[][][fontsize=xx-small]{
systemd─┬─2*[agetty]
        ├─dbus-daemon
        ├─polkitd───2*[{polkitd}]
        ├─sshd───sshd───sshd───bash───script───bash───pstree　※
        ├─sudo───bash─┬─bash
        │             └─inotifywait
        ├─systemd───(sd-pam)
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-network
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        └─unattended-upgr
//}

 * @<code>{※}は実際には出力されない
 * この行をみると、 bash(pstreeと入力したターミナル)がpstreeを呼び出していることがわかる



#@# X-TODO pwd -L -P の話をするべきか？




=={pwd} pwd




自分が現在作業しているディレクトリを@<B>{絶対パスで表示}する。
pwdは「Print Working Directory」もしくは「Present Working Directory」の略。




=== 書式




//list[][][fontsize=xx-small]{
$ pwd [options]
//}




=== 実行例







==== 実行例 






//list[][][fontsize=xx-small]{
$ pwd
//}








==== 実行結果





//list[][][fontsize=xx-small]{
$ pwd
/home/admin
//}
現在自分（ユーザadmin）がいるディレクトリが表示されている様子



#@# 




=={python} python3







=== 書式




//list[][][fontsize=xx-small]{
$ python3
$ python3 ファイル名
//}

 * python3と単体で入力した場合は対話モードとなり、コードを入力すると実行される。
   quit()と入力すれば、対話モードは終了する。
 * 引数があれば、その引数のファイルを1行ずつ実行していく（スクリプト言語、下記を参照）





==== コンパイラ言語とスクリプト言語




プログラミング言語は大きく分けて二種類ある。
コンパイラ言語とスクリプト言語だ。

コンパイラ言語とはC言語が代表例である。
(a)まずソースコードを書き(b)それをコンパイラで実行形式(@<code>{a.out})に変換する。
OSに実行してもらうのは@<code>{a.out}ファイルである。

一方、pythonはスクリプト言語である。
www.pyのようなプログラムは実行ファイルではなくソースコードにあたる。
pythonの場合、実行ファイルは作成しない。
pythonプログラムがソースコード(www.py)を一行ずつ読みながら逐次実行する。
こういった（python）プログラムをインタープリタと呼ぶ。

「pythonのプログラムを動かす」という表現は上のような意味である。
よって、プログラム(www.py)自体に実行権限がなくてもwww.pyを実行できる
（注意：www.pyに実行権限は不要だが、pythonがwww.pyを読める権限は必要である）。





=== 実行例




以下のように@<code>{print}一行だけのhello.pyファイルがあるとする
//list[][][fontsize=xx-small]{
$ cat hello.py

print("Hello World")
//}
ちなみに、ファイルの中身を確認するときはcatコマンドを使うと表示できる





==== 実行例1




//list[][][fontsize=xx-small]{
$ python3 hello.py   
//}





==== 実行結果1




//list[][][fontsize=xx-small]{
$ python3 hello.py 
Hello World
//}
hello.pyが実行され、結果が出力されている。





==== 実行例2




//list[][][fontsize=xx-small]{
$ python3
〜省略〜
>>>
//}
対話モードに入ったため、>>>と表示される。
 



==== 実行結果2




//list[][][fontsize=xx-small]{
>>> print("Hello World")
Hello World

>>>quit()
$

//}

 * @<code>{print("Hello World")}を入力したあとENTERを押すと、入力した行が実行され、結果が出力された様子
 * @<code>{quit()}を入力しENTERを押すと、対話モードが終了する。
   シェルに戻ってきたので@<code>{$ }が表示されている。
   これでUnixコマンドが打てる状態に戻った



#@# 




=={scp} scp




SSHプロトコルを利用して、自分のコンピュータのファイルを他のコンピュータに転送するコマンド。
scpは「Secure Copy」の略。

実際に使う際は、コピー元のパスとコピー先のパスを指定する。




=== 書式




//list[][][fontsize=xx-small]{
$ scp [options] SOURCE... TARGET
//}

 * 基本的に@<code>{cp}コマンドのSSH版。
   @<code>{scp コピー元ファイル コピー先ファイル}のように使う。
   コピー先ファイルがネットワークの向こう側でも良いところが@<code>{cp}と異なる
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
 ** testuserがコピー先のユーザ名(exampleサーバにログインする際のユーザ名)
 ** exampleがドメイン名（サーバ名）
 ** ホスト名(この例ではexample)の部分はIPアドレスでもよい





=== 知っていると便利なオプション: -r




コピーしたい対象がディレクトリの場合に使用する。
指定したディレクトリ以下すべてをコピーする
（再帰的（recursive）のr）





==== 実行例 




sampledirディレクトリを、サーバexampleの/home/testディレクトリへコピーする

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



#@# X-TODO: ss のネットワーク周りの説明は要検討、むずかしいだろ、これ




=={ss} ss




コマンド名はsocket statisticsの頭文字。
ネットワーク通信で利用するソケットについての情報を出力する。

#@# X-TODO: ss の用語は「用語集」に移すべきか？
 *  ソケット: 外部とやり取りをするときの窓口
 ** 通信するためにIPアドレス、ポート番号、通信プロトコルなどを決めてある
 *  IPアドレス:	ネットワークにつながっている機器(サーバー、PC、スマホなど)に割り振られた番号
 *  ポート番号:	通信に使用するプログラムを識別するための番号、0～65535まで設定可能 
 ** IPアドレスがマンションの住所にあたり、そのマンションの部屋番号がポート番号にあたる。




=== 書式




//list[][][fontsize=xx-small]{
$ ss [options]
//}

 * オプションなしでは情報過多
 * 定番の@<code>{ss -l4n}の形で覚えることを推奨





=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ ss
//}




==== 実行結果




//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port                
user ESTAB      0      0        * 1031009                         * 0                    
user ESTAB      0      0       /run/systemd/journal/stdout 874    * 10967                
     〜 省略 〜
tcp  ESTAB      0      0       172.31.1.171:41136                 172.31.101.90:nfs 
//}
実用上は、開いているポート番号（@<code>{:数字}部分）の確認に使うことが多い。
詳細は@<table>{ss}





=== 知っていると便利なオプション: -l




数字ではなく英語小文字のエル、lima の l
（listenのlに由来する）。

接続待ち状態(StateがListen)のソケットのみを表示する。
いわゆるサーバだけを表示したいときに使用する




==== 実行例




//list[][][fontsize=xx-small]{
$ ss -l
//}





==== 実行結果




//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port
u_str LISTEN     0      128    /root/.pm2/pub.sock 24878          * 0                    
u_str LISTEN     0      128    /root/.pm2/rpc.sock 24879          * 0  
      〜 省略 〜
tcp   LISTEN     0      128     *:56958                           *:*
//}
StateがListenのもののみが表示されている。




=== 知っていると便利なオプション: -4




IPv4のソケットの情報だけを表示する。

#@# X-TODO: ss の用語IPv4は「用語集」に移すべきか？
備考：
IPv4 ... IPv4全体は2進数の32桁で表現される。
人間が見るために2進数8桁ずつ4つに分割して、
それぞれを10進数に変換した後にピリオド(.)で区切った表記になっている
0.0.0.0～255.255.255.255でIPアドレスを指定する





==== 実行例




//list[][][fontsize=xx-small]{
$ ss -4  
//}




==== 実行結果




//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port                 Peer Address:Port                
udp   ESTAB      0      0      127.0.0.1:57674                127.0.0.1:57674                
tcp   ESTAB      0      0      127.0.0.1:6081                 127.0.0.1:35634                
tcp   ESTAB      0      0      127.0.0.1:35000                127.0.0.1:48549
      〜 省略 〜
//}
省略されているが、Netidがudpまたはtcp、Addressがipv4の表記(x.x.x.x)のみを示している。




=== 知っていると便利なオプション: -n




名前解決を行わない(プロトコル名やドメイン名が表示されない)





=== 知っていると便利なオプション: -l4n




これまで説明したオプションをl,4,nの順番で行う。




==== 実行例




//list[][][fontsize=xx-small]{
$ ss -l4n
//}




==== 実行結果




//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q     Local Address:Port       Peer Address:Port
tcp   LISTEN     0      128        *:59707                  *:*                  
tcp   LISTEN     0      128        *:40603                  *:*     
      〜 省略 〜
//}

//table[ss][ssの各列の意味]{
1行目の各項目	説明
----------------------------------------------------------------------
Netid		ネットワーク識別子(ソケットが何を対象としているソケットかを表すもの)
　		user ... userに対する通信のためのソケット
　		tcp  ... tcp通信を行うためのソケット
State		ソケットの状態(ESTABなら接続中、LISTENから接続待ちなど)
Recv-Q		アプリケーションが読み取ってないデータ量
　		(0ならデータを適切に処理している)
Send-Q		アプリケーションが送信していないデータ量
　		(0ならすべてのデータを送信している)
Local Address:Port	ソケット通信におけるローカル側
　    			ソケットファイルパスまたはIPアドレスとポート番号を示す
Peer Address:Port	ソケット通信における接続先(ピア)側
　   			ソケットファイルパスまたはIPアドレスとポート番号を示す
//}



#@# 




=={ssh} ssh




他のコンピューター・サーバにSSH(Secure Shell)プロトコルでログインする。
非対称鍵暗号による認証と通信路の暗号化を行う商用インターネット時代のデファクトスタンダードツール。サーバ運用管理の必須ツール。

認証時には、
非対称鍵方式と対象鍵（パスワード）方式が利用できるが、
インターネットからアクセスできるサーバは公開鍵認証のみで運用するべきである。




=== 書式




//list[][][fontsize=xx-small]{
$ ssh  [options] DESTINATION
$ ssh  [options] DESTINATION [command [argument...]
//}

 *  @<code>{ssh サーバ}形式でサーバへ遠隔ログインできる
 ** 引数が「サーバ」形式の場合、
    サーバにログインするユーザ名は今コマンドを実行しているユーザ名と同じと想定される
 ** 「ユーザ@サーバ」つまりメールアドレス形式で、サーバのユーザ名を指定できる
 *  @<code>{ssh サーバ コマンド}形式でコマンドを遠隔実行できるが、演習では使わないため説明は省略




=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ ssh user@16.32.64.128
//}



==== 実行結果




//list[][][fontsize=xx-small]{
$ ssh user@16.32.64.128
    〜省略〜
user@16.32.64.128$ 
//}
最終行はシェルのプロンプトである。
この例では@<code>{$ }の左側に「ユーザー名@ipアドレス」が表示されている。





=== 知っていると便利なオプション: -i ファイル名




#@# X-TODO 秘密鍵という紛らわしい表現について

SSH接続に使用する秘密鍵ファイルを指定する。





===== 実行例




//list[][][fontsize=xx-small]{
$ ssh -i .ssh/id_rsa.pem user@16.32.64.128
//}
@<code>{.ssh/id_rsa.pem}の部分が秘密鍵ファイルである





===== 実行結果




//list[][][fontsize=xx-small]{
$ ssh -i .ssh/id_rsa.pem user@16.32.64.128
    〜省略〜
user@16.32.64.128$ 
//}
説明は同上なので省略



#@# 




=={sudo} sudo




ルート権限(ほぼすべての操作が可能な管理者の権限)を持たない一般ユーザーが、
sudoコマンドを使うと、コマンド単位でルート権限を利用できる




=== 書式




//list[][][fontsize=xx-small]{
$ sudo [options] command [arg ...]
//}




=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ sudo id
//}




==== 実行結果




//list[][][fontsize=xx-small]{
$ sudo id
uid=0(root) gid=0(root) groups=0(root)
//}




=== ルート権限の特長







==== IDが変わる




コマンドは実行時のユーザIDと紐付いている。
ルート権限を持つユーザー(root)のidは0なので、
sudoを利用して実行したコマンドはid=0で動作する。




===== 実行例




@<code>{id}コマンドに、コマンド実行時のユーザIDを表示させてみよう。

@<code>{id}コマンドにより自身のIDについて確認できる。
（@<secref>{id}節を参照）
//list[][][fontsize=xx-small]{
$ id -u
//}
sudoをつけて実行する場合は次のようにする。
//list[][][fontsize=xx-small]{
$ sudo id -u
//}





===== 実行結果



//list[][][fontsize=xx-small]{
$ id -u
1000
$ sudo id -u
0
//}
sudoを使う時と使わないときでIDが変化していることがわかる





=== 特権ポートでサーバを起動する




ネットワークでは、通信を識別するために、
ネットワークの入出力口（ソケット）に識別番号（ポート番号）をつけている。
当然サーバが待ち受けするポートもある。
広く利用される（公益性が高い）サーバが使うポート番号には1024未満が割り当てられており、
特権ポートと呼ばれている。
このポートを利用する際、つまりサーバを起動する際には、ルート権限が必要である

sudoコマンドを利用することで、この制限を回避し、サーバを起動することが出来るようになる





===== 実行例




ポート番号80番でPythonのWWWサーバを起動しようとする例を見てみよう。

一般ユーザの場合。
//list[][][fontsize=xx-small]{
$ python3 -m http.server 80
//}

sudoコマンドをつけて、
一般ユーザが、
ポート番号80番でPythonのWWWサーバを起動しようとするなら次のようにする。
//list[][][fontsize=xx-small]{
$ sudo python3 -m http.server 80
//}





===== 実行結果




HTTPデフォルトのポート番号80番でPythonのWWWサーバを起動しようとすると、
次のように@<code>{PermissionError: [Errno 13] Permission denied}というエラーメッセージが表示され、
異常終了する。
//list[][][fontsize=xx-small]{
$ python3 -m http.server 80
Traceback (most recent call last):
    〜省略〜
PermissionError: [Errno 13] Permission denied
//}

sudoコマンドをつければ起動できるようになる
//list[][][fontsize=xx-small]{
$ sudo python3 -m http.server 80
Serving HTTP on 0.0.0.0 port 80 (http://0.0.0.0:80/) ...
    〜省略〜
//}
sudoなしだと権限が80番ポートを開く権限がないため、WWWサーバを開けない。
sudoを使うことで80番ポートを開く権限が得られるため、
WWWサーバを開くことができる





=== 注意点




root権限を持つユーザーはセキュリティ上狙われやすいユーザーであるため、
直接ルートユーザーにログインするのではなく、
権限を持たないユーザーでログインし、
必要な場合にsudoコマンドを利用してルート権限を利用すること



#@# X-TODO telnet ... 実行例として、ポート番号 13 は適切なのか？




=={telnet} telnet




他のコンピューター・サーバーにログインできる。
通信をする際は、暗号化をせずに通信する(暗号化をして通信をする際は、sshコマンドを利用する)。

今日では、
デバッグ用途か、LANでネットワーク機器の設定をする際に利用するくらいであるが、
いまだに何かと便利なコマンド




=== 書式




//list[][][fontsize=xx-small]{
$ telnet [options ...] [HOST [PORT]]
//}

 * 引数なしで@<code>{telnet}コマンドを起動すると、対話モードに入ってしまうので注意。
   quitで抜けることが出来る
 * @<code>{telnet HOST}形式で起動すると、HOSTへtelnetプロトコルで接続する
 * @<code>{telnet HOST PORT}形式で起動すれば、
   HOSTのポート番号PORTとのあいだにTCP論理回線が構築される。
   よく、アプリケーションプロトコルのデバッグで用いるのがコレ





=== 実行例







==== 実行例




アメリカ国立標準技術研究所(NIST)の時刻サーバーへ接続する
//list[][][fontsize=xx-small]{
$ telnet time.nist.gov 13
//}

#@#  * IPアドレス: ネットワークにつながっている機器(サーバー、PC、スマホなど)に割り振られた番号
#@#  * ポート番号: 通信に使用するプログラムを識別するための番号、0～65535まで設定可能
#@#  * IPアドレスがマンションの住所にあたり、そのマンションの部屋番号がポート番号にあたる。




==== 実行結果




//list[][][fontsize=xx-small]{
$ telnet time.nist.gov 13
60642 24-11-04 15:18:00 00 0 0 762.9 UTC(NIST) *
//}
NISTから時刻の返信が来ている。
読み方は次のとおり

 * 60642が1970/1/1から現在(記録日2024/11/4)までの日数
 * 15:18:00はアメリカの現在時刻
 * 00はエラーが発生してないことを確認する。(00以外ならエラー)
 * @<code>{0 0 762.9}は時間の補正に関する値である。
 * UTC(NIST)は、
   NISTの協定世界時であるUTC(いわゆるグリニッジ標準時)で時刻表示していることを示している



#@# 




=={tracepath} tracepath




宛先にパケットを送信し、宛先までに通過する各ルータのIPアドレスを記録する。記録されたIPアドレスによって、宛先のホストまでのネットワーク経路を可視化するために利用する。




=== 書式




//list[][][fontsize=xx-small]{
$ tracepath [options] DESTINATION
//}
DESTINATIONはホスト名かIPアドレス





=== 実行例







==== 実行例 




//list[][][fontsize=xx-small]{
$ tracepath IPアドレス
//}




==== 実行結果　（192.159.190.35 nintendo.com）




//list[][][fontsize=xx-small]{
$ tracepath 192.159.190.35
1?: [LOCALHOST]                      pmtu 1280
1:  LAPTOP-A860U3T2.mshome.net                            1.443ms
1:  LAPTOP-A860U3T2.mshome.net                            0.383ms
2:  unifi.localdomain                                     1.811ms
3:  10.252.0.1                                            1.910ms
4:  118.23.89.234                                         4.303ms
5:  118.23.89.77                                          5.230ms
6:  221.184.5.205                                         6.879ms
7:  122.1.245.193                                        18.817ms
8:  122.1.245.206                                        21.827ms
9:  ae-9.a03.tokyjp05.jp.bb.gin.ntt.net                  19.898ms
10:  ae-5.r32.tokyjp05.jp.bb.gin.ntt.net                 19.778ms asymm 11
11:  ae-4.r27.snjsca04.us.bb.gin.ntt.net                 128.045ms
12:  ae-0.a02.sttlwa01.us.bb.gin.ntt.net                 120.781ms asymm 13
13:  ae-0.comcast.sttlwa01.us.bb.gin.ntt.net             116.382ms
14:  be-1211-cs02.portland.or.ibone.comcast.net          147.274ms asymm 16
15:  be-36131-arsc1.burien.wa.seattle.comcast.net        136.669ms asymm 16
16:  ae-501-ar01.seattle.wa.seattle.comcast.net          121.145ms asymm 17
17:  be-2-sur02.bellevue.wa.seattle.comcast.net          152.747ms asymm 20
18:  be-1-sur03.bellevue.wa.seattle.comcast.net          149.624ms asymm 19
19:  50.231.28.130                                       128.459ms asymm 18
20:  no reply
   〜省略〜
30:  no reply
		Too many hops: pmtu 1280
		Resume: pmtu 1280
//} 

出力の読み方：
日本のサーバからアメリカのAmazon社のサーバを経由していることが分かる。
一部分だけ解説すると次のとおり

 * ホスト名: ae-5.r32.tokyjp05.jp.bb.gin.ntt.net
 ** 東京にあるルータ
 * ホスト名: be-1-sur03.bellevue.wa.seattle.comcast.net
 ** アメリカのAmazon社が持っているルータ
 * 通信時間: 19.778ms






=== 知っていると便利なオプション: -n




DNSの検索をせずに処理を実行する。





==== 実行例 




//list[][][fontsize=xx-small]{
$ tracepath -n IPアドレス
//}





==== 実行結果 （192.159.190.35 nintendo.com）




//list[][][fontsize=xx-small]{
$ tracepath -n 192.159.190.35
1?: [LOCALHOST]                      pmtu 1280
1:  172.29.208.1                                          1.404ms
1:  172.29.208.1                                          1.343ms
2:  192.168.1.1                                           1.767ms
3:  10.252.0.1                                            3.226ms
4:  118.23.89.234                                         9.273ms
5:  118.23.89.77                                         11.126ms
6:  221.184.5.205                                        12.700ms
7:  122.1.245.193                                        24.420ms
8:  122.1.245.206                                        24.939ms
9:  120.88.53.21                                         25.712ms
10:  129.250.5.109                                        19.804ms asymm 11
11:  129.250.5.78                                        125.279ms
12:  129.250.5.227                                       133.718ms asymm 13
13:  129.250.66.106                                      115.329ms
14:  96.110.44.93                                        128.149ms asymm 15
15:  68.86.93.2                                          129.075ms asymm 17
16:  96.216.153.6                                        144.728ms
17:  69.139.164.126                                      130.598ms asymm 19
18:  68.86.96.142                                        150.784ms asymm 19
19:  50.231.28.130                                       131.109ms asymm 18
20:  no reply
   〜省略〜
   30:  no reply
		Too many hops: pmtu 1280
		Resume: pmtu 1280
//}


//note[-n][-nオプションの意義]{
#@# X-TODO -n の意義

ネットワーク系のコマンドでは、
@<code>{-n}オプションをつけて実行することを心がけるべきである
（その手のコマンドには普通@<code>{-n}オプションがあるはず）。

なぜかというと、
この手のコマンドを実行するのは障害対応の場面であり、
DNS障害も確認するべき項目の一つだからだ。
DNS障害に引きづられないよう、
DNSを使わずにネットワークの動作確認を行うべきである

//}



#@# 




=={tree} tree




ファイルとディレクトリを樹木状に表示する。ファイルやディレクトリの整理状況を把握するために利用する。





=== 書式




//list[][][fontsize=xx-small]{
$ tree [options] [ディレクトリ]
//}





=== 実行例







==== 実行例 （adminディレクトリを出力する場合）




//list[][][fontsize=xx-small]{
$ tree admin
//}





==== 実行結果 （adminディレクトリを出力する場合）




//list[][][fontsize=xx-small]{
$ tree admin
admin
├── __pycache__
│   └── bws.cpython-311.pyc
├── bws.py
├── cc-04.py
├── htdocs
│   ├── cart.html
│   ├── index.html
│   ├── lsform.html
│   ├── rek_janken.html
│   └── upload.html
├── rekognition.py
└── www.py

3 directories, 10 files
//}






=== 知っていると便利なオプション







=== -d オプション




ディレクトリのみを樹木状に出力する。





==== 実行例 




//list[][][fontsize=xx-small]{
$ tree -d ディレクトリ
//}





==== 実行結果 （adminディレクトリ内のディレクトリのみを出力する場合）




//list[][][fontsize=xx-small]{
$ tree -d admin
admin
├── __pycache__
└── htdocs

3 directories
//}





=== -a オプション




隠しファイルを含むすべてのディレクトリとファイルを出力する。






==== 実行例 




//list[][][fontsize=xx-small]{
$ tree -a ディレクトリ
//}





==== 実行結果 （adminファイル内のすべてのディレクトリとファイルを出力する場合）




//list[][][fontsize=xx-small]{
$ tree -a admin
admin
├── .bash_history
├── .bash_logout
├── .bashrc
├── .local
│   └── share
│       └── nano
├── .profile
├── .ssh
│   └── authorized_keys
├── .sudo_as_admin_successful
├── .viminfo
├── __pycache__
│   └── bws.cpython-311.pyc
├── bws.py
├── cc-04.py
├── htdocs
│   ├── cart.html
│   ├── index.html
│   ├── lsform.html
│   ├── rek_janken.html
│   └── upload.html
├── rekognition.py
└── www.py

7 directories, 17 files
//}
.sshなど.(ドット)から始まる隠しファイルや隠しディレクトリも表示されていることが分かる。



#@# 




=={unzip} unzip




圧縮されたzipファイルから、ファイルを取り出す（解凍する）コマンド。
@<code>{zip}コマンドの反対（@<secref>{zip}節も参照）




=== 書式




//list[][][fontsize=xx-small]{
$ unzip [options] 解凍したいファイル名
//}





=== 実行例




（test1.txtとtest2.txtが格納されている）example.zipを解凍することを考える。




==== 実行例 




//list[][][fontsize=xx-small]{
$ unzip example.zip
//}




==== 実行結果




//list[][][fontsize=xx-small]{
$ unzip example.zip
 Archive:  example.zip
  extracting: text1.txt               
  extracting: text2.txt  
//}



#@# 




=={vi} vi




Linuxを含むUnixベースのOSで利用できるテキストエディタ。
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





=== 実行例




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

:で始めるコマンドはexコマンドを呼び出す呪文だ。
exとは何か？というとviの一つ前に開発されていたエディタで、
実際のところviとexは同じプログラムへの異なるインターフェイスである。

こういうインターネット古代史はBSDのマニュアルにはきちんと書いてあるが:-)、
vi(vim)のマニュアルには書いていないようである
（少なくともDebian同梱のviには無い）。
まぁ古代史を知らなくとも困らないが、
我々の道具が何故このような形に落ち着いているのか興味ありませんか？
（「わたし、気になります！」というIT古典部気質の人は、
エンジニア適性があると思う）

//}



#@# 




=={zip} zip




ファイルをzip形式で圧縮するコマンド。
@<code>{unzip}コマンドの反対（@<secref>{unzip}も参照）




=== 書式




//list[][][fontsize=xx-small]{
$ zip [options] 圧縮後のファイルの名前 圧縮したいファイルの名前...
//}
「圧縮したいファイルの名前...」は可変長である。





=== 実行例




text1.txtとtext2.txtをexample.zipに圧縮する。




==== 実行例 




//list[][][fontsize=xx-small]{
$ zip example.zip test1.txt test2.txt
//}




==== 実行結果




//list[][][fontsize=xx-small]{
$ zip example.zip text1.txt text2.txt
   adding: text1.txt (stored 0%)
   adding: text2.txt (stored 0%)
//}



