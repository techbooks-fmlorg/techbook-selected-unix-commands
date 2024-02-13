= 頭文字が l のコマンド

#@# 

== ls

デフォルトでは現在のディレクトリの中にあるファイルに関する情報をリストアップする。
-cftuvSUX または --sort のいずれも指定されていない場合は、検索結果をアルファベット順にソートして出力する。


===== 実行例 


//list[][][fontsize=xx-small]{
ls
//}



===== 実行結果 


//list[][][fontsize=xx-small]{
auto_create_md.py  ls.md  man.md  ping.md
//}


=== オプション一覧


  

==== -a もしくは --all



. から始まるファイル（ドットファイル）も表示する。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -a
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  .  ..  .git  auto_create_md.py  ls.md  man.md  ping.md
//}



==== -A もしくは --almost-all



どこのディレクトリにもあるドットファイルである、「.」および「..」をリストに含めないようにする。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -A
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  .git  auto_create_md.py  ls.md  man.md  ping.md
//}



==== --author



-l と併用することで各ファイルの作者を表示できる。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -l --author
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 36
  -rw-r--r-- 1 author user user  4519 Dec 23 15:10 auto_create_md.py
  -rw-rw-r-- 1 author user user 11692 Dec 23 15:10 ls.md
  -rw-rw-r-- 1 author user user 10558 Dec 10 03:49 man.md
  -rw-rw-r-- 1 author user user  1024 Dec 9 04:23 ping.md
//}


上の例でわかりやすく author としているところに作者のアカウント名が表示される。


==== --color[=WHEN]



ファイルの種類を区別するための出力の色をつけるかどうかを変更できるオプション。

オプションを付与した場合にのみ作用され、常に変更できるわけではない。常に変更する場合は LS_COLORS という環境変数により設定を変更できる。その設定には dircolors コマンドを使用する必要がある。（ここでは記載しない。）



デフォルトの ls では引数 (=WHEN) に always が渡された時と同じく、色がついている状態。以下の値を引数に取ることができる。

- always : デフォルトの挙動。色がつく。

- auto : 標準出力がターミナルに接続できている場合にのみ、色がつく。ssh などにより色がつかなくなっているのはこのオプションによるもの。

- never : 色がつかない。




===== 実行例 


//list[][][fontsize=xx-small]{
  ls --colors=never
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  auto_create_md.py  ls.md  man.md  ping.md
//}



この書式上、色が区別できる状態の実行結果を見せることはできないが、上記の実行例ではかならず何も着色されていない状態で出力される。


==== -f



ソートせず、-aU オプションを有効にし、-ls --color オプションを無効にした出力をするオプション。つまり、詳細情報ではない隠しファイルをふくむすべてのファイルを見つけた順で色なしで表示するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -f
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  ..  .  man.md  create_hoge_files.sh  ls.md  auto_create_md.py  ping.md
//}






==== --format=WORD



引数( WORD ) に以下の単語を渡すことで指定できる出力形式で、出力できるオプション。


- across(=-xオプション) : 行で出力する。

- commas(=-mオプション) : カンマ区切りで出力する。

- horizontal(=-xオプション) : 行で出力する。

- long(=-lオプション) : 詳細情報まで出力する。

- single-column(=-1オプション) : 1行につき1ファイルずつ出力する。

- verbose(=-lオプション) : 詳細情報まで出力する。

- vertical(=-Cオプション) : 詳細情報まで出力する。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls --format=across
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  各コマンドの出力先を参照。
//}







==== --group-directories-first



ディレクトリをファイルより先に表示するオプション。

--sort オプションと組み合わせて使用することもできるが、--sort=none もしくは -U と併用してしまうと先にディレクトリが表示されないようになってしまう。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls --group-directories-first
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // dir = ディレクトリ
  auto_create_md.py  create_hoge_files.sh  dir  ls.md  man.md  ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // dir = ディレクトリ
  dir  auto_create_md.py  create_hoge_files.sh  ls.md  man.md  ping.md
//}



==== --hide=PATTERN



シェルで利用できる正規表現を引数( =PATTERN )に渡すことで指定した正規表現にマッチするファイル名を表示しないで出力するオプション。-a オプションなどとの併用ではマッチしたものも表示されてしまう。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls --hide='*.md'
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  auto_create_md.py  create_hoge_files.sh  dir  ls.md  man.md  ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  auto_create_md.py  create_hoge_files.sh  dir
//}



