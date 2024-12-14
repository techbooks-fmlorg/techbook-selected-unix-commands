#@# 

== tree

 ファイルとディレクトリを樹木状に表示する。ファイルやディレクトリの整理状況を把握するために利用する。



===== 実行例 



//list[][][fontsize=xx-small]{
  tree ディレクトリ
//}





===== 実行結果　（adminディレクトリを出力する場合）



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



=== オプション一覧




==== -d




ディレクトリのみを樹木状に出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  tree -d ディレクトリ
//}





===== 実行結果　（adminディレクトリ内のディレクトリのみを出力する場合）



//list[][][fontsize=xx-small]{
	$ tree -d admin
	admin
	├── __pycache__
	└── htdocs

	3 directories
//}




==== -a




隠しファイルを含むすべてのディレクトリとファイルを出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  tree -a ディレクトリ
//}





===== 実行結果　（adminファイル内のすべてのディレクトリとファイルを出力する場合）



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

		------------------------------------------------------------------------
  ※出力の読み方
	.sshなど.(ドット)から始まるファイルが隠しファイル
//}

