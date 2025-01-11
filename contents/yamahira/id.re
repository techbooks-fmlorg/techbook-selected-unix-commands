#@# 

== id

 ユーザーIDやユーザー名、グループID、グループ名などの識別情報を出力する。自分の役割を確認するために利用する。



===== 実行例 



//list[][][fontsize=xx-small]{
  id ユーザ名
//}





===== 実行結果　（ユーザ名がadminのユーザ情報を出力する場合）



//list[][][fontsize=xx-small]{
	$ id admin
	uid=1000(admin) gid=1000(admin) groups=1000(admin),4(adm),20(dialout),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev)
	
	------------------------------------------------------------------------
	※出力の読み方
	uid=1000(admin):ユーザ名がadmin、ユーザIDが1000
	gid=1000(admin):グループ名がadmin、グループIDが1000
	groups=1000(admin),4(adm),20(dialout):admin,adm,dialoutグループに所属
	ユーザ名がadminのユーザIDや所属グループがわかる
//}




===== 実行結果　（自分のユーザ情報を出力する場合）



//list[][][fontsize=xx-small]{
	$ id
	uid=1000(admin) gid=1000(admin) groups=1000(admin),4(adm),20(dialout),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev)

	------------------------------------------------------------------------
	※出力の読み方
	自分のユーザ名やユーザID、所属グループがわかる
	現在のユーザがadminの場合 $ id admin と同じ出力である
//}




===== 実行結果　（ユーザ名がrootのユーザ情報を出力する場合）



//list[][][fontsize=xx-small]{
	$ id root
	uid=0(root) gid=0(root) groups=0(root)
//}




===== 実行結果　（管理者権限(sudo)を利用し、自分のユーザ情報を出力する場合）



//list[][][fontsize=xx-small]{
	$ sudo id
	uid=0(root) gid=0(root) groups=0(root)

	------------------------------------------------------------------------
	※出力の読み方
	管理者権限で実行した場合、 $ id root と同じ出力である
//}




=== オプション一覧




==== -u




ユーザIDのみ出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  id -u ユーザ名
//}





===== 実行結果　（ユーザ名がadminのユーザIDを出力する場合）



//list[][][fontsize=xx-small]{
	$ id -u admin
	1000

	------------------------------------------------------------------------
	※出力の読み方
	ユーザ名がadminのユーザIDがわかる
//}
