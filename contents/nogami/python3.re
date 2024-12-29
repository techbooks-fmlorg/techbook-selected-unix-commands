#@# 

== python3

pythonのプログラムを動かすことができる。この時、プログラム自体に実行権限がなくても実行される。
python3と単体で入力した場合は対話モードとなり、コードを入力すると実行される。
この時、quit()と入力すると、対話モードが終了する。

===== 実行例1

//list[][][fontsize=xx-small]{
python3 ファイル名
$ cat hello.py

print("Hello World")
※ hello.pyファイルの中身を確認している。

$ python3 hello.py   
//}
===== 実行結果1

//list[][][fontsize=xx-small]{
$ python3 hello.py 
Hello World
※hello.pyが実行され、結果が出力されている。
//}

===== 実行例2

//list[][][fontsize=xx-small]{
$ python3
※ 対話モードが実行されると、>>>と表示される。

>>>print("Hello World")

>>>quit()
//}
===== 実行結果2

//list[][][fontsize=xx-small]{
>>> print("Hello World")
Hello World
※print("Hello World")が実行され、結果が出力されている。

>>>quit()
$
※ 対話モードが終了し、コマンドが打てるようになる。

//}