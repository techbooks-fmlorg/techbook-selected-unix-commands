= 厳選Unixコマンド

#@# 




=={aws} @<term>{aws}




awsコマンドを使うと、
コマンドラインからAWSサービスを利用できる。

AWS固有のコマンドなので、当然Unix標準ではない。
AWS提供のEC2のOSイメージではawsコマンドが標準搭載のようだが、
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
aws単体だとエラーとヘルプメッセージが表示される。

//note[show-help-by-error][コマンドの使い方が分からない時]{
@<idx>{コマンド((こまんど))<<>>の使い方が分からない時((のつかいかたがわからないとき))}に、
「わざとエラーを起こしてヘルプメッセージを表示させる」技は、
ほぼ、どんなときでも使えるので覚えておきたい
//}




=== @<idx>{aws<<>> s3} subcommand




awsで使えるコマンドは様々であるが、今回はサービスの一つであるS3のみを紹介する。

@<B>{S3（Simple Storage Service）}はAWSを代表するサービスの一つである。
きわめて耐久性が高く、
@<B>{99.999999999％（イレブン・ナイン）を超えるデータ耐久性}を唱う。
S3の代表的な使い方は
「@<idx>{ストレージ((すとれーじ))}サービス（データの長期保存）」と
「@<idx>{静的Webサイト((せいてきうえぶさいと))}(事前にHTMLを作成し、その通りに動くサイト)の公開」である。

S3を利用する際には、まず@<B>{バケット}と呼ばれるファイルの入れ物を作成する。
これはUnixのディレクトリやWindowsのフォルダに相当するものと考えて良い。
ユーザは、このバケットにファイルをアップロードしていくことになる。

awsコマンドでS3サービスを呼び出す場合、command部分にはs3を指定する。
subcommandで様々なファイル操作が行える。例：

 * バケットの内部を確認する際は ls 
 * データの送受信は cp もしくは sync
 ** cpはファイル、syncはバケットとフォルダを同期
    @<br>{}
    注：操作方法はcpもsyncも同じなのでsyncの実行例は省略する





==== 前提




以下の実行例では、次の前提がある

 *  @<code>{$ }行は、AWSのEC2にログインしている状態での操作である
 ** ユーザadminのホームディレクトリ(/home/admin)で作業している
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
S3バケットにあるhello.pyをEC2内にhello.pyという名前でコピーする




==== 実行結果




//list[][][fontsize=xx-small]{
$ aws s3 cp s3://testBucket/hello.py hello.py
$ ls
hello.py   www.py   htdocs
//}
EC2上にhello.pyファイルが増えたことが分かる






=={cat} @<term>{cat}




@<idx>{ファイル((ふぁいる))<<>>を表示する((をひょうじする))}@<B>{だけ}のコマンド。
教科書やマニュアルでは「ファイルを表示する」際に@<B>{cat}コマンドを紹介しがちだが、
実際の現場では、何百行もあるファイルに対して@<B>{cat}を使ってしまい、
目的の行を見ることが出来ず、
後悔したあげくに@<B>{@<idx>{less}}を使うことがシバシバである。
そういうわけなので、
「ターミナルでは@<B>{cat}より@<B>{less}（@<secref>{less}節を参照）を使う」
と覚えておくほうが汎用性がある。





=== 書式




//list[][][fontsize=xx-small]{
$ cat ファイル名 [ファイル名...]
//}
 * 引数に、複数のファイル名を記述しても良い。
   複数の場合はコンテンツが連結(concatenate)した状態で表示される。
   ちなみに、これ(concatenate)がコマンド名の由来である




=== 実行例： www.py@<idx>{ファイル((ふぁいる))<<>>を表示する((をひょうじする))}




//list[][][fontsize=xx-small]{
$ cat www.py
//}
www.pyは数百行あるファイルなので、どんどん表示が流れていく。
実質、最後の数十行だけが表示される
（「行数」は各自のターミナルによる）。



#@#

//footnote[other][他者(others)とは、ユーザつまりファイルのオーナー（所有者）でもなく、ファイルのグループにも属していないユーザ]




=={chmod} @<term>{chmod}




ファイルやディレクトリの@<B>{@<idx>{パーミッション}（アクセス権限）}を変更することができる。  
これにより、ファイルやディレクトリに対する@<B>{読み取り、書き込み、実行}などの@<idx>{権限((けんげん))}を設定することができる。




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

たとえば、所有者に読み込み・書き込み・実行を許可し、グループのメンバに読み込み・実行を許可し、 他者@<fn>{other}に読み込み・実行を許可する絶対値指定のモードは、 755 (400+200+100+040+010+004+001) となる。

who シンボルの'u','g','o'はそれぞれユーザ、グループ、他者に相当する。
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
100	ファイルの場合、所有者による実行を許可。
　	ディレクトリの場合、所有者による検索@<fn>{searchable}および（ディレクトリ内への）移動を許可。
040	グループのメンバからの読み込みを許可。
020	グループのメンバからの書き込みを許可。
010	ファイルの場合、グループのメンバによる実行を許可。
　	ディレクトリの場合、グループのメンバによる検索および（ディレクトリ内への）移動を許可。
004	他者からの読み込みを許可。
002	他者からの書き込みを許可。
001	ファイルの場合、他者による実行を許可。
　	ディレクトリの場合、他者による検索および（ディレクトリ内への）移動を許可。
//}

//table[table-chmod-symbol-who][シンボル指定(who):操作対象を指定する]{
だれ	説明
------------------------------------
u	ファイルの所有者が対象
g	ファイルのグループに属しているユーザが対象
o	上記２つに該当しないユーザ、他者が対象
//}

//table[table-chmod-symbol-perm][シンボル指定(perm):（whoで指定した対象に対する）権限の追加・削除]{
権限	説明
------------------------------------
r	読み込み許可ビット
w	書き込み許可ビット
x	実行もしくは検索/移動許可ビット
//}

//footnote[searchable][マニュアルにsearchableとあるので直訳だが、実際に何を意味するのか？を正確に説明することは難しい。とりあえず、ディレクトリの中を見る/に移動するには@<B>{+x}が必要と覚えておいてほしい]





=== 実行例 




アクセス権限が0664(rw-rw-r--)のtext.txtに0644(rw-r--r--)を設定する。

//list[][][fontsize=xx-small]{
$ ls -l @<balloon>{このコマンドでファイルの権限を確認できる}
-rw-rw-r-- 1 admin205 group205 63 Sep 10 16:07 test.txt

$ chmod 644 text.txt
もしくは
$ chmod u=rw,g=r,o=r text.txt

$ ls -l
//}




==== 実行結果




//list[][][fontsize=xx-small]{
-rw-rw-r-- 1 admin205 group205 63 Sep 10 16:07 test.txt   @<balloon>{変更前}

-rw-r--r-- 1 admin205 group205 63 Sep 10 16:07 test.txt   @<balloon>{変更後}
//}




==== 解説




アクセス権限が0664(rw-rw-r--)のtext.txtが、0644(rw-r--r--)に変更された。
「所有者(admin205)」と「他者」の権限に変更は無いが、
グループ所属のユーザはtext.txtに書きこめなくなった。





=== 知っていると便利なオプション: -v もしくは --verbose@<fn>{chmod-v}




処理されたファイルごとに処理結果を出力する

//footnote[chmod-v][LinuxとWindowsのみ。正確にはGNU coreutilsのcpをインストールしている場合に利用できるオプション。@<B>{Unix伝統のchmodコマンドに -v オプションは無い}]





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




=={cp} @<term>{cp}




@<idx>{ファイル((ふぁいる))<<>>をコピーする((をこぴーする))}





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




いま作業しているディレクトリ以下には、次のようにhtdocsフォルダとtest.txtファイルがある。

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




=={curl} @<term>{curl}




HTTPリクエストを利用してデータを取得する。
「ブラウザの代わり」や「@<idx>{ファイル((ふぁいる))<<>>をダウンロード((をだうんろーどする))}する」といった用途で利用できる。




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





=== 知っていると便利なオプション: -o, -O







==== -o (小文字 o、英小文字のオー、OscarのO)




出力結果をファイルに保存する。




===== 実行例 




