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
.sshなど.(ドット)から始まる隠しファイルや隠しディレクトリも表示されていることが分かる。