==== -l



ファイル(ディレクトリ)の詳細情報を表示するオプション。


total にはディレクトリ内のすべてのファイルの*ブロック数の合計が出力される。



（* ブロック : ディスク上の容量のひとまとまりの単位のこと。通常1ブロックは 512 もしくは 1024バイト）



左から、ファイル(ディレクトリ)のパーミッション、そのファイルに対する*ハードリンクの数、ファイルの所有者、所属グループ、ファイルサイズ、最終変更時刻、ファイル(ディレクトリ)名が表示される。



(* ハードリンク : 同一のファイルに対する別名のこと。ハードリンク同士で同じデータブロックを共有するため、どちらかの変更が他方にも反映される。)



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -l
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  -rw-r--r-- 1 user user  4519 Dec 25 15:10 auto_create_md.py
  -rwxrwxr-x 1 user user    63 Dec 26 01:27 create_hoge_files.sh
  drwxrwxr-x 2 user user  4096 Dec 28 00:20 dir
  -rw-rw-r-- 1 user user 11692 Dec 25 15:10 ls.md
  -rw-rw-r-- 1 user user 10558 Dec 11 03:49 man.md
  -rw-rw-r-- 1 user user  1024 Dec 11 04:23 ping.md
//}



==== -p もしくは --indicator-style=slash



ディレクトリ名の末尾に / が追加されて表示されるオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -p
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // dir は ディレクトリ
  auto_create_md.py  create_hoge_files.sh  dir/  ls.md  man.md  ping.md
//}



==== -Q もしくは --quote-name



表示されるファイル(ディレクトリ)名がダブルクォーテーションで囲まれて出力されるオプション。

ファイル(ディレクトリ)名にスペースや特殊文字が含まれているときに使用することが多い。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -Q
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   auto_create_md.py      dir     man.md               ping.md
  create_hoge_files.sh   ls.md  'one'$'\n''two.txt'
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  "auto_create_md.py"     "dir"    "man.md"        "ping.md"
  "create_hoge_files.sh"  "ls.md"  "one\ntwo.txt"
//}



==== -r もしくは --reverse



ファイル(ディレクトリ)のソートの順番を逆にするオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -r
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   auto_create_md.py      dir     man.md               ping.mdcreate_hoge_files.sh   ls.md  'one'$'\n''two.txt'
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  ping.md              man.md   dir                    auto_create_md.py
  'one'$'\n''two.txt'   ls.md    create_hoge_files.sh
//}



==== -R もしくは --recursive



*サブディレクトリの中身まで再帰的に表示するオプション。


(* サブディレクトリ : 現在のディレクトリの下に存在するディレクトリのこと)



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -R
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // dir ディレクトリの中
  user@localhost:~/dir$ ls
  hoge-hoge.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // dirディレクトリの上の階層のディレクトリの中
  user@localhost:~$ ls -R
  .:
  auto_create_md.py      dir     man.md               ping.md
  create_hoge_files.sh   ls.md  'one'$'\n''two.txt'

  ./dir:
  hoge-hoge.txt
//}



上記例では *カレントディレクトリは . として表示されている。


(* カレントディレクトリ : 現在のディレクトリのこと)


==== -S



ファイルサイズの大きい順にソートして表示されるオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -S
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 52
  drwxrwxr-x  3 user user  4096 Dec 28 01:52  ./
  drwxr-x--- 15 user user  4096 Dec 26 03:48  ../
  -rw-r--r--  1 user user  4519 Dec 25 15:10  auto_create_md.py
  -rwxrwxr-x  1 user user    63 Dec 26 01:27  create_hoge_files.sh*
  drwxrwxr-x  2 user user  4096 Dec 28 02:11  dir/
  -rw-rw-r--  1 user user 11692 Dec 25 15:10  ls.md
  -rw-rw-r--  1 user user 10558 Dec 11 03:49  man.md
  -rw-rw-r--  1 user user     0 Dec 28 01:52 'one'$'\n''two.txt'
  -rw-rw-r--  1 user user  1024 Dec 11 04:23  ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // 横でソートされているのを確認するために
  // ls -Sx としている

  ls.md                  man.md               auto_create_md.py   dir   ping.md
  create_hoge_files.sh  'one'$'\n''two.txt'
//}



上記の ls -l の例から ls.md, man.md, auto_create_md.py, ... の順にファイルサイズが大きいことが確認でき、ls -Sx の例からその順でソートされて出力されていることが確認できる。


