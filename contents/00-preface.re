= まえがき / はじめに

ITインフラ修行中の三年生が製作した「厳選Unixコマンド」第2版をお届けします。
執筆者一同の考える「おすすめ」かつ「必須」Unixコマンド群です。

この書籍には電子版と印刷版があります。
中身は同一です。
どちらも、次のURLからダウンロードできます。

@<href>{https://selected-unix-commands.techbooks.fml.org/}

学内で印刷版も無料配布しているので手に取ってみてください。
H205や情報棟一階、図書館で配布しています


==[notoc] 本書の対象読者

おおまかにはUnixオペレーティングシステムのコマンド操作の初心者が対象ですが、
授業の構成を考えると、
情報システム工学科3年春学期に副読本として、おすすめです。
演習授業のおともに、ご活用ください



==[notoc] 第1版と第2版の違い

 *  3年生の授業で用いるコマンドだけに絞ってあります。
    いわゆる「カリカリにチューン」された内容です
 ** 授業で出てこなくても知っておいた方が良い知識やオプション等が執筆者と監修者の判断で少し追加されています
 ** コマンド大辞典のような書籍が必要なら、そういった商業出版物が多数あります。
    必要な方は、そちらを読んでください
 *  第1章「@<B>{Unix小概論}」と@<B>{索引}を追加
 *  第2版はレビュー(by 深町)されているので、内容は信用して大丈夫です



==[notoc] 問い合わせ先

メール: infra-club@cist.fml.org 

学内のかたは、H205に遊びにきてくれると歓迎されます

感想・意見等をお待ちしております


#@# 強制改ページ
//clearpage

== 凡例

====[notoc] XXX

//list[][]{
書式

実行例

実行結果
//}

====[notoc] XXX

====[notoc] XXX


#@# 強制改ページ
//clearpage

== 用語

 * シェル     ... 対話処理をしているOS側のプログラムのこと
 * プロンプト ... シェルが「入力待ち」状態を示す行左端の特殊文字。
                  例: @<B>{$}, @<B>{>}
 * コマンド   ... 対話処理の際にユーザが打ちこむ命令（プログラム名）
 * CLI        ... Command Line Interfaceの頭文字。コマンドを入力して対話すること
                  CUIは同義語。反対語はGUI(Graphical User Interface)
 * ターミナル ... ユーザが入出力をおこなうアプリのこと。
                  もともとはターミナルという装置。
                  文脈によっては「シェル」と同義語
 * クラウド   ... 「さまざまなITリソースをオンデマンドで利用することができるサービスの総称です。必要なときに必要な量のリソースへ簡単にアクセスすることができ、ご利用料金は実際につかった分のお支払いのみといった重量課金が一般的です。(AWSのウエブより引用)」
 * AWS        ... Amazon Web Servicesの略。
                  Amazonが提供するクラウドコンピューティングサービスの総称
 * EC2        ... AWSを代表するサービス。仮想のPCを提供する。OSをインストールして使う
 * S3         ... AWSを代表するサービス。オブジェクトストレージ
 * IP         ... IPアドレス。コンピュータに付ける識別子の数字
 * Public IP  ... 世界で一意に割り当てるIP。サイバースペースにおける住所に相当するIP。別名グローバルIP
 * Private IP ... 各組織が自由に割り当てられるIP。Public IPの逆
 * BSD Unix   ...
 * Linux      ...
 * Debian     ... Debian GNU/Linux。
                  もっとも歴史のあるLinuxディストリビューションの一つ