//list[][][fontsize=xx-small]{
$ curl -o 保存するファイル名 URL
//}




===== 実行結果 （https://api.fml.org/dist/www.pyの中身を3w.pyとして保存する場合）




//list[][][fontsize=xx-small]{
$ curl -o 3w.py https://api.fml.org/dist/www.py
	% Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
																Dload  Upload   Total   Spent    Left  Speed
100  9698  100  9698    0     0  99644      0 --:--:-- --:--:-- --:--:-- 99979

$ ls  @<balloon>{ディレクトリ内のファイルを確認}
3w.py
//}





==== -O (大文字 O、英大文字のオー、OscarのO)




出力結果をリモートファイルと同じ名前で保存する。





===== 実行例 




//list[][][fontsize=xx-small]{
$ curl -O URL
//}





===== 実行結果 （https://api.fml.org/dist/www.pyをwww.pyとして保存する場合）




//list[][][fontsize=xx-small]{
$ curl -O https://api.fml.org/dist/www.py
	% Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
																Dload  Upload   Total   Spent    Left  Speed
100  9698  100  9698    0     0  99644      0 --:--:-- --:--:-- --:--:-- 99979

$ ls  @<balloon>{ディレクトリ内のファイルを確認}
www.py
//}
#@# @<balloon>{ディレクトリ内のファイルを確認} verify




#@# 




=={df} @<term>{df}




Unixの@<idx>{ストレージ((すとれーじ))<<>>利用状況を確認((りようじょうきょうをかくにん))}できる。




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
　		（OSが割り当てた「デバイスの識別子」もしくは「ファイルシスシステムの種類」）
1K-blocks	使用できるディスク容量、基本単位はKBである
　		例：（/の）/dev/xvda1ファイルシステムの容量は7838MBである
Used		使用中のディスク容量
Available	ディスクの空き容量
Use%		ディスクの使用率
Mounted on	ファイルシステムがどのディレクトリで使えるか
　		（Unix用語では「ファイルシステムのマウント先ディレクトリ」）
　		例：/dev/xvda1は/（ルートディレクトリ）にマウントされている
//}





=== 知っていると便利なオプション: -m




MB単位で出力する(1MB=1024KB)@<fn>{df-m}。




===== 実行例




//list[][][fontsize=xx-small]{
$ df -m 
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
たとえば2行目のudevは、@<code>{485284KB/1024 = 474（473.9を繰り上げ）}なので、MBに変換された値が表示されている。


//footnote[df-m][いまどきのストレージは大きいのでMBどころかGBやTB単位で表示してほしいと思うかもしれない。KBとMBの表示は良いのだが、それより大きい単位はLinux(GNU)系とBSDでオプションが異なる。]

//note[IO-unit][ストレージやIOの基本単位]{

dfに限らずストレージやIO統計のツールでは、表示の単位に気をつけたい。
歴史的に@<idx>{ストレージ((すとれーじ))<<>>の基本単位((のきほんたんい))}は1セクタ@<idx>{512}バイトであるが、
ツールやOSごとに表示単位はマチマチなので注意が必要だ。

セクタ数表示なのか？バイト表示なのか？
1000で割った数字なのか？
それとも1024で割った数字なのか？
など気をつける点がいろいろある。
正解はマニュアルを読めとしか言えないのだが...

//}



#@#

//image[windows-command-prompt][WindowsのコマンドプロンプトでAWS EC2にsshし、作業後にexitしてWindowsに戻ってきた様子][scale=1.0]




=={exit} @<term>{exit}




sshやsudoコマンドでログインしたときに、ログイン先から@<term>{ログアウト((ろぐあうと))}できる（@<img>{windows-command-prompt}）。
Windowsなどの
ターミナルアプリ（例：tetaterm）上でexitコマンドを実行した場合、そのターミナルアプリごと閉じてしまうことに注意
（注：@<img>{windows-command-prompt}は閉じる一歩手前の状態。さらにexitを入力すれば、このウインドウごと閉じてしまう）





=== 書式




//list[][][fontsize=xx-small]{
$ exit
//}





=== 実行例




以下、Windowsのターミナルアプリ上でsshコマンドを実行し、
EC2上に作成した@<idx>{Debian}のサーバにSSHログインしている前提とする

//list[][][fontsize=xx-small]{
Windowsのターミナルアプリ ---(SSH)---> Debian GNU/Linux (EC2)
//}





==== 実行例1 （EC2からログアウトする）




//list[][][fontsize=xx-small]{
admin@16.32.64.128$ exit
//}
@<idx>{Debian}上で@<B>{exit}コマンドを実行する




==== 実行結果1




//list[][][fontsize=xx-small]{
admin@16.32.64.128$ exit
Script done.
Connection to 16.32.64.128 closed.
C:\Users\b2902900>
//}
ssh先からログアウトして、Windowsのターミナルに戻る。
出力例の最終行@<code>{C:\Users\b2902900> }はSSH元のPCのターミナルに戻ってきた様子。





==== 実行例2 （Windowsのターミナルアプリからログアウトする）




//list[][][fontsize=xx-small]{
C:\Users\b2902900> exit
//}
（実行例1の続きで）いまはWindowsのターミナルに戻っている。
その上で、もういちどexitを実行すると






==== 実行結果2




ターミナルアプリごと閉じてしまう



#@# 




=={host} @<term>{host}




コマンドの引数を検索し、
その引数に紐づくドメイン名やIPアドレスの情報を出力する。
よく使う操作に次のものがある。

 * 正引き: 引数がドメイン名 -> @<idx>{IP((あいぴーあどれす))<<>>アドレスを出力((あどれすをしゅつりょく))}
 * 逆引き: 引数がIPアドレス -> @<idx>{ドメイン名((どめいんめい))<<>>を出力((をしゅつりょく))}





==== 書式




//list[][][fontsize=xx-small]{
$ host 名前
//}
「名前」の部分にはドメイン名やIPアドレスを指定する

以下に「@<idx>{正引き((せいびき))}」と「@<idx>{逆引き((ぎゃくびき))}」の実行例を示す。





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

@<idx>{host} と似たコマンドとして、@<idx>{dig} と @<idx>{nslookup} も存在する。
これら3つのうち、どれがデフォルトで使えるか？はOSごとにマチマチなので注意しよう。
もちろんインストールすれば、どの環境でも使用できる。

ちなみに、Windows の場合は、nslookup コマンドが標準搭載されている。

//}



#@# 

//footnote[hostname][@<B>{ホスト名}とは、各機器に便宜上つける名前だ。たいてい、サーバの役割が分かる名前をつける。@<br>{}例：メールサーバはmail、ファイルサーバはfs]




=={hostname} @<term>{hostname}




このコマンドを実行したコンピュータの@<idx>{ホスト((ほすと))<<>>名を表示する((めいをひょうじする))}@<fn>{hostname}。
SSH接続している場合、接続先のホスト名が表示されることに注意。
また、Unix 系の OS (@<idx>{Debian} や @<idx>{Ubuntu} など)ではホスト名の確認に加えて、ホスト名を設定することができる。
以下に、ホスト名の確認と設定の実行例を示す。





==== 書式




//list[][][fontsize=xx-small]{
$ hostname
//}





==== 実行例 (ホスト名の確認)






//list[][][fontsize=xx-small]{
$ hostname
//}








==== 実行結果 (ホスト名の確認)






//list[][][fontsize=xx-small]{
$ hostname
ip-172-31-9-130
//}



この場合、「ip-172-31-9-130」がホスト名となる
（注： Windows はこのホスト名の確認のみ行うことができる）。






==== 実行例 (ホスト名の設定)（注：Unix 系 OS 限定・Windowsは不可）@<fn>{column-set-hostname} 






//list[][][fontsize=xx-small]{
$ hostname <設定したいホスト名>
//}








==== 実行結果 (ホスト名の設定)






//list[][][fontsize=xx-small]{
$ hostname debian.example.co.jp
//}



//list[][][fontsize=xx-small]{
$ hostname
debian.example.co.jp
//}