==== --sort=WORD



出力を引数( =WORD )にて指定した方法でソートするオプション。WORD には以下の単語を指定できる。


- none (= -Uオプション) : ソートしない。ファイルが見つかった順。

- size (= -Sオプション) : ファイルサイズが大きい順。

- time (= -tオプション) : 更新時刻順。

- versino (= -vオプション) : バージョン番号順。

- extension (= -Xオプション) : 拡張子順。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls --sort=none
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  -rw-r--r-- 1 user user  4519 Dec 25 15:10  auto_create_md.py
  -rwxrwxr-x 1 user user    63 Dec 26 01:27  create_hoge_files.sh
  drwxrwxr-x 2 user user  4096 Dec 28 02:11  dir
  -rw-rw-r-- 1 user user 11692 Dec 25 15:10  ls.md
  -rw-rw-r-- 1 user user 10558 Dec 11 03:49  man.md
  -rw-rw-r-- 1 user user     0 Dec 28 01:52 'one'$'\n''two.txt'
  -rw-rw-r-- 1 user user  1024 Dec 11 04:23  ping.md
//}



以下のソートではソートの結果を行で確認するため、-x オプションを使用している。



===== 実行結果 


//list[][][fontsize=xx-small]{
   dir     man.md              create_hoge_files.sh  'one'$'\n''two.txt'
   ls.md   auto_create_md.py   ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   ls.md                  man.md               auto_create_md.py   dir   ping.md
   create_hoge_files.sh  'one'$'\n''two.txt'
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   dir                'one'$'\n''two.txt'   create_hoge_files.sh   ls.md
   auto_create_md.py   ping.md              man.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   auto_create_md.py    create_hoge_files.sh   dir   ls.md   man.md
   'one'$'\n''two.txt'   ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   dir                    ls.md                man.md   ping.md   auto_create_md.py
   create_hoge_files.sh  'one'$'\n''two.txt'
//}



==== -u



ファイル (ディレクトリ) のアクセス時刻 (atime) に基づいてソートする際の動作を指定するオプション。

しばしば、-lt オプションや -l オプションなどと併用される。


  - -lt オプションと併用 : ファイルの詳細情報がアクセス時刻 (atime) が新しい順で表示される。

  - -l オプションと併用 : ファイルの詳細情報がファイル名のアルファベット順でアクセス時刻 (atime) とともに表示される。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -ltu
  ls -lu
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  drwxrwxr-x 2 user user  4096 Dec 28 02:11  dir
  -rw-rw-r-- 1 user user     0 Dec 28 01:52 'one'$'\n''two.txt'
  -rw-rw-r-- 1 user user 11692 Dec 27 22:45  ls.md
  -rwxrwxr-x 1 user user    63 Dec 26 01:27  create_hoge_files.sh
  -rw-r--r-- 1 user user  4519 Dec 25 15:10  auto_create_md.py
  -rw-rw-r-- 1 user user 10558 Dec 11 23:42  man.md
  -rw-rw-r-- 1 user user  1024 Dec 11 04:23  ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  -rw-r--r-- 1 user user  4519 Dec 25 15:10  auto_create_md.py
  -rwxrwxr-x 1 user user    63 Dec 26 01:27  create_hoge_files.sh
  drwxrwxr-x 2 user user  4096 Dec 28 02:11  dir
  -rw-rw-r-- 1 user user 11692 Dec 27 22:45  ls.md
  -rw-rw-r-- 1 user user 10558 Dec 11 23:42  man.md
  -rw-rw-r-- 1 user user     0 Dec 28 01:52 'one'$'\n''two.txt'
  -rw-rw-r-- 1 user user  1024 Dec 11 04:23  ping.md
//}



==== -U



ファイル (ディレクトリ) 名をソートせずに表示するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  ls -U
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
   auto_create_md.py      dir     man.md               ping.md
   create_hoge_files.sh   ls.md  'one'$'\n''two.txt'
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
   dir      create_hoge_files.sh   ls.md               ping.md
   man.md  'one'$'\n''two.txt'     auto_create_md.py
//}



==== -v



