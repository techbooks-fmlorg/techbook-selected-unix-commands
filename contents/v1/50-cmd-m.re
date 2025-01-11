= 頭文字が m のコマンド

#@# 

== man-recode

マニュアルページ（ manページ ）を別のエンコーディングに変換するためのユーティリティ。
ファイル名から各ページに対して適切な入力エンコーディングを推測して変換することもある。これは、レガシーな文字コードが使用されているマニュアルページの多くを共通のエンコード方法（ 一般に UTF-8 ）で変換する場合で有用である。このプログラムは各ページに対してman --recode や manconv を実行するよりもはるかに高速である。

マニュアルページの最初の行で以下のようなエンコーディング宣言が見つかると、その宣言が入力エンコーディングとして使われる。そうでない場合は、入力エンコーディングはファイル名から推測される。

マニュアルページの先頭に書かれるエンコーディング宣言は通常は以下の形式をとる：

//list[][][fontsize=xx-small]{
'\"-*- coding: UTF-8 -*-
//}


\**マニュアルページプリプロセッサ* も宣言する場合：

//list[][][fontsize=xx-small]{
'\" t -*- coding：ISO-8859-1 -*-
//}


(\* マニュアルページプリプロセッサ : マニュアルページ（manページ）の作成や処理を補助するためのツールやプログラムのこと。ソースコードを構造化された形式に変換し、適切なマークアップやフォーマットを適用する役割を果たす。)

上記のエンコーディング宣言を変換したいマニュアルページの冒頭に書き加えたのち、man-recode コマンドを実行することでエンコーディング方法を変更してマニュアルページを作成できる。


===== 実行例 

//list[][][fontsize=xx-small]{
man-recode -t shift_jis --in-place touch.1.gz
//}



===== 実行結果 

//list[][][fontsize=xx-small]{
// 変更前 touch.1.gz(UTF-8) 
// user@localhost:/usr/share/man/man1$ man ./touch.1.gz

TOUCH(1)                         User Commands                        TOUCH(1)

NAME
       touch - change file timestamps

SYNOPSIS
       touch [OPTION]... FILE...

DESCRIPTION
       Update  the  access  and modification times of each FILE to the current
       time.

       A FILE argument that does not exist is created empty, unless -c  or  -h
       is supplied.

       A  FILE  argument  string of - is handled specially and causes touch to
       change the times of the file associated with standard output.

       Mandatory arguments to long options are  mandatory  for  short  options
       too.

       -a     change only the access time

       -c, --no-create
              do not create any files
... 
//}

以上のように正常なマニュアルページが表示される


===== 実行結果 

//list[][][fontsize=xx-small]{
// 変更前 touch.1.gz(shift-jis) 
// user@localhost:~/man-recode$ man ./touch.1.gz