ホスト名の設定を行う場合、実行しても設定結果が出力されるわけではないため、改めて hostname コマンドなどを実行し確認する必要がある。
ただし、ホスト名の設定には管理者 (root) @<idx>{権限((けんげん))}が必要となるため、多くの場合、hostname コマンドの前に sudo コマンドをつけなくてはいけない。
また、hostname コマンドで設定したホスト名は恒久的には変更されず、再起動すると設定前のホスト名に変更される。

//footnote[column-set-hostname][hostnameコマンドでホスト名をつける作業は通常おこなわない。OSの各種設定は@<idx>{/etc}以下の設定ファイルを適切に編集し、再起動、設定が反映されていることを確認するべきである]



#@# 




=={id} @<term>{id}




ユーザIDやユーザ名、グループID、グループ名などの識別情報を出力する。
自分（自分のユーザ名）の役割や@<idx>{権限((けんげん))}を確認するために利用する。





==== 書式




//list[][][fontsize=xx-small]{
$ id

$ id ユーザ名
//}
「ユーザ名」を指定しない場合は、このコマンドを実行している「ユーザ名」の情報が表示される。
たとえば、AWSの@<idx>{Debian}イメージであれば、通常あなたの使うユーザはadminである。
よって
//list[][][fontsize=xx-small]{
$ id
//}
も
//list[][][fontsize=xx-small]{
$ id admin
//}
も同じようにadmin@<idx>{ユーザ((ゆーざ))<<>>の情報を表示する((のじょうほうをひょうじする))}





=== 実行例







==== 実行例 




//list[][][fontsize=xx-small]{
$ id admin
//}






==== 実行結果 （ユーザadminの情報を出力する場合）




//list[][][fontsize=xx-small]{
$ id admin
uid=1000(admin) gid=1000(admin) groups=1000(admin),4(adm),20(dialout),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev)
//}
ユーザ名adminのユーザIDや所属グループがわかる

 * uid=1000(admin):				ユーザ名がadmin、ユーザIDが1000
 * gid=1000(admin):				グループ名がadmin、グループIDが1000
 * groups=1000(admin),4(adm),20(dialout):	ユーザadminは上述のデフォルトグループadminに加えてadmとdialoutグループにも所属している







==== 実行結果 （自分のユーザ情報を出力する場合）






//list[][][fontsize=xx-small]{
$ id
uid=1000(admin) gid=1000(admin) groups=1000(admin),4(adm),20(dialout),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev)
//}
出力がユーザadminの場合と同じであることに注意してほしい。






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




ユーザIDのみを出力する@<fn>{id-u}。






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

//footnote[id-u][このオプションをターミナル上で利用することは少ないが、シェルスクリプトやDockerfileを書く際には必要な知識である]



#@# 




=={ip} @<term>{ip}




ネットワークデバイスやルーティングなどの表示や変更ができる。
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

 * OBJECT部分には、
   @<B>{address}（IPアドレス）や
   @<B>{route}（経路情報）など、
   ネットワークの構成要素を指定する。
 * COMMAND部分では、そのOBJECTごとのコマンドが利用できる。
 * COMMANDを指定しない場合は、たいてい情報の表示が行われる。
   たとえば、
   @<code>{ip address}
   は
   @<code>{ip address show}
   と同じ意味に解釈され、現在のIPアドレス情報が表示される
 * もしCOMMANDが分からない場合は、
   OBJECTに関わらずhelpコマンドを指定すればヘルプメッセージが表示される





=== 実行例: IPアドレス情報を調べる （@<idx>{ip<<>> address}）




address オブジェクト（省略してaも可）を用いて、
ネットワークインターフェース@<fn>{net-if}に関連するIPアドレス情報を確認できる。

//footnote[net-if][データを送受信するための接続ポイント]




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

//footnote[macaddr][各ネットワークインターフェースに割り当てられた一意の物理アドレス]

最重要の確認項目は次の２つ。

 *  inet行:	ipv4アドレス/プレフィックス（のビット数）が表示されている
 ** 上の例では、172.31.13.152/20
 *  link/ether行: MACアドレス@<fn>{macaddr}が表示されている
 ** 上の例では、0a:16:41:0c:9e:43

左端の数字(1:, 2:, ...)に特別な意味はない。
@<code>{2: enp4s0:}の@<code>{enp4s0}部分はネットワークインターフェイス名である。
この名前はOSが割り当てるため、OSやハードウエア構成によって異なる値を取ることに注意。
あくまでもenp4s0は一例である。
一昔前までLinuxでは@<idx>{eth0}のような名前の付け方をしていたが、
最近、enp4s0のようなハードウエア情報に基づく名前の付け方に変わった@<fn>{bsd-device-name}

//footnote[bsd-device-name][最初からBSD Unixに合わせておけばよかったのに！と思ったあなたは同志です:-)]





=== 実行例: IPアドレス情報を調べる （@<idx>{ip<<>> route}）




route オブジェクト（省略してrも可）を指定すると、
ルーティング（ネットワークの経路）情報を出力する。




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
 * 2行目以降はネットワーク（IPアドレス/プレフィックス）ごとの情報
 ** 例えば2行目の@<code>{210.128.53.200/29}は、
    @<code>{210.128.53.200/29}というアドレス範囲への通信のルーティング情報
 ** dev enp3s8のenp3s8は、
    @<code>{210.128.53.200/29}が存在するネットワークのインターフェイス（デバイス）名。
 ** src 210.128.53.204のIPアドレスはネットワークインターフェイス（デバイス）のIPアドレス。    つまりenp3s8に付いているIPアドレスと同じ


//note[column-ip][ipコマンドによる設定変更は原則おこなわない]{

ipコマンドによる設定変更も可能だが、
これは障害対応の場合にのみ許される作業と考えておいたほうがよい。

通常、ネットワークの設定は@<idx>{/etc}以下の設定ファイルにもとづきOS起動時に行われる。
ネットワーク関連の変更は/etc以下を適切に変更後、再起動してOSに設定してもらうべきである
//}






=={less} @<term>{less}




@<idx>{ファイル((ふぁいる))<<>>を表示する((をひょうじする))}コマンドだが、
画面単位で行ったり来たり、検索なども出来るところが便利。
@<B>{@<idx>{vi}}エディタのコマンドモードだけが使える状態と考えて良い。

教科書やマニュアルでは「ファイルを表示する」際に@<B>{cat}コマンドを紹介しがちだが、
実際の現場では、何百行もあるファイルに対して@<B>{cat}を使ってしまい、
目的の行を見ることが出来ず、
後悔したあげくに@<B>{less}を使うことがシバシバである。
@<B>{cat}@<secref>{cat}節と@<B>{vi}@<secref>{vi}節も参照。

@<B>{「ファイルを見るときにエディタを使う」方法は良くない。うっかり編集してしまうかもしれないから。}
@<B>{一つの操作/機能は一つの専用コマンドで行うべき}である。
この先祖伝来の@<idx>{Unix<<>>コマンド群の設計思想((こまんどぐんのせっけいしそう))}@<fn>{unix-design}
を覚えておいてほしい

//footnote[unix-design][最近のコマンドは、そうでもないという非肉が込められている文章:-)]





=== 書式




//list[][][fontsize=xx-small]{
$ less ファイル名
//}




=== 実行例： www.pyファイルを表示する




//list[][][fontsize=xx-small]{
$ less www.py
//}
 *  @<B>{q}を叩くと終了する(もちろんquitのq)
 *  スペースを叩くと次の画面に変わる（スクロール）
 *  @<B>{b}を叩くと一つ前の画面に戻る(backのb)
 *  @<B>{/}を叩くと検索モードに入ることが出来る
 ** @<B>{/}は画面の下に向かって検索を行う
 ** @<B>{?}は反対で、画面の上に向かう検索が出来る
 *  @<B>{h}を叩けば、ヘルプ画面が表示される(もちろんhelpのh)
 *  @<B>{v}を叩くと、いま見ているファイルに対して@<B>{vi}エディタを起動する
 ** つまり必要なら編集モードへ移行できるわけである


//note[more-and-less][moreとless、lessがないならmoreも試してみるとよい]{
このような操作には元々@<B>{@<idx>{more}}コマンドがあったが、
その機能強化版として@<B>{less}が開発された
(moreの反対語なのに強化版という名付け方が御洒落:-)。

いずれにせよ、moreのほうが古いのでlessコマンドがない場合はmoreを試してみるとよい。たいていは、あるはずだ。
//}