ファイル (ディレクトリ) 名の数字が自然な順序で表示するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  ls -v
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
   auto_create_md.py    create_hoge_files.sh   dir   hoge10.txt   hoge1.txt   hoge2.txt   ls.md   man.md
   'one'$'\n''two.txt'   ping.md
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
   auto_create_md.py    create_hoge_files.sh   dir   hoge1.txt   hoge2.txt   hoge10.txt   ls.md   man.md
  'one'$'\n''two.txt'   ping.md
//}



上記例からこのオプションを使用すると、hoge10.txt の位置が hoge2.txt の後に来ることがわかる。


==== -w もしくは --width=COLS



出力幅 (横の文字数) を引数( COLS )にて指定できるオプション。0 を渡すと、制限なしと解釈される。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -w 50
  もしくは
  ls --width=50
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   auto_create_md.py      hoge2.txt
   create_hoge_files.sh   ls.md
   dir                    man.md
   hoge10.txt            'one'$'\n''two.txt'
   hoge1.txt              ping.md
//}



==== -x



ファイル (ディレクトリ) 名を行ごとに表示するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -x
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   auto_create_md.py      dir          hoge1.txt   ls.md   'one'$'\n''two.txt'
   create_hoge_files.sh   hoge10.txt   hoge2.txt   man.md   ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
   auto_create_md.py   create_hoge_files.sh   dir      hoge10.txt           hoge1.txt
   hoge2.txt           ls.md                  man.md  'one'$'\n''two.txt'   ping.md
//}



==== -X



ファイルの拡張子のアルファベット順でソートして表示するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -X
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // 容易のため ls -xX で実行

   dir                    ls.md        man.md      ping.md     auto_create_md.py
   create_hoge_files.sh   hoge10.txt   hoge1.txt   hoge2.txt  'one'$'\n''two.txt'
//}



==== -1



1行に1ファイル (ディレクトリ) のみ表示するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -1
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  auto_create_md.py
  create_hoge_files.sh
  dir
  hoge10.txt
  hoge1.txt
  hoge2.txt
  ls.md
  man.md
  'one'$'\n''two.txt'
  ping.md
//}


==== -b もしくは --escape



C言語の形式で非表示文字（エスケープシーケンス）を表示する。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -b
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // 比較のために改行をわかりやすくしている
  auto_create_md.py
  ls.md
  man.md
  one                       // ここが改行されている
  two.txt
  ping.md
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  auto_create_md.py  ls.md  man.md  one\ntwo.txt  ping.md
//}




==== --block-size=SIZE



SIZE の部分を変更することで -l オプションを使用したときに確認できる、ファイルのバイトサイズを任意のオーダーで確認できるようになる。

引数として利用できるのはSI接頭辞と整数の掛け合わせ(例：10K = 10 * 1024)の形式に限られる。



- ここで使えるSI接頭辞は @<strong>{キロ(K/k)、メガ(M/m)、ギガ(G/g)、テラ(T/t)、ペタ(P/p)、エクサ(E/e)、ゼタ(Z/z)、ヨタ(Y/y)} であり、それぞれそのまま使用すると、2の10乗である 1024 の倍数として利用できる(例：G = 1024 * 1024 * 1024)。

- 直後にBをつけることで、10の累乗による概念のSI接頭辞として利用できる(例：G = 10^9)。

- バイナリ接頭辞も利用することができ、 キロ に相当するのが KiB(キビバイト), メガ に相当するのが MiB(メビバイト) などのように使用できる。




===== 実行例 


//list[][][fontsize=xx-small]{
  ls -l --block-size=K
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 36
  -rw-r--r-- 1 user user  4519 Dec 25 15:10   auto_create_md.py
  -rw-rw-r-- 1 user user 11692 Dec 25 15:10 ls.md
  -rw-rw-r-- 1 user user 10558 Dec 11 03:49 man.md
  -rw-rw-r-- 1 user user  1024 Dec 11 04:23 ping.md
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  total 36K
  -rw-r--r-- 1 user user  5K Dec 25 15:10 auto_create_md.py
  -rw-rw-r-- 1 user user 12K Dec 25 15:10 ls.md
  -rw-rw-r-- 1 user user 11K Dec 11 03:49 man.md
  -rw-rw-r-- 1 user user  1K Dec 11 04:23 ping.md
//}



上記のように指定したオーダー表記にするために切り上げ処理が施される。


==== -B もしくは --ignore-backups



「~」で終わるファイル(バックアップファイル)を表示しない。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -B
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  auto_create_md.py  hoge.txt  hoge.txt~  ls.md  man.md  ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  auto_create_md.py  hoge.txt  ls.md  man.md  ping.md
//}



