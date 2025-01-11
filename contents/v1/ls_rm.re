
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