=={logout} @<term>{logout}




@<B>{exit}コマンドと同様に、SSH先のLinux/Unixから@<idx>{ログアウト((ろぐあうと))}できる。

@<secref>{exit}節も参照のこと。




=== 書式




//list[][][fontsize=xx-small]{
$ logout
//}



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



#@# 




=={lsblk} @<term>{lsblk}




利用可能な@<idx>{ブロックデバイス((ぶろっくでばいす))<<>>をツリー状に一覧表示する((をつりーじょうにいちらんひょうじする))}@<fn>{block-device}。

//footnote[block-device][ブロックデバイスとは、512バイトなどのまとまったデータ量(ブロック)を単位として読み書きするHDDやSSDなどの記憶装置のこと。]





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




#@# X-TODO 左端の特殊記号のせいでコンパイルすると、ずれるらしい (PENDING)
#@#        スペースで微調整して少しマシにしたけれど、根本的な解決方法は不明
//list[][][fontsize=xx-small]{
NAME      MAJ:MIN RM  SIZE RO TYPE MOUNTPOINTS
xvda      202:0    0    8G  0 disk 
├─xvda1  202:1    0  7.9G  0 part /
├─xvda14 202:14   0    3M  0 part 
└─xvda15 202:15   0  124M  0 part /boot/efi
//}
実用上は、左端のデバイス名と右端のマウントポイントだけ見ていれば十分だろう。
詳細は@<table>{lsblk}を参照

#@# X-TODO lsblkの表の位置調整 (DEFERRED)
//table[lsblk][lsblkの表示]{
1行目		説明
----------------------------------------
NAME		デバイス名（OSが自動的に割り当てている）
MAJ:MIN		MAJはメジャーデバイス番号。どのデバイスドライバを使うべきかを示す情報
　		MINはマイナーデバイス番号で、同一ドライバを使用するデバイスを区別する番号
　		(例：ここに表示されているxvdaはすべて同じデバイスドライバを使用している)
RM		リムーバルディスクか否か（OS動作中に取り外し可能であれば1）
SIZE		デバイスの容量
RO		読み取り専用かどうかを示している。読み取り専用であれば1である。
TYPE		デバイスのタイプ
　		disk = 物理ディスク、part = パーティション(ディスクを論理分割したもの)
MOUNTPOINTS	ファイルシステムがマウントされている場合、そのパスが表示される
//}



#@# 




=={lscpu} @<term>{lscpu}




@<idx>{CPU<<>>の情報を表示((のじょうほうをひょうじ))}する




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


#@# X-TODO lscpu table の場所 (DEFERRED)
//table[lscpu][lscpuの読み方(一部)]{
項目(一部)		説明
------------------------------------------------------------
Architecture		CPUのアーキテクチャ
CPU op			CPUがサポートしてるモード
　  			(例：64bit,32bitアーキテクチャをサポートしている)
Address sizes		物理アドレスと仮想アドレスのサイズ
　			(例：物理アドレス46bit,仮想アドレス48bit)
Byte Order		バイトオーダ(例：リトルエンディアンという最下位バイトが最初に来る形式)
CPU(s)			システムに搭載されてるCPUの数
On-line CPU(s) list	現在使用可能なCPUのリスト(例：0番目のCPU1つのみが使用可能)
//}



#@# 




=={lsmem} @<term>{lsmem}




(オンライン状態になっている)
メイン@<idx>{メモリ<<>>の利用可能な範囲を表示((のりようかのうなはんいをひょうじ))}する。




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

#@# X-TODO lsmem table の位置調整 (DEFERRED)
//table[lsmem][lsmemの読み方]{
項目			説明
------------------------------------------------------------
RANGE			メモリのアドレス範囲(この例では1GBを示している)
Memory block size	1ブロック当たりのサイズ(1GB/8=128MB)
Total online memory	使用可能な(オンラインの)メモリサイズ(例：1GB)
Total offline memory	使用不可能な（現在オフライン@<fn>{offine-memory}の）メモリサイズ
//}


//footnote[offine-memory][オフラインとは？メモリをブロック単位でオンライン/オフラインを設定できるのだが、超巨大な仮想基盤でもないかぎり使う機会のない機能に思える。詳細は@<href>{https://www.kernel.org/pub/linux/utils/util-linux/}の@<term>{chmem}のマニュアルとソースコードを参照したほうがよい]






=={man} @<term>{man}




@<idx>{Unix<<>>マニュアルを見る((まにゅあるをみる))}コマンド。
ただし、
初心者向きではない。
Unixマニュアルの記述は網羅的だが、
いちから読むというより、必要なときにピンポイントでコマンドの使い方の確認に使うことが多いと思う。








=== 書式




//list[][][fontsize=xx-small]{
$ man コマンド名
//}




=== 実行例： lsコマンドのマニュアルを見る




//list[][][fontsize=xx-small]{
$ man ls
//}
 * 完全な書式、すべてのオプションの説明等が表示される（ので刮目して読め:-）


//note[][蛇足：manがあるのだから、このような本は...]{
本来、このような技術同人誌は不要なのですね... ;-)
//}



#@# 




=={mkdir} @<term>{mkdir}




@<idx>{ディレクトリ((でぃれくとり))<<>>を作成する((をさくせいする))}




=== 書式




//list[][][fontsize=xx-small]{
$  mkdir [option]... DIRECTORY...
//}

 * 引数に、作成するディレクトリを少なくとも1つは指定する必要がある
 * 引数は可変長。作成したいディレクトリは、引数として複数つなげて書けば良い。
   Unixなので、いつものように@<B>{スペース区切り}である





=== 実行例







==== 前提




現状の確認は@<code>{ls}コマンドで行える。
//list[][][fontsize=xx-small]{
$ ls
www.py htdocs/ 
//}
いま作業しているディレクトリには、
www.pyというファイルとhtdocsというディレクトリがある。




==== 実行例1




//list[][][fontsize=xx-small]{
$ mkdir test
//}
新たに@<code>{test}ディレクトリを作成し、結果をlsコマンドで確認する。





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




=={nano} @<term>{nano}




Windowsのメモ帳のような@<B>{シンプルな操作方法}の@<idx>{エディタ((えでぃた))}。

ファイル名を指定することで、指定した@<idx>{ファイル((ふぁいる))<<>>を編集する((をへんしゅうする))}ことができる。
ファイル指定をせずに起動した場合や、
存在しないファイルを指定して起動した時は、
起動後に、あらためて
新規ファイルの作成・編集ができる。

//footnote[vim][@<idx>{vi<<>>クローン((くろーん))}。オリジナルのviを遥かに超えてより強化されたvi似のエディタ。今どきはvimがviという名でインストールされていることが多いが、たまに@<term>{BSD<<>>4.4---}由来の@<term>{nvi}もあるので注意]

//note[unix-editors][Unixのエディタ]{

Unixに昔からあるテキストエディタとしては@<idx>{vi}や@<idx>{emacs}が有名だ。
viやvim@<fn>{vim}には複数のモードがあるが、nanoにはモード変更などない。
nanoは、モード変更を使用せず、
画面下部に書かれているショートカットを用いることでコピーやペースト等を行う
（この点nanoの使い勝手はemacsに近い）。

//}


#@# X-TODO nano 図表の位置調整(最後におこなう) (DEFERRED)
//image[nano][nano画面下のヘルプメッセージ（ショートカットのチートシート）][pos=t]

//table[nano-shortkeys][nanoコマンドのショートカットキー（抜粋）]{
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
 * そのファイルが存在しない場合は、ファイルを新規作成する
 * その後エディタ画面になり、文字を入力できるようになる





=== ショートカットについて




上述のとおり、
nanoエディタを起動した際には、
図にあるショートカットの説明が確認できる
（@<imgref>{nano}を参照）。
なお、
ショートカットにある@<B>{^}という文字は、Windowsであればctrl、MacOSXであればcommandと読み替えてほしい。

#@# //image[nano][nano画面下のヘルプメッセージ（ショートカットのチートシート）][pos=b]




==== 終了する （ctrl +x もしくは command +x）