==== -c



-lt オプションと併用すると、 @<strong>{ctime} (ファイルステータス情報の最終変更時刻) に基づいてファイルを最新のものからソートして表示する。



-l オプションと併用すると、**ctime** を含むファイルの詳細情報をファイル名ソートして表示する。


単独で使用すると、**ctime** でソートして表示する。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -ltc
  ls -lc
  ls -c
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // ファイルの最終変更時刻順
  total 40
  -rw-rw-r-- 1 user user     9 Dec 26 01:05 hoge.txt
  -rw-rw-r-- 1 user user 11692 Dec 25 15:10 ls.md
  -rw-r--r-- 1 user user  4519 Dec 25 15:10 auto_create_md.py
  -rw-rw-r-- 1 user user  1024 Dec 11 23:42 ping.md
  -rw-rw-r-- 1 user user 10558 Dec 11 23:42 man.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // ファイルの名前順
  total 40
  -rw-r--r-- 1 user user  4519 Dec 25 15:10 auto_create_md.py
  -rw-rw-r-- 1 user user     9 Dec 26 01:05 hoge.txt
  -rw-rw-r-- 1 user user 11692 Dec 25 15:10 ls.md
  -rw-rw-r-- 1 user user 10558 Dec 11 23:42 man.md
  -rw-rw-r-- 1 user user  1024 Dec 11 23:42 ping.md
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // ファイルの最終変更時刻順
  hoge.txt  ls.md  auto_create_md.py  ping.md  man.md
//}




==== -C



出力を列にするオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -C
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  なんか全く変わらないんで,消す候補です
//}



==== -d もしくは --directory



ディレクトリの内容ではなく、ディレクトリそのものをリストアップする



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -d ~/directory
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  /home/user/directory
//}



==== -D もしくは --dired



Emacsのdiredモード用にデザインされた出力を生成する。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -F もしくは --classify


エントリに対して特定のマーク（インディケータ）を追加します。各マークはエントリの種類を示し、ファイルがディレクトリであるか、実行可能であるか、シンボリックリンクであるかなどを示します。


以下は、使用可能なマークとその意味です：


- /: ディレクトリ

- *: 実行可能なファイル

- =: ソケットファイル

- \>: ファイルがスパーシャルブロックデバイス\

- |: ファイルがパイプ（FIFO）ファイル

- @: シンボリックリンク



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --file-type



-f と同様にインジケータをつけるものの、ファイルを示す'*'だけ付けないオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --full-time



-lオプションと同様に詳細な情報を表示します。また、--time-style=full-isoオプションも適用され、時刻の表示が完全なISO 8601形式で行われます。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls --full-time
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 40
  -rw-r--r-- 1 user user  4519 2023-12-25 15:10:17.029008035 +0900 auto_create_md.py
  -rwxrwxr-x 1 user user    63 2023-12-26 01:27:26.133960460 +0900 create_hoge_files.sh
  -rw-rw-r-- 1 user user 11692 2023-12-25 15:10:20.957091058 +0900 ls.md
  -rw-rw-r-- 1 user user 10558 2023-12-11 03:49:33.924170811 +0900 man.md
  -rw-rw-r-- 1 user user  1024 2023-12-11 04:23:17.953652140 +0900 ping.md
//}



==== -g



-l オプションと同様に詳細情報を表示するが、ファイルの所有者の情報のみ表示しないで出力するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -g
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 40
  -rw-r--r-- 1 user  4519 Dec 25 15:10 auto_create_md.py
  -rwxrwxr-x 1 user    63 Dec 26 01:27 create_hoge_files.sh
  -rw-rw-r-- 1 user 11692 Dec 25 15:10 ls.md
  -rw-rw-r-- 1 user 10558 Dec 11 03:49 man.md
  -rw-rw-r-- 1 user  1024 Dec 11 04:23 ping.md
//}



==== -G もしくは --no-group



長いリストでは、グループ名を印刷しない



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -h もしくは --human-readable



