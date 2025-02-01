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
OSが実行するのは@<code>{a.out}である。

一方、pythonはスクリプト言語である。
www.pyのようなプログラムは実行ファイルではなくソースコードにあたる。
実行ファイルは作成しない。
pythonはソースコード(www.py)を一行ずつ読みながら逐次実行している。

「pythonのプログラムを動かす」という表現は上のような意味である。
よって、プログラム(www.py)自体に実行権限がなくても実行できる。


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