nanoエディタ画面から抜けるときに使用する。
これを使用した際には、保存するかどうか聞かれるので、保存するときはyを、保存しないときはnを押す。
yを押した場合、保存したいファイル名を聞かれるので、そのままの名前でよい場合はEnterを押す。
ファイルを保存後、ターミナルに戻る。
もし、違う名前で保存したい場合は、ファイル名を変更してEnterを押すことで保存される。
nを押した場合、保存せずにターミナルの画面に戻る（編集内容は廃棄される）。




==== 上書き保存する （ctrl +s もしくは command +s）




変更内容を上書き保存する場合に入力する。この場合、エディタは続行される。




==== 選択範囲の開始 （ctrl +6 もしくは command +6）




後述するカット及びコピーを範囲選択する際の
始点をカーソル位置で決定する。




==== 選択範囲の終了 （alt +6 もしくは option +6）




選択の終点を指定する。上述の「選択範囲の開始」とペアの操作である。




==== 選択範囲の削除 （ctrl +k もしくは command +k）




（上述の操作で）選択した範囲を削除する。




==== 選択範囲のペースト （ctrl +u もしくは command +u）




（上述の操作で）選択した範囲をペーストする。





=== マウス操作




最近のアプリはウインドウシステムとの連携も意識しているので、
CUIのエディタでもGUI操作による入出力を相当うけつける。

nanoでは文字列をドラックして選択して右クリックをした後、
コピーを選択することで、文字列のコピーができる。
同様に貼り付ける場合は、ペーストしたい位置にカーソルを移動後、
右クリックしてペーストを選択することで、文字列のペーストができる。



#@# 




=={ping} @<term>{ping}




ターゲット@<idx>{ホスト((ほすと))<<>>の生死を確認する((のせいしをかくにんする))}コマンド。
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
ttl		ルータを最大で何個まで通過できるか？
time		送受信の往復にようした時間
//}






==== 実行結果 （成功パターン:10.252.0.11から応答があったとき）




//list[][][fontsize=xx-small]{
$ ping 10.252.0.11
PING 10.252.0.11 (10.252.0.11) 56(84) bytes of data.
64 bytes from 10.252.0.11: icmp_seq=1 ttl=64 time=0.039 ms
64 bytes from 10.252.0.11: icmp_seq=2 ttl=64 time=0.042 ms
    〜中略〜
64 bytes from 10.252.0.11: icmp_seq=7 ttl=64 time=0.018 ms
^C                                    @<balloon>{Ctrl-Cを打ち込んだ行}
--- 10.252.0.11 ping statistics ---
7 packets transmitted, 7 received, 0% packet loss, time 6151ms
rtt min/avg/max/mdev = 0.017/0.027/0.042/0.010 ms
//}
最終行の
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
^C                                    @<balloon>{Ctrl-Cを打ち込んだ行}
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

pingという単語は@<idx>{潜水艦のソナー((せんすいかんのそなー))}に由来する。
（アクティブ）ソナーとは
「潜水艦から音波を出し、障害物から反射してくる音波を分析する」ことで水中の様子をさぐる仕組みのこと。
水中でのレーダーと考えれば良い。
@<code>{ping}コマンドは、それのサイバースペース版

//}



#@#




=={ps} @<term>{ps}




@<idx>{プロセス((ぷろせす))<<>>の情報を表示する((のじょうほうをひょうじする))}コマンド。





=== 書式




//list[][][fontsize=xx-small]{
$ ps [options]
//}

 * 引数なしで実行しても、あまり有益な情報は得られない
 * 典型的な使い方は@<code>{ps auxww}である@<fn>{ps-format}@<fn>{ps-option}。この形で覚えることを推奨

//footnote[ps-format][書式は歴史的に2系統ある。Linux搭載の@<code>{ps}コマンドは両系統の上位互換に見える。本書では伝統のUnix由来のオプションのみを紹介する]
//footnote[ps-option][古代Unixとの互換性を保つため、psコマンドは、オプションに@<B>{-}をつけてもつけなくても受け付ける数少ないコマンドである。例：ps auxwwとps -auxwwどちらでもよい]
   




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
PID		プログラムごとに割り当てられている番号（プロセスIDの略）
TTY		プロセスが関連づけられているターミナル
STAT		プロセスの状態（aオプション指定時）
TIME		プロセスが使用したCPU時間
CMD		実行されているコマンド
//}





=== 知っていると便利なオプション: a 




他のターミナルを含めたプロセスを表示する




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
TTY列は各ユーザに割り当てられたターミナルである。
前述の出力例で分かるとおり、pts/1の行が自分がいる@<B>{"ターミナル"}を意味している。
その他のtty1、tty7、pts/0は別のターミナルである。
この例ではpts/0行が@<code>{-bash}なので、
自分以外のユーザも同じサーバ上にログインして（＝シェルを起動していて）作業中であることが分かる。

STAT列はプロセスの状態で、
@<table>{ps-stat}を組み合わせた値が表示される。

//table[ps-stat][psコマンドのSTAT列の読み方]{
STAT列の項目	説明
------------------------------------------------------
R		実行中(CPUを今使っている)
S		待機中(例：-bashはユーザからの入力を待っている)
s 		セッションリーダー(sが付くプロセスが、sが付かないプロセスを呼び出している)
l@<fn>{lwp}	マルチスレッドプロセスであること（複雑なプロセスにつくことが多い）
+		（ターミナルに紐づいていて）ユーザが操作できる状態のプロセス
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
このどちらかの列の値が異常に大きいプロセスが犯人である可能性が高い。

//table[ps-u][ps uで追加表示される列]{
列	 説明
------------------------------------------------------
USER	（右端のコマンドを実行している）ユーザ名
%CPU	プロセスのCPUの使用率
%MEM	プロセスの物理メモリの使用率
VSZ	仮想メモリを確保しているサイズ
RSS	物理メモリを確保しているサイズ
//}

#@# ページ下部に出力するために脚注も挿入位置の調整が必要 (DEFERRED)
//footnote[lwp][（IT古典部むけ？）マルチスレッドなのに、l（エル）なことに疑問を持つあなたはエンジニア向きである。これはスレッドに相当するカーネルのlightweight processという用語に由来する。]




=== 知っていると便利なオプション: x




ターミナルに紐づかないプロセス（サーバとしてターミナルを切り離した状態で動作するプロセスなど）も表示する。




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
TTYが？のものは、ターミナル（TTY）が紐付いていないサーバプロセスである。





=== 知っていると便利なオプション: aux,auxww




これまで説明したオプションのa,u,xを組み合わせたもの。
しかし、auxだと長いコマンドの場合に出力が省略されるため、コマンドライン引数をすべて確認したい場合はauxwwとする




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
（上の例では省略されているが）基本的に全てのプロセスが表示されている。

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
@<idx>{ps<<>> aux}の場合と異なり、
@<idx>{ps<<>> auxww}の場合はコマンドの末尾まで出力されていることがわかる。



#@#

//footnote[process-tree][Unixの場合、プロセスにも親子関係があり、プロセスもツリー状になっている（注：学部のOSの授業では、ここまで説明しない）。そのため、親プロセス、子プロセスという言い回しもある]




=={pstree} @<term>{pstree}




@<idx>{プロセス((ぷろせす))<<>>の親子関係をツリー状に((のおやこかんけいをつりーじょうに))}アスキーアートで表示する@<fn>{process-tree}




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
        ├─sshd───sshd───sshd───bash───script───bash───pstree　@<balloon>{(1)}
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

 * (1)の行をみると、 bash(pstreeを入力したターミナルに紐づいたシェル)がpstreeを呼び出していることがわかる



#@#




=={pwd} @<term>{pwd}




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
現在自分（ユーザadmin）がいるディレクトリが表示されている様子。

#@# pwd -L or -P の問題があるが、この同人誌の読者にとっては関係ないと思うので、その（いったんは準備した）注意書きは削除とする (2025/02)



#@# 




=={python} @<term>{python3}







=== 書式




//list[][][fontsize=xx-small]{
$ python3
$ python3 ファイル名
//}

 * python3と単体で入力した場合は対話モードとなり、コードを入力すると実行される。
   quit()と入力すれば、対話モードは終了する
 * 引数があれば、その引数のファイルを1行ずつ実行していく（スクリプト言語、下記ノートを参照）