-l オプションや -s オプションと組み合わせて使用されます。このオプションを使用すると、ファイルやディレクトリのサイズが人間が理解しやすい形式で表示されます。サイズが大きい場合にはキロバイト（K）、メガバイト（M）、ギガバイト（G）などの単位が適切に変換されて表示されます。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -lh
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44K
  -rw-r--r-- 1 user user 4.5K Dec 25 15:10 auto_create_md.py
  -rwxrwxr-x 1 user user   63 Dec 26 01:27 create_hoge_files.sh
  drwxrwxr-x 2 user user 4.0K Dec 28 00:20 dir
  -rw-rw-r-- 1 user user  12K Dec 25 15:10 ls.md
  -rw-rw-r-- 1 user user  11K Dec 11 03:49 man.md
  -rw-rw-r-- 1 user user 1.0K Dec 11 04:23 ping.md
//}



==== --si



-l オプションや -s オプションと組み合わせて使用されます。このオプションを使用すると、ファイルやディレクトリのサイズが2のべき乗ではなく、10のべき乗で表現され、キロ（K）、メガ（M）、ギガ（G）などの単位が使われます。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -l --si
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 46k
  -rw-r--r-- 1 shuuto shuuto 4.6k Dec 25 15:10 auto_create_md.py
  -rwxrwxr-x 1 shuuto shuuto   63 Dec 26 01:27 create_hoge_files.sh
  drwxrwxr-x 2 shuuto shuuto 4.1k Dec 28 00:20 dir
  -rw-rw-r-- 1 shuuto shuuto  12k Dec 25 15:10 ls.md
  -rw-rw-r-- 1 shuuto shuuto  11k Dec 11 03:49 man.md
  -rw-rw-r-- 1 shuuto shuuto 1.1k Dec 11 04:23 ping.md
//}



==== -H もしくは --dereference-command-line



コマンドラインに記載されているシンボリックリンクをたどる



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --dereference-command-line-symlink-to-dir



コマンドラインのシンボリックリンクディレクトリを指す



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --hyperlink[=WHEN]



ファイル名をハイパーリンクとして表示します。=WHENはオプションで、次のいずれかの値を取ります：


- always: 常にハイパーリンクとして表示する（デフォルト値）。

- auto: 標準出力が端末に接続されている場合のみ、ハイパーリンクとして表示する。

- never: ハイパーリンクとして表示しない。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --indicator-style=WORD



エントリ名にスタイル付きのインディケータを追加します。WORDには以下のいずれかの値を指定できます：


- none: インディケータなし（デフォルト値）。

- -p: ディレクトリにはスラッシュ(/)、実行可能なファイルにはアスタリスク(*)など、エントリの種類に合わせたインディケータが表示されます。

- --file-type: --classifyオプションと同様に、エントリの種類に応じたインディケータが表示されます。

- -F: --classifyオプションと同じく、エントリの種類に応じたインディケータが表示されます。




===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -i もしくは --inode



各ファイルのインデックス番号（inode番号）を表示するオプション。インデックス番号とは、ファイルやディレクトリがファイルシステム内で一意に識別されるための番号のこと。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -i
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  1973241 auto_create_md.py     1969394 dir    1973352 man.md
  1994807 create_hoge_files.sh  1994891 ls.md  1973372 ping.md
//}



==== -I もしくは --ignore=PATTERN



シェルで利用できる正規表現を引数( =PATTERN )に渡すことで指定した正規表現にマッチするファイル名を表示しないで出力するオプション。-a オプションなどとの併用でもマッチしたものが表示されない。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -aI '*.md'
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  .  ..  auto_create_md.py  create_hoge_files.sh  dir
//}



==== -k もしくは --kibibytes



-s オプションとの併用でのみ使用でき、ディスク使用量を1024バイト(1キビバイト)単位で表示するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -sk
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  8 auto_create_md.py      4 dir    12 man.md
  4 create_hoge_files.sh  12 ls.md   4 ping.md
//}



==== -L もしくは --dereference



シンボリックリンクのファイル情報を表示する場合は、リンクの情報を表示します。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -n もしくは --numeric-uid-gid



-l オプションのように詳細情報を表示するが、所有者を数値のユーザーIDで、所有グループをグループIDで表示する。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -n
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  -rw-r--r-- 1 1000 1000  4519 Dec 25 15:10 auto_create_md.py
  -rwxrwxr-x 1 1000 1000    63 Dec 26 01:27 create_hoge_files.sh
  drwxrwxr-x 2 1000 1000  4096 Dec 28 00:20 dir
  -rw-rw-r-- 1 1000 1000 11692 Dec 25 15:10 ls.md
  -rw-rw-r-- 1 1000 1000 10558 Dec 11 03:49 man.md
  -rw-rw-r-- 1 1000 1000  1024 Dec 11 04:23 ping.md
