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