=== 実行例




以下のように@<code>{print}一行だけのhello.pyファイルがあるとする
//list[][][fontsize=xx-small]{
$ cat hello.py

print("Hello World")
//}
ちなみに、ファイルの中身を確認するときは@<idx>{cat}コマンドを使うと表示できる、
@<secref>{cat}節も参照。





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



//note[compiler-vs-script-languages][コンパイラ言語とスクリプト言語]{

プログラミング言語は大きく分けて二種類ある。
@<idx>{コンパイラ言語((こんぱいらげんご))}と@<idx>{スクリプト言語((すくりぷとげんご))}だ。

コンパイラ言語の代表例は@<term>{C言語((しーげんご))}である。
(a)まずソースコードを書き(b)それをコンパイラで実行形式(@<code>{a.out})に変換する。
OSに実行してもらうのは@<code>{a.out}ファイルである。

一方、pythonはスクリプト言語である。
www.pyのようなプログラムは実行ファイルではなくソースコードにあたる。
pythonの場合、実行ファイルは作成しない。
pythonプログラムがソースコード(www.py)を一行ずつ読みながら逐次実行する。
こういったプログラムを@<term>{インタープリタ((いんたーぷりた))}と呼ぶ。
「pythonのプログラムを動かす」という表現は上のような意味である。
よって、プログラム(www.py)自体に実行@<idx>{権限((けんげん))}がなくてもwww.pyを実行できる
（注意：www.pyに実行権限は不要だが、pythonがwww.pyを読める権限は必要である）。
//}



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




sample.txtファイルを、exampleという名のサーバ上の/home/testディレクトリへコピーしたい

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



#@#




=={ss} @<term>{ss}




コマンド名はsocket statisticsの頭文字。
ネットワーク通信で利用している@<idx>{ソケット((そけっと))<<>>の情報を出力((のじょうほうをしゅつりょく))}する。




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
Netid State  Recv-Q Send-Q Local Address:Port       Peer Address:PortProcess
udp   UNCONN 0      0            0.0.0.0:123        0.0.0.0:*
      〜 省略 〜
tcp   LISTEN 0      128          0.0.0.0:22         0.0.0.0:*
tcp   LISTEN 0      511          0.0.0.0:80         0.0.0.0:*
//}
実用上は、開いているポート番号（@<code>{:数字}部分）の確認に使うことが多い。
「IPアドレス:数字」形式の部分が重要である@<fn>{ip-any}。
その他の詳細は省略する@<fn>{ss-detail}。

//footnote[ip-any][0.0.0.0は「すべて（のIPアドレス）」という意味。「すべて」意味で@<B>{*}を使うツールも多い。@<br>{}サーバやルータは複数のネットワークインターフェイス（IPアドレス）を持ちうることに注意]
//footnote[ss-detail][きちんとマニュアルに説明がないので、正解はソースコードを参照のこと。@<br>{}@<href>{https://www.kernel.org/pub/linux/utils/net/iproute2/}]







=== 知っていると便利なオプション: -l




数字ではなく英語小文字のエル、lima の l
（listenのlに由来する）。
接続待ち状態(StateがLISTEN)のソケットのみを表示する。
サーバプロセスだけを表示したいときに使用する。




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
StateがLISTENの行のみが表示されている。




=== 知っていると便利なオプション: -4




IPv4のソケット情報のみを表示する。





==== 実行例




//list[][][fontsize=xx-small]{
$ ss -4
//}




==== 実行結果




//list[][][fontsize=xx-small]{
Netid State      Recv-Q Send-Q Local Address:Port             Peer Address:Port
udp   ESTAB      0      0      127.0.0.1:57674                127.0.0.1:57674
tcp   ESTAB      0      0      127.0.0.1:6081                 127.0.0.1:35634
tcp   ESTAB      0      0      127.0.0.1:35000                127.0.0.1:48549
      〜 省略 〜
//}
AddressがIPv4表記(数字.数字.数字.数字)の行のみが表示されている。




=== 知っていると便利なオプション: @<idx>{-n}




名前解決を行わない(プロトコル名やドメイン名が表示されない)





=== 知っていると便利なオプション: -l4n




これまで説明したオプションl,4,nすべてを適用する。おすすめのオプション




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



#@#

//footnote[asymmetric-encryption][本文中では「非対称暗号」に統一しておいたが、「公開鍵暗号」という言いまわしの方が広く使われていると思う。「公開鍵」と「秘密鍵」という鍵のペアを用いる。「公開鍵」という表現は「方式」「鍵」どちらの話か？と素人を混乱させるので、非対称鍵という言い回しをしている。]




=={ssh} @<term>{ssh}




他のコンピュータ・サーバにSSH(Secure Shell)プロトコルで@<idx>{ログイン((ろぐいん))}する。
@<idx>{非対称鍵暗号((ひたいしょうかぎあんごう))}@<fn>{asymmetric-encryption}による「認証」と「通信路の暗号化」を行う商用インターネット時代のデファクトスタンダードツール。サーバ運用管理の必須ツール。

認証には、
非対称鍵暗号と@<idx>{対称鍵暗号((たいしょうかぎあんごう))}の両方式が利用できるが、
インターネットからアクセスできるサーバは非対称鍵暗号認証で運用するべきである。




=== 書式




//list[][][fontsize=xx-small]{
$ ssh  [options] DESTINATION
$ ssh  [options] DESTINATION [command [argument...]
//}

 *  「@<code>{ssh サーバ}」の形式でサーバへ遠隔ログインできる
 ** 引数が「サーバ」形式の場合、
    サーバにログインするユーザ名は（今sshコマンドを実行しているユーザ名と）同じと想定される
 ** 「ユーザ@サーバ」つまりメールアドレス形式で、サーバのユーザ名とサーバ名を同時に指定できる
 *  「@<code>{ssh サーバ コマンド}」の形式でコマンドを遠隔実行できるが、演習では使わないため説明は省略




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
最終行は（ログイン先サーバの）シェルのプロンプトである。
この例では@<code>{$ }の左側に「ユーザ名@ipアドレス」が表示されている。





=== 知っていると便利なオプション: -i （i, indiaのi)




-iオプションには、
引数として「（SSH接続に使用する非対称鍵暗号方式の）@<B>{秘密鍵}ファイル」を指定する。
ちなみにオプション名は@<B>{identityのi}である。





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

//footnote[root-priv][ほぼすべての操作が可能な管理者の権限]




=={sudo} @<term>{sudo}




@<idx>{ルート権限((るーとけんげん))}@<fn>{root-priv}を持たない一般ユーザが、
sudoコマンドを使うと、コマンド単位でルート@<idx>{権限((けんげん))}を利用できる




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




コマンドは実行時の@<idx>{ユーザ((ゆーざ))<<>>ID((あいでぃー))}（@<term>{uid}）と紐付いている。
ルート権限を持つユーザ(root)のuidは0なので、
sudoを利用して実行したコマンドはuidが0で動作する。




===== 実行例




@<code>{id}コマンドに、コマンド実行時のuidを表示させてみよう。

@<code>{id}コマンドにより自身のuidについて確認できる。
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
sudoを使う時と使わないときでuidが異なることがわかる





=== 特権ポートでサーバを起動する




ネットワークでは、通信を識別するために、
ネットワークの入出力口（@<idx>{ソケット((そけっと))}）に識別番号（@<idx>{ポート番号((ぽーとばんごう))}）をつけている。
当然サーバが待ち受けするポートもある。
広く利用される（公益性が高い）サーバが使うポート番号には@<term>{1024}未満が割り当てられており、
@<term>{特権ポート((とっけんぽーと))}と呼ばれている。
このポートを利用する際、つまりサーバを起動する際には、ルート権限が必要である

sudoコマンドを利用することでルート権限を取得し、特権ポートでサーバを起動することが出来るようになる





===== 実行例




@<idx>{ポート番号((ぽーとばんごう))<<>>80}番でPythonのWWWサーバを起動する例を見てみよう。

//list[][一般ユーザが普通にサーバを起動する場合][fontsize=xx-small]{
$ python3 -m http.server 80
//}