//}



==== -N もしくは --literal



特殊文字やスペースがファイル名に存在している時でもクォーテーションを使用しないで表示するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -N
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // ' one'$'\n''two.txt' はファイル名に改行が入っている
   auto_create_md.py      dir     man.md                ping.md
   create_hoge_files.sh   ls.md  ' one'$'\n''two.txt'
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // one?two.txt という表示になった
  auto_create_md.py     dir    man.md        ping.md
  create_hoge_files.sh  ls.md   one?two.txt
//}



==== -o



-l オプションと同様に詳細なリスト形式でエントリを表示しますが、グループ情報を表示しません。通常、-l オプションを使用すると、エントリごとに所有者とグループが表示されますが、-o オプションを追加することでグループ情報を省略できます。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -o
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  -rw-r--r-- 1 user  4519 Dec 25 15:10 auto_create_md.py
  -rwxrwxr-x 1 user    63 Dec 26 01:27 create_hoge_files.sh
  drwxrwxr-x 2 user  4096 Dec 28 00:20 dir
  -rw-rw-r-- 1 user 11692 Dec 25 15:10 ls.md
  -rw-rw-r-- 1 user 10558 Dec 11 03:49 man.md
  -rw-rw-r-- 1 user  1024 Dec 11 04:23 ping.md
//}



==== -q もしくは --hide-control-chars



制御文字などの特殊文字が表示される時に ? で置換されて表示されるオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --show-control-chars



制御文字などの特殊文字をそのまま表示するオプション。標準出力がターミナルに接続されている時は ls コマンドは特殊文字を表示するようになっているため、 ssh 接続時などで利用することが多い。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --quoting-style=WORD



ファイル(ディレクトリ)名の引用スタイルを指定する。引数( =WORD )には以下の単語を指定できる。


- literal : ファイル(ディレクトリ)名をそのまま表示する。

- locale : ロケールに基づいたスタイルで表示する。

- shell : シェルの解釈可能なスタイルで表示する。

- shell-always : シェルの解釈可能なスタイルかつ、特殊文字が含まれていなくても引用符で囲まれて表示する。

- shell-escape : シェルの解釈可能なスタイルで、特殊文字をエスケープして表示する。

- shell-escape-always : シェルの解釈可能なスタイルで、特殊文字をエスケープして、特殊文字が含まれていなくても引用符で囲まれて表示する。

- c : プログラムで利用可能なスタイルで表示する。

- escape : 特殊文字をエスケープして表示する。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -s もしくは --size



各ファイルの割り当てられたサイズをブロック単位で表示するオプション。(ファイルサイズは通常はバイト単位で表示される。)



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -s
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  total 44
  8  auto_create_md.py      4  dir    12  man.md               4  ping.md
  4  create_hoge_files.sh  12  ls.md   0 'one'$'\n''two.txt'
//}



==== --time=WORD



ファイルのタイムスタンプに関する表示やソートの方法を引数( =WORD )にて指定し出力するオプション。WORD には以下の単語を指定できる。


- atime, access, use : ファイルのアクセス時刻 (atime) を表示またはソートする。

- ctime, status : ファイルの変更時刻 (ctime) を表示またはソートする。

- birth, creation : ファイルの作成時刻 (birth time) を表示またはソートする。




===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== --time-style=TIME_STYLE



-lオプションと併用することで、表示されるファイルの最終変更時刻のスタイルを変更できるオプション。引数( TIME_STYLE )には次のスタイルが適用できる。


- full-iso : 完全なISO 8601 



  例) '2023-12-25 10:00:00.000000000 +0000'

- long-iso : 長いISO 8601 



  例) '2023-12-25 10:00'

- iso : ISO 8601



  例) '2023-12-25'

- locale : ロケールに基づいた日時のスタイル

- +FORMAT : date(1)コマンドのスタイルで指定したカスタムフォーマット



  例) '+%Y-%m-%d %H:%M:%S'


TIME_STYLE 環境変数を設定することでデフォルトのスタイルを指定することもできる。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -t



ファイル(ディレクトリ)名を時間が新しい順でソートして表示する。

ls --sort=timeと全く同じ。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -T もしくは --tabsize=COLS



タブ文字のサイズを変更できるオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}



==== -Z もしくは --context



各ファイルのセキュリティコンテキストを表示するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  ls -Z
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  実行結果
//}