^B^C�Vmo�6��_q󗥘�$N�u�Z���mb��"��(��D�"eG��;�/�
tb�’����1
��"|�Gx^Fat����:�\[uFFFD]UU����y����^CĦ��S��w�%   ����h’��
\[uFFFD]�dp?                          ���^L��gB�%�*��T!�Ei���q2�‐Ƌ
|?xZ��ew:�����l�Ο�0^DR",B    kG���^F!&?H�.....�$�)�E��q�J:a��^L��,x(��L��ci‐
j%P�D�*|��^D���^Dy��X#��Jj�7B67��E����       ^G�A}m�e(q%��(]ӅZ��y�~\[uFFFD]Ƙ��2<^Dx��e�+��؉u��k�+����I��m)c%��bQ[�÷<U+0099>�m^E�ϐ�a�A]�q�\[uFFFD].Є�0�+k��’�3��](drC�p�����b^?/��lf*���!��^B�WP�m‘Fc�G}�
7�L]_��6(�~b��^�
���A79�M��{��"��’7^L�����%@,(l��N���u����O�Z#;�7^Gy��^Da�^?:�E���y�٦X�\[u0150]+���%���J^Bn�   F�ֹ�^B�6x��|1R����@:�F���Q�ŏz�B�W�i’��5S^C�����E�O���hp?cOOWWϏ�����a��Sh��ϭ�<��2�}TG4‘��H3��^Gt���.�^EA�.�^C��V���ٗ�^C~wj\[uFFFD]��l�G
\[uFFFD]                                                        i
3��‐s��z���������bCH��Z.�^C�V�^G^Hv4����N8�xO^G�t(�y�^CL��V_T������
�d����3��W)K�^D�I�+Qf�N�~�PFK���%�Pr�.޷�‘5�C0��ܹ���}�4O�
i�Q�YXr��:�Zw��’����u�.~��.�o{pz���C��Ї���)��}���H‐_DY]�D4�‘p�
�[��P;�)(��     S^E㈩�88Y���#�������ҙ�[)�v1��7~,w��ћ�F�Xa�)�w�.��5�y,�J���G;��*E٫b��ɐ�q�����D�P
��^F�j�3�A�V5�����ݺ�oX^E�D��                   ��^Ce��N�#�r������5�W
5������q�T......�1���n0���?K�]����O^C�^B��"q>�M�����͢�~��D7�T�ʜ+m��l�݆k]��Z�Y��‐�����ه
U�\[uFFFD]��h^B�Jh�{z��5������ee�ƙ�vq>d     c������(�2eS�u�‘yz[��5A|�F......צ��ƺ0�qܩXj�7����o}����=�/       ��_b�v��^מ��<�\[uFFFD]^?^H9��J�$׻^B�15/pc���jS^DD.....mŐh�7��d
_^F��‘=vw%dM�RV^E���ض[�F0�[L;�5��5j�w��]���P9O����^D�(��\[uFFFD]�o’{�7�H���^G���v�A

 Manual page touch.1.gz line 1/19 (END) (press h for help or q to quit)
//}

以上のように文字化けが発生してしまう。



=== オプション一覧



==== -t もしくは --to-code=CODE



出力のエンコーディング方法を指定するオプション。この指定は必須であるため、忘れるとコマンドが実行できない。


上で既に実行例を出しているため実行例は省略する。


==== -d もしくは --debug



デバッグ情報を出すオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  man-recode -d -t shift_jis --in-place touch.1.gz
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  loading seccomp filter (permissive: 0)
  guessed input encoding UTF-8 for touch.1.gz
  loading seccomp filter (permissive: 0)
  seccomp already enabled
  trying encoding UTF-8 -> shift_jis\/\/IGNORE
  stem: touch.1, basename: touch.1.gz
//}



この場合は、UTF-8 でエンコーディングされることが予想されるファイルであり、そのファイルを無理やり shift_jis でエンコーディングしようとしたことが読み取れる。


\/\/IGNORE は変換できない文字をそのままにしておくオプションであるらしい。


==== --in-place



入力ファイルをその場で上書きするオプション。圧縮拡張子が削除される。



上で既に実行例を出しているため実行例は省略する。


==== --suffix=SUFFIX



出力ファイル名に付加する接尾辞を引数（ SUFFIX ）として指定することで、その接尾辞でファイルを作成するオプション。



===== 実行例 


//list[][][fontsize=xx-small]{
  man-recode -t shift_jis --suffix=".txt" touch.1.gz
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  // 実行前
  // touchコマンドのマニュアルページのみが存在することを確認
  user@localhost:~/man-recode$ ls
  touch.1.gz

  // 実行後
  // touch.1.txt が存在することを確認
  user@localhost:~/man-recode$ ls
  touch.1.gz  touch.1.txt
//}


==== -q もしくは --quiet



ページを変換できない場合にエラーメッセージを表示しないようにするオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  実行結果
//}

#@# 

== manpath

マニュアルページの検索パス（ manpath ）を決定、表示するための \**ユーティリティ* 。

（\* ユーティリティ : コンピュータの分析、構成、最適化、保守のためのソフトウェアの総称。ユーティリティソフトウェアとも呼ばれる。）

環境変数 $MANPATH が設定されている場合、manpath はその内容を表示して警告を発する。
もし設定されていなければ、 manpath は適切なマニュアルページの階層検索パスを決定し、その結果を表示する。

パスはコロンで区切られ、/etc/manpath.config（ man-dbの設定ファイル ）およびユーザーの環境から取得された情報を使用して決定される。


===== 実行例 

//list[][][fontsize=xx-small]{
manpath
//}



===== 実行結果 

//list[][][fontsize=xx-small]{
/usr/local/man:/usr/local/share/man:/usr/share/man/cat1:/usr/share/man
//}



=== オプション一覧


  

==== -c もしくは --catpath



manpath が決定された後、各パス要素を相対的な catpath に変換するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  manpath -c
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  /var/cache/man/oldlocal:/var/cache/man/local:/usr/share/man/cat1:/var/cache/man
//}



余談だが、/etc/manpath.config という設定ファイルの中に次のような記述がある。



//list[][][fontsize=xx-small]{
  #         *MANPATH*      ->	    *CATPATH*
  #
  MANDB_MAP	/usr/man		          /var/cache/man/fsstnd
  MANDB_MAP	/usr/share/man		    /var/cache/man
  MANDB_MAP	/usr/local/man		    /var/cache/man/oldlocal
  MANDB_MAP	/usr/local/share/man	/var/cache/man/local
  MANDB_MAP	/usr/X11R6/man		    /var/cache/man/X11R6
  MANDB_MAP	/opt/man		          /var/cache/man/opt
  MANDB_MAP	/snap/man		          /var/cache/man/snap
//}



ここのコンフィグファイルに書かれているマッピングをもとに変換されることが最初に例示した実行例と上記の実行例からわかる。


==== -C FILE もしくは --config-file=FILE



このユーザー設定ファイルを使用し、デフォルトの ~/.manpath ではない manpath を決定するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  manpath -C hoge.conf
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  // hoge.conf というコンフィグファイルを用意
  user@localhost:~/manpath$ ls
  hoge.conf

  // 内容は次のとおり
  MANDATORY_MANPATH  /etc

  // 実行結果
  /usr/local/man:/usr/local/share/man:/usr/share/man/cat1:/usr/share/man:/etc
//}



/etc ディレクトリが追加されていることがわかる。


==== -d もしくは --debug



デバッグ情報を表示するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  manpath -d
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  From the config file /etc/manpath.config:
  Mandatory mandir `/usr/man'.
  Mandatory mandir `/usr/share/man'.
  Mandatory mandir `/usr/local/share/man'.
  Path `/bin' mapped to mandir `/usr/share/man'.
  Path `/usr/bin' mapped to mandir `/usr/share/man'.
  Path `/sbin' mapped to mandir `/usr/share/man'.
  Path `/usr/sbin' mapped to mandir `/usr/share/man'.
  Path `/usr/local/bin' mapped to mandir `/usr/local/man'.
  Path `/usr/local/bin' mapped to mandir `/usr/local/share/man'.
  Path `/usr/local/bin' mapped to mandir `/usr/share/man/cat1'.
  Path `/usr/local/sbin' mapped to mandir `/usr/local/man'.
  Path `/usr/local/sbin' mapped to mandir `/usr/local/share/man'.
  Path `/usr/X11R6/bin' mapped to mandir `/usr/X11R6/man'.
  Path `/usr/bin/X11' mapped to mandir `/usr/X11R6/man'.
  Path `/usr/games' mapped to mandir `/usr/share/man'.
  Path `/opt/bin' mapped to mandir `/opt/man'.
  Path `/opt/sbin' mapped to mandir `/opt/man'.
  Global mandir `/usr/man', catdir `/var/cache/man/fsstnd'.
  Global mandir `/usr/share/man', catdir `/var/cache/man'.
  Global mandir `/usr/local/man', catdir `/var/cache/man/oldlocal'.
  Global mandir `/usr/local/share/man', catdir `/var/cache/man/local'.
  Global mandir `/usr/X11R6/man', catdir `/var/cache/man/X11R6'.
  Global mandir `/opt/man', catdir `/var/cache/man/opt'.
  Global mandir `/snap/man', catdir `/var/cache/man/snap'.
  Added sections: `1', `n', `l', `8', `3', `0', `2', `3posix', `3pm', `3perl', `3am', `5', `4', `9', `6', `7'.
  path directory /home/shuuto/.local/bin is not in the config file
  path directory /usr/local/sbin is in the config file
    adding /usr/local/man to manpath
    adding /usr/local/share/man to manpath
  path directory /usr/local/bin is in the config file
    adding /usr/share/man/cat1 to manpath
  path directory /usr/sbin is in the config file
    adding /usr/share/man to manpath
  path directory /usr/bin is in the config file
  path directory /sbin is in the config file
  path directory /bin is in the config file
  path directory /usr/games is in the config file
  path directory /usr/local/games is not in the config file
  path directory /snap/bin is not in the config file
  adding mandatory man directories
  warning: /usr/man: No such file or directory
  /usr/local/man:/usr/local/share/man:/usr/share/man/cat1:/usr/share/man
//}



==== -g もしくは --global



 man-db設定ファイルで「global」として指定されたすべてのパスから構成される manpath を生成するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  manpath -g
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  /usr/man:/usr/share/man:/usr/local/man:/usr/local/share/man:/usr/X11R6/man:/opt/man:/snap/man
//}


==== -m SYSTEM もしくは --systems=SYSTEM



このシステムが他のオペレーティングシステムのマニュアル階層にアクセスできる場合????、引数（ SYSTEM ）に指定することで、これを出力に含めるために使用できるオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  実行結果
//}



==== -q もしくは --quiet



警告を発しないオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  実行結果
//}

#@# 

== mcookie

\**X認証システム* で使用するための \**マジッククッキー（魔法のクッキー）* を生成するための \**ユーティリティ* 。

（\* X認証システム : X Window System という GUI を提供するためのプロトコルとディスプレイサーバに関するソフトウェアプロトコルで使用されるセキュリティ機構のこと。）

（\* マジッククッキー : セッション間での認証トークンとして使用されるランダムデータのこと。）

（\* ユーティリティ : コンピュータの分析、構成、最適化、保守のためのソフトウェアの総称。ユーティリティソフトウェアとも呼ばれる。）

具体的には、X認証システムで使用する128ビットのランダムな16進数を生成する。



===== 実行例 

//list[][][fontsize=xx-small]{
mcookie
//}



===== 実行結果 

//list[][][fontsize=xx-small]{
7f5666105aff03809c17dfb9f2d9ae12
//}



=== オプション一覧


  

==== -f もしくは --file FILE



引数（ FILE ）として指定したファイルをクッキーのシードとして使用するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  mcookie -m 1 -f hoge.txt
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  e9f79e7e1edc12fdda16fb3a4dc70e6b
//}



==== -m もしくは --max-size NUM



シードファイルからの読み込み量を制限するオプション。引数（ NUM ）で指定したバイト数をマックスとする。何かしらのファイルやデバイスをシードにする際に指定しないと実行できないため、-f オプションと併用して使用する。

指定するバイトは当たり前だが、そのファイルのディスク使用量以下にする必要がある。以下の実行例で用いている hoge.txt は 5バイトのファイルである。



===== 実行例 

//list[][][fontsize=xx-small]{
  mcookie -m 5 -f hoge.txt
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  17b6822a593be8cab50b8e29cabab42a
//}



==== -v もしくは --verbose



各ソースから読み取ったエントロピーの量とともにランダム性を出所を表示するオプション。



===== 実行例 

//list[][][fontsize=xx-small]{
  mcookie -m 5 -f create_hoge_files.sh -v 
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  Got 5 bytes from create_hoge_files.sh
  Got 128 bytes from getrandom() function
  f9370557c62ab6c3703b7b614d6ae34f
//}

#@# 

== mesg

mesg コマンドは、システム上の他のユーザーが write コマンドまたは talk コマンドを使用して、 メッセージを送信できるかどうかを制御するコマンド。引数なしで呼び出されると、mesg コマンドは、ターミナルの現在のメッセージ許可設定を表示する。
root 権限を持つユーザーは、メッセージ許可設定に関係なく、どのターミナルにでもメッセージを送信できる。

次に示すフラグによって制御する。


==== n : メッセージを許可しない。


==== y : メッセージの表示を許可する。



===== 実行例 

//list[][][fontsize=xx-small]{
mesg
//}



===== 実行結果 

//list[][][fontsize=xx-small]{
is y
//}



=== オプション一覧


  

なし


==== -v もしくは --verbose



mesg コマンドは、端末で実行されていない場合にはエラーステータス2でサイレントに終了します。この場合、mesg を実行することは無意味です。バージョン2.33でこの挙動が導入され、--verbose オプションを使用すると、この状況で mesg が警告を表示するようになりました。



===== 実行例 

//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果 

//list[][][fontsize=xx-small]{
  実行結果
//}