//list[][sudoコマンドをつけて、サーバを起動する場合][fontsize=xx-small]{
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
sudoなしだと、@<B>{80番ポートを開く権限がない}ため、WWWサーバを起動できない。
sudoを使うことで、@<B>{80番ポートを開く権限得られる}ため、
WWWサーバを起動することができる。





=== 注意点




root権限を持つユーザはセキュリティ上ねらわれやすいユーザであるため、
直接ルートユーザにログインするのではなく、
一般ユーザでログインし、
必要な場合にのみsudoコマンドを利用してルート権限を利用することを心がける。



#@# X-TODO telnet ... 実行例として、ポート番号 13 は適切なのか？ (PENDING)




=={telnet} @<term>{telnet}




他のコンピュータ・サーバに@<idx>{ログイン((ろぐいん))}できる。
暗号化は行わない。
暗号通信をしたい場合は、@<idx>{ssh}コマンドを利用する。
今日では、
「@<idx>{デバッグ((でばっぐ))}」か「LANで@<idx>{ネットワーク((ねっとわーく))<<>>機器の設定((ききのせってい))}」に利用するくらいだが、
何かと便利なコマンドである。




=== 書式




//list[][][fontsize=xx-small]{
$ telnet [options ...] [HOST [PORT]]
//}

 * 引数なしで@<code>{telnet}コマンドを起動すると、@<idx>{対話モード((たいわもーど))}に入ってしまうので注意。
   quitで抜けることが出来る
 * 「@<code>{telnet HOST}」形式で起動すると、HOSTへtelnetプロトコルで接続する
 * 「@<code>{telnet HOST PORT}」形式で起動すれば、
   HOSTの@<idx>{ポート番号((ぽーとばんごう))}PORTとのあいだに@<idx>{TCP}論理回線が構築される。
   アプリケーションプロトコルのデバッグで用いる





=== 実行例







==== 実行例




アメリカ国立標準技術研究所(NIST)の時刻サーバへ接続する
//list[][][fontsize=xx-small]{
$ telnet time.nist.gov 13
//}

#@#  * IPアドレス: ネットワークにつながっている機器(サーバ、PC、スマホなど)に割り振られた番号
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






=={top} @<term>{top}




top コマンドは、OSのステータスのサマリを表示する。

 *  表示は@<B>{数秒おきに自動的に更新}される
 *  8行目以下はpsコマンドに似たプロセス一覧表
 ** いま活発に動いているプロセスが上の方に表示される
 ** 同じコマンドが表示され続けているなら、そのコマンドはシステムを重くしている犯人候補だ




=== 書式




//list[][][fontsize=xx-small]{
$ top
//}

//list[][][fontsize=xx-small]{
top - 01:29:59 up 1 min,  1 user,  load average: 0.09, 0.04, 0.01
Tasks:  86 total,   1 running,  85 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.0 us,  0.3 sy,  0.0 ni, 89.0 id,  0.6 wa,  0.0 hi,  0.0 si, 10.1 st
MiB Mem :    970.0 total,    748.8 free,    229.1 used,    123.9 buff/cache
MiB Swap:      0.0 total,      0.0 free,      0.0 used.    740.9 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
     36 root       0 -20       0      0      0 I   0.3   0.0   0:00.01 kworker/0:1H-kblockd
      1 root      20   0  102128  12068   9184 S   0.0   1.2   0:00.79 systemd
      2 root      20   0       0      0      0 S   0.0   0.0   0:00.00 kthreadd
   ... 以下略 ... 
//}

特に注意するべき項目は次の2ヶ所だろう。

 *  @<code>{load average: 0.09, 0.04, 0.01}
 ** どれくらいシステム（OS）が忙しいのか？の目安@<fn>{loadavg}
 *  @<code>{MiB Mem :    970.0 total,    748.8 free}
 ** メモリ使用量。
    この例では、
    トータルが970MB、未使用が748MB（つまり220MBほど使用中）なので、まだまだ余力があることが分かる

表示の詳細はUnixマニュアルを参照のこと。


//footnote[loadavg][おおむねCPUコア数以下なら気にしなくてよいだろう。load averageとは、プロセスの待ち行列の長さなので、直感的な忙しさとは微妙に異なるが、システム負荷の目安とされている。]



#@# 

#@# 脚注の位置調整 (DEFERRED)
//footnote[NCOM][NTTコミュニケーション。旧Verioを買収して世界規模の長距離回線を擁するTier-1のキャリア。業界人はNTT COMではなくNCOM（えぬこむ）と呼ぶ。電車の中で「NCOMが〜」とか電話してる同業者がいるとドキドキするよね？(w)]
//footnote[comcast][アメリカのケーブルテレビ大手]




=={tracepath} @<term>{tracepath}




宛先にパケットを送信し、宛先までに通過する各ルータのIPアドレスを表示する。宛先のホストまでの@<idx>{ネットワーク((ねっとわーく))<<>>経路を可視化((けいろをかしか))}するために利用する。




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
1:  LAPTOP-A860U3T2.mshome.net                      1.443ms
1:  LAPTOP-A860U3T2.mshome.net                      0.383ms
2:  unifi.localdomain                               1.811ms
3:  10.252.0.1                                      1.910ms
4:  118.23.89.234                                   4.303ms
5:  118.23.89.77                                    5.230ms
6:  221.184.5.205                                   6.879ms
7:  122.1.245.193                                  18.817ms
8:  122.1.245.206                                  21.827ms
9:  ae-9.a03.tokyjp05.jp.bb.gin.ntt.net            19.898ms             @<balloon>{NCOM,東京}
10:  ae-5.r32.tokyjp05.jp.bb.gin.ntt.net           19.778ms asymm 11    @<balloon>{ここまで日本国内}
11:  ae-4.r27.snjsca04.us.bb.gin.ntt.net           128.045ms            @<balloon>{NCOM,サンノゼ}
12:  ae-0.a02.sttlwa01.us.bb.gin.ntt.net           120.781ms asymm 13
13:  ae-0.comcast.sttlwa01.us.bb.gin.ntt.net       116.382ms            @<balloon>{ここまでNCOM}
14:  be-1211-cs02.portland.or.ibone.comcast.net    147.274ms asymm 16   @<balloon>{ここからcomcast}
15:  be-36131-arsc1.burien.wa.seattle.comcast.net  136.669ms asymm 16
16:  ae-501-ar01.seattle.wa.seattle.comcast.net    121.145ms asymm 17
17:  be-2-sur02.bellevue.wa.seattle.comcast.net    152.747ms asymm 20
18:  be-1-sur03.bellevue.wa.seattle.comcast.net    149.624ms asymm 19
19:  50.231.28.130                                 128.459ms asymm 18
20:  no reply
   〜省略〜
30:  no reply
		Too many hops: pmtu 1280
		Resume: pmtu 1280
//} 

出力の読み方：
日本のサーバ〜NCOM@<fn>{NCOM}〜アメリカのComcast@<fn>{comcast}のルータ群を経由していることが分かる。
14番目のルータのドメイン名にはポートランドとある。
サンノゼもポートランドもデータセンター銀座である。
NCOMの海底ケーブルで太平洋を超え（10番目〜11番目）、
サンノゼで陸揚げし、アメリカ西海岸を北上して、ポートランドでcomcastのアメリカ内陸ネットワークに入ったことが読み取れる。






=== 知っていると便利なオプション: @<idx>{-n}




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
ドメイン名ではなくIPアドレスで表示されていることが分かる。


//note[-n][-nオプションの意義]{

ネットワーク系のコマンドは、
@<code>{@<term>{-n}}オプションをつけて実行することを心がけたい
（その手のコマンドには普通@<code>{-n}オプションがあるはず）。
なぜなら、
この手のコマンドを実行するのは障害対応時であり、
DNSも確認項目の一つだからだ。
DNS障害に引きづらずに
@<idx>{ネットワーク((ねっとわーく))<<>>の動作確認((のどうさかくにん))}をする必要がある。

//}



#@# 




=={traceroute} @<term>{traceroute}




宛先にパケットを送信し、宛先までに通過する各ルータのIPアドレスを記録する。記録されたIPアドレスによって、宛先のホストまでのネットワーク経路を可視化するために利用する。

