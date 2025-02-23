#@# 

=={id} @<term>{id}

ユーザIDやユーザ名、グループID、グループ名などの識別情報を出力する。
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