歴史的には@<B>{traceroute}コマンドが初出で、
ほとんどのUnix/Linuxで利用できるのは@<B>{traceroute}コマンドである。
当然@<idx>{Debian}/GNU Linuxにも存在する（デフォルトでは入っていないかもしれないが、その時はapt install traceroute）。
ただし、
なぜか@<idx>{Ubuntu}には@<B>{traceroute}ではなく@<B>{tracepath}コマンドが入っているらしい@<fn>{vocareum-terminal}。

@<B>{traceroute}と@<B>{tracepath}の基本的な使い方は一緒なので、
詳細は@<B>{tracepath}@<secref>{tracepath}節を参照

//footnote[vocareum-terminal][少なくともAWS Academy(vocareum)の環境ではtracepathしか使えない]





=== 書式




//list[][][fontsize=xx-small]{
$ traceroute [options] DESTINATION
//}
 * DESTINATIONはホスト名かIPアドレス
 * @<B>{-n} オプションあり


//note[][Windowsでもネットワーク障害切り分けにpingとtracertが使える]{
Windowsのコマンドプロンプトでも@<B>{@<idx>{ping}}と@<B>{@<idx>{tracert}}コマンド(@<idx>{traceroute<<>>Windows版---((ういんどうずばん))})が利用できる。
ただしMicrosoftが再実装したものらしく、
オプションがUnixと異なるため注意が必要だ。
それでも非常時の障害きりわけには有効なので、
Windowsにもパチモノが搭載されていることを覚えておこう。
//}



#@# 




=={tree} @<term>{tree}





@<idx>{ファイルとディレクトリ((ふぁいるとでぃれくとり))<<>>をツリー状に表示する((をじゅきじょうにひょうじする))}。ファイルやディレクトリの整理状況を把握するために利用する。





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




ディレクトリのみをツリー状に出力する。





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
.sshなど.(ドット)から始まる隠しファイルや隠しディレクトリも表示されている。



#@# 




=={unzip} @<term>{unzip}




zipアーカイブ（ファイル）から、
アーカイブ内の@<idx>{ファイル((ふぁいる))<<>>を取り出す((をとりだす))}（解凍する）コマンド。
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




=={vi} @<term>{vi}




Linuxを含むUnixベースのOSで利用できるテキスト@<idx>{エディタ((えでぃた))}。
viは、キーボードのみの編集を前提にしたコマンドラインベースのエディタであり、
テキスト編集にはキーボードショートカットを使用する。





=== 書式




//list[][][fontsize=xx-small]{
$ vi [options] [file ...]
//}





=== 実行例







==== 実行例




//list[][][fontsize=xx-small]{
$ vi ファイル名
//}




==== 実行結果




 * ファイル名を指定して起動する
 * そのファイルが実行したディレクトリに無ければ、ファイルを新たに作成する
 * その後エディタ画面になる。コマンドモードである
    




=== コマンドモードと入力モード




viには@<B>{モード}という考え方があり、モードごとに挙動が異なる。
@<B>{コマンドモード}と@<B>{入力モード}の２つがある。
vi起動時のモードはコマンドモードになっている。

エディタとして期待される「文字を入力できる状態」が「入力モード」だ。
コマンドモードは、その他の制御を行うモードで、
Microsoft Wordでいえば画面上にある様々なボタン/リボンに対応する。





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

 * @<B>{変更があれば上書き保存}後に終了
 * @<B>{変更がないなら即終了}。
   変更を捨てたい場合は、次の@<code>{:q!}




===== :q!




@<B>{変更内容を保存せずに終了}する場合には@<code>{:q!}だけを入力する。




===== :w




「@<B>{上書き保存}」。
変更内容を保存したい場合に利用。エディタは終了しない。




===== :wq




「上書き保存」しつつ「終了」。
変更内容を保存して終了したい場合に入力。




==== コピー＆ペースト




コマンドモードで以下のコマンドを実行するとコピー及びペーストができる。

入力モードの場合には、マウスでコピー＆ペーストも可能だ。
マウスで文字列をドラックして選択し、右クリック後、
コピーを選択すると文字列のコピーができる。
同様に貼り付ける場合は、ペーストしたい位置にカーソルを移動後、
右クリックしてペーストを選択することで、文字列のペーストができる。




===== yy




カーソル位置の行をコピーする。




===== 数値 +yy




カーソル位置以下の数値分の行を一括でコピーする。




===== p,P




コピーした行をペーストする。
pであればカーソルの一つ下の行に、Pであればカーソルの一つ上の行にペーストする。





=== 実行例 （コマンドモードでの操作）




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
3 gorira
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

@<idx>{:<<>>で始めるコマンド((ではじめるこまんど))}は@<idx>{ex}コマンドを呼び出す呪文だ。
exとは何か？というとviの一つ前に開発されていた@<idx>{エディタ((えでぃた))}で、
実際のところviとexは同じプログラムへの異なるインターフェイスである。

こういう@<idx>{インターネット古代史((いんたーねっとこだいし))}は@<idx>{BSD}のマニュアルにはきちんと書いてあるが:-)、
vi(@<idx>{vim==>>vi})のマニュアルには書いていないようである
（少なくとも@<idx>{Debian}同梱のviには無い）。
まぁ古代史を知らなくとも困らないが、
我々の道具が何故このような形に落ち着いているのか興味ないだろうか？
（「わたし、気になります！」というIT古典部気質の人は、
@<idx>{エンジニア適性((えんじにあてきせい))}があると思う）

コンピュータ開発史についてはYAPC::Hakodateで少しだけ語っているので、
speakerdeckのスライドを参照してほしい（URLは脚注@<fn>{yapc-hakodate-2024}を参照）。
動画も近々Youtubeに上がると思う（まだ準備中らしい）。
//}

//footnote[yapc-hakodate-2024][@<href>{https://speakerdeck.com/fmlorg/sierutoperlnoshi-ifen-ke-souitutasi-kao-nodao-ju-ha-dokokaralai-te-dokoheyukunoka-v1-dot-1-0, YAPC::Hakodate 2024 "シェルとPerlの使い分け、 そういった思考の道具は、どこから来て、どこへゆくのか？"}]



#@# 




=={zip} @<term>{zip}




@<idx>{ファイル((ふぁいる))<<>>をzip形式でアーカイブ((をじっぷけいしきであーかいぶ))}するコマンド。
反対は@<code>{unzip}コマンド（@<secref>{unzip}も参照）




=== 書式




//list[][][fontsize=xx-small]{
$ zip [options] アーカイブファイル名 アーカイブしたいファイルの名前...
//}
「アーカイブしたいファイルの名前...」は可変長である。





=== 実行例




text1.txtとtext2.txtをexample.zipにアーカイブする。




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



#@# 広告ページ

==[notoc] 広告

深町およびITインフラ部が製作した技術同人誌（PDF）群は電子版を配布しています。
ものによっては印刷版も無料で配布しています（在庫かぎり）

 * 電子版の配布場所: @<href>{https://distribution.techbooks.fml.org/} 
 *  最新情報(github): @<href>{https://github.com/techbooks-fmlorg}

//blankline

2024年度刊行（技術監修あり）

 *   厳選Unixコマンド 第2版 (本書)
 **  2025/02/28 刊行、インフラ部の最新刊！
 **  公立千歳科学技術大学 IT インフラ部[著]、深町賢一[監修]
 *   ITインフラ演習環境 hands-on-base 0.3.0 の設計と実装
 **  技術: Unixコマンド(シェル)、docker-compose
 **  LPI Webinar@<fn>{lpi-2024-06-08}用に開発した環境です。
     これはインフラ部の成果物ではなく、作者は深町のみ。
     ただ、このシステムがインフラ部のシステムや研修の元ネタとして再利用されているので、ぜひ御一読を。
 **  企業の新人研修やインターンシップに最適と思います、どうでしょう？

//blankline

近刊予定(鋭意執筆中)

 *  冴えないPaaS(へろく)の育て方 by 深町
 ** 技術: HTML 1.1, CGI, Web API, Go言語, docker-compose
 ** PaaSの基本原理を学習する研究室兼インフラ部の研修用教材

//footnote[lpi-2024-06-08][2024-06-08: @<href>{https://lpic-2024q2.demo.fml.org/}]
